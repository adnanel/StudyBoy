//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_GAMEBOYCORE_H
#define STUDYBOY_GAMEBOYCORE_H


#include <cassert>
#include <iostream>
#include "memory/MemoryMap.h"
#include "cpu/Processor.h"
#include "GameBoyConfig.h"
#include "lcd/LcdController.h"

class GameBoyCore {
private:
    /**
     Interrupt Enable Register
     --------------------------- FFFF
     Internal RAM
     --------------------------- FF80
     Empty but unusable for I/O
     --------------------------- FF4C
     I/O ports
     --------------------------- FF00
     Empty but unusable for I/O
     --------------------------- FEA0
     Sprite Attrib Memory (OAM)
     --------------------------- FE00
     Echo of 8kB Internal RAM
     --------------------------- E000
     8kB Internal RAM
     --------------------------- C000
     8kB switchable RAM bank
     --------------------------- A000
     8kB Video RAM
     --------------------------- 8000 -
     16kB switchable ROM bank         |
     --------------------------- 4000 |= 32kB Cartrigbe
     16kB ROM bank #0                 |
     --------------------------- 0000 -

       * NOTE: b = bit, B = byte

     */
    MemoryMap mWorkRam;
    MemoryMap mDisplayRam;



    Processor mCpu;

    LcdController mLcdController;

    bool mImeFlag;
public:
    GameBoyCore(const GameBoyConfig& gbConfig);
    ~GameBoyCore();

    inline Processor* getCpu() {
        return &mCpu;
    }
    inline const Processor* getCpu() const {
        return &mCpu;
    }

    inline bool IsHalted() {
        return mCpu.getIORegisters()->getFF0F().to_ullong() != 0;
    }
    inline bool setIsHalted(bool isHalted) {
        mCpu.getIORegisters()->setFF0F(isHalted ? 1 : 0);
    }

    bool getInterruptsEnabled() const;

    void setInterruptsEnabled(bool mInterruptsEnabled);

    MemoryMap* GetMemoryForAddress(unsigned long long targetAddress);

    const MemoryMap* GetMemoryForAddress(unsigned long long targetAddress) const;

    std::bitset<16u> ReadData16(unsigned long long targetAddress) const;

    std::bitset<8u> ReadData8(unsigned long long targetAddress) const;

    void WriteData8(unsigned long long address, const Register<8u>& reg);

    void WriteData16(unsigned long long address, const Register<16u>& reg);

    void SetFlags(bool z, bool n, bool h, bool c);

    template<unsigned int N>
    Register<N> PopStack() {
        assert( N % 8 == 0 );

        int bytes = N / 8;

        auto& cpu = *getCpu();

        Register<N> reg = 0;

        for ( int i = 0; i < bytes; ++ i ) {
            auto sp = cpu.getCpuRegisters()->getSP();
            cpu.getCpuRegisters()->setSP(cpu.getCpuRegisters()->getSP() + 1);

            auto data = ReadData8(sp.to_ullong());

            reg = (reg << 8) | ( 0xFF & data.to_ullong());
        }

        return reg;
    }

    template<unsigned int N>
    void PushToStack(Register<N> reg)
    {
        assert( N % 8 == 0 );

        int bytes = N / 8;

        auto& cpu = *getCpu();
        for ( int i = 0; i < bytes; ++ i ) {
            cpu.getCpuRegisters()->setSP(cpu.getCpuRegisters()->getSP() - 1);

            Register<8> r = 0xFF & (reg >> 8).to_ullong();

            WriteData8(cpu.getCpuRegisters()->getSP().to_ullong(), r);
        }
    }


    void Step();

    void PrintRegisters();

    void GenerateInterrupt();
};


#endif //STUDYBOY_GAMEBOYCORE_H
