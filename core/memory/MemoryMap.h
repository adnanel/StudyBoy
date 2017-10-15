//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_MEMORYMAP_H
#define STUDYBOY_MEMORYMAP_H


#include <cstdio>
#include <bitset>
#include <stdexcept>

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
    std::bitset<BitCount> ReadData(unsigned long long targetAddress) {
        if ( BitCount % 8 != 0 ) throw std::invalid_argument("BitCount unsupported!");
        std::bitset<BitCount> res;
        int byteCount = BitCount % 8;

        for ( int i = 0; i < byteCount; ++ i ) {
            res = (res.to_ullong() << 8) | mMemory[targetAddress + i];
        }
        return res;
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
