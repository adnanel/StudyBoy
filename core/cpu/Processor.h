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
#include "codeloaders/CodeLoader.h"
#include "memory_controllers/MemoryController.h"

class Processor {
protected:
    // 127 * 8 bits of built in RAM (working and stack)
    MemoryMap mInternalRam;
    // 16 stage frequency divider
    FrequencyDivider mFrequencyDivider;
    // 8 bit timer
    Timer mTimer;
    // DMA controller
    DmaController mDmaController;

    MemoryController* mMemoryController;

    // Registers
    IORegisters mIORegisters;
    CpuRegisters mCpuRegisters;

    CodeLoader* mCodeLoader;

public:
    Processor();
    virtual ~Processor() {
        delete mCodeLoader;
        delete mMemoryController;
    }

    virtual void HardReset();


    inline bool getZFlag() const {
        getCpuRegisters()->getF()[7];
    }

    inline void setZFlag(bool set) {
        auto f = getCpuRegisters()->getF();
        f[7] = set;
        getCpuRegisters()->setF(f);
    }

    inline bool getNFlag() const {
        getCpuRegisters()->getF()[6];
    }
    inline void setNFlag(bool set) {
        auto f = getCpuRegisters()->getF();
        f[6] = set;
        getCpuRegisters()->setF(f);
    }

    inline bool getHFlag() const {
        getCpuRegisters()->getF()[5];
    }
    inline void setHFlag(bool set) {
        auto f = getCpuRegisters()->getF();
        f[5] = set;
        getCpuRegisters()->setF(f);
    }

    inline bool getCFlag() const {
        getCpuRegisters()->getF()[4];
    }
    inline void setCFlag(bool set) {
        auto f = getCpuRegisters()->getF();
        f[4] = set;
        getCpuRegisters()->setF(f);
    }

    const CpuRegisters* getCpuRegisters() const {
        return &mCpuRegisters;
    }
    CpuRegisters* getCpuRegisters() {
        return &mCpuRegisters;
    }

    inline CodeLoader* setCodeLoader( CodeLoader* loader ) {
        auto old = this->mCodeLoader;
        this->mCodeLoader = loader;
        return old;
    }

    inline CodeLoader* getCodeLoader() {
        return this->mCodeLoader;
    }
    inline const CodeLoader* getCodeLoader() const {
        return this->mCodeLoader;
    }

    inline IORegisters* getIORegisters() {
        return &mIORegisters;
    }
    inline const IORegisters* getIORegisters() const {
        return &mIORegisters;
    }

    const MemoryMap* getInternalRam() const {
        return &mInternalRam;
    }

    MemoryMap* getInternalRam() {
        return &mInternalRam;
    }

    void setMemoryController(MemoryController* memController) {
        this->mMemoryController = memController;
    }
    MemoryController* getMemoryController() {
        return this->mMemoryController;
    }
};


#endif //STUDYBOY_PROCESSOR_H
