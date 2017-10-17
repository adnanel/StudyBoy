//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_CODELOADER_H
#define STUDYBOY_CODELOADER_H


#include <cstdio>
#include <cstring>
#include "../components/Register.h"

class CodeLoader {
    char* mCodeMemory;
    size_t mCodeSize;

public:
    CodeLoader(char* data, size_t size) {
        mCodeMemory = data;
        mCodeSize = size;
    }
    CodeLoader(const CodeLoader&) = delete;
    CodeLoader& operator=(const CodeLoader&) = delete;

    char operator[](size_t index) const {
        return mCodeMemory[index];
    }


    template<unsigned int N>
    Register<N * 8> ReadBytes(size_t addr) {
        addr /= 4;

        Register<N * 8> res = 0;

        for ( auto i = addr; i < addr + N; ++ i ) {
            res = (res << 8) | mCodeMemory[ i ];
        }
        return res;
    }

    virtual ~CodeLoader() {
        delete[] mCodeMemory;
    }
};


#endif //STUDYBOY_CODELOADER_H
