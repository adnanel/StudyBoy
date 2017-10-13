#include <iostream>
#include "core/GameBoyConfig.h"
#include "core/GameBoyCore.h"

int main() {
    GameBoyConfig testConfig;
    testConfig.displayMemorySize = 8 * 1024;
    testConfig.workMemorySize = 8 * 1024;

    GameBoyCore core(testConfig);


    return 0;
}