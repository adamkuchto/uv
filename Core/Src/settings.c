
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

void restart()
{
	if (settingsValue.status != DONE) return;

	settingsValue.status = STOP;
	stopLedInfo();

	pcf8574_cursor(0, 0);
	pcf8574_send_string("      STOP     ");

	idle();

	uart_buf_len = sprintf(uart_buf, "%s s\r\n", "stop");
	HAL_USART_Transmit(&husart1, (uint8_t *)uart_buf, uart_buf_len, 100);
}

void startHeating()
{

	if((checkDoor() == CLOSE) && (settingsValue.status != DONE)) {

		settingsValue.status = WORKING;
		startLedInfo();

		pcf8574_cursor(0, 0);
		pcf8574_send_string("  IN PROGRESS   ");

		uart_buf_len = sprintf(uart_buf, "%s s\r\n", "start");
		HAL_USART_Transmit(&husart1, (uint8_t *)uart_buf, uart_buf_len, 100);

		settingsValue.status = heating(settingsValue.time, settingsValue.power);


		if (settingsValue.status == DONE) {
			pcf8574_cursor(0, 0);
			pcf8574_send_string("    SUCCESS    ");
		}

		if (settingsValue.status == STOP) {
			stopLedInfo();
			pcf8574_cursor(0, 0);
			pcf8574_send_string("      STOP     ");
		}

		if (settingsValue.door == OPEN) {
			pcf8574_cursor(0, 0);
			pcf8574_send_string("  DOOR IS OPEN  ");
		}

	} else if (settingsValue.door == OPEN) {
		pcf8574_cursor(0, 0);
		pcf8574_send_string("  DOOR IS OPEN  ");

	} else
		__NOP();

}

doorStatus checkDoor()
{
	if (HAL_GPIO_ReadPin(DoorButton_GPIO_Port, DoorButton_Pin) == GPIO_PIN_SET) {
		settingsValue.door = OPEN;
		settingsValue.status = DOOR_OPEN;
	} else {
		settingsValue.door = CLOSE;
	}

	return settingsValue.door;
}

running checkStopButton()
{
	if (HAL_GPIO_ReadPin(StopButton_GPIO_Port, StopButton_Pin) == GPIO_PIN_RESET)
		settingsValue.status = STOP;

	return settingsValue.status;
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
