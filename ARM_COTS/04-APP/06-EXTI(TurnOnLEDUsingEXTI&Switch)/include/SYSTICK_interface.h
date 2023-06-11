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
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks,void (*PVNotificationFunction)(void));
void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks,void (*PVNotificationFunction)(void));
u32 MSYSTICK_u32GetElapsedTime (void);
u32 MSYSTICK_u32GetRemainigTime (void);

#endif