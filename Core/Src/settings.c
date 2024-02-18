
#include "settings.h"
#include "main.h"
#include "leds.h"
#include "usart.h"
#include "buzzer.h"
#include "heaters.h"
#include <stdio.h>

settings settingsValue;
uint32_t globalTime = 0;

int timeOfHeating[] = {30, 60, 90, 120, 180};
char uart_buf[50];
int uart_buf_len;

void setHeatingTime()
{

	if(settingsValue.status == WORKING) return;
	idle();

	settingsValue.time++;
	if (settingsValue.time > 4) settingsValue.time = 0;

	pcf8574_cursor(0, 0);
	pcf8574_send_string("    Set Time    ");

	uart_buf_len = sprintf(uart_buf, "Time: %d s\r\n", timeOfHeating[settingsValue.time]);
	HAL_USART_Transmit(&husart1, (uint8_t *)uart_buf, uart_buf_len, 100);
}

void setHeatingPower()
{

	if(settingsValue.status == WORKING) return;
	idle();

	pcf8574_cursor(0, 0);
	pcf8574_send_string("    Set Power   ");

	settingsValue.power++;
	if (settingsValue.power > 2) settingsValue.power = 0;

	uart_buf_len = sprintf(uart_buf, "%s s\r\n", "power");
	HAL_USART_Transmit(&husart1, (uint8_t *)uart_buf, uart_buf_len, 100);
}

void stopHeating()
{
	if (settingsValue.status != WORKING) return;

	settingsValue.status = STOP;
	stopLedInfo();
	ring();

	pcf8574_cursor(0, 0);
	pcf8574_send_string("      STOP     ");

	idle();

	uart_buf_len = sprintf(uart_buf, "%s s\r\n", "stop");
	HAL_USART_Transmit(&husart1, (uint8_t *)uart_buf, uart_buf_len, 100);
}

void startHeating()
{

	checkDoor();

	if((settingsValue.door == false) && (settingsValue.status != WORKING)) {
		settingsValue.status = WORKING;
		startLedInfo();
		ring();

		pcf8574_cursor(0, 0);
		pcf8574_send_string("  IN PROGRESS   ");

		uart_buf_len = sprintf(uart_buf, "%s s\r\n", "start");
		HAL_USART_Transmit(&husart1, (uint8_t *)uart_buf, uart_buf_len, 100);

		if (heating(settingsValue.time, settingsValue.power) == GLOBAL_ERROR)
			settingsValue.status = GLOBAL_ERROR;
		else {
			pcf8574_cursor(0, 0);
			pcf8574_send_string("    SUCCESS    ");
		}

	} else if (settingsValue.door == true) {
		pcf8574_cursor(0, 0);
		pcf8574_send_string("  DOOR IS OPEN  ");
	} else
		__NOP();

}

void checkDoor()
{
	if (HAL_GPIO_ReadPin(DoorButton_GPIO_Port, DoorButton_Pin) == GPIO_PIN_SET) {
		settingsValue.door = true;
		settingsValue.status = DOOR_OPEN;
	} else {
		settingsValue.door = false;
	}
}

void displayStatus()
{
	char buffor[16];
	char level[3] = {'L', 'M', 'H'};
	sprintf(buffor,"P: %c  T: %is  ", level[settingsValue.power], timeOfHeating[settingsValue.time]);
	pcf8574_cursor(1, 0);
	pcf8574_send_string(buffor);
}

void idle()
{
	idleLedInfo();
	settingsValue.status = IDLE;

}

void welcome()
{
	pcf8574_cursor(0, 0);
	pcf8574_send_string(" UV HEATER V1.0");
	pcf8574_cursor(1, 3);
	pcf8574_send_string("HELLO :)");
}

void setGlobalTime()
{
		globalTime++;
		globalTime &= UINT32_MAX;
}
