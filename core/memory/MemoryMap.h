//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_MEMORYMAP_H
#define STUDYBOY_MEMORYMAP_H


#include <cstdio>
#include <bitset>
#include <stdexcept>
#include "../cpu/components/Register.h"

class MemoryMap {
    char* mMemory;
    size_t mMemSize;

    bool mIsReadonly;

    size_t mAddrOffset;
public:
    explicit MemoryMap(const size_t& memSize = 32 * 1024, bool readonly = false, char* allocatedData = nullptr);

    void setAddressOffset(size_t offset) {
        mAddrOffset = offset;
    }
    size_t getAddressOffset() const {
        return mAddrOffset;
    }

    template<unsigned int BitCount>
    std::bitset<BitCount> ReadData(unsigned long long targetAddress) const {
        if ( BitCount % 8 != 0 ) {
            throw std::invalid_argument("BitCount unsupported!");
        }
        if ( targetAddress >= mMemSize ) {
            throw std::invalid_argument("Address out of memory range!");
        }

        //targetAddress /= 4;

        std::bitset<BitCount> res = 0;
        int byteCount = BitCount / 8;

        for ( int i = byteCount; i >= 0; -- i ) {
            res = (res.to_ullong() << 8) | mMemory[targetAddress + i + mAddrOffset];
        }

        return res;
    }

    template<unsigned int BitCount>
    void WriteData(unsigned long long address, const Register<BitCount>& reg) {
        if ( mIsReadonly ) {
            throw std::domain_error("Can't write to read only memory! Address = " + std::to_string(address));
        }
        if ( address >= mMemSize ) {
            throw std::invalid_argument("Address out of memory range!");
        }

        if ( BitCount % 8 != 0 ) throw std::invalid_argument("BitCount unsupported!");
        //address /= 4;

        int byteCount = BitCount / 8;

        auto data = reg.to_ullong();
        for ( int i = 0; i < byteCount; ++ i ) {
            mMemory[address + i + mAddrOffset] = static_cast<char>(0xFF & data);
            data >>= 8;
        }
    }

};


#endif //STUDYBOY_MEMORYMAP_H
