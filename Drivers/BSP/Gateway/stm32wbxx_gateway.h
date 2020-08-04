/** 
  ******************************************************************************
  * @file    stm32wbxx_nucleo.h
  * @author  MCD Application Team
  * @brief   This file contains definitions for:
  *          - LEDs and push-button available on STM32WBXX-Nucleo Kit 
  *            from STMicroelectronics
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics. 
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the 
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32WBXX_NUCLEO_H
#define __STM32WBXX_NUCLEO_H

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup BSP
  * @{
  */

/** @addtogroup STM32WBXX_NUCLEO
  * @{
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32wbxx_hal.h"
   
/** @defgroup STM32WBXX_NUCLEO_Exported_Types Exported Types
  * @{
  */
typedef enum 
{
  LED1 = 0,
  LED2 = 1,
  LED3 = 2,
  /* Color led aliases */
  LED_BLUE   = LED1,
  LED_GREEN  = LED2,
  LED_RED    = LED3
}Led_TypeDef;

typedef enum 
{  
  BUTTON_SW1 = 0,
  BUTTON_SW2 = 1,
  BUTTON_SW3 = 2,
}Button_TypeDef;

typedef enum 
{  
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
}ButtonMode_TypeDef;


/** @defgroup  LED Constants
  * @{
  */
#define LEDn                                    3

#define LED1_PIN                                GPIO_PIN_5
#define LED1_GPIO_PORT                          GPIOB
#define LED1_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED1_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOB_CLK_ENABLE()

#define LED2_PIN                                GPIO_PIN_0
#define LED2_GPIO_PORT                          GPIOB
#define LED2_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED2_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOB_CLK_ENABLE()

#define LED3_PIN                                GPIO_PIN_1
#define LED3_GPIO_PORT                          GPIOB
#define LED3_GPIO_CLK_ENABLE()                  __HAL_RCC_GPIOB_CLK_ENABLE()
#define LED3_GPIO_CLK_DISABLE()                 __HAL_RCC_GPIOB_CLK_ENABLE()

#define LEDx_GPIO_CLK_ENABLE(__INDEX__)         __HAL_RCC_GPIOB_CLK_ENABLE() /* All Led on same port */
#define LEDx_GPIO_CLK_DISABLE(__INDEX__)        __HAL_RCC_GPIOB_CLK_ENABLE() /* All Led on same port */
/**
  * @}
  */ 
  
/** @defgroup  BUTTON Constants
  * @{
  */  
#define BUTTONn                                 3

/**
 * @brief Key push-button
 */
#define BUTTON_SW1_PIN                          GPIO_PIN_4
#define BUTTON_SW1_GPIO_PORT                    GPIOC
#define BUTTON_SW1_GPIO_CLK_ENABLE()            __HAL_RCC_GPIOC_CLK_ENABLE()
#define BUTTON_SW1_GPIO_CLK_DISABLE()           __HAL_RCC_GPIOC_CLK_DISABLE()
#define BUTTON_SW1_EXTI_LINE                    GPIO_PIN_4
#ifdef CORE_CM0PLUS
#define BUTTON_SW1_EXTI_IRQn                    EXTI15_4_IRQn
#else
#define BUTTON_SW1_EXTI_IRQn                    EXTI4_IRQn
#endif

#define BUTTON_SW2_PIN                          GPIO_PIN_0
#define BUTTON_SW2_GPIO_PORT                    GPIOD
#define BUTTON_SW2_GPIO_CLK_ENABLE()            __HAL_RCC_GPIOD_CLK_ENABLE()
#define BUTTON_SW2_GPIO_CLK_DISABLE()           __HAL_RCC_GPIOD_CLK_DISABLE()
#define BUTTON_SW2_EXTI_LINE                    GPIO_PIN_0
#ifdef CORE_CM0PLUS
#define BUTTON_SW2_EXTI_IRQn                    EXTI1_0_IRQn
#else
#define BUTTON_SW2_EXTI_IRQn                    EXTI0_IRQn
#endif

#define BUTTON_SW3_PIN                          GPIO_PIN_1
#define BUTTON_SW3_GPIO_PORT                    GPIOD
#define BUTTON_SW3_GPIO_CLK_ENABLE()            __HAL_RCC_GPIOD_CLK_ENABLE()
#define BUTTON_SW3_GPIO_CLK_DISABLE()           __HAL_RCC_GPIOD_CLK_DISABLE()
#define BUTTON_SW3_EXTI_LINE                    GPIO_PIN_1
#ifdef CORE_CM0PLUS
#define BUTTON_SW3_EXTI_IRQn                    EXTI1_0_IRQn
#else
#define BUTTON_SW3_EXTI_IRQn                    EXTI1_IRQn
#endif

#define BUTTONx_GPIO_CLK_ENABLE(__INDEX__)    do { if ((__INDEX__) == BUTTON_SW1) BUTTON_SW1_GPIO_CLK_ENABLE(); else \
                                              if ((__INDEX__) == BUTTON_SW2) BUTTON_SW2_GPIO_CLK_ENABLE(); else \
                                              if ((__INDEX__) == BUTTON_SW3) BUTTON_SW3_GPIO_CLK_ENABLE();} while(0)

#define BUTTONx_GPIO_CLK_DISABLE(__INDEX__)    do { if ((__INDEX__) == BUTTON_SW1) BUTTON_SW1_GPIO_CLK_DISABLE(); else \
                                              if ((__INDEX__) == BUTTON_SW2) BUTTON_SW2_GPIO_CLK_DISABLE(); else \
                                              if ((__INDEX__) == BUTTON_SW3) BUTTON_SW3_GPIO_CLK_DISABLE();} while(0)

																							uint32_t         BSP_GetVersion(void);  

/** @addtogroup LED_Functions
  * @{
  */
void             BSP_LED_Init(Led_TypeDef Led);
void             BSP_LED_DeInit(Led_TypeDef Led);
void             BSP_LED_On(Led_TypeDef Led);
void             BSP_LED_Off(Led_TypeDef Led);
void             BSP_LED_Toggle(Led_TypeDef Led);


/** @addtogroup BUTTON_Functions
  * @{
  */
void             BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef ButtonMode);
void             BSP_PB_DeInit(Button_TypeDef Button);
uint32_t         BSP_PB_GetState(Button_TypeDef Button);



#ifdef __cplusplus
}
#endif

#endif /* __STM32WBXX_NUCLEO_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
