//
// Created by adnan on 14/10/2017.
//

#include <cassert>
#include "Instruction.h"
#include <stdexcept>

namespace Instruction {

    void update_flags_adc_8(const Register<8> &oldVal,
                            const Register<8> &newVal,
                            const Register<8> &r8,
                            GameBoyCore *core,
                            unsigned long long) {

        bool c = ((oldVal.to_ullong() ^ r8.to_ullong() ^ newVal.to_ullong()) & 0x100) == 0x100;
        bool h = ((oldVal.to_ullong() ^ r8.to_ullong() ^ newVal.to_ullong()) & 0x10) == 0x10;

        core->SetFlags(newVal.to_ullong() == 0, false, c, h);
    }

    void update_flags_add_8(const Register<8> &oldVal,
                            const Register<8> &newVal,
                            const Register<8> &r8,
                            GameBoyCore *core,
                            unsigned long long opcode) {
        bool c = ((oldVal.to_ullong() ^ r8.to_ullong() ^ newVal.to_ullong()) & 0x100) == 0x100;
        bool h = ((oldVal.to_ullong() ^ r8.to_ullong() ^ newVal.to_ullong()) & 0x10) == 0x10;

        core->SetFlags(newVal.to_ullong() == 0, false, c, h);
    }

    void update_flags_dec_8(const Register<8> &oldVal,
                            const Register<8> &newVal,
                            GameBoyCore *core,
                            unsigned long long) {
        // doesn't affect flags
    }


    void update_flags_cp_8(const Register<8> &oldVal,
                           const Register<8> &newVal,
                           const Register<8> &op,
                           GameBoyCore *core,
                           unsigned long long opcode) {
        bool hFlag = ((oldVal.to_ullong() - op.to_ullong()) & 0xF) > (oldVal.to_ullong() & 0xF);

        core->SetFlags(newVal.to_ullong() == 0, true, hFlag, oldVal.to_ullong() < op.to_ullong());
    }


    void update_flags_sub_8(const Register<8> &oldVal,
                            const Register<8> &newVal,
                            const Register<8> &op,
                            GameBoyCore *core,
                            unsigned long long opcode) {
        /*
    Z - Set if result is zero.
    N - Set.
    H - Set if no borrow from bit 4.
    C - Set if no borrow.
     */


        bool cFlag = oldVal.to_ullong() < op.to_ullong();
        bool hFlag = ((oldVal.to_ullong() - op.to_ullong()) & 0xF) > (oldVal.to_ullong() & 0xF);

        core->SetFlags(newVal.to_ullong() == 0, true, hFlag, cFlag);
    }

    void update_flags_sbc_8(const Register<8> &oldVal,
                            const Register<8> &newVal,
                            const Register<8> &op,
                            GameBoyCore *core,
                            unsigned long long opcode) {
        /*
    Z - Set if result is zero.
    N - Set.
    H - Set if no borrow from bit 4.
    C - Set if no borrow.
     */

        bool cFlag = oldVal.to_ullong() < op.to_ullong();
        bool hFlag = ((oldVal.to_ullong() - op.to_ullong()) & 0xF) > (oldVal.to_ullong() & 0xF);

        core->SetFlags(newVal.to_ullong() == 0, true, hFlag, cFlag);
    }

    void update_flags_and_8(const Register<8> &oldVal,
                            const Register<8> &newVal,
                            GameBoyCore *core,
                            unsigned long long opcode) {
        core->SetFlags(newVal.to_ullong() == 0, false, true, false);
    }

    void update_flags_or_8(const Register<8> &oldVal,
                           const Register<8> &newVal,
                           GameBoyCore *core,
                           unsigned long long opcode) {
        core->SetFlags(newVal.to_ullong() == 0, false, false, false);
    }

    void update_flags_xor_8(const Register<8> &oldVal,
                            const Register<8> &newVal,
                            GameBoyCore *core,
                            unsigned long long opcode) {
        core->SetFlags(newVal.to_ullong() == 0, false, false, false);
    }

    void update_flags_add_16(const Register<16> &oldVal,
                             const Register<16> &newVal,
                             const Register<16> &op,
                             GameBoyCore *core,
                             unsigned long long opcode) {
        /*
        Z - Not affected.
        N - Reset.
        H - Set if carry from bit 11.
        C - Set if carry from bit 15.
     */

        core->getCpu()->setNFlag(false);

        core->getCpu()->setCFlag(((oldVal.to_ullong() ^ op.to_ullong() ^ newVal.to_ullong()) & 0x10000) == 0x10000);
        core->getCpu()->setHFlag(((oldVal.to_ullong() ^ op.to_ullong() ^ newVal.to_ullong()) & 0x1000) == 0x1000);
    }

    void update_flags_dec_16(const Register<16> &oldVal,
                             const Register<16> &newVal,
                             GameBoyCore *core,
                             unsigned long long opcode) {
        // doesn't affect flags.
    }


    void update_flags_inc_16(const Register<16> &oldVal,
                             const Register<16> &newVal,
                             GameBoyCore *core,
                             unsigned long long opcode) {
        // doesn't affect flags.
    }


    void update_flags_inc_8(const Register<8> &oldVal,
                            const Register<8> &newVal,
                            GameBoyCore *core,
                            unsigned long long opcode) {
        // doesn't affect flags.
    }


// RET NZ
    void ret_nz_(GameBoyCore *core, unsigned long long opcode) {
        if (core->getCpu()->getZFlag())
            return;

        ret__(core, opcode);
    }

// RET
    void ret__(GameBoyCore *core, unsigned long long) {
        // pop 2 bytes from stack and jump to that address
        core->getCpu()->getCpuRegisters()->setPC(core->PopStack<16>().to_ullong() - 1);
    }

// RET Z
    void ret_z_(GameBoyCore *core, unsigned long long opcode) {
        if (!core->getCpu()->getZFlag())
            return;

        ret__(core, opcode);
    }

// RET NC
    void ret_nc_(GameBoyCore *core, unsigned long long opcode) {
        if (core->getCpu()->getCFlag())
            return;

        ret__(core, opcode);
    }

// RET C
    void ret_c_(GameBoyCore *core, unsigned long long opcode) {
        if (!core->getCpu()->getCFlag())
            return;

        ret__(core, opcode);
    }

// RRA
    void rra__(GameBoyCore *core, unsigned long long) {
        auto reg = core->getCpu()->getCpuRegisters()->getA();
        bool old = reg[0];
        Register<8> oldCarry = core->getCpu()->getCFlag();

        reg = (reg >> 1) | (oldCarry << 7);

        core->getCpu()->getCpuRegisters()->setA(reg);

        core->SetFlags(!reg.any(), false, false, old);
    }


// ADC A (HL)
    void adc_a__hl_(GameBoyCore *core, unsigned long long opcode) {
        // A += MEMORY[ HL ]
        auto cReg = core->getCpu()->getCpuRegisters()->getA();
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        auto oldVal = cReg;
        auto op = core->ReadData8(hl.to_ullong());
        op = op.to_ullong() + static_cast<int>(core->getCpu()->getCFlag());

        cReg += op;

        core->getCpu()->getCpuRegisters()->setA(cReg);

        update_flags_adc_8(oldVal, cReg, op, core, opcode);
    }

// ADC A L
    void adc_a_l(GameBoyCore *core, unsigned long long opcode) {
        auto cReg = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = cReg;
        auto l = core->getCpu()->getCpuRegisters()->getL();
        l += static_cast<int>(core->getCpu()->getCFlag());

        cReg += l;

        update_flags_adc_8(oldVal, cReg, l, core, opcode);
    }

// ADC A H
    void adc_a_h(GameBoyCore *core, unsigned long long opcode) {
        auto cReg = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = cReg;
        auto h = core->getCpu()->getCpuRegisters()->getH();
        h += static_cast<int>(core->getCpu()->getCFlag());

        cReg += h;

        core->getCpu()->getCpuRegisters()->setA(cReg);

        update_flags_adc_8(oldVal, cReg, h, core, opcode);
    }

// ADC A E
    void adc_a_e(GameBoyCore *core, unsigned long long opcode) {
        auto cReg = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = cReg;
        auto e = core->getCpu()->getCpuRegisters()->getE();
        e += static_cast<int>(core->getCpu()->getCFlag());

        cReg += e;

        core->getCpu()->getCpuRegisters()->setA(cReg);

        update_flags_adc_8(oldVal, cReg, e, core, opcode);
    }

// ADC A D
    void adc_a_d(GameBoyCore *core, unsigned long long opcode) {
        auto cReg = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = cReg;
        auto d = core->getCpu()->getCpuRegisters()->getD();
        d += static_cast<int>(core->getCpu()->getCFlag());

        cReg += d;

        core->getCpu()->getCpuRegisters()->setA(cReg);

        update_flags_adc_8(oldVal, cReg, d, core, opcode);
    }


// ADD A d8
    void add_a_d8(GameBoyCore *core, unsigned long long opcode) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

        auto d8 = core->ReadData8(pc.to_ullong() + 1);

        auto oldVal = core->getCpu()->getCpuRegisters()->getA();
        auto newVal = oldVal + d8;

        core->getCpu()->getCpuRegisters()->setA(newVal.to_ullong());
        update_flags_add_8(oldVal, newVal, d8, core, opcode);
    }

// ADD A C
    void add_a_c(GameBoyCore *core, unsigned long long opcode) {
        auto cReg = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = cReg;

        auto c = core->getCpu()->getCpuRegisters()->getC();
        cReg += c;

        core->getCpu()->getCpuRegisters()->setA(cReg);

        update_flags_add_8(oldVal, cReg, c, core, opcode);
    }

// ADD A B
    void add_a_b(GameBoyCore *core, unsigned long long opcode) {
        auto cReg = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = cReg;
        auto b = core->getCpu()->getCpuRegisters()->getB();

        cReg += b;

        core->getCpu()->getCpuRegisters()->setA(cReg);

        update_flags_add_8(oldVal, cReg, b, core, opcode);
    }

// ADD A A
    void add_a_a(GameBoyCore *core, unsigned long long opcode) {
        auto cReg = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = cReg;

        cReg += cReg;

        core->getCpu()->getCpuRegisters()->setA(cReg);

        update_flags_add_8(oldVal, cReg, oldVal, core, opcode);
    }

// ADD HL DE
    void add_hl_de(GameBoyCore *core, unsigned long long opcode) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();
        auto de = core->getCpu()->getCpuRegisters()->getDE();
        auto oldVal = hl;

        hl += de;

        core->getCpu()->getCpuRegisters()->setHL(hl);

        update_flags_add_16(oldVal, hl, de, core, opcode);
    }

// ADC A d8
    void adc_a_d8(GameBoyCore *core, unsigned long long opcode) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);
        auto oldVal = core->getCpu()->getCpuRegisters()->getA();

        auto d8 = core->ReadData8(pc.to_ullong() + 1);
        d8 = d8.to_ullong() + static_cast<int>(core->getCpu()->getCFlag());

        auto newVal = oldVal + d8.to_ullong();

        core->getCpu()->getCpuRegisters()->setA(newVal);

        update_flags_adc_8(oldVal, newVal, d8, core, opcode);
    }

// ADD HL HL
    void add_hl_hl(GameBoyCore *core, unsigned long long opcode) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();
        auto oldVal = hl;
        hl += hl;

        core->getCpu()->getCpuRegisters()->setHL(hl);

        update_flags_add_16(oldVal, hl, hl, core, opcode);
    }

// ADD SP r8
    void add_sp_r8(GameBoyCore *core, unsigned long long opcode) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

        auto oldVal = core->getCpu()->getCpuRegisters()->getSP();
        auto data = core->ReadData8(pc.to_ullong() + 1);
        auto newVal = oldVal + data;

        Register<16> op = data.to_ullong();
        update_flags_add_16(oldVal, newVal, op, core, opcode);
        core->getCpu()->setZFlag(false);
        core->getCpu()->setNFlag(false);
    }

// ADD HL SP
    void add_hl_sp(GameBoyCore *core, unsigned long long opcode) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();
        auto sp = core->getCpu()->getCpuRegisters()->getSP();
        auto oldVal = hl;

        hl += sp;

        core->getCpu()->getCpuRegisters()->setHL(hl);

        update_flags_add_16(oldVal, hl, sp, core, opcode);
    }

// ADD HL BC
    void add_hl_bc(GameBoyCore *core, unsigned long long opcode) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();
        auto bc = core->getCpu()->getCpuRegisters()->getBC();
        auto oldVal = hl;

        hl += bc;

        core->getCpu()->getCpuRegisters()->setHL(hl);

        update_flags_add_16(oldVal, hl, bc, core, opcode);
    }

// ADC A A
    void adc_a_a(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = a;

        a += a;
        a += static_cast<int>(core->getCpu()->getCFlag());

        core->getCpu()->getCpuRegisters()->setA(a);

        update_flags_adc_8(oldVal, a, oldVal, core, opcode);
    }

// ADD A (HL)
    void add_a__hl_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getA();
        auto op = core->ReadData8(core->getCpu()->getCpuRegisters()->getHL().to_ullong());
        auto newVal = oldVal.to_ullong() + op.to_ullong();

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_add_8(oldVal.to_ullong(), newVal, op, core, opcode);
    }

// ADD A L
    void add_a_l(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getA();
        auto op = core->getCpu()->getCpuRegisters()->getL();
        auto newVal = oldVal + op;

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_add_8(oldVal.to_ullong(), newVal.to_ullong(), op, core, opcode);
    }

// ADD A H
    void add_a_h(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getA();
        auto op = core->getCpu()->getCpuRegisters()->getH();
        auto newVal = oldVal + op;

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_add_8(oldVal.to_ullong(), newVal.to_ullong(), op, core, opcode);
    }

// ADD A E
    void add_a_e(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getA();
        auto op = core->getCpu()->getCpuRegisters()->getE();
        auto newVal = oldVal + op;

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_add_8(oldVal.to_ullong(), newVal.to_ullong(), op, core, opcode);
    }

// ADD A D
    void add_a_d(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getA();
        auto op = core->getCpu()->getCpuRegisters()->getD();
        auto newVal = oldVal + op;

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_add_8(oldVal.to_ullong(), newVal.to_ullong(), op, core, opcode);
    }

// ADC A C
    void adc_a_c(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getA();
        auto c = core->getCpu()->getCpuRegisters()->getC() + core->getCpu()->getCFlag();
        auto newVal = oldVal + c;

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_adc_8(oldVal.to_ullong(), newVal.to_ullong(), c, core, opcode);
    }

// ADC A B
    void adc_a_b(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getB() + core->getCpu()->getCFlag();
        auto newVal = oldVal + b;

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_adc_8(oldVal.to_ullong(), newVal.to_ullong(), b, core, opcode);
    }

// CALL NZ a16
    void call_nz_a16(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 2);
        if (core->getCpu()->getZFlag()) {
            return;
        }
        core->PushToStack(pc + 3);

        auto a16 = core->ReadData16(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
    }

// CALL NC a16
    void call_nc_a16(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 2);
        if (core->getCpu()->getCFlag()) {
            return;
        }
        core->PushToStack(pc + 3);

        auto a16 = core->ReadData16(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
    }

// CALL a16
    void call_a16_(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
		core->getCpu()->getCpuRegisters()->setPC(pc + 2);

        core->PushToStack(pc + 3);

        auto a16 = core->ReadData16(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
    }

// CALL Z a16
    void call_z_a16(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 2);
        if (!core->getCpu()->getZFlag()) {
            return;
        }
        core->PushToStack(pc + 3);

        auto a16 = core->ReadData16(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
    }

// CALL C a16
    void call_c_a16(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 2);
        if (!core->getCpu()->getCFlag()) {
            return;
        }
        core->PushToStack(pc + 3);

        auto a16 = core->ReadData16(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
    }

// DI
    void di__(GameBoyCore *core, unsigned long long) {
        core->setInterruptsEnabled(false);
    }

// JP NZ a16
    void jp_nz_a16(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 1);

        auto a16 = core->ReadData16(pc.to_ullong() + 1);
        if (core->getCpu()->getZFlag()) {
            return;
        }

        core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
    }

// JP a16
    void jp_a16_(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();

        auto a16 = core->ReadData16(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
    }

// JP NC a16
    void jp_nc_a16(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 1);

        auto a16 = core->ReadData16(pc.to_ullong() + 1);
        if (core->getCpu()->getCFlag()) {
            return;
        }

        core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
    }

// JP (HL)
    void jp__hl__(GameBoyCore *core, unsigned long long) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();
        auto data = core->ReadData16(hl.to_ullong());

        core->getCpu()->getCpuRegisters()->setPC(data.to_ullong() - 1);
    }

// JP Z a16
    void jp_z_a16(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 1);

        auto a16 = core->ReadData16(pc.to_ullong() + 1);
        if (!core->getCpu()->getZFlag()) {
            return;
        }

        core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
    }

// JP C a16
    void jp_c_a16(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 1);

        auto a16 = core->ReadData16(pc.to_ullong() + 1);
        if (!core->getCpu()->getCFlag()) {
            return;
        }

        core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
    }

// RLA
    void rla__(GameBoyCore *core, unsigned long long) {
        auto a = core->getCpu()->getCpuRegisters()->getA();

        auto carry = (a >> 7).to_ullong();
        assert(carry == 0 || carry == 1);

        a = (a << 1) | static_cast<int>(core->getCpu()->getCFlag());

        /*
        Z - Set if result is zero.
        N - Reset.
        H - Reset.
        C - Contains old bit 7 data.
     */
        core->getCpu()->setZFlag(a.to_ullong() == 0);
        core->getCpu()->setNFlag(false);
        core->getCpu()->setHFlag(false);
        core->getCpu()->setCFlag(static_cast<bool>(carry));

        core->getCpu()->getCpuRegisters()->setA(a);
    }

// JR r8
    void jr_r8_(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();

        auto data = core->ReadData8(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + data.to_ullong() - 1);
    }

// JR NZ r8
    void jr_nz_r8(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 1);
        if (core->getCpu()->getZFlag()) return;

        auto data = core->ReadData8(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + data.to_ullong());
    }

// JR Z r8
    void jr_z_r8(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 1);
        if (!core->getCpu()->getZFlag()) return;

        auto data = core->ReadData8(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + data.to_ullong());
    }

// JR NC r8
    void jr_nc_r8(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 1);
        if (core->getCpu()->getCFlag()) return;

        auto data = core->ReadData8(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + data.to_ullong());
    }

// JR C r8
    void jr_c_r8(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 1);
        if (!core->getCpu()->getCFlag()) return;

        auto data = core->ReadData8(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + data.to_ullong());
    }

// RETI
    void reti__(GameBoyCore *core, unsigned long long opcode) {
        auto pc = core->PopStack<16>().to_ullong() - 1;
        core->getCpu()->getCpuRegisters()->setPC(pc);
        ei__(core, opcode);
    }

// LDH (a8) A
    void ldh__a8__a(GameBoyCore *core, unsigned long long) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 1);

        Register<16> a16 = 0xFF00 + core->ReadData8(pc.to_ullong() + 1).to_ullong();

        core->WriteData8(a16.to_ullong(), a);
    }

// LDH A (a8)
    void ldh_a__a8_(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

        Register<16> a16 = 0xFF00 + core->ReadData8(pc.to_ullong() + 1).to_ullong();

        auto data = core->ReadData8(a16.to_ullong());

        core->getCpu()->getCpuRegisters()->setA(data);
    }

// SBC A d8
    void sbc_a_d8(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

        auto data = core->ReadData8(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setA(data);
    }

// SBC A B
    void sbc_a_b(GameBoyCore *core, unsigned long long opcode) {
        auto op = core->getCpu()->getCpuRegisters()->getB();
        auto carry = static_cast<int>(core->getCpu()->getCFlag());

        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = a;

        op += carry;
        a -= op;
        core->getCpu()->getCpuRegisters()->setA(a);

        update_flags_sbc_8(oldVal, a, op, core, opcode);
    }

// SBC A C
    void sbc_a_c(GameBoyCore *core, unsigned long long opcode) {
        auto op = core->getCpu()->getCpuRegisters()->getC();
        auto carry = static_cast<int>(core->getCpu()->getCFlag());

        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = a;

        op += carry;
        a -= op;
        core->getCpu()->getCpuRegisters()->setA(a);

        update_flags_sbc_8(oldVal, a, op, core, opcode);
    }

// SBC A A
    void sbc_a_a(GameBoyCore *core, unsigned long long opcode) {
        auto op = core->getCpu()->getCpuRegisters()->getA();
        auto carry = static_cast<int>(core->getCpu()->getCFlag());

        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = a;

        op += carry;
        a -= op;
        core->getCpu()->getCpuRegisters()->setA(a);

        update_flags_sbc_8(oldVal, a, op, core, opcode);
    }

// SBC A (HL)
    void sbc_a__hl_(GameBoyCore *core, unsigned long long opcode) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        auto op = core->ReadData8(hl.to_ullong()).to_ullong();
        auto carry = static_cast<int>(core->getCpu()->getCFlag());

        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = a;

        op += carry;
        a -= op;
        core->getCpu()->getCpuRegisters()->setA(a);

        update_flags_sbc_8(oldVal, a, op, core, opcode);
    }

// SBC A L
    void sbc_a_l(GameBoyCore *core, unsigned long long opcode) {
        auto op = core->getCpu()->getCpuRegisters()->getL();
        auto carry = static_cast<int>(core->getCpu()->getCFlag());

        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = a;

        op += carry;
        a -= op;
        core->getCpu()->getCpuRegisters()->setA(a);

        update_flags_sbc_8(oldVal, a, op, core, opcode);
    }

// SBC A H
    void sbc_a_h(GameBoyCore *core, unsigned long long opcode) {
        auto op = core->getCpu()->getCpuRegisters()->getH();
        auto carry = static_cast<int>(core->getCpu()->getCFlag());

        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = a;

        op += carry;
        a -= op;
        core->getCpu()->getCpuRegisters()->setA(a);

        update_flags_sbc_8(oldVal, a, op, core, opcode);
    }

// SBC A E
    void sbc_a_e(GameBoyCore *core, unsigned long long opcode) {
        auto op = core->getCpu()->getCpuRegisters()->getE();
        auto carry = static_cast<int>(core->getCpu()->getCFlag());

        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = a;

        op += carry;
        a -= op;
        core->getCpu()->getCpuRegisters()->setA(a);

        update_flags_sbc_8(oldVal, a, op, core, opcode);
    }

// SBC A D
    void sbc_a_d(GameBoyCore *core, unsigned long long opcode) {
        auto op = core->getCpu()->getCpuRegisters()->getD();
        auto carry = static_cast<int>(core->getCpu()->getCFlag());

        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto oldVal = a;

        op += carry;
        a -= op;
        core->getCpu()->getCpuRegisters()->setA(a);

        update_flags_sbc_8(oldVal, a, op, core, opcode);
    }

// HALT
    void halt__(GameBoyCore *core, unsigned long long) {
        core->setIsHalted(true);
    }

// SUB d8
    void sub_d8_(GameBoyCore *core, unsigned long long opcode) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

        auto d8 = core->ReadData8(pc.to_ullong() + 1);
        auto oldVal = core->getCpu()->getCpuRegisters()->getA();

        auto newVal = oldVal + d8;

        core->getCpu()->getCpuRegisters()->setA(newVal);

        update_flags_sub_8(oldVal, newVal, d8, core, opcode);
    }

// SUB B
    void sub_b_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getB();
        auto nA = a - b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_sub_8(a, nA, b, core, opcode);
    }

// SUB A
    void sub_a_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getA();
        auto nA = a - b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_sub_8(a, nA, b, core, opcode);
    }

// SUB (HL)
    void sub__hl__(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        auto b = core->ReadData8(hl.to_ullong());

        auto nA = a - b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_sub_8(a, nA, b, core, opcode);
    }

// SUB L
    void sub_l_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getL();
        auto nA = a - b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_sub_8(a, nA, b, core, opcode);
    }

// SUB H
    void sub_h_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getH();
        auto nA = a - b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_sub_8(a, nA, b, core, opcode);
    }

// SUB E
    void sub_e_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getE();
        auto nA = a - b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_sub_8(a, nA, b, core, opcode);
    }

// SUB D
    void sub_d_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getD();
        auto nA = a - b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_sub_8(a, nA, b, core, opcode);
    }

// SUB C
    void sub_c_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getC();
        auto nA = a - b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_sub_8(a, nA, b, core, opcode);
    }

// OR C
    void or_c_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getC();

        auto nA = a | b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_or_8(a, nA, core, opcode);
    }

// OR B
    void or_b_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getB();

        auto nA = a | b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_or_8(a, nA, core, opcode);
    }

// OR A
    void or_a_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getA();

        auto nA = a | b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_or_8(a, nA, core, opcode);
    }

// OR (HL)
    void or__hl__(GameBoyCore *core, unsigned long long opcode) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->ReadData8(hl.to_ullong()).to_ullong();

        auto nA = a | b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_or_8(a, nA, core, opcode);
    }

// OR L
    void or_l_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getL();

        auto nA = a | b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_or_8(a, nA, core, opcode);
    }

// OR H
    void or_h_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getH();

        auto nA = a | b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_or_8(a, nA, core, opcode);
    }

// OR E
    void or_e_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getE();

        auto nA = a | b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_or_8(a, nA, core, opcode);
    }

// OR D
    void or_d_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getD();

        auto nA = a | b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_or_8(a, nA, core, opcode);
    }

// OR d8
    void or_d8_(GameBoyCore *core, unsigned long long opcode) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->ReadData8(pc.to_ullong() + 1);

        auto nA = a | b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_or_8(a, nA, core, opcode);
    }

// DEC D
    void dec_d_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getD();
        auto newVal = oldVal - 1;
        core->getCpu()->getCpuRegisters()->setD(newVal);

        update_flags_dec_8(oldVal, newVal, core, opcode);
    }

// DEC E
    void dec_e_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getE();
        auto newVal = oldVal - 1;
        core->getCpu()->getCpuRegisters()->setE(newVal);

        update_flags_dec_8(oldVal, newVal, core, opcode);
    }

// DEC DE
    void dec_de_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getDE();
        auto newVal = oldVal - 1;
        core->getCpu()->getCpuRegisters()->setDE(newVal);

        update_flags_dec_16(oldVal, newVal, core, opcode);
    }

// DEC H
    void dec_h_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getH();
        auto newVal = oldVal - 1;
        core->getCpu()->getCpuRegisters()->setH(newVal);

        update_flags_dec_8(oldVal, newVal, core, opcode);
    }

// DEC L
    void dec_l_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getL();
        auto newVal = oldVal - 1;
        core->getCpu()->getCpuRegisters()->setL(newVal);

        update_flags_dec_8(oldVal, newVal, core, opcode);
    }

// DEC HL
    void dec_hl_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getHL();
        auto newVal = oldVal - 1;
        core->getCpu()->getCpuRegisters()->setHL(newVal);

        update_flags_dec_16(oldVal, newVal, core, opcode);
    }

// DEC (HL)
    void dec__hl__(GameBoyCore *core, unsigned long long opcode) {
        auto addr = core->getCpu()->getCpuRegisters()->getHL();

        auto oldVal = core->ReadData8(addr.to_ullong());
        auto newVal = oldVal.to_ullong() - 1;

        core->WriteData8(addr.to_ullong(), newVal);

        update_flags_dec_8(oldVal.to_ullong(), newVal, core, opcode);
    }

// DEC SP
    void dec_sp_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getSP();
        auto newVal = oldVal - 1;
        core->getCpu()->getCpuRegisters()->setSP(newVal);

        update_flags_dec_16(oldVal, newVal, core, opcode);
    }

// DEC A
    void dec_a_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getA();
        auto newVal = oldVal - 1;
        core->getCpu()->getCpuRegisters()->setA(newVal);

        update_flags_dec_8(oldVal, newVal, core, opcode);
    }

// DEC B
    void dec_b_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getB();
        auto newVal = oldVal - 1;
        core->getCpu()->getCpuRegisters()->setB(newVal);

        update_flags_dec_8(oldVal, newVal, core, opcode);
    }

// DEC BC
    void dec_bc_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getBC();
        auto newVal = oldVal - 1;
        core->getCpu()->getCpuRegisters()->setBC(newVal);

        update_flags_dec_16(oldVal, newVal, core, opcode);
    }

// DEC C
    void dec_c_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getC();
        auto newVal = oldVal - 1;
        core->getCpu()->getCpuRegisters()->setC(newVal);

        update_flags_dec_8(oldVal, newVal, core, opcode);
    }

// EI
    void ei__(GameBoyCore *core, unsigned long long) {
        core->setInterruptsEnabled(true);
    }

// STOP 0
    void stop_0_(GameBoyCore *core, unsigned long long) {

// todo
        throw std::invalid_argument(__FUNCTION__);;

    }

// DAA
    void daa__(GameBoyCore *core, unsigned long long) {
        /*
     * When this instruction is executed, the A register is BCD corrected using the contents of the flags.
     * The exact process is the following: if the least significant four bits of A contain a non-BCD digit
     * (i. e. it is greater than 9) or the H flag is set, then $06 is added to the register. Then the four
     * most significant bits are checked. If this more significant digit also happens to be greater than 9
     * or the C flag is set, then $60 is added.
     */

        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto nA = a;

        Register<4> high;
        Register<4> low;

        SplitRegister(a, high, low);

        if (low.to_ullong() > 9 || core->getCpu()->getHFlag()) {
            nA += 0x06;

            if (high.to_ullong() > 9 || core->getCpu()->getCFlag()) {
                nA += 0x60;
            }
        }

        core->getCpu()->setHFlag(false);
        core->getCpu()->setZFlag(nA.to_ullong() == 0);

        // todo
        throw std::invalid_argument(__FUNCTION__);;

        core->getCpu()->getCpuRegisters()->setA(nA);
    }

// CCF
    void ccf__(GameBoyCore *core, unsigned long long) {
        /*
        Z - Not affected.
        N - Reset.
        H - Reset.
        C - Complemented.
     */

        core->getCpu()->setNFlag(false);
        core->getCpu()->setHFlag(false);
        core->getCpu()->setCFlag(!core->getCpu()->getCFlag());
    }

// CP C
    void cp_c_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getC();

        auto nA = a - b;

        update_flags_cp_8(a, nA, b, core, opcode);
    }

// CP B
    void cp_b_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getB();

        auto nA = a - b;

        update_flags_cp_8(a, nA, b, core, opcode);
    }

// CP D
    void cp_d_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getD();

        auto nA = a - b;

        update_flags_cp_8(a, nA, b, core, opcode);
    }

// CP A
    void cp_a_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getA();

        auto nA = a - b;

        update_flags_cp_8(a, nA, b, core, opcode);
    }

// CP (HL)
    void cp__hl__(GameBoyCore *core, unsigned long long opcode) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->ReadData8(hl.to_ullong()).to_ullong();

        auto nA = a - b;

        update_flags_cp_8(a, nA, b, core, opcode);
    }

// CP L
    void cp_l_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getL();

        auto nA = a - b;

        update_flags_cp_8(a, nA, b, core, opcode);
    }

// CP H
    void cp_h_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getH();

        auto nA = a - b;

        update_flags_cp_8(a, nA, b, core, opcode);
    }

// CP E
    void cp_e_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getE();

        auto nA = a - b;

        update_flags_cp_8(a, nA, b, core, opcode);
    }

// CP d8
    void cp_d8_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();

        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

        auto b = core->ReadData8(pc.to_ullong() + 1);

        auto nA = a - b;

        update_flags_cp_8(a, nA, b, core, opcode);
    }

// NOP
    void nop__(GameBoyCore *core, unsigned long long) {
        // nope nope nope nope nope
    }

// POP BC
    void pop_bc_(GameBoyCore *core, unsigned long long) {
        core->getCpu()->getCpuRegisters()->setBC(core->PopStack<16>());
    }

// POP DE
    void pop_de_(GameBoyCore *core, unsigned long long) {
        core->getCpu()->getCpuRegisters()->setDE(core->PopStack<16>());
    }

// POP HL
    void pop_hl_(GameBoyCore *core, unsigned long long) {
        core->getCpu()->getCpuRegisters()->setHL(core->PopStack<16>());
    }

// POP AF
    void pop_af_(GameBoyCore *core, unsigned long long) {
        core->getCpu()->getCpuRegisters()->setAF(core->PopStack<16>());
    }

// RST 00H
    void rst_00h_(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();

        core->PushToStack(pc);

        core->getCpu()->getCpuRegisters()->setPC(-1);
    }

// RST 10H
    void rst_10h_(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();

        core->PushToStack(pc);

        core->getCpu()->getCpuRegisters()->setPC(0x10 - 1);
    }

// RST 20H
    void rst_20h_(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();

        core->PushToStack(pc);

        core->getCpu()->getCpuRegisters()->setPC(0x20 - 1);
    }

// RST 08H
    void rst_08h_(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();

        core->PushToStack(pc);

        core->getCpu()->getCpuRegisters()->setPC(0x8 - 1);
    }

// RST 30H
    void rst_30h_(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();

        core->PushToStack(pc);

        core->getCpu()->getCpuRegisters()->setPC(0x30 - 1);
    }

// RST 18H
    void rst_18h_(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();

        core->PushToStack(pc);

        core->getCpu()->getCpuRegisters()->setPC(0x18 - 1);
    }

// RST 28H
    void rst_28h_(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();

        core->PushToStack(pc);

        core->getCpu()->getCpuRegisters()->setPC(0x28 - 1);
    }

// RST 38H
    void rst_38h_(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();

        core->PushToStack(pc);

        core->getCpu()->getCpuRegisters()->setPC(0x38 - 1);
    }

// PREFIX CB
    void prefix_cb_(GameBoyCore *core, unsigned long long) {
// todo Gameboy color instruction prefix
        throw std::invalid_argument(__FUNCTION__);;
    }

// AND B
    void and_b_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getB();
        auto newVal = a & b;

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_and_8(a, newVal, core, opcode);
    }

// AND A
    void and_a_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getA();
        auto newVal = a & b;

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_and_8(a, newVal, core, opcode);
    }

// AND (HL)
    void and__hl__(GameBoyCore *core, unsigned long long opcode) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->ReadData8(hl.to_ullong()).to_ullong();
        auto newVal = a & b;

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_and_8(a, newVal, core, opcode);
    }

// AND L
    void and_l_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getL();
        auto newVal = a & b;

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_and_8(a, newVal, core, opcode);
    }

// AND H
    void and_h_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getH();
        auto newVal = a & b;

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_and_8(a, newVal, core, opcode);
    }

// AND E
    void and_e_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getE();
        auto newVal = a & b;

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_and_8(a, newVal, core, opcode);
    }

// AND D
    void and_d_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getD();
        auto newVal = a & b;

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_and_8(a, newVal, core, opcode);
    }

// AND C
    void and_c_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getC();
        auto newVal = a & b;

        core->getCpu()->getCpuRegisters()->setA(newVal);
        update_flags_and_8(a, newVal, core, opcode);
    }

// AND d8
    void and_d8_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

        auto data = core->ReadData8(pc.to_ullong() + 1);

        auto nA = a & data;

        update_flags_and_8(a, nA, core, opcode);
    }

// SCF
    void scf__(GameBoyCore *core, unsigned long long) {
        /*
    Z - Not affected.
    N - Reset.
    H - Reset.
    C - Set.
     */

        core->getCpu()->setNFlag(false);
        core->getCpu()->setHFlag(false);
        core->getCpu()->setCFlag(true);
    }

// LD D d8
    void ld_d_d8(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

        auto d8 = core->ReadData8(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setD(d8);
    }

// LD (DE) A
    void ld__de__a(GameBoyCore *core, unsigned long long) {
        auto de = core->getCpu()->getCpuRegisters()->getDE();
        auto a = core->getCpu()->getCpuRegisters()->getA();

        core->WriteData8(de.to_ullong(), a);
    }

// LD DE d16
    void ld_de_d16(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 2);

        auto d16 = core->ReadData16(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setDE(d16);
    }

// LD E d8
    void ld_e_d8(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

        auto d8 = core->ReadData8(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setE(d8);
    }

// LD A (DE)
    void ld_a__de_(GameBoyCore *core, unsigned long long) {
        auto de = core->getCpu()->getCpuRegisters()->getDE();

        auto data = core->ReadData8(de.to_ullong());

        core->getCpu()->getCpuRegisters()->setA(data);
    }

// LD HL d16
    void ld_hl_d16(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 2);

        auto d16 = core->ReadData16(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setHL(d16);
    }

// LD H d8
    void ld_h_d8(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

        auto d8 = core->ReadData8(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setH(d8);
    }

// LD (HL+) A
    void ld__hlplus__a(GameBoyCore *core, unsigned long long opcode) {
        // Same as: LD (HL),A - INC HL
        ld__hl__a(core, opcode);
        inc_hl_(core, opcode);
    }

// LD A (HL+)
    void ld_a__hlplus_(GameBoyCore *core, unsigned long long opcode) {
        // Same as: LD A,(HL) - INC H
        ld_a__hl_(core, opcode);
        inc_h_(core, opcode);
    }

// LD (C) A
    void ld__c__a(GameBoyCore *core, unsigned long long) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto c = core->getCpu()->getCpuRegisters()->getC();

        core->WriteData8(0xff00 + c.to_ullong(), a);
    }

// LD L d8
    void ld_l_d8(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

        auto d8 = core->ReadData8(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setL(d8);
    }

// LD (HL-) A
    void ld__hlminus__a(GameBoyCore *core, unsigned long long opcode) {
        //  Same as: LD (HL),A - DEC HL
        ld__hl__a(core, opcode);
        dec_hl_(core, opcode);
    }

// LD SP d16
    void ld_sp_d16(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 2);

        auto d16 = core->ReadData16(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setSP(d16);
    }

// LD (HL) d8
    void ld__hl__d8(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

        auto d8 = core->ReadData8(pc.to_ullong() + 1);
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        core->WriteData8(hl.to_ullong(), d8);
    }

// LD A (HL-)
    void ld_a__hlminus_(GameBoyCore *core, unsigned long long opcode) {
        // Same as: LD A,(HL) - DEC HL
        ld_a__hl_(core, opcode);
        dec_hl_(core, opcode);
    }

// LD A (C)
    void ld_a__c_(GameBoyCore *core, unsigned long long) {
        auto c = core->getCpu()->getCpuRegisters()->getC();

        auto data = core->ReadData8(c.to_ullong() + 0xff00);

        core->getCpu()->getCpuRegisters()->setA(data);
    }

// LD SP HL
    void ld_sp_hl(GameBoyCore *core, unsigned long long) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        auto data = core->ReadData16(hl.to_ullong());

        core->getCpu()->getCpuRegisters()->setSP(data);
    }

// LD A d8
    void ld_a_d8(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 1);

        auto data = core->ReadData8(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setA(data.to_ullong());
    }

// LD HL SP+r8
    void ld_hl_spplusr8(GameBoyCore *core, unsigned long long) {
        /**
     Description:  Put SP + n effective address into HL.
     Use with:      n = one byte signed immediate value.
     Flags affected:  Z - Reset.  N - Reset.  H - Set or reset according to operation.  C - Set or reset according to operation.
     */

        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

        auto r8 = core->ReadData8(pc.to_ullong() + 1);

        auto oldVal = core->getCpu()->getCpuRegisters()->getSP();
        auto newVal = oldVal + r8;

        core->getCpu()->getCpuRegisters()->setHL(newVal);

        core->SetFlags(false, false, false, false);
        if (((oldVal.to_ullong() ^ r8.to_ullong() ^ newVal.to_ullong()) & 0x100) == 0x100) {
            core->getCpu()->setCFlag(true);
        }

        if (((oldVal.to_ullong() ^ r8.to_ullong() ^ newVal.to_ullong()) & 0x10) == 0x10) {
            core->getCpu()->setHFlag(true);
        }
    }

// LD B E
    void ld_b_e(GameBoyCore *core, unsigned long long) {
        auto e = core->getCpu()->getCpuRegisters()->getE();

        core->getCpu()->getCpuRegisters()->setB(e);
    }

// LD B D
    void ld_b_d(GameBoyCore *core, unsigned long long) {
        auto d = core->getCpu()->getCpuRegisters()->getD();

        core->getCpu()->getCpuRegisters()->setB(d);
    }

// LD B C
    void ld_b_c(GameBoyCore *core, unsigned long long) {
        auto c = core->getCpu()->getCpuRegisters()->getC();

        core->getCpu()->getCpuRegisters()->setB(c);
    }

// LD B B
    void ld_b_b(GameBoyCore *core, unsigned long long) {
        auto b = core->getCpu()->getCpuRegisters()->getB();

        core->getCpu()->getCpuRegisters()->setB(b);
    }

// LD C C
    void ld_c_c(GameBoyCore *core, unsigned long long) {
        auto c = core->getCpu()->getCpuRegisters()->getC();

        core->getCpu()->getCpuRegisters()->setC(c);
    }

// LD C B
    void ld_c_b(GameBoyCore *core, unsigned long long) {
        auto b = core->getCpu()->getCpuRegisters()->getB();

        core->getCpu()->getCpuRegisters()->setC(b);
    }

// LD B A
    void ld_b_a(GameBoyCore *core, unsigned long long) {
        auto a = core->getCpu()->getCpuRegisters()->getA();

        core->getCpu()->getCpuRegisters()->setB(a);
    }

// LD B (HL)
    void ld_b__hl_(GameBoyCore *core, unsigned long long) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        auto data = core->ReadData8(hl.to_ullong());

        core->getCpu()->getCpuRegisters()->setB(data);
    }

// LD B L
    void ld_b_l(GameBoyCore *core, unsigned long long) {
        auto l = core->getCpu()->getCpuRegisters()->getL();

        core->getCpu()->getCpuRegisters()->setB(l);
    }

// LD B H
    void ld_b_h(GameBoyCore *core, unsigned long long) {
        auto h = core->getCpu()->getCpuRegisters()->getH();

        core->getCpu()->getCpuRegisters()->setB(h);
    }

// LD C H
    void ld_c_h(GameBoyCore *core, unsigned long long) {
        auto h = core->getCpu()->getCpuRegisters()->getH();

        core->getCpu()->getCpuRegisters()->setC(h);
    }

// LD C E
    void ld_c_e(GameBoyCore *core, unsigned long long) {
        auto e = core->getCpu()->getCpuRegisters()->getE();

        core->getCpu()->getCpuRegisters()->setC(e);
    }

// LD C D
    void ld_c_d(GameBoyCore *core, unsigned long long) {
        auto d = core->getCpu()->getCpuRegisters()->getD();

        core->getCpu()->getCpuRegisters()->setC(d);
    }

// LD BC d16
    void ld_bc_d16(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();

        core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 2);

        auto data = core->ReadData16(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setBC(data);
    }

// LD (BC) A
    void ld__bc__a(GameBoyCore *core, unsigned long long) {
        auto bc = core->getCpu()->getCpuRegisters()->getBC();
        auto a = core->getCpu()->getCpuRegisters()->getA();

        core->WriteData8(bc.to_ullong(), a);
    }

// LD C A
    void ld_c_a(GameBoyCore *core, unsigned long long) {
        auto a = core->getCpu()->getCpuRegisters()->getA();

        core->getCpu()->getCpuRegisters()->setC(a);
    }

// LD B d8
    void ld_b_d8(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 1);

        auto d8 = core->ReadData8(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setB(d8);
    }

// LD C (HL)
    void ld_c__hl_(GameBoyCore *core, unsigned long long) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        auto data = core->ReadData8(hl.to_ullong());

        core->getCpu()->getCpuRegisters()->setC(data);
    }

// LD C L
    void ld_c_l(GameBoyCore *core, unsigned long long) {
        auto l = core->getCpu()->getCpuRegisters()->getL();

        core->getCpu()->getCpuRegisters()->setC(l);
    }

// LD (a16) SP
    void ld__a16__sp(GameBoyCore *core, unsigned long long) {
        auto sp = core->getCpu()->getCpuRegisters()->getSP();

        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 2);

        Register<16> reg = core->ReadData16(pc.to_ullong() + 1);

        core->WriteData16(reg.to_ullong(), sp);
    }

// LD D H
    void ld_d_h(GameBoyCore *core, unsigned long long) {
        auto h = core->getCpu()->getCpuRegisters()->getH();

        core->getCpu()->getCpuRegisters()->setD(h);
    }

// LD D E
    void ld_d_e(GameBoyCore *core, unsigned long long) {
        auto e = core->getCpu()->getCpuRegisters()->getE();

        core->getCpu()->getCpuRegisters()->setD(e);
    }

// LD D D
    void ld_d_d(GameBoyCore *core, unsigned long long) {
        auto d = core->getCpu()->getCpuRegisters()->getD();

        core->getCpu()->getCpuRegisters()->setD(d);
    }

// LD D C
    void ld_d_c(GameBoyCore *core, unsigned long long) {
        auto c = core->getCpu()->getCpuRegisters()->getC();

        core->getCpu()->getCpuRegisters()->setD(c);
    }

// LD (a16) A
    void ld__a16__a(GameBoyCore *core, unsigned long long) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto pc = core->getCpu()->getCpuRegisters()->getPC();

        core->getCpu()->getCpuRegisters()->setPC(pc + 2);

        Register<16> reg = core->ReadData16(pc.to_ullong() + 1);

        core->WriteData8(reg.to_ullong(), a);
    }

// LD D B
    void ld_d_b(GameBoyCore *core, unsigned long long) {
        auto b = core->getCpu()->getCpuRegisters()->getB();

        core->getCpu()->getCpuRegisters()->setD(b);
    }

// LD E C
    void ld_e_c(GameBoyCore *core, unsigned long long) {
        auto c = core->getCpu()->getCpuRegisters()->getC();

        core->getCpu()->getCpuRegisters()->setE(c);
    }

// LD E B
    void ld_e_b(GameBoyCore *core, unsigned long long) {
        auto b = core->getCpu()->getCpuRegisters()->getB();

        core->getCpu()->getCpuRegisters()->setE(b);
    }

// LD D A
    void ld_d_a(GameBoyCore *core, unsigned long long) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        core->getCpu()->getCpuRegisters()->setD(a);
    }

// LD D (HL)
    void ld_d__hl_(GameBoyCore *core, unsigned long long) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        auto data = core->ReadData8(hl.to_ullong());

        core->getCpu()->getCpuRegisters()->setD(data);
    }

// LD D L
    void ld_d_l(GameBoyCore *core, unsigned long long) {
        auto l = core->getCpu()->getCpuRegisters()->getL();

        core->getCpu()->getCpuRegisters()->setD(l);
    }

// LD E L
    void ld_e_l(GameBoyCore *core, unsigned long long) {
        auto l = core->getCpu()->getCpuRegisters()->getL();

        core->getCpu()->getCpuRegisters()->setE(l);
    }

// LD E H
    void ld_e_h(GameBoyCore *core, unsigned long long) {
        auto h = core->getCpu()->getCpuRegisters()->getH();

        core->getCpu()->getCpuRegisters()->setE(h);
    }

// LD E E
    void ld_e_e(GameBoyCore *core, unsigned long long) {
        auto e = core->getCpu()->getCpuRegisters()->getE();

        core->getCpu()->getCpuRegisters()->setE(e);
    }

// LD E D
    void ld_e_d(GameBoyCore *core, unsigned long long) {
        auto d = core->getCpu()->getCpuRegisters()->getD();

        core->getCpu()->getCpuRegisters()->setE(d);
    }

// LD E A
    void ld_e_a(GameBoyCore *core, unsigned long long) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        core->getCpu()->getCpuRegisters()->setE(a);
    }

// LD E (HL)
    void ld_e__hl_(GameBoyCore *core, unsigned long long) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        auto data = core->ReadData8(hl.to_ullong());

        core->getCpu()->getCpuRegisters()->setE(data);
    }

// LD H L
    void ld_h_l(GameBoyCore *core, unsigned long long) {
        auto l = core->getCpu()->getCpuRegisters()->getL();

        core->getCpu()->getCpuRegisters()->setH(l);
    }

// LD H H
    void ld_h_h(GameBoyCore *core, unsigned long long) {
        auto h = core->getCpu()->getCpuRegisters()->getH();

        core->getCpu()->getCpuRegisters()->setH(h);
    }

// LD H E
    void ld_h_e(GameBoyCore *core, unsigned long long) {
        auto e = core->getCpu()->getCpuRegisters()->getE();

        core->getCpu()->getCpuRegisters()->setH(e);
    }

// LD H D
    void ld_h_d(GameBoyCore *core, unsigned long long) {
        auto d = core->getCpu()->getCpuRegisters()->getD();

        core->getCpu()->getCpuRegisters()->setH(d);
    }

// LD H C
    void ld_h_c(GameBoyCore *core, unsigned long long) {
        auto c = core->getCpu()->getCpuRegisters()->getC();

        core->getCpu()->getCpuRegisters()->setH(c);
    }

// LD A (a16)
    void ld_a__a16_(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();


        auto addr = core->ReadData16(pc.to_ullong() + 1);
        core->getCpu()->getCpuRegisters()->setPC(pc + 2);

        auto data = core->ReadData8(addr.to_ullong());
        core->getCpu()->getCpuRegisters()->setA(data);
    }

// LD H B
    void ld_h_b(GameBoyCore *core, unsigned long long) {
        auto b = core->getCpu()->getCpuRegisters()->getB();

        core->getCpu()->getCpuRegisters()->setH(b);
    }

// LD A (BC)
    void ld_a__bc_(GameBoyCore *core, unsigned long long) {
        auto bc = core->getCpu()->getCpuRegisters()->getBC();

        auto data = core->ReadData8(bc.to_ullong());

        core->getCpu()->getCpuRegisters()->setA(data);
    }

// LD L C
    void ld_l_c(GameBoyCore *core, unsigned long long) {
        auto c = core->getCpu()->getCpuRegisters()->getC();
        core->getCpu()->getCpuRegisters()->setL(c);
    }

// LD C d8
    void ld_c_d8(GameBoyCore *core, unsigned long long) {
        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 1);

        auto d8 = core->ReadData8(pc.to_ullong() + 1);

        core->getCpu()->getCpuRegisters()->setC(d8);
    }

// LD L B
    void ld_l_b(GameBoyCore *core, unsigned long long) {
        auto b = core->getCpu()->getCpuRegisters()->getB();

        core->getCpu()->getCpuRegisters()->setL(b);
    }

// LD H A
    void ld_h_a(GameBoyCore *core, unsigned long long) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        core->getCpu()->getCpuRegisters()->setH(a);
    }

// LD H (HL)
    void ld_h__hl_(GameBoyCore *core, unsigned long long) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        auto data = core->ReadData8(hl.to_ullong());

        core->getCpu()->getCpuRegisters()->setH(data);
    }

// LD L (HL)
    void ld_l__hl_(GameBoyCore *core, unsigned long long) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();
        auto dat = core->ReadData8(hl.to_ullong());

        core->getCpu()->getCpuRegisters()->setL(dat);
    }

// LD L L
    void ld_l_l(GameBoyCore *core, unsigned long long) {
        auto l = core->getCpu()->getCpuRegisters()->getL();

        core->getCpu()->getCpuRegisters()->setL(l);
    }

// LD L H
    void ld_l_h(GameBoyCore *core, unsigned long long) {
        auto h = core->getCpu()->getCpuRegisters()->getH();

        core->getCpu()->getCpuRegisters()->setL(h);
    }

// LD L E
    void ld_l_e(GameBoyCore *core, unsigned long long) {
        auto e = core->getCpu()->getCpuRegisters()->getE();

        core->getCpu()->getCpuRegisters()->setL(e);
    }

// LD L D
    void ld_l_d(GameBoyCore *core, unsigned long long) {
        auto d = core->getCpu()->getCpuRegisters()->getD();

        core->getCpu()->getCpuRegisters()->setL(d);
    }

// LD L A
    void ld_l_a(GameBoyCore *core, unsigned long long) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        core->getCpu()->getCpuRegisters()->setL(a);
    }

// LD (HL) L
    void ld__hl__l(GameBoyCore *core, unsigned long long) {
        auto l = core->getCpu()->getCpuRegisters()->getL();
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        core->WriteData8(hl.to_ullong(), l);
    }

// LD (HL) H
    void ld__hl__h(GameBoyCore *core, unsigned long long) {
        auto h = core->getCpu()->getCpuRegisters()->getH();
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        core->WriteData8(hl.to_ullong(), h);
    }

// LD (HL) E
    void ld__hl__e(GameBoyCore *core, unsigned long long) {
        auto e = core->getCpu()->getCpuRegisters()->getE();
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        core->WriteData8(hl.to_ullong(), e);
    }

// LD (HL) D
    void ld__hl__d(GameBoyCore *core, unsigned long long) {
        auto d = core->getCpu()->getCpuRegisters()->getD();
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        core->WriteData8(hl.to_ullong(), d);
    }

// LD (HL) C
    void ld__hl__c(GameBoyCore *core, unsigned long long) {
        auto c = core->getCpu()->getCpuRegisters()->getC();
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        core->WriteData8(hl.to_ullong(), c);
    }

// LD (HL) B
    void ld__hl__b(GameBoyCore *core, unsigned long long) {
        auto b = core->getCpu()->getCpuRegisters()->getB();
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        core->WriteData8(hl.to_ullong(), b);
    }

// LD A C
    void ld_a_c(GameBoyCore *core, unsigned long long) {
        auto c = core->getCpu()->getCpuRegisters()->getC();
        core->getCpu()->getCpuRegisters()->setA(c);
    }

// LD A B
    void ld_a_b(GameBoyCore *core, unsigned long long) {
        auto b = core->getCpu()->getCpuRegisters()->getB();

        core->getCpu()->getCpuRegisters()->setA(b);
    }

// LD (HL) A
    void ld__hl__a(GameBoyCore *core, unsigned long long) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();
        auto a = core->getCpu()->getCpuRegisters()->getA();

        core->WriteData8(hl.to_ullong(), a);
    }

// LD A A
    void ld_a_a(GameBoyCore *core, unsigned long long) {
        auto regA = core->getCpu()->getCpuRegisters()->getA();

        core->getCpu()->getCpuRegisters()->setA(regA);
    }

// LD A (HL)
    void ld_a__hl_(GameBoyCore *core, unsigned long long) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();
        auto data = core->ReadData8(hl.to_ullong());

        core->getCpu()->getCpuRegisters()->setA(data);
    }

// LD A L
    void ld_a_l(GameBoyCore *core, unsigned long long) {
        auto l = core->getCpu()->getCpuRegisters()->getL();
        core->getCpu()->getCpuRegisters()->setA(l);
    }

// LD A H
    void ld_a_h(GameBoyCore *core, unsigned long long) {
        auto h = core->getCpu()->getCpuRegisters()->getH();
        core->getCpu()->getCpuRegisters()->setA(h);
    }

// LD A E
    void ld_a_e(GameBoyCore *core, unsigned long long) {
        auto e = core->getCpu()->getCpuRegisters()->getE();
        core->getCpu()->getCpuRegisters()->setA(e);
    }

// LD A D
    void ld_a_d(GameBoyCore *core, unsigned long long) {
        auto d = core->getCpu()->getCpuRegisters()->getD();
        core->getCpu()->getCpuRegisters()->setA(d);
    }

// RRCA
    void rrca__(GameBoyCore *core, unsigned long long) {
        auto a = core->getCpu()->getCpuRegisters()->getA();

        auto carry = (0x1 & a).to_ullong();
        assert(carry == 1 || carry == 0);

        a = a >> 1;

        core->getCpu()->getCpuRegisters()->setA(a);

        /*
    Z - Set if result is zero.
    N - Reset.
    H - Reset.
    C - Contains old bit 0 data
     */
        core->getCpu()->setZFlag(a.to_ullong() == 0);
        core->getCpu()->setNFlag(false);
        core->getCpu()->setHFlag(false);
        core->getCpu()->setCFlag(static_cast<bool>(carry));
    }

// XOR B
    void xor_b_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getB();

        auto nA = a ^b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_xor_8(a, nA, core, opcode);
    }

// XOR C
    void xor_c_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getC();

        auto nA = a ^b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_xor_8(a, nA, core, opcode);
    }

// XOR A
    void xor_a_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getA();

        auto nA = a ^b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_xor_8(a, nA, core, opcode);
    }

// XOR (HL)
    void xor__hl__(GameBoyCore *core, unsigned long long opcode) {
        auto hl = core->getCpu()->getCpuRegisters()->getHL();

        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->ReadData8(hl.to_ullong()).to_ullong();

        auto nA = a ^b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_xor_8(a, nA, core, opcode);
    }

// XOR L
    void xor_l_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getL();

        auto nA = a ^b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_xor_8(a, nA, core, opcode);
    }

// XOR H
    void xor_h_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getH();

        auto nA = a ^b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_xor_8(a, nA, core, opcode);
    }

// XOR E
    void xor_e_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getE();

        auto nA = a ^b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_xor_8(a, nA, core, opcode);
    }

// XOR D
    void xor_d_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();
        auto b = core->getCpu()->getCpuRegisters()->getD();

        auto nA = a ^b;
        core->getCpu()->getCpuRegisters()->setA(nA);

        update_flags_xor_8(a, nA, core, opcode);
    }

// XOR d8
    void xor_d8_(GameBoyCore *core, unsigned long long opcode) {
        auto a = core->getCpu()->getCpuRegisters()->getA();

        auto pc = core->getCpu()->getCpuRegisters()->getPC();
        core->getCpu()->getCpuRegisters()->setPC(pc + 1);

        auto data = core->ReadData8(pc.to_ullong() + 1);
        auto nA = a ^data;

        update_flags_xor_8(a, nA, core, opcode);
    }

// CPL
    void cpl__(GameBoyCore *core, unsigned long long) {
        auto a = core->getCpu()->getCpuRegisters()->getA();

        core->getCpu()->getCpuRegisters()->setA(~a);

        core->getCpu()->setNFlag(true);
        core->getCpu()->setHFlag(true);
    }

// RLCA
    void rlca__(GameBoyCore *core, unsigned long long) {
        auto a = core->getCpu()->getCpuRegisters()->getA();

        auto carry = (a >> 7).to_ullong();
        assert(carry == 0 || carry == 1);

        a = (a << 1) | carry;

        /*
        Z - Set if result is zero.
        N - Reset.
        H - Reset.
        C - Contains old bit 7 data.
     */
        core->getCpu()->setZFlag(a.to_ullong() == 0);
        core->getCpu()->setNFlag(false);
        core->getCpu()->setHFlag(false);
        core->getCpu()->setCFlag(static_cast<bool>(carry));

        core->getCpu()->getCpuRegisters()->setA(a);
    }

// PUSH BC
    void push_bc_(GameBoyCore *core, unsigned long long) {
        core->PushToStack(core->getCpu()->getCpuRegisters()->getBC());
    }

// PUSH DE
    void push_de_(GameBoyCore *core, unsigned long long) {
        core->PushToStack(core->getCpu()->getCpuRegisters()->getDE());
    }

// PUSH HL
    void push_hl_(GameBoyCore *core, unsigned long long) {
        core->PushToStack(core->getCpu()->getCpuRegisters()->getHL());
    }

// PUSH AF
    void push_af_(GameBoyCore *core, unsigned long long) {
        core->PushToStack(core->getCpu()->getCpuRegisters()->getAF());
    }

// INC D
    void inc_d_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getD();
        auto newVal = oldVal + 1;
        core->getCpu()->getCpuRegisters()->setD(newVal);

        update_flags_inc_8(oldVal, newVal, core, opcode);
    }

// INC DE
    void inc_de_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getDE();
        auto newVal = oldVal + 1;
        core->getCpu()->getCpuRegisters()->setDE(newVal);

        update_flags_inc_16(oldVal, newVal, core, opcode);
    }

// INC E
    void inc_e_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getE();
        auto newVal = oldVal + 1;
        core->getCpu()->getCpuRegisters()->setE(newVal);

        update_flags_inc_8(oldVal, newVal, core, opcode);
    }

// INC H
    void inc_h_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getH();
        auto newVal = oldVal + 1;
        core->getCpu()->getCpuRegisters()->setH(newVal);

        update_flags_inc_8(oldVal, newVal, core, opcode);
    }

// INC HL
    void inc_hl_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getHL();
        auto newVal = oldVal + 1;
        core->getCpu()->getCpuRegisters()->setHL(newVal);

        update_flags_inc_16(oldVal, newVal, core, opcode);
    }

// INC L
    void inc_l_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getL();
        auto newVal = oldVal + 1;
        core->getCpu()->getCpuRegisters()->setL(newVal);

        update_flags_inc_8(oldVal, newVal, core, opcode);
    }

// INC (HL)
    void inc__hl__(GameBoyCore *core, unsigned long long opcode) {
        auto addr = core->getCpu()->getCpuRegisters()->getHL();
        auto oldVal = core->ReadData16(addr.to_ullong());
        auto newVal = std::bitset<16>(oldVal.to_ullong() + 1);
        core->WriteData16(addr.to_ullong(), newVal);

        update_flags_inc_8(oldVal.to_ullong(), newVal.to_ullong(), core, opcode);
    }

// INC SP
    void inc_sp_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getSP();
        auto newVal = oldVal + 1;
        core->getCpu()->getCpuRegisters()->setSP(newVal);

        update_flags_inc_16(oldVal, newVal, core, opcode);
    }

// INC A
    void inc_a_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getA();
        auto newVal = oldVal + 1;
        core->getCpu()->getCpuRegisters()->setA(newVal);

        update_flags_inc_8(oldVal, newVal, core, opcode);
    }

// INC BC
    void inc_bc_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getBC();
        auto newVal = oldVal + 1;
        core->getCpu()->getCpuRegisters()->setBC(newVal);

        update_flags_inc_16(oldVal, newVal, core, opcode);
    }

// INC B
    void inc_b_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getB();
        auto newVal = oldVal + 1;
        core->getCpu()->getCpuRegisters()->setB(newVal);

        update_flags_inc_8(oldVal, newVal, core, opcode);
    }

// INC C
    void inc_c_(GameBoyCore *core, unsigned long long opcode) {
        auto oldVal = core->getCpu()->getCpuRegisters()->getC();
        auto newVal = oldVal + 1;
        core->getCpu()->getCpuRegisters()->setC(newVal);

        update_flags_inc_8(oldVal, newVal, core, opcode);
    }


    CpuInstruction DecodeInstruction(unsigned long long opcode) {
        const InstructionMap &instructionMap = GetInstructionMap();

        auto it = instructionMap.find(opcode);
        if (it == instructionMap.end()) {
            throw std::invalid_argument("Invalid opcode!");
        }
        return it->second;
    }


    const InstructionMap &GetInstructionMap() {
        static const std::map<unsigned long long, CpuInstruction> instructionMap{
                {
                        0xc0, { ret_nz_, "RET NZ ", 1, 20 }
                },
                {
                        0xc9, { ret__, "RET  ", 1, 16 }
                },
                {
                        0xc8, { ret_z_, "RET Z ", 1, 20 }
                },
                {
                        0xd0, { ret_nc_, "RET NC ", 1, 20 }
                },
                {
                        0xd8, { ret_c_, "RET C ", 1, 20 }
                },
                {
                        0x1f, { rra__, "RRA  ", 1, 4 }
                },
                {
                        0xce, { adc_a_d8, "ADC A d8", 2, 8 }
                },
                {
                        0x89, { adc_a_c, "ADC A C", 1, 4 }
                },
                {
                        0x88, { adc_a_b, "ADC A B", 1, 4 }
                },
                {
                        0x8f, { adc_a_a, "ADC A A", 1, 4 }
                },
                {
                        0x8e, { adc_a__hl_, "ADC A (HL)", 1, 8 }
                },
                {
                        0x8d, { adc_a_l, "ADC A L", 1, 4 }
                },
                {
                        0x8c, { adc_a_h, "ADC A H", 1, 4 }
                },
                {
                        0x8b, { adc_a_e, "ADC A E", 1, 4 }
                },
                {
                        0x8a, { adc_a_d, "ADC A D", 1, 4 }
                },
                {
                        0x19, { add_hl_de, "ADD HL DE", 1, 8 }
                },
                {
                        0xc6, { add_a_d8, "ADD A d8", 2, 8 }
                },
                {
                        0x29, { add_hl_hl, "ADD HL HL", 1, 8 }
                },
                {
                        0xe8, { add_sp_r8, "ADD SP r8", 2, 16 }
                },
                {
                        0x39, { add_hl_sp, "ADD HL SP", 1, 8 }
                },
                {
                        0x09, { add_hl_bc, "ADD HL BC", 1, 8 }
                },
                {
                        0x87, { add_a_a, "ADD A A", 1, 4 }
                },
                {
                        0x86, { add_a__hl_, "ADD A (HL)", 1, 8 }
                },
                {
                        0x85, { add_a_l, "ADD A L", 1, 4 }
                },
                {
                        0x84, { add_a_h, "ADD A H", 1, 4 }
                },
                {
                        0x83, { add_a_e, "ADD A E", 1, 4 }
                },
                {
                        0x82, { add_a_d, "ADD A D", 1, 4 }
                },
                {
                        0x81, { add_a_c, "ADD A C", 1, 4 }
                },
                {
                        0x80, { add_a_b, "ADD A B", 1, 4 }
                },
                {
                        0xc4, { call_nz_a16, "CALL NZ a16", 3, 24 }
                },
                {
                        0xd4, { call_nc_a16, "CALL NC a16", 3, 24 }
                },
                {
                        0xcd, { call_a16_, "CALL a16 ", 3, 24 }
                },
                {
                        0xcc, { call_z_a16, "CALL Z a16", 3, 24 }
                },
                {
                        0xdc, { call_c_a16, "CALL C a16", 3, 24 }
                },
                {
                        0xf3, { di__, "DI  ", 1, 4 }
                },
                {
                        0xc2, { jp_nz_a16, "JP NZ a16", 3, 16 }
                },
                {
                        0xc3, { jp_a16_, "JP a16 ", 3, 16 }
                },
                {
                        0xd2, { jp_nc_a16, "JP NC a16", 3, 16 }
                },
                {
                        0xe9, { jp__hl__, "JP (HL) ", 1, 4 }
                },
                {
                        0xca, { jp_z_a16, "JP Z a16", 3, 16 }
                },
                {
                        0xda, { jp_c_a16, "JP C a16", 3, 16 }
                },
                {
                        0x17, { rla__, "RLA  ", 1, 4 }
                },
                {
                        0x18, { jr_r8_, "JR r8 ", 2, 12 }
                },
                {
                        0x20, { jr_nz_r8, "JR NZ r8", 2, 12 }
                },
                {
                        0x28, { jr_z_r8, "JR Z r8", 2, 12 }
                },
                {
                        0x30, { jr_nc_r8, "JR NC r8", 2, 12 }
                },
                {
                        0x38, { jr_c_r8, "JR C r8", 2, 12 }
                },
                {
                        0xd9, { reti__, "RETI  ", 1, 16 }
                },
                {
                        0xe0, { ldh__a8__a, "LDH (a8) A", 2, 12 }
                },
                {
                        0xf0, { ldh_a__a8_, "LDH A (a8)", 2, 12 }
                },
                {
                        0xde, { sbc_a_d8, "SBC A d8", 2, 8 }
                },
                {
                        0x98, { sbc_a_b, "SBC A B", 1, 4 }
                },
                {
                        0x99, { sbc_a_c, "SBC A C", 1, 4 }
                },
                {
                        0x9f, { sbc_a_a, "SBC A A", 1, 4 }
                },
                {
                        0x9e, { sbc_a__hl_, "SBC A (HL)", 1, 8 }
                },
                {
                        0x9d, { sbc_a_l, "SBC A L", 1, 4 }
                },
                {
                        0x9c, { sbc_a_h, "SBC A H", 1, 4 }
                },
                {
                        0x9b, { sbc_a_e, "SBC A E", 1, 4 }
                },
                {
                        0x9a, { sbc_a_d, "SBC A D", 1, 4 }
                },
                {
                        0x76, { halt__, "HALT  ", 1, 4 }
                },
                {
                        0xd6, { sub_d8_, "SUB d8 ", 2, 8 }
                },
                {
                        0x90, { sub_b_, "SUB B ", 1, 4 }
                },
                {
                        0x97, { sub_a_, "SUB A ", 1, 4 }
                },
                {
                        0x96, { sub__hl__, "SUB (HL) ", 1, 8 }
                },
                {
                        0x95, { sub_l_, "SUB L ", 1, 4 }
                },
                {
                        0x94, { sub_h_, "SUB H ", 1, 4 }
                },
                {
                        0x93, { sub_e_, "SUB E ", 1, 4 }
                },
                {
                        0x92, { sub_d_, "SUB D ", 1, 4 }
                },
                {
                        0x91, { sub_c_, "SUB C ", 1, 4 }
                },
                {
                        0xb1, { or_c_, "OR C ", 1, 4 }
                },
                {
                        0xb0, { or_b_, "OR B ", 1, 4 }
                },
                {
                        0xb7, { or_a_, "OR A ", 1, 4 }
                },
                {
                        0xb6, { or__hl__, "OR (HL) ", 1, 8 }
                },
                {
                        0xb5, { or_l_, "OR L ", 1, 4 }
                },
                {
                        0xb4, { or_h_, "OR H ", 1, 4 }
                },
                {
                        0xb3, { or_e_, "OR E ", 1, 4 }
                },
                {
                        0xb2, { or_d_, "OR D ", 1, 4 }
                },
                {
                        0xf6, { or_d8_, "OR d8 ", 2, 8 }
                },
                {
                        0x15, { dec_d_, "DEC D ", 1, 4 }
                },
                {
                        0x1d, { dec_e_, "DEC E ", 1, 4 }
                },
                {
                        0x1b, { dec_de_, "DEC DE ", 1, 8 }
                },
                {
                        0x25, { dec_h_, "DEC H ", 1, 4 }
                },
                {
                        0x2d, { dec_l_, "DEC L ", 1, 4 }
                },
                {
                        0x2b, { dec_hl_, "DEC HL ", 1, 8 }
                },
                {
                        0x35, { dec__hl__, "DEC (HL) ", 1, 12 }
                },
                {
                        0x3b, { dec_sp_, "DEC SP ", 1, 8 }
                },
                {
                        0x3d, { dec_a_, "DEC A ", 1, 4 }
                },
                {
                        0x05, { dec_b_, "DEC B ", 1, 4 }
                },
                {
                        0x0b, { dec_bc_, "DEC BC ", 1, 8 }
                },
                {
                        0x0d, { dec_c_, "DEC C ", 1, 4 }
                },
                {
                        0xfb, { ei__, "EI  ", 1, 4 }
                },
                {
                        0x10, { stop_0_, "STOP 0 ", 2, 4 }
                },
                {
                        0x27, { daa__, "DAA  ", 1, 4 }
                },
                {
                        0x3f, { ccf__, "CCF  ", 1, 4 }
                },
                {
                        0xb9, { cp_c_, "CP C ", 1, 4 }
                },
                {
                        0xb8, { cp_b_, "CP B ", 1, 4 }
                },
                {
                        0xba, { cp_d_, "CP D ", 1, 4 }
                },
                {
                        0xbf, { cp_a_, "CP A ", 1, 4 }
                },
                {
                        0xbe, { cp__hl__, "CP (HL) ", 1, 8 }
                },
                {
                        0xbd, { cp_l_, "CP L ", 1, 4 }
                },
                {
                        0xbc, { cp_h_, "CP H ", 1, 4 }
                },
                {
                        0xbb, { cp_e_, "CP E ", 1, 4 }
                },
                {
                        0xfe, { cp_d8_, "CP d8 ", 2, 8 }
                },
                {
                        0x00, { nop__, "NOP  ", 1, 4 }
                },
                {
                        0xc1, { pop_bc_, "POP BC ", 1, 12 }
                },
                {
                        0xd1, { pop_de_, "POP DE ", 1, 12 }
                },
                {
                        0xe1, { pop_hl_, "POP HL ", 1, 12 }
                },
                {
                        0xf1, { pop_af_, "POP AF ", 1, 12 }
                },
                {
                        0xc7, { rst_00h_, "RST 00H ", 1, 16 }
                },
                {
                        0xd7, { rst_10h_, "RST 10H ", 1, 16 }
                },
                {
                        0xe7, { rst_20h_, "RST 20H ", 1, 16 }
                },
                {
                        0xcf, { rst_08h_, "RST 08H ", 1, 16 }
                },
                {
                        0xf7, { rst_30h_, "RST 30H ", 1, 16 }
                },
                {
                        0xdf, { rst_18h_, "RST 18H ", 1, 16 }
                },
                {
                        0xef, { rst_28h_, "RST 28H ", 1, 16 }
                },
                {
                        0xff, { rst_38h_, "RST 38H ", 1, 16 }
                },
                {
                        0xcb, { prefix_cb_, "PREFIX CB ", 1, 4 }
                },
                {
                        0xa0, { and_b_, "AND B ", 1, 4 }
                },
                {
                        0xa7, { and_a_, "AND A ", 1, 4 }
                },
                {
                        0xa6, { and__hl__, "AND (HL) ", 1, 8 }
                },
                {
                        0xa5, { and_l_, "AND L ", 1, 4 }
                },
                {
                        0xa4, { and_h_, "AND H ", 1, 4 }
                },
                {
                        0xa3, { and_e_, "AND E ", 1, 4 }
                },
                {
                        0xa2, { and_d_, "AND D ", 1, 4 }
                },
                {
                        0xa1, { and_c_, "AND C ", 1, 4 }
                },
                {
                        0xe6, { and_d8_, "AND d8 ", 2, 8 }
                },
                {
                        0x37, { scf__, "SCF  ", 1, 4 }
                },
                {
                        0x16, { ld_d_d8, "LD D d8", 2, 8 }
                },
                {
                        0x12, { ld__de__a, "LD (DE) A", 1, 8 }
                },
                {
                        0x11, { ld_de_d16, "LD DE d16", 3, 12 }
                },
                {
                        0x1e, { ld_e_d8, "LD E d8", 2, 8 }
                },
                {
                        0x1a, { ld_a__de_, "LD A (DE)", 1, 8 }
                },
                {
                        0x21, { ld_hl_d16, "LD HL d16", 3, 12 }
                },
                {
                        0x26, { ld_h_d8, "LD H d8", 2, 8 }
                },
                {
                        0x22, { ld__hlplus__a, "LD (HL+) A", 1, 8 }
                },
                {
                        0x2a, { ld_a__hlplus_, "LD A (HL+)", 1, 8 }
                },
                {
                        0xe2, { ld__c__a, "LD (C) A", 2, 8 }
                },
                {
                        0x2e, { ld_l_d8, "LD L d8", 2, 8 }
                },
                {
                        0x32, { ld__hlminus__a, "LD (HL-) A", 1, 8 }
                },
                {
                        0x31, { ld_sp_d16, "LD SP d16", 3, 12 }
                },
                {
                        0x36, { ld__hl__d8, "LD (HL) d8", 2, 12 }
                },
                {
                        0x3a, { ld_a__hlminus_, "LD A (HL-)", 1, 8 }
                },
                {
                        0xf2, { ld_a__c_, "LD A (C)", 2, 8 }
                },
                {
                        0xf9, { ld_sp_hl, "LD SP HL", 1, 8 }
                },
                {
                        0x3e, { ld_a_d8, "LD A d8", 2, 8 }
                },
                {
                        0xf8, { ld_hl_spplusr8, "LD HL SP+r8", 2, 12 }
                },
                {
                        0x43, { ld_b_e, "LD B E", 1, 4 }
                },
                {
                        0x42, { ld_b_d, "LD B D", 1, 4 }
                },
                {
                        0x41, { ld_b_c, "LD B C", 1, 4 }
                },
                {
                        0x40, { ld_b_b, "LD B B", 1, 4 }
                },
                {
                        0x49, { ld_c_c, "LD C C", 1, 4 }
                },
                {
                        0x48, { ld_c_b, "LD C B", 1, 4 }
                },
                {
                        0x47, { ld_b_a, "LD B A", 1, 4 }
                },
                {
                        0x46, { ld_b__hl_, "LD B (HL)", 1, 8 }
                },
                {
                        0x45, { ld_b_l, "LD B L", 1, 4 }
                },
                {
                        0x44, { ld_b_h, "LD B H", 1, 4 }
                },
                {
                        0x4c, { ld_c_h, "LD C H", 1, 4 }
                },
                {
                        0x4b, { ld_c_e, "LD C E", 1, 4 }
                },
                {
                        0x4a, { ld_c_d, "LD C D", 1, 4 }
                },
                {
                        0x01, { ld_bc_d16, "LD BC d16", 3, 12 }
                },
                {
                        0x02, { ld__bc__a, "LD (BC) A", 1, 8 }
                },
                {
                        0x4f, { ld_c_a, "LD C A", 1, 4 }
                },
                {
                        0x06, { ld_b_d8, "LD B d8", 2, 8 }
                },
                {
                        0x4e, { ld_c__hl_, "LD C (HL)", 1, 8 }
                },
                {
                        0x4d, { ld_c_l, "LD C L", 1, 4 }
                },
                {
                        0x08, { ld__a16__sp, "LD (a16) SP", 3, 20 }
                },
                {
                        0x54, { ld_d_h, "LD D H", 1, 4 }
                },
                {
                        0x53, { ld_d_e, "LD D E", 1, 4 }
                },
                {
                        0x52, { ld_d_d, "LD D D", 1, 4 }
                },
                {
                        0x51, { ld_d_c, "LD D C", 1, 4 }
                },
                {
                        0xea, { ld__a16__a, "LD (a16) A", 3, 16 }
                },
                {
                        0x50, { ld_d_b, "LD D B", 1, 4 }
                },
                {
                        0x59, { ld_e_c, "LD E C", 1, 4 }
                },
                {
                        0x58, { ld_e_b, "LD E B", 1, 4 }
                },
                {
                        0x57, { ld_d_a, "LD D A", 1, 4 }
                },
                {
                        0x56, { ld_d__hl_, "LD D (HL)", 1, 8 }
                },
                {
                        0x55, { ld_d_l, "LD D L", 1, 4 }
                },
                {
                        0x5d, { ld_e_l, "LD E L", 1, 4 }
                },
                {
                        0x5c, { ld_e_h, "LD E H", 1, 4 }
                },
                {
                        0x5b, { ld_e_e, "LD E E", 1, 4 }
                },
                {
                        0x5a, { ld_e_d, "LD E D", 1, 4 }
                },
                {
                        0x5f, { ld_e_a, "LD E A", 1, 4 }
                },
                {
                        0x5e, { ld_e__hl_, "LD E (HL)", 1, 8 }
                },
                {
                        0x65, { ld_h_l, "LD H L", 1, 4 }
                },
                {
                        0x64, { ld_h_h, "LD H H", 1, 4 }
                },
                {
                        0x63, { ld_h_e, "LD H E", 1, 4 }
                },
                {
                        0x62, { ld_h_d, "LD H D", 1, 4 }
                },
                {
                        0x61, { ld_h_c, "LD H C", 1, 4 }
                },
                {
                        0xfa, { ld_a__a16_, "LD A (a16)", 3, 16 }
                },
                {
                        0x60, { ld_h_b, "LD H B", 1, 4 }
                },
                {
                        0x0a, { ld_a__bc_, "LD A (BC)", 1, 8 }
                },
                {
                        0x69, { ld_l_c, "LD L C", 1, 4 }
                },
                {
                        0x0e, { ld_c_d8, "LD C d8", 2, 8 }
                },
                {
                        0x68, { ld_l_b, "LD L B", 1, 4 }
                },
                {
                        0x67, { ld_h_a, "LD H A", 1, 4 }
                },
                {
                        0x66, { ld_h__hl_, "LD H (HL)", 1, 8 }
                },
                {
                        0x6e, { ld_l__hl_, "LD L (HL)", 1, 8 }
                },
                {
                        0x6d, { ld_l_l, "LD L L", 1, 4 }
                },
                {
                        0x6c, { ld_l_h, "LD L H", 1, 4 }
                },
                {
                        0x6b, { ld_l_e, "LD L E", 1, 4 }
                },
                {
                        0x6a, { ld_l_d, "LD L D", 1, 4 }
                },
                {
                        0x6f, { ld_l_a, "LD L A", 1, 4 }
                },
                {
                        0x75, { ld__hl__l, "LD (HL) L", 1, 8 }
                },
                {
                        0x74, { ld__hl__h, "LD (HL) H", 1, 8 }
                },
                {
                        0x73, { ld__hl__e, "LD (HL) E", 1, 8 }
                },
                {
                        0x72, { ld__hl__d, "LD (HL) D", 1, 8 }
                },
                {
                        0x71, { ld__hl__c, "LD (HL) C", 1, 8 }
                },
                {
                        0x70, { ld__hl__b, "LD (HL) B", 1, 8 }
                },
                {
                        0x79, { ld_a_c, "LD A C", 1, 4 }
                },
                {
                        0x78, { ld_a_b, "LD A B", 1, 4 }
                },
                {
                        0x77, { ld__hl__a, "LD (HL) A", 1, 8 }
                },
                {
                        0x7f, { ld_a_a, "LD A A", 1, 4 }
                },
                {
                        0x7e, { ld_a__hl_, "LD A (HL)", 1, 8 }
                },
                {
                        0x7d, { ld_a_l, "LD A L", 1, 4 }
                },
                {
                        0x7c, { ld_a_h, "LD A H", 1, 4 }
                },
                {
                        0x7b, { ld_a_e, "LD A E", 1, 4 }
                },
                {
                        0x7a, { ld_a_d, "LD A D", 1, 4 }
                },
                {
                        0x0f, { rrca__, "RRCA  ", 1, 4 }
                },
                {
                        0xa8, { xor_b_, "XOR B ", 1, 4 }
                },
                {
                        0xa9, { xor_c_, "XOR C ", 1, 4 }
                },
                {
                        0xaf, { xor_a_, "XOR A ", 1, 4 }
                },
                {
                        0xae, { xor__hl__, "XOR (HL) ", 1, 8 }
                },
                {
                        0xad, { xor_l_, "XOR L ", 1, 4 }
                },
                {
                        0xac, { xor_h_, "XOR H ", 1, 4 }
                },
                {
                        0xab, { xor_e_, "XOR E ", 1, 4 }
                },
                {
                        0xaa, { xor_d_, "XOR D ", 1, 4 }
                },
                {
                        0xee, { xor_d8_, "XOR d8 ", 2, 8 }
                },
                {
                        0x2f, { cpl__, "CPL  ", 1, 4 }
                },
                {
                        0x07, { rlca__, "RLCA  ", 1, 4 }
                },
                {
                        0xc5, { push_bc_, "PUSH BC ", 1, 16 }
                },
                {
                        0xd5, { push_de_, "PUSH DE ", 1, 16 }
                },
                {
                        0xe5, { push_hl_, "PUSH HL ", 1, 16 }
                },
                {
                        0xf5, { push_af_, "PUSH AF ", 1, 16 }
                },
                {
                        0x14, { inc_d_, "INC D ", 1, 4 }
                },
                {
                        0x13, { inc_de_, "INC DE ", 1, 8 }
                },
                {
                        0x1c, { inc_e_, "INC E ", 1, 4 }
                },
                {
                        0x24, { inc_h_, "INC H ", 1, 4 }
                },
                {
                        0x23, { inc_hl_, "INC HL ", 1, 8 }
                },
                {
                        0x2c, { inc_l_, "INC L ", 1, 4 }
                },
                {
                        0x34, { inc__hl__, "INC (HL) ", 1, 12 }
                },
                {
                        0x33, { inc_sp_, "INC SP ", 1, 8 }
                },
                {
                        0x3c, { inc_a_, "INC A ", 1, 4 }
                },
                {
                        0x03, { inc_bc_, "INC BC ", 1, 8 }
                },
                {
                        0x04, { inc_b_, "INC B ", 1, 4 }
                },
                {
                        0x0c, { inc_c_, "INC C ", 1, 4 }
                }
        };

        return instructionMap;
    }



} // namespace Instruction