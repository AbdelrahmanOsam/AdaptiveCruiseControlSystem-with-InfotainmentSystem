/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: Abd El Rahman
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"

int main (void)
{
	MRCC_voidInit();
	MGPIO_voidInit();

	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);
	MGPIO_voidSetPinMode(GPIOA,GPIO_PIN0,GPIO_MODE_OUTPUT);
	MGPIO_voidSetOutputPinMode(GPIOA,GPIO_PIN0,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinSpeed(GPIOA,GPIO_PIN0,HIGH_SPEED);
	while(1)
	{
		MGPIO_voidSetPinValue(GPIOA,GPIO_PIN0,GPIO_HIGH);
		MGPIO_voidSetPinValue(GPIOA,GPIO_PIN0,GPIO_LOW);
	}
	return 0;
}


