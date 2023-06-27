/*
 * Delay.c
 *
 *  Created on: May 9, 2023
 *      Author: Delta Store
 */

#include "STD_TYPES.h"
#include "Delay.h"

void	_delay_ms(u32 _ms)
{
	for(u32 i = 0; i < (_ms * 500) ; i++)
	{
		/*NO Operation , do no thing*/
		asm("NOP");
	}
}

/**************** Sudo Code *****************/
/*
 * while(1)
 * {
 * 		if(B1 ==1)
 * 		{
 * 			Turn ON LED1
 * 			_delay_ms(777);
 * 		}
 * 		if(B2 == 1)
 * 		{
 * 			Turn ON LED2;
 * 			_delay_ms
 * 		}
 *
 * }
 *
 */
