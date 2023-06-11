/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 9 May , 2023
* SWC 	  : SYSTICK
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

void MSTK_voidInit(void);
void MSTK_voidEnableSTK(void);
void MSTK_voidDisableSTK(void);
void MSTK_voidEnableInterrupt(void);
void MSTK_voidDisableInterrupt(void);
void MSTK_voidSetClockSource(u8 Copy_u8ClockSource);
u32 MSTK_u32GetElapsedTime(void);
u32 MSTK_u32GetRemainingTime(void);
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks,void (*PVNotificationFunction)(void));
void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks,void (*PVNotificationFunction)(void));


/* Macros for clock source */
#define MSTK_CLOCK_AHB				0
#define MSTK_CLOCK_AHB_DIV_BY_8		1

#endif