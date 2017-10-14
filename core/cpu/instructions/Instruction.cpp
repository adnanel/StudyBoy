//
// Created by adnan on 14/10/2017.
//

#include "Instruction.h"

Instruction::~Instruction() = default;

Instruction::Instruction(long opcode) {

}


std::map<unsigned long long, Instruction*> Instruction::instructionMap{
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
                0x9, nullptr // ADD HL BC
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
                0x5, nullptr // DEC B
        },
        {
                0xb, nullptr // DEC BC
        },
        {
                0xd, nullptr // DEC C
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
                0x0, nullptr // NOP
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
                0x1, nullptr // LD BC d16
        },
        {
                0x2, nullptr // LD (BC) A
        },
        {
                0x4f, nullptr // LD C A
        },
        {
                0x6, nullptr // LD B d8
        },
        {
                0x4e, nullptr // LD C (HL)
        },
        {
                0x4d, nullptr // LD C L
        },
        {
                0x8, nullptr // LD (a16) SP
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
                0xa, nullptr // LD A (BC)
        },
        {
                0x69, nullptr // LD L C
        },
        {
                0xe, nullptr // LD C d8
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
                0xf, nullptr // RRCA
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
                0x7, nullptr // RLCA
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
                0x3, nullptr // INC BC
        },
        {
                0x4, nullptr // INC B
        },
        {
                0xc, nullptr // INC C
        }
};
