//
// Created by adnan on 14/10/2017.
//

#ifndef STUDYBOY_GAMEBOYCONFIG_H
#define STUDYBOY_GAMEBOYCONFIG_H

#include <cstdio>
#include <fstream>

struct GameBoyConfig {
    size_t displayMemorySize;
    size_t workMemorySize;

    static GameBoyConfig FromFile(const char* fpath) {
        std::ifstream istream(fpath);

        //todo
    }
};



#endif //STUDYBOY_GAMEBOYCONFIG_H
