//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_GAMEBOYCORE_H
#define STUDYBOY_GAMEBOYCORE_H


#include <cassert>
#include "memory/MemoryMap.h"
#include "cpu/Processor.h"
#include "GameBoyConfig.h"
#include "lcd/LcdController.h"

class GameBoyCore {
private:
    MemoryMap mWorkRam;
    MemoryMap mDisplayRam;

    Processor mCpu;

    LcdController mLcdController;
public:
    GameBoyCore(const GameBoyConfig& gbConfig);
    ~GameBoyCore();

    inline Processor* getCpu() {
        return &mCpu;
    }
    inline const Processor* getCpu() const {
        return &mCpu;
    }

    inline MemoryMap* getWorkRam() {
        return &mWorkRam;
    }
    inline const MemoryMap* getWorkRam() const {
        return &mWorkRam;
    }

    inline MemoryMap* getDisplayRam() {
        return &mDisplayRam;
    }
    inline const MemoryMap* getDisplayRam() const {
        return &mDisplayRam;
    }

    inline void SetFlags(bool z, bool n, bool h, bool c) {
        mCpu.getFlagRegister()->setZ(z);
        mCpu.getFlagRegister()->setN(n);
        mCpu.getFlagRegister()->setH(h);
        mCpu.getFlagRegister()->setC(c);
    }


    template<unsigned int N>
    inline void PushToStack(Register<N> reg)
    {
        assert( N % 8 == 0 );

        int bytes = N / 8;

        auto& cpu = *getCpu();
        for ( int i = 0; i < bytes; ++ i ) {
            cpu.getCpuRegisters()->setSP(cpu.getCpuRegisters()->getSP() - 1);

            Register<8> r = 0xFF & (reg >> 8).to_ullong();

            getWorkRam()->WriteData<8>(cpu.getCpuRegisters()->getSP().to_ullong(), r);
        }
    }
};


#endif //STUDYBOY_GAMEBOYCORE_H
