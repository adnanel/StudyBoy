//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_GAMEBOYCORE_H
#define STUDYBOY_GAMEBOYCORE_H


#include "memory/MemoryMap.h"
#include "cpu/Processor.h"

class GameBoyCore {
private:
    MemoryMap mWorkRam;
    MemoryMap mDisplayRam;

    Processor mCpu;
};


#endif //STUDYBOY_GAMEBOYCORE_H
