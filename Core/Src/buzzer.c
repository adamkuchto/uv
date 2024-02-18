
#include "buzzer.h"
#include "tim.h"
#include "main.h"

void ring()
{
	int now = globalTime + START_TIMING;

	while (now > globalTime) {
		__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 300);
	}
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
}

