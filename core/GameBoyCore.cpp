//
// Created by adnan on 14/10/2017.
//

#include "GameBoyCore.h"

GameBoyCore::GameBoyCore(const GameBoyConfig& gbConfig)
    : mWorkRam(gbConfig.workMemorySize),
      mDisplayRam(gbConfig.displayMemorySize)
{

}

GameBoyCore::~GameBoyCore() {

}
