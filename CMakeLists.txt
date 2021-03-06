cmake_minimum_required(VERSION 3.8)
project(StudyBoy)

set(CMAKE_EXE_LINKER_FLAGS -static-libstdc++)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        core/memory/MemoryMap.cpp
        core/memory/MemoryMap.h
        core/cpu/Processor.cpp
        core/cpu/Processor.h
        core/GameBoyCore.cpp
        core/GameBoyCore.h
        core/input/InputDriver.cpp
        core/input/InputDriver.h
        core/input/keyboard_driver/KeyboardDriver.cpp
        core/input/keyboard_driver/KeyboardDriver.h
        core/GameBoyConfig.h
        core/cpu/components/FrequencyDivider.cpp
        core/cpu/components/FrequencyDivider.h
        core/cpu/components/Timer.cpp
        core/cpu/components/Timer.h
        core/cpu/components/DmaController.cpp
        core/cpu/components/DmaController.h
        core/lcd/LcdController.cpp
        core/lcd/LcdController.h
        core/cpu/components/Register.h
        core/cpu/DmgProcessor.cpp
        core/cpu/DmgProcessor.h
        core/cpu/ColorProcessor.cpp
        core/cpu/ColorProcessor.h
        core/cpu/components/CpuRegisters.h
        core/cpu/components/IORegisters.h
        core/cpu/codeloaders/CodeLoader.cpp
        core/cpu/codeloaders/CodeLoader.h
        core/cpu/instructions/Instruction.cpp
        core/cpu/instructions/Instruction.h
        core/RomReader.cpp
        core/RomReader.h
        core/cpu/components/IORegisters.cpp
        tests.h
        tests.cpp
        core/cpu/memory_controllers/MemoryController.cpp
        core/cpu/memory_controllers/MemoryController.h
        core/cpu/memory_controllers/Mbc1MemoryController.cpp
        core/cpu/memory_controllers/Mbc1MemoryController.h
        core/cpu/memory_controllers/Mbc2MemoryController.cpp
        core/cpu/memory_controllers/Mbc2MemoryController.h core/cpu/memory_controllers/RomOnlyMemoryController.cpp core/cpu/memory_controllers/RomOnlyMemoryController.h)

add_executable(StudyBoy ${SOURCE_FILES})

target_link_libraries(StudyBoy SDL2)
