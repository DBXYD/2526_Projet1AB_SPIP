/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32g4xx_hal.h"

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
#define US_TRIG_Pin GPIO_PIN_0
#define US_TRIG_GPIO_Port GPIOA
#define US_ECHO_INT_Pin GPIO_PIN_1
#define US_ECHO_INT_GPIO_Port GPIOA
#define UART_STLINK_TX_Pin GPIO_PIN_2
#define UART_STLINK_TX_GPIO_Port GPIOA
#define UART_STLINK_RX_Pin GPIO_PIN_3
#define UART_STLINK_RX_GPIO_Port GPIOA
#define X1_INT_Pin GPIO_PIN_4
#define X1_INT_GPIO_Port GPIOA
#define X2_INT_Pin GPIO_PIN_5
#define X2_INT_GPIO_Port GPIOA
#define X3_INT_Pin GPIO_PIN_6
#define X3_INT_GPIO_Port GPIOA
#define X4_INT_Pin GPIO_PIN_7
#define X4_INT_GPIO_Port GPIOA
#define UART_XL320_Pin GPIO_PIN_4
#define UART_XL320_GPIO_Port GPIOC
#define MotorFault_Pin GPIO_PIN_10
#define MotorFault_GPIO_Port GPIOB
#define USR_BTN_3_Pin GPIO_PIN_12
#define USR_BTN_3_GPIO_Port GPIOB
#define USR_BTN_2_Pin GPIO_PIN_13
#define USR_BTN_2_GPIO_Port GPIOB
#define USR_BTN_1_Pin GPIO_PIN_14
#define USR_BTN_1_GPIO_Port GPIOB
#define USR_LED_3_Pin GPIO_PIN_15
#define USR_LED_3_GPIO_Port GPIOB
#define USR_LED_2_Pin GPIO_PIN_6
#define USR_LED_2_GPIO_Port GPIOC
#define USR_LED_1_Pin GPIO_PIN_8
#define USR_LED_1_GPIO_Port GPIOA
#define MotorB_PWM_Reverse_Pin GPIO_PIN_10
#define MotorB_PWM_Reverse_GPIO_Port GPIOA
#define MotorA_PWM_Forward_Pin GPIO_PIN_15
#define MotorA_PWM_Forward_GPIO_Port GPIOA
#define MotorA_ENC_A_Pin GPIO_PIN_4
#define MotorA_ENC_A_GPIO_Port GPIOB
#define MotorA_ENC_B_Pin GPIO_PIN_5
#define MotorA_ENC_B_GPIO_Port GPIOB
#define MotorB_ENC_A_Pin GPIO_PIN_6
#define MotorB_ENC_A_GPIO_Port GPIOB
#define MotorB_ENC_B_Pin GPIO_PIN_7
#define MotorB_ENC_B_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
