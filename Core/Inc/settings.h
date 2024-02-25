
#ifndef INC_SETTINGS_H_
#define INC_SETTINGS_H_

#include "main.h"

/*
 * Ustawia czas grzania.
 */
void setHeatingTime();

/*
 * Ustawia moc grzania.
 */
void setHeatingPower();

/*
 * Wyłącza grzanie.
 */
running checkStopButton();

/*
 * Włącza grzanie.
 */
void startHeating();

/*
 * Sprawdzenie zamknięcia drzwi.
 */
doorStatus checkDoor();

/*
 * Wyświetla aktuale ustawienia.
 */
void displayStatus();

/*
 * Wyświetla powitanie.
 */
void welcome();

/*
 *
 */
void idle();

/*
 * Odmierza czas zwiększając zmienną globalną co sekundę o 1.
 */
void setGlobalTime();

/*
 * Restartuje globalny czas.
 */
void restart();

#endif /* INC_SETTINGS_H_ */
