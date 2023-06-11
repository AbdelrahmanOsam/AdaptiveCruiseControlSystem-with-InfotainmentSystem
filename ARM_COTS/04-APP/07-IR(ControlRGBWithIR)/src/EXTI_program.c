/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 22 May , 2023
* SWC 	  : EXTI
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void (*Global_pvCallBack[16])(void) = {{NULL}};


void MEXTI_voidInit(void)
{
		/* Disable Rising trigger and falling trigger registers */
	/*MEXTI->RTSR &= 0x00000000
	MEXTI->FTSR	= 0x00000000
	#if MEXTI0_SENSE_MODE == MEXTI_FALLING_EDGE
		
	#elif MEXTI0_SENSE_MODE == MEXTI_RISING_EDGE
		
	#elif MEXTI0_SENSE_MODE == MEXTI_ON_CHANGE
		
	#else
		#error "Configuration error : EXTI0 sense mode error"
	#endif*/
}
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILine)
{
		/* Security for user input*/
	if(Copy_u8EXTILine > 15)
	{
		return;
	}
		/* Enable interrupt */
	SET_BIT(MEXTI->IMR,Copy_u8EXTILine);
}
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILine)
{
		/* Security for user input*/
	if(Copy_u8EXTILine > 15)
	{
		return;
	}
		/* Disable Interrupt */
	CLEAR_BIT(MEXTI->IMR,Copy_u8EXTILine);
}
void MEXTI_ChangeSenseMode(u8 Copy_u8EXTILine, u8 Copy_u8SenseSignal)
{
		/* detect the selected sense mode */
	switch(Copy_u8SenseSignal)
	{
		case MEXTI_RISING_EDGE :
				/* Disable Falling edge mode */
			CLEAR_BIT(MEXTI->FTSR,Copy_u8EXTILine);
				/* Enable Rising edge mode */
			SET_BIT(MEXTI->RTSR,Copy_u8EXTILine);
		break;
		case MEXTI_FALLING_EDGE :
				/* Disable Rising edge mode */
			CLEAR_BIT(MEXTI->RTSR,Copy_u8EXTILine);
				/* Enable Falling edge mode */
			SET_BIT(MEXTI->FTSR,Copy_u8EXTILine);
		break;
		case MEXTI_ON_CHANGE :
				/* Enable On change mode */
			SET_BIT(MEXTI->FTSR,Copy_u8EXTILine);
			SET_BIT(MEXTI->RTSR,Copy_u8EXTILine);
		break;
		default :
			// error
		break;
	}
}
void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine, void (*pvNotificationFunction)(void))
{
		/* Security for user input*/
	if(Copy_u8EXTILine > 15)
	{
		return;
	}
		/* Set The callBack Function int the ISR through global pointer to function */
	Global_pvCallBack[Copy_u8EXTILine] = pvNotificationFunction;
}

void EXTI0_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[0] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[0]();
	}
		/* Clear Pending flag of line 0 */
	SET_BIT(MEXTI->PR,0);
}

void EXTI1_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[1] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[1]();
	}
	/* Clear Pending flag of line 0 */
	SET_BIT(MEXTI->PR,0);
}

void EXTI2_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[2] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[2]();
	}
		/* Clear Pending flag of line 0 */
	SET_BIT(MEXTI->PR,2);
}

void EXTI3_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[3] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[3]();
	}
		/* Clear Pending flag of line 0 */
	SET_BIT(MEXTI->PR,3);
}

void EXTI4_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[4] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[4]();
	}
		/* Clear Pending flag of line 0 */
	SET_BIT(MEXTI->PR,4);
}

void EXTI5_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[5] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[5]();
	}
		/* Clear Pending flag of line 0 */
	SET_BIT(MEXTI->PR,5);
}

void EXTI6_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[6] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[6]();
	}
		/* Clear Pending flag of line 0 */
	SET_BIT(MEXTI->PR,6);
}

void EXTI7_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[7] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[7]();
	}
		/* Clear Pending flag of line 7 */
	SET_BIT(MEXTI->PR,7);
}

void EXTI8_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[8] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[8]();
	}
		/* Clear Pending flag of line 8 */
	SET_BIT(MEXTI->PR,8);
}

void EXTI9_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[9] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[9]();
	}
		/* Clear Pending flag of line 9 */
	SET_BIT(MEXTI->PR,9);
}

void EXTI10_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[10] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[10]();
	}
		/* Clear Pending flag of line 10 */
	SET_BIT(MEXTI->PR,10);
}

void EXTI11_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[11] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[11]();
	}
		/* Clear Pending flag of line 11 */
	SET_BIT(MEXTI->PR,11);
}

void EXTI12_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[12] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[12]();
	}
		/* Clear Pending flag of line 12 */
	SET_BIT(MEXTI->PR,12);
}

void EXTI13_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[13] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[13]();
	}
		/* Clear Pending flag of line 13 */
	SET_BIT(MEXTI->PR,13);
}

void EXTI14_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[14] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[14]();
	}
		/* Clear Pending flag of line 14 */
	SET_BIT(MEXTI->PR,14);
}

void EXTI15_IRQHandler(void)
{
		/* Ensure that flag hasnot NUll */
	if(Global_pvCallBack[15] != NULL)
	{
			/* Call callBack function */
		Global_pvCallBack[15]();
	}
		/* Clear Pending flag of line 15 */
	SET_BIT(MEXTI->PR,15);
}
