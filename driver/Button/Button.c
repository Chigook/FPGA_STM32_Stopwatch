/*
 * Button.c
 *
 *  Created on: Oct 7, 2022
 *      Author: chigook
 */

#include "Button.h"

void Button_GetInstance(Button *btn, GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN)
{
	btn->GPIOX = GPIOx;
	btn->GPIO_PIN = GPIO_PIN;
	btn->prevState = RELEASED;
}

int Button_GetState(Button *btn)
{
	int curState;

	curState = HAL_GPIO_ReadPin(btn->GPIOX, btn->GPIO_PIN);

	if(curState == PUSHED && btn->prevState == RELEASED){
		btn->prevState = PUSHED;
		return ACTIVE_PUSH;
	}
	else if(curState == RELEASED && btn->prevState == PUSHED)
	{
		btn->prevState = RELEASED;
		return ACTIVE_RELEASE;
	}
	return ACTIVE_NO;
}
