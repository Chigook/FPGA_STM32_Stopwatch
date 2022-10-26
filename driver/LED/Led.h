/*
 * Led.h
 *
 *  Created on: Oct 7, 2022
 *      Author: chigook
 */

#ifndef SRC_DRIVER_LED_LED_H_
#define SRC_DRIVER_LED_LED_H_

#include "stm32f4xx_hal.h"

typedef struct _led {
	GPIO_TypeDef* GPIOX;
	uint16_t GPIO_PIN;
}Led;

void Led_GetInstance(Led *led, GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);
void Led_On(Led *led);
void Led_Off(Led *led);
void Led_Toggle(Led *led);

#endif /* SRC_DRIVER_LED_LED_H_ */
