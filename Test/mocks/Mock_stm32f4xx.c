#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "Mock_stm32f4xx.h"


static struct mock_stm32f4xxInstance
{
  unsigned char placeHolder;
} Mock;

extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_stm32f4xx_Verify(void)
{
}

void mock_stm32f4xx_Init(void)
{
  mock_stm32f4xx_Destroy();
}

void mock_stm32f4xx_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

