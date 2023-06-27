/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 22 May , 2023
* SWC 	  : EXTI
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct 
{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_t;

#define MEXTI			((volatile EXTI_t *)0x40013C00)

#endif