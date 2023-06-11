/*
 * main.c
 *
 *  Created on: May 14, 2023
 *      Author: Abd El Rahman
 */



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "GPIO_interface.h"

#include "LEDMATRIX_interface.h"

int main (void)
{
	/* Initialize RCC */
	MRCC_voidInit();
	/* Enable GPIOA clock */
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOB);

	/* Initialize GPIO */
	MGPIO_voidInit();

	/* Initialize SYSTICK */
	MSTK_voidInit();

	HLEDMATRIX_voidInit();
	/* Initialize SevenSegment */
	u8 A[8]={0, 252, 36, 36, 36, 252, 0, 0};

	while(1)
	{
		HLEDMATRIX_voidDisplay(A);
		MSTK_voidSetBusyWait(1000000);
	}
	return 0;
}
