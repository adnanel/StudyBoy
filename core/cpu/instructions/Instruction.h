//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_INSTRUCTION_H
#define STUDYBOY_INSTRUCTION_H

#include <string>
#include <map>
#include <functional>

#include "./../../GameBoyCore.h"

typedef std::function<void(GameBoyCore*, unsigned long long)> InstructionFun;
namespace Instruction {
    // RET NZ
    void ret_nz_(GameBoyCore* core, unsigned long long opcode);

    // RET
    void ret__(GameBoyCore* core, unsigned long long opcode);

    // RET Z
    void ret_z_(GameBoyCore* core, unsigned long long opcode);

    // RET NC
    void ret_nc_(GameBoyCore* core, unsigned long long opcode);

    // RET C
    void ret_c_(GameBoyCore* core, unsigned long long opcode);

    // RRA
    void rra__(GameBoyCore* core, unsigned long long opcode);

    // ADC A d8
    void adc_a_d8(GameBoyCore* core, unsigned long long opcode);

    // ADC A C
    void adc_a_c(GameBoyCore* core, unsigned long long opcode);

    // ADC A B
    void adc_a_b(GameBoyCore* core, unsigned long long opcode);

    // ADC A A
    void adc_a_a(GameBoyCore* core, unsigned long long opcode);

    // ADC A (HL)
    void adc_a__hl_(GameBoyCore* core, unsigned long long opcode);

    // ADC A L
    void adc_a_l(GameBoyCore* core, unsigned long long opcode);

    // ADC A H
    void adc_a_h(GameBoyCore* core, unsigned long long opcode);

    // ADC A E
    void adc_a_e(GameBoyCore* core, unsigned long long opcode);

    // ADC A D
    void adc_a_d(GameBoyCore* core, unsigned long long opcode);

    // ADD HL DE
    void add_hl_de(GameBoyCore* core, unsigned long long opcode);

    // ADD A d8
    void add_a_d8(GameBoyCore* core, unsigned long long opcode);

    // ADD HL HL
    void add_hl_hl(GameBoyCore* core, unsigned long long opcode);

    // ADD SP r8
    void add_sp_r8(GameBoyCore* core, unsigned long long opcode);

    // ADD HL SP
    void add_hl_sp(GameBoyCore* core, unsigned long long opcode);

    // ADD HL BC
    void add_hl_bc(GameBoyCore* core, unsigned long long opcode);

    // ADD A A
    void add_a_a(GameBoyCore* core, unsigned long long opcode);

    // ADD A (HL)
    void add_a__hl_(GameBoyCore* core, unsigned long long opcode);

    // ADD A L
    void add_a_l(GameBoyCore* core, unsigned long long opcode);

    // ADD A H
    void add_a_h(GameBoyCore* core, unsigned long long opcode);

    // ADD A E
    void add_a_e(GameBoyCore* core, unsigned long long opcode);

    // ADD A D
    void add_a_d(GameBoyCore* core, unsigned long long opcode);

    // ADD A C
    void add_a_c(GameBoyCore* core, unsigned long long opcode);

    // ADD A B
    void add_a_b(GameBoyCore* core, unsigned long long opcode);

    // CALL NZ a16
    void call_nz_a16(GameBoyCore* core, unsigned long long opcode);

    // CALL NC a16
    void call_nc_a16(GameBoyCore* core, unsigned long long opcode);

    // CALL a16
    void call_a16_(GameBoyCore* core, unsigned long long opcode);

    // CALL Z a16
    void call_z_a16(GameBoyCore* core, unsigned long long opcode);

    // CALL C a16
    void call_c_a16(GameBoyCore* core, unsigned long long opcode);

    // DI
    void di__(GameBoyCore* core, unsigned long long opcode);

    // JP NZ a16
    void jp_nz_a16(GameBoyCore* core, unsigned long long opcode);

    // JP a16
    void jp_a16_(GameBoyCore* core, unsigned long long opcode);

    // JP NC a16
    void jp_nc_a16(GameBoyCore* core, unsigned long long opcode);

    // JP (HL)
    void jp__hl__(GameBoyCore* core, unsigned long long opcode);

    // JP Z a16
    void jp_z_a16(GameBoyCore* core, unsigned long long opcode);

    // JP C a16
    void jp_c_a16(GameBoyCore* core, unsigned long long opcode);

    // RLA
    void rla__(GameBoyCore* core, unsigned long long opcode);

    // JR r8
    void jr_r8_(GameBoyCore* core, unsigned long long opcode);

    // JR NZ r8
    void jr_nz_r8(GameBoyCore* core, unsigned long long opcode);

    // JR Z r8
    void jr_z_r8(GameBoyCore* core, unsigned long long opcode);

    // JR NC r8
    void jr_nc_r8(GameBoyCore* core, unsigned long long opcode);

    // JR C r8
    void jr_c_r8(GameBoyCore* core, unsigned long long opcode);

    // RETI
    void reti__(GameBoyCore* core, unsigned long long opcode);

    // LDH (a8) A
    void ldh__a8__a(GameBoyCore* core, unsigned long long opcode);

    // LDH A (a8)
    void ldh_a__a8_(GameBoyCore* core, unsigned long long opcode);

    // SBC A d8
    void sbc_a_d8(GameBoyCore* core, unsigned long long opcode);

    // SBC A B
    void sbc_a_b(GameBoyCore* core, unsigned long long opcode);

    // SBC A C
    void sbc_a_c(GameBoyCore* core, unsigned long long opcode);

    // SBC A A
    void sbc_a_a(GameBoyCore* core, unsigned long long opcode);

    // SBC A (HL)
    void sbc_a__hl_(GameBoyCore* core, unsigned long long opcode);

    // SBC A L
    void sbc_a_l(GameBoyCore* core, unsigned long long opcode);

    // SBC A H
    void sbc_a_h(GameBoyCore* core, unsigned long long opcode);

    // SBC A E
    void sbc_a_e(GameBoyCore* core, unsigned long long opcode);

    // SBC A D
    void sbc_a_d(GameBoyCore* core, unsigned long long opcode);

    // HALT
    void halt__(GameBoyCore* core, unsigned long long opcode);

    // SUB d8
    void sub_d8_(GameBoyCore* core, unsigned long long opcode);

    // SUB B
    void sub_b_(GameBoyCore* core, unsigned long long opcode);

    // SUB A
    void sub_a_(GameBoyCore* core, unsigned long long opcode);

    // SUB (HL)
    void sub__hl__(GameBoyCore* core, unsigned long long opcode);

    // SUB L
    void sub_l_(GameBoyCore* core, unsigned long long opcode);

    // SUB H
    void sub_h_(GameBoyCore* core, unsigned long long opcode);

    // SUB E
    void sub_e_(GameBoyCore* core, unsigned long long opcode);

    // SUB D
    void sub_d_(GameBoyCore* core, unsigned long long opcode);

    // SUB C
    void sub_c_(GameBoyCore* core, unsigned long long opcode);

    // OR C
    void or_c_(GameBoyCore* core, unsigned long long opcode);

    // OR B
    void or_b_(GameBoyCore* core, unsigned long long opcode);

    // OR A
    void or_a_(GameBoyCore* core, unsigned long long opcode);

    // OR (HL)
    void or__hl__(GameBoyCore* core, unsigned long long opcode);

    // OR L
    void or_l_(GameBoyCore* core, unsigned long long opcode);

    // OR H
    void or_h_(GameBoyCore* core, unsigned long long opcode);

    // OR E
    void or_e_(GameBoyCore* core, unsigned long long opcode);

    // OR D
    void or_d_(GameBoyCore* core, unsigned long long opcode);

    // OR d8
    void or_d8_(GameBoyCore* core, unsigned long long opcode);

    // DEC D
    void dec_d_(GameBoyCore* core, unsigned long long opcode);

    // DEC E
    void dec_e_(GameBoyCore* core, unsigned long long opcode);

    // DEC DE
    void dec_de_(GameBoyCore* core, unsigned long long opcode);

    // DEC H
    void dec_h_(GameBoyCore* core, unsigned long long opcode);

    // DEC L
    void dec_l_(GameBoyCore* core, unsigned long long opcode);

    // DEC HL
    void dec_hl_(GameBoyCore* core, unsigned long long opcode);

    // DEC (HL)
    void dec__hl__(GameBoyCore* core, unsigned long long opcode);

    // DEC SP
    void dec_sp_(GameBoyCore* core, unsigned long long opcode);

    // DEC A
    void dec_a_(GameBoyCore* core, unsigned long long opcode);

    // DEC B
    void dec_b_(GameBoyCore* core, unsigned long long opcode);

    // DEC BC
    void dec_bc_(GameBoyCore* core, unsigned long long opcode);

    // DEC C
    void dec_c_(GameBoyCore* core, unsigned long long opcode);

    // EI
    void ei__(GameBoyCore* core, unsigned long long opcode);

    // STOP 0
    void stop_0_(GameBoyCore* core, unsigned long long opcode);

    // DAA
    void daa__(GameBoyCore* core, unsigned long long opcode);

    // CCF
    void ccf__(GameBoyCore* core, unsigned long long opcode);

    // CP C
    void cp_c_(GameBoyCore* core, unsigned long long opcode);

    // CP B
    void cp_b_(GameBoyCore* core, unsigned long long opcode);

    // CP D
    void cp_d_(GameBoyCore* core, unsigned long long opcode);

    // CP A
    void cp_a_(GameBoyCore* core, unsigned long long opcode);

    // CP (HL)
    void cp__hl__(GameBoyCore* core, unsigned long long opcode);

    // CP L
    void cp_l_(GameBoyCore* core, unsigned long long opcode);

    // CP H
    void cp_h_(GameBoyCore* core, unsigned long long opcode);

    // CP E
    void cp_e_(GameBoyCore* core, unsigned long long opcode);

    // CP d8
    void cp_d8_(GameBoyCore* core, unsigned long long opcode);

    // NOP
    void nop__(GameBoyCore* core, unsigned long long opcode);

    // POP BC
    void pop_bc_(GameBoyCore* core, unsigned long long opcode);

    // POP DE
    void pop_de_(GameBoyCore* core, unsigned long long opcode);

    // POP HL
    void pop_hl_(GameBoyCore* core, unsigned long long opcode);

    // POP AF
    void pop_af_(GameBoyCore* core, unsigned long long opcode);

    // RST 00H
    void rst_00h_(GameBoyCore* core, unsigned long long opcode);

    // RST 10H
    void rst_10h_(GameBoyCore* core, unsigned long long opcode);

    // RST 20H
    void rst_20h_(GameBoyCore* core, unsigned long long opcode);

    // RST 08H
    void rst_08h_(GameBoyCore* core, unsigned long long opcode);

    // RST 30H
    void rst_30h_(GameBoyCore* core, unsigned long long opcode);

    // RST 18H
    void rst_18h_(GameBoyCore* core, unsigned long long opcode);

    // RST 28H
    void rst_28h_(GameBoyCore* core, unsigned long long opcode);

    // RST 38H
    void rst_38h_(GameBoyCore* core, unsigned long long opcode);

    // PREFIX CB
    void prefix_cb_(GameBoyCore* core, unsigned long long opcode);

    // AND B
    void and_b_(GameBoyCore* core, unsigned long long opcode);

    // AND A
    void and_a_(GameBoyCore* core, unsigned long long opcode);

    // AND (HL)
    void and__hl__(GameBoyCore* core, unsigned long long opcode);

    // AND L
    void and_l_(GameBoyCore* core, unsigned long long opcode);

    // AND H
    void and_h_(GameBoyCore* core, unsigned long long opcode);

    // AND E
    void and_e_(GameBoyCore* core, unsigned long long opcode);

    // AND D
    void and_d_(GameBoyCore* core, unsigned long long opcode);

    // AND C
    void and_c_(GameBoyCore* core, unsigned long long opcode);

    // AND d8
    void and_d8_(GameBoyCore* core, unsigned long long opcode);

    // SCF
    void scf__(GameBoyCore* core, unsigned long long opcode);

    // LD D d8
    void ld_d_d8(GameBoyCore* core, unsigned long long opcode);

    // LD (DE) A
    void ld__de__a(GameBoyCore* core, unsigned long long opcode);

    // LD DE d16
    void ld_de_d16(GameBoyCore* core, unsigned long long opcode);

    // LD E d8
    void ld_e_d8(GameBoyCore* core, unsigned long long opcode);

    // LD A (DE)
    void ld_a__de_(GameBoyCore* core, unsigned long long opcode);

    // LD HL d16
    void ld_hl_d16(GameBoyCore* core, unsigned long long opcode);

    // LD H d8
    void ld_h_d8(GameBoyCore* core, unsigned long long opcode);

    // LD (HL+) A
    void ld__hlplus__a(GameBoyCore* core, unsigned long long opcode);

    // LD A (HL+)
    void ld_a__hlplus_(GameBoyCore* core, unsigned long long opcode);

    // LD (C) A
    void ld__c__a(GameBoyCore* core, unsigned long long opcode);

    // LD L d8
    void ld_l_d8(GameBoyCore* core, unsigned long long opcode);

    // LD (HL-) A
    void ld__hlminus__a(GameBoyCore* core, unsigned long long opcode);

    // LD SP d16
    void ld_sp_d16(GameBoyCore* core, unsigned long long opcode);

    // LD (HL) d8
    void ld__hl__d8(GameBoyCore* core, unsigned long long opcode);

    // LD A (HL-)
    void ld_a__hlminus_(GameBoyCore* core, unsigned long long opcode);

    // LD A (C)
    void ld_a__c_(GameBoyCore* core, unsigned long long opcode);

    // LD SP HL
    void ld_sp_hl(GameBoyCore* core, unsigned long long opcode);

    // LD A d8
    void ld_a_d8(GameBoyCore* core, unsigned long long opcode);

    // LD HL SP+r8
    void ld_hl_spplusr8(GameBoyCore* core, unsigned long long opcode);

    // LD B E
    void ld_b_e(GameBoyCore* core, unsigned long long opcode);

    // LD B D
    void ld_b_d(GameBoyCore* core, unsigned long long opcode);

    // LD B C
    void ld_b_c(GameBoyCore* core, unsigned long long opcode);

    // LD B B
    void ld_b_b(GameBoyCore* core, unsigned long long opcode);

    // LD C C
    void ld_c_c(GameBoyCore* core, unsigned long long opcode);

    // LD C B
    void ld_c_b(GameBoyCore* core, unsigned long long opcode);

    // LD B A
    void ld_b_a(GameBoyCore* core, unsigned long long opcode);

    // LD B (HL)
    void ld_b__hl_(GameBoyCore* core, unsigned long long opcode);

    // LD B L
    void ld_b_l(GameBoyCore* core, unsigned long long opcode);

    // LD B H
    void ld_b_h(GameBoyCore* core, unsigned long long opcode);

    // LD C H
    void ld_c_h(GameBoyCore* core, unsigned long long opcode);

    // LD C E
    void ld_c_e(GameBoyCore* core, unsigned long long opcode);

    // LD C D
    void ld_c_d(GameBoyCore* core, unsigned long long opcode);

    // LD BC d16
    void ld_bc_d16(GameBoyCore* core, unsigned long long opcode);

    // LD (BC) A
    void ld__bc__a(GameBoyCore* core, unsigned long long opcode);

    // LD C A
    void ld_c_a(GameBoyCore* core, unsigned long long opcode);

    // LD B d8
    void ld_b_d8(GameBoyCore* core, unsigned long long opcode);

    // LD C (HL)
    void ld_c__hl_(GameBoyCore* core, unsigned long long opcode);

    // LD C L
    void ld_c_l(GameBoyCore* core, unsigned long long opcode);

    // LD (a16) SP
    void ld__a16__sp(GameBoyCore* core, unsigned long long opcode);

    // LD D H
    void ld_d_h(GameBoyCore* core, unsigned long long opcode);

    // LD D E
    void ld_d_e(GameBoyCore* core, unsigned long long opcode);

    // LD D D
    void ld_d_d(GameBoyCore* core, unsigned long long opcode);

    // LD D C
    void ld_d_c(GameBoyCore* core, unsigned long long opcode);

    // LD (a16) A
    void ld__a16__a(GameBoyCore* core, unsigned long long opcode);

    // LD D B
    void ld_d_b(GameBoyCore* core, unsigned long long opcode);

    // LD E C
    void ld_e_c(GameBoyCore* core, unsigned long long opcode);

    // LD E B
    void ld_e_b(GameBoyCore* core, unsigned long long opcode);

    // LD D A
    void ld_d_a(GameBoyCore* core, unsigned long long opcode);

    // LD D (HL)
    void ld_d__hl_(GameBoyCore* core, unsigned long long opcode);

    // LD D L
    void ld_d_l(GameBoyCore* core, unsigned long long opcode);

    // LD E L
    void ld_e_l(GameBoyCore* core, unsigned long long opcode);

    // LD E H
    void ld_e_h(GameBoyCore* core, unsigned long long opcode);

    // LD E E
    void ld_e_e(GameBoyCore* core, unsigned long long opcode);

    // LD E D
    void ld_e_d(GameBoyCore* core, unsigned long long opcode);

    // LD E A
    void ld_e_a(GameBoyCore* core, unsigned long long opcode);

    // LD E (HL)
    void ld_e__hl_(GameBoyCore* core, unsigned long long opcode);

    // LD H L
    void ld_h_l(GameBoyCore* core, unsigned long long opcode);

    // LD H H
    void ld_h_h(GameBoyCore* core, unsigned long long opcode);

    // LD H E
    void ld_h_e(GameBoyCore* core, unsigned long long opcode);

    // LD H D
    void ld_h_d(GameBoyCore* core, unsigned long long opcode);

    // LD H C
    void ld_h_c(GameBoyCore* core, unsigned long long opcode);

    // LD A (a16)
    void ld_a__a16_(GameBoyCore* core, unsigned long long opcode);

    // LD H B
    void ld_h_b(GameBoyCore* core, unsigned long long opcode);

    // LD A (BC)
    void ld_a__bc_(GameBoyCore* core, unsigned long long opcode);

    // LD L C
    void ld_l_c(GameBoyCore* core, unsigned long long opcode);

    // LD C d8
    void ld_c_d8(GameBoyCore* core, unsigned long long opcode);

    // LD L B
    void ld_l_b(GameBoyCore* core, unsigned long long opcode);

    // LD H A
    void ld_h_a(GameBoyCore* core, unsigned long long opcode);

    // LD H (HL)
    void ld_h__hl_(GameBoyCore* core, unsigned long long opcode);

    // LD L (HL)
    void ld_l__hl_(GameBoyCore* core, unsigned long long opcode);

    // LD L L
    void ld_l_l(GameBoyCore* core, unsigned long long opcode);

    // LD L H
    void ld_l_h(GameBoyCore* core, unsigned long long opcode);

    // LD L E
    void ld_l_e(GameBoyCore* core, unsigned long long opcode);

    // LD L D
    void ld_l_d(GameBoyCore* core, unsigned long long opcode);

    // LD L A
    void ld_l_a(GameBoyCore* core, unsigned long long opcode);

    // LD (HL) L
    void ld__hl__l(GameBoyCore* core, unsigned long long opcode);

    // LD (HL) H
    void ld__hl__h(GameBoyCore* core, unsigned long long opcode);

    // LD (HL) E
    void ld__hl__e(GameBoyCore* core, unsigned long long opcode);

    // LD (HL) D
    void ld__hl__d(GameBoyCore* core, unsigned long long opcode);

    // LD (HL) C
    void ld__hl__c(GameBoyCore* core, unsigned long long opcode);

    // LD (HL) B
    void ld__hl__b(GameBoyCore* core, unsigned long long opcode);

    // LD A C
    void ld_a_c(GameBoyCore* core, unsigned long long opcode);

    // LD A B
    void ld_a_b(GameBoyCore* core, unsigned long long opcode);

    // LD (HL) A
    void ld__hl__a(GameBoyCore* core, unsigned long long opcode);

    // LD A A
    void ld_a_a(GameBoyCore* core, unsigned long long opcode);

    // LD A (HL)
    void ld_a__hl_(GameBoyCore* core, unsigned long long opcode);

    // LD A L
    void ld_a_l(GameBoyCore* core, unsigned long long opcode);

    // LD A H
    void ld_a_h(GameBoyCore* core, unsigned long long opcode);

    // LD A E
    void ld_a_e(GameBoyCore* core, unsigned long long opcode);

    // LD A D
    void ld_a_d(GameBoyCore* core, unsigned long long opcode);

    // RRCA
    void rrca__(GameBoyCore* core, unsigned long long opcode);

    // XOR B
    void xor_b_(GameBoyCore* core, unsigned long long opcode);

    // XOR C
    void xor_c_(GameBoyCore* core, unsigned long long opcode);

    // XOR A
    void xor_a_(GameBoyCore* core, unsigned long long opcode);

    // XOR (HL)
    void xor__hl__(GameBoyCore* core, unsigned long long opcode);

    // XOR L
    void xor_l_(GameBoyCore* core, unsigned long long opcode);

    // XOR H
    void xor_h_(GameBoyCore* core, unsigned long long opcode);

    // XOR E
    void xor_e_(GameBoyCore* core, unsigned long long opcode);

    // XOR D
    void xor_d_(GameBoyCore* core, unsigned long long opcode);

    // XOR d8
    void xor_d8_(GameBoyCore* core, unsigned long long opcode);

    // CPL
    void cpl__(GameBoyCore* core, unsigned long long opcode);

    // RLCA
    void rlca__(GameBoyCore* core, unsigned long long opcode);

    // PUSH BC
    void push_bc_(GameBoyCore* core, unsigned long long opcode);

    // PUSH DE
    void push_de_(GameBoyCore* core, unsigned long long opcode);

    // PUSH HL
    void push_hl_(GameBoyCore* core, unsigned long long opcode);

    // PUSH AF
    void push_af_(GameBoyCore* core, unsigned long long opcode);

    // INC D
    void inc_d_(GameBoyCore* core, unsigned long long opcode);

    // INC DE
    void inc_de_(GameBoyCore* core, unsigned long long opcode);

    // INC E
    void inc_e_(GameBoyCore* core, unsigned long long opcode);

    // INC H
    void inc_h_(GameBoyCore* core, unsigned long long opcode);

    // INC HL
    void inc_hl_(GameBoyCore* core, unsigned long long opcode);

    // INC L
    void inc_l_(GameBoyCore* core, unsigned long long opcode);

    // INC (HL)
    void inc__hl__(GameBoyCore* core, unsigned long long opcode);

    // INC SP
    void inc_sp_(GameBoyCore* core, unsigned long long opcode);

    // INC A
    void inc_a_(GameBoyCore* core, unsigned long long opcode);

    // INC BC
    void inc_bc_(GameBoyCore* core, unsigned long long opcode);

    // INC B
    void inc_b_(GameBoyCore* core, unsigned long long opcode);

    // INC C
    void inc_c_(GameBoyCore* core, unsigned long long opcode);




    InstructionFun DecodeInstruction(unsigned long long opcode);
};


#endif //STUDYBOY_INSTRUCTION_H
