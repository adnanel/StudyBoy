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
    bool mIsReadonly;

public:
    explicit MemoryMap(const size_t& memSize = 32 * 1024, bool readonly = false);

    // Access memory data directly via the [] operator
    const char& operator[](const int& addr) const;
    char& operator[](const int& addr);


    void WriteData(int targetAddress, char* data, size_t size);
    void CopyData(int targetAddress, char* target, size_t size);


    template<unsigned int BitCount>
    std::bitset<BitCount> ReadData(unsigned long long targetAddress) const {
        if ( BitCount % 8 != 0 ) throw std::invalid_argument("BitCount unsupported!");
        std::bitset<BitCount> res;
        int byteCount = BitCount % 8;

        for ( int i = byteCount; i >= 0; -- i ) {
            res = (res.to_ullong() << 8) | mMemory[targetAddress + i];
        }
        return res;
    }

    template<unsigned int BitCount>
    void WriteData(unsigned long long address, const Register<BitCount>& reg) {
        if ( BitCount % 8 != 0 ) throw std::invalid_argument("BitCount unsupported!");

        int byteCount = BitCount % 8;

        auto data = reg.to_ullong();
        for ( int i = 0; i < byteCount; ++ i ) {
            mMemory[address + i] = static_cast<char>(0xFF & data);
            data >>= 8;
        }
    }

    template<typename T>
    T* ReadData(unsigned long long targetAddress) {
        return reinterpret_cast<T*>(mMemory[targetAddress]);
    }

    template<typename T>
    const T* ReadData(unsigned long long targetAddress) const {
        return reinterpret_cast<T*>(mMemory[targetAddress]);
    }
};


#endif //STUDYBOY_MEMORYMAP_H
