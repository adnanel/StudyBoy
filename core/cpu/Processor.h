//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_PROCESSOR_H
#define STUDYBOY_PROCESSOR_H


#include "../memory/MemoryMap.h"
#include "components/FrequencyDivider.h"
#include "components/Timer.h"
#include "components/DmaController.h"

class Processor {
private:
    // 127 * 8 bits of built in RAM (working and stack)
    MemoryMap mRam;
    // 16 stage frequency divider
    FrequencyDivider mFrequencyDivider;
    // 8 bit timer
    Timer mTimer;
    // DMA controller
    DmaController mDmaController;
};


#endif //STUDYBOY_PROCESSOR_H
