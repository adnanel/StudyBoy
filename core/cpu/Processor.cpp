//
// Created by adnan on 14/10/2017.
//

#include "Processor.h"


Processor::Processor()
    : mInternalRam(127), codeLoader(nullptr)
{
    HardReset();
    mInternalRam.setAddressOffset(0xff80);
}

void Processor::HardReset() {
    mCpuRegisters.setPC(0x100);
    mCpuRegisters.setSP(0xFFFE);
}

