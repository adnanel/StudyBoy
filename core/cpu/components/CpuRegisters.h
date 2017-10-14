//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_CPUREGISTERS_H
#define STUDYBOY_CPUREGISTERS_H

#include "Register.h"

typedef struct {
    Register<Reg8Bit> A;
    Register<Reg8Bit> B;
    Register<Reg8Bit> C;
    Register<Reg8Bit> D;
    Register<Reg8Bit> E;
    Register<Reg8Bit> F;
    Register<Reg8Bit> H;
    Register<Reg8Bit> L;

    Register<Reg16Bit> SP;
    Register<Reg16Bit> PC;
} CpuRegisters;

#endif //STUDYBOY_CPUREGISTERS_H
