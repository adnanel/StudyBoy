//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_INSTRUCTION_H
#define STUDYBOY_INSTRUCTION_H

#include <string>
#include <map>
#include <functional>

#include "./../../GameBoyCore.h"

typedef std::function<void(GameBoyCore*)> InstructionFun;
namespace Instruction {
    // RET NZ
    void ret_nz_(GameBoyCore* core);

    // RET
    void ret__(GameBoyCore* core);

    // RET Z
    void ret_z_(GameBoyCore* core);

    // RET NC
    void ret_nc_(GameBoyCore* core);

    // RET C
    void ret_c_(GameBoyCore* core);

    // RRA
    void rra__(GameBoyCore* core);

    // ADC A d8
    void adc_a_d8(GameBoyCore* core);

    // ADC A C
    void adc_a_c(GameBoyCore* core);

    // ADC A B
    void adc_a_b(GameBoyCore* core);

    // ADC A A
    void adc_a_a(GameBoyCore* core);

    // ADC A (HL)
    void adc_a__hl_(GameBoyCore* core);

    // ADC A L
    void adc_a_l(GameBoyCore* core);

    // ADC A H
    void adc_a_h(GameBoyCore* core);

    // ADC A E
    void adc_a_e(GameBoyCore* core);

    // ADC A D
    void adc_a_d(GameBoyCore* core);

    // ADD HL DE
    void add_hl_de(GameBoyCore* core);

    // ADD A d8
    void add_a_d8(GameBoyCore* core);

    // ADD HL HL
    void add_hl_hl(GameBoyCore* core);

    // ADD SP r8
    void add_sp_r8(GameBoyCore* core);

    // ADD HL SP
    void add_hl_sp(GameBoyCore* core);

    // ADD HL BC
    void add_hl_bc(GameBoyCore* core);

    // ADD A A
    void add_a_a(GameBoyCore* core);

    // ADD A (HL)
    void add_a__hl_(GameBoyCore* core);

    // ADD A L
    void add_a_l(GameBoyCore* core);

    // ADD A H
    void add_a_h(GameBoyCore* core);

    // ADD A E
    void add_a_e(GameBoyCore* core);

    // ADD A D
    void add_a_d(GameBoyCore* core);

    // ADD A C
    void add_a_c(GameBoyCore* core);

    // ADD A B
    void add_a_b(GameBoyCore* core);

    // CALL NZ a16
    void call_nz_a16(GameBoyCore* core);

    // CALL NC a16
    void call_nc_a16(GameBoyCore* core);

    // CALL a16
    void call_a16_(GameBoyCore* core);

    // CALL Z a16
    void call_z_a16(GameBoyCore* core);

    // CALL C a16
    void call_c_a16(GameBoyCore* core);

    // DI
    void di__(GameBoyCore* core);

    // JP NZ a16
    void jp_nz_a16(GameBoyCore* core);

    // JP a16
    void jp_a16_(GameBoyCore* core);

    // JP NC a16
    void jp_nc_a16(GameBoyCore* core);

    // JP (HL)
    void jp__hl__(GameBoyCore* core);

    // JP Z a16
    void jp_z_a16(GameBoyCore* core);

    // JP C a16
    void jp_c_a16(GameBoyCore* core);

    // RLA
    void rla__(GameBoyCore* core);

    // JR r8
    void jr_r8_(GameBoyCore* core);

    // JR NZ r8
    void jr_nz_r8(GameBoyCore* core);

    // JR Z r8
    void jr_z_r8(GameBoyCore* core);

    // JR NC r8
    void jr_nc_r8(GameBoyCore* core);

    // JR C r8
    void jr_c_r8(GameBoyCore* core);

    // RETI
    void reti__(GameBoyCore* core);

    // LDH (a8) A
    void ldh__a8__a(GameBoyCore* core);

    // LDH A (a8)
    void ldh_a__a8_(GameBoyCore* core);

    // SBC A d8
    void sbc_a_d8(GameBoyCore* core);

    // SBC A B
    void sbc_a_b(GameBoyCore* core);

    // SBC A C
    void sbc_a_c(GameBoyCore* core);

    // SBC A A
    void sbc_a_a(GameBoyCore* core);

    // SBC A (HL)
    void sbc_a__hl_(GameBoyCore* core);

    // SBC A L
    void sbc_a_l(GameBoyCore* core);

    // SBC A H
    void sbc_a_h(GameBoyCore* core);

    // SBC A E
    void sbc_a_e(GameBoyCore* core);

    // SBC A D
    void sbc_a_d(GameBoyCore* core);

    // HALT
    void halt__(GameBoyCore* core);

    // SUB d8
    void sub_d8_(GameBoyCore* core);

    // SUB B
    void sub_b_(GameBoyCore* core);

    // SUB A
    void sub_a_(GameBoyCore* core);

    // SUB (HL)
    void sub__hl__(GameBoyCore* core);

    // SUB L
    void sub_l_(GameBoyCore* core);

    // SUB H
    void sub_h_(GameBoyCore* core);

    // SUB E
    void sub_e_(GameBoyCore* core);

    // SUB D
    void sub_d_(GameBoyCore* core);

    // SUB C
    void sub_c_(GameBoyCore* core);

    // OR C
    void or_c_(GameBoyCore* core);

    // OR B
    void or_b_(GameBoyCore* core);

    // OR A
    void or_a_(GameBoyCore* core);

    // OR (HL)
    void or__hl__(GameBoyCore* core);

    // OR L
    void or_l_(GameBoyCore* core);

    // OR H
    void or_h_(GameBoyCore* core);

    // OR E
    void or_e_(GameBoyCore* core);

    // OR D
    void or_d_(GameBoyCore* core);

    // OR d8
    void or_d8_(GameBoyCore* core);

    // DEC D
    void dec_d_(GameBoyCore* core);

    // DEC E
    void dec_e_(GameBoyCore* core);

    // DEC DE
    void dec_de_(GameBoyCore* core);

    // DEC H
    void dec_h_(GameBoyCore* core);

    // DEC L
    void dec_l_(GameBoyCore* core);

    // DEC HL
    void dec_hl_(GameBoyCore* core);

    // DEC (HL)
    void dec__hl__(GameBoyCore* core);

    // DEC SP
    void dec_sp_(GameBoyCore* core);

    // DEC A
    void dec_a_(GameBoyCore* core);

    // DEC B
    void dec_b_(GameBoyCore* core);

    // DEC BC
    void dec_bc_(GameBoyCore* core);

    // DEC C
    void dec_c_(GameBoyCore* core);

    // EI
    void ei__(GameBoyCore* core);

    // STOP 0
    void stop_0_(GameBoyCore* core);

    // DAA
    void daa__(GameBoyCore* core);

    // CCF
    void ccf__(GameBoyCore* core);

    // CP C
    void cp_c_(GameBoyCore* core);

    // CP B
    void cp_b_(GameBoyCore* core);

    // CP D
    void cp_d_(GameBoyCore* core);

    // CP A
    void cp_a_(GameBoyCore* core);

    // CP (HL)
    void cp__hl__(GameBoyCore* core);

    // CP L
    void cp_l_(GameBoyCore* core);

    // CP H
    void cp_h_(GameBoyCore* core);

    // CP E
    void cp_e_(GameBoyCore* core);

    // CP d8
    void cp_d8_(GameBoyCore* core);

    // NOP
    void nop__(GameBoyCore* core);

    // POP BC
    void pop_bc_(GameBoyCore* core);

    // POP DE
    void pop_de_(GameBoyCore* core);

    // POP HL
    void pop_hl_(GameBoyCore* core);

    // POP AF
    void pop_af_(GameBoyCore* core);

    // RST 00H
    void rst_00h_(GameBoyCore* core);

    // RST 10H
    void rst_10h_(GameBoyCore* core);

    // RST 20H
    void rst_20h_(GameBoyCore* core);

    // RST 08H
    void rst_08h_(GameBoyCore* core);

    // RST 30H
    void rst_30h_(GameBoyCore* core);

    // RST 18H
    void rst_18h_(GameBoyCore* core);

    // RST 28H
    void rst_28h_(GameBoyCore* core);

    // RST 38H
    void rst_38h_(GameBoyCore* core);

    // PREFIX CB
    void prefix_cb_(GameBoyCore* core);

    // AND B
    void and_b_(GameBoyCore* core);

    // AND A
    void and_a_(GameBoyCore* core);

    // AND (HL)
    void and__hl__(GameBoyCore* core);

    // AND L
    void and_l_(GameBoyCore* core);

    // AND H
    void and_h_(GameBoyCore* core);

    // AND E
    void and_e_(GameBoyCore* core);

    // AND D
    void and_d_(GameBoyCore* core);

    // AND C
    void and_c_(GameBoyCore* core);

    // AND d8
    void and_d8_(GameBoyCore* core);

    // SCF
    void scf__(GameBoyCore* core);

    // LD D d8
    void ld_d_d8(GameBoyCore* core);

    // LD (DE) A
    void ld__de__a(GameBoyCore* core);

    // LD DE d16
    void ld_de_d16(GameBoyCore* core);

    // LD E d8
    void ld_e_d8(GameBoyCore* core);

    // LD A (DE)
    void ld_a__de_(GameBoyCore* core);

    // LD HL d16
    void ld_hl_d16(GameBoyCore* core);

    // LD H d8
    void ld_h_d8(GameBoyCore* core);

    // LD (HL+) A
    void ld__hlplus__a(GameBoyCore* core);

    // LD A (HL+)
    void ld_a__hlplus_(GameBoyCore* core);

    // LD (C) A
    void ld__c__a(GameBoyCore* core);

    // LD L d8
    void ld_l_d8(GameBoyCore* core);

    // LD (HL-) A
    void ld__hlminus__a(GameBoyCore* core);

    // LD SP d16
    void ld_sp_d16(GameBoyCore* core);

    // LD (HL) d8
    void ld__hl__d8(GameBoyCore* core);

    // LD A (HL-)
    void ld_a__hlminus_(GameBoyCore* core);

    // LD A (C)
    void ld_a__c_(GameBoyCore* core);

    // LD SP HL
    void ld_sp_hl(GameBoyCore* core);

    // LD A d8
    void ld_a_d8(GameBoyCore* core);

    // LD HL SP+r8
    void ld_hl_spplusr8(GameBoyCore* core);

    // LD B E
    void ld_b_e(GameBoyCore* core);

    // LD B D
    void ld_b_d(GameBoyCore* core);

    // LD B C
    void ld_b_c(GameBoyCore* core);

    // LD B B
    void ld_b_b(GameBoyCore* core);

    // LD C C
    void ld_c_c(GameBoyCore* core);

    // LD C B
    void ld_c_b(GameBoyCore* core);

    // LD B A
    void ld_b_a(GameBoyCore* core);

    // LD B (HL)
    void ld_b__hl_(GameBoyCore* core);

    // LD B L
    void ld_b_l(GameBoyCore* core);

    // LD B H
    void ld_b_h(GameBoyCore* core);

    // LD C H
    void ld_c_h(GameBoyCore* core);

    // LD C E
    void ld_c_e(GameBoyCore* core);

    // LD C D
    void ld_c_d(GameBoyCore* core);

    // LD BC d16
    void ld_bc_d16(GameBoyCore* core);

    // LD (BC) A
    void ld__bc__a(GameBoyCore* core);

    // LD C A
    void ld_c_a(GameBoyCore* core);

    // LD B d8
    void ld_b_d8(GameBoyCore* core);

    // LD C (HL)
    void ld_c__hl_(GameBoyCore* core);

    // LD C L
    void ld_c_l(GameBoyCore* core);

    // LD (a16) SP
    void ld__a16__sp(GameBoyCore* core);

    // LD D H
    void ld_d_h(GameBoyCore* core);

    // LD D E
    void ld_d_e(GameBoyCore* core);

    // LD D D
    void ld_d_d(GameBoyCore* core);

    // LD D C
    void ld_d_c(GameBoyCore* core);

    // LD (a16) A
    void ld__a16__a(GameBoyCore* core);

    // LD D B
    void ld_d_b(GameBoyCore* core);

    // LD E C
    void ld_e_c(GameBoyCore* core);

    // LD E B
    void ld_e_b(GameBoyCore* core);

    // LD D A
    void ld_d_a(GameBoyCore* core);

    // LD D (HL)
    void ld_d__hl_(GameBoyCore* core);

    // LD D L
    void ld_d_l(GameBoyCore* core);

    // LD E L
    void ld_e_l(GameBoyCore* core);

    // LD E H
    void ld_e_h(GameBoyCore* core);

    // LD E E
    void ld_e_e(GameBoyCore* core);

    // LD E D
    void ld_e_d(GameBoyCore* core);

    // LD E A
    void ld_e_a(GameBoyCore* core);

    // LD E (HL)
    void ld_e__hl_(GameBoyCore* core);

    // LD H L
    void ld_h_l(GameBoyCore* core);

    // LD H H
    void ld_h_h(GameBoyCore* core);

    // LD H E
    void ld_h_e(GameBoyCore* core);

    // LD H D
    void ld_h_d(GameBoyCore* core);

    // LD H C
    void ld_h_c(GameBoyCore* core);

    // LD A (a16)
    void ld_a__a16_(GameBoyCore* core);

    // LD H B
    void ld_h_b(GameBoyCore* core);

    // LD A (BC)
    void ld_a__bc_(GameBoyCore* core);

    // LD L C
    void ld_l_c(GameBoyCore* core);

    // LD C d8
    void ld_c_d8(GameBoyCore* core);

    // LD L B
    void ld_l_b(GameBoyCore* core);

    // LD H A
    void ld_h_a(GameBoyCore* core);

    // LD H (HL)
    void ld_h__hl_(GameBoyCore* core);

    // LD L (HL)
    void ld_l__hl_(GameBoyCore* core);

    // LD L L
    void ld_l_l(GameBoyCore* core);

    // LD L H
    void ld_l_h(GameBoyCore* core);

    // LD L E
    void ld_l_e(GameBoyCore* core);

    // LD L D
    void ld_l_d(GameBoyCore* core);

    // LD L A
    void ld_l_a(GameBoyCore* core);

    // LD (HL) L
    void ld__hl__l(GameBoyCore* core);

    // LD (HL) H
    void ld__hl__h(GameBoyCore* core);

    // LD (HL) E
    void ld__hl__e(GameBoyCore* core);

    // LD (HL) D
    void ld__hl__d(GameBoyCore* core);

    // LD (HL) C
    void ld__hl__c(GameBoyCore* core);

    // LD (HL) B
    void ld__hl__b(GameBoyCore* core);

    // LD A C
    void ld_a_c(GameBoyCore* core);

    // LD A B
    void ld_a_b(GameBoyCore* core);

    // LD (HL) A
    void ld__hl__a(GameBoyCore* core);

    // LD A A
    void ld_a_a(GameBoyCore* core);

    // LD A (HL)
    void ld_a__hl_(GameBoyCore* core);

    // LD A L
    void ld_a_l(GameBoyCore* core);

    // LD A H
    void ld_a_h(GameBoyCore* core);

    // LD A E
    void ld_a_e(GameBoyCore* core);

    // LD A D
    void ld_a_d(GameBoyCore* core);

    // RRCA
    void rrca__(GameBoyCore* core);

    // XOR B
    void xor_b_(GameBoyCore* core);

    // XOR C
    void xor_c_(GameBoyCore* core);

    // XOR A
    void xor_a_(GameBoyCore* core);

    // XOR (HL)
    void xor__hl__(GameBoyCore* core);

    // XOR L
    void xor_l_(GameBoyCore* core);

    // XOR H
    void xor_h_(GameBoyCore* core);

    // XOR E
    void xor_e_(GameBoyCore* core);

    // XOR D
    void xor_d_(GameBoyCore* core);

    // XOR d8
    void xor_d8_(GameBoyCore* core);

    // CPL
    void cpl__(GameBoyCore* core);

    // RLCA
    void rlca__(GameBoyCore* core);

    // PUSH BC
    void push_bc_(GameBoyCore* core);

    // PUSH DE
    void push_de_(GameBoyCore* core);

    // PUSH HL
    void push_hl_(GameBoyCore* core);

    // PUSH AF
    void push_af_(GameBoyCore* core);

    // INC D
    void inc_d_(GameBoyCore* core);

    // INC DE
    void inc_de_(GameBoyCore* core);

    // INC E
    void inc_e_(GameBoyCore* core);

    // INC H
    void inc_h_(GameBoyCore* core);

    // INC HL
    void inc_hl_(GameBoyCore* core);

    // INC L
    void inc_l_(GameBoyCore* core);

    // INC (HL)
    void inc__hl__(GameBoyCore* core);

    // INC SP
    void inc_sp_(GameBoyCore* core);

    // INC A
    void inc_a_(GameBoyCore* core);

    // INC BC
    void inc_bc_(GameBoyCore* core);

    // INC B
    void inc_b_(GameBoyCore* core);

    // INC C
    void inc_c_(GameBoyCore* core);


    InstructionFun DecodeInstruction(unsigned long long opcode);
};


#endif //STUDYBOY_INSTRUCTION_H
