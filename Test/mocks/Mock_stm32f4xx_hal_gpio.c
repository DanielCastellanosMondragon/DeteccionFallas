/*
 * Mock_stm32f4xx_hal_gpio.c
 *
 *  Created on: Jul 20, 2024
 *      Author: danie
 */


#include "Mock_stm32f4xx_hal_gpio.h"
#include <string.h>

static const char* CMockString_GPIO_Pin = "GPIO_Pin";
static const char* CMockString_GPIOx = "GPIOx";
static const char* CMockString_HAL_GPIO_ReadPin = "HAL_GPIO_ReadPin";
static const char* CMockString_HAL_GPIO_WritePin = "HAL_GPIO_WritePin";
static const char* CMockString_PinState = "PinState";

typedef struct _CMOCK_HAL_GPIO_WritePin_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  GPIO_TypeDef* Expected_GPIOx;
  uint16_t Expected_GPIO_Pin;
  GPIO_PinState Expected_PinState;

} CMOCK_HAL_GPIO_WritePin_CALL_INSTANCE;

typedef struct _CMOCK_HAL_GPIO_ReadPin_CALL_INSTANCE
{
  UNITY_LINE_TYPE LineNumber;
  GPIO_PinState ReturnVal;
  GPIO_TypeDef* Expected_GPIOx;
  uint16_t Expected_GPIO_Pin;

} CMOCK_HAL_GPIO_ReadPin_CALL_INSTANCE;

static struct Mockstm32f4xx_hal_gpioInstance
{
  char HAL_GPIO_Init_IgnoreBool;
  char HAL_GPIO_Init_CallbackBool;
  CMOCK_HAL_GPIO_Init_CALLBACK HAL_GPIO_Init_CallbackFunctionPointer;
  int HAL_GPIO_Init_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE HAL_GPIO_Init_CallInstance;
  char HAL_GPIO_DeInit_IgnoreBool;
  char HAL_GPIO_DeInit_CallbackBool;
  CMOCK_HAL_GPIO_DeInit_CALLBACK HAL_GPIO_DeInit_CallbackFunctionPointer;
  int HAL_GPIO_DeInit_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE HAL_GPIO_DeInit_CallInstance;
  char HAL_GPIO_ReadPin_IgnoreBool;
  GPIO_PinState HAL_GPIO_ReadPin_FinalReturn;
  char HAL_GPIO_ReadPin_CallbackBool;
  CMOCK_HAL_GPIO_ReadPin_CALLBACK HAL_GPIO_ReadPin_CallbackFunctionPointer;
  int HAL_GPIO_ReadPin_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE HAL_GPIO_ReadPin_CallInstance;
  char HAL_GPIO_WritePin_IgnoreBool;
  char HAL_GPIO_WritePin_CallbackBool;
  CMOCK_HAL_GPIO_WritePin_CALLBACK HAL_GPIO_WritePin_CallbackFunctionPointer;
  int HAL_GPIO_WritePin_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE HAL_GPIO_WritePin_CallInstance;
  char HAL_GPIO_TogglePin_IgnoreBool;
  char HAL_GPIO_TogglePin_CallbackBool;
  CMOCK_HAL_GPIO_TogglePin_CALLBACK HAL_GPIO_TogglePin_CallbackFunctionPointer;
  int HAL_GPIO_TogglePin_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE HAL_GPIO_TogglePin_CallInstance;
  char HAL_GPIO_LockPin_IgnoreBool;
  HAL_StatusTypeDef HAL_GPIO_LockPin_FinalReturn;
  char HAL_GPIO_LockPin_CallbackBool;
  CMOCK_HAL_GPIO_LockPin_CALLBACK HAL_GPIO_LockPin_CallbackFunctionPointer;
  int HAL_GPIO_LockPin_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE HAL_GPIO_LockPin_CallInstance;
  char HAL_GPIO_EXTI_IRQHandler_IgnoreBool;
  char HAL_GPIO_EXTI_IRQHandler_CallbackBool;
  CMOCK_HAL_GPIO_EXTI_IRQHandler_CALLBACK HAL_GPIO_EXTI_IRQHandler_CallbackFunctionPointer;
  int HAL_GPIO_EXTI_IRQHandler_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE HAL_GPIO_EXTI_IRQHandler_CallInstance;
  char HAL_GPIO_EXTI_Callback_IgnoreBool;
  char HAL_GPIO_EXTI_Callback_CallbackBool;
  CMOCK_HAL_GPIO_EXTI_Callback_CALLBACK HAL_GPIO_EXTI_Callback_CallbackFunctionPointer;
  int HAL_GPIO_EXTI_Callback_CallbackCalls;
  CMOCK_MEM_INDEX_TYPE HAL_GPIO_EXTI_Callback_CallInstance;
} Mock;


void CMockExpectParameters_HAL_GPIO_ReadPin(CMOCK_HAL_GPIO_ReadPin_CALL_INSTANCE* cmock_call_instance, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
void CMockExpectParameters_HAL_GPIO_ReadPin(CMOCK_HAL_GPIO_ReadPin_CALL_INSTANCE* cmock_call_instance, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  cmock_call_instance->Expected_GPIOx = GPIOx;
  cmock_call_instance->Expected_GPIO_Pin = GPIO_Pin;
}

void HAL_GPIO_ReadPin_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState cmock_to_return)
{
  CMOCK_MEM_INDEX_TYPE cmock_guts_index = CMock_Guts_MemNew(sizeof(CMOCK_HAL_GPIO_ReadPin_CALL_INSTANCE));
  CMOCK_HAL_GPIO_ReadPin_CALL_INSTANCE* cmock_call_instance = (CMOCK_HAL_GPIO_ReadPin_CALL_INSTANCE*)CMock_Guts_GetAddressFor(cmock_guts_index);
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringOutOfMemory);
  memset(cmock_call_instance, 0, sizeof(*cmock_call_instance));
  Mock.HAL_GPIO_ReadPin_CallInstance = CMock_Guts_MemChain(Mock.HAL_GPIO_ReadPin_CallInstance, cmock_guts_index);
  Mock.HAL_GPIO_ReadPin_IgnoreBool = (char)0;
  cmock_call_instance->LineNumber = cmock_line;
  CMockExpectParameters_HAL_GPIO_ReadPin(cmock_call_instance, GPIOx, GPIO_Pin);
  memcpy((void*)(&cmock_call_instance->ReturnVal), (void*)(&cmock_to_return),
         sizeof(GPIO_PinState[sizeof(cmock_to_return) == sizeof(GPIO_PinState) ? 1 : -1])); /* add GPIO_PinState to :treat_as_array if this causes an error */
}

GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_HAL_GPIO_ReadPin_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_HAL_GPIO_ReadPin);
  cmock_call_instance = (CMOCK_HAL_GPIO_ReadPin_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.HAL_GPIO_ReadPin_CallInstance);
  Mock.HAL_GPIO_ReadPin_CallInstance = CMock_Guts_MemNext(Mock.HAL_GPIO_ReadPin_CallInstance);
  if (Mock.HAL_GPIO_ReadPin_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    if (cmock_call_instance == NULL)
      return Mock.HAL_GPIO_ReadPin_FinalReturn;
    memcpy((void*)(&Mock.HAL_GPIO_ReadPin_FinalReturn), (void*)(&cmock_call_instance->ReturnVal),
         sizeof(GPIO_PinState[sizeof(cmock_call_instance->ReturnVal) == sizeof(GPIO_PinState) ? 1 : -1])); /* add GPIO_PinState to :treat_as_array if this causes an error */
    return cmock_call_instance->ReturnVal;
  }
  if (!Mock.HAL_GPIO_ReadPin_CallbackBool &&
      Mock.HAL_GPIO_ReadPin_CallbackFunctionPointer != NULL)
  {
    GPIO_PinState cmock_cb_ret = Mock.HAL_GPIO_ReadPin_CallbackFunctionPointer(GPIOx, GPIO_Pin, Mock.HAL_GPIO_ReadPin_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return cmock_cb_ret;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_HAL_GPIO_ReadPin,CMockString_GPIOx);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_GPIOx), (void*)(GPIOx), sizeof(GPIO_TypeDef), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_HAL_GPIO_ReadPin,CMockString_GPIO_Pin);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_GPIO_Pin, GPIO_Pin, cmock_line, CMockStringMismatch);
  }
  if (Mock.HAL_GPIO_ReadPin_CallbackFunctionPointer != NULL)
  {
    cmock_call_instance->ReturnVal = Mock.HAL_GPIO_ReadPin_CallbackFunctionPointer(GPIOx, GPIO_Pin, Mock.HAL_GPIO_ReadPin_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
  return cmock_call_instance->ReturnVal;
}

void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
  UNITY_LINE_TYPE cmock_line = TEST_LINE_NUM;
  CMOCK_HAL_GPIO_WritePin_CALL_INSTANCE* cmock_call_instance;
  UNITY_SET_DETAIL(CMockString_HAL_GPIO_WritePin);
  cmock_call_instance = (CMOCK_HAL_GPIO_WritePin_CALL_INSTANCE*)CMock_Guts_GetAddressFor(Mock.HAL_GPIO_WritePin_CallInstance);
  Mock.HAL_GPIO_WritePin_CallInstance = CMock_Guts_MemNext(Mock.HAL_GPIO_WritePin_CallInstance);
  if (Mock.HAL_GPIO_WritePin_IgnoreBool)
  {
    UNITY_CLR_DETAILS();
    return;
  }
  if (!Mock.HAL_GPIO_WritePin_CallbackBool &&
      Mock.HAL_GPIO_WritePin_CallbackFunctionPointer != NULL)
  {
    Mock.HAL_GPIO_WritePin_CallbackFunctionPointer(GPIOx, GPIO_Pin, PinState, Mock.HAL_GPIO_WritePin_CallbackCalls++);
    UNITY_CLR_DETAILS();
    return;
  }
  UNITY_TEST_ASSERT_NOT_NULL(cmock_call_instance, cmock_line, CMockStringCalledMore);
  cmock_line = cmock_call_instance->LineNumber;
  {
    UNITY_SET_DETAILS(CMockString_HAL_GPIO_WritePin,CMockString_GPIOx);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(cmock_call_instance->Expected_GPIOx), (void*)(GPIOx), sizeof(GPIO_TypeDef), cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_HAL_GPIO_WritePin,CMockString_GPIO_Pin);
    UNITY_TEST_ASSERT_EQUAL_HEX16(cmock_call_instance->Expected_GPIO_Pin, GPIO_Pin, cmock_line, CMockStringMismatch);
  }
  {
    UNITY_SET_DETAILS(CMockString_HAL_GPIO_WritePin,CMockString_PinState);
    UNITY_TEST_ASSERT_EQUAL_MEMORY((void*)(&cmock_call_instance->Expected_PinState), (void*)(&PinState), sizeof(GPIO_PinState), cmock_line, CMockStringMismatch);
  }
  if (Mock.HAL_GPIO_WritePin_CallbackFunctionPointer != NULL)
  {
    Mock.HAL_GPIO_WritePin_CallbackFunctionPointer(GPIOx, GPIO_Pin, PinState, Mock.HAL_GPIO_WritePin_CallbackCalls++);
  }
  UNITY_CLR_DETAILS();
}
