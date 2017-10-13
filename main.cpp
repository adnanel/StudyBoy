#include <iostream>
#include "core/GameBoyConfig.h"
#include "core/GameBoyCore.h"

int main() {
    GameBoyConfig testConfig;
    testConfig.displayMemorySize = 64 * 1024;
    testConfig.workMemorySize = 64 * 1024;

    GameBoyCore core(testConfig);


    return 0;
}