//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_IOREGISTERS_H
#define STUDYBOY_IOREGISTERS_H


#include <map>
#include "Register.h"

class IORegisters {
    Register<8> FF00; // P1
    Register<8> FF01; // SB
    Register<8> FF02; // SC
    Register<8> FF04; // DIV
    Register<8> FF05; // TIMA
    Register<8> FF06; // TMA
    Register<8> FF07; // TAC
    Register<8> FF0F; // Interrupt Flag (IF)
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

    std::map<unsigned long long, Register<8>*> mRegisterMap;
public:
    IORegisters();

    Register<8> getRegisterByAddress(unsigned long long addr) const {
        auto it = mRegisterMap.find(addr);
        if ( it == mRegisterMap.end() ) {
            throw std::invalid_argument("Invalid register address");
        }
        return *(it->second);
    }

    void setRegisterByAddress(unsigned long long addr, const Register<8>& reg) {
        auto it = mRegisterMap.find(addr);
        if ( it == mRegisterMap.end() ) {
            throw std::invalid_argument("Invalid register address");
        }
        *(it->second) = reg;
    }

    const Register<8> &getFF00() const {
        return FF00;
    }

    void setFF00(const Register<8> &FF00) {
        IORegisters::FF00 = FF00;
    }

    const Register<8> &getFF01() const {
        return FF01;
    }

    void setFF01(const Register<8> &FF01) {
        IORegisters::FF01 = FF01;
    }

    const Register<8> &getFF02() const {
        return FF02;
    }

    void setFF02(const Register<8> &FF02) {
        IORegisters::FF02 = FF02;
    }

    const Register<8> &getFF04() const {
        return FF04;
    }

    void setFF04(const Register<8> &FF04) {
        IORegisters::FF04 = FF04;
    }

    const Register<8> &getFF05() const {
        return FF05;
    }

    void setFF05(const Register<8> &FF05) {
        IORegisters::FF05 = FF05;
    }

    const Register<8> &getFF06() const {
        return FF06;
    }

    void setFF06(const Register<8> &FF06) {
        IORegisters::FF06 = FF06;
    }

    const Register<8> &getFF07() const {
        return FF07;
    }

    void setFF07(const Register<8> &FF07) {
        IORegisters::FF07 = FF07;
    }

    const Register<8> &getFF0F() const {
        return FF0F;
    }

    void setFF0F(const Register<8> &FF0F) {
        IORegisters::FF0F = FF0F;
    }

    const Register<8> &getFF10() const {
        return FF10;
    }

    void setFF10(const Register<8> &FF10) {
        IORegisters::FF10 = FF10;
    }

    const Register<8> &getFF11() const {
        return FF11;
    }

    void setFF11(const Register<8> &FF11) {
        IORegisters::FF11 = FF11;
    }

    const Register<8> &getFF12() const {
        return FF12;
    }

    void setFF12(const Register<8> &FF12) {
        IORegisters::FF12 = FF12;
    }

    const Register<8> &getFF13() const {
        return FF13;
    }

    void setFF13(const Register<8> &FF13) {
        IORegisters::FF13 = FF13;
    }

    const Register<8> &getFF14() const {
        return FF14;
    }

    void setFF14(const Register<8> &FF14) {
        IORegisters::FF14 = FF14;
    }

    const Register<8> &getFF16() const {
        return FF16;
    }

    void setFF16(const Register<8> &FF16) {
        IORegisters::FF16 = FF16;
    }

    const Register<8> &getFF17() const {
        return FF17;
    }

    void setFF17(const Register<8> &FF17) {
        IORegisters::FF17 = FF17;
    }

    const Register<8> &getFF18() const {
        return FF18;
    }

    void setFF18(const Register<8> &FF18) {
        IORegisters::FF18 = FF18;
    }

    const Register<8> &getFF19() const {
        return FF19;
    }

    void setFF19(const Register<8> &FF19) {
        IORegisters::FF19 = FF19;
    }

    const Register<8> &getFF1A() const {
        return FF1A;
    }

    void setFF1A(const Register<8> &FF1A) {
        IORegisters::FF1A = FF1A;
    }

    const Register<8> &getFF1B() const {
        return FF1B;
    }

    void setFF1B(const Register<8> &FF1B) {
        IORegisters::FF1B = FF1B;
    }

    const Register<8> &getFF1C() const {
        return FF1C;
    }

    void setFF1C(const Register<8> &FF1C) {
        IORegisters::FF1C = FF1C;
    }

    const Register<8> &getFF1D() const {
        return FF1D;
    }

    void setFF1D(const Register<8> &FF1D) {
        IORegisters::FF1D = FF1D;
    }

    const Register<8> &getFF1E() const {
        return FF1E;
    }

    void setFF1E(const Register<8> &FF1E) {
        IORegisters::FF1E = FF1E;
    }

    const Register<8> &getFF20() const {
        return FF20;
    }

    void setFF20(const Register<8> &FF20) {
        IORegisters::FF20 = FF20;
    }

    const Register<8> &getFF21() const {
        return FF21;
    }

    void setFF21(const Register<8> &FF21) {
        IORegisters::FF21 = FF21;
    }

    const Register<8> &getFF22() const {
        return FF22;
    }

    void setFF22(const Register<8> &FF22) {
        IORegisters::FF22 = FF22;
    }

    const Register<8> &getFF23() const {
        return FF23;
    }

    void setFF23(const Register<8> &FF23) {
        IORegisters::FF23 = FF23;
    }

    const Register<8> &getFF24() const {
        return FF24;
    }

    void setFF24(const Register<8> &FF24) {
        IORegisters::FF24 = FF24;
    }

    const Register<8> &getFF25() const {
        return FF25;
    }

    void setFF25(const Register<8> &FF25) {
        IORegisters::FF25 = FF25;
    }

    const Register<8> &getFF26() const {
        return FF26;
    }

    void setFF26(const Register<8> &FF26) {
        IORegisters::FF26 = FF26;
    }

    const Register<8> &getFF30() const {
        return FF30;
    }

    void setFF30(const Register<8> &FF30) {
        IORegisters::FF30 = FF30;
    }

    const Register<8> &getFF31() const {
        return FF31;
    }

    void setFF31(const Register<8> &FF31) {
        IORegisters::FF31 = FF31;
    }

    const Register<8> &getFF32() const {
        return FF32;
    }

    void setFF32(const Register<8> &FF32) {
        IORegisters::FF32 = FF32;
    }

    const Register<8> &getFF33() const {
        return FF33;
    }

    void setFF33(const Register<8> &FF33) {
        IORegisters::FF33 = FF33;
    }

    const Register<8> &getFF34() const {
        return FF34;
    }

    void setFF34(const Register<8> &FF34) {
        IORegisters::FF34 = FF34;
    }

    const Register<8> &getFF35() const {
        return FF35;
    }

    void setFF35(const Register<8> &FF35) {
        IORegisters::FF35 = FF35;
    }

    const Register<8> &getFF36() const {
        return FF36;
    }

    void setFF36(const Register<8> &FF36) {
        IORegisters::FF36 = FF36;
    }

    const Register<8> &getFF37() const {
        return FF37;
    }

    void setFF37(const Register<8> &FF37) {
        IORegisters::FF37 = FF37;
    }

    const Register<8> &getFF38() const {
        return FF38;
    }

    void setFF38(const Register<8> &FF38) {
        IORegisters::FF38 = FF38;
    }

    const Register<8> &getFF39() const {
        return FF39;
    }

    void setFF39(const Register<8> &FF39) {
        IORegisters::FF39 = FF39;
    }

    const Register<8> &getFF3A() const {
        return FF3A;
    }

    void setFF3A(const Register<8> &FF3A) {
        IORegisters::FF3A = FF3A;
    }

    const Register<8> &getFF3B() const {
        return FF3B;
    }

    void setFF3B(const Register<8> &FF3B) {
        IORegisters::FF3B = FF3B;
    }

    const Register<8> &getFF3C() const {
        return FF3C;
    }

    void setFF3C(const Register<8> &FF3C) {
        IORegisters::FF3C = FF3C;
    }

    const Register<8> &getFF3D() const {
        return FF3D;
    }

    void setFF3D(const Register<8> &FF3D) {
        IORegisters::FF3D = FF3D;
    }

    const Register<8> &getFF3E() const {
        return FF3E;
    }

    void setFF3E(const Register<8> &FF3E) {
        IORegisters::FF3E = FF3E;
    }

    const Register<8> &getFF3F() const {
        return FF3F;
    }

    void setFF3F(const Register<8> &FF3F) {
        IORegisters::FF3F = FF3F;
    }

    const Register<8> &getFF40() const {
        return FF40;
    }

    void setFF40(const Register<8> &FF40) {
        IORegisters::FF40 = FF40;
    }

    const Register<8> &getFF41() const {
        return FF41;
    }

    void setFF41(const Register<8> &FF41) {
        IORegisters::FF41 = FF41;
    }

    const Register<8> &getFF42() const {
        return FF42;
    }

    void setFF42(const Register<8> &FF42) {
        IORegisters::FF42 = FF42;
    }

    const Register<8> &getFF43() const {
        return FF43;
    }

    void setFF43(const Register<8> &FF43) {
        IORegisters::FF43 = FF43;
    }

    const Register<8> &getFF44() const {
        return FF44;
    }

    void setFF44(const Register<8> &FF44) {
        IORegisters::FF44 = FF44;
    }

    const Register<8> &getFF45() const {
        return FF45;
    }

    void setFF45(const Register<8> &FF45) {
        IORegisters::FF45 = FF45;
    }

    const Register<8> &getFF46() const {
        return FF46;
    }

    void setFF46(const Register<8> &FF46) {
        IORegisters::FF46 = FF46;
    }

    const Register<8> &getFF47() const {
        return FF47;
    }

    void setFF47(const Register<8> &FF47) {
        IORegisters::FF47 = FF47;
    }

    const Register<8> &getFF48() const {
        return FF48;
    }

    void setFF48(const Register<8> &FF48) {
        IORegisters::FF48 = FF48;
    }

    const Register<8> &getFF49() const {
        return FF49;
    }

    void setFF49(const Register<8> &FF49) {
        IORegisters::FF49 = FF49;
    }

    const Register<8> &getFF4A() const {
        return FF4A;
    }

    void setFF4A(const Register<8> &FF4A) {
        IORegisters::FF4A = FF4A;
    }

    const Register<8> &getFF4B() const {
        return FF4B;
    }

    void setFF4B(const Register<8> &FF4B) {
        IORegisters::FF4B = FF4B;
    }

    const Register<8> &getFFFF() const {
        return FFFF;
    }

    void setFFFF(const Register<8> &FFFF) {
        IORegisters::FFFF = FFFF;
    }
};


#endif //STUDYBOY_IOREGISTERS_H
