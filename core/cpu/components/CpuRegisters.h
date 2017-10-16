//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_CPUREGISTERS_H
#define STUDYBOY_CPUREGISTERS_H

#include "Register.h"

class CpuRegisters {
private:
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
public:

    const Register<8> &getA() const {
        return A;
    }

    void setA(const Register<8> &A) {
        CpuRegisters::A = A;
    }

    const Register<8> &getB() const {
        return B;
    }

    void setB(const Register<8> &B) {
        CpuRegisters::B = B;
    }

    const Register<8> &getC() const {
        return C;
    }

    void setC(const Register<8> &C) {
        CpuRegisters::C = C;
    }

    const Register<8> &getD() const {
        return D;
    }

    void setD(const Register<8> &D) {
        CpuRegisters::D = D;
    }

    const Register<8> &getE() const {
        return E;
    }

    void setE(const Register<8> &E) {
        CpuRegisters::E = E;
    }

    const Register<8> &getF() const {
        return F;
    }

    void setF(const Register<8> &F) {
        CpuRegisters::F = F;
    }

    const Register<8> &getH() const {
        return H;
    }

    void setH(const Register<8> &H) {
        CpuRegisters::H = H;
    }

    const Register<8> &getL() const {
        return L;
    }

    void setL(const Register<8> &L) {
        CpuRegisters::L = L;
    }

    const Register<16> &getSP() const {
        return SP;
    }

    void setSP(const Register<16> &SP) {
        CpuRegisters::SP = SP;
    }

    const Register<16> &getPC() const {
        return PC;
    }

    void setPC(const Register<16> &PC) {
        CpuRegisters::PC = PC;
    }

    void setHL(const Register<16>& hl) {
        SplitRegister(hl, H, L);
    }

    void setBC(const Register<16>& hl) {
        SplitRegister(hl, B, C);
    }

    void setDE(const Register<16>& hl) {
        SplitRegister(hl, D, E);
    }

    void setAF(const Register<16>& af) {
        SplitRegister(af, A, F);
    }

    Register<16> getBC() const {
        return CombineRegisters<8,8>(B, C);
    }

    Register<16> getDE() const {
        return CombineRegisters<8,8>(D, E);
    }

    Register<16> getHL() const {
        return CombineRegisters<8,8>(H, L);
    }

    Register<16> getAF() const {
        return CombineRegisters<8,8>(A, F);
    }
};

#endif //STUDYBOY_CPUREGISTERS_H
