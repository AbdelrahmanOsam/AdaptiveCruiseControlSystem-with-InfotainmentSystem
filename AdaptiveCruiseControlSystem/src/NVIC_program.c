/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 21 May , 2023
* SWC 	  : NVIC
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInit(void)
{
	/* Set the group and sub priorities distrubtion */
    SCB_AIRCR |= (AIRCR_PRIVKEY << 16) | (MNVIC_GRB_SUB_DISTRUBTION << 8);
}

void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8PeripheralID)
{
	u8 Local_u8ISERIndex;
	Local_u8ISERIndex = Copy_u8PeripheralID / 32;
	MNVIC->ISER[Local_u8ISERIndex] = (1<<(Copy_u8PeripheralID%32));
}

void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8PeripheralID)
{
	u8 Local_u8ICERIndex;
	Local_u8ICERIndex = Copy_u8PeripheralID / 32;
	MNVIC->ICER[Local_u8ICERIndex] = (1<<(Copy_u8PeripheralID%32));
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISPRIndex;
    Local_u8ISPRIndex = Copy_u8PeripheralID / 32;
    MNVIC -> ISPR[Local_u8ISPRIndex] = (1 << (Copy_u8PeripheralID%32));
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ICPRIndex;
    Local_u8ICPRIndex = Copy_u8PeripheralID / 32;
    MNVIC -> ICPR[Local_u8ICPRIndex] = (1 << (Copy_u8PeripheralID%32));
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralID)
{
	u8 Local_u8ReturnedActiveFlag;
	u8 Local_u8IAPRIndex;
	Local_u8IAPRIndex = Copy_u8PeripheralID / 32;
	Local_u8ReturnedActiveFlag = GET_BIT(MNVIC->IABR[Local_u8IAPRIndex],(Copy_u8PeripheralID % 32));
	return Local_u8ReturnedActiveFlag;
}

void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority)
{
    MNVIC -> IPR[Copy_u8PeripheralID] = (Copy_u8Priority << 4);
}
