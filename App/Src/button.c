/*
 * button.c
 *
 *  Created on: Jul 19, 2024
 *      Author: danie
 */

#include "button.h"

ButtonState Button_GetState(ButtonNumber buttonNumber)
{
	ButtonState state;
	if(buttonNumber == BUTTON_0)
	{
		state = (ButtonState)HAL_GPIO_ReadPin(Button0_GPIO_Port, Button0_Pin);
	}
	else if(buttonNumber == BUTTON_1)
	{
		state = (ButtonState)HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
	}
	else if(buttonNumber == BUTTON_2)
	{
		state = (ButtonState)HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
	}
	return state;
}
