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
#include <stdbool.h>
#include <time.h>
#include "pcf8574.h"
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
#define DisplayBrightness_Pin GPIO_PIN_0
#define DisplayBrightness_GPIO_Port GPIOA
#define StopButton_Pin GPIO_PIN_10
#define StopButton_GPIO_Port GPIOB
#define StopButton_EXTI_IRQn EXTI15_10_IRQn
#define LedInfoBlue_Pin GPIO_PIN_12
#define LedInfoBlue_GPIO_Port GPIOB
#define LedInfoRed_Pin GPIO_PIN_13
#define LedInfoRed_GPIO_Port GPIOB
#define LedInfoGreen_Pin GPIO_PIN_14
#define LedInfoGreen_GPIO_Port GPIOB
#define DoorButton_Pin GPIO_PIN_15
#define DoorButton_GPIO_Port GPIOB
#define DoorButton_EXTI_IRQn EXTI15_10_IRQn
#define TimeButton_Pin GPIO_PIN_6
#define TimeButton_GPIO_Port GPIOC
#define TimeButton_EXTI_IRQn EXTI9_5_IRQn
#define PowerButton_Pin GPIO_PIN_7
#define PowerButton_GPIO_Port GPIOC
#define PowerButton_EXTI_IRQn EXTI9_5_IRQn
#define StartButton_Pin GPIO_PIN_8
#define StartButton_GPIO_Port GPIOC
#define StartButton_EXTI_IRQn EXTI9_5_IRQn
#define Buzzer_Pin GPIO_PIN_4
#define Buzzer_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

#define DEBOUNCE 350

typedef enum {
	IDLE,
	WORKING,
	STOP,
	GLOBAL_ERROR,
	DONE,
	DOOR_OPEN
} running;

typedef enum {
	CLOSE,
	OPEN
}doorStatus;

typedef struct {
	int time;
	int power;
	running status;
	doorStatus door;
} settings;


extern uint32_t globalTime;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
