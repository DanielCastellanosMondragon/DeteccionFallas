/*
 * Mock_stm32f446xx.h
 *
 *  Created on: Jul 20, 2024
 *      Author: danie
 */

#ifndef MOCKS_MOCK_STM32F446XX_H_
#define MOCKS_MOCK_STM32F446XX_H_

#include <stdint.h>

/**
  * @brief General Purpose I/O
  */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */
typedef struct
{
  __IO uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  __IO uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  __IO uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  __IO uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  __IO uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  __IO uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  __IO uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  __IO uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  __IO uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;


#endif /* MOCKS_MOCK_STM32F446XX_H_ */
