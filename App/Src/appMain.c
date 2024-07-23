/*
 * appMain.c
 *
 *  Created on: Jul 22, 2024
 *      Author: danie
 */

#include "appMain.h"

static void checkButtons(void);
void appLoop(void)
{
	while(1)
	{
		checkButtons();
	}
}

void checkButtons(void)
{
	if(Button_GetState(BUTTON_0) == BUTTON_PRESSED)
	{
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	}
	else if(Button_GetState(BUTTON_0) == BUTTON_RELEASED)
	{
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	}
	if(Button_GetState(BUTTON_1) == BUTTON_PRESSED)
	{
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	}
	else if(Button_GetState(BUTTON_1) == BUTTON_RELEASED)
	{
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	}
	if(Button_GetState(BUTTON_2) == BUTTON_PRESSED)
	{
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET);
	}
	else if(Button_GetState(BUTTON_2) == BUTTON_RELEASED)
	{
	  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);
	}
}
