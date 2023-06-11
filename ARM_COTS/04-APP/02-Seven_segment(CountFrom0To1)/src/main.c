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

#include "SevenSegment_interface.h"

int main (void)
{
	/* Initialize RCC */
	MRCC_voidInit();
	/* Enable GPIOA clock */
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);
	/* Initialize GPIO */
	MGPIO_voidInit();

	/* Initialize SYSTICK */
	MSTK_voidInit();

	/* Enable STK */
	MSTK_voidEnableSTK();
		/* Create segment */
	SevenSegment Segment1={GPIOA,GPIO_PIN0,GPIO_PIN1,GPIO_PIN2,GPIO_PIN3,GPIO_PIN4,GPIO_PIN5,GPIO_PIN6,GPIO_PIN7};
	SevenSegment Segment2={GPIOB,GPIO_PIN0,GPIO_PIN1,GPIO_PIN2,GPIO_PIN3,GPIO_PIN4,GPIO_PIN5,GPIO_PIN6,GPIO_PIN7};
	/* Initialize SevenSegment */
	SevenSegment_voidInit(&Segment1);
	SevenSegment_voidInit(&Segment2);

	while(1)
	{
		SevenSegment_voidDisplayNumber1(&Segment2);
		SevenSegment_voidDisplayNumber0(&Segment1);
		MSTK_voidSetBusyWait(1000000);

		SevenSegment_voidDisplayNumber0(&Segment2);
		SevenSegment_voidDisplayNumber9(&Segment1);
		MSTK_voidSetBusyWait(1000000);

		SevenSegment_voidDisplayNumber0(&Segment2);
		SevenSegment_voidDisplayNumber8(&Segment1);
		MSTK_voidSetBusyWait(1000000);

		SevenSegment_voidDisplayNumber0(&Segment2);
		SevenSegment_voidDisplayNumber7(&Segment1);
		MSTK_voidSetBusyWait(1000000);

		SevenSegment_voidDisplayNumber0(&Segment2);
		SevenSegment_voidDisplayNumber6(&Segment1);
		MSTK_voidSetBusyWait(1000000);

		SevenSegment_voidDisplayNumber0(&Segment2);
		SevenSegment_voidDisplayNumber5(&Segment1);
		MSTK_voidSetBusyWait(1000000);

		SevenSegment_voidDisplayNumber0(&Segment2);
		SevenSegment_voidDisplayNumber4(&Segment1);
		MSTK_voidSetBusyWait(1000000);

		SevenSegment_voidDisplayNumber0(&Segment2);
		SevenSegment_voidDisplayNumber3(&Segment1);
		MSTK_voidSetBusyWait(1000000);

		SevenSegment_voidDisplayNumber0(&Segment2);
		SevenSegment_voidDisplayNumber2(&Segment1);
		MSTK_voidSetBusyWait(1000000);

		SevenSegment_voidDisplayNumber0(&Segment2);
		SevenSegment_voidDisplayNumber1(&Segment1);
		MSTK_voidSetBusyWait(1000000);
	}

	return 0;
}
