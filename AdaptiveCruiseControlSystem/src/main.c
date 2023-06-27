
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_interface.h"
#include "NVIC_interface.h"
#include "timer_interface.h"
#include "Ultrasonic.h"
#include "ACC.h"
#include "Emergency_stop.h"
#include "SpeedLevel.h"
#include "EXTI_interface.h"
#include "SYSCFG_interface.h"
#include "IR_interface.h"
#include "MotorDirections_interface.h"

extern volatile u8 User_Range;
extern volatile u8 User_SpeedSelcted;


void main()
{
	/*--------------------------------------- System Clock initialization  ----------------------------------------------------*/
	MRCC_voidInit();
	/*--------------------------------------- TIMER3 & UltraSonic ----------------------------------------------------*/
	/*GPIO pins initialization*/
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOA); 				/* Enable GPIOA Clock */
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN6,GPIO_MODE_AF);			/* Set PinA6 Alternative (ECHO PIN of UltraSonic) */
	MGPIO_voidSetAlternativeMode(GPIO_PORTA,GPIO_PIN6,2);
	MRCC_voidEnablePeripheralClock(RCC_APB1,RCC_TIMER3);				/* Enable TIM3 Clock */
	MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN5,GPIO_MODE_OUTPUT);		/* Set PinA5 OUTPUT (Trigger PIN of UltraSonic) */
	MNVIC_voidInit();
	/*Interrupt initialization*/
	MNVIC_voidEnablePeripheralInterrupt(29); 							/* Enable Timer3 Global Interrupt */

	/*Timer initialization*/
	Timer3_voidCapture_Compare_Init();									/*Timer initialization*/
	Timer3_voidStart();													/*Timer Start*/

	/*--------------------------------------- TIMER2 & Motors ----------------------------------------------------*/
	MRCC_voidEnablePeripheralClock(RCC_AHB1,RCC_GPIOB);
	MGPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN10,GPIO_MODE_AF);			/* Set PinA6 Alternative (ECHO PIN of UltraSonic) */
	MGPIO_voidSetAlternativeMode(GPIO_PORTB,GPIO_PIN10,1);
	MGTimer2_void_Init();
	MGTimer2_void_Prescaller(160);
	MGTimer2_void_PeriodValue(1000-1);

	HIR_voidInit();
	Moter_VoidCarInit();






	User_Range = FAR;
	User_SpeedSelcted = 25;
	while(1)
	{
//		Ultrsonic_Trigger();
//		Emergency_StopvoidInit();
//		ACC_voidInit();
//		SpeedLevel_voidInit();
	Moter_VoidCarStop();
	ACCOFF_voidInit();
	}

}



