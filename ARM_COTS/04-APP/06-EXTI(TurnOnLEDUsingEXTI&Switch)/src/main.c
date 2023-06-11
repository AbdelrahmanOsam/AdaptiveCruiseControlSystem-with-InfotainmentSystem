/*
 * main.c
 *
 *  Created on: May 22, 2023
 *      Author: Abd El Rahman
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSTICK_interface.h"

void FUNC(void);
int main (void)
{
		/* Initialize RCC */
	MRCC_voidInit();
		/* Initialize SisTick */
	MSTK_voidInit();
		/* Initialize GPIO */
	MGPIO_voidInit();
		/* Initialize NVIC */
	MNVIC_voidInit();
		/* Enable GPIOA clock */
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);
		/* Set A1 as Output pin */
	MGPIO_voidSetPinMode(GPIOA,GPIO_PIN1,GPIO_MODE_OUTPUT);
		/* Select output push pull mode for A1 */
	MGPIO_voidSetOutputPinMode(GPIOA,GPIO_PIN1,OUTPUT_PUSH_PULL);
		/* Select medium speed for A1 */
	MGPIO_voidSetOutputPinSpeed(GPIOA,GPIO_PIN1,MEDIUM_SPEED);
		/* Set A0 as input pin */
	MGPIO_voidSetPinMode(GPIOA,GPIO_PIN0,GPIO_MODE_INPUT);
		/* Select Pull up mode for A1 */
	MGPIO_voidSetPinPullMode(GPIOA,GPIO_PIN0,PULL_UP);
		/* Enable NVIC interrupt for EXTI0 */
	MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);
		/* Select Falling edge sense mode for EXTI0 */
	MEXTI_ChangeSenseMode(MEXTI_LINE0,MEXTI_FALLING_EDGE);
		/* SET FUNC function in the callback function for EXTI0 */
	MEXTI_voidSetCallBack(MEXTI_LINE0,&FUNC);
		/* Enable EXTI interrupt for EXTI0 */
	MEXTI_voidEnableInterrupt(MEXTI_LINE0);
	while(1)
	{
		MGPIO_voidSetPinValue(GPIOA,GPIO_PIN1,GPIO_LOW);
	}

	return 0;
}
void FUNC(void)
{
	MGPIO_voidSetPinValue(GPIOA,GPIO_PIN1,GPIO_HIGH);
	MSTK_voidSetBusyWait(1000000);
}


