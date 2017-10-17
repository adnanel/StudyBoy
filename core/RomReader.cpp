//
// Created by adnan on 17/10/2017.
//

#include "RomReader.h"


std::ostream& operator<<(std::ostream& stream, CartidgeType type) {
    switch ( type ) {
        case RomOnly:
            stream<<"ROM ONLY";
            break;
        case RomMbc1:
            stream<<"ROM + MBC1";
            break;
        case RomMbc1Ram:
            stream<<"ROM + MBC1 + RAM";
            break;
        case RomMbc1RamBattery:
            stream<<"ROM + MBC1 + RAM + BATTERY";
            break;
        case RomMbc2:
            stream<<"ROM + MBC2";
            break;
        case RomMbc2Battery:
            stream<<"ROM + MBC";
            break;
        default:
            stream<<"N/A";
            break;
    }

    return stream;
}


std::ostream& operator<<(std::ostream& stream, CartidgeLanguage lang) {
    switch ( lang ) {
        case Japanese:
            stream<<"Japanese";
            break;
        case English:
            stream<<"English";
            break;
        default:
            stream<<"N/A";
    }
    return stream;
}

