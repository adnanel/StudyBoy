//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_GAMEBOYCORE_H
#define STUDYBOY_GAMEBOYCORE_H


#include "memory/MemoryMap.h"
#include "cpu/Processor.h"
#include "GameBoyConfig.h"

class GameBoyCore {
private:
    MemoryMap mWorkRam;
    MemoryMap mDisplayRam;

    Processor mCpu;

public:
    GameBoyCore(const GameBoyConfig& gbConfig);
    ~GameBoyCore();
};


#endif //STUDYBOY_GAMEBOYCORE_H
