/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    button.c
  * @brief   This file provides code for button interrupt handling
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "button.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

// Global button event flag
volatile bool buttonPressed = false;

// Timestamp of last button press for debouncing
static volatile uint32_t lastButtonPressTime = 0;

/* USER CODE BEGIN 1 */

// Initialize button interrupt
void buttonInit(void) {
    // Button is already configured by STM32CubeMX on PC13 as GPIO input with EXTI
    // This function can be used for additional initialization if needed
    lastButtonPressTime = 0;
    buttonPressed = false;
}

// Clear the button pressed flag
void buttonClearFlag(void) {
    buttonPressed = false;
}

// Get button pressed state
bool buttonIsPressed(void) { 
    if (HAL_GPIO_ReadPin(USER_BTN_GPIO_Port, USER_BTN_Pin) == GPIO_PIN_RESET) {
      buttonPressed = true;
    }; // Check if button is currently pressed (active low)
    return buttonPressed;
}

bool buttonIsDown(void) {
  return (HAL_GPIO_ReadPin(USER_BTN_GPIO_Port, USER_BTN_Pin) == GPIO_PIN_RESET) ? true : false;
}

// EXTI interrupt handler for USER_BTN (PC13)
// This should be called from the main HAL EXTI callback
// void HAL_GPIO_EXTI_Callback_enough(uint16_t GPIO_Pin) {
//     if (GPIO_Pin == USER_BTN_Pin) {
//         uint32_t currentTime = HAL_GetTick();
        
//         // Debounce: ignore if interrupt occurred within BUTTON_DEBOUNCE_TIME_MS
//         if ((currentTime - lastButtonPressTime) >= BUTTON_DEBOUNCE_TIME_MS) {
//             // Check if button is actually pressed (low on PC13)
//             if (HAL_GPIO_ReadPin(USER_BTN_GPIO_Port, USER_BTN_Pin) == GPIO_PIN_RESET) {
//                 buttonPressed = true;
//                 lastButtonPressTime = currentTime;
//             }
//         }
//     }
// }

/* USER CODE END 1 */