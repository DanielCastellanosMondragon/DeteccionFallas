/*
 * Mock_stm32f4xx_hal_def.h
 *
 *  Created on: Jul 21, 2024
 *      Author: danie
 */

#ifndef MOCKS_MOCK_STM32F4XX_HAL_DEF_H_
#define MOCKS_MOCK_STM32F4XX_HAL_DEF_H_

#include "Mock_stm32f4xx.h"

typedef enum
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;

#endif /* MOCKS_MOCK_STM32F4XX_HAL_DEF_H_ */
