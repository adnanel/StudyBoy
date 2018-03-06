#include <iostream>
#include <chrono>

#include "core/GameBoyConfig.h"
#include "core/GameBoyCore.h"
#include "core/RomReader.h"
#include "core/cpu/instructions/Instruction.h"

int main() {
    GameBoyConfig gameBoyClassicConfig;
    gameBoyClassicConfig.displayMemorySize = 8 * 1024;
    gameBoyClassicConfig.workMemorySize = 8 * 1024;
    gameBoyClassicConfig.clockSpeed = 5 * 1000 * 1000;

    GameBoyConfig gameBoyColorConfig;
    gameBoyClassicConfig.displayMemorySize = 16 * 1024;
    gameBoyClassicConfig.workMemorySize = 8 * 1024; // todo update
    gameBoyClassicConfig.clockSpeed = 5 * 1000 * 1000; // todo update

    GameBoyCore core(gameBoyClassicConfig);

    // Privremeno dok je u test fazi...

    RomReader reader("C:\\Stuff\\Projects\\StudyBoy\\roms\\helloworld.gb");
    // RomReader reader("C:\\Users\\adnan\\CLionProjects\\StudyBoy\\roms\\Bounce.gb");


    core.getCpu()->setCodeLoader(new CodeLoader(reader.allocRomBuffer(), reader.getRomSize()));

    while ( true ) {
        try {
            core.Step();
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