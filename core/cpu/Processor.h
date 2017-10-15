//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_PROCESSOR_H
#define STUDYBOY_PROCESSOR_H


#include "../memory/MemoryMap.h"
#include "components/FrequencyDivider.h"
#include "components/Timer.h"
#include "components/DmaController.h"
#include "components/Register.h"
#include "components/IORegisters.h"
#include "components/CpuRegisters.h"
#include "components/FlagRegister.h"

class Processor {
protected:
    // 127 * 8 bits of built in RAM (working and stack)
    MemoryMap mRam;
    // 16 stage frequency divider
    FrequencyDivider mFrequencyDivider;
    // 8 bit timer
    Timer mTimer;
    // DMA controller
    DmaController mDmaController;

    // Registers
    IORegisters mIORegisters;
    CpuRegisters mCpuRegisters;
    FlagRegister mFlagRegister;
public:
    Processor();
    virtual ~Processor();

    virtual void HardReset();

    FlagRegister* getFlagRegister() {
        return &mFlagRegister;
    }
    const FlagRegister* getFlagRegister() const {
        return &mFlagRegister;
    }

    const CpuRegisters* getCpuRegisters() const {
        return &mCpuRegisters;
    }
    CpuRegisters* getCpuRegisters() {
        return &mCpuRegisters;
    }
};


#endif //STUDYBOY_PROCESSOR_H
