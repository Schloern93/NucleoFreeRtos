# Mindestanforderungen an CMake-Version
cmake_minimum_required(VERSION 3.15)

# Set CMake to create a static library instead of an executable during compiler tests
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

# Toolchain Datei für ARM-GCC
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Projektname und Sprache
project(BlinkExample LANGUAGES C CXX ASM)
add_definitions(-DSTM32G491xx)

# STM32CubeG4 Library hinzufügen
# add_subdirectory(libs/CMSIS)
# add_subdirectory(libs/stm32g4xx-hal-driver)

# Definiere das Board (STM32G491)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(STM32_CHIP STM32G491RE)

# Compiler-Flags (angepasst für STM32)
set(CMAKE_C_FLAGS "-mcpu=cortex-m4 -mthumb -Wall -O0 -ffunction-sections -fdata-sections -g")


#set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections -T${CMAKE_SOURCE_DIR}/linker/STM32G491RETX_FLASH.ld")


# Includepfade für HAL und CMSIS
include_directories(
    ${CMAKE_SOURCE_DIR}/config
    ${CMAKE_SOURCE_DIR}/libs/stm32g4xx-hal-driver/Inc
    ${CMAKE_SOURCE_DIR}/libs/CMSIS/Device/ST/STM32G4xx/Include
    ${CMAKE_SOURCE_DIR}/libs/CMSIS/Core/Include
)

# Hauptquelle hinzufügen
add_executable(${PROJECT_NAME} 
    linker/startup_stm32g491xx.s
    linker/system_stm32g4xx.c     
    src/main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".elf")


# HAL-Bibliothek verlinken
#target_link_libraries(${PROJECT_NAME} STM32G4xx_HAL_Driver)

target_link_options(${PROJECT_NAME} PRIVATE 
    -T${CMAKE_SOURCE_DIR}/linker/STM32G491RETX_FLASH.ld
    -Wl,--gc-sections
)
