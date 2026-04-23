/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    notecard.h
  * @brief   This file contains the function prototypes for
  *          the notecard.c file
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
#ifndef __NOTECARD_H__
#define __NOTECARD_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include <math.h>

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

const char* noteCardCheckInit(void);
const char* noteCardInitialize(char *projectName, char* stationName);
const char *sendMeasure(uint16_t adc, uint8_t reading, float_t turbidityValue);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __NOTECARD_H__ */