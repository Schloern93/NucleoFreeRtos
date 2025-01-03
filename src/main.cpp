
#include "stm32g4xx_hal.h" 
#include <cstdio>


// HardFault Handler
extern "C"  void HardFault_Handler(void)
{
    // Stack-Frames der betroffenen Register auslesen
    uint32_t* stacked_r0  = (uint32_t*) 0x2001BFC8;  // Beispieladresse für den Stack
    uint32_t* stacked_r1  = stacked_r0 + 1;
    uint32_t* stacked_r2  = stacked_r0 + 2;
    uint32_t* stacked_r3  = stacked_r0 + 3;
    uint32_t* stacked_r12 = stacked_r0 + 4;
    uint32_t* stacked_lr  = stacked_r0 + 5;
    uint32_t* stacked_pc  = stacked_r0 + 6;
    uint32_t* stacked_xpsr = stacked_r0 + 7;

    // Ausgabe der Registerwerte für Debugging (z.B. auf UART)
    printf("HardFault detected!\n");
    printf("R0: %lx, R1: %lx, R2: %lx, R3: %lx\n", *stacked_r0, *stacked_r1, *stacked_r2, *stacked_r3);
    printf("R12: %lx, LR: %lx, PC: %lx, xPSR: %lx\n", *stacked_r12, *stacked_lr, *stacked_pc, *stacked_xpsr);

    // Optional: Fehlerbehandlung oder Reset durchführen
    while(1) {
        // Im Fehlerfall in einer Endlosschleife bleiben
    }
}

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
    //__HAL_RCC_WWDG_CLK_DISABLE();
    GPIO_Init();
   


    while (1) {
        HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);  // Toggle LED an Pin 5
        HAL_Delay(1000);  // 1 Sekunde warten
    }
}






