/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 23 May , 2023
* SWC 	  : SYSCFG
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#ifndef SYSCFG_PRIVATE_H
#define SYSCFG_PRIVATE_H

typedef struct 
{
	volatile u32 MEMRMP;
	volatile u32 PMC;
	volatile u32 EXTICR1;
	volatile u32 EXTICR2;
	volatile u32 EXTICR3;
	volatile u32 EXTICR4;
	volatile u32 CMPCR;
}SYSCFG_t;

#define MSYSCFG	((volatile SYSCFG_t *) 0x40013800)

#endif