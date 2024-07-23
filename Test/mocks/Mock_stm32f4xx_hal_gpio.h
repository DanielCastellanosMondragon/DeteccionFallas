/*
 * Mock_stm32f4xx_hal_gpio.h
 *
 *  Created on: Jul 20, 2024
 *      Author: danie
 */

#ifndef MOCKS_MOCK_STM32F4XX_HAL_GPIO_H_
#define MOCKS_MOCK_STM32F4XX_HAL_GPIO_H_

#include "Mock_stm32f4xx_hal_def.h"
#include "unity.h"

/**
  * @brief  GPIO Bit SET and Bit RESET enumeration
  */
typedef enum
{
  GPIO_PIN_RESET = 0,
  GPIO_PIN_SET
}GPIO_PinState;

typedef struct
{
  uint32_t Pin;       /*!< Specifies the GPIO pins to be configured.
                           This parameter can be any value of @ref GPIO_pins_define */

  uint32_t Mode;      /*!< Specifies the operating mode for the selected pins.
                           This parameter can be a value of @ref GPIO_mode_define */

  uint32_t Pull;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
                           This parameter can be a value of @ref GPIO_pull_define */

  uint32_t Speed;     /*!< Specifies the speed for the selected pins.
                           This parameter can be a value of @ref GPIO_speed_define */

  uint32_t Alternate;  /*!< Peripheral to be connected to the selected pins.
                            This parameter can be a value of @ref GPIO_Alternate_function_selection */
}GPIO_InitTypeDef;

typedef void (* CMOCK_HAL_GPIO_Init_CALLBACK)(GPIO_TypeDef* GPIOx, GPIO_InitTypeDef* GPIO_Init, int cmock_num_calls);
#define HAL_GPIO_ReadPin_ExpectAndReturn(GPIOx, GPIO_Pin, cmock_retval) HAL_GPIO_ReadPin_CMockExpectAndReturn(__LINE__, GPIOx, GPIO_Pin, cmock_retval)
void HAL_GPIO_ReadPin_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState cmock_to_return);
typedef void (* CMOCK_HAL_GPIO_DeInit_CALLBACK)(GPIO_TypeDef* GPIOx, uint32_t GPIO_Pin, int cmock_num_calls);
typedef GPIO_PinState (* CMOCK_HAL_GPIO_ReadPin_CALLBACK)(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, int cmock_num_calls);
typedef void (* CMOCK_HAL_GPIO_WritePin_CALLBACK)(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState, int cmock_num_calls);
typedef void (* CMOCK_HAL_GPIO_TogglePin_CALLBACK)(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, int cmock_num_calls);
typedef HAL_StatusTypeDef (* CMOCK_HAL_GPIO_LockPin_CALLBACK)(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, int cmock_num_calls);
typedef void (* CMOCK_HAL_GPIO_EXTI_IRQHandler_CALLBACK)(uint16_t GPIO_Pin, int cmock_num_calls);
typedef void (* CMOCK_HAL_GPIO_EXTI_Callback_CALLBACK)(uint16_t GPIO_Pin, int cmock_num_calls);
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);

#endif /* MOCKS_MOCK_STM32F4XX_HAL_GPIO_H_ */
