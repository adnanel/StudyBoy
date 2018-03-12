//
// Created by adnan on 3/11/2018.
//

#ifndef STUDYBOY_ROMONLYMEMORYCONTROLLER_H
#define STUDYBOY_ROMONLYMEMORYCONTROLLER_H


#include "MemoryController.h"

class RomOnlyMemoryController: public MemoryController {
public:
	RomOnlyMemoryController(GameBoyCore* core, RomReader* romReader);

	std::bitset<16u> ReadData16(unsigned long long targetAddress) const override;

	std::bitset<8u> ReadData8(unsigned long long targetAddress) const override;

	void WriteData8(unsigned long long address, const Register<8u> &reg) override;

	void WriteData16(unsigned long long address, const Register<16u> &reg) override;
};


#endif //STUDYBOY_ROMONLYMEMORYCONTROLLER_H
