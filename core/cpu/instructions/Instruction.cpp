//
// Created by adnan on 14/10/2017.
//

#include "Instruction.h"

Instruction::~Instruction() = default;

Instruction::Instruction(long opcode) {

}


std::map<std::string, Instruction*> Instruction::instructionMap{
        {
            "11000000", nullptr // RET NZ
        },
        {
            "11001001", nullptr // RET
        },
        {
            "11001000", nullptr // RET Z
        },
        {
            "11010000", nullptr // RET NC
        },
        {
            "11011000", nullptr // RET C
        },
        {
            "00011111", nullptr // RRA
        },
        {
            "11001110", nullptr // ADC A d8
        },
        {
            "10001001", nullptr // ADC A C
        },
        {
            "10001000", nullptr // ADC A B
        },
        {
            "10001111", nullptr // ADC A A
        },
        {
            "10001110", nullptr // ADC A (HL)
        },
        {
            "10001101", nullptr // ADC A L
        },
        {
            "10001100", nullptr // ADC A H
        },
        {
            "10001011", nullptr // ADC A E
        },
        {
            "10001010", nullptr // ADC A D
        },
        {
            "00011001", nullptr // ADD HL DE
        },
        {
            "11000110", nullptr // ADD A d8
        },
        {
            "00101001", nullptr // ADD HL HL
        },
        {
            "11101000", nullptr // ADD SP r8
        },
        {
            "00111001", nullptr // ADD HL SP
        },
        {
            "00001001", nullptr // ADD HL BC
        },
        {
            "10000111", nullptr // ADD A A
        },
        {
            "10000110", nullptr // ADD A (HL)
        },
        {
            "10000101", nullptr // ADD A L
        },
        {
            "10000100", nullptr // ADD A H
        },
        {
            "10000011", nullptr // ADD A E
        },
        {
            "10000010", nullptr // ADD A D
        },
        {
            "10000001", nullptr // ADD A C
        },
        {
            "10000000", nullptr // ADD A B
        },
        {
            "11000100", nullptr // CALL NZ a16
        },
        {
            "11010100", nullptr // CALL NC a16
        },
        {
            "11001101", nullptr // CALL a16
        },
        {
            "11001100", nullptr // CALL Z a16
        },
        {
            "11011100", nullptr // CALL C a16
        },
        {
            "11110011", nullptr // DI
        },
        {
            "11000010", nullptr // JP NZ a16
        },
        {
            "11000011", nullptr // JP a16
        },
        {
            "11010010", nullptr // JP NC a16
        },
        {
            "11101001", nullptr // JP (HL)
        },
        {
            "11001010", nullptr // JP Z a16
        },
        {
            "11011010", nullptr // JP C a16
        },
        {
            "00010111", nullptr // RLA
        },
        {
            "00011000", nullptr // JR r8
        },
        {
            "00100000", nullptr // JR NZ r8
        },
        {
            "00101000", nullptr // JR Z r8
        },
        {
            "00110000", nullptr // JR NC r8
        },
        {
            "00111000", nullptr // JR C r8
        },
        {
            "11011001", nullptr // RETI
        },
        {
            "11100000", nullptr // LDH (a8) A
        },
        {
            "11110000", nullptr // LDH A (a8)
        },
        {
            "11011110", nullptr // SBC A d8
        },
        {
            "10011000", nullptr // SBC A B
        },
        {
            "10011001", nullptr // SBC A C
        },
        {
            "10011111", nullptr // SBC A A
        },
        {
            "10011110", nullptr // SBC A (HL)
        },
        {
            "10011101", nullptr // SBC A L
        },
        {
            "10011100", nullptr // SBC A H
        },
        {
            "10011011", nullptr // SBC A E
        },
        {
            "10011010", nullptr // SBC A D
        },
        {
            "01110110", nullptr // HALT
        },
        {
            "11010110", nullptr // SUB d8
        },
        {
            "10010000", nullptr // SUB B
        },
        {
            "10010111", nullptr // SUB A
        },
        {
            "10010110", nullptr // SUB (HL)
        },
        {
            "10010101", nullptr // SUB L
        },
        {
            "10010100", nullptr // SUB H
        },
        {
            "10010011", nullptr // SUB E
        },
        {
            "10010010", nullptr // SUB D
        },
        {
            "10010001", nullptr // SUB C
        },
        {
            "10110001", nullptr // OR C
        },
        {
            "10110000", nullptr // OR B
        },
        {
            "10110111", nullptr // OR A
        },
        {
            "10110110", nullptr // OR (HL)
        },
        {
            "10110101", nullptr // OR L
        },
        {
            "10110100", nullptr // OR H
        },
        {
            "10110011", nullptr // OR E
        },
        {
            "10110010", nullptr // OR D
        },
        {
            "11110110", nullptr // OR d8
        },
        {
            "00010101", nullptr // DEC D
        },
        {
            "00011101", nullptr // DEC E
        },
        {
            "00011011", nullptr // DEC DE
        },
        {
            "00100101", nullptr // DEC H
        },
        {
            "00101101", nullptr // DEC L
        },
        {
            "00101011", nullptr // DEC HL
        },
        {
            "00110101", nullptr // DEC (HL)
        },
        {
            "00111011", nullptr // DEC SP
        },
        {
            "00111101", nullptr // DEC A
        },
        {
            "00000101", nullptr // DEC B
        },
        {
            "00001011", nullptr // DEC BC
        },
        {
            "00001101", nullptr // DEC C
        },
        {
            "11111011", nullptr // EI
        },
        {
            "00010000", nullptr // STOP 0
        },
        {
            "00100111", nullptr // DAA
        },
        {
            "00111111", nullptr // CCF
        },
        {
            "10111001", nullptr // CP C
        },
        {
            "10111000", nullptr // CP B
        },
        {
            "10111010", nullptr // CP D
        },
        {
            "10111111", nullptr // CP A
        },
        {
            "10111110", nullptr // CP (HL)
        },
        {
            "10111101", nullptr // CP L
        },
        {
            "10111100", nullptr // CP H
        },
        {
            "10111011", nullptr // CP E
        },
        {
            "11111110", nullptr // CP d8
        },
        {
            "00000000", nullptr // NOP
        },
        {
            "11000001", nullptr // POP BC
        },
        {
            "11010001", nullptr // POP DE
        },
        {
            "11100001", nullptr // POP HL
        },
        {
            "11110001", nullptr // POP AF
        },
        {
            "11000111", nullptr // RST 00H
        },
        {
            "11010111", nullptr // RST 10H
        },
        {
            "11100111", nullptr // RST 20H
        },
        {
            "11001111", nullptr // RST 08H
        },
        {
            "11110111", nullptr // RST 30H
        },
        {
            "11011111", nullptr // RST 18H
        },
        {
            "11101111", nullptr // RST 28H
        },
        {
            "11111111", nullptr // RST 38H
        },
        {
            "11001011", nullptr // PREFIX CB
        },
        {
            "10100000", nullptr // AND B
        },
        {
            "10100111", nullptr // AND A
        },
        {
            "10100110", nullptr // AND (HL)
        },
        {
            "10100101", nullptr // AND L
        },
        {
            "10100100", nullptr // AND H
        },
        {
            "10100011", nullptr // AND E
        },
        {
            "10100010", nullptr // AND D
        },
        {
            "10100001", nullptr // AND C
        },
        {
            "11100110", nullptr // AND d8
        },
        {
            "00110111", nullptr // SCF
        },
        {
            "00010110", nullptr // LD D d8
        },
        {
            "00010010", nullptr // LD (DE) A
        },
        {
            "00010001", nullptr // LD DE d16
        },
        {
            "00011110", nullptr // LD E d8
        },
        {
            "00011010", nullptr // LD A (DE)
        },
        {
            "00100001", nullptr // LD HL d16
        },
        {
            "00100110", nullptr // LD H d8
        },
        {
            "00100010", nullptr // LD (HL+) A
        },
        {
            "00101010", nullptr // LD A (HL+)
        },
        {
            "11100010", nullptr // LD (C) A
        },
        {
            "00101110", nullptr // LD L d8
        },
        {
            "00110010", nullptr // LD (HL-) A
        },
        {
            "00110001", nullptr // LD SP d16
        },
        {
            "00110110", nullptr // LD (HL) d8
        },
        {
            "00111010", nullptr // LD A (HL-)
        },
        {
            "11110010", nullptr // LD A (C)
        },
        {
            "11111001", nullptr // LD SP HL
        },
        {
            "00111110", nullptr // LD A d8
        },
        {
            "11111000", nullptr // LD HL SP+r8
        },
        {
            "01000011", nullptr // LD B E
        },
        {
            "01000010", nullptr // LD B D
        },
        {
            "01000001", nullptr // LD B C
        },
        {
            "01000000", nullptr // LD B B
        },
        {
            "01001001", nullptr // LD C C
        },
        {
            "01001000", nullptr // LD C B
        },
        {
            "01000111", nullptr // LD B A
        },
        {
            "01000110", nullptr // LD B (HL)
        },
        {
            "01000101", nullptr // LD B L
        },
        {
            "01000100", nullptr // LD B H
        },
        {
            "01001100", nullptr // LD C H
        },
        {
            "01001011", nullptr // LD C E
        },
        {
            "01001010", nullptr // LD C D
        },
        {
            "00000001", nullptr // LD BC d16
        },
        {
            "00000010", nullptr // LD (BC) A
        },
        {
            "01001111", nullptr // LD C A
        },
        {
            "00000110", nullptr // LD B d8
        },
        {
            "01001110", nullptr // LD C (HL)
        },
        {
            "01001101", nullptr // LD C L
        },
        {
            "00001000", nullptr // LD (a16) SP
        },
        {
            "01010100", nullptr // LD D H
        },
        {
            "01010011", nullptr // LD D E
        },
        {
            "01010010", nullptr // LD D D
        },
        {
            "01010001", nullptr // LD D C
        },
        {
            "11101010", nullptr // LD (a16) A
        },
        {
            "01010000", nullptr // LD D B
        },
        {
            "01011001", nullptr // LD E C
        },
        {
            "01011000", nullptr // LD E B
        },
        {
            "01010111", nullptr // LD D A
        },
        {
            "01010110", nullptr // LD D (HL)
        },
        {
            "01010101", nullptr // LD D L
        },
        {
            "01011101", nullptr // LD E L
        },
        {
            "01011100", nullptr // LD E H
        },
        {
            "01011011", nullptr // LD E E
        },
        {
            "01011010", nullptr // LD E D
        },
        {
            "01011111", nullptr // LD E A
        },
        {
            "01011110", nullptr // LD E (HL)
        },
        {
            "01100101", nullptr // LD H L
        },
        {
            "01100100", nullptr // LD H H
        },
        {
            "01100011", nullptr // LD H E
        },
        {
            "01100010", nullptr // LD H D
        },
        {
            "01100001", nullptr // LD H C
        },
        {
            "11111010", nullptr // LD A (a16)
        },
        {
            "01100000", nullptr // LD H B
        },
        {
            "00001010", nullptr // LD A (BC)
        },
        {
            "01101001", nullptr // LD L C
        },
        {
            "00001110", nullptr // LD C d8
        },
        {
            "01101000", nullptr // LD L B
        },
        {
            "01100111", nullptr // LD H A
        },
        {
            "01100110", nullptr // LD H (HL)
        },
        {
            "01101110", nullptr // LD L (HL)
        },
        {
            "01101101", nullptr // LD L L
        },
        {
            "01101100", nullptr // LD L H
        },
        {
            "01101011", nullptr // LD L E
        },
        {
            "01101010", nullptr // LD L D
        },
        {
            "01101111", nullptr // LD L A
        },
        {
            "01110101", nullptr // LD (HL) L
        },
        {
            "01110100", nullptr // LD (HL) H
        },
        {
            "01110011", nullptr // LD (HL) E
        },
        {
            "01110010", nullptr // LD (HL) D
        },
        {
            "01110001", nullptr // LD (HL) C
        },
        {
            "01110000", nullptr // LD (HL) B
        },
        {
            "01111001", nullptr // LD A C
        },
        {
            "01111000", nullptr // LD A B
        },
        {
            "01110111", nullptr // LD (HL) A
        },
        {
            "01111111", nullptr // LD A A
        },
        {
            "01111110", nullptr // LD A (HL)
        },
        {
            "01111101", nullptr // LD A L
        },
        {
            "01111100", nullptr // LD A H
        },
        {
            "01111011", nullptr // LD A E
        },
        {
            "01111010", nullptr // LD A D
        },
        {
            "00001111", nullptr // RRCA
        },
        {
            "10101000", nullptr // XOR B
        },
        {
            "10101001", nullptr // XOR C
        },
        {
            "10101111", nullptr // XOR A
        },
        {
            "10101110", nullptr // XOR (HL)
        },
        {
            "10101101", nullptr // XOR L
        },
        {
            "10101100", nullptr // XOR H
        },
        {
            "10101011", nullptr // XOR E
        },
        {
            "10101010", nullptr // XOR D
        },
        {
            "11101110", nullptr // XOR d8
        },
        {
            "00101111", nullptr // CPL
        },
        {
            "00000111", nullptr // RLCA
        },
        {
            "11000101", nullptr // PUSH BC
        },
        {
            "11010101", nullptr // PUSH DE
        },
        {
            "11100101", nullptr // PUSH HL
        },
        {
            "11110101", nullptr // PUSH AF
        },
        {
            "00010100", nullptr // INC D
        },
        {
            "00010011", nullptr // INC DE
        },
        {
            "00011100", nullptr // INC E
        },
        {
            "00100100", nullptr // INC H
        },
        {
            "00100011", nullptr // INC HL
        },
        {
            "00101100", nullptr // INC L
        },
        {
            "00110100", nullptr // INC (HL)
        },
        {
            "00110011", nullptr // INC SP
        },
        {
            "00111100", nullptr // INC A
        },
        {
            "00000011", nullptr // INC BC
        },
        {
            "00000100", nullptr // INC B
        },
        {
            "00001100", nullptr // INC C
        }
};
