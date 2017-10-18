//
// Created by adnan on 14/10/2017.
//

#include <cassert>
#include "Instruction.h"
#include <stdexcept>


void update_flags_adc(unsigned long long oldVal,
                      unsigned long long newVal,
                      GameBoyCore* core,
                      unsigned long long opcode) {
    // todo
    core->SetFlags(newVal == 0, false, false, false);
}

void update_flags_adc(const Register<8>& oldVal,
                      const Register<8>& newVal,
                      GameBoyCore* core,
                      unsigned long long opcode) {
    // todo
    update_flags_adc(oldVal.to_ullong(), newVal.to_ullong(), core, opcode);
}

void update_flags_add(unsigned long long oldVal,
                      unsigned long long newVal,
                      GameBoyCore* core,
                      unsigned long long opcode) {
    // todo
    core->SetFlags(newVal == 0, false, false, false);
}

void update_flags_add(const Register<8>& oldVal,
                      const Register<8>& newVal,
                      GameBoyCore* core,
                      unsigned long long opcode) {
    // todo
    update_flags_add(oldVal.to_ullong(), newVal.to_ullong(), core, opcode);
}

void update_flags_inc(unsigned long long oldVal,
                      unsigned long long newVal,
                      GameBoyCore* core,
                      unsigned long long opcode) {
    // todo
    core->SetFlags(newVal == 0, false, false, false);
}

void update_flags_inc(const Register<8>& oldVal,
                      const Register<8>& newVal,
                      GameBoyCore* core,
                      unsigned long long opcode) {
    // todo
    update_flags_inc(oldVal.to_ullong(), newVal.to_ullong(), core, opcode);
}

void update_flags_dec(unsigned long long oldVal,
                      unsigned long long newVal,
                      GameBoyCore* core,
                      unsigned long long) {
    // todo
    core->SetFlags(newVal == 0, false, false, false);
}

void update_flags_dec(const Register<8>& oldVal,
                      const Register<8>& newVal,
                      GameBoyCore* core,
                      unsigned long long opcode) {
    // todo
    update_flags_dec(oldVal.to_ullong(), newVal.to_ullong(), core, opcode);
}

void update_flags_sub(unsigned long long oldVal,
                      unsigned long long newVal,
                      GameBoyCore* core,
                      unsigned long long opcode) {
    // todo
    core->SetFlags(newVal == 0, false, false, false);
}

void update_flags_sub(unsigned long long t1, const Register<8>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_sub(t1, t2.to_ullong(), core, opcode);
}

void update_flags_sub(const Register<8>& t1, unsigned long long t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_sub(t1.to_ullong(), t2, core, opcode);
}

void update_flags_sub(const Register<8>& t1, const Register<8>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_sub(t1.to_ullong(), t2.to_ullong(), core, opcode);
}

void update_flags_sbc(unsigned long long oldVal,
                      unsigned long long newVal,
                      GameBoyCore* core,
                      unsigned long long opcode) {
    // todo
    core->SetFlags(newVal == 0, false, false, false);
}

void update_flags_sbc(unsigned long long t1, const Register<8>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_sbc(t1, t2.to_ullong(), core, opcode);
}

void update_flags_sbc(const Register<8>& t1, unsigned long long t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_sbc(t1.to_ullong(), t2, core, opcode);
}

void update_flags_sbc(const Register<8>& t1, const Register<8>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_sbc(t1.to_ullong(), t2.to_ullong(), core, opcode);
}


void update_flags_and(unsigned long long oldVal,
                      unsigned long long newVal,
                      GameBoyCore* core,
                      unsigned long long opcode) {
    // todo
    core->SetFlags(newVal == 0, false, false, false);
}

void update_flags_and(unsigned long long t1, const Register<8>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_and(t1, t2.to_ullong(), core, opcode);
}

void update_flags_and(const Register<8>& t1, unsigned long long t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_and(t1.to_ullong(), t2, core, opcode);
}

void update_flags_and(const Register<8>& t1, const Register<8>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_and(t1.to_ullong(), t2.to_ullong(), core, opcode);
}


void update_flags_or(unsigned long long oldVal,
                      unsigned long long newVal,
                      GameBoyCore* core,
                      unsigned long long opcode) {
    core->SetFlags(newVal == 0, false, false, false);
}

void update_flags_or(unsigned long long t1, const Register<8>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_or(t1, t2.to_ullong(), core, opcode);
}

void update_flags_or(const Register<8>& t1, unsigned long long t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_or(t1.to_ullong(), t2, core, opcode);
}

void update_flags_or(const Register<8>& t1, const Register<8>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_or(t1.to_ullong(), t2.to_ullong(), core, opcode);
}


void update_flags_xor(unsigned long long oldVal,
                     unsigned long long newVal,
                     GameBoyCore* core,
                     unsigned long long opcode) {
    core->SetFlags(newVal == 0, false, false, false);
}

void update_flags_xor(unsigned long long t1, const Register<8>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_xor(t1, t2.to_ullong(), core, opcode);
}

void update_flags_xor(const Register<8>& t1, unsigned long long t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_xor(t1.to_ullong(), t2, core, opcode);
}

void update_flags_xor(const Register<8>& t1, const Register<8>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_xor(t1.to_ullong(), t2.to_ullong(), core, opcode);
}


void update_flags_cp(unsigned long long oldVal,
                      unsigned long long newVal,
                      GameBoyCore* core,
                      unsigned long long opcode) {
    // todo
    core->SetFlags(newVal == 0, true, false, false);
}

void update_flags_cp(unsigned long long t1, const Register<8>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_cp(t1, t2.to_ullong(), core, opcode);
}

void update_flags_cp(const Register<8>& t1, unsigned long long t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_cp(t1.to_ullong(), t2, core, opcode);
}

void update_flags_cp(const Register<8>& t1, const Register<8>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_cp(t1.to_ullong(), t2.to_ullong(), core, opcode);
}

void update_flags_add_16(unsigned long long oldVal,
                     unsigned long long newVal,
                     GameBoyCore* core,
                     unsigned long long opcode) {
    // todo
    core->SetFlags(newVal == 0, true, false, false);
}

void update_flags_add_16(unsigned long long t1, const Register<16>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_add_16(t1, t2.to_ullong(), core, opcode);
}

void update_flags_add_16(const Register<16>& t1, unsigned long long t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_add_16(t1.to_ullong(), t2, core, opcode);
}

void update_flags_add_16(const Register<16>& t1, const Register<16>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_add_16(t1.to_ullong(), t2.to_ullong(), core, opcode);
}

void update_flags_dec_16(unsigned long long oldVal,
                         unsigned long long newVal,
                         GameBoyCore* core,
                         unsigned long long opcode) {
    // todo
    core->SetFlags(newVal == 0, true, false, false);
}

void update_flags_dec_16(unsigned long long t1, const Register<16>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_dec_16(t1, t2.to_ullong(), core, opcode);
}

void update_flags_dec_16(const Register<16>& t1, unsigned long long t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_dec_16(t1.to_ullong(), t2, core, opcode);
}

void update_flags_dec_16(const Register<16>& t1, const Register<16>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_dec_16(t1.to_ullong(), t2.to_ullong(), core, opcode);
}


void update_flags_inc_16(unsigned long long oldVal,
                         unsigned long long newVal,
                         GameBoyCore* core,
                         unsigned long long opcode) {
    // todo
    core->SetFlags(newVal == 0, true, false, false);
}

void update_flags_inc_16(unsigned long long t1, const Register<16>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_inc_16(t1, t2.to_ullong(), core, opcode);
}

void update_flags_inc_16(const Register<16>& t1, unsigned long long t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_inc_16(t1.to_ullong(), t2, core, opcode);
}

void update_flags_inc_16(const Register<16>& t1, const Register<16>& t2, GameBoyCore* core, unsigned long long opcode) {
    return update_flags_inc_16(t1.to_ullong(), t2.to_ullong(), core, opcode);
}





// RET NZ
void Instruction::ret_nz_(GameBoyCore* core, unsigned long long opcode) {
    if ( core->getCpu()->getFlagRegister()->getZ() )
        return;

    ret__(core, opcode);
}

// RET
void Instruction::ret__(GameBoyCore* core, unsigned long long) {
    // pop 2 bytes from stack and jump to that address
    core->getCpu()->getCpuRegisters()->setPC(core->PopStack<16>().to_ullong() - 1);
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
    Register<8> oldCarry = core->getCpu()->getFlagRegister()->getC();

    reg = (reg >> 1) | (oldCarry << 7) ;

    core->getCpu()->getCpuRegisters()->setA(reg);

    core->SetFlags(!reg.any(), false, false, old);
}


// ADC A (HL)
void Instruction::adc_a__hl_(GameBoyCore* core, unsigned long long opcode) {
    // A += MEMORY[ HL ]
    auto cReg = core->getCpu()->getCpuRegisters()->getA();
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    auto oldVal = cReg;
    cReg += core->ReadData8(hl.to_ullong());
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
void Instruction::add_a_d8(GameBoyCore* core, unsigned long long opcode) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC( pc.to_ullong() + 1 );

    auto d8 = core->ReadData8(pc.to_ullong() + 1);

    auto oldVal = core->getCpu()->getCpuRegisters()->getA();
    auto newVal = oldVal + d8;

    core->getCpu()->getCpuRegisters()->setA(newVal.to_ullong());
    update_flags_add(oldVal, newVal, core, opcode);
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

    update_flags_add_16(oldVal, hl, core, opcode);
}

// ADC A d8
void Instruction::adc_a_d8(GameBoyCore* core, unsigned long long opcode) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);
    auto oldVal = core->getCpu()->getCpuRegisters()->getA();

    auto d8 = core->ReadData8(pc.to_ullong() + 1);

    auto newVal = oldVal + (d8.to_ullong() + static_cast<int>(core->getCpu()->getFlagRegister()->getC()));

    core->getCpu()->getCpuRegisters()->setA(newVal);

    update_flags_adc(oldVal, newVal, core, opcode);
}

// ADD HL HL
void Instruction::add_hl_hl(GameBoyCore* core, unsigned long long opcode) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();
    auto oldVal = hl;
    hl += hl;

    core->getCpu()->getCpuRegisters()->setHL(hl);

    update_flags_add_16(oldVal, hl, core, opcode);
}

// ADD SP r8
void Instruction::add_sp_r8(GameBoyCore* core, unsigned long long opcode) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

    auto oldVal = core->getCpu()->getCpuRegisters()->getSP();
    auto newVal = oldVal + core->ReadData8(pc.to_ullong() + 1);

    update_flags_add(oldVal, newVal, core, opcode);
    core->getCpu()->getFlagRegister()->setZ(false);
    core->getCpu()->getFlagRegister()->setN(false);
}

// ADD HL SP
void Instruction::add_hl_sp(GameBoyCore* core, unsigned long long opcode) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();
    auto sp = core->getCpu()->getCpuRegisters()->getSP();
    auto oldVal = hl;

    hl += sp;

    core->getCpu()->getCpuRegisters()->setHL(hl);

    update_flags_add_16(oldVal, hl, core, opcode);
}

// ADD HL BC
void Instruction::add_hl_bc(GameBoyCore* core, unsigned long long opcode) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();
    auto bc = core->getCpu()->getCpuRegisters()->getBC();
    auto oldVal = hl;

    hl += bc;

    core->getCpu()->getCpuRegisters()->setHL(hl);

    update_flags_add_16(oldVal, hl, core, opcode);
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
    auto oldVal = core->getCpu()->getCpuRegisters()->getA();
    auto newVal = oldVal.to_ullong() +
            core->ReadData8(core->getCpu()->getCpuRegisters()->getHL().to_ullong()).to_ullong();

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_add(oldVal.to_ullong(), newVal, core, opcode);
}

// ADD A L
void Instruction::add_a_l(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getA();
    auto newVal = oldVal + core->getCpu()->getCpuRegisters()->getL();

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_add(oldVal.to_ullong(), newVal.to_ullong(), core, opcode);
}

// ADD A H
void Instruction::add_a_h(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getA();
    auto newVal = oldVal + core->getCpu()->getCpuRegisters()->getH();

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_add(oldVal.to_ullong(), newVal.to_ullong(), core, opcode);
}

// ADD A E
void Instruction::add_a_e(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getA();
    auto newVal = oldVal + core->getCpu()->getCpuRegisters()->getE();

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_add(oldVal.to_ullong(), newVal.to_ullong(), core, opcode);
}

// ADD A D
void Instruction::add_a_d(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getA();
    auto newVal = oldVal + core->getCpu()->getCpuRegisters()->getD();

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_add(oldVal.to_ullong(), newVal.to_ullong(), core, opcode);
}

// ADC A C
void Instruction::adc_a_c(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getA();
    auto newVal = oldVal + core->getCpu()->getCpuRegisters()->getC() + core->getCpu()->getFlagRegister()->getC();

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_adc(oldVal.to_ullong(), newVal.to_ullong(), core, opcode);
}

// ADC A B
void Instruction::adc_a_b(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getA();
    auto newVal = oldVal + core->getCpu()->getCpuRegisters()->getB() + core->getCpu()->getFlagRegister()->getC();

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_adc(oldVal.to_ullong(), newVal.to_ullong(), core, opcode);
}

// CALL NZ a16
void Instruction::call_nz_a16(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC( pc + 1 );
    if ( core->getCpu()->getFlagRegister()->getZ() ) {
        return;
    }
    core->PushToStack(pc + 1);

    auto a16 = core->ReadData16(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
}

// CALL NC a16
void Instruction::call_nc_a16(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC( pc + 1 );
    if ( core->getCpu()->getFlagRegister()->getC() ) {
        return;
    }
    core->PushToStack(pc + 1);

    auto a16 = core->ReadData16(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
}

// CALL a16
void Instruction::call_a16_(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();

    core->PushToStack(pc + 1);

    auto a16 = core->ReadData16(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
}

// CALL Z a16
void Instruction::call_z_a16(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC( pc + 1 );
    if ( !core->getCpu()->getFlagRegister()->getZ() ) {
        return;
    }
    core->PushToStack(pc + 1);

    auto a16 = core->ReadData16(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
}

// CALL C a16
void Instruction::call_c_a16(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC( pc + 1 );
    if ( !core->getCpu()->getFlagRegister()->getC() ) {
        return;
    }
    core->PushToStack(pc + 1);

    auto a16 = core->ReadData16(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
}

// DI
void Instruction::di__(GameBoyCore* core, unsigned long long) {
    core->setInterruptsEnabled(false);
}

// JP NZ a16
void Instruction::jp_nz_a16(GameBoyCore* core, unsigned long long) {

// todo
throw std::invalid_argument(__FUNCTION__);;
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JP a16
void Instruction::jp_a16_(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();

    auto a16 = core->ReadData16(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setPC(a16.to_ullong() - 1);
}

// JP NC a16
void Instruction::jp_nc_a16(GameBoyCore* core, unsigned long long) {

// todo
throw std::invalid_argument(__FUNCTION__);;
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JP (HL)
void Instruction::jp__hl__(GameBoyCore* core, unsigned long long) {

// todo
throw std::invalid_argument(__FUNCTION__);;
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JP Z a16
void Instruction::jp_z_a16(GameBoyCore* core, unsigned long long) {

// todo
throw std::invalid_argument(__FUNCTION__);;
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JP C a16
void Instruction::jp_c_a16(GameBoyCore* core, unsigned long long) {

// todo
throw std::invalid_argument(__FUNCTION__);;
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// RLA
void Instruction::rla__(GameBoyCore* core, unsigned long long) {
    auto a = core->getCpu()->getCpuRegisters()->getA();

    auto carry = (a >> 7).to_ullong();
    assert(carry == 0 || carry == 1);

    a = (a << 1) | static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    /*
        Z - Set if result is zero.
        N - Reset.
        H - Reset.
        C - Contains old bit 7 data.
     */
    core->getCpu()->getFlagRegister()->setZ(a.to_ullong() == 0);
    core->getCpu()->getFlagRegister()->setN(false);
    core->getCpu()->getFlagRegister()->setH(false);
    core->getCpu()->getFlagRegister()->setC(static_cast<bool>(carry));

    core->getCpu()->getCpuRegisters()->setA(a);
}

// JR r8
void Instruction::jr_r8_(GameBoyCore* core, unsigned long long) {

// todo
throw std::invalid_argument(__FUNCTION__);;
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// JR NZ r8
void Instruction::jr_nz_r8(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc + 1);
    if ( core->getCpu()->getFlagRegister()->getZ() ) return;

    auto data = core->getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + data.to_ullong());
}

// JR Z r8
void Instruction::jr_z_r8(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc + 1);
    if ( !core->getCpu()->getFlagRegister()->getZ() ) return;

    auto data = core->getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + data.to_ullong());
}

// JR NC r8
void Instruction::jr_nc_r8(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc + 1);
    if ( core->getCpu()->getFlagRegister()->getC() ) return;

    auto data = core->getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + data.to_ullong());
}

// JR C r8
void Instruction::jr_c_r8(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc + 1);
    if ( !core->getCpu()->getFlagRegister()->getC() ) return;

    auto data = core->getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + data.to_ullong());
}

// RETI
void Instruction::reti__(GameBoyCore* core, unsigned long long opcode) {
    auto pc = core->PopStack<16>().to_ullong() - 1;
    core->getCpu()->getCpuRegisters()->setPC(pc);
    ei__(core, opcode);
}

// LDH (a8) A
void Instruction::ldh__a8__a(GameBoyCore* core, unsigned long long) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc + 1);

    auto& codeLoader = *core->getCpu()->getCodeLoader();

    auto a8 = 0xFF00 + codeLoader.ReadBytes<1>(pc.to_ullong() + 1).to_ullong();

    core->WriteData8( a8, a );
}

// LDH A (a8)
void Instruction::ldh_a__a8_(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

    auto a8 = 0xFF00 + core->getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong() + 1);

    auto data = core->ReadData8(a8.to_ullong());

    core->getCpu()->getCpuRegisters()->setA(data);
}

// SBC A d8
void Instruction::sbc_a_d8(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

    auto data = core->ReadData8(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setA(data);
}

// SBC A B
void Instruction::sbc_a_b(GameBoyCore* core, unsigned long long opcode) {
    auto op = core->getCpu()->getCpuRegisters()->getB();
    auto carry = static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = a;

    a -= op + carry;
    core->getCpu()->getCpuRegisters()->setA(a);

    update_flags_sbc(oldVal, a, core, opcode);
}

// SBC A C
void Instruction::sbc_a_c(GameBoyCore* core, unsigned long long opcode) {
    auto op = core->getCpu()->getCpuRegisters()->getC();
    auto carry = static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = a;

    a -= op + carry;
    core->getCpu()->getCpuRegisters()->setA(a);

    update_flags_sbc(oldVal, a, core, opcode);
}

// SBC A A
void Instruction::sbc_a_a(GameBoyCore* core, unsigned long long opcode) {
    auto op = core->getCpu()->getCpuRegisters()->getA();
    auto carry = static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = a;

    a -= op + carry;
    core->getCpu()->getCpuRegisters()->setA(a);

    update_flags_sbc(oldVal, a, core, opcode);
}

// SBC A (HL)
void Instruction::sbc_a__hl_(GameBoyCore* core, unsigned long long opcode) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    auto op = core->ReadData8(hl.to_ullong()).to_ullong();
    auto carry = static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = a;

    a -= op + carry;
    core->getCpu()->getCpuRegisters()->setA(a);

    update_flags_sbc(oldVal, a, core, opcode);
}

// SBC A L
void Instruction::sbc_a_l(GameBoyCore* core, unsigned long long opcode) {
    auto op = core->getCpu()->getCpuRegisters()->getL();
    auto carry = static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = a;

    a -= op + carry;
    core->getCpu()->getCpuRegisters()->setA(a);

    update_flags_sbc(oldVal, a, core, opcode);
}

// SBC A H
void Instruction::sbc_a_h(GameBoyCore* core, unsigned long long opcode) {
    auto op = core->getCpu()->getCpuRegisters()->getH();
    auto carry = static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = a;

    a -= op + carry;
    core->getCpu()->getCpuRegisters()->setA(a);

    update_flags_sbc(oldVal, a, core, opcode);
}

// SBC A E
void Instruction::sbc_a_e(GameBoyCore* core, unsigned long long opcode) {
    auto op = core->getCpu()->getCpuRegisters()->getE();
    auto carry = static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = a;

    a -= op + carry;
    core->getCpu()->getCpuRegisters()->setA(a);

    update_flags_sbc(oldVal, a, core, opcode);
}

// SBC A D
void Instruction::sbc_a_d(GameBoyCore* core, unsigned long long opcode) {
    auto op = core->getCpu()->getCpuRegisters()->getD();
    auto carry = static_cast<int>(core->getCpu()->getFlagRegister()->getC());

    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto oldVal = a;

    a -= op + carry;
    core->getCpu()->getCpuRegisters()->setA(a);

    update_flags_sbc(oldVal, a, core, opcode);
}

// HALT
void Instruction::halt__(GameBoyCore* core, unsigned long long) {
    core->setIsHalted(true);
}

// SUB d8
void Instruction::sub_d8_(GameBoyCore* core, unsigned long long) {
    bool z;
    bool h;
    bool c;

// todo
throw std::invalid_argument(__FUNCTION__);;
    core->SetFlags(z, true, h, c);
}

// SUB B
void Instruction::sub_b_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getB();
    auto nA = a - b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_sub(a, nA, core, opcode);
}

// SUB A
void Instruction::sub_a_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getA();
    auto nA = a - b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_sub(a, nA, core, opcode);
}

// SUB (HL)
void Instruction::sub__hl__(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    auto b = core->ReadData8(hl.to_ullong());

    auto nA = a - b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_sub(a, nA, core, opcode);
}

// SUB L
void Instruction::sub_l_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getL();
    auto nA = a - b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_sub(a, nA, core, opcode);
}

// SUB H
void Instruction::sub_h_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getH();
    auto nA = a - b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_sub(a, nA, core, opcode);
}

// SUB E
void Instruction::sub_e_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getE();
    auto nA = a - b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_sub(a, nA, core, opcode);
}

// SUB D
void Instruction::sub_d_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getD();
    auto nA = a - b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_sub(a, nA, core, opcode);
}

// SUB C
void Instruction::sub_c_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getC();
    auto nA = a - b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_sub(a, nA, core, opcode);
}

// OR C
void Instruction::or_c_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getC();

    auto nA = a | b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_or(a, nA, core, opcode);
}

// OR B
void Instruction::or_b_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getB();

    auto nA = a | b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_or(a, nA, core, opcode);
}

// OR A
void Instruction::or_a_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getA();

    auto nA = a | b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_or(a, nA, core, opcode);
}

// OR (HL)
void Instruction::or__hl__(GameBoyCore* core, unsigned long long opcode) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->ReadData8(hl.to_ullong()).to_ullong();

    auto nA = a | b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_or(a, nA, core, opcode);
}

// OR L
void Instruction::or_l_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getL();

    auto nA = a | b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_or(a, nA, core, opcode);
}

// OR H
void Instruction::or_h_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getH();

    auto nA = a | b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_or(a, nA, core, opcode);
}

// OR E
void Instruction::or_e_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getE();

    auto nA = a | b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_or(a, nA, core, opcode);
}

// OR D
void Instruction::or_d_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getD();

    auto nA = a | b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_or(a, nA, core, opcode);
}

// OR d8
void Instruction::or_d8_(GameBoyCore* core, unsigned long long) {
    bool z;

// todo
throw std::invalid_argument(__FUNCTION__);;
    core->SetFlags(z, false, false, false);
}

// DEC D
void Instruction::dec_d_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getD();
    auto newVal = oldVal - 1;
    core->getCpu()->getCpuRegisters()->setD(newVal);

    update_flags_dec(oldVal, newVal, core, opcode);
}

// DEC E
void Instruction::dec_e_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getE();
    auto newVal = oldVal - 1;
    core->getCpu()->getCpuRegisters()->setE(newVal);

    update_flags_dec(oldVal, newVal, core, opcode);
}

// DEC DE
void Instruction::dec_de_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getDE();
    auto newVal = oldVal - 1;
    core->getCpu()->getCpuRegisters()->setDE(newVal);

    update_flags_dec_16(oldVal, newVal, core, opcode);
}

// DEC H
void Instruction::dec_h_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getH();
    auto newVal = oldVal - 1;
    core->getCpu()->getCpuRegisters()->setH(newVal);

    update_flags_dec(oldVal, newVal, core, opcode);
}

// DEC L
void Instruction::dec_l_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getL();
    auto newVal = oldVal - 1;
    core->getCpu()->getCpuRegisters()->setL(newVal);

    update_flags_dec(oldVal, newVal, core, opcode);
}

// DEC HL
void Instruction::dec_hl_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getHL();
    auto newVal = oldVal - 1;
    core->getCpu()->getCpuRegisters()->setHL(newVal);

    update_flags_dec_16(oldVal, newVal, core, opcode);
}

// DEC (HL)
void Instruction::dec__hl__(GameBoyCore* core, unsigned long long opcode) {
    auto addr = core->getCpu()->getCpuRegisters()->getHL();

    auto oldVal = core->ReadData8(addr.to_ullong());
    auto newVal = oldVal.to_ullong() - 1;

    core->WriteData8(addr.to_ullong(), newVal);

    update_flags_dec(oldVal.to_ullong(), newVal, core, opcode);
}

// DEC SP
void Instruction::dec_sp_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getSP();
    auto newVal = oldVal - 1;
    core->getCpu()->getCpuRegisters()->setSP(newVal);

    update_flags_dec_16(oldVal, newVal, core, opcode);
}

// DEC A
void Instruction::dec_a_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getA();
    auto newVal = oldVal - 1;
    core->getCpu()->getCpuRegisters()->setA(newVal);

    update_flags_dec(oldVal, newVal, core, opcode);
}

// DEC B
void Instruction::dec_b_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getB();
    auto newVal = oldVal - 1;
    core->getCpu()->getCpuRegisters()->setB(newVal);

    update_flags_dec(oldVal, newVal, core, opcode);
}

// DEC BC
void Instruction::dec_bc_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getBC();
    auto newVal = oldVal - 1;
    core->getCpu()->getCpuRegisters()->setBC(newVal);

    update_flags_dec_16(oldVal, newVal, core, opcode);
}

// DEC C
void Instruction::dec_c_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getC();
    auto newVal = oldVal - 1;
    core->getCpu()->getCpuRegisters()->setC(newVal);

    update_flags_dec(oldVal, newVal, core, opcode);
}

// EI
void Instruction::ei__(GameBoyCore* core, unsigned long long) {
    core->setInterruptsEnabled(true);
}

// STOP 0
void Instruction::stop_0_(GameBoyCore* core, unsigned long long) {

// todo
throw std::invalid_argument(__FUNCTION__);;
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// DAA
void Instruction::daa__(GameBoyCore* core, unsigned long long) {
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

    if ( low.to_ullong() > 9 || core->getCpu()->getFlagRegister()->getH() ) {
        nA += 0x06;

        if ( high.to_ullong() > 9 || core->getCpu()->getFlagRegister()->getC() ) {
            nA += 0x60;
        }
    }

    core->getCpu()->getFlagRegister()->setH(false);
    core->getCpu()->getFlagRegister()->setZ(nA.to_ullong() == 0);

    // todo
throw std::invalid_argument(__FUNCTION__);;

    core->getCpu()->getCpuRegisters()->setA(nA);
}

// CCF
void Instruction::ccf__(GameBoyCore* core, unsigned long long) {
    /*
        Z - Not affected.
        N - Reset.
        H - Reset.
        C - Complemented.
     */

    core->getCpu()->getFlagRegister()->setN(false);
    core->getCpu()->getFlagRegister()->setH(false);
    core->getCpu()->getFlagRegister()->setC(!core->getCpu()->getFlagRegister()->getC());
}

// CP C
void Instruction::cp_c_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getC();

    auto nA = a - b;

    update_flags_cp(a, nA, core, opcode);
}

// CP B
void Instruction::cp_b_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getB();

    auto nA = a - b;

    update_flags_cp(a, nA, core, opcode);
}

// CP D
void Instruction::cp_d_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getD();

    auto nA = a - b;

    update_flags_cp(a, nA, core, opcode);
}

// CP A
void Instruction::cp_a_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getA();

    auto nA = a - b;

    update_flags_cp(a, nA, core, opcode);
}

// CP (HL)
void Instruction::cp__hl__(GameBoyCore* core, unsigned long long opcode) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->ReadData8(hl.to_ullong()).to_ullong();

    auto nA = a - b;

    update_flags_cp(a, nA, core, opcode);
}

// CP L
void Instruction::cp_l_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getL();

    auto nA = a - b;

    update_flags_cp(a, nA, core, opcode);
}

// CP H
void Instruction::cp_h_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getH();

    auto nA = a - b;

    update_flags_cp(a, nA, core, opcode);
}

// CP E
void Instruction::cp_e_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getE();

    auto nA = a - b;

    update_flags_cp(a, nA, core, opcode);
}

// CP d8
void Instruction::cp_d8_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();

    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

    auto b = core->ReadData8(pc.to_ullong() + 1);

    auto nA = a - b;

    update_flags_cp(a, nA, core, opcode);
}

// NOP
void Instruction::nop__(GameBoyCore* core, unsigned long long) {
    // nope nope nope nope nope
}

// POP BC
void Instruction::pop_bc_(GameBoyCore* core, unsigned long long) {
    core->getCpu()->getCpuRegisters()->setBC(core->PopStack<16>());
}

// POP DE
void Instruction::pop_de_(GameBoyCore* core, unsigned long long) {
    core->getCpu()->getCpuRegisters()->setDE(core->PopStack<16>());
}

// POP HL
void Instruction::pop_hl_(GameBoyCore* core, unsigned long long) {
    core->getCpu()->getCpuRegisters()->setHL(core->PopStack<16>());
}

// POP AF
void Instruction::pop_af_(GameBoyCore* core, unsigned long long) {
    core->getCpu()->getCpuRegisters()->setAF(core->PopStack<16>());
}

// RST 00H
void Instruction::rst_00h_(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();

    core->PushToStack(pc);

    core->getCpu()->getCpuRegisters()->setPC(-1);
}

// RST 10H
void Instruction::rst_10h_(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();

    core->PushToStack(pc);

    core->getCpu()->getCpuRegisters()->setPC(0x10 - 1);
}

// RST 20H
void Instruction::rst_20h_(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();

    core->PushToStack(pc);

    core->getCpu()->getCpuRegisters()->setPC(0x20 - 1);
}

// RST 08H
void Instruction::rst_08h_(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();

    core->PushToStack(pc);

    core->getCpu()->getCpuRegisters()->setPC(0x8 - 1);
}

// RST 30H
void Instruction::rst_30h_(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();

    core->PushToStack(pc);

    core->getCpu()->getCpuRegisters()->setPC(0x30 - 1);
}

// RST 18H
void Instruction::rst_18h_(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();

    core->PushToStack(pc);

    core->getCpu()->getCpuRegisters()->setPC(0x18 - 1);
}

// RST 28H
void Instruction::rst_28h_(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();

    core->PushToStack(pc);

    core->getCpu()->getCpuRegisters()->setPC(0x28 - 1);
}

// RST 38H
void Instruction::rst_38h_(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();

    core->PushToStack(pc);

    core->getCpu()->getCpuRegisters()->setPC(0x38 - 1);
}

// PREFIX CB
void Instruction::prefix_cb_(GameBoyCore* core, unsigned long long) {
// todo
throw std::invalid_argument(__FUNCTION__);;
}

// AND B
void Instruction::and_b_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getB();
    auto newVal = a & b;

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_and(a, newVal, core, opcode);
}

// AND A
void Instruction::and_a_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getA();
    auto newVal = a & b;

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_and(a, newVal, core, opcode);
}

// AND (HL)
void Instruction::and__hl__(GameBoyCore* core, unsigned long long opcode) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->ReadData8(hl.to_ullong()).to_ullong();
    auto newVal = a & b;

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_and(a, newVal, core, opcode);
}

// AND L
void Instruction::and_l_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getL();
    auto newVal = a & b;

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_and(a, newVal, core, opcode);
}

// AND H
void Instruction::and_h_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getH();
    auto newVal = a & b;

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_and(a, newVal, core, opcode);
}

// AND E
void Instruction::and_e_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getE();
    auto newVal = a & b;

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_and(a, newVal, core, opcode);
}

// AND D
void Instruction::and_d_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getD();
    auto newVal = a & b;

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_and(a, newVal, core, opcode);
}

// AND C
void Instruction::and_c_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getC();
    auto newVal = a & b;

    core->getCpu()->getCpuRegisters()->setA(newVal);
    update_flags_and(a, newVal, core, opcode);
}

// AND d8
void Instruction::and_d8_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

    auto data = core->getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong() + 1);

    auto nA = a & data;

    update_flags_and(a, nA, core, opcode);
}

// SCF
void Instruction::scf__(GameBoyCore* core, unsigned long long) {
    /*
    Z - Not affected.
    N - Reset.
    H - Reset.
    C - Set.
     */

    core->getCpu()->getFlagRegister()->setN(false);
    core->getCpu()->getFlagRegister()->setH(false);
    core->getCpu()->getFlagRegister()->setC(true);
}

// LD D d8
void Instruction::ld_d_d8(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

    auto d8 = core->getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setD(d8);
}

// LD (DE) A
void Instruction::ld__de__a(GameBoyCore* core, unsigned long long) {
    auto de = core->getCpu()->getCpuRegisters()->getDE();
    auto a = core->getCpu()->getCpuRegisters()->getA();

    core->WriteData8(de.to_ullong(), a);
}

// LD DE d16
void Instruction::ld_de_d16(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 2);

    auto d16 = core->getCpu()->getCodeLoader()->ReadBytes<2>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setDE(d16);
}

// LD E d8
void Instruction::ld_e_d8(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

    auto d8 = core->getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setE(d8);
}

// LD A (DE)
void Instruction::ld_a__de_(GameBoyCore* core, unsigned long long) {
    auto de = core->getCpu()->getCpuRegisters()->getDE();

    auto data = core->ReadData8(de.to_ullong());

    core->getCpu()->getCpuRegisters()->setA(data);
}

// LD HL d16
void Instruction::ld_hl_d16(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc + 2);

    auto d16 = core->getCpu()->getCodeLoader()->ReadBytes<2>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setHL(d16);
}

// LD H d8
void Instruction::ld_h_d8(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

    auto d8 = core->getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setH(d8);
}

// LD (HL+) A
void Instruction::ld__hlplus__a(GameBoyCore* core, unsigned long long) {

// todo
throw std::invalid_argument(__FUNCTION__);;
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD A (HL+)
void Instruction::ld_a__hlplus_(GameBoyCore* core, unsigned long long opcode) {
    // Same as: LD A,(HL) - INC H
    Instruction::ld_a__hl_(core, opcode);
    Instruction::inc_h_(core, opcode);
}

// LD (C) A
void Instruction::ld__c__a(GameBoyCore* core, unsigned long long) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto c = core->getCpu()->getCpuRegisters()->getC();

    core->WriteData8(0xff00 + c.to_ullong(), a);
}

// LD L d8
void Instruction::ld_l_d8(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 1);

    auto d8 = core->getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setL(d8);
}

// LD (HL-) A
void Instruction::ld__hlminus__a(GameBoyCore* core, unsigned long long opcode) {
    //  Same as: LD (HL),A - DEC HL
    ld__hl__a(core, opcode);
    dec_hl_(core, opcode);
}

// LD SP d16
void Instruction::ld_sp_d16(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 2);

    auto d16 = core->getCpu()->getCodeLoader()->ReadBytes<2>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setSP(d16);
}

// LD (HL) d8
void Instruction::ld__hl__d8(GameBoyCore* core, unsigned long long) {

// todo
throw std::invalid_argument(__FUNCTION__);;
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD A (HL-)
void Instruction::ld_a__hlminus_(GameBoyCore* core, unsigned long long) {

// todo
throw std::invalid_argument(__FUNCTION__);;
    core->SetFlags(core->getCpu()->getFlagRegister()->getN(), core->getCpu()->getFlagRegister()->getH(), core->getCpu()->getFlagRegister()->getC(), core->getCpu()->getFlagRegister()->getZ());
}

// LD A (C)
void Instruction::ld_a__c_(GameBoyCore* core, unsigned long long) {
    auto c = core->getCpu()->getCpuRegisters()->getC();

    auto data = core->ReadData8(c.to_ullong() + 0xff00);

    core->getCpu()->getCpuRegisters()->setA(data);
}

// LD SP HL
void Instruction::ld_sp_hl(GameBoyCore* core, unsigned long long) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    auto data = core->ReadData16(hl.to_ullong());

    core->getCpu()->getCpuRegisters()->setSP(data);
}

// LD A d8
void Instruction::ld_a_d8(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc + 1);

    auto data = core->getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setA(data.to_ullong());
}

// LD HL SP+r8
void Instruction::ld_hl_spplusr8(GameBoyCore* core, unsigned long long) {
    bool h;
    bool c;

// todo
throw std::invalid_argument(__FUNCTION__);;
    core->SetFlags(false, false, h, c);
}

// LD B E
void Instruction::ld_b_e(GameBoyCore* core, unsigned long long) {
    auto e = core->getCpu()->getCpuRegisters()->getE();

    core->getCpu()->getCpuRegisters()->setB(e);
}

// LD B D
void Instruction::ld_b_d(GameBoyCore* core, unsigned long long) {
    auto d = core->getCpu()->getCpuRegisters()->getD();

    core->getCpu()->getCpuRegisters()->setB(d);
}

// LD B C
void Instruction::ld_b_c(GameBoyCore* core, unsigned long long) {
    auto c = core->getCpu()->getCpuRegisters()->getC();

    core->getCpu()->getCpuRegisters()->setB(c);
}

// LD B B
void Instruction::ld_b_b(GameBoyCore* core, unsigned long long) {
    auto b = core->getCpu()->getCpuRegisters()->getB();

    core->getCpu()->getCpuRegisters()->setB(b);
}

// LD C C
void Instruction::ld_c_c(GameBoyCore* core, unsigned long long) {
    auto c = core->getCpu()->getCpuRegisters()->getC();

    core->getCpu()->getCpuRegisters()->setC(c);
}

// LD C B
void Instruction::ld_c_b(GameBoyCore* core, unsigned long long) {
    auto b = core->getCpu()->getCpuRegisters()->getB();

    core->getCpu()->getCpuRegisters()->setC(b);
}

// LD B A
void Instruction::ld_b_a(GameBoyCore* core, unsigned long long) {
    auto a = core->getCpu()->getCpuRegisters()->getA();

    core->getCpu()->getCpuRegisters()->setB(a);
}

// LD B (HL)
void Instruction::ld_b__hl_(GameBoyCore* core, unsigned long long) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    auto data = core->ReadData8(hl.to_ullong());

    core->getCpu()->getCpuRegisters()->setB(data);
}

// LD B L
void Instruction::ld_b_l(GameBoyCore* core, unsigned long long) {
    auto l = core->getCpu()->getCpuRegisters()->getL();

    core->getCpu()->getCpuRegisters()->setB(l);
}

// LD B H
void Instruction::ld_b_h(GameBoyCore* core, unsigned long long) {
    auto h = core->getCpu()->getCpuRegisters()->getH();

    core->getCpu()->getCpuRegisters()->setB(h);
}

// LD C H
void Instruction::ld_c_h(GameBoyCore* core, unsigned long long) {
    auto h = core->getCpu()->getCpuRegisters()->getH();

    core->getCpu()->getCpuRegisters()->setC(h);
}

// LD C E
void Instruction::ld_c_e(GameBoyCore* core, unsigned long long) {
    auto e = core->getCpu()->getCpuRegisters()->getE();

    core->getCpu()->getCpuRegisters()->setC(e);
}

// LD C D
void Instruction::ld_c_d(GameBoyCore* core, unsigned long long) {
    auto d = core->getCpu()->getCpuRegisters()->getD();

    core->getCpu()->getCpuRegisters()->setC(d);
}

// LD BC d16
void Instruction::ld_bc_d16(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();

    core->getCpu()->getCpuRegisters()->setPC(pc.to_ullong() + 2);

    auto data = core->getCpu()->getCodeLoader()->ReadBytes<2>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setBC(data);
}

// LD (BC) A
void Instruction::ld__bc__a(GameBoyCore* core, unsigned long long) {
    auto bc = core->getCpu()->getCpuRegisters()->getBC();
    auto a  = core->getCpu()->getCpuRegisters()->getA();

    core->WriteData8(bc.to_ullong(), a);
}

// LD C A
void Instruction::ld_c_a(GameBoyCore* core, unsigned long long) {
    auto a = core->getCpu()->getCpuRegisters()->getA();

    core->getCpu()->getCpuRegisters()->setC(a);
}

// LD B d8
void Instruction::ld_b_d8(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc + 1);

    auto d8 = core->getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setB(d8);
}

// LD C (HL)
void Instruction::ld_c__hl_(GameBoyCore* core, unsigned long long) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    auto data = core->ReadData8(hl.to_ullong());

    core->getCpu()->getCpuRegisters()->setC(data);
}

// LD C L
void Instruction::ld_c_l(GameBoyCore* core, unsigned long long) {
    auto l = core->getCpu()->getCpuRegisters()->getL();

    core->getCpu()->getCpuRegisters()->setC(l);
}

// LD (a16) SP
void Instruction::ld__a16__sp(GameBoyCore* core, unsigned long long) {
    auto sp   = core->getCpu()->getCpuRegisters()->getSP();
    auto& codeLoader = *core->getCpu()->getCodeLoader();

    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc + 2);

    Register<16> reg = codeLoader.ReadBytes<2>(pc.to_ullong() + 1);

    core->WriteData16(reg.to_ullong(), sp);
}

// LD D H
void Instruction::ld_d_h(GameBoyCore* core, unsigned long long) {
    auto h = core->getCpu()->getCpuRegisters()->getH();

    core->getCpu()->getCpuRegisters()->setD(h);
}

// LD D E
void Instruction::ld_d_e(GameBoyCore* core, unsigned long long) {
    auto e = core->getCpu()->getCpuRegisters()->getE();

    core->getCpu()->getCpuRegisters()->setD(e);
}

// LD D D
void Instruction::ld_d_d(GameBoyCore* core, unsigned long long) {
    auto d = core->getCpu()->getCpuRegisters()->getD();

    core->getCpu()->getCpuRegisters()->setD(d);
}

// LD D C
void Instruction::ld_d_c(GameBoyCore* core, unsigned long long) {
    auto c = core->getCpu()->getCpuRegisters()->getC();

    core->getCpu()->getCpuRegisters()->setD(c);
}

// LD (a16) A
void Instruction::ld__a16__a(GameBoyCore* core, unsigned long long) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    auto& codeLoader = *core->getCpu()->getCodeLoader();

    core->getCpu()->getCpuRegisters()->setPC(pc + 2);

    Register<16> reg = codeLoader.ReadBytes<2>(pc.to_ullong() + 1);

    core->WriteData8( reg.to_ullong(), a );
}

// LD D B
void Instruction::ld_d_b(GameBoyCore* core, unsigned long long) {
    auto b = core->getCpu()->getCpuRegisters()->getB();

    core->getCpu()->getCpuRegisters()->setD(b);
}

// LD E C
void Instruction::ld_e_c(GameBoyCore* core, unsigned long long) {
    auto c = core->getCpu()->getCpuRegisters()->getC();

    core->getCpu()->getCpuRegisters()->setE(c);
}

// LD E B
void Instruction::ld_e_b(GameBoyCore* core, unsigned long long) {
    auto b = core->getCpu()->getCpuRegisters()->getB();

    core->getCpu()->getCpuRegisters()->setE(b);
}

// LD D A
void Instruction::ld_d_a(GameBoyCore* core, unsigned long long) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    core->getCpu()->getCpuRegisters()->setD(a);
}

// LD D (HL)
void Instruction::ld_d__hl_(GameBoyCore* core, unsigned long long) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    auto data = core->ReadData8(hl.to_ullong());

    core->getCpu()->getCpuRegisters()->setD(data);
}

// LD D L
void Instruction::ld_d_l(GameBoyCore* core, unsigned long long) {
    auto l = core->getCpu()->getCpuRegisters()->getL();

    core->getCpu()->getCpuRegisters()->setD(l);
}

// LD E L
void Instruction::ld_e_l(GameBoyCore* core, unsigned long long) {
    auto l = core->getCpu()->getCpuRegisters()->getL();

    core->getCpu()->getCpuRegisters()->setE(l);
}

// LD E H
void Instruction::ld_e_h(GameBoyCore* core, unsigned long long) {
    auto h = core->getCpu()->getCpuRegisters()->getH();

    core->getCpu()->getCpuRegisters()->setE(h);
}

// LD E E
void Instruction::ld_e_e(GameBoyCore* core, unsigned long long) {
    auto e = core->getCpu()->getCpuRegisters()->getE();

    core->getCpu()->getCpuRegisters()->setE(e);
}

// LD E D
void Instruction::ld_e_d(GameBoyCore* core, unsigned long long) {
    auto d = core->getCpu()->getCpuRegisters()->getD();

    core->getCpu()->getCpuRegisters()->setE(d);
}

// LD E A
void Instruction::ld_e_a(GameBoyCore* core, unsigned long long) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    core->getCpu()->getCpuRegisters()->setE(a);
}

// LD E (HL)
void Instruction::ld_e__hl_(GameBoyCore* core, unsigned long long) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    auto data = core->ReadData8(hl.to_ullong());

    core->getCpu()->getCpuRegisters()->setE(data);
}

// LD H L
void Instruction::ld_h_l(GameBoyCore* core, unsigned long long) {
    auto l = core->getCpu()->getCpuRegisters()->getL();

    core->getCpu()->getCpuRegisters()->setH(l);
}

// LD H H
void Instruction::ld_h_h(GameBoyCore* core, unsigned long long) {
    auto h = core->getCpu()->getCpuRegisters()->getH();

    core->getCpu()->getCpuRegisters()->setH(h);
}

// LD H E
void Instruction::ld_h_e(GameBoyCore* core, unsigned long long) {
    auto e = core->getCpu()->getCpuRegisters()->getE();

    core->getCpu()->getCpuRegisters()->setH(e);
}

// LD H D
void Instruction::ld_h_d(GameBoyCore* core, unsigned long long) {
    auto d = core->getCpu()->getCpuRegisters()->getD();

    core->getCpu()->getCpuRegisters()->setH(d);
}

// LD H C
void Instruction::ld_h_c(GameBoyCore* core, unsigned long long) {
    auto c = core->getCpu()->getCpuRegisters()->getC();

    core->getCpu()->getCpuRegisters()->setH(c);
}

// LD A (a16)
void Instruction::ld_a__a16_(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();

    auto codeLoader = core->getCpu()->getCodeLoader();

    auto addr = codeLoader->ReadBytes<2>(pc.to_ullong() + 1);
    core->getCpu()->getCpuRegisters()->setPC(pc + 2);

    auto data = core->ReadData8( addr.to_ullong() );
    core->getCpu()->getCpuRegisters()->setA(data);
}

// LD H B
void Instruction::ld_h_b(GameBoyCore* core, unsigned long long) {
    auto b = core->getCpu()->getCpuRegisters()->getB();

    core->getCpu()->getCpuRegisters()->setH(b);
}

// LD A (BC)
void Instruction::ld_a__bc_(GameBoyCore* core, unsigned long long) {
    auto bc = core->getCpu()->getCpuRegisters()->getBC();

    auto data = core->ReadData8(bc.to_ullong());

    core->getCpu()->getCpuRegisters()->setA(data);
}

// LD L C
void Instruction::ld_l_c(GameBoyCore* core, unsigned long long) {
    auto c = core->getCpu()->getCpuRegisters()->getC();
    core->getCpu()->getCpuRegisters()->setL(c);
}

// LD C d8
void Instruction::ld_c_d8(GameBoyCore* core, unsigned long long) {
    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc + 1);

    auto d8 = core->getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong() + 1);

    core->getCpu()->getCpuRegisters()->setC(d8);
}

// LD L B
void Instruction::ld_l_b(GameBoyCore* core, unsigned long long) {
    auto b = core->getCpu()->getCpuRegisters()->getB();

    core->getCpu()->getCpuRegisters()->setL(b);
}

// LD H A
void Instruction::ld_h_a(GameBoyCore* core, unsigned long long) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    core->getCpu()->getCpuRegisters()->setH(a);
}

// LD H (HL)
void Instruction::ld_h__hl_(GameBoyCore* core, unsigned long long) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    auto data = core->ReadData8(hl.to_ullong());

    core->getCpu()->getCpuRegisters()->setH(data);
}

// LD L (HL)
void Instruction::ld_l__hl_(GameBoyCore* core, unsigned long long) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();
    auto dat = core->ReadData8(hl.to_ullong());

    core->getCpu()->getCpuRegisters()->setL(dat);
}

// LD L L
void Instruction::ld_l_l(GameBoyCore* core, unsigned long long) {
    auto l = core->getCpu()->getCpuRegisters()->getL();

    core->getCpu()->getCpuRegisters()->setL(l);
}

// LD L H
void Instruction::ld_l_h(GameBoyCore* core, unsigned long long) {
    auto h = core->getCpu()->getCpuRegisters()->getH();

    core->getCpu()->getCpuRegisters()->setL(h);
}

// LD L E
void Instruction::ld_l_e(GameBoyCore* core, unsigned long long) {
    auto e = core->getCpu()->getCpuRegisters()->getE();

    core->getCpu()->getCpuRegisters()->setL(e);
}

// LD L D
void Instruction::ld_l_d(GameBoyCore* core, unsigned long long) {
    auto d = core->getCpu()->getCpuRegisters()->getD();

    core->getCpu()->getCpuRegisters()->setL(d);
}

// LD L A
void Instruction::ld_l_a(GameBoyCore* core, unsigned long long) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    core->getCpu()->getCpuRegisters()->setL(a);
}

// LD (HL) L
void Instruction::ld__hl__l(GameBoyCore* core, unsigned long long) {
    auto l = core->getCpu()->getCpuRegisters()->getL();
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    core->WriteData8(hl.to_ullong(), l);
}

// LD (HL) H
void Instruction::ld__hl__h(GameBoyCore* core, unsigned long long) {
    auto h = core->getCpu()->getCpuRegisters()->getH();
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    core->WriteData8(hl.to_ullong(), h);
}

// LD (HL) E
void Instruction::ld__hl__e(GameBoyCore* core, unsigned long long) {
    auto e = core->getCpu()->getCpuRegisters()->getE();
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    core->WriteData8(hl.to_ullong(), e);
}

// LD (HL) D
void Instruction::ld__hl__d(GameBoyCore* core, unsigned long long) {
    auto d = core->getCpu()->getCpuRegisters()->getD();
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    core->WriteData8(hl.to_ullong(), d);
}

// LD (HL) C
void Instruction::ld__hl__c(GameBoyCore* core, unsigned long long) {
    auto c = core->getCpu()->getCpuRegisters()->getC();
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    core->WriteData8(hl.to_ullong(), c);
}

// LD (HL) B
void Instruction::ld__hl__b(GameBoyCore* core, unsigned long long) {
    auto b = core->getCpu()->getCpuRegisters()->getB();
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    core->WriteData8(hl.to_ullong(), b);
}

// LD A C
void Instruction::ld_a_c(GameBoyCore* core, unsigned long long) {
    auto c = core->getCpu()->getCpuRegisters()->getC();
    core->getCpu()->getCpuRegisters()->setA(c);
}

// LD A B
void Instruction::ld_a_b(GameBoyCore* core, unsigned long long) {
    auto b = core->getCpu()->getCpuRegisters()->getB();

    core->getCpu()->getCpuRegisters()->setA(b);
}

// LD (HL) A
void Instruction::ld__hl__a(GameBoyCore* core, unsigned long long) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();
    auto a  = core->getCpu()->getCpuRegisters()->getA();

    core->WriteData8(hl.to_ullong(), a);
}

// LD A A
void Instruction::ld_a_a(GameBoyCore* core, unsigned long long) {
    auto regA = core->getCpu()->getCpuRegisters()->getA();

    core->getCpu()->getCpuRegisters()->setA(regA);
}

// LD A (HL)
void Instruction::ld_a__hl_(GameBoyCore* core, unsigned long long) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();
    auto data = core->ReadData8(hl.to_ullong());

    core->getCpu()->getCpuRegisters()->setA(data);
}

// LD A L
void Instruction::ld_a_l(GameBoyCore* core, unsigned long long) {
    auto l = core->getCpu()->getCpuRegisters()->getL();
    core->getCpu()->getCpuRegisters()->setA(l);
}

// LD A H
void Instruction::ld_a_h(GameBoyCore* core, unsigned long long) {
    auto h = core->getCpu()->getCpuRegisters()->getH();
    core->getCpu()->getCpuRegisters()->setA(h);
}

// LD A E
void Instruction::ld_a_e(GameBoyCore* core, unsigned long long) {
    auto e = core->getCpu()->getCpuRegisters()->getE();
    core->getCpu()->getCpuRegisters()->setA(e);
}

// LD A D
void Instruction::ld_a_d(GameBoyCore* core, unsigned long long) {
    auto d = core->getCpu()->getCpuRegisters()->getD();
    core->getCpu()->getCpuRegisters()->setA(d);
}

// RRCA
void Instruction::rrca__(GameBoyCore* core, unsigned long long) {
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
    core->getCpu()->getFlagRegister()->setZ(a.to_ullong() == 0);
    core->getCpu()->getFlagRegister()->setN(false);
    core->getCpu()->getFlagRegister()->setH(false);
    core->getCpu()->getFlagRegister()->setC(static_cast<bool>(carry));
}

// XOR B
void Instruction::xor_b_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getB();

    auto nA = a ^ b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_xor(a, nA, core, opcode);
}

// XOR C
void Instruction::xor_c_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getC();

    auto nA = a ^ b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_xor(a, nA, core, opcode);
}

// XOR A
void Instruction::xor_a_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getA();

    auto nA = a ^ b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_xor(a, nA, core, opcode);
}

// XOR (HL)
void Instruction::xor__hl__(GameBoyCore* core, unsigned long long opcode) {
    auto hl = core->getCpu()->getCpuRegisters()->getHL();

    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->ReadData8(hl.to_ullong()).to_ullong();

    auto nA = a ^ b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_xor(a, nA, core, opcode);
}

// XOR L
void Instruction::xor_l_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getL();

    auto nA = a ^ b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_xor(a, nA, core, opcode);
}

// XOR H
void Instruction::xor_h_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getH();

    auto nA = a ^ b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_xor(a, nA, core, opcode);
}

// XOR E
void Instruction::xor_e_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getE();

    auto nA = a ^ b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_xor(a, nA, core, opcode);
}

// XOR D
void Instruction::xor_d_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();
    auto b = core->getCpu()->getCpuRegisters()->getD();

    auto nA = a ^ b;
    core->getCpu()->getCpuRegisters()->setA(nA);

    update_flags_xor(a, nA, core, opcode);
}

// XOR d8
void Instruction::xor_d8_(GameBoyCore* core, unsigned long long opcode) {
    auto a = core->getCpu()->getCpuRegisters()->getA();

    auto pc = core->getCpu()->getCpuRegisters()->getPC();
    core->getCpu()->getCpuRegisters()->setPC(pc + 1);

    auto data = core->getCpu()->getCodeLoader()->ReadBytes<1>(pc.to_ullong() + 1);
    auto nA = a ^ data;

    update_flags_xor(a, nA, core, opcode);
}

// CPL
void Instruction::cpl__(GameBoyCore* core, unsigned long long) {
    auto a = core->getCpu()->getCpuRegisters()->getA();

    core->getCpu()->getCpuRegisters()->setA(~a);

    core->getCpu()->getFlagRegister()->setN(true);
    core->getCpu()->getFlagRegister()->setH(true);
}

// RLCA
void Instruction::rlca__(GameBoyCore* core, unsigned long long) {
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
    core->getCpu()->getFlagRegister()->setZ(a.to_ullong() == 0);
    core->getCpu()->getFlagRegister()->setN(false);
    core->getCpu()->getFlagRegister()->setH(false);
    core->getCpu()->getFlagRegister()->setC(static_cast<bool>(carry));

    core->getCpu()->getCpuRegisters()->setA(a);
}

// PUSH BC
void Instruction::push_bc_(GameBoyCore* core, unsigned long long) {
    core->PushToStack(core->getCpu()->getCpuRegisters()->getBC());
}

// PUSH DE
void Instruction::push_de_(GameBoyCore* core, unsigned long long) {
    core->PushToStack(core->getCpu()->getCpuRegisters()->getDE());
}

// PUSH HL
void Instruction::push_hl_(GameBoyCore* core, unsigned long long) {
    core->PushToStack(core->getCpu()->getCpuRegisters()->getHL());
}

// PUSH AF
void Instruction::push_af_(GameBoyCore* core, unsigned long long) {
    core->PushToStack(core->getCpu()->getCpuRegisters()->getAF());
}

// INC D
void Instruction::inc_d_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getD();
    auto newVal = oldVal + 1;
    core->getCpu()->getCpuRegisters()->setD(newVal);

    update_flags_inc(oldVal, newVal, core, opcode);
}

// INC DE
void Instruction::inc_de_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getDE();
    auto newVal = oldVal + 1;
    core->getCpu()->getCpuRegisters()->setDE(newVal);

    update_flags_inc_16(oldVal, newVal, core, opcode);
}

// INC E
void Instruction::inc_e_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getE();
    auto newVal = oldVal + 1;
    core->getCpu()->getCpuRegisters()->setE(newVal);

    update_flags_inc(oldVal, newVal, core, opcode);
}

// INC H
void Instruction::inc_h_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getH();
    auto newVal = oldVal + 1;
    core->getCpu()->getCpuRegisters()->setH(newVal);

    update_flags_inc(oldVal, newVal, core, opcode);
}

// INC HL
void Instruction::inc_hl_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getHL();
    auto newVal = oldVal + 1;
    core->getCpu()->getCpuRegisters()->setHL(newVal);

    update_flags_inc_16(oldVal, newVal, core, opcode);
}

// INC L
void Instruction::inc_l_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getL();
    auto newVal = oldVal + 1;
    core->getCpu()->getCpuRegisters()->setL(newVal);

    update_flags_inc(oldVal, newVal, core, opcode);
}

// INC (HL)
void Instruction::inc__hl__(GameBoyCore* core, unsigned long long opcode) {
    auto addr = core->getCpu()->getCpuRegisters()->getHL();
    auto oldVal = core->ReadData16(addr.to_ullong());
    auto newVal = std::bitset<16>(oldVal.to_ullong() + 1);
    core->WriteData16(addr.to_ullong(), newVal);

    update_flags_inc(oldVal.to_ullong(), newVal.to_ullong(), core, opcode);
}

// INC SP
void Instruction::inc_sp_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getSP();
    auto newVal = oldVal + 1;
    core->getCpu()->getCpuRegisters()->setSP(newVal);

    update_flags_inc_16(oldVal, newVal, core, opcode);
}

// INC A
void Instruction::inc_a_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getA();
    auto newVal = oldVal + 1;
    core->getCpu()->getCpuRegisters()->setA(newVal);

    update_flags_inc(oldVal, newVal, core, opcode);
}

// INC BC
void Instruction::inc_bc_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getBC();
    auto newVal = oldVal + 1;
    core->getCpu()->getCpuRegisters()->setBC(newVal);

    update_flags_inc_16(oldVal, newVal, core, opcode);
}

// INC B
void Instruction::inc_b_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getB();
    auto newVal = oldVal + 1;
    core->getCpu()->getCpuRegisters()->setB(newVal);

    update_flags_inc(oldVal, newVal, core, opcode);
}

// INC C
void Instruction::inc_c_(GameBoyCore* core, unsigned long long opcode) {
    auto oldVal = core->getCpu()->getCpuRegisters()->getC();
    auto newVal = oldVal + 1;
    core->getCpu()->getCpuRegisters()->setC(newVal);

    update_flags_inc(oldVal, newVal, core, opcode);
}





CpuInstruction Instruction::DecodeInstruction(unsigned long long opcode) {
    static std::map<unsigned long long, CpuInstruction> instructionMap{
            {
                    0xc0, { ret_nz_, "RET NZ " }
            },
            {
                    0xc9, { ret__, "RET  " }
            },
            {
                    0xc8, { ret_z_, "RET Z " }
            },
            {
                    0xd0, { ret_nc_, "RET NC " }
            },
            {
                    0xd8, { ret_c_, "RET C " }
            },
            {
                    0x1f, { rra__, "RRA  " }
            },
            {
                    0xce, { adc_a_d8, "ADC A d8" }
            },
            {
                    0x89, { adc_a_c, "ADC A C" }
            },
            {
                    0x88, { adc_a_b, "ADC A B" }
            },
            {
                    0x8f, { adc_a_a, "ADC A A" }
            },
            {
                    0x8e, { adc_a__hl_, "ADC A (HL)" }
            },
            {
                    0x8d, { adc_a_l, "ADC A L" }
            },
            {
                    0x8c, { adc_a_h, "ADC A H" }
            },
            {
                    0x8b, { adc_a_e, "ADC A E" }
            },
            {
                    0x8a, { adc_a_d, "ADC A D" }
            },
            {
                    0x19, { add_hl_de, "ADD HL DE" }
            },
            {
                    0xc6, { add_a_d8, "ADD A d8" }
            },
            {
                    0x29, { add_hl_hl, "ADD HL HL" }
            },
            {
                    0xe8, { add_sp_r8, "ADD SP r8" }
            },
            {
                    0x39, { add_hl_sp, "ADD HL SP" }
            },
            {
                    0x09, { add_hl_bc, "ADD HL BC" }
            },
            {
                    0x87, { add_a_a, "ADD A A" }
            },
            {
                    0x86, { add_a__hl_, "ADD A (HL)" }
            },
            {
                    0x85, { add_a_l, "ADD A L" }
            },
            {
                    0x84, { add_a_h, "ADD A H" }
            },
            {
                    0x83, { add_a_e, "ADD A E" }
            },
            {
                    0x82, { add_a_d, "ADD A D" }
            },
            {
                    0x81, { add_a_c, "ADD A C" }
            },
            {
                    0x80, { add_a_b, "ADD A B" }
            },
            {
                    0xc4, { call_nz_a16, "CALL NZ a16" }
            },
            {
                    0xd4, { call_nc_a16, "CALL NC a16" }
            },
            {
                    0xcd, { call_a16_, "CALL a16 " }
            },
            {
                    0xcc, { call_z_a16, "CALL Z a16" }
            },
            {
                    0xdc, { call_c_a16, "CALL C a16" }
            },
            {
                    0xf3, { di__, "DI  " }
            },
            {
                    0xc2, { jp_nz_a16, "JP NZ a16" }
            },
            {
                    0xc3, { jp_a16_, "JP a16 " }
            },
            {
                    0xd2, { jp_nc_a16, "JP NC a16" }
            },
            {
                    0xe9, { jp__hl__, "JP (HL) " }
            },
            {
                    0xca, { jp_z_a16, "JP Z a16" }
            },
            {
                    0xda, { jp_c_a16, "JP C a16" }
            },
            {
                    0x17, { rla__, "RLA  " }
            },
            {
                    0x18, { jr_r8_, "JR r8 " }
            },
            {
                    0x20, { jr_nz_r8, "JR NZ r8" }
            },
            {
                    0x28, { jr_z_r8, "JR Z r8" }
            },
            {
                    0x30, { jr_nc_r8, "JR NC r8" }
            },
            {
                    0x38, { jr_c_r8, "JR C r8" }
            },
            {
                    0xd9, { reti__, "RETI  " }
            },
            {
                    0xe0, { ldh__a8__a, "LDH (a8) A" }
            },
            {
                    0xf0, { ldh_a__a8_, "LDH A (a8)" }
            },
            {
                    0xde, { sbc_a_d8, "SBC A d8" }
            },
            {
                    0x98, { sbc_a_b, "SBC A B" }
            },
            {
                    0x99, { sbc_a_c, "SBC A C" }
            },
            {
                    0x9f, { sbc_a_a, "SBC A A" }
            },
            {
                    0x9e, { sbc_a__hl_, "SBC A (HL)" }
            },
            {
                    0x9d, { sbc_a_l, "SBC A L" }
            },
            {
                    0x9c, { sbc_a_h, "SBC A H" }
            },
            {
                    0x9b, { sbc_a_e, "SBC A E" }
            },
            {
                    0x9a, { sbc_a_d, "SBC A D" }
            },
            {
                    0x76, { halt__, "HALT  " }
            },
            {
                    0xd6, { sub_d8_, "SUB d8 " }
            },
            {
                    0x90, { sub_b_, "SUB B " }
            },
            {
                    0x97, { sub_a_, "SUB A " }
            },
            {
                    0x96, { sub__hl__, "SUB (HL) " }
            },
            {
                    0x95, { sub_l_, "SUB L " }
            },
            {
                    0x94, { sub_h_, "SUB H " }
            },
            {
                    0x93, { sub_e_, "SUB E " }
            },
            {
                    0x92, { sub_d_, "SUB D " }
            },
            {
                    0x91, { sub_c_, "SUB C " }
            },
            {
                    0xb1, { or_c_, "OR C " }
            },
            {
                    0xb0, { or_b_, "OR B " }
            },
            {
                    0xb7, { or_a_, "OR A " }
            },
            {
                    0xb6, { or__hl__, "OR (HL) " }
            },
            {
                    0xb5, { or_l_, "OR L " }
            },
            {
                    0xb4, { or_h_, "OR H " }
            },
            {
                    0xb3, { or_e_, "OR E " }
            },
            {
                    0xb2, { or_d_, "OR D " }
            },
            {
                    0xf6, { or_d8_, "OR d8 " }
            },
            {
                    0x15, { dec_d_, "DEC D " }
            },
            {
                    0x1d, { dec_e_, "DEC E " }
            },
            {
                    0x1b, { dec_de_, "DEC DE " }
            },
            {
                    0x25, { dec_h_, "DEC H " }
            },
            {
                    0x2d, { dec_l_, "DEC L " }
            },
            {
                    0x2b, { dec_hl_, "DEC HL " }
            },
            {
                    0x35, { dec__hl__, "DEC (HL) " }
            },
            {
                    0x3b, { dec_sp_, "DEC SP " }
            },
            {
                    0x3d, { dec_a_, "DEC A " }
            },
            {
                    0x05, { dec_b_, "DEC B " }
            },
            {
                    0x0b, { dec_bc_, "DEC BC " }
            },
            {
                    0x0d, { dec_c_, "DEC C " }
            },
            {
                    0xfb, { ei__, "EI  " }
            },
            {
                    0x10, { stop_0_, "STOP 0 " }
            },
            {
                    0x27, { daa__, "DAA  " }
            },
            {
                    0x3f, { ccf__, "CCF  " }
            },
            {
                    0xb9, { cp_c_, "CP C " }
            },
            {
                    0xb8, { cp_b_, "CP B " }
            },
            {
                    0xba, { cp_d_, "CP D " }
            },
            {
                    0xbf, { cp_a_, "CP A " }
            },
            {
                    0xbe, { cp__hl__, "CP (HL) " }
            },
            {
                    0xbd, { cp_l_, "CP L " }
            },
            {
                    0xbc, { cp_h_, "CP H " }
            },
            {
                    0xbb, { cp_e_, "CP E " }
            },
            {
                    0xfe, { cp_d8_, "CP d8 " }
            },
            {
                    0x00, { nop__, "NOP  " }
            },
            {
                    0xc1, { pop_bc_, "POP BC " }
            },
            {
                    0xd1, { pop_de_, "POP DE " }
            },
            {
                    0xe1, { pop_hl_, "POP HL " }
            },
            {
                    0xf1, { pop_af_, "POP AF " }
            },
            {
                    0xc7, { rst_00h_, "RST 00H " }
            },
            {
                    0xd7, { rst_10h_, "RST 10H " }
            },
            {
                    0xe7, { rst_20h_, "RST 20H " }
            },
            {
                    0xcf, { rst_08h_, "RST 08H " }
            },
            {
                    0xf7, { rst_30h_, "RST 30H " }
            },
            {
                    0xdf, { rst_18h_, "RST 18H " }
            },
            {
                    0xef, { rst_28h_, "RST 28H " }
            },
            {
                    0xff, { rst_38h_, "RST 38H " }
            },
            {
                    0xcb, { prefix_cb_, "PREFIX CB " }
            },
            {
                    0xa0, { and_b_, "AND B " }
            },
            {
                    0xa7, { and_a_, "AND A " }
            },
            {
                    0xa6, { and__hl__, "AND (HL) " }
            },
            {
                    0xa5, { and_l_, "AND L " }
            },
            {
                    0xa4, { and_h_, "AND H " }
            },
            {
                    0xa3, { and_e_, "AND E " }
            },
            {
                    0xa2, { and_d_, "AND D " }
            },
            {
                    0xa1, { and_c_, "AND C " }
            },
            {
                    0xe6, { and_d8_, "AND d8 " }
            },
            {
                    0x37, { scf__, "SCF  " }
            },
            {
                    0x16, { ld_d_d8, "LD D d8" }
            },
            {
                    0x12, { ld__de__a, "LD (DE) A" }
            },
            {
                    0x11, { ld_de_d16, "LD DE d16" }
            },
            {
                    0x1e, { ld_e_d8, "LD E d8" }
            },
            {
                    0x1a, { ld_a__de_, "LD A (DE)" }
            },
            {
                    0x21, { ld_hl_d16, "LD HL d16" }
            },
            {
                    0x26, { ld_h_d8, "LD H d8" }
            },
            {
                    0x22, { ld__hlplus__a, "LD (HL+) A" }
            },
            {
                    0x2a, { ld_a__hlplus_, "LD A (HL+)" }
            },
            {
                    0xe2, { ld__c__a, "LD (C) A" }
            },
            {
                    0x2e, { ld_l_d8, "LD L d8" }
            },
            {
                    0x32, { ld__hlminus__a, "LD (HL-) A" }
            },
            {
                    0x31, { ld_sp_d16, "LD SP d16" }
            },
            {
                    0x36, { ld__hl__d8, "LD (HL) d8" }
            },
            {
                    0x3a, { ld_a__hlminus_, "LD A (HL-)" }
            },
            {
                    0xf2, { ld_a__c_, "LD A (C)" }
            },
            {
                    0xf9, { ld_sp_hl, "LD SP HL" }
            },
            {
                    0x3e, { ld_a_d8, "LD A d8" }
            },
            {
                    0xf8, { ld_hl_spplusr8, "LD HL SP+r8" }
            },
            {
                    0x43, { ld_b_e, "LD B E" }
            },
            {
                    0x42, { ld_b_d, "LD B D" }
            },
            {
                    0x41, { ld_b_c, "LD B C" }
            },
            {
                    0x40, { ld_b_b, "LD B B" }
            },
            {
                    0x49, { ld_c_c, "LD C C" }
            },
            {
                    0x48, { ld_c_b, "LD C B" }
            },
            {
                    0x47, { ld_b_a, "LD B A" }
            },
            {
                    0x46, { ld_b__hl_, "LD B (HL)" }
            },
            {
                    0x45, { ld_b_l, "LD B L" }
            },
            {
                    0x44, { ld_b_h, "LD B H" }
            },
            {
                    0x4c, { ld_c_h, "LD C H" }
            },
            {
                    0x4b, { ld_c_e, "LD C E" }
            },
            {
                    0x4a, { ld_c_d, "LD C D" }
            },
            {
                    0x01, { ld_bc_d16, "LD BC d16" }
            },
            {
                    0x02, { ld__bc__a, "LD (BC) A" }
            },
            {
                    0x4f, { ld_c_a, "LD C A" }
            },
            {
                    0x06, { ld_b_d8, "LD B d8" }
            },
            {
                    0x4e, { ld_c__hl_, "LD C (HL)" }
            },
            {
                    0x4d, { ld_c_l, "LD C L" }
            },
            {
                    0x08, { ld__a16__sp, "LD (a16) SP" }
            },
            {
                    0x54, { ld_d_h, "LD D H" }
            },
            {
                    0x53, { ld_d_e, "LD D E" }
            },
            {
                    0x52, { ld_d_d, "LD D D" }
            },
            {
                    0x51, { ld_d_c, "LD D C" }
            },
            {
                    0xea, { ld__a16__a, "LD (a16) A" }
            },
            {
                    0x50, { ld_d_b, "LD D B" }
            },
            {
                    0x59, { ld_e_c, "LD E C" }
            },
            {
                    0x58, { ld_e_b, "LD E B" }
            },
            {
                    0x57, { ld_d_a, "LD D A" }
            },
            {
                    0x56, { ld_d__hl_, "LD D (HL)" }
            },
            {
                    0x55, { ld_d_l, "LD D L" }
            },
            {
                    0x5d, { ld_e_l, "LD E L" }
            },
            {
                    0x5c, { ld_e_h, "LD E H" }
            },
            {
                    0x5b, { ld_e_e, "LD E E" }
            },
            {
                    0x5a, { ld_e_d, "LD E D" }
            },
            {
                    0x5f, { ld_e_a, "LD E A" }
            },
            {
                    0x5e, { ld_e__hl_, "LD E (HL)" }
            },
            {
                    0x65, { ld_h_l, "LD H L" }
            },
            {
                    0x64, { ld_h_h, "LD H H" }
            },
            {
                    0x63, { ld_h_e, "LD H E" }
            },
            {
                    0x62, { ld_h_d, "LD H D" }
            },
            {
                    0x61, { ld_h_c, "LD H C" }
            },
            {
                    0xfa, { ld_a__a16_, "LD A (a16)" }
            },
            {
                    0x60, { ld_h_b, "LD H B" }
            },
            {
                    0x0a, { ld_a__bc_, "LD A (BC)" }
            },
            {
                    0x69, { ld_l_c, "LD L C" }
            },
            {
                    0x0e, { ld_c_d8, "LD C d8" }
            },
            {
                    0x68, { ld_l_b, "LD L B" }
            },
            {
                    0x67, { ld_h_a, "LD H A" }
            },
            {
                    0x66, { ld_h__hl_, "LD H (HL)" }
            },
            {
                    0x6e, { ld_l__hl_, "LD L (HL)" }
            },
            {
                    0x6d, { ld_l_l, "LD L L" }
            },
            {
                    0x6c, { ld_l_h, "LD L H" }
            },
            {
                    0x6b, { ld_l_e, "LD L E" }
            },
            {
                    0x6a, { ld_l_d, "LD L D" }
            },
            {
                    0x6f, { ld_l_a, "LD L A" }
            },
            {
                    0x75, { ld__hl__l, "LD (HL) L" }
            },
            {
                    0x74, { ld__hl__h, "LD (HL) H" }
            },
            {
                    0x73, { ld__hl__e, "LD (HL) E" }
            },
            {
                    0x72, { ld__hl__d, "LD (HL) D" }
            },
            {
                    0x71, { ld__hl__c, "LD (HL) C" }
            },
            {
                    0x70, { ld__hl__b, "LD (HL) B" }
            },
            {
                    0x79, { ld_a_c, "LD A C" }
            },
            {
                    0x78, { ld_a_b, "LD A B" }
            },
            {
                    0x77, { ld__hl__a, "LD (HL) A" }
            },
            {
                    0x7f, { ld_a_a, "LD A A" }
            },
            {
                    0x7e, { ld_a__hl_, "LD A (HL)" }
            },
            {
                    0x7d, { ld_a_l, "LD A L" }
            },
            {
                    0x7c, { ld_a_h, "LD A H" }
            },
            {
                    0x7b, { ld_a_e, "LD A E" }
            },
            {
                    0x7a, { ld_a_d, "LD A D" }
            },
            {
                    0x0f, { rrca__, "RRCA  " }
            },
            {
                    0xa8, { xor_b_, "XOR B " }
            },
            {
                    0xa9, { xor_c_, "XOR C " }
            },
            {
                    0xaf, { xor_a_, "XOR A " }
            },
            {
                    0xae, { xor__hl__, "XOR (HL) " }
            },
            {
                    0xad, { xor_l_, "XOR L " }
            },
            {
                    0xac, { xor_h_, "XOR H " }
            },
            {
                    0xab, { xor_e_, "XOR E " }
            },
            {
                    0xaa, { xor_d_, "XOR D " }
            },
            {
                    0xee, { xor_d8_, "XOR d8 " }
            },
            {
                    0x2f, { cpl__, "CPL  " }
            },
            {
                    0x07, { rlca__, "RLCA  " }
            },
            {
                    0xc5, { push_bc_, "PUSH BC " }
            },
            {
                    0xd5, { push_de_, "PUSH DE " }
            },
            {
                    0xe5, { push_hl_, "PUSH HL " }
            },
            {
                    0xf5, { push_af_, "PUSH AF " }
            },
            {
                    0x14, { inc_d_, "INC D " }
            },
            {
                    0x13, { inc_de_, "INC DE " }
            },
            {
                    0x1c, { inc_e_, "INC E " }
            },
            {
                    0x24, { inc_h_, "INC H " }
            },
            {
                    0x23, { inc_hl_, "INC HL " }
            },
            {
                    0x2c, { inc_l_, "INC L " }
            },
            {
                    0x34, { inc__hl__, "INC (HL) " }
            },
            {
                    0x33, { inc_sp_, "INC SP " }
            },
            {
                    0x3c, { inc_a_, "INC A " }
            },
            {
                    0x03, { inc_bc_, "INC BC " }
            },
            {
                    0x04, { inc_b_, "INC B " }
            },
            {
                    0x0c, { inc_c_, "INC C " }
            }
    };


    auto it = instructionMap.find(opcode);
    if ( it == instructionMap.end() ) {
        throw std::invalid_argument("Invalid opcode!");
    }
    return it->second;
}

