/*
 * main.c
 *
 *  Created on: May 23, 2023
 *      Author: Abd El Rahman
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSCFG_interface.h"
#include "IR_interface.h"

void main (void)
{
	HIR_voidInit();

	MRCC_voidInit();
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);


	MGPIO_voidSetPinMode(GPIO_PORTA ,GPIO_PIN1 , GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTA ,GPIO_PIN2 , GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTA ,GPIO_PIN3 , GPIO_MODE_OUTPUT);

	MGPIO_voidSetOutputPinMode(GPIO_PORTA ,GPIO_PIN1 ,GPIO_OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(GPIO_PORTA ,GPIO_PIN2 ,GPIO_OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(GPIO_PORTA ,GPIO_PIN2 ,GPIO_OUTPUT_PUSH_PULL);

	MGPIO_voidSetOutputPinSpeed(GPIO_PORTA,GPIO_PIN1 ,GPIO_MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(GPIO_PORTA,GPIO_PIN2 ,GPIO_MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(GPIO_PORTA,GPIO_PIN3 ,GPIO_MEDIUM_SPEED);
	while(1)
	{

		switch(Global_u8ButtonData)
			{
			// OFF Button
			case 69:
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , GPIO_LOW);
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN2 , GPIO_LOW);
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN3 , GPIO_LOW);
				break;
				//Button Number (1) For Led Light
			case 12:
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN2 , GPIO_LOW);
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN3 , GPIO_LOW);
				break;
				//Button Number (2) For GREEN Light
			case 24:
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , GPIO_LOW);
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN2 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN3 , GPIO_LOW);
				break;
				//Button Number (3) For BLUE Light
			case 94:
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , GPIO_LOW);
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN2 , GPIO_LOW);
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN3 , GPIO_HIGH);
				break;
				//Button Number (4) For BLUE Light
			case 8:
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN2 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN3 , GPIO_LOW);
				break;
				//Button Number (5) For BLUE Light
			case 28:
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , GPIO_LOW);
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN2 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN3 , GPIO_HIGH);
				break;
				//Button Number (6) For BLUE Light
			case 90:
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN1 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN2 , GPIO_HIGH);
				MGPIO_voidSetPinValue(GPIO_PORTA , GPIO_PIN3 , GPIO_HIGH);
				break;

			}

	}
}

