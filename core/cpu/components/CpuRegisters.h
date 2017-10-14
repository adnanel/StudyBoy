//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_CPUREGISTERS_H
#define STUDYBOY_CPUREGISTERS_H

#include "Register.h"

typedef struct {
    Register<8> A;
    Register<8> B;
    Register<8> C;
    Register<8> D;
    Register<8> E;
    Register<8> F;
    Register<8> H;
    Register<8> L;

    Register<16> SP;
    Register<16> PC;
} CpuRegisters;

#endif //STUDYBOY_CPUREGISTERS_H
