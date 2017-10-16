//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_CODELOADER_H
#define STUDYBOY_CODELOADER_H


#include <cstdio>
#include <cstring>

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


};


#endif //STUDYBOY_CODELOADER_H
