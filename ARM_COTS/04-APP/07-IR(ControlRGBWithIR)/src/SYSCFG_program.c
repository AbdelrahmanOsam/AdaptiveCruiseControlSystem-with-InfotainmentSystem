/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 23 May , 2023
* SWC 	  : SYSCFG
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSCFG_interface.h"
#include "SYSCFG_private.h"
#include "SYSCFG_config.h"

void MSYSCFG_voidSetEXTISourceInput(u8 Copy_u8EXTILine,u8 Copy_u8PortID)
{
	if (Copy_u8EXTILine <= 3)	
	{	
		MSYSCFG->EXTICR1 &=~ ((0b1111)<<(Copy_u8EXTILine*4));
		MSYSCFG->EXTICR1 |= ((Copy_u8PortID)<<(Copy_u8EXTILine*4));
	}
	else if (Copy_u8EXTILine <= 7)
	{
		MSYSCFG->EXTICR2 &=~ ((0b1111)<<(Copy_u8EXTILine*4));
		MSYSCFG->EXTICR2 |= ((Copy_u8PortID)<<(Copy_u8EXTILine*4));
	}
	else if (Copy_u8EXTILine <= 11)
	{
		MSYSCFG->EXTICR3 &=~ ((0b1111)<<(Copy_u8EXTILine*4));
		MSYSCFG->EXTICR3 |= ((Copy_u8PortID)<<(Copy_u8EXTILine*4));
	}
	else if (Copy_u8EXTILine <= 15)
	{
		MSYSCFG->EXTICR4 &=~ ((0b1111)<<(Copy_u8EXTILine*4));
		MSYSCFG->EXTICR4 |= ((Copy_u8PortID)<<(Copy_u8EXTILine*4));
	}
	else
	{
		//error
	}
}	
