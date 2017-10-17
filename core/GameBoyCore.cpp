//
// Created by adnan on 14/10/2017.
//

#include "GameBoyCore.h"
#include "cpu/instructions/Instruction.h"

GameBoyCore::GameBoyCore(const GameBoyConfig& gbConfig)
    : mWorkRam(gbConfig.workMemorySize),
      mDisplayRam(gbConfig.displayMemorySize)
{

}

GameBoyCore::~GameBoyCore() = default;

void GameBoyCore::Step() {
    auto pc = getCpu()->getCpuRegisters()->getPC();

    auto instruction = getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong());

    std::cout<<"Decoding instruction - pc = "<<std::hex<<pc.to_ullong()<<", (pc) = "<<std::hex<<instruction.to_ullong()<<std::endl;
    auto fun = Instruction::DecodeInstruction(instruction.to_ullong());

    fun(this, instruction.to_ullong());

    pc = getCpu()->getCpuRegisters()->getPC();
    getCpu()->getCpuRegisters()->setPC(pc + 1);
}

void GameBoyCore::SetFlags(bool z, bool n, bool h, bool c)  {
    mCpu.getFlagRegister()->setZ(z);
    mCpu.getFlagRegister()->setN(n);
    mCpu.getFlagRegister()->setH(h);
    mCpu.getFlagRegister()->setC(c);
}


