/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l4xx_hal.h"
#include "stm32l4xx_ll_tim.h"
#include "stm32l4xx_ll_usart.h"
#include "stm32l4xx_ll_rcc.h"
#include "stm32l4xx_ll_system.h"
#include "stm32l4xx_ll_gpio.h"
#include "stm32l4xx_ll_exti.h"
#include "stm32l4xx_ll_bus.h"
#include "stm32l4xx_ll_cortex.h"
#include "stm32l4xx_ll_utils.h"
#include "stm32l4xx_ll_pwr.h"
#include "stm32l4xx_ll_dma.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define B1_Pin LL_GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define B1_EXTI_IRQn EXTI15_10_IRQn
#define LSE_IN_Pin LL_GPIO_PIN_14
#define LSE_IN_GPIO_Port GPIOC
#define LSE_OUT_Pin LL_GPIO_PIN_15
#define LSE_OUT_GPIO_Port GPIOC
#define Trigger_Pin LL_GPIO_PIN_1
#define Trigger_GPIO_Port GPIOA
#define DBG_TX_Pin LL_GPIO_PIN_2
#define DBG_TX_GPIO_Port GPIOA
#define DBG_RX_Pin LL_GPIO_PIN_3
#define DBG_RX_GPIO_Port GPIOA
#define Echo_Pin LL_GPIO_PIN_4
#define Echo_GPIO_Port GPIOA
#define LD2_Pin LL_GPIO_PIN_5
#define LD2_GPIO_Port GPIOA
#define COL_1_Pin LL_GPIO_PIN_10
#define COL_1_GPIO_Port GPIOB
#define COL_1_EXTI_IRQn EXTI15_10_IRQn
#define COL_4_Pin LL_GPIO_PIN_7
#define COL_4_GPIO_Port GPIOC
#define COL_4_EXTI_IRQn EXTI9_5_IRQn
#define COL_2_Pin LL_GPIO_PIN_8
#define COL_2_GPIO_Port GPIOA
#define COL_2_EXTI_IRQn EXTI9_5_IRQn
#define COL_3_Pin LL_GPIO_PIN_9
#define COL_3_GPIO_Port GPIOA
#define COL_3_EXTI_IRQn EXTI9_5_IRQn
#define ROW_1_Pin LL_GPIO_PIN_10
#define ROW_1_GPIO_Port GPIOA
#define TMS_Pin LL_GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin LL_GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define ROW_2_Pin LL_GPIO_PIN_3
#define ROW_2_GPIO_Port GPIOB
#define ROW_4_Pin LL_GPIO_PIN_4
#define ROW_4_GPIO_Port GPIOB
#define ROW_3_Pin LL_GPIO_PIN_5
#define ROW_3_GPIO_Port GPIOB
#define NET_TX_Pin LL_GPIO_PIN_6
#define NET_TX_GPIO_Port GPIOB
#define NET_RX_Pin LL_GPIO_PIN_7
#define NET_RX_GPIO_Port GPIOB
#define OLED_SCL_Pin LL_GPIO_PIN_8
#define OLED_SCL_GPIO_Port GPIOB
#define OLED_SDA_Pin LL_GPIO_PIN_9
#define OLED_SDA_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
