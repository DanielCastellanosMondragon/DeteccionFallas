#ifndef _MOCK_STM32F4XX_H
#define _MOCK_STM32F4XX_H

#include "unity.h"

#if defined(STM32F411xE)
#include "Mock_stm32f411xe.h"
#elif defined(STM32F446xx)
#include "Mock_stm32f446xx.h"
#else
#error "Please select first the target STM32F4xx device used in your application (in stm32f4xx.h file)"
#endif

#define __IO volatile

typedef enum
{
  DISABLE = 0U,
  ENABLE = !DISABLE
} FunctionalState;

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

#ifdef __cplusplus
extern "C" {
#endif

void mock_stm32f4xx_Init(void);
void mock_stm32f4xx_Destroy(void);
void mock_stm32f4xx_Verify(void);





#ifdef __cplusplus
}
#endif

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
