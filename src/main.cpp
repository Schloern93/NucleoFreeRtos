#include "stm32g4xx_hal.h"
#include <cstdio>




// Funktion zur Initialisierung der GPIO
void GPIO_Init()
{
    GPIO_InitTypeDef GPIO_InitStruct = {};
    __HAL_RCC_GPIOA_CLK_ENABLE();  // Enable clock for GPIOA

    GPIO_InitStruct.Pin = GPIO_PIN_5;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;  // Push-pull output
    GPIO_InitStruct.Pull = GPIO_NOPULL;          // No pull-up or pull-down resistors
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);      // Initialize GPIOA pin 5
}

int main(void)
{
    //Reset of all peripherals, Initializes the Flash interface and the Systick.
    HAL_Init();
    __HAL_RCC_WWDG_CLK_DISABLE();
    GPIO_Init();
   


    while (1) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);  // Toggle LED an Pin 5
        HAL_Delay(1000);  // 1 Sekunde warten
    }
}






