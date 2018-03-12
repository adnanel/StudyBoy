//
// Created by adnan on 3/7/2018.
//

#ifndef STUDYBOY_MBC1MEMORYCONTROLLER_H
#define STUDYBOY_MBC1MEMORYCONTROLLER_H


#include "MemoryController.h"

class Mbc1MemoryController: public MemoryController {
public:
	Mbc1MemoryController(GameBoyCore* core, RomReader* romReader): MemoryController(core, romReader) {}

	std::bitset<16u> ReadData16(unsigned long long targetAddress) const override;

	std::bitset<8u> ReadData8(unsigned long long targetAddress) const override;

	void WriteData8(unsigned long long address, const Register<8u> &reg) override;

	void WriteData16(unsigned long long address, const Register<16u> &reg) override;
};


#endif //STUDYBOY_MBC1MEMORYCONTROLLER_H
