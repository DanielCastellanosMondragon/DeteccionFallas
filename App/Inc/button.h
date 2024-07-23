/*
 * button.h
 *
 *  Created on: Jul 19, 2024
 *      Author: danie
 */

#ifndef BUTTON_H_
#define BUTTON_H_

//#include <stdint.h>
#include "main.h"

// Button states
typedef enum {
	BUTTON_PRESSED = 0,
	BUTTON_RELEASED
} ButtonState;

typedef enum {
    BUTTON_0 = 0,
    BUTTON_1,
	BUTTON_2
} ButtonNumber;

// Function prototypes
ButtonState Button_GetState(ButtonNumber buttonNumber);
#endif /* BUTTON_H_ */
