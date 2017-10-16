//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_CODELOADER_H
#define STUDYBOY_CODELOADER_H


#include <cstdio>
#include <cstring>
#include "../components/Register.h"

class CodeLoader {
    unsigned char* mCodeMemory;
public:
    CodeLoader(const unsigned char* data, size_t size) {
        mCodeMemory = new unsigned char[size];
        memcpy(mCodeMemory, data, size);
    }

    unsigned char operator[](size_t index) const {
        return mCodeMemory[index];
    }


    template<unsigned int N>
    Register<N * 8> ReadBytes(size_t addr, int bytes) {
        Register<N * 8> res = 0;

        for ( auto i = addr; i < addr + bytes; ++ i ) {
            res = (res << 8) | mCodeMemory[ i ];
        }
        return res;
    }

};


#endif //STUDYBOY_CODELOADER_H
