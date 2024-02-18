
#ifndef INC_SETTINGS_H_
#define INC_SETTINGS_H_


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
void stopHeating();

/*
 * Włącza grzanie.
 */
void startHeating();

/*
 * Sprawdzenie zamknięcia drzwi.
 */
void checkDoor();

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

#endif /* INC_SETTINGS_H_ */
