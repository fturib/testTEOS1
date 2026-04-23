/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    measure.c
  * @brief   This file provides code for measurement handling
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
#include "measure.h"
#include "usart.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* USER CODE BEGIN 1 */

// Initialize the random number generator
void initMeasure(void) {
    // Seed the random generator with current system tick
    srand(HAL_GetTick());
}

// Get a random measurement value (0-255) and output to UART2
uint8_t getMeasure(void) {
    // Generate random number between 0 and 255
    uint8_t measurement = (uint8_t)(rand() % 256);
    
    // Format and send the measurement via UART2
    char buffer[64];
    sprintf(buffer, "Measure: %u\r\n", measurement);
    HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), HAL_MAX_DELAY);
    
    return measurement;
}

/* USER CODE END 1 */