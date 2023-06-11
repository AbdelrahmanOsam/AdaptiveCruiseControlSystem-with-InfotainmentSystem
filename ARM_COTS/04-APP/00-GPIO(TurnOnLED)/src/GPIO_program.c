/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 2 May , 2023
* SWC 	  : GPIO
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void MGPIO_voidInit(void)
{
		/* Init mode for the output pins mode */
	#if GPIOA_OUTPUT_MODE_SELECTION == OUTPUT_PUSH_PULL
		GPIOA_OTYPER = OUTPUT_PUSH_PULL_VALUE;
	#elif GPIOA_OUTPUT_MODE_SELECTION == OUTPUT_OPEN_DRAIN
		GPIOA_OTYPER = OUTPUT_OPEN_DRAIN_VALUE;
	#else
		#error "Configuration Error : GPIOA Output mode selection error"
	#endif
	
	#if GPIOB_OUTPUT_MODE_SELECTION == OUTPUT_PUSH_PULL
		GPIOB_OTYPER = OUTPUT_PUSH_PULL_VALUE;
	#elif GPIOB_OUTPUT_MODE_SELECTION == OUTPUT_OPEN_DRAIN
		GPIOB_OTYPER = OUTPUT_OPEN_DRAIN_VALUE;
	#else
		#error "Configuration Error : GPIOB Output mode selection error"
	#endif
	
	#if GPIOC_OUTPUT_MODE_SELECTION == OUTPUT_PUSH_PULL
		GPIOC_OTYPER = OUTPUT_PUSH_PULL_VALUE;
	#elif GPIOC_OUTPUT_MODE_SELECTION == OUTPUT_OPEN_DRAIN
		GPIOC_OTYPER = OUTPUT_OPEN_DRAIN_VALUE;
	#else
		#error "Configuration Error : GPIOC Output mode selection error"
	#endif
	
		/* Init mode for output pins speed */
	#if GPIOA_OUTPUT_SPEED_SELECTION == LOW_SPEED
		GPIOA_OSPEEDR = LOW_SPEED_VALUE;
	#elif GPIOA_OUTPUT_SPEED_SELECTION == MEDIUM_SPEED
		GPIOA_OSPEEDR = MEDIUM_SPEED_VALUE;
	#elif GPIOA_OUTPUT_SPEED_SELECTION == HIGH_SPEED
		GPIOA_OSPEEDR = HIGH_SPEED_VALUE;
	#elif GPIOA_OUTPUT_SPEED_SELECTION == VERY_HIGH_SPEED
		GPIOA_OSPEEDR = VERY_HIGH_SPEED_VALUE;
	#else
		#error "Configuration Error : GPIOA output speed selection error"
	#endif
	
	#if GPIOB_OUTPUT_SPEED_SELECTION == LOW_SPEED
		GPIOB_OSPEEDR = LOW_SPEED_VALUE;
	#elif GPIOB_OUTPUT_SPEED_SELECTION == MEDIUM_SPEED
		GPIOB_OSPEEDR = MEDIUM_SPEED_VALUE;
	#elif GPIOB_OUTPUT_SPEED_SELECTION == HIGH_SPEED
		GPIOB_OSPEEDR = HIGH_SPEED_VALUE;
	#elif GPIOB_OUTPUT_SPEED_SELECTION == VERY_HIGH_SPEED
		GPIOB_OSPEEDR = VERY_HIGH_SPEED_VALUE;
	#else
		#error "Configuration Error : GPIOB output speed selection error"
	#endif
	
	#if GPIOC_OUTPUT_SPEED_SELECTION == LOW_SPEED
		GPIOC_OSPEEDR = LOW_SPEED_VALUE;
	#elif GPIOC_OUTPUT_SPEED_SELECTION == MEDIUM_SPEED
		GPIOC_OSPEEDR = MEDIUM_SPEED_VALUE;
	#elif GPIOC_OUTPUT_SPEED_SELECTION == HIGH_SPEED
		GPIOC_OSPEEDR = HIGH_SPEED_VALUE;
	#elif GPIOC_OUTPUT_SPEED_SELECTION == VERY_HIGH_SPEED
		GPIOC_OSPEEDR = VERY_HIGH_SPEED_VALUE;
	#else
		#error "Configuration Error : GPIOC output speed selection error"
	#endif
	
	#if GPIOA_PULL_MODE_SELECTION	== NO_PULL
		GPIOA_PUPDR = NO_PULL_VALUE;
	#elif GPIOA_PULL_MODE_SELECTION == PULL_UP
		GPIOA_PUPDR = PULL_UP_VALUE;
	#elif GPIOA_PULL_MODE_SELECTION == PULL_DOWN
		GPIOA_PUPDR = PULL_DOWN_VALUE;
	#else
		#error "Configuration Error : GPIOA pull mode selection error"
	#endif
	
	#if GPIOB_PULL_MODE_SELECTION	== NO_PULL
		GPIOB_PUPDR = NO_PULL_VALUE;
	#elif GPIOB_PULL_MODE_SELECTION == PULL_UP
		GPIOB_PUPDR = PULL_UP_VALUE;
	#elif GPIOB_PULL_MODE_SELECTION == PULL_DOWN
		GPIOB_PUPDR = PULL_DOWN_VALUE;
	#else
		#error "Configuration Error : GPIOA pull mode selection error"
	#endif
	
	#if GPIOC_PULL_MODE_SELECTION	== NO_PULL
		GPIOC_PUPDR = NO_PULL_VALUE;
	#elif GPIOC_PULL_MODE_SELECTION == PULL_UP
		GPIOC_PUPDR = PULL_UP_VALUE;
	#elif GPIOC_PULL_MODE_SELECTION == PULL_DOWN
		GPIOC_PUPDR = PULL_DOWN_VALUE;
	#else
		#error "Configuration Error : GPIOA pull mode selection error"
	#endif
}

void MGPIO_voidSetPinMode(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinMode)
{
	switch(Copy_u8PortID)
	{
		case GPIOA :
				/*Set zeros on selected pin*/
			GPIOA_MODER &=~((0b11)<<(Copy_u8PinID*2));
				/*Set mode to selected pin*/
			GPIOA_MODER |= ((Copy_u8PinMode)<<(Copy_u8PinID*2));
		
		break;
		case GPIOB :
				/*Set zeros on selected pin*/
			GPIOB_MODER &=~((0b11)<<(Copy_u8PinID*2));
				/*Set mode to selected pin*/
			GPIOB_MODER |= ((Copy_u8PinMode)<<(Copy_u8PinID*2));
		break;
		case GPIOC :
				/*Set zeros on selected pin*/
			GPIOC_MODER &=~((0b11)<<(Copy_u8PinID*2));
				/*Set mode to selected pin*/
			GPIOC_MODER |= ((Copy_u8PinMode)<<(Copy_u8PinID*2));
		break;
		default :
			// error state
		break;
	}
}
void MGPIO_voidSetOutputPinMode(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8OutputPinMode)
{
	switch(Copy_u8PortID)
	{
		case GPIOA :
			if(Copy_u8OutputPinMode == OUTPUT_PUSH_PULL)
			{
				CLEAR_BIT(GPIOA_OTYPER,Copy_u8PinID);
			}
			else if (Copy_u8OutputPinMode == OUTPUT_OPEN_DRAIN)
			{
				SET_BIT(GPIOA_OTYPER,Copy_u8PinID);
			}
			else
			{
				// error 
			}
		break;
		case GPIOB :
			if(Copy_u8OutputPinMode == OUTPUT_PUSH_PULL)
			{
				CLEAR_BIT(GPIOB_OTYPER,Copy_u8PinID);
			}
			else if (Copy_u8OutputPinMode == OUTPUT_OPEN_DRAIN)
			{
				SET_BIT(GPIOB_OTYPER,Copy_u8PinID);
			}
			else
			{
				// error 
			}
		break;
		case GPIOC :
			if(Copy_u8OutputPinMode == OUTPUT_PUSH_PULL)
			{
				CLEAR_BIT(GPIOC_OTYPER,Copy_u8PinID);
			}
			else if (Copy_u8OutputPinMode == OUTPUT_OPEN_DRAIN)
			{
				SET_BIT(GPIOC_OTYPER,Copy_u8PinID);
			}
			else
			{
				// error 
			}
		break;
		default :
			// error state
		break;
	}
}

void MGPIO_voidSetOutputPinSpeed(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8OutputPinSpeed)
{
	switch(Copy_u8PortID)
	{
		case GPIOA :
			/*Set zeros on selected pin*/
			GPIOA_OSPEEDR &=~((0b11)<<(Copy_u8PinID*2));
			/*Set Speed to selected pin*/
			GPIOA_OSPEEDR |= ((Copy_u8OutputPinSpeed)<<(Copy_u8PinID*2));
		break;
		case GPIOB :
			/*Set zeros on selected pin*/
			GPIOB_OSPEEDR &=~((0b11)<<(Copy_u8PinID*2));
			/*Set Speed to selected pin*/
			GPIOB_OSPEEDR |= ((Copy_u8OutputPinSpeed)<<(Copy_u8PinID*2));
		break;
		case GPIOC :
			/*Set zeros on selected pin*/
			GPIOC_OSPEEDR &=~((0b11)<<(Copy_u8PinID*2));
			/*Set Speed to selected pin*/
			GPIOC_OSPEEDR |= ((Copy_u8OutputPinSpeed)<<(Copy_u8PinID*2));
		break;
		default :
			// error state
		break;
	}
}

void MGPIO_voidSetPinPullMode(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinPullMode)
{
	switch(Copy_u8PortID)
	{
		case GPIOA :
			/*Set zeros on selected pin*/
			GPIOA_PUPDR &=~((0b11)<<(Copy_u8PinID*2));
			/*Set Speed to selected pin*/
			GPIOA_PUPDR |= ((Copy_u8PinPullMode)<<(Copy_u8PinID*2));
		break;
		case GPIOB :
			/*Set zeros on selected pin*/
			GPIOB_PUPDR &=~((0b11)<<(Copy_u8PinID*2));
			/*Set Speed to selected pin*/
			GPIOB_PUPDR |= ((Copy_u8PinPullMode)<<(Copy_u8PinID*2));
		break;
		case GPIOC :
			/*Set zeros on selected pin*/
			GPIOC_PUPDR &=~((0b11)<<(Copy_u8PinID*2));
			/*Set Speed to selected pin*/
			GPIOC_PUPDR |= ((Copy_u8PinPullMode)<<(Copy_u8PinID*2));
		break;
		default :
			// error state
		break;
	}
}

void MGPIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue)
{
	switch(Copy_u8PortID)
	{
		case GPIOA :
			if(Copy_u8PinValue == GPIO_LOW)
			{
				CLEAR_BIT(GPIOA_ODR,Copy_u8PinID);
			}
			else if (Copy_u8PinValue == GPIO_HIGH)
			{
				SET_BIT(GPIOA_ODR,Copy_u8PinID);
			}
			else
			{
				// error 
			}
		break;
		case GPIOB :
			if(Copy_u8PinValue == GPIO_LOW)
			{
				CLEAR_BIT(GPIOB_ODR,Copy_u8PinID);
			}
			else if (Copy_u8PinValue == GPIO_HIGH)
			{
				SET_BIT(GPIOB_ODR,Copy_u8PinID);
			}
			else
			{
				// error 
			}
		break;
		case GPIOC :
			if(Copy_u8PinValue == GPIO_LOW)
			{
				CLEAR_BIT(GPIOC_ODR,Copy_u8PinID);
			}
			else if (Copy_u8PinValue == GPIO_HIGH)
			{
				SET_BIT(GPIOC_ODR,Copy_u8PinID);
			}
			else
			{
				// error 
			}
		break;
		default :
			// error state
		break;
	}
}

u8 MGPIO_voidGetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID)
{
	u8 Local_u8ReturnedValue;
	switch(Copy_u8PortID)
	{
		case GPIOA :
			Local_u8ReturnedValue = GET_BIT(GPIOA_IDR,Copy_u8PinID);
		break;
		case GPIOB :
			Local_u8ReturnedValue = GET_BIT(GPIOB_IDR,Copy_u8PinID);
		break;
		case GPIOC :
			Local_u8ReturnedValue = GET_BIT(GPIOC_IDR,Copy_u8PinID);
		break;
		default :
			// error state
		break;
	}
	return Local_u8ReturnedValue;
}

void MGPIO_voidAtomicSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue)
{
	switch(Copy_u8PortID)
	{
		case GPIOA :
			if (Copy_u8PinValue == GPIO_LOW)
			{
				Copy_u8PinID += 16;
				GPIOA_BSRR = (1<<Copy_u8PinID);
			}
			else if (Copy_u8PinValue == GPIO_HIGH)
			{
				GPIOA_BSRR = (1<<Copy_u8PinID);
			}
			else
			{
				// Error
			}
		break;
		case GPIOB :
			if (Copy_u8PinValue == GPIO_LOW)
			{
				Copy_u8PinID += 16;
				GPIOB_BSRR = (1<<Copy_u8PinID);
			}
			else if (Copy_u8PinValue == GPIO_HIGH)
			{
				GPIOB_BSRR = (1<<Copy_u8PinID);
			}
			else
			{
				// Error
			}
		break;
		case GPIOC :
			if (Copy_u8PinValue == GPIO_LOW)
			{
				Copy_u8PinID += 16;
				GPIOC_BSRR = (1<<Copy_u8PinID);
			}
			else if (Copy_u8PinValue == GPIO_HIGH)
			{
				GPIOC_BSRR = (1<<Copy_u8PinID);
			}
			else
			{
				// Error
			}
		break;
		default :
			// error state
		break;
	}
}
/******************** Edited function *******************/
/*void MGPIO_voidAtomicSetPinValue(u8 Copy_u8PortID,u32 Copy_u8PinID,u8 Copy_u8PinValue)
{
	switch(Copy_u8PortID)
	{
		case GPIOA :
			if (Copy_u8PinValue == GPIO_LOW)
			{
				Copy_u8PinID = Copy_u8PinID<<16;
				GPIOA_BSRR = (Copy_u8PinID);
			}
			else if (Copy_u8PinValue == GPIO_HIGH)
			{
				GPIOA_BSRR = (Copy_u8PinID);
			}
			else
			{
				// Error
			}
		break;
		case GPIOB :
			if (Copy_u8PinValue == GPIO_LOW)
			{
				Copy_u8PinID = Copy_u8PinID<<16;
				GPIOB_BSRR = (Copy_u8PinID);
			}
			else if (Copy_u8PinValue == GPIO_HIGH)
			{
				GPIOB_BSRR = (Copy_u8PinID);
			}
			else
			{
				// Error
			}
		break;
		case GPIOC :
			if (Copy_u8PinValue == GPIO_LOW)
			{
				Copy_u8PinID = Copy_u8PinID<<16;
				GPIOC_BSRR = (Copy_u8PinID);
			}
			else if (Copy_u8PinValue == GPIO_HIGH)
			{
				GPIOC_BSRR = (1<<Copy_u8PinID);
			}
			else
			{
				// Error
			}
		break;
		default :
			// error state
		break;
	}
}*/
