
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "timer_interface.h"
#include "timer_priv.h"
#include "timer_conf.h"

void Timer3_voidStart(void)
{
	SET_BIT(TIMER3_BASE -> CR1 , 0);			/* Enable Counter */

	CLEAR_BIT(TIMER3_BASE -> CR1 , 4);		/* counter mode is up counting */
}

void Timer3_u16Count(u16 Copy_u16Count)
{
	TIMER3_BASE -> CNT = Copy_u16Count;	/* Intial Value Of TIMER3_BASE */
}

u32  Timer3_voidReadCaptureVal(void)
{
	return TIMER3_BASE -> CCR1;			/* Return Captured Value */
}

void Timer3_voidPrescale(u16 Copy_u16Prescaler)
{
	TIMER3_BASE -> PSC = Copy_u16Prescaler -1 ;	/* TIMER3_BASE Prescaler */
}



void Timer3_voidCapture_Compare_Init(void)
{
	/*DIER Register*/

	SET_BIT(TIMER3_BASE -> DIER , 1);	/* Capture/Compare interrupt enable */

	/*CCMR1 Register*/

	SET_BIT(TIMER3_BASE -> CCMR1 , 0);	/* configure TIMER3_BASE ch1 as input */
	CLEAR_BIT(TIMER3_BASE -> CCMR1 , 1);

	CLEAR_BIT(TIMER3_BASE -> CCMR1 , 2);	/* configure TIMER3_BASE ch1 to capture at every edge detected */
	CLEAR_BIT(TIMER3_BASE -> CCMR1 , 3);


	CLEAR_BIT(TIMER3_BASE -> CCMR1 , 6);
	CLEAR_BIT(TIMER3_BASE -> CCMR1 , 7);

	/*CCER Register*/

	SET_BIT(TIMER3_BASE -> CCER , 0);	/* Capture Enabled */


	SET_BIT(TIMER3_BASE -> CCER , 1);	/* Capture/Compare channel captures on both edges (rising & falling) */
	SET_BIT(TIMER3_BASE -> CCER , 3);

	Timer3_voidPrescale(72);

	TIMER3_BASE -> ARR = 65535;			/*Max of Ticks*/

}


void MGTimer2_void_Init()
{
	/*Select output mode*/
	CLEAR_BIT(TIMER2_BASE -> CCMR2, 0);
	CLEAR_BIT(TIMER2_BASE -> CCMR2, 1);
	/*Select polarity as Active High*/
	CLEAR_BIT(TIMER2_BASE -> CCER, CCER_CC3P);
	/*Select PWM mode 1*/
	CLEAR_BIT(TIMER2_BASE -> CCMR2,4);
	SET_BIT(TIMER2_BASE -> CCMR2,5);
	SET_BIT(TIMER2_BASE -> CCMR2,6);

	SET_BIT(TIMER2_BASE -> CCMR2,CCMR2_OC3PE);
	/*Enable capture compare*/
	SET_BIT(TIMER2_BASE -> CCER, CCER_CC3E);

	CLEAR_BIT(TIMER2_BASE -> CR1,CR1_ARPE);
	/*Select counting mode*/
	CLEAR_BIT(TIMER2_BASE -> CR1,4);
	CLEAR_BIT(TIMER2_BASE -> CR1,5);
	CLEAR_BIT(TIMER2_BASE -> CR1,6);
}
void MGTimer2_void_Prescaller(u16 Copy_u16Prescaller)
{
	Clr_ALL_BITS(TIMER2_BASE -> PSC);
	TIMER2_BASE -> PSC |=Copy_u16Prescaller;
}
void MGTimer2_void_PeriodValue(u16 Copy_u16Value)
{
	TIMER2_BASE -> ARR =Copy_u16Value;

}
void MGTimer2_void_CompValue(u16 Copy_u16Value)
{
	TIMER2_BASE -> CCR3 =Copy_u16Value;

}
void MGTimer2_voidStartTimer()
{
	SET_BIT(TIMER2_BASE -> CR1, CR1_CEN);

}
void MGTimer2_voidStopTimer()
{
	CLEAR_BIT(TIMER2_BASE -> CR1, CR1_CEN);

}














