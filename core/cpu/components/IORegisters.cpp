//
// Created by prg01 on 10/18/2017.
//

#include "IORegisters.h"

IORegisters::IORegisters() {
    mRegisterMap[0xff00] = &FF00;
    mRegisterMap[0xFF01] = &FF01;
    mRegisterMap[0xFF02] = &FF02;

    mRegisterMap[0xFF04] = &FF04;
    mRegisterMap[0xFF05] = &FF05;
    mRegisterMap[0xFF06] = &FF06;
    mRegisterMap[0xFF07] = &FF07;

    mRegisterMap[0xFF0F] = &FF0F;
    mRegisterMap[0xFF10] = &FF10;
    mRegisterMap[0xFF11] = &FF11;
    mRegisterMap[0xFF12] = &FF12;
    mRegisterMap[0xFF13] = &FF13;
    mRegisterMap[0xFF14] = &FF14;

    mRegisterMap[0xFF16] = &FF16;
    mRegisterMap[0xFF17] = &FF17;
    mRegisterMap[0xFF18] = &FF18;
    mRegisterMap[0xFF19] = &FF19;
    mRegisterMap[0xFF1A] = &FF1A;
    mRegisterMap[0xFF1B] = &FF1B;
    mRegisterMap[0xFF1C] = &FF1C;
    mRegisterMap[0xFF1D] = &FF1D;
    mRegisterMap[0xFF1E] = &FF1E;

    mRegisterMap[0xFF20] = &FF20;
    mRegisterMap[0xFF21] = &FF21;
    mRegisterMap[0xFF22] = &FF22;
    mRegisterMap[0xFF23] = &FF23;
    mRegisterMap[0xFF24] = &FF24;
    mRegisterMap[0xFF25] = &FF25;
    mRegisterMap[0xFF26] = &FF26;

    mRegisterMap[0xFF30] = &FF30;
    mRegisterMap[0xFF31] = &FF31;
    mRegisterMap[0xFF32] = &FF32;
    mRegisterMap[0xFF33] = &FF33;
    mRegisterMap[0xFF34] = &FF34;
    mRegisterMap[0xFF35] = &FF35;
    mRegisterMap[0xFF36] = &FF36;
    mRegisterMap[0xFF37] = &FF37;
    mRegisterMap[0xFF38] = &FF38;
    mRegisterMap[0xFF39] = &FF39;
    mRegisterMap[0xFF3A] = &FF3A;
    mRegisterMap[0xFF3B] = &FF3B;
    mRegisterMap[0xFF3C] = &FF3C;
    mRegisterMap[0xFF3D] = &FF3D;
    mRegisterMap[0xFF3E] = &FF3E;
    mRegisterMap[0xFF3F] = &FF3F;
    mRegisterMap[0xFF40] = &FF40;
    mRegisterMap[0xFF41] = &FF41;
    mRegisterMap[0xFF42] = &FF42;
    mRegisterMap[0xFF43] = &FF43;
    mRegisterMap[0xFF44] = &FF44;
    mRegisterMap[0xFF45] = &FF45;
    mRegisterMap[0xFF46] = &FF46;
    mRegisterMap[0xFF47] = &FF47;
    mRegisterMap[0xFF48] = &FF48;
    mRegisterMap[0xFF49] = &FF49;
    mRegisterMap[0xFF4A] = &FF4A;
    mRegisterMap[0xFF4B] = &FF4B;

    mRegisterMap[0xFFFF] = &FFFF;

}
