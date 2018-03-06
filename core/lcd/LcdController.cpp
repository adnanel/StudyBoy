//
// Created by adnan on 14/10/2017.
//

#include <iomanip>
#include "LcdController.h"

LcdController::LcdController(GameBoyCore *core) : mCore(core) {

}

void LcdController::SetScreenEnabled(bool enable) {

}


void LcdController::Step() {
    // todo take into account SCX and SCY registers for scrolling. See chapter 2 page 51

    auto lcdc = mCore->getCpu()->getIORegisters()->getFF40();

    // todo - replace true with CGB/DMG check, should be ( isDMG || lcdc[0] )
    if ( true || lcdc[0] ) {
        // ----- BG Display --------
        std::cout << "----\n";
        // note - 144x144 (18x18 blocks) is the visible grid. 256x256 (32x32 blocks) is the memory allocated grid
        // 1 block = 8x8 px
        for (auto i = 0; i < 32; ++i) {
            for (auto j = 0; j < 32; ++j) {
                const unsigned long long offset = lcdc[4] ? 0x9C00 : 0x9800;

                const auto &reg = mCore->ReadData8(offset + i * 32 + j);

                // todo for CGB read the ATTR data from the other memory bank

                std::cout << std::setw(3) << reg.to_ullong() << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "----\n";
    }


}

void LcdController::setStatus(int status) {
    assert(status >= 0 && status < 4 );
    auto reg = mCore->getCpu()->getIORegisters()->getFF41();
    reg[1] = status >= 2;
    reg[0] = status == 1 || status == 3;
    mCore->getCpu()->getIORegisters()->setFF41(reg);
}

int LcdController::getStatus() const {
    auto reg = mCore->getCpu()->getIORegisters()->getFF41();
    return reg[0] | (reg[1] << 1);
};

