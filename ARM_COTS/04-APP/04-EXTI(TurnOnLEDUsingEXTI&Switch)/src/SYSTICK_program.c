/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 9 May , 2023
* SWC 	  : SYSTICK
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

u8 Global_u8PeriodicIntervalStatue;
static void (*Global_pvoidCallBackFunction)(void) = NULL;

void MSTK_voidInit(void)
{
	#if CLOCK_SOURCE_SELECTION == AHB
		SET_BIT(STK_CTRL,STK_CTRL_CLKSOURCE);
	#elif CLOCK_SOURCE_SELECTION == AHB_DIV_BY_8
		CLEAR_BIT(STK_CTRL,STK_CTRL_CLKSOURCE);
	#else
		#error "Configuration error : Clock source selection error"
	#endif
	
	#if MSTK_INTERRUPT_MODE ==ENABLE
		SET_BIT(STK_CTRL,STK_CTRL_ENABLE);
	#elif MSTK_INTERRUPT_MODE == DISABLE
		CLEAR_BIT(STK_CTRL,STK_CTRL_ENABLE);
	#else
		#error "Configuration error : MSTK interrupt enable error"
	#endif
	
		/* Disable Systick interrupt at intialization*/
	CLEAR_BIT(STK_CTRL,STK_CTRL_TICKINT);
	
}

void MSTK_voidEnableSTK(void)
{
	SET_BIT(STK_CTRL,STK_CTRL_ENABLE);
}

void MSTK_voidDisableSTK(void)
{
	CLEAR_BIT(STK_CTRL,STK_CTRL_ENABLE);
}

void MSTK_voidEnableInterrupt(void)
{
	SET_BIT(STK_CTRL,STK_CTRL_TICKINT);	
}

void MSTK_voidDisableInterrupt(void)
{
	SET_BIT(STK_CTRL,STK_CTRL_TICKINT);	
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
		/* Set Ticks number in Load register */
	STK_LOAD = Copy_u32Ticks;
		/* Enable SYSTICK to start count */
	MSTK_voidEnableSTK();
		/* Wait until Count flag returns zero */
	while(!(GET_BIT(STK_CTRL,STK_CTRL_COUNTFLAG)));
		/* Disable SYSTICK to stop*/
	MSTK_voidDisableSTK();
}

void MSTK_voidSetSingleInterval(u32 Copy_u32Ticks,void (*PVNotificationFunction)(void))
{
	Global_u8PeriodicIntervalStatue = 0;
	STK_LOAD = Copy_u32Ticks;
	Global_pvoidCallBackFunction = PVNotificationFunction;
	MSTK_voidEnableSTK();	
	SET_BIT(STK_CTRL,STK_CTRL_TICKINT);
}

void MSTK_voidSetPeriodicInterval(u32 Copy_u32Ticks,void (*PVNotificationFunction)(void))
{
	Global_u8PeriodicIntervalStatue = 1;
	STK_LOAD = Copy_u32Ticks;
	Global_pvoidCallBackFunction = PVNotificationFunction;
	SET_BIT(STK_CTRL,STK_CTRL_ENABLE);
	SET_BIT(STK_CTRL,STK_CTRL_TICKINT);
}

u32 MSYSTICK_u32GetElapsedTime (void)
{
	u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = STK_LOAD - STK_VAL;
	return Local_u32ElapsedTime;
}

u32 MSYSTICK_u32GetRemainingTime (void)
{
	u32 Local_u32RemainingTime = STK_VAL;
	return Local_u32RemainingTime;
}
void Systick_Handler(void)
{
	u32 Local_u32TempVar;
	if(Global_pvoidCallBackFunction != NULL)
	{
		Global_pvoidCallBackFunction();
	}
	else
	{
		
	}
	if(Global_u8PeriodicIntervalStatue == 0)
	{
		STK_LOAD = 0;
		STK_VAL = 0;
		CLEAR_BIT(STK_CTRL,STK_CTRL_ENABLE);
	}
	Local_u32TempVar = GET_BIT(STK_CTRL,STK_CTRL_COUNTFLAG);
}
