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

void uvLedsOn(short mode) {
	switch (mode) {
	case 0:
		HAL_GPIO_WritePin(UvPanel1_GPIO_Port, UvPanel1_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(UvPanel1_GPIO_Port, UvPanel1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(UvPanel2_GPIO_Port, UvPanel2_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(UvPanel1_GPIO_Port, UvPanel1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(UvPanel2_GPIO_Port, UvPanel2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(UvPanel3_GPIO_Port, UvPanel3_Pin, GPIO_PIN_SET);
		break;
	default:
		__NOP();
		break;
	}
}

/*
 * Wyłącza diody uv.
 */
void uvLedsOff() {
	HAL_GPIO_WritePin(UvPanel1_GPIO_Port, UvPanel1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(UvPanel2_GPIO_Port, UvPanel2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(UvPanel3_GPIO_Port, UvPanel3_Pin, GPIO_PIN_RESET);
}
