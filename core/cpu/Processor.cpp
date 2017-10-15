//
// Created by adnan on 14/10/2017.
//

#include "Processor.h"

Processor::~Processor() {

}

Processor::Processor()
    : mRam(127)
{
    HardReset();
}

void Processor::HardReset() {
    mCpuRegisters.PC = 0x100;
    mCpuRegisters.SP = 0xFFFE;
}

