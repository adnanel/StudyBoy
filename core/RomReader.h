//
// Created by adnan on 17/10/2017.
//

#ifndef STUDYBOY_ROMREADER_H
#define STUDYBOY_ROMREADER_H

#include <istream>
#include <fstream>
#include <iostream>

/**
https://fms.komkon.org/GameBoy/Tech/Software.html

The internal information area is located at 0100-014F in each cartridge. It contains following values:
0100-0103  A sequence of bytes 00 C3 xx xx where last two bytes contain the
           starting address of a cartridge (lower byte first). The first two
           bytes of this sequence can be used as a "magic number" to
           recognize GameBoy cartridges. When GameBoy starts, the control is
           passed to address 0100 and then the sequence is interpreted as
           NOP; JP .
0105-0133  Nintendo character area:
           CE ED 66 66 CC 0D 00 0B 03 73 00 83 00 0C 00 0D
           00 08 11 1F 88 89 00 0E DC CC 6E E6 DD DD D9 99
           BB BB 67 63 6E 0E EC CC DD DC 99 9F BB B9 33 3E
0134-0143  Title of the game in ASCII terminated by zeroes
0144-0145  Extended manufacturer code in ASCII, when 33 stored at 014B
0146       Not used
0147       Cartridge type:
           0 - ROM ONLY         3 - ROM+MBC1+RAM+BATTERY
           1 - ROM+MBC1         5 - ROM+MBC2
           2 - ROM+MBC1+RAM     6 - ROM+MBC2+BATTERY
0148       ROM size:
           0 - 256kBit =  32kB =  2 banks
           1 - 512kBit =  64kB =  4 banks
           2 -   1MBit = 128kB =  8 banks
           3 -   2MBit = 256kB = 16 banks
           4 -   4MBit = 512kB = 32 banks
0149       RAM size:
           0 - None
           1 -  16kBit =  2kB = 1 bank
           2 -  64kBit =  8kB = 1 bank
           3 - 256kBit = 32kB = 4 banks
014A       Language:
           0 - Japanese game
           1 - English game
014B       Manufacturer code:
           33 - Nintendo or extended (see 0144-0145)
           79 - Accolade
           A4 - Konami
014C       Version number
014D       Complement check
014E-014F  Checksum (higher byte first) produced by adding all bytes of
           a cartridge except for two checksum bytes together and taking
           two lower bytes of the result.
 */

enum CartidgeType {
    RomOnly = 0,
    RomMbc1 = 1,
    RomMbc1Ram = 2,
    RomMbc1RamBattery = 3,
    RomMbc2 = 5,
    RomMbc2Battery = 6
};

class RomReader {
    std::ifstream mRomFile;

public:
    std::string getGameTitle() {
        mRomFile.seekg(0x134);
        const int length = 0x143 - 0x0134;
        char str[length];
        mRomFile.read(str, length);

        return std::string(str);
    }

    CartidgeType getCartidgeType() {
        mRomFile.seekg(0x0147);
        return static_cast<CartidgeType>(mRomFile.get());
    }

    unsigned long long getCartStartAddress() {
        mRomFile.seekg(0x100);

        if ( mRomFile.get() != 0 ) throw std::invalid_argument("Invalid file!");
        if ( mRomFile.get() != 0xC3 ) throw std::invalid_argument("Invalid file!");

        int low = mRomFile.get();
        int high = mRomFile.get();

        return (static_cast<unsigned long long>(high) << 8) | low;
    }

    unsigned long long getRomSize() {
        if ( 1 < 2 ) return 100;

        mRomFile.seekg(0x148);

        auto size = mRomFile.get();
        switch ( size ) {
            case 0: return 32 * 1024;
            case 1: return 64 * 1024;
            case 2: return 128 * 1024;
            case 3: return 256 * 1024;
            case 4: return 512 * 1024;
            default:
                throw std::invalid_argument("Invalid rom size!");
        }
    }

    char* allocRomBuffer() {
        auto romSize = getRomSize();
        auto * res = new char[romSize];
        mRomFile.seekg(getCartStartAddress());

        mRomFile.read(res, romSize);

        return res;
    }

    RomReader(const char* fpath) : mRomFile(fpath) {
        if ( !mRomFile ) throw std::invalid_argument("File not found!");



        std::cout<<"Game title: "<<getGameTitle()<<std::endl;
        std::cout<<"Cartidge type: "<<getCartidgeType()<<std::endl;
        std::cout<<"Start address: "<<getCartStartAddress()<<std::endl;
        std::cout<<"Rom size (bytes): "<<getRomSize()<<std::endl;
    }
};


#endif //STUDYBOY_ROMREADER_H
