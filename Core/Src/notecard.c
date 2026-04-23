/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    notecard.c
  * @brief   This file provides code for the Notecard interface
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
#include "main.h"
#include "notecard.h"
#include "note.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>


/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* USER CODE BEGIN 1 */

// Notecard interface functions

// Check if Notecard is initialized and responding
const char* noteCardCheckInit(void) {
    // Send a simple request to check if Notecard is responding
    J *rsp = NoteRequestResponse(NoteNewRequest("card.version"));
    if (rsp == NULL) {
        return "Failed to get response from Notecard";
    }

    // Check if we got a valid response with version field
    if (!JIsObject(rsp) || JGetString(rsp, "version") == NULL) {
        NoteDeleteResponse(rsp);
        return "Invalid response from Notecard";
    }

    NoteDeleteResponse(rsp);
    return NULL; // Success
}

// Initialize Notecard with project and station information
const char* noteCardInitialize(char *projectName, char* stationName) {
    // Set up the hub configuration
    J *req = NoteNewRequest("hub.set");
    if (req == NULL) {
        return "Failed to create request";
    }

    // Set the product ID (project name)
    if (projectName && projectName[0]) {
        JAddStringToObject(req, "product", projectName);
    }

    // Set mode to continuous for live demo
    JAddStringToObject(req, "mode", "continuous");

    // Send the request
    if (!NoteRequest(req)) {
        return "Failed to send hub.set request";
    }

    // Optionally set station name or other configuration
    // This could be extended to set additional parameters

    return NULL; // Success
}

// Send a measurement to Notehub
const char* sendMeasure(uint16_t adc, uint8_t reading, float_t turbidityValue) {
    // Create a note with the measurement data
    J *req = NoteNewRequest("note.add");
    if (req == NULL) {
        return "Failed to create note request";
    }

    // Sync immediately so we can see the data in Notehub without delay
    JAddBoolToObject(req, "sync", true);

    // Create the body of the note
    J *body = JCreateObject();
    if (body == NULL) {
        JDelete(req);
        return "Failed to create note body";
    }

    // Add timestamp (current time in milliseconds)
    JAddNumberToObject(body, "timestamp", (JNUMBER)HAL_GetTick());

    // Add the body to the request
    JAddItemToObject(req, "body", body);

    J *turbidity = JCreateObject();
    if (turbidity == NULL) {
      JDelete(req);
      return "Failed to create note turbidity";
    }

    // Add measurement data
    JAddNumberToObject(turbidity, "adc_value", adc);
    JAddNumberToObject(turbidity, "reading", reading);
    JAddNumberToObject(turbidity, "value", turbidityValue);

    // Add turbidity to the body
    JAddItemToObject(body, "turbidity", turbidity);

    // Send the request
    if (!NoteRequest(req)) {
        return "Failed to send note.add request";
    }

    return NULL; // Success
}

/* USER CODE END 1 */