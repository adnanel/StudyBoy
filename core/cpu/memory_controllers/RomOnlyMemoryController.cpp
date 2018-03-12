//
// Created by adnan on 3/11/2018.
//

#include "RomOnlyMemoryController.h"

RomOnlyMemoryController::RomOnlyMemoryController(GameBoyCore *core, RomReader* reader)
		: MemoryController(core, reader) {}

std::bitset<16u> RomOnlyMemoryController::ReadData16(unsigned long long targetAddress) const {
	throw std::invalid_argument("RomOnlyMemoryController::ReadData16 not yet implemented");
}

std::bitset<8u> RomOnlyMemoryController::ReadData8(unsigned long long targetAddress) const {
	throw std::invalid_argument("RomOnlyMemoryController::ReadData8 not yet implemented");
}

void RomOnlyMemoryController::WriteData8(unsigned long long address, const Register<8u> &reg) {
	throw std::invalid_argument("RomOnlyMemoryController::WriteData8 not yet implemented");
}

void RomOnlyMemoryController::WriteData16(unsigned long long address, const Register<16u> &reg) {
	throw std::invalid_argument("RomOnlyMemoryController::WriteData16 not yet implemented");
}
