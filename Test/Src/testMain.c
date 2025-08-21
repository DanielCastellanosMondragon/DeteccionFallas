/*
 * testMain.c
 *
 *  Created on: Jul 19, 2024
 *      Author: Daniel Castellanos
 */

#include "unity.h"
#include "appMain.h"
#include "testMain.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

void setUp(void)
{
	HAL_GPIO_WritePin_StubWithCallback(HAL_GPIO_WritePinStub);
}
void tearDown(void)
{

}
void testPass(void)
{
    TEST_ASSERT_TRUE(appReturnTrue());
}

static void CMock_Verify(void)
{
  mock_stm32f4xx_hal_gpio_Verify();
  mock_stm32f4xx_hal_adc_Verify();
  mock_stm32f4xx_hal_tim_Verify();
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(testPass);
    CMock_Verify();
    return UNITY_END();
}
