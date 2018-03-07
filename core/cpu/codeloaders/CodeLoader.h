//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_CODELOADER_H
#define STUDYBOY_CODELOADER_H


#include <cstdio>
#include <cstring>
#include "../components/Register.h"
#include "../../memory/MemoryMap.h"

class CodeLoader {
    MemoryMap mCodeMemory;
public:
    CodeLoader(char* data, size_t size) : mCodeMemory(size, true, data) {
    }
    CodeLoader(const CodeLoader&) = delete;
    CodeLoader& operator=(const CodeLoader&) = delete;
/*
    char operator[](size_t index) const {
        return mCodeMemory[index];
    }
*/

    template<unsigned int N>
    Register<N * 8> ReadBytes(size_t addr) {
        return mCodeMemory.ReadData<N * 8>(addr);
    }

    const MemoryMap* getMemoryMap() const {
        return &mCodeMemory;
    }
    MemoryMap* getMemoryMap() {
        return &mCodeMemory;
    }

};


#endif //STUDYBOY_CODELOADER_H
