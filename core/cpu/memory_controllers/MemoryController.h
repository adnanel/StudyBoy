//
// Created by adnan on 3/7/2018.
//

#ifndef STUDYBOY_MEMORYCONTROLLER_H
#define STUDYBOY_MEMORYCONTROLLER_H


#include <bitset>
#include "../components/Register.h"
#include "../../RomReader.h"

class GameBoyCore;
class RomReader;

class MemoryController {
protected:
	GameBoyCore* mCore;
	RomReader* mRomReader;
public:
	explicit MemoryController(GameBoyCore* core, RomReader* reader) : mCore(core), mRomReader(reader) {}

	virtual ~MemoryController() = default;

	virtual std::bitset<16u> ReadData16(unsigned long long targetAddress) const = 0;
	virtual std::bitset<8u> ReadData8(unsigned long long targetAddress) const = 0;

	virtual void WriteData8(unsigned long long address, const Register<8u>& reg) = 0;
	virtual void WriteData16(unsigned long long address, const Register<16u>& reg) = 0;
};

MemoryController* MakeMemoryControllerForCartidgeType(GameBoyCore* core, RomReader* type);
#endif //STUDYBOY_MEMORYCONTROLLER_H
