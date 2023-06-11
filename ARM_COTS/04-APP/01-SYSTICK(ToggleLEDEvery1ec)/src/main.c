/*
 * main.c
 *
 *  Created on: May 9, 2023
 *      Author: Abd El Rahman
 */


#include"STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "RCC_interface.h"

int main (void)
{
	MRCC_voidInit();
	MGPIO_voidInit();
	MSTK_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);
	MGPIO_voidSetPinMode(GPIOA,GPIO_PIN0,GPIO_MODE_OUTPUT);
	MGPIO_voidSetOutputPinMode(GPIOA,GPIO_PIN0,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinSpeed(GPIOA,GPIO_PIN0,MEDIUM_SPEED);
	u8 x=5;
	while(x)
	{
		MGPIO_voidSetPinValue(GPIOA,GPIO_PIN0,GPIO_LOW);
		MSTK_voidSetBusyWait(1000000);
		MGPIO_voidSetPinValue(GPIOA,GPIO_PIN0,GPIO_HIGH);
		MSTK_voidSetBusyWait(1000000);
		MGPIO_voidSetPinValue(GPIOA,GPIO_PIN0,GPIO_LOW);
		x--;
	}
	return 0;
}

