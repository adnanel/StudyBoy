//
// Created by adnan on 14/10/2017.
//

#include "Processor.h"

Processor::~Processor() {

}

Processor::Processor()
    : mRam(127), codeLoader(nullptr)
{
    HardReset();
}

void Processor::HardReset() {
    mCpuRegisters.setPC(0x100);
    mCpuRegisters.setSP(0xFFFE);
}

