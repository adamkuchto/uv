
#include "heaters.h"
#include "settings.h"
#include "tim.h"

running heating(int time, int power)
{
	if ((time < 0) || (time > 4)) return GLOBAL_ERROR;
	if ((power < 0) || (power > 3)) return GLOBAL_ERROR;

	int timeValues[] = {3, 60, 90, 120, 180};
	globalTime = 0;
	int now = globalTime + timeValues[time];

	while (now >= globalTime) {
		if(checkDoor() == OPEN) return DOOR_OPEN;
		if(checkStopButton() == STOP) return STOP;

		char buffor[16];
		sprintf(buffor,"%lis  ",	(now - globalTime));
		pcf8574_cursor(1, 9);
		pcf8574_send_string(buffor);
		// Włączenie diod UV.
	}

	return DONE;
}

