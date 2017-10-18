#include <iostream>
#include <chrono>

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

    // RomReader reader("C:\\Users\\prg01\\CLionProjects\\StudyBoy\\roms\\Bounce.gb");
    RomReader reader("C:\\Users\\adnan\\CLionProjects\\StudyBoy\\roms\\Bounce.gb");

    while ( 1 ) {
        try {
            core.Step();
            // core.CheckForInterrupts();
        } catch ( const std::invalid_argument& ex ) {
            std::cout<<std::endl;
            std::cout<<ex.what();
            break;
        } catch ( const std::exception& ex ) {
            std::cout<<std::endl<<"SHIET "<<ex.what();
            break;
        }
    }
    core.PrintRegisters();

    return 0;
}