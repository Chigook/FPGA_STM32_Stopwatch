/*
 * Button.h
 *
 *  Created on: Oct 7, 2022
 *      Author: chigook
 */

#ifndef SRC_DRIVER_BUTTON_H_
#define SRC_DRIVER_BUTTON_H_

#include "stm32f4xx_hal.h"

enum {ACTIVE_NO, ACTIVE_PUSH, ACTIVE_RELEASE};

enum {PUSHED, RELEASED};

typedef struct _button {
	GPIO_TypeDef* GPIOX;
	uint16_t GPIO_PIN;
	int prevState;
}Button;

/* 참고용
 * void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState)
{
}
 */

void Button_GetInstance(Button *btn, GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN);
int Button_GetState(Button *btn);

#endif /* SRC_DRIVER_BUTTON_H_ */
