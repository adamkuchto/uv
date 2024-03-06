
#include "heaters.h"
#include "settings.h"
#include "tim.h"
#include "leds.h"

running heating(int time, short power)
{
	char buffor[16];

	if ((time < 0) || (time > 5)) return GLOBAL_ERROR;
	if ((power < 0) || (power > 3)) return GLOBAL_ERROR;

	if (time == 5) {
		while (checkStopButton() != STOP) {
			while (checkDoor() == OPEN) {
				uvLedsOff();
				if(checkStopButton() == STOP) return STOP;
			}

			/*TODO
			 * Maksymalny czas w trybie dokładania nie dłuższy niż 5min.
			 * Odliczanie sekund w górę.
			 * Ustawienia startowe:
			 * 	- Tryb dokładania.
			 * 	- Pełna moc.
			 */
			pcf8574_cursor(1, 9);
			pcf8574_send_string("inf");
			uvLedsOn(power);
		}
		return STOP;
	} else {
		int timeValues[] = {3, 60, 90, 120, 180};
		globalTime = 0;
		int now = globalTime + timeValues[time];

		while (now >= globalTime) {
			if(checkDoor() == OPEN) return DOOR_OPEN;
			if(checkStopButton() == STOP) return STOP;

			sprintf(buffor,"%lis  ", (now - globalTime));
			pcf8574_cursor(1, 9);
			pcf8574_send_string(buffor);
			uvLedsOn(power);
		}
	}


	return DONE;
}

