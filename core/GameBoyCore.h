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

    MemoryMap* GetMemoryForAddress(unsigned long long targetAddress) {
        if ( targetAddress <= 0x4000 ) {
            return mCpu.getCodeLoader()->getMemoryMap();
        } else if ( targetAddress <= 0x8000 ) {
            throw std::invalid_argument("switchable ROM bank not implemented"); // switchable ROM bank
        } else if ( targetAddress <= 0xA000 ) {
            return &mDisplayRam;
        } else if ( targetAddress <= 0xC000 ) {
            throw std::invalid_argument("switchable RAM bank not implemented"); // switchable RAM bank
        } else if ( targetAddress <= 0xE000 ) {
            return &mWorkRam;
        } else if ( targetAddress <= 0xFE00 ) {
            throw std::invalid_argument(" Echo of 8kB Internal RAM not implemented"); //  Echo of 8kB Internal RAM
        } else if ( targetAddress <= 0xFEA0 ) {
            throw std::invalid_argument(" Sprite Attrib Memory (OAM) not implemented"); //  Sprite Attrib Memory (OAM)
        } else if ( targetAddress <= 0xFF00 ) {
            throw std::invalid_argument(" Empty but unusable for I/O not implemented"); //  Empty but unusable for I/O
        } else if ( targetAddress <= 0xFF4C ) {
            throw std::invalid_argument(" I/O ports not implemented"); //  I/O ports
        } else if ( targetAddress <= 0xFF80 ) {
            throw std::invalid_argument(" Empty but unusable for I/O not implemented"); //  Empty but unusable for I/O
        } else if ( targetAddress <= 0xFFFF ) {
            throw std::invalid_argument(" Internal RAM, interrupt enable register if == 0xFFFF not supported here, "
                                                "use FFFF register directly");
        }

        throw std::invalid_argument("Invalid address!");
    }

    const MemoryMap* GetMemoryForAddress(unsigned long long targetAddress) const {
        if ( targetAddress <= 0x4000 ) {
            return mCpu.getCodeLoader()->getMemoryMap();
        } else if ( targetAddress <= 0x8000 ) {
            throw std::invalid_argument("switchable ROM bank not implemented"); // switchable ROM bank
        } else if ( targetAddress <= 0xA000 ) {
            return &mDisplayRam;
        } else if ( targetAddress <= 0xC000 ) {
            throw std::invalid_argument("switchable RAM bank not implemented"); // switchable RAM bank
        } else if ( targetAddress <= 0xE000 ) {
            return &mWorkRam;
        } else if ( targetAddress <= 0xFE00 ) {
            throw std::invalid_argument(" Echo of 8kB Internal RAM not implemented"); //  Echo of 8kB Internal RAM
        } else if ( targetAddress <= 0xFEA0 ) {
            throw std::invalid_argument(" Sprite Attrib Memory (OAM) not implemented"); //  Sprite Attrib Memory (OAM)
        } else if ( targetAddress <= 0xFF00 ) {
            throw std::invalid_argument(" Empty but unusable for I/O not implemented"); //  Empty but unusable for I/O
        } else if ( targetAddress <= 0xFF4C ) {
            throw std::invalid_argument(" I/O ports not implemented"); //  I/O ports
        } else if ( targetAddress <= 0xFF80 ) {
            throw std::invalid_argument(" Empty but unusable for I/O not implemented"); //  Empty but unusable for I/O
        } else if ( targetAddress <= 0xFFFF ) {
            throw std::invalid_argument(" Internal RAM, interrupt enable register if == 0xFFFF not supported here, "
                                                "use FFFF register directly");
        }

        throw std::invalid_argument("Invalid address!");
    }

    std::bitset<16u> ReadData16(unsigned long long targetAddress) const {
        auto* targetMemory = GetMemoryForAddress(targetAddress);

        return targetMemory->ReadData<16u>(targetAddress);
    }

    std::bitset<8u> ReadData8(unsigned long long targetAddress) const {
        if ( targetAddress == 0xFFFF ) {
            return mCpu.getIORegisters()->getFFFF();
        }

        auto* targetMemory = GetMemoryForAddress(targetAddress);

        return targetMemory->ReadData<8>(targetAddress);
    }

    void WriteData8(unsigned long long address, const Register<8u>& reg) {
        if ( address == 0xFFFF ) {
            return mCpu.getIORegisters()->setFFFF(reg);
        }

        auto* targetMemory = GetMemoryForAddress(address);

        return targetMemory->WriteData<8>(address, reg);
    }

    void WriteData16(unsigned long long address, const Register<16u>& reg) {
        auto* targetMemory = GetMemoryForAddress(address);

        return targetMemory->WriteData<16u>(address, reg);
    }

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


    void GenerateInterrupt() {
        mCpu.getIORegisters()->setFF0F(1);

        if ( !mImeFlag ) return;

        auto pc = mCpu.getCpuRegisters()->getPC();
        PushToStack(pc);

        mCpu.getCpuRegisters()->setPC(pc);
        /*
         1. When an interrupt is generated, the IF flag will be    set.
         2. If the IME flag is set & the corresponding IE flag     is set, the following 3 steps are performed.
         3. Reset the IME flag and prevent all interrupts.
         4. The PC (program counter) is pushed onto the stack. 5. Jump to the starting address of the interrupt.
         */

    }
};


#endif //STUDYBOY_GAMEBOYCORE_H
