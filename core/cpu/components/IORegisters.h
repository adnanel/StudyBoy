//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_IOREGISTERS_H
#define STUDYBOY_IOREGISTERS_H


#include "Register.h"

typedef struct {
    Register<Reg8Bit> FF00; // P1
    Register<Reg8Bit> FF01; // SB
    Register<Reg8Bit> FF02; // SC
    Register<Reg8Bit> FF04; // DIV
    Register<Reg8Bit> FF05; // TIMA
    Register<Reg8Bit> FF06; // TMA
    Register<Reg8Bit> FF07; // TAC
    Register<Reg8Bit> FF0F; // IF
    Register<Reg8Bit> FF10; // NR 10
    Register<Reg8Bit> FF11; // NR 11
    Register<Reg8Bit> FF12; // NR 12
    Register<Reg8Bit> FF13; // NR 13
    Register<Reg8Bit> FF14; // NR 14
    Register<Reg8Bit> FF16; // NR 21
    Register<Reg8Bit> FF17; // NR 22
    Register<Reg8Bit> FF18; // NR 23
    Register<Reg8Bit> FF19; // NR 24
    Register<Reg8Bit> FF1A; // NR 30
    Register<Reg8Bit> FF1B; // NR 31
    Register<Reg8Bit> FF1C; // NR 32
    Register<Reg8Bit> FF1D; // NR 33
    Register<Reg8Bit> FF1E; // NR 34
    Register<Reg8Bit> FF20; // NR 41
    Register<Reg8Bit> FF21; // NR 42
    Register<Reg8Bit> FF22; // NR 43
    Register<Reg8Bit> FF23; // NR 44
    Register<Reg8Bit> FF24; // NR 50
    Register<Reg8Bit> FF25; // NR 51
    Register<Reg8Bit> FF26; // NR 52

    Register<Reg8Bit> FF30; // Wave pattern 1
    Register<Reg8Bit> FF31; // Wave pattern 2
    Register<Reg8Bit> FF32; // Wave pattern 3
    Register<Reg8Bit> FF33; // Wave pattern 4
    Register<Reg8Bit> FF34; // Wave pattern 5
    Register<Reg8Bit> FF35; // Wave pattern 6
    Register<Reg8Bit> FF36; // Wave pattern 7
    Register<Reg8Bit> FF37; // Wave pattern 8
    Register<Reg8Bit> FF38; // Wave pattern 9
    Register<Reg8Bit> FF39; // Wave pattern 10
    Register<Reg8Bit> FF3A; // Wave pattern 11
    Register<Reg8Bit> FF3B; // Wave pattern 12
    Register<Reg8Bit> FF3C; // Wave pattern 13
    Register<Reg8Bit> FF3D; // Wave pattern 14
    Register<Reg8Bit> FF3E; // Wave pattern 15
    Register<Reg8Bit> FF3F; // Wave pattern 16

    Register<Reg8Bit> FF40; // LCDC
    Register<Reg8Bit> FF41; // STAT
    Register<Reg8Bit> FF42; // SCY
    Register<Reg8Bit> FF43; // SCX
    Register<Reg8Bit> FF44; // LY
    Register<Reg8Bit> FF45; // LYC
    Register<Reg8Bit> FF46; // DMA

    Register<Reg8Bit> FF47; // BGP
    Register<Reg8Bit> FF48; // OBP0
    Register<Reg8Bit> FF49; // OBP1
    Register<Reg8Bit> FF4A; // WY
    Register<Reg8Bit> FF4B; // WX
    Register<Reg8Bit> FFFF; // IE
} IORegisters;

#endif //STUDYBOY_IOREGISTERS_H
