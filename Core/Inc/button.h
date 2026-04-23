/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    button.h
  * @brief   This file contains the function prototypes for
  *          the button.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __BUTTON_H__
#define __BUTTON_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <stdbool.h>

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

#define BUTTON_DEBOUNCE_TIME_MS 50  // Debounce time in milliseconds

/* USER CODE END Private defines */

// Global button event flag - set to true when button press detected
extern volatile bool buttonPressed;

// Initialize button interrupt
void buttonInit(void);

// Clear the button pressed flag
void buttonClearFlag(void);

// Get button pressed state
bool buttonIsPressed(void);

// Get current button state (true if currently pressed, false if not)
bool buttonIsDown(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __BUTTON_H__ */