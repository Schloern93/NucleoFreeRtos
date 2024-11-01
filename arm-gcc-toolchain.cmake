# Toolchain Datei für ARM-GCC
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Cross-Compiler
set(CMAKE_C_COMPILER arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER arm-none-eabi-g++)
set(CMAKE_ASM_COMPILER arm-none-eabi-gcc)

# Pfade zu den Toolchain-Binärdateien (optional, falls nicht im PATH)
#set(CMAKE_C_COMPILER "C:/Path/To/Your/arm-none-eabi-gcc/bin/arm-none-eabi-gcc.exe")
#set(CMAKE_CXX_COMPILER "C:/Path/To/Your/arm-none-eabi-gcc/bin/arm-none-eabi-g++.exe")
