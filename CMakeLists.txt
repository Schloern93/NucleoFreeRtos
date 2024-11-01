# Mindestanforderungen an CMake-Version
cmake_minimum_required(VERSION 3.15)

# Projektname und Sprache
project(BlinkExample LANGUAGES C CXX)

# STM32CubeG4 Library hinzufügen
add_subdirectory(libs/STM32CubeG4)

# Definiere das Board (STM32G491)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)
set(STM32_CHIP STM32G491RE)

# Compiler-Flags (angepasst für STM32)
set(CMAKE_C_FLAGS "-mcpu=cortex-m4 -mthumb -Wall -O2 -ffunction-sections -fdata-sections")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections")

# Includepfade für HAL und CMSIS
include_directories(
    libs/STM32G4xx_HAL_Driver/Inc
    libs/CMSIS/Device/ST/STM32G4xx/Include  # Beispielpfad für CMSIS, ggf. anpassen
    libs/CMSIS/Core/Include                  # Beispielpfad für CMSIS, ggf. anpassen
)

# Hauptquelle hinzufügen
add_executable(${PROJECT_NAME} src/main.c)

# HAL-Bibliothek verlinken
target_link_libraries(${PROJECT_NAME} STM32G4xx_HAL_Driver)

# Linker Options
target_link_options(${PROJECT_NAME} PRIVATE -T linker/STM32G491RE_FLASH.ld)