# Mindestanforderungen an CMake-Version
cmake_minimum_required(VERSION 3.15)

# Set CMake to create a static library instead of an executable during compiler tests
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

# Projektname und Sprache
project(BlinkExample LANGUAGES C CXX)
add_definitions(-DSTM32G491xx)

# STM32CubeG4 Library hinzufügen
# add_subdirectory(libs/CMSIS)
# add_subdirectory(libs/stm32g4xx-hal-driver)

# Definiere das Board (STM32G491)
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
#set(CMAKE_ASM_COMPILER C:\Toolchain\arm-gnu-toolchain-13.3.rel1-mingw-w64-i686-arm-none-eabi\bin\arm-none-eabi-gcc)
set(STM32_CHIP STM32G491RE)

# Compiler-Flags (angepasst für STM32)
set(CMAKE_C_FLAGS "-mcpu=cortex-m4 -mthumb -Wall -O2 -ffunction-sections -fdata-sections")
set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections -T${CMAKE_SOURCE_DIR}/linker/STM32G491RETX_FLASH.ld")

# Includepfade für HAL und CMSIS
include_directories(
    libs/STM32G4xx_HAL_Driver/Inc
    libs/CMSIS/Device/ST/STM32G4xx/Include  # Beispielpfad für CMSIS, ggf. anpassen
    libs/CMSIS/Core/Include                  # Beispielpfad für CMSIS, ggf. anpassen
)

# Hauptquelle hinzufügen
add_executable(${PROJECT_NAME} 
    linker/syscalls.c
    linker/sysmem.c
    linker/system_stm32g4xx.c   
    src/main.cpp
    linker/startup_stm32g491xx.s
)

set_target_properties(BlinkExample PROPERTIES SUFFIX ".elf")


# HAL-Bibliothek verlinken
target_link_libraries(${PROJECT_NAME} STM32G4xx_HAL_Driver)

# Linker Options
#set(CMAKE_EXE_LINKER_FLAGS "")

#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -T${CMAKE_SOURCE_DIR}/linker/STM32G491RETX_FLASH.ld -Wl,--gc-sections")

# target_link_options(${PROJECT_NAME} PRIVATE 
#     -T linker/STM32G491RETX_FLASH.ld
# )