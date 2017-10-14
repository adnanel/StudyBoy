//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_IOREGISTERS_H
#define STUDYBOY_IOREGISTERS_H


#include "Register.h"

typedef struct {
    Register<8> FF00; // P1
    Register<8> FF01; // SB
    Register<8> FF02; // SC
    Register<8> FF04; // DIV
    Register<8> FF05; // TIMA
    Register<8> FF06; // TMA
    Register<8> FF07; // TAC
    Register<8> FF0F; // IF
    Register<8> FF10; // NR 10
    Register<8> FF11; // NR 11
    Register<8> FF12; // NR 12
    Register<8> FF13; // NR 13
    Register<8> FF14; // NR 14
    Register<8> FF16; // NR 21
    Register<8> FF17; // NR 22
    Register<8> FF18; // NR 23
    Register<8> FF19; // NR 24
    Register<8> FF1A; // NR 30
    Register<8> FF1B; // NR 31
    Register<8> FF1C; // NR 32
    Register<8> FF1D; // NR 33
    Register<8> FF1E; // NR 34
    Register<8> FF20; // NR 41
    Register<8> FF21; // NR 42
    Register<8> FF22; // NR 43
    Register<8> FF23; // NR 44
    Register<8> FF24; // NR 50
    Register<8> FF25; // NR 51
    Register<8> FF26; // NR 52

    Register<8> FF30; // Wave pattern 1
    Register<8> FF31; // Wave pattern 2
    Register<8> FF32; // Wave pattern 3
    Register<8> FF33; // Wave pattern 4
    Register<8> FF34; // Wave pattern 5
    Register<8> FF35; // Wave pattern 6
    Register<8> FF36; // Wave pattern 7
    Register<8> FF37; // Wave pattern 8
    Register<8> FF38; // Wave pattern 9
    Register<8> FF39; // Wave pattern 10
    Register<8> FF3A; // Wave pattern 11
    Register<8> FF3B; // Wave pattern 12
    Register<8> FF3C; // Wave pattern 13
    Register<8> FF3D; // Wave pattern 14
    Register<8> FF3E; // Wave pattern 15
    Register<8> FF3F; // Wave pattern 16

    Register<8> FF40; // LCDC
    Register<8> FF41; // STAT
    Register<8> FF42; // SCY
    Register<8> FF43; // SCX
    Register<8> FF44; // LY
    Register<8> FF45; // LYC
    Register<8> FF46; // DMA

    Register<8> FF47; // BGP
    Register<8> FF48; // OBP0
    Register<8> FF49; // OBP1
    Register<8> FF4A; // WY
    Register<8> FF4B; // WX
    Register<8> FFFF; // IE
} IORegisters;

#endif //STUDYBOY_IOREGISTERS_H
