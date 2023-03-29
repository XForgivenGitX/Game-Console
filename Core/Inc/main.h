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
#include "stm32f1xx_hal.h"

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
#define LCD_nCS_Pin GPIO_PIN_13
#define LCD_nCS_GPIO_Port GPIOC
#define LCD_RS_Pin GPIO_PIN_14
#define LCD_RS_GPIO_Port GPIOC
#define LCD_nWR_Pin GPIO_PIN_15
#define LCD_nWR_GPIO_Port GPIOC
#define LCD_nRD_Pin GPIO_PIN_6
#define LCD_nRD_GPIO_Port GPIOA
#define LED_Pin GPIO_PIN_7
#define LED_GPIO_Port GPIOA
#define DB0_Pin GPIO_PIN_0
#define DB0_GPIO_Port GPIOB
#define DB1_Pin GPIO_PIN_1
#define DB1_GPIO_Port GPIOB
#define DB2_Pin GPIO_PIN_2
#define DB2_GPIO_Port GPIOB
#define LEDA15_Pin GPIO_PIN_15
#define LEDA15_GPIO_Port GPIOA
#define DB3_Pin GPIO_PIN_3
#define DB3_GPIO_Port GPIOB
#define DB4_Pin GPIO_PIN_4
#define DB4_GPIO_Port GPIOB
#define DB4_EXTI_IRQn EXTI4_IRQn
#define DB5_Pin GPIO_PIN_5
#define DB5_GPIO_Port GPIOB
#define DB5_EXTI_IRQn EXTI9_5_IRQn
#define DB6_Pin GPIO_PIN_6
#define DB6_GPIO_Port GPIOB
#define DB6_EXTI_IRQn EXTI9_5_IRQn
#define DB7_Pin GPIO_PIN_7
#define DB7_GPIO_Port GPIOB
#define DB7_EXTI_IRQn EXTI9_5_IRQn
#define LCD_nRESET_Pin GPIO_PIN_9
#define LCD_nRESET_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
