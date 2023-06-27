/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 23 May , 2023
* SWC 	  : IR
* MC 	  : STM32F401X
* LAYER   : HAL
* VERSION : V1.0
********************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "IR_interface.h"
#include "IR_private.h"
#include "IR_config.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SYSTICK_interface.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "SYSCFG_interface.h"

u8 Global_u8StartEdgeFlag = 0;
u32 Global_au32ReceivedFrame[50] = {0};
u8 Global_u8EdgeCounter = 0;
u8 Global_u8ButtonData = 0;

void HIR_voidInit(void)
{
		/* Initialize RCC */
	MRCC_voidInit();
		/* Initialize GPIO */
	MGPIO_voidInit();
		/* Initialize Systick */
	MSTK_voidInit();
		/* Initialize NVIC */
	MNVIC_voidInit();
	
	#if IR_PORT == GPIO_PORTA
			/* Enable clock for IR port and */
		MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA);
			/* select the port of EXTI */
		MSYSCFG_voidSetEXTISourceInput(IR_PIN,SYSCFG_PORTA);
	#elif  IR_PORT == GPIO_PORTB
		MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOB);
		MSYSCFG_voidSetEXTISourceInput(IR_PIN,SYSCFG_PORTB);
	#elif  IR_PORT == GPIO_PORTC
		MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOC);
		MSYSCFG_voidSetEXTISourceInput(IR_PIN,SYSCFG_PORTC);
	#else
		#error "Configuration error : IR port selection error"
	#endif
		
		/* Set IR pin as input */
	MGPIO_voidSetPinMode(IR_PORT,IR_PIN,GPIO_MODE_INPUT);
		/* Set Pull up mode for IR pin output mode */
	MGPIO_voidSetOutputPinMode(IR_PORT,IR_PIN,GPIO_PULL_UP);
	
	#if IR_PIN == GPIO_PIN0
			/* Select Falling edge for EXTI */
		MEXTI_ChangeSenseMode(MEXTI_LINE0, MEXTI_FALLING_EDGE);
			/* Set HIR_voidGetRemoteFrame in EXTI callback function */
		MEXTI_voidSetCallBack(MEXTI_LINE0, &HIR_voidGetRemoteFrame);
			/* Enable EXTI interrupt */
		MEXTI_voidEnableInterrupt(MEXTI_LINE0);
			/* Enable NVIC interrupt */
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);
	#elif IR_PIN == GPIO_PIN1
		MEXTI_ChangeSenseMode(MEXTI_LINE1, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE1, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE1);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI1);
	#elif IR_PIN == GPIO_PIN2
		MEXTI_ChangeSenseMode(MEXTI_LINE2, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE2, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE2);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI2);
	#elif IR_PIN == GPIO_PIN3
		MEXTI_ChangeSenseMode(MEXTI_LINE3, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE3, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE3);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI3);
	#elif IR_PIN == GPIO_PIN4
		MEXTI_ChangeSenseMode(MEXTI_LINE4, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE4, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE4);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI4);
	#elif IR_PIN == GPIO_PIN5
		MEXTI_ChangeSenseMode(MEXTI_LINE5, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE5, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE5);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI5);
	#elif IR_PIN == GPIO_PIN6
		MEXTI_ChangeSenseMode(MEXTI_LINE6, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE6, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE6);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI6);
	#elif IR_PIN == GPIO_PIN7
		MEXTI_ChangeSenseMode(MEXTI_LINE7, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE7, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE7);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI7);
	#elif IR_PIN == GPIO_PIN8
		MEXTI_ChangeSenseMode(MEXTI_LINE8, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE8, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE8);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI8);
	#elif IR_PIN == GPIO_PIN9
		MEXTI_ChangeSenseMode(MEXTI_LINE9, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE9, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE9);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI9);
	#elif IR_PIN == GPIO_PIN10
		MEXTI_ChangeSenseMode(MEXTI_LINE10, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE10, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE10);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI10);
	#elif IR_PIN == GPIO_PIN11
		MEXTI_ChangeSenseMode(MEXTI_LINE11, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE11, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE11);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI11);
	#elif IR_PIN == GPIO_PIN12
		MEXTI_ChangeSenseMode(MEXTI_LINE12, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE12, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE12);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI12);
	#elif IR_PIN == GPIO_PIN13
		MEXTI_ChangeSenseMode(MEXTI_LINE13, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE13, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE13);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI13);
	#elif IR_PIN == GPIO_PIN14
		MEXTI_ChangeSenseMode(MEXTI_LINE14, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE14, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE14);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI14);
	#elif IR_PIN == GPIO_PIN15
		MEXTI_ChangeSenseMode(MEXTI_LINE15, MEXTI_FALLING_EDGE);
		MEXTI_voidSetCallBack(MEXTI_LINE15, &HIR_voidGetRemoteFrame);
		MEXTI_voidEnableInterrupt(MEXTI_LINE15);
		MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI15);
	#else 
		#error "Configuration error : IR pin selection error"
	#endif
}
void HIR_voidGetRemoteFrame(void)
{	
	if(Global_u8StartEdgeFlag == 0)
	{
		MSTK_voidSetSingleInterval(600000,&HIR_voidTakeAction);
		Global_u8StartEdgeFlag = 1;
	}
	else
	{
			/* Get the counted time */
		Global_au32ReceivedFrame[Global_u8EdgeCounter] = MSTK_u32GetElapsedTime();
			/* Reset the timer */
		MSTK_voidResetSystick();
			/* Set Preload Value */
		MSTK_voidSetSingleInterval(600000,&HIR_voidTakeAction);
			/* Increment edge counter */
		Global_u8EdgeCounter++;
	}
}

void HIR_voidTakeAction(void)
{
	u8 Local_u8LoopCounter = 0;
	for(Local_u8LoopCounter = 0;Local_u8LoopCounter<DATA_BITS;Local_u8LoopCounter++)
	{
		if((Global_au32ReceivedFrame[17+Local_u8LoopCounter] >= MIN_OFF_PERIOD)&&(Global_au32ReceivedFrame[17+Local_u8LoopCounter] <=MAX_OFF_PERIOD))
		{
			CLEAR_BIT(Global_u8ButtonData,Local_u8LoopCounter);
		}
		else
		{
			SET_BIT(Global_u8ButtonData,Local_u8LoopCounter);
		}
	}
	Global_u8EdgeCounter = 0;
	Global_u8StartEdgeFlag = 0 ;
}


