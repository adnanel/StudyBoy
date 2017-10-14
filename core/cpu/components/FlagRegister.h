//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_FLAGREGISTER_H
#define STUDYBOY_FLAGREGISTER_H

#include "Register.h"

class FlagRegister {
    Register<8> mFlags;

    /*
    Bits in mFlags:
    | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
    | Z | N | H | C | 0 | 0 | 0 | 0 |
     */
public:
    FlagRegister();

    inline bool getZ() const {
        return mFlags[7];
    }

    inline void setZ(bool set) {
        mFlags[7] = set;
    }

    inline bool getN() const {

    }
    inline void setN(bool set) {
        mFlags[6] = set;
    }

    inline bool getH() const {

    }
    inline void setH(bool set) {
        mFlags[5] = set;
    }

    inline bool getC() const {

    }
    inline void setC(bool set) {
        mFlags[4] = set;
    }
};


#endif //STUDYBOY_FLAGREGISTER_H
