/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 9 May , 2023
* SWC 	  : SYSTICK
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/
#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define STK_CTRL	*((volatile u32*)(0xE000E010))
#define STK_LOAD	*((volatile u32*)(0xE000E014))
#define STK_VAL		*((volatile u32*)(0xE000E018))
#define STK_CALIB	*((volatile u32*)(0xE000E01C))

/***********Macros for STK_CTRL*********/
#define STK_CTRL_ENABLE			0
#define STK_CTRL_TICKINT		1
#define STK_CTRL_CLKSOURCE		2
#define STK_CTRL_COUNTFLAG		16

#define AHB						0
#define AHB_DIV_BY_8			1

void SYSTICK_Handler(void);


#endif
