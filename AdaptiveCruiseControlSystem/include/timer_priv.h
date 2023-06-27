

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

/***************************************************************************************/
/* 							Timers Base Addresses									   */
/***************************************************************************************/

#define Timer2_BASE_ADDRESS		(0x40000000)
#define Timer3_BASE_ADDRESS		(0x40000400)

typedef struct
{
	u32	volatile CR1		;
	u32	volatile CR2		;
	u32 volatile SMCR		;
	u32 volatile DIER		;
	u32 volatile SR			;
	u32 volatile EGR		;
	u32 volatile CCMR1		;
	u32 volatile CCMR2		;
	u32 volatile CCER		;
	u32 volatile CNT		;
	u32 volatile PSC		;
	u32 volatile ARR		;
	u32 volatile RESERVED_1	;
	u32 volatile CCR1		;
	u32 volatile CCR2		;
	u32 volatile CCR3		;
	u32 volatile CCR4		;
	u32 volatile RESERVED_2	;
	u32 volatile DCR		;
	u32 volatile DMAR		;
	u32 volatile QR			;

}TIMR_t;
//#define TIMER2_BASE		(( TIMR_t *) (Timer2_BASE_ADDRESS))
//#define Timer3		((TIMR_t *) (Timer3_BASE_ADDRESS))



#define TIMER2_BASE		(( TIMR_t *)0x40000000)
#define TIMER3_BASE		((TIMR_t *) (Timer3_BASE_ADDRESS))
#define TIMER4_BASE		(( TIMR_t *)0x40000800)
#define TIMER5_BASE		(( TIMR_t *)0x40000C00)

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







#endif /* TIMER_PRIVATE_H_ */
