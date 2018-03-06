//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_LCDCONTROLLER_H
#define STUDYBOY_LCDCONTROLLER_H


#include "../GameBoyCore.h"

class GameBoyCore;

class LcdController {
private:
    GameBoyCore* mCore;

public:
    LcdController(GameBoyCore* core);

    void SetScreenEnabled(bool enable);
    void Step();


    inline int getStatus() const;
    inline void setStatus(int status);
};


#endif //STUDYBOY_LCDCONTROLLER_H
