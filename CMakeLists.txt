cmake_minimum_required(VERSION 3.8)
project(StudyBoy)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp core/memory/MemoryMap.cpp core/memory/MemoryMap.h core/cpu/Processor.cpp core/cpu/Processor.h core/GameBoyCore.cpp core/GameBoyCore.h core/input/InputDriver.cpp core/input/InputDriver.h core/input/keyboard_driver/KeyboardDriver.cpp core/input/keyboard_driver/KeyboardDriver.h core/GameBoyConfig.h)
add_executable(StudyBoy ${SOURCE_FILES})