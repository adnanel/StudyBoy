//
// Created by adnan on 14/10/2017.
//

#include <new>
#include "MemoryMap.h"

MemoryMap::MemoryMap(const size_t &memSize, bool isReadonly) {
    this->mMemory = new char[memSize];
    this->mIsReadonly = isReadonly;
}
