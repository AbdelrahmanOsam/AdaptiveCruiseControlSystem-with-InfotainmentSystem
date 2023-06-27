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

void MSYSCFG_voidSetEXTISourceInput(u8 Copy_u8EXTILine,u8 Copy_u8PortID);
/* Macros for Source inputs for EXTI -> Copy_u8PortID*/
#define SYSCFG_PORTA	0b0000
#define SYSCFG_PORTB	0b0001
#define SYSCFG_PORTC	0b0010
#define SYSCFG_PORTD	0b0011
#define SYSCFG_PORTE	0b0100
#define SYSCFG_PORTH	0b0111
#endif
