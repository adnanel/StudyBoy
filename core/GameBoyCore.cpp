//
// Created by adnan on 14/10/2017.
//

#include <iomanip>
#include "GameBoyCore.h"
#include "cpu/instructions/Instruction.h"

GameBoyCore::GameBoyCore(const GameBoyConfig& gbConfig)
    : mWorkRam(gbConfig.workMemorySize),
      mDisplayRam(gbConfig.displayMemorySize),
      mImeFlag(true)
{

}

GameBoyCore::~GameBoyCore() = default;

void GameBoyCore::Step() {
    if ( IsHalted() ) return;

    auto pc = getCpu()->getCpuRegisters()->getPC();

    auto instruction = getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong());

    std::cout<<"Decoding instruction - pc = "<<std::hex<<std::setw(5)<<pc.to_ullong()<<", (pc) = "<<std::setw(5)<<std::hex<<instruction.to_ullong();
    auto fun = Instruction::DecodeInstruction(instruction.to_ullong());

    std::cout<<"  | "<<fun.instructionText<<std::endl;

    fun.instructionFun(this, instruction.to_ullong());

    pc = getCpu()->getCpuRegisters()->getPC();
    getCpu()->getCpuRegisters()->setPC(pc + 1);
}

void GameBoyCore::SetFlags(bool z, bool n, bool h, bool c)  {
    mCpu.setZFlag(z);
    mCpu.setNFlag(n);
    mCpu.setHFlag(h);
    mCpu.setCFlag(c);
}

bool GameBoyCore::getInterruptsEnabled() const {
    return mCpu.getIORegisters()->getFFFF().to_ullong() != 0;
}

void GameBoyCore::setInterruptsEnabled(bool mInterruptsEnabled) {
    return mCpu.getIORegisters()->setFFFF(mInterruptsEnabled);
}

void GameBoyCore::PrintRegisters() {
    int z, n, h, c;
    z = getCpu()->getZFlag();
    n = getCpu()->getNFlag();
    h = getCpu()->getHFlag();
    c = getCpu()->getCFlag();
    std::cout<<std::endl<<"FLAGS = [ Z = "<<z<<", N = "<<n<<", H = "<<h<<", C = "<<c<<" ]";
    std::cout<<std::endl<<"SP = "<<std::hex<<getCpu()->getCpuRegisters()->getSP().to_ullong();
    std::cout<<std::endl<<"PC = "<<std::hex<<getCpu()->getCpuRegisters()->getPC().to_ullong();
}

MemoryMap *GameBoyCore::GetMemoryForAddress(unsigned long long targetAddress) {
    if ( targetAddress <= 0x4000 ) {
        return mCpu.getCodeLoader()->getMemoryMap();
    } else if ( targetAddress <= 0x8000 ) {
        throw std::invalid_argument("switchable ROM bank not implemented"); // switchable ROM bank
    } else if ( targetAddress <= 0xA000 ) {
        return &mDisplayRam;
    } else if ( targetAddress <= 0xC000 ) {
        throw std::invalid_argument("switchable RAM bank not implemented"); // switchable RAM bank
    } else if ( targetAddress <= 0xE000 ) {
        return &mWorkRam;
    } else if ( targetAddress <= 0xFE00 ) {
        throw std::invalid_argument(" Echo of 8kB Internal RAM not implemented"); //  Echo of 8kB Internal RAM
    } else if ( targetAddress <= 0xFEA0 ) {
        throw std::invalid_argument(" Sprite Attrib Memory (OAM) not implemented"); //  Sprite Attrib Memory (OAM)
    } else if ( targetAddress <= 0xFF00 ) {
        throw std::invalid_argument(" Empty but unusable for I/O not implemented"); //  Empty but unusable for I/O
    } else if ( targetAddress <= 0xFF4C ) {
        throw std::invalid_argument(" I/O ports not implemented"); //  I/O ports
    } else if ( targetAddress <= 0xFF80 ) {
        throw std::invalid_argument(" Empty but unusable for I/O not implemented"); //  Empty but unusable for I/O
    } else if ( targetAddress <= 0xFFFF ) {
        throw std::invalid_argument(" Internal RAM, interrupt enable register if == 0xFFFF not supported here, "
                                            "use FFFF register directly");
    }

    throw std::invalid_argument("Invalid address!");
}

const MemoryMap *GameBoyCore::GetMemoryForAddress(unsigned long long targetAddress) const {
    if ( targetAddress <= 0x4000 ) {
        return mCpu.getCodeLoader()->getMemoryMap();
    } else if ( targetAddress <= 0x8000 ) {
        throw std::invalid_argument("switchable ROM bank not implemented"); // switchable ROM bank
    } else if ( targetAddress <= 0xA000 ) {
        return &mDisplayRam;
    } else if ( targetAddress <= 0xC000 ) {
        throw std::invalid_argument("switchable RAM bank not implemented"); // switchable RAM bank
    } else if ( targetAddress <= 0xE000 ) {
        return &mWorkRam;
    } else if ( targetAddress <= 0xFE00 ) {
        throw std::invalid_argument(" Echo of 8kB Internal RAM not implemented"); //  Echo of 8kB Internal RAM
    } else if ( targetAddress <= 0xFEA0 ) {
        throw std::invalid_argument(" Sprite Attrib Memory (OAM) not implemented"); //  Sprite Attrib Memory (OAM)
    } else if ( targetAddress <= 0xFF00 ) {
        throw std::invalid_argument(" Empty but unusable for I/O not implemented"); //  Empty but unusable for I/O
    } else if ( targetAddress <= 0xFF4C ) {
        throw std::invalid_argument(" I/O ports not implemented"); //  I/O ports
    } else if ( targetAddress <= 0xFF80 ) {
        throw std::invalid_argument(" Empty but unusable for I/O not implemented"); //  Empty but unusable for I/O
    } else if ( targetAddress <= 0xFFFF ) {
        throw std::invalid_argument(" Internal RAM, interrupt enable register if == 0xFFFF not supported here, "
                                            "use FFFF register directly");
    }

    throw std::invalid_argument("Invalid address!");
}

std::bitset<16u> GameBoyCore::ReadData16(unsigned long long targetAddress) const {
    auto* targetMemory = GetMemoryForAddress(targetAddress);

    return targetMemory->ReadData<16u>(targetAddress);
}

std::bitset<8u> GameBoyCore::ReadData8(unsigned long long targetAddress) const {
    if ( targetAddress == 0xFFFF ) {
        return mCpu.getIORegisters()->getFFFF();
    }

    auto* targetMemory = GetMemoryForAddress(targetAddress);

    return targetMemory->ReadData<8>(targetAddress);
}

void GameBoyCore::WriteData8(unsigned long long address, const Register<8u> &reg) {
    if ( address == 0xFFFF ) {
        return mCpu.getIORegisters()->setFFFF(reg);
    }

    auto* targetMemory = GetMemoryForAddress(address);

    return targetMemory->WriteData<8>(address, reg);
}

void GameBoyCore::WriteData16(unsigned long long address, const Register<16u> &reg) {
    auto* targetMemory = GetMemoryForAddress(address);

    return targetMemory->WriteData<16u>(address, reg);
}

void GameBoyCore::GenerateInterrupt() {
    mCpu.getIORegisters()->setFF0F(1);

    if ( !mImeFlag ) return;

    auto pc = mCpu.getCpuRegisters()->getPC();
    PushToStack(pc);

    mCpu.getCpuRegisters()->setPC(pc);
    /*
     1. When an interrupt is generated, the IF flag will be    set.
     2. If the IME flag is set & the corresponding IE flag     is set, the following 3 steps are performed.
     3. Reset the IME flag and prevent all interrupts.
     4. The PC (program counter) is pushed onto the stack. 5. Jump to the starting address of the interrupt.
     */

}


