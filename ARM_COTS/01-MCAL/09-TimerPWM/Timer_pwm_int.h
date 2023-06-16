/*
 * Author :Hager Badr
 * Version : V0.0
 * Date : 11/Jun/2023
 */
#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


typedef enum
{
	TIMER2,
	TIMER3,
	TIMER4,
	TIMER5
}TIMERN_t;

typedef enum
{
	CHANNEL1 = 1,
	CHANNEL2,
	CHANNEL3,
	CHANNEL4
}CHANNE_t;
void MGTimer_void_Init(TIMERN_t Copy_Timer_No , CHANNE_t Copy_Timer_Channel);
void MGTimer_void_Prescaller(TIMERN_t Copy_Timer_No , u16 Copy_u16Prescaller);
void MGTimer_void_PeriodValue(TIMERN_t Copy_Timer_No , u16 Copy_u16Value);
void MGTimer_void_CompValue(TIMERN_t Copy_Timer_No , CHANNE_t Copy_Timer_Channel, u16 Copy_u16Value);
void MGTimer_voidStartTimer(TIMERN_t Copy_Timer_No);
void MGTimer_voidStopTimer(TIMERN_t Copy_Timer_No);



#endif
