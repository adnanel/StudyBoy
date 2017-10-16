#include <iostream>
#include "core/GameBoyConfig.h"
#include "core/GameBoyCore.h"
#include "core/RomReader.h"

int main() {
    GameBoyConfig testConfig;
    testConfig.displayMemorySize = 8 * 1024;
    testConfig.workMemorySize = 8 * 1024;
    testConfig.clockSpeed = 5 * 1000 * 1000;

    GameBoyCore core(testConfig);

    // Privremeno dok je u test fazi...

    RomReader reader("C:/Users/adnan/CLionProjects/StudyBoy/roms/Bounce.gb");


    core.getCpu()->setCodeLoader(new CodeLoader(reader.allocRomBuffer(), reader.getRomSize()));

    for ( int i = 0; i < 50; ++ i ) {
        core.Step();
    }

    return 0;
}