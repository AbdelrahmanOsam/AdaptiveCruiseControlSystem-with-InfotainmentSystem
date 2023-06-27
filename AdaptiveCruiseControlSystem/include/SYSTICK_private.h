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

#define STK_BASE_ADDRESS		0xE000E010

#define STK_CTRL				*((volatile u32*)(STK_BASE_ADDRESS + 0x00))
#define STK_LOAD				*((volatile u32*)(STK_BASE_ADDRESS + 0x04))
#define STK_VAL					*((volatile u32*)(STK_BASE_ADDRESS + 0x08))
#define STK_CALIB				*((volatile u32*)(STK_BASE_ADDRESS + 0x0C))

/***********Macros for STK_CTRL*********/
#define STK_CTRL_ENABLE			0
#define STK_CTRL_TICKINT		1
#define STK_CTRL_CLKSOURCE		2
#define STK_CTRL_COUNTFLAG		16

#define AHB						0
#define AHB_DIV_BY_8			1

#define ENABLE					1
#define DISABLE					0

#define SINGLE_INTERVAL			0
#define PERIODIC_INTERVAL		1

void SysTick_Handler(void);

#endif
