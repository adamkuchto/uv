/*
 * leds.c
 *
 *  Created on: Dec 11, 2023
 *      Author: adam
 */
#include "leds.h"
#include "gpio.h"


void startLedInfo() {
	HAL_GPIO_WritePin(LedInfoRed_GPIO_Port, LedInfoRed_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LedInfoBlue_GPIO_Port, LedInfoBlue_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LedInfoGreen_GPIO_Port, LedInfoGreen_Pin, GPIO_PIN_RESET);
}

void stopLedInfo() {
	HAL_GPIO_WritePin(LedInfoGreen_GPIO_Port, LedInfoGreen_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LedInfoBlue_GPIO_Port, LedInfoBlue_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LedInfoRed_GPIO_Port, LedInfoRed_Pin, GPIO_PIN_RESET);
}

void idleLedInfo() {
	HAL_GPIO_WritePin(LedInfoBlue_GPIO_Port, LedInfoBlue_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(LedInfoRed_GPIO_Port, LedInfoRed_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LedInfoGreen_GPIO_Port, LedInfoGreen_Pin, GPIO_PIN_RESET);
}

