/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 23 May , 2023
* SWC 	  : SYSCFG
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H

void MSYSCFG_voidSetEXTISourceInput(u8 Copy_u8EXTILine, Copy_u8PortID);

/* Macros for EXTI lines */
#define EXTI_LINE0		0
#define EXTI_LINE1		1
#define EXTI_LINE2		2
#define EXTI_LINE3		3
#define EXTI_LINE4		4
#define EXTI_LINE5		5
#define EXTI_LINE6		6
#define EXTI_LINE7		7
#define EXTI_LINE8		8
#define EXTI_LINE9		9
#define EXTI_LINE10		10
#define EXTI_LINE11		11
#define EXTI_LINE12		12
#define EXTI_LINE13		13
#define EXTI_LINE14		14
#define EXTI_LINE15		15

/* Macros for Source inputs for EXTI -> Copy_u8PortID*/
#define SYSCFG_PORTA	0b0000
#define SYSCFG_PORTB	0b0001
#define SYSCFG_PORTC	0b0010
#define SYSCFG_PORTD	0b0011
#define SYSCFG_PORTE	0b0100
#define SYSCFG_PORTH	0b0111
#endif