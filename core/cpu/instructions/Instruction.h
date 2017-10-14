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


    InstructionFun DecodeInstruction(unsigned long long opcode) {
        static std::map<unsigned long long, InstructionFun> instructionMap{
                {
                        0xc0, nullptr // RET NZ
                },
                {
                        0xc9, nullptr // RET
                },
                {
                        0xc8, nullptr // RET Z
                },
                {
                        0xd0, nullptr // RET NC
                },
                {
                        0xd8, nullptr // RET C
                },
                {
                        0x1f, nullptr // RRA
                },
                {
                        0xce, nullptr // ADC A d8
                },
                {
                        0x89, nullptr // ADC A C
                },
                {
                        0x88, nullptr // ADC A B
                },
                {
                        0x8f, nullptr // ADC A A
                },
                {
                        0x8e, nullptr // ADC A (HL)
                },
                {
                        0x8d, nullptr // ADC A L
                },
                {
                        0x8c, nullptr // ADC A H
                },
                {
                        0x8b, nullptr // ADC A E
                },
                {
                        0x8a, nullptr // ADC A D
                },
                {
                        0x19, nullptr // ADD HL DE
                },
                {
                        0xc6, nullptr // ADD A d8
                },
                {
                        0x29, nullptr // ADD HL HL
                },
                {
                        0xe8, nullptr // ADD SP r8
                },
                {
                        0x39, nullptr // ADD HL SP
                },
                {
                        0x09, nullptr // ADD HL BC
                },
                {
                        0x87, nullptr // ADD A A
                },
                {
                        0x86, nullptr // ADD A (HL)
                },
                {
                        0x85, nullptr // ADD A L
                },
                {
                        0x84, nullptr // ADD A H
                },
                {
                        0x83, nullptr // ADD A E
                },
                {
                        0x82, nullptr // ADD A D
                },
                {
                        0x81, nullptr // ADD A C
                },
                {
                        0x80, nullptr // ADD A B
                },
                {
                        0xc4, nullptr // CALL NZ a16
                },
                {
                        0xd4, nullptr // CALL NC a16
                },
                {
                        0xcd, nullptr // CALL a16
                },
                {
                        0xcc, nullptr // CALL Z a16
                },
                {
                        0xdc, nullptr // CALL C a16
                },
                {
                        0xf3, nullptr // DI
                },
                {
                        0xc2, nullptr // JP NZ a16
                },
                {
                        0xc3, nullptr // JP a16
                },
                {
                        0xd2, nullptr // JP NC a16
                },
                {
                        0xe9, nullptr // JP (HL)
                },
                {
                        0xca, nullptr // JP Z a16
                },
                {
                        0xda, nullptr // JP C a16
                },
                {
                        0x17, nullptr // RLA
                },
                {
                        0x18, nullptr // JR r8
                },
                {
                        0x20, nullptr // JR NZ r8
                },
                {
                        0x28, nullptr // JR Z r8
                },
                {
                        0x30, nullptr // JR NC r8
                },
                {
                        0x38, nullptr // JR C r8
                },
                {
                        0xd9, nullptr // RETI
                },
                {
                        0xe0, nullptr // LDH (a8) A
                },
                {
                        0xf0, nullptr // LDH A (a8)
                },
                {
                        0xde, nullptr // SBC A d8
                },
                {
                        0x98, nullptr // SBC A B
                },
                {
                        0x99, nullptr // SBC A C
                },
                {
                        0x9f, nullptr // SBC A A
                },
                {
                        0x9e, nullptr // SBC A (HL)
                },
                {
                        0x9d, nullptr // SBC A L
                },
                {
                        0x9c, nullptr // SBC A H
                },
                {
                        0x9b, nullptr // SBC A E
                },
                {
                        0x9a, nullptr // SBC A D
                },
                {
                        0x76, nullptr // HALT
                },
                {
                        0xd6, nullptr // SUB d8
                },
                {
                        0x90, nullptr // SUB B
                },
                {
                        0x97, nullptr // SUB A
                },
                {
                        0x96, nullptr // SUB (HL)
                },
                {
                        0x95, nullptr // SUB L
                },
                {
                        0x94, nullptr // SUB H
                },
                {
                        0x93, nullptr // SUB E
                },
                {
                        0x92, nullptr // SUB D
                },
                {
                        0x91, nullptr // SUB C
                },
                {
                        0xb1, nullptr // OR C
                },
                {
                        0xb0, nullptr // OR B
                },
                {
                        0xb7, nullptr // OR A
                },
                {
                        0xb6, nullptr // OR (HL)
                },
                {
                        0xb5, nullptr // OR L
                },
                {
                        0xb4, nullptr // OR H
                },
                {
                        0xb3, nullptr // OR E
                },
                {
                        0xb2, nullptr // OR D
                },
                {
                        0xf6, nullptr // OR d8
                },
                {
                        0x15, nullptr // DEC D
                },
                {
                        0x1d, nullptr // DEC E
                },
                {
                        0x1b, nullptr // DEC DE
                },
                {
                        0x25, nullptr // DEC H
                },
                {
                        0x2d, nullptr // DEC L
                },
                {
                        0x2b, nullptr // DEC HL
                },
                {
                        0x35, nullptr // DEC (HL)
                },
                {
                        0x3b, nullptr // DEC SP
                },
                {
                        0x3d, nullptr // DEC A
                },
                {
                        0x05, nullptr // DEC B
                },
                {
                        0x0b, nullptr // DEC BC
                },
                {
                        0x0d, nullptr // DEC C
                },
                {
                        0xfb, nullptr // EI
                },
                {
                        0x10, nullptr // STOP 0
                },
                {
                        0x27, nullptr // DAA
                },
                {
                        0x3f, nullptr // CCF
                },
                {
                        0xb9, nullptr // CP C
                },
                {
                        0xb8, nullptr // CP B
                },
                {
                        0xba, nullptr // CP D
                },
                {
                        0xbf, nullptr // CP A
                },
                {
                        0xbe, nullptr // CP (HL)
                },
                {
                        0xbd, nullptr // CP L
                },
                {
                        0xbc, nullptr // CP H
                },
                {
                        0xbb, nullptr // CP E
                },
                {
                        0xfe, nullptr // CP d8
                },
                {
                        0x00, nullptr // NOP
                },
                {
                        0xc1, nullptr // POP BC
                },
                {
                        0xd1, nullptr // POP DE
                },
                {
                        0xe1, nullptr // POP HL
                },
                {
                        0xf1, nullptr // POP AF
                },
                {
                        0xc7, nullptr // RST 00H
                },
                {
                        0xd7, nullptr // RST 10H
                },
                {
                        0xe7, nullptr // RST 20H
                },
                {
                        0xcf, nullptr // RST 08H
                },
                {
                        0xf7, nullptr // RST 30H
                },
                {
                        0xdf, nullptr // RST 18H
                },
                {
                        0xef, nullptr // RST 28H
                },
                {
                        0xff, nullptr // RST 38H
                },
                {
                        0xcb, nullptr // PREFIX CB
                },
                {
                        0xa0, nullptr // AND B
                },
                {
                        0xa7, nullptr // AND A
                },
                {
                        0xa6, nullptr // AND (HL)
                },
                {
                        0xa5, nullptr // AND L
                },
                {
                        0xa4, nullptr // AND H
                },
                {
                        0xa3, nullptr // AND E
                },
                {
                        0xa2, nullptr // AND D
                },
                {
                        0xa1, nullptr // AND C
                },
                {
                        0xe6, nullptr // AND d8
                },
                {
                        0x37, nullptr // SCF
                },
                {
                        0x16, nullptr // LD D d8
                },
                {
                        0x12, nullptr // LD (DE) A
                },
                {
                        0x11, nullptr // LD DE d16
                },
                {
                        0x1e, nullptr // LD E d8
                },
                {
                        0x1a, nullptr // LD A (DE)
                },
                {
                        0x21, nullptr // LD HL d16
                },
                {
                        0x26, nullptr // LD H d8
                },
                {
                        0x22, nullptr // LD (HL+) A
                },
                {
                        0x2a, nullptr // LD A (HL+)
                },
                {
                        0xe2, nullptr // LD (C) A
                },
                {
                        0x2e, nullptr // LD L d8
                },
                {
                        0x32, nullptr // LD (HL-) A
                },
                {
                        0x31, nullptr // LD SP d16
                },
                {
                        0x36, nullptr // LD (HL) d8
                },
                {
                        0x3a, nullptr // LD A (HL-)
                },
                {
                        0xf2, nullptr // LD A (C)
                },
                {
                        0xf9, nullptr // LD SP HL
                },
                {
                        0x3e, nullptr // LD A d8
                },
                {
                        0xf8, nullptr // LD HL SP+r8
                },
                {
                        0x43, nullptr // LD B E
                },
                {
                        0x42, nullptr // LD B D
                },
                {
                        0x41, nullptr // LD B C
                },
                {
                        0x40, nullptr // LD B B
                },
                {
                        0x49, nullptr // LD C C
                },
                {
                        0x48, nullptr // LD C B
                },
                {
                        0x47, nullptr // LD B A
                },
                {
                        0x46, nullptr // LD B (HL)
                },
                {
                        0x45, nullptr // LD B L
                },
                {
                        0x44, nullptr // LD B H
                },
                {
                        0x4c, nullptr // LD C H
                },
                {
                        0x4b, nullptr // LD C E
                },
                {
                        0x4a, nullptr // LD C D
                },
                {
                        0x01, nullptr // LD BC d16
                },
                {
                        0x02, nullptr // LD (BC) A
                },
                {
                        0x4f, nullptr // LD C A
                },
                {
                        0x06, nullptr // LD B d8
                },
                {
                        0x4e, nullptr // LD C (HL)
                },
                {
                        0x4d, nullptr // LD C L
                },
                {
                        0x08, nullptr // LD (a16) SP
                },
                {
                        0x54, nullptr // LD D H
                },
                {
                        0x53, nullptr // LD D E
                },
                {
                        0x52, nullptr // LD D D
                },
                {
                        0x51, nullptr // LD D C
                },
                {
                        0xea, nullptr // LD (a16) A
                },
                {
                        0x50, nullptr // LD D B
                },
                {
                        0x59, nullptr // LD E C
                },
                {
                        0x58, nullptr // LD E B
                },
                {
                        0x57, nullptr // LD D A
                },
                {
                        0x56, nullptr // LD D (HL)
                },
                {
                        0x55, nullptr // LD D L
                },
                {
                        0x5d, nullptr // LD E L
                },
                {
                        0x5c, nullptr // LD E H
                },
                {
                        0x5b, nullptr // LD E E
                },
                {
                        0x5a, nullptr // LD E D
                },
                {
                        0x5f, nullptr // LD E A
                },
                {
                        0x5e, nullptr // LD E (HL)
                },
                {
                        0x65, nullptr // LD H L
                },
                {
                        0x64, nullptr // LD H H
                },
                {
                        0x63, nullptr // LD H E
                },
                {
                        0x62, nullptr // LD H D
                },
                {
                        0x61, nullptr // LD H C
                },
                {
                        0xfa, nullptr // LD A (a16)
                },
                {
                        0x60, nullptr // LD H B
                },
                {
                        0x0a, nullptr // LD A (BC)
                },
                {
                        0x69, nullptr // LD L C
                },
                {
                        0x0e, nullptr // LD C d8
                },
                {
                        0x68, nullptr // LD L B
                },
                {
                        0x67, nullptr // LD H A
                },
                {
                        0x66, nullptr // LD H (HL)
                },
                {
                        0x6e, nullptr // LD L (HL)
                },
                {
                        0x6d, nullptr // LD L L
                },
                {
                        0x6c, nullptr // LD L H
                },
                {
                        0x6b, nullptr // LD L E
                },
                {
                        0x6a, nullptr // LD L D
                },
                {
                        0x6f, nullptr // LD L A
                },
                {
                        0x75, nullptr // LD (HL) L
                },
                {
                        0x74, nullptr // LD (HL) H
                },
                {
                        0x73, nullptr // LD (HL) E
                },
                {
                        0x72, nullptr // LD (HL) D
                },
                {
                        0x71, nullptr // LD (HL) C
                },
                {
                        0x70, nullptr // LD (HL) B
                },
                {
                        0x79, nullptr // LD A C
                },
                {
                        0x78, nullptr // LD A B
                },
                {
                        0x77, nullptr // LD (HL) A
                },
                {
                        0x7f, nullptr // LD A A
                },
                {
                        0x7e, nullptr // LD A (HL)
                },
                {
                        0x7d, nullptr // LD A L
                },
                {
                        0x7c, nullptr // LD A H
                },
                {
                        0x7b, nullptr // LD A E
                },
                {
                        0x7a, nullptr // LD A D
                },
                {
                        0x0f, nullptr // RRCA
                },
                {
                        0xa8, nullptr // XOR B
                },
                {
                        0xa9, nullptr // XOR C
                },
                {
                        0xaf, nullptr // XOR A
                },
                {
                        0xae, nullptr // XOR (HL)
                },
                {
                        0xad, nullptr // XOR L
                },
                {
                        0xac, nullptr // XOR H
                },
                {
                        0xab, nullptr // XOR E
                },
                {
                        0xaa, nullptr // XOR D
                },
                {
                        0xee, nullptr // XOR d8
                },
                {
                        0x2f, nullptr // CPL
                },
                {
                        0x07, nullptr // RLCA
                },
                {
                        0xc5, nullptr // PUSH BC
                },
                {
                        0xd5, nullptr // PUSH DE
                },
                {
                        0xe5, nullptr // PUSH HL
                },
                {
                        0xf5, nullptr // PUSH AF
                },
                {
                        0x14, nullptr // INC D
                },
                {
                        0x13, nullptr // INC DE
                },
                {
                        0x1c, nullptr // INC E
                },
                {
                        0x24, nullptr // INC H
                },
                {
                        0x23, nullptr // INC HL
                },
                {
                        0x2c, nullptr // INC L
                },
                {
                        0x34, nullptr // INC (HL)
                },
                {
                        0x33, nullptr // INC SP
                },
                {
                        0x3c, nullptr // INC A
                },
                {
                        0x03, nullptr // INC BC
                },
                {
                        0x04, nullptr // INC B
                },
                {
                        0x0c, nullptr // INC C
                }
        };


        auto it = instructionMap.find(opcode);
        if ( it == instructionMap.end() ) {
            throw std::invalid_argument("Invalid opcode!");
        }
        return it->second;
    }
};


#endif //STUDYBOY_INSTRUCTION_H
