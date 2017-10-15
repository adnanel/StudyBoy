//
// Created by adnan on 14/10/2017.
//

#include "Instruction.h"

template<unsigned int N>
void update_flags_adc(const Register<N>& oldVal,
                      const Register<N>& newVal,
                      GameBoyCore* core,
                      unsigned long long) {
    core->SetFlags(!newVal.any(), false, false, false);
}

template<unsigned int N>
void update_flags_add(const Register<N>& oldVal,
                      const Register<N>& newVal,
                      GameBoyCore* core,
                      unsigned long long) {
    core->SetFlags(!newVal.any(), false, false, false);
}



// RET NZ
void Instruction::ret_nz_(GameBoyCore* core, unsigned long long opcode) {
    if ( core->getCpu()->getFlagRegister()->getZ() )
        return;

    ret__(core, opcode);
}

// RET
void Instruction::ret__(GameBoyCore* core, unsigned long long opcode) {
    // pop 2 bytes from stack and jump to that address
    auto sp = core->getCpu()->getCpuRegisters()->getSP();
    // todo
}

// RET Z
void Instruction::ret_z_(GameBoyCore* core, unsigned long long opcode) {
    if ( !core->getCpu()->getFlagRegister()->getZ() )
        return;

    ret__(core, opcode);
}

// RET NC
void Instruction::ret_nc_(GameBoyCore* core, unsigned long long opcode) {
    if ( core->getCpu()->getFlagRegister()->getN() )
        return;

    ret__(core, opcode);
}

// RET C
void Instruction::ret_c_(GameBoyCore* core, unsigned long long opcode) {
    if ( !core->getCpu()->getFlagRegister()->getC() )
        return;

    ret__(core, opcode);
}

// RRA
void Instruction::rra__(GameBoyCore* core, unsigned long long) {
    auto reg = core->getCpu()->getCpuRegisters()->getA();
    bool old = reg[0];
    reg = (reg >> 1) | (old << 7) ;

    core->getCpu()->getCpuRegisters()->setA(reg);

    core->SetFlags(!reg.any(), false, false, old);
}


// ADC A (HL)
void Instruction::adc_a__hl_(GameBoyCore* core, unsigned long long opcode) {
    // A += MEMORY[ HL ]
    auto cReg = core->getCpu()->getCpuRegisters()->getA();
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    auto oldVal = cReg;
    cReg += core->getWorkRam()->ReadData<8>(hl.to_ullong());
    cReg += static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    core->getCpu()->getCpuRegisters()->setA(cReg);

    update_flags_adc(oldVal, cReg, core, opcode);
}

// ADC A L
void Instruction::adc_a_l(GameBoyCore* core, unsigned long long opcode) {
    auto cReg = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = cReg;

    cReg += core->getCpu()->getCpuRegisters()->getL();
    cReg += static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    update_flags_adc(oldVal, cReg, core, opcode);
}

// ADC A H
void Instruction::adc_a_h(GameBoyCore* core, unsigned long long opcode) {
    auto cReg = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = cReg;

    cReg += core->getCpu()->getCpuRegisters()->getH();
    cReg += static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    core->getCpu()->getCpuRegisters()->setA(cReg);

    update_flags_adc(oldVal, cReg, core, opcode);
}

// ADC A E
void Instruction::adc_a_e(GameBoyCore* core, unsigned long long opcode) {
    auto cReg = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = cReg;

    cReg += core->getCpu()->getCpuRegisters()->getE();
    cReg += static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    core->getCpu()->getCpuRegisters()->setA(cReg);

    update_flags_adc(oldVal, cReg, core, opcode);
}

// ADC A D
void Instruction::adc_a_d(GameBoyCore* core, unsigned long long opcode) {
    auto cReg = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = cReg;

    cReg += core->getCpu()->getCpuRegisters()->getD();
    cReg += static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    core->getCpu()->getCpuRegisters()->setA(cReg);

    update_flags_adc(oldVal, cReg, core, opcode);
}


// ADD A d8
void Instruction::add_a_d8(GameBoyCore* core, unsigned long long) {
    bool z;
    bool h;
    bool c;

    auto reg = core->getCpu()->getCpuRegisters()->getA();

    // reg +=
    //core->getCpu()->getCpuRegisters()->A +=
// todo
    core->SetFlags(z, false, h, c);
}

// ADD A C
void Instruction::add_a_c(GameBoyCore* core, unsigned long long opcode) {
    auto cReg = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = cReg;

    cReg += core->getCpu()->getCpuRegisters()->getC();

    core->getCpu()->getCpuRegisters()->setA(cReg);

    update_flags_add(oldVal, cReg, core, opcode);
}

// ADD A B
void Instruction::add_a_b(GameBoyCore* core, unsigned long long opcode) {
    auto cReg = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = cReg;

    cReg += core->getCpu()->getCpuRegisters()->getB();

    core->getCpu()->getCpuRegisters()->setA(cReg);

    update_flags_add(oldVal, cReg, core, opcode);
}

// ADD A A
void Instruction::add_a_a(GameBoyCore* core, unsigned long long opcode) {
    auto cReg = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = cReg;

    cReg += cReg;

    core->getCpu()->getCpuRegisters()->setA(cReg);

    update_flags_add(oldVal, cReg, core, opcode);
}

// ADD HL DE
void Instruction::add_hl_de(GameBoyCore* core, unsigned long long opcode) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();
    auto de = core->getCpu()->getCpuRegisters()->getDE();
    auto oldVal = hl;

    hl += de;

    core->getCpu()->getCpuRegisters()->setHL(hl);

    update_flags_add(oldVal, hl, core, opcode);
}

// ADC A d8
void Instruction::adc_a_d8(GameBoyCore* core, unsigned long long) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, false, h, c);
}

// ADD HL HL
void Instruction::add_hl_hl(GameBoyCore* core, unsigned long long opcode) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();
    auto oldVal = hl;
    hl += hl;

    core->getCpu()->getCpuRegisters()->setHL(hl);

    update_flags_add(oldVal, hl, core, opcode);
}

// ADD SP r8
void Instruction::add_sp_r8(GameBoyCore* core, unsigned long long opcode) {
    bool h;
    bool c;

    auto sp = core->getCpu()->getCpuRegisters()->getSP();

// todo
    core->SetFlags(false, false, h, c);
}

// ADD HL SP
void Instruction::add_hl_sp(GameBoyCore* core, unsigned long long opcode) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();
    auto sp = core->getCpu()->getCpuRegisters()->getSP();
    auto oldVal = hl;

    hl += sp;

    core->getCpu()->getCpuRegisters()->setHL(hl);

    update_flags_add(oldVal, hl, core, opcode);
}

// ADD HL BC
void Instruction::add_hl_bc(GameBoyCore* core, unsigned long long opcode) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();
    auto bc = core->getCpu()->getCpuRegisters()->getBC();
    auto oldVal = hl;

    hl += bc;

    core->getCpu()->getCpuRegisters()->setHL(hl);

    update_flags_add(oldVal, hl, core, opcode);
}

// ADC A A
void Instruction::adc_a_a(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = a;

    a += a;
    a += static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    core->getCpu()->getCpuRegisters()->setA(a);

    update_flags_adc(oldVal, a, core, opcode);
}

// ADD A (HL)
void Instruction::add_a__hl_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, false, h, c);
}

// ADD A L
void Instruction::add_a_l(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, false, h, c);
}

// ADD A H
void Instruction::add_a_h(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, false, h, c);
}

// ADD A E
void Instruction::add_a_e(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, false, h, c);
}

// ADD A D
void Instruction::add_a_d(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, false, h, c);
}

// ADC A C
void Instruction::adc_a_c(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, false, h, c);
}

// ADC A B
void Instruction::adc_a_b(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, false, h, c);
}

// CALL NZ a16
void Instruction::call_nz_a16(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// CALL NC a16
void Instruction::call_nc_a16(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// CALL a16
void Instruction::call_a16_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// CALL Z a16
void Instruction::call_z_a16(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// CALL C a16
void Instruction::call_c_a16(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// DI
void Instruction::di__(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JP NZ a16
void Instruction::jp_nz_a16(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JP a16
void Instruction::jp_a16_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JP NC a16
void Instruction::jp_nc_a16(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JP (HL)
void Instruction::jp__hl__(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JP Z a16
void Instruction::jp_z_a16(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JP C a16
void Instruction::jp_c_a16(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// RLA
void Instruction::rla__(GameBoyCore* core, unsigned long long opcode) {
    bool c;

// todo
    core->SetFlags(false, false, false, c);
}

// JR r8
void Instruction::jr_r8_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JR NZ r8
void Instruction::jr_nz_r8(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JR Z r8
void Instruction::jr_z_r8(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JR NC r8
void Instruction::jr_nc_r8(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JR C r8
void Instruction::jr_c_r8(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// RETI
void Instruction::reti__(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LDH (a8) A
void Instruction::ldh__a8__a(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LDH A (a8)
void Instruction::ldh_a__a8_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// SBC A d8
void Instruction::sbc_a_d8(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SBC A B
void Instruction::sbc_a_b(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SBC A C
void Instruction::sbc_a_c(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SBC A A
void Instruction::sbc_a_a(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SBC A (HL)
void Instruction::sbc_a__hl_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SBC A L
void Instruction::sbc_a_l(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SBC A H
void Instruction::sbc_a_h(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SBC A E
void Instruction::sbc_a_e(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SBC A D
void Instruction::sbc_a_d(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// HALT
void Instruction::halt__(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// SUB d8
void Instruction::sub_d8_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SUB B
void Instruction::sub_b_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SUB A
void Instruction::sub_a_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SUB (HL)
void Instruction::sub__hl__(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SUB L
void Instruction::sub_l_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SUB H
void Instruction::sub_h_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SUB E
void Instruction::sub_e_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SUB D
void Instruction::sub_d_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// SUB C
void Instruction::sub_c_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// OR C
void Instruction::or_c_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// OR B
void Instruction::or_b_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// OR A
void Instruction::or_a_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// OR (HL)
void Instruction::or__hl__(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// OR L
void Instruction::or_l_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// OR H
void Instruction::or_h_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// OR E
void Instruction::or_e_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// OR D
void Instruction::or_d_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// OR d8
void Instruction::or_d8_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// DEC D
void Instruction::dec_d_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, true, h, core->getCpu()->getFlagRegister()->getZ());
}

// DEC E
void Instruction::dec_e_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, true, h, core->getCpu()->getFlagRegister()->getZ());
}

// DEC DE
void Instruction::dec_de_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// DEC H
void Instruction::dec_h_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, true, h, core->getCpu()->getFlagRegister()->getZ());
}

// DEC L
void Instruction::dec_l_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, true, h, core->getCpu()->getFlagRegister()->getZ());
}

// DEC HL
void Instruction::dec_hl_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// DEC (HL)
void Instruction::dec__hl__(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, true, h, core->getCpu()->getFlagRegister()->getZ());
}

// DEC SP
void Instruction::dec_sp_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// DEC A
void Instruction::dec_a_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, true, h, core->getCpu()->getFlagRegister()->getZ());
}

// DEC B
void Instruction::dec_b_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, true, h, core->getCpu()->getFlagRegister()->getZ());
}

// DEC BC
void Instruction::dec_bc_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// DEC C
void Instruction::dec_c_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, true, h, core->getCpu()->getFlagRegister()->getZ());
}

// EI
void Instruction::ei__(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// STOP 0
void Instruction::stop_0_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// DAA
void Instruction::daa__(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool c;

// todo
    core->SetFlags(z, core->getCpu()->getFlagRegister()->getH(), false, c);
}

// CCF
void Instruction::ccf__(GameBoyCore* core, unsigned long long opcode) {
    bool c;

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), false, false, c);
}

// CP C
void Instruction::cp_c_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// CP B
void Instruction::cp_b_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// CP D
void Instruction::cp_d_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// CP A
void Instruction::cp_a_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// CP (HL)
void Instruction::cp__hl__(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// CP L
void Instruction::cp_l_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// CP H
void Instruction::cp_h_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// CP E
void Instruction::cp_e_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// CP d8
void Instruction::cp_d8_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;
    bool c;

// todo
    core->SetFlags(z, true, h, c);
}

// NOP
void Instruction::nop__(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// POP BC
void Instruction::pop_bc_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// POP DE
void Instruction::pop_de_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// POP HL
void Instruction::pop_hl_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// POP AF
void Instruction::pop_af_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool n;
    bool h;
    bool c;

// todo
    core->SetFlags(z, n, h, c);
}

// RST 00H
void Instruction::rst_00h_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// RST 10H
void Instruction::rst_10h_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// RST 20H
void Instruction::rst_20h_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// RST 08H
void Instruction::rst_08h_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// RST 30H
void Instruction::rst_30h_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// RST 18H
void Instruction::rst_18h_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// RST 28H
void Instruction::rst_28h_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// RST 38H
void Instruction::rst_38h_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// PREFIX CB
void Instruction::prefix_cb_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// AND B
void Instruction::and_b_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, true, false);
}

// AND A
void Instruction::and_a_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, true, false);
}

// AND (HL)
void Instruction::and__hl__(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, true, false);
}

// AND L
void Instruction::and_l_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, true, false);
}

// AND H
void Instruction::and_h_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, true, false);
}

// AND E
void Instruction::and_e_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, true, false);
}

// AND D
void Instruction::and_d_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, true, false);
}

// AND C
void Instruction::and_c_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, true, false);
}

// AND d8
void Instruction::and_d8_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, true, false);
}

// SCF
void Instruction::scf__(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), false, false, true);
}

// LD D d8
void Instruction::ld_d_d8(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD (DE) A
void Instruction::ld__de__a(GameBoyCore* core, unsigned long long) {
    auto de = core->getCpu()->getCpuRegisters()->getDE();
    auto a = core->getCpu()->getCpuRegisters()->getA();

    core->getWorkRam()->WriteData(de.to_ullong(), a);
}

// LD DE d16
void Instruction::ld_de_d16(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD E d8
void Instruction::ld_e_d8(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD A (DE)
void Instruction::ld_a__de_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD HL d16
void Instruction::ld_hl_d16(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD H d8
void Instruction::ld_h_d8(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD (HL+) A
void Instruction::ld__hlplus__a(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD A (HL+)
void Instruction::ld_a__hlplus_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD (C) A
void Instruction::ld__c__a(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD L d8
void Instruction::ld_l_d8(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD (HL-) A
void Instruction::ld__hlminus__a(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD SP d16
void Instruction::ld_sp_d16(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD (HL) d8
void Instruction::ld__hl__d8(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD A (HL-)
void Instruction::ld_a__hlminus_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD A (C)
void Instruction::ld_a__c_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD SP HL
void Instruction::ld_sp_hl(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD A d8
void Instruction::ld_a_d8(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD HL SP+r8
void Instruction::ld_hl_spplusr8(GameBoyCore* core, unsigned long long opcode) {
    bool h;
    bool c;

// todo
    core->SetFlags(false, false, h, c);
}

// LD B E
void Instruction::ld_b_e(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD B D
void Instruction::ld_b_d(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD B C
void Instruction::ld_b_c(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD B B
void Instruction::ld_b_b(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD C C
void Instruction::ld_c_c(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD C B
void Instruction::ld_c_b(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD B A
void Instruction::ld_b_a(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();

    core->getCpu()->getCpuRegisters()->setB(a);
}

// LD B (HL)
void Instruction::ld_b__hl_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD B L
void Instruction::ld_b_l(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD B H
void Instruction::ld_b_h(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD C H
void Instruction::ld_c_h(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD C E
void Instruction::ld_c_e(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD C D
void Instruction::ld_c_d(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD BC d16
void Instruction::ld_bc_d16(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD (BC) A
void Instruction::ld__bc__a(GameBoyCore* core, unsigned long long opcode) {
    auto bc = core->getCpu()->getCpuRegisters()->getBC();
    auto a  = core->getCpu()->getCpuRegisters()->getA();

    core->getWorkRam()->WriteData(bc.to_ullong(), a);
}

// LD C A
void Instruction::ld_c_a(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();

    core->getCpu()->getCpuRegisters()->setC(a);
}

// LD B d8
void Instruction::ld_b_d8(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD C (HL)
void Instruction::ld_c__hl_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD C L
void Instruction::ld_c_l(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD (a16) SP
void Instruction::ld__a16__sp(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD D H
void Instruction::ld_d_h(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD D E
void Instruction::ld_d_e(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD D D
void Instruction::ld_d_d(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD D C
void Instruction::ld_d_c(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD (a16) A
void Instruction::ld__a16__a(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD D B
void Instruction::ld_d_b(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD E C
void Instruction::ld_e_c(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD E B
void Instruction::ld_e_b(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD D A
void Instruction::ld_d_a(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    core->getCpu()->getCpuRegisters()->setD(a);
}

// LD D (HL)
void Instruction::ld_d__hl_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD D L
void Instruction::ld_d_l(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD E L
void Instruction::ld_e_l(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD E H
void Instruction::ld_e_h(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD E E
void Instruction::ld_e_e(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD E D
void Instruction::ld_e_d(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD E A
void Instruction::ld_e_a(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    core->getCpu()->getCpuRegisters()->setE(a);
}

// LD E (HL)
void Instruction::ld_e__hl_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD H L
void Instruction::ld_h_l(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD H H
void Instruction::ld_h_h(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD H E
void Instruction::ld_h_e(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD H D
void Instruction::ld_h_d(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD H C
void Instruction::ld_h_c(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD A (a16)
void Instruction::ld_a__a16_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD H B
void Instruction::ld_h_b(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD A (BC)
void Instruction::ld_a__bc_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD L C
void Instruction::ld_l_c(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD C d8
void Instruction::ld_c_d8(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD L B
void Instruction::ld_l_b(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD H A
void Instruction::ld_h_a(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    core->getCpu()->getCpuRegisters()->setH(a);
}

// LD H (HL)
void Instruction::ld_h__hl_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD L (HL)
void Instruction::ld_l__hl_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD L L
void Instruction::ld_l_l(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD L H
void Instruction::ld_l_h(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD L E
void Instruction::ld_l_e(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD L D
void Instruction::ld_l_d(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD L A
void Instruction::ld_l_a(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    core->getCpu()->getCpuRegisters()->setL(a);
}

// LD (HL) L
void Instruction::ld__hl__l(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD (HL) H
void Instruction::ld__hl__h(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD (HL) E
void Instruction::ld__hl__e(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD (HL) D
void Instruction::ld__hl__d(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD (HL) C
void Instruction::ld__hl__c(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD (HL) B
void Instruction::ld__hl__b(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD A C
void Instruction::ld_a_c(GameBoyCore* core, unsigned long long opcode) {
    auto c = core->getCpu()->getCpuRegisters()->getC();
    core->getCpu()->getCpuRegisters()->setA(c);
}

// LD A B
void Instruction::ld_a_b(GameBoyCore* core, unsigned long long) {
    auto b = core->getCpu()->getCpuRegisters()->getB();

    core->getCpu()->getCpuRegisters()->setA(b);
}

// LD (HL) A
void Instruction::ld__hl__a(GameBoyCore* core, unsigned long long opcode) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();
    auto a  = core->getCpu()->getCpuRegisters()->getA();

    core->getWorkRam()->WriteData(hl.to_ullong(), a);
}

// LD A A
void Instruction::ld_a_a(GameBoyCore* core, unsigned long long opcode) {
    auto regA = core->getCpu()->getCpuRegisters()->getA();

    core->getCpu()->getCpuRegisters()->setA(regA);
}

// LD A (HL)
void Instruction::ld_a__hl_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD A L
void Instruction::ld_a_l(GameBoyCore* core, unsigned long long opcode) {
    auto l = core->getCpu()->getCpuRegisters()->getL();
    core->getCpu()->getCpuRegisters()->setA(l);
}

// LD A H
void Instruction::ld_a_h(GameBoyCore* core, unsigned long long opcode) {
    auto h = core->getCpu()->getCpuRegisters()->getH();
    core->getCpu()->getCpuRegisters()->setA(h);
}

// LD A E
void Instruction::ld_a_e(GameBoyCore* core, unsigned long long opcode) {
    auto e = core->getCpu()->getCpuRegisters()->getE();
    core->getCpu()->getCpuRegisters()->setA(e);
}

// LD A D
void Instruction::ld_a_d(GameBoyCore* core, unsigned long long opcode) {
    auto d = core->getCpu()->getCpuRegisters()->getD();
    core->getCpu()->getCpuRegisters()->setA(d);
}

// RRCA
void Instruction::rrca__(GameBoyCore* core, unsigned long long opcode) {
    bool c;

// todo
    core->SetFlags(false, false, false, c);
}

// XOR B
void Instruction::xor_b_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// XOR C
void Instruction::xor_c_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// XOR A
void Instruction::xor_a_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// XOR (HL)
void Instruction::xor__hl__(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// XOR L
void Instruction::xor_l_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// XOR H
void Instruction::xor_h_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// XOR E
void Instruction::xor_e_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// XOR D
void Instruction::xor_d_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// XOR d8
void Instruction::xor_d8_(GameBoyCore* core, unsigned long long opcode) {
    bool z;

// todo
    core->SetFlags(z, false, false, false);
}

// CPL
void Instruction::cpl__(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), true, true, core->getCpu()->getFlagRegister()->getZ());
}

// RLCA
void Instruction::rlca__(GameBoyCore* core, unsigned long long opcode) {
    bool c;

// todo
    core->SetFlags(false, false, false, c);
}

// PUSH BC
void Instruction::push_bc_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// PUSH DE
void Instruction::push_de_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// PUSH HL
void Instruction::push_hl_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// PUSH AF
void Instruction::push_af_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// INC D
void Instruction::inc_d_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, false, h, core->getCpu()->getFlagRegister()->getZ());
}

// INC DE
void Instruction::inc_de_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// INC E
void Instruction::inc_e_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, false, h, core->getCpu()->getFlagRegister()->getZ());
}

// INC H
void Instruction::inc_h_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, false, h, core->getCpu()->getFlagRegister()->getZ());
}

// INC HL
void Instruction::inc_hl_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// INC L
void Instruction::inc_l_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, false, h, core->getCpu()->getFlagRegister()->getZ());
}

// INC (HL)
void Instruction::inc__hl__(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, false, h, core->getCpu()->getFlagRegister()->getZ());
}

// INC SP
void Instruction::inc_sp_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// INC A
void Instruction::inc_a_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, false, h, core->getCpu()->getFlagRegister()->getZ());
}

// INC BC
void Instruction::inc_bc_(GameBoyCore* core, unsigned long long opcode) {

// todo
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// INC B
void Instruction::inc_b_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, false, h, core->getCpu()->getFlagRegister()->getZ());
}

// INC C
void Instruction::inc_c_(GameBoyCore* core, unsigned long long opcode) {
    bool z;
    bool h;

// todo
    core->SetFlags(z, false, h, core->getCpu()->getFlagRegister()->getZ());
}





InstructionFun Instruction::DecodeInstruction(unsigned long long opcode) {
    static std::map<unsigned long long, InstructionFun> instructionMap{
            {
                    0xc0, ret_nz_
            },
            {
                    0xc9, ret__
            },
            {
                    0xc8, ret_z_
            },
            {
                    0xd0, ret_nc_
            },
            {
                    0xd8, ret_c_
            },
            {
                    0x1f, rra__
            },
            {
                    0xce, adc_a_d8
            },
            {
                    0x89, adc_a_c
            },
            {
                    0x88, adc_a_b
            },
            {
                    0x8f, adc_a_a
            },
            {
                    0x8e, adc_a__hl_
            },
            {
                    0x8d, adc_a_l
            },
            {
                    0x8c, adc_a_h
            },
            {
                    0x8b, adc_a_e
            },
            {
                    0x8a, adc_a_d
            },
            {
                    0x19, add_hl_de
            },
            {
                    0xc6, add_a_d8
            },
            {
                    0x29, add_hl_hl
            },
            {
                    0xe8, add_sp_r8
            },
            {
                    0x39, add_hl_sp
            },
            {
                    0x09, add_hl_bc
            },
            {
                    0x87, add_a_a
            },
            {
                    0x86, add_a__hl_
            },
            {
                    0x85, add_a_l
            },
            {
                    0x84, add_a_h
            },
            {
                    0x83, add_a_e
            },
            {
                    0x82, add_a_d
            },
            {
                    0x81, add_a_c
            },
            {
                    0x80, add_a_b
            },
            {
                    0xc4, call_nz_a16
            },
            {
                    0xd4, call_nc_a16
            },
            {
                    0xcd, call_a16_
            },
            {
                    0xcc, call_z_a16
            },
            {
                    0xdc, call_c_a16
            },
            {
                    0xf3, di__
            },
            {
                    0xc2, jp_nz_a16
            },
            {
                    0xc3, jp_a16_
            },
            {
                    0xd2, jp_nc_a16
            },
            {
                    0xe9, jp__hl__
            },
            {
                    0xca, jp_z_a16
            },
            {
                    0xda, jp_c_a16
            },
            {
                    0x17, rla__
            },
            {
                    0x18, jr_r8_
            },
            {
                    0x20, jr_nz_r8
            },
            {
                    0x28, jr_z_r8
            },
            {
                    0x30, jr_nc_r8
            },
            {
                    0x38, jr_c_r8
            },
            {
                    0xd9, reti__
            },
            {
                    0xe0, ldh__a8__a
            },
            {
                    0xf0, ldh_a__a8_
            },
            {
                    0xde, sbc_a_d8
            },
            {
                    0x98, sbc_a_b
            },
            {
                    0x99, sbc_a_c
            },
            {
                    0x9f, sbc_a_a
            },
            {
                    0x9e, sbc_a__hl_
            },
            {
                    0x9d, sbc_a_l
            },
            {
                    0x9c, sbc_a_h
            },
            {
                    0x9b, sbc_a_e
            },
            {
                    0x9a, sbc_a_d
            },
            {
                    0x76, halt__
            },
            {
                    0xd6, sub_d8_
            },
            {
                    0x90, sub_b_
            },
            {
                    0x97, sub_a_
            },
            {
                    0x96, sub__hl__
            },
            {
                    0x95, sub_l_
            },
            {
                    0x94, sub_h_
            },
            {
                    0x93, sub_e_
            },
            {
                    0x92, sub_d_
            },
            {
                    0x91, sub_c_
            },
            {
                    0xb1, or_c_
            },
            {
                    0xb0, or_b_
            },
            {
                    0xb7, or_a_
            },
            {
                    0xb6, or__hl__
            },
            {
                    0xb5, or_l_
            },
            {
                    0xb4, or_h_
            },
            {
                    0xb3, or_e_
            },
            {
                    0xb2, or_d_
            },
            {
                    0xf6, or_d8_
            },
            {
                    0x15, dec_d_
            },
            {
                    0x1d, dec_e_
            },
            {
                    0x1b, dec_de_
            },
            {
                    0x25, dec_h_
            },
            {
                    0x2d, dec_l_
            },
            {
                    0x2b, dec_hl_
            },
            {
                    0x35, dec__hl__
            },
            {
                    0x3b, dec_sp_
            },
            {
                    0x3d, dec_a_
            },
            {
                    0x05, dec_b_
            },
            {
                    0x0b, dec_bc_
            },
            {
                    0x0d, dec_c_
            },
            {
                    0xfb, ei__
            },
            {
                    0x10, stop_0_
            },
            {
                    0x27, daa__
            },
            {
                    0x3f, ccf__
            },
            {
                    0xb9, cp_c_
            },
            {
                    0xb8, cp_b_
            },
            {
                    0xba, cp_d_
            },
            {
                    0xbf, cp_a_
            },
            {
                    0xbe, cp__hl__
            },
            {
                    0xbd, cp_l_
            },
            {
                    0xbc, cp_h_
            },
            {
                    0xbb, cp_e_
            },
            {
                    0xfe, cp_d8_
            },
            {
                    0x00, nop__
            },
            {
                    0xc1, pop_bc_
            },
            {
                    0xd1, pop_de_
            },
            {
                    0xe1, pop_hl_
            },
            {
                    0xf1, pop_af_
            },
            {
                    0xc7, rst_00h_
            },
            {
                    0xd7, rst_10h_
            },
            {
                    0xe7, rst_20h_
            },
            {
                    0xcf, rst_08h_
            },
            {
                    0xf7, rst_30h_
            },
            {
                    0xdf, rst_18h_
            },
            {
                    0xef, rst_28h_
            },
            {
                    0xff, rst_38h_
            },
            {
                    0xcb, prefix_cb_
            },
            {
                    0xa0, and_b_
            },
            {
                    0xa7, and_a_
            },
            {
                    0xa6, and__hl__
            },
            {
                    0xa5, and_l_
            },
            {
                    0xa4, and_h_
            },
            {
                    0xa3, and_e_
            },
            {
                    0xa2, and_d_
            },
            {
                    0xa1, and_c_
            },
            {
                    0xe6, and_d8_
            },
            {
                    0x37, scf__
            },
            {
                    0x16, ld_d_d8
            },
            {
                    0x12, ld__de__a
            },
            {
                    0x11, ld_de_d16
            },
            {
                    0x1e, ld_e_d8
            },
            {
                    0x1a, ld_a__de_
            },
            {
                    0x21, ld_hl_d16
            },
            {
                    0x26, ld_h_d8
            },
            {
                    0x22, ld__hlplus__a
            },
            {
                    0x2a, ld_a__hlplus_
            },
            {
                    0xe2, ld__c__a
            },
            {
                    0x2e, ld_l_d8
            },
            {
                    0x32, ld__hlminus__a
            },
            {
                    0x31, ld_sp_d16
            },
            {
                    0x36, ld__hl__d8
            },
            {
                    0x3a, ld_a__hlminus_
            },
            {
                    0xf2, ld_a__c_
            },
            {
                    0xf9, ld_sp_hl
            },
            {
                    0x3e, ld_a_d8
            },
            {
                    0xf8, ld_hl_spplusr8
            },
            {
                    0x43, ld_b_e
            },
            {
                    0x42, ld_b_d
            },
            {
                    0x41, ld_b_c
            },
            {
                    0x40, ld_b_b
            },
            {
                    0x49, ld_c_c
            },
            {
                    0x48, ld_c_b
            },
            {
                    0x47, ld_b_a
            },
            {
                    0x46, ld_b__hl_
            },
            {
                    0x45, ld_b_l
            },
            {
                    0x44, ld_b_h
            },
            {
                    0x4c, ld_c_h
            },
            {
                    0x4b, ld_c_e
            },
            {
                    0x4a, ld_c_d
            },
            {
                    0x01, ld_bc_d16
            },
            {
                    0x02, ld__bc__a
            },
            {
                    0x4f, ld_c_a
            },
            {
                    0x06, ld_b_d8
            },
            {
                    0x4e, ld_c__hl_
            },
            {
                    0x4d, ld_c_l
            },
            {
                    0x08, ld__a16__sp
            },
            {
                    0x54, ld_d_h
            },
            {
                    0x53, ld_d_e
            },
            {
                    0x52, ld_d_d
            },
            {
                    0x51, ld_d_c
            },
            {
                    0xea, ld__a16__a
            },
            {
                    0x50, ld_d_b
            },
            {
                    0x59, ld_e_c
            },
            {
                    0x58, ld_e_b
            },
            {
                    0x57, ld_d_a
            },
            {
                    0x56, ld_d__hl_
            },
            {
                    0x55, ld_d_l
            },
            {
                    0x5d, ld_e_l
            },
            {
                    0x5c, ld_e_h
            },
            {
                    0x5b, ld_e_e
            },
            {
                    0x5a, ld_e_d
            },
            {
                    0x5f, ld_e_a
            },
            {
                    0x5e, ld_e__hl_
            },
            {
                    0x65, ld_h_l
            },
            {
                    0x64, ld_h_h
            },
            {
                    0x63, ld_h_e
            },
            {
                    0x62, ld_h_d
            },
            {
                    0x61, ld_h_c
            },
            {
                    0xfa, ld_a__a16_
            },
            {
                    0x60, ld_h_b
            },
            {
                    0x0a, ld_a__bc_
            },
            {
                    0x69, ld_l_c
            },
            {
                    0x0e, ld_c_d8
            },
            {
                    0x68, ld_l_b
            },
            {
                    0x67, ld_h_a
            },
            {
                    0x66, ld_h__hl_
            },
            {
                    0x6e, ld_l__hl_
            },
            {
                    0x6d, ld_l_l
            },
            {
                    0x6c, ld_l_h
            },
            {
                    0x6b, ld_l_e
            },
            {
                    0x6a, ld_l_d
            },
            {
                    0x6f, ld_l_a
            },
            {
                    0x75, ld__hl__l
            },
            {
                    0x74, ld__hl__h
            },
            {
                    0x73, ld__hl__e
            },
            {
                    0x72, ld__hl__d
            },
            {
                    0x71, ld__hl__c
            },
            {
                    0x70, ld__hl__b
            },
            {
                    0x79, ld_a_c
            },
            {
                    0x78, ld_a_b
            },
            {
                    0x77, ld__hl__a
            },
            {
                    0x7f, ld_a_a
            },
            {
                    0x7e, ld_a__hl_
            },
            {
                    0x7d, ld_a_l
            },
            {
                    0x7c, ld_a_h
            },
            {
                    0x7b, ld_a_e
            },
            {
                    0x7a, ld_a_d
            },
            {
                    0x0f, rrca__
            },
            {
                    0xa8, xor_b_
            },
            {
                    0xa9, xor_c_
            },
            {
                    0xaf, xor_a_
            },
            {
                    0xae, xor__hl__
            },
            {
                    0xad, xor_l_
            },
            {
                    0xac, xor_h_
            },
            {
                    0xab, xor_e_
            },
            {
                    0xaa, xor_d_
            },
            {
                    0xee, xor_d8_
            },
            {
                    0x2f, cpl__
            },
            {
                    0x07, rlca__
            },
            {
                    0xc5, push_bc_
            },
            {
                    0xd5, push_de_
            },
            {
                    0xe5, push_hl_
            },
            {
                    0xf5, push_af_
            },
            {
                    0x14, inc_d_
            },
            {
                    0x13, inc_de_
            },
            {
                    0x1c, inc_e_
            },
            {
                    0x24, inc_h_
            },
            {
                    0x23, inc_hl_
            },
            {
                    0x2c, inc_l_
            },
            {
                    0x34, inc__hl__
            },
            {
                    0x33, inc_sp_
            },
            {
                    0x3c, inc_a_
            },
            {
                    0x03, inc_bc_
            },
            {
                    0x04, inc_b_
            },
            {
                    0x0c, inc_c_
            }
    };


    auto it = instructionMap.find(opcode);
    if ( it == instructionMap.end() ) {
        throw std::invalid_argument("Invalid opcode!");
    }
    return it->second;
}

