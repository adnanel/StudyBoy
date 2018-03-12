//
// Created by adnan on 14/10/2017.
//

#include "Processor.h"


Processor::Processor()
    : mInternalRam(127), mCodeLoader(nullptr)
{
    HardReset();
    mInternalRam.setAddressOffset(0xff80);
}

void Processor::HardReset() {
    mCpuRegisters.setPC(0x100);

    mCpuRegisters.setAF(0x01B0); // todo different for gbc
    // mCpuRegisters.setF(0xB0);
    mCpuRegisters.setBC(0x0013);
    mCpuRegisters.setDE(0x00D8);
    mCpuRegisters.setHL(0x014D);

    mCpuRegisters.setSP(0xFFFE);

    mIORegisters.setRegisterByAddress(0xFF05, 0);
    mIORegisters.setRegisterByAddress(0xFF06, 0);
    mIORegisters.setRegisterByAddress(0xFF07, 0);
    mIORegisters.setRegisterByAddress(0xFF10, 0x80);
    mIORegisters.setRegisterByAddress(0xFF11, 0xBF);
    mIORegisters.setRegisterByAddress(0xFF12, 0xF3);
    mIORegisters.setRegisterByAddress(0xFF14, 0xBF);

    mIORegisters.setRegisterByAddress(0xFF16, 0x3F);
    mIORegisters.setRegisterByAddress(0xFF17, 0x00);
    mIORegisters.setRegisterByAddress(0xFF19, 0xBF);

    mIORegisters.setRegisterByAddress(0xFF1A, 0x7F);
    mIORegisters.setRegisterByAddress(0xFF1B, 0xff);
    mIORegisters.setRegisterByAddress(0xFF1C, 0x9f);
    mIORegisters.setRegisterByAddress(0xFF1E, 0xbf);

    mIORegisters.setRegisterByAddress(0xFF20, 0xff);
    mIORegisters.setRegisterByAddress(0xFF21, 0x00);
    mIORegisters.setRegisterByAddress(0xFF22, 0x00);
    mIORegisters.setRegisterByAddress(0xFF23, 0xbf);
    mIORegisters.setRegisterByAddress(0xFF24, 0x77);
    mIORegisters.setRegisterByAddress(0xFF25, 0xf3);

    mIORegisters.setRegisterByAddress(0xFF26, 0xf1); // todo different for gbc
    mIORegisters.setRegisterByAddress(0xFF40, 0x91);
    mIORegisters.setRegisterByAddress(0xFF42, 0x00);
    mIORegisters.setRegisterByAddress(0xFF43, 0x00);

    mIORegisters.setRegisterByAddress(0xFF45, 0);
    mIORegisters.setRegisterByAddress(0xFF47, 0xfc);
    mIORegisters.setRegisterByAddress(0xFF48, 0xff);
    mIORegisters.setRegisterByAddress(0xFF49, 0xff);
    mIORegisters.setRegisterByAddress(0xFF4A, 0);
    mIORegisters.setRegisterByAddress(0xFF4B, 0);

    mIORegisters.setRegisterByAddress(0xFFFF, 0);
}

