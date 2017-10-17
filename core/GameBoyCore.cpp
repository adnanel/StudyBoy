//
// Created by adnan on 14/10/2017.
//

#include <iomanip>
#include "GameBoyCore.h"
#include "cpu/instructions/Instruction.h"

GameBoyCore::GameBoyCore(const GameBoyConfig& gbConfig)
    : mWorkRam(gbConfig.workMemorySize),
      mDisplayRam(gbConfig.displayMemorySize)
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
    mCpu.getFlagRegister()->setZ(z);
    mCpu.getFlagRegister()->setN(n);
    mCpu.getFlagRegister()->setH(h);
    mCpu.getFlagRegister()->setC(c);
}

bool GameBoyCore::getInterruptsEnabled() const {
    return mCpu.getIORegisters()->getFFFF().to_ullong() != 0;
}

void GameBoyCore::setInterruptsEnabled(bool mInterruptsEnabled) {
    return mCpu.getIORegisters()->setFFFF(mInterruptsEnabled);
}


