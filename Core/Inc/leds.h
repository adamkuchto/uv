/*
 * leds.h
 *
 *  Created on: Dec 11, 2023
 *      Author: adam
 */

#ifndef INC_LEDS_H_
#define INC_LEDS_H_

/*
 * Włącza czerwoną diodę.
 */
void startLedInfo();

/*
 * Włącza zieloną diodę.
 */
void stopLedInfo();

/*
 * Włącza niebieską diodę.
 */
void idleLedInfo();

/*
 * Włącza diody uv.
 * @param[in] mode - Ile diod ma być włączonych.
 */
void uvLedsOn(short mode);

/*
 * Wyłącza diody uv.
 */
void uvLedsOff();

#endif /* INC_LEDS_H_ */
