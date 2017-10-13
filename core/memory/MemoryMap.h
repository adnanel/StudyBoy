//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_MEMORYMAP_H
#define STUDYBOY_MEMORYMAP_H


#include <cstdio>

class MemoryMap {
    char* mMemory;

public:
    explicit MemoryMap(const size_t& memSize = 32 * 1024);
};


#endif //STUDYBOY_MEMORYMAP_H
