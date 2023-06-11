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

static void (*Global_pvCallBack[16])(void) = {{NULL}};

void MEXTI_voidInit(void)
{
	
}
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILine)
{
	if(Copy_u8EXTILine > 15)
	{
		return;
	}
	SET_BIT(MEXTI->IMR,Copy_u8EXTILine);
}
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILine)
{
	if(Copy_u8EXTILine > 15)
	{
		return;
	}
	CLEAR_BIT(MEXTI->IMR,Copy_u8EXTILine);
}
void MEXTI_ChangeSenseMode(u8 Copy_u8EXTILine, u8 Copy_u8SenseSignal)
{
	switch(Copy_u8SenseSignal)
	{
		case MEXTI_RISING_EDGE :
			CLEAR_BIT(MEXTI->FTSR,Copy_u8EXTILine);
			SET_BIT(MEXTI->RTSR,Copy_u8EXTILine);
		break;
		case MEXTI_FALLING_EDGE :
			CLEAR_BIT(MEXTI->RTSR,Copy_u8EXTILine);
			SET_BIT(MEXTI->FTSR,Copy_u8EXTILine);
		break;
		case MEXTI_ON_CHANGE :
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
	if(Copy_u8EXTILine > 15)
	{
		return;
	}
	Global_pvCallBack[Copy_u8EXTILine] = pvNotificationFunction;
}

void EXTI0_IRQHandler(void)
{
	if(Global_pvCallBack[0] != NULL)
	{
		Global_pvCallBack[0]();
	}
	SET_BIT(MEXTI->PR,0);
}

void EXTI1_IRQHandler(void)
{
	if(Global_pvCallBack[1] != NULL)
	{
		Global_pvCallBack[1]();
	}
}

void EXTI2_IRQHandler(void)
{
	if(Global_pvCallBack[2] != NULL)
	{
		Global_pvCallBack[2]();
	}
}

void EXTI3_IRQHandler(void)
{
	if(Global_pvCallBack[3] != NULL)
	{
		Global_pvCallBack[3]();
	}
}

void EXTI4_IRQHandler(void)
{
	if(Global_pvCallBack[4] != NULL)
	{
		Global_pvCallBack[4]();
	}
}

void EXTI5_IRQHandler(void)
{
	if(Global_pvCallBack[5] != NULL)
	{
		Global_pvCallBack[5]();
	}
}

void EXTI6_IRQHandler(void)
{
	if(Global_pvCallBack[6] != NULL)
	{
		Global_pvCallBack[6]();
	}
}

void EXTI7_IRQHandler(void)
{
	if(Global_pvCallBack[7] != NULL)
	{
		Global_pvCallBack[7]();
	}
}

void EXTI8_IRQHandler(void)
{
	if(Global_pvCallBack[8] != NULL)
	{
		Global_pvCallBack[8]();
	}
}

void EXTI9_IRQHandler(void)
{
	if(Global_pvCallBack[9] != NULL)
	{
		Global_pvCallBack[9]();
	}
}

void EXTI10_IRQHandler(void)
{
	if(Global_pvCallBack[10] != NULL)
	{
		Global_pvCallBack[10]();
	}
}

void EXTI11_IRQHandler(void)
{
	if(Global_pvCallBack[11] != NULL)
	{
		Global_pvCallBack[11]();
	}
}

void EXTI12_IRQHandler(void)
{
	if(Global_pvCallBack[12] != NULL)
	{
		Global_pvCallBack[12]();
	}
}

void EXTI13_IRQHandler(void)
{
	if(Global_pvCallBack[13] != NULL)
	{
		Global_pvCallBack[13]();
	}
}

void EXTI14_IRQHandler(void)
{
	if(Global_pvCallBack[14] != NULL)
	{
		Global_pvCallBack[14]();
	}
}

void EXTI15_IRQHandler(void)
{
	if(Global_pvCallBack[15] != NULL)
	{
		Global_pvCallBack[15]();
	}
}

