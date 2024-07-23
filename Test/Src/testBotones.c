/*
 * testBotones.c
 *
 *  Created on: Jul 22, 2024
 *      Author: danie
 */

#include "button.h"

void test_Button_GetState_Should_ReturnPressedWhenGPIOPinIsReset_AllButtons(void)
{
	HAL_GPIO_ReadPin_ExpectAndReturn(Button0_GPIO_Port, Button0_Pin, GPIO_PIN_RESET);
    ButtonState state = Button_GetState(BUTTON_0);
    TEST_ASSERT_EQUAL(BUTTON_PRESSED, state);

    HAL_GPIO_ReadPin_ExpectAndReturn(Button0_GPIO_Port, Button1_Pin, GPIO_PIN_RESET);
	state = Button_GetState(BUTTON_1);
	TEST_ASSERT_EQUAL(BUTTON_PRESSED, state);

	HAL_GPIO_ReadPin_ExpectAndReturn(Button0_GPIO_Port, Button2_Pin, GPIO_PIN_RESET);
	state = Button_GetState(BUTTON_2);
    TEST_ASSERT_EQUAL(BUTTON_PRESSED, state);
}

void test_Button_GetState_Should_ReturnReleasedWhenGPIOPinIsSet_AllButtons(void)
{
	HAL_GPIO_ReadPin_ExpectAndReturn(Button0_GPIO_Port, Button0_Pin, GPIO_PIN_SET);
    ButtonState state = Button_GetState(BUTTON_0);
    TEST_ASSERT_EQUAL(BUTTON_RELEASED, state);

    HAL_GPIO_ReadPin_ExpectAndReturn(Button1_GPIO_Port, Button1_Pin, GPIO_PIN_SET);
	state = Button_GetState(BUTTON_1);
	TEST_ASSERT_EQUAL(BUTTON_RELEASED, state);

	HAL_GPIO_ReadPin_ExpectAndReturn(Button2_GPIO_Port, Button2_Pin, GPIO_PIN_SET);
	state = Button_GetState(BUTTON_2);
	TEST_ASSERT_EQUAL(BUTTON_RELEASED, state);
}

int botonesMain(void)
{
	RUN_TEST(test_Button_GetState_Should_ReturnPressedWhenGPIOPinIsReset_AllButtons);
	RUN_TEST(test_Button_GetState_Should_ReturnReleasedWhenGPIOPinIsSet_AllButtons);
	return 0;
}
