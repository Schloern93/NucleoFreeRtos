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
#set(STM32_CHIP STM32G491RE)

# Compiler-Flags (angepasst für STM32)
set(CMAKE_C_FLAGS "-mcpu=cortex-m4 -mthumb -Wall -O0 -ffunction-sections -fdata-sections -g")


#set(CMAKE_EXE_LINKER_FLAGS "-Wl,--gc-sections -T${CMAKE_SOURCE_DIR}/linker/STM32G491RETX_FLASH.ld")


# Includepfade für HAL und CMSIS
include_directories(
    #${CMAKE_SOURCE_DIR}/config
    ${CMAKE_SOURCE_DIR}/libs/stm32g4xx-hal-driver/Inc
    ${CMAKE_SOURCE_DIR}/libs/CMSIS/Device/ST/STM32G4xx/Include
    ${CMAKE_SOURCE_DIR}/libs/CMSIS/Core/Include
)

# Hauptquelle hinzufügen
add_executable(${PROJECT_NAME} 
    linker/startup_stm32g491xx.s
    linker/system_stm32g4xx.c
    linker/syscalls.c
    linker/sysmem.c
    # libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal.c
    # libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_cortex.c
    # libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_gpio.c 
    # libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_flash.c
    # libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_dma.c
    # libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_tim.c   
    # libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_rcc.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_adc.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_adc_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_comp.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_cordic.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_cortex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_crc.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_crc_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_cryp.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_cryp_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_dac.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_dac_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_dma.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_dma_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_exti.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_fdcan.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_flash.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_flash_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_flash_ramfunc.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_fmac.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_gpio.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_hrtim.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_i2c.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_i2c_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_i2s.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_irda.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_iwdg.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_lptim.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_msp_template.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_nand.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_nor.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_opamp.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_opamp_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_pcd.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_pcd_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_pwr.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_pwr_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_qspi.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_rcc.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_rcc_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_rng.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_rtc.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_rtc_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_sai.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_sai_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_smartcard.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_smartcard_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_smbus.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_smbus_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_spi.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_spi_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_sram.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_tim.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_tim_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_timebase_tim_template.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_uart.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_uart_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_usart.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_usart_ex.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_hal_wwdg.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_adc.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_comp.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_cordic.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_crc.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_crs.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_dac.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_dma.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_exti.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_fmac.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_fmc.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_gpio.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_hrtim.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_i2c.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_lptim.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_lpuart.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_opamp.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_pwr.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_rcc.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_rng.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_rtc.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_spi.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_tim.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_ucpd.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_usart.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_usb.c
    libs/stm32g4xx-hal-driver/Src/stm32g4xx_ll_utils.c
    src/main.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".elf")


# HAL-Bibliothek verlinken
#target_link_libraries(${PROJECT_NAME} STM32G4xx_HAL_Driver)

target_link_options(${PROJECT_NAME} PRIVATE 
    -T${CMAKE_SOURCE_DIR}/linker/STM32G491RETX_FLASH.ld
   # -Wl,--gc-sections
)
# Füge dies in die CMakeLists.txt ein, um die .map-Datei zu generieren
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-Map=output.map")

