//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_MEMORYMAP_H
#define STUDYBOY_MEMORYMAP_H


#include <cstdio>

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

};


#endif //STUDYBOY_MEMORYMAP_H
