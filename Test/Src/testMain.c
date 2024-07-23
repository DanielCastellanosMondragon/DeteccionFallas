/*
 * testMain.c
 *
 *  Created on: Jul 19, 2024
 *      Author: Daniel Castellanos
 */

#include "unity.h"
#include "appMain.h"

void testPass(void)
{
    TEST_ASSERT_TRUE(appReturnTrue());
}
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(testPass);
    return UNITY_END();
}
