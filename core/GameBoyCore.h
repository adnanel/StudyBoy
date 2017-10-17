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
public:
    GameBoyCore(const GameBoyConfig& gbConfig);
    ~GameBoyCore();

    inline Processor* getCpu() {
        return &mCpu;
    }
    inline const Processor* getCpu() const {
        return &mCpu;
    }

    MemoryMap* GetMemoryForAddress(unsigned long long targetAddress) {
        if ( targetAddress <= 0x4000 ) {
            throw std::exception(); // ROM bank #0
        } else if ( targetAddress <= 0x8000 ) {
            throw std::exception(); //switchable ROM bank
        } else if ( targetAddress <= 0xA000 ) {
            return &mDisplayRam;
        } else if ( targetAddress <= 0xC000 ) {
            throw std::exception(); //switchable RAM bank
        } else if ( targetAddress <= 0xE000 ) {
            return &mWorkRam;
        } else if ( targetAddress <= 0xFE00 ) {
            throw std::exception(); // Echo of 8kB Internal RAM
        } else if ( targetAddress <= 0xFEA0 ) {
            throw std::exception(); // Sprite Attrib Memory (OAM)
        } else if ( targetAddress <= 0xFF00 ) {
            throw std::exception(); // Empty but unusable for I/O
        } else if ( targetAddress <= 0xFF4C ) {
            throw std::exception(); // I/O ports
        } else if ( targetAddress <= 0xFF80 ) {
            throw std::exception(); // Empty but unusable for I/O
        } else if ( targetAddress <= 0xFFFF ) {
            throw std::exception(); // Internal RAM, interrupt enable register if == 0xFFFF
        }

        throw std::invalid_argument("Invalid address!");
    }

    const MemoryMap* GetMemoryForAddress(unsigned long long targetAddress) const {
        if ( targetAddress <= 0x4000 ) {
            throw std::exception(); // ROM bank #0
        } else if ( targetAddress <= 0x8000 ) {
            throw std::exception(); //switchable ROM bank
        } else if ( targetAddress <= 0xA000 ) {
            return &mDisplayRam;
        } else if ( targetAddress <= 0xC000 ) {
            throw std::exception(); //switchable RAM bank
        } else if ( targetAddress <= 0xE000 ) {
            return &mWorkRam;
        } else if ( targetAddress <= 0xFE00 ) {
            throw std::exception(); // Echo of 8kB Internal RAM
        } else if ( targetAddress <= 0xFEA0 ) {
            throw std::exception(); // Sprite Attrib Memory (OAM)
        } else if ( targetAddress <= 0xFF00 ) {
            throw std::exception(); // Empty but unusable for I/O
        } else if ( targetAddress <= 0xFF4C ) {
            throw std::exception(); // I/O ports
        } else if ( targetAddress <= 0xFF80 ) {
            throw std::exception(); // Empty but unusable for I/O
        } else if ( targetAddress <= 0xFFFF ) {
            throw std::exception(); // Internal RAM, interrupt enable register if == 0xFFFF
        }

        throw std::invalid_argument("Invalid address!");
    }

    template<unsigned int BitCount>
    std::bitset<BitCount> ReadData(unsigned long long targetAddress) const {
        auto* targetMemory = GetMemoryForAddress(targetAddress);

        return targetMemory->ReadData<BitCount>(targetAddress);
    }

    template<unsigned int BitCount>
    void WriteData(unsigned long long address, const Register<BitCount>& reg) {
        auto* targetMemory = GetMemoryForAddress(address);

        return targetMemory->WriteData<BitCount>(address, reg);
    }

    void SetFlags(bool z, bool n, bool h, bool c);


    template<unsigned int N>
    void PushToStack(Register<N> reg)
    {
        assert( N % 8 == 0 );

        int bytes = N / 8;

        auto& cpu = *getCpu();
        for ( int i = 0; i < bytes; ++ i ) {
            cpu.getCpuRegisters()->setSP(cpu.getCpuRegisters()->getSP() - 1);

            Register<8> r = 0xFF & (reg >> 8).to_ullong();

            WriteData<8>(cpu.getCpuRegisters()->getSP().to_ullong(), r);
        }
    }


    void Step();
};


#endif //STUDYBOY_GAMEBOYCORE_H
