/*
 * Author :Hager Badr
 * Version : V0.0
 * Date : 11/Jun/2023
 */
#ifndef _TIMER_PRIV_H_
#define _TIMER_PRIV_H_


typedef	struct
{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SMCR;
	volatile u32 DIER;
	volatile u32 SR;
	volatile u32 EGR;
	volatile u32 CCMR1;
	volatile u32 CCMR2;
	volatile u32 CCER;
	volatile u32 CNT;
	volatile u32 PSC;
	volatile u32 ARR;
	volatile u32 RESERVED_1;
	volatile u32 CCR1;						//capture/compare mode register
	volatile u32 CCR2;
	volatile u32 CCR3;
	volatile u32 CCR4;
	volatile u32 RESERVED_2;
	volatile u32 DCR;
	volatile u32 DMAR;
	volatile u32 OR;
}TIM_PWM_t;


#define TIMER2_BASE		(( TIM_PWM_t *)0x40000000)
#define TIMER3_BASE		(( TIM_PWM_t *)0x40000400)
#define TIMER4_BASE		(( TIM_PWM_t *)0x40000800)
#define TIMER5_BASE		(( TIM_PWM_t *)0x40000C00)

#define CR1_CEN			0
#define CR1_OPM			3
#define CR1_ARPE		7

//#define EGR_UG
//
//#define CCMR1_OC1M
#define CCMR1_OC1PE			3
#define CCMR1_OC2PE			11
#define CCMR2_OC3PE			3
#define CCMR2_OC4PE			11

//#define CCER_CC4P			//enable 4 channel

#define CCER_CC1E			0
#define CCER_CC2E			4
#define CCER_CC3E			8
#define CCER_CC4E			12

#define CCER_CC1P			1
#define CCER_CC2P			5
#define CCER_CC3P			9
#define CCER_CC4P			13





#endif
