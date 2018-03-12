//
// Created by adnan on 3/7/2018.
//

#include "Mbc2MemoryController.h"

std::bitset<16u> Mbc2MemoryController::ReadData16(unsigned long long targetAddress) const {
	throw std::invalid_argument("Mbc1MemoryController::ReadData16 not implemented yet");
}

std::bitset<8u> Mbc2MemoryController::ReadData8(unsigned long long targetAddress) const {
	throw std::invalid_argument("Mbc1MemoryController::ReadData8 not implemented yet");
}

void Mbc2MemoryController::WriteData8(unsigned long long address, const Register<8u> &reg) {
	throw std::invalid_argument("Mbc1MemoryController::WriteData8 not implemented yet");
}

void Mbc2MemoryController::WriteData16(unsigned long long address, const Register<16u> &reg) {
	throw std::invalid_argument("Mbc1MemoryController::WriteData16 not implemented yet");
}
