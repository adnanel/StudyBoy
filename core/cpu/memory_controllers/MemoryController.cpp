//
// Created by adnan on 3/7/2018.
//

#include "MemoryController.h"
#include "Mbc2MemoryController.h"
#include "Mbc1MemoryController.h"
#include "RomOnlyMemoryController.h"


MemoryController* MakeMemoryControllerForCartidgeType(GameBoyCore* core, RomReader* reader) {
	switch ( reader->getCartidgeType()  ) {
		case RomOnly:
			return new RomOnlyMemoryController(core, reader);
		case RomMbc1:
		case RomMbc1Ram:
		case RomMbc1RamBattery:
			return new Mbc1MemoryController(core, reader);
		case RomMbc2:
		case RomMbc2Battery:
			return new Mbc2MemoryController(core, reader);
		default:
			throw std::invalid_argument("Unsupported cartidge type!");
	}
}

