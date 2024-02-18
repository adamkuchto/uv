
#include "heaters.h"
#include "settings.h"
#include "tim.h"

running heating(int time, int power)
{
	if ((time < 0) || (time > 4)) return GLOBAL_ERROR;
	if ((power < 0) || (power > 3)) return GLOBAL_ERROR;

	int timeValues[] = {30, 60, 90, 120, 180};

	int now = globalTime + timeValues[time];

	while (now > globalTime) {
		if(HAL_GPIO_ReadPin(StopButton_GPIO_Port, StopButton_Pin) == GPIO_PIN_RESET) {
			return STOP;
		}
		// Włączenie diod UV.
	}

	return OK;
}
