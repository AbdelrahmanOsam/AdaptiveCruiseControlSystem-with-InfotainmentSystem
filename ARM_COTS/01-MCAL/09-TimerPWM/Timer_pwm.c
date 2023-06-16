/*
 * Author :Hager Badr
 * Version : V0.0
 * Date : 11/Jun/2023
 * Description : Timer_pwm.c --> Functions' Implementation
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Timer_pwm_int.h"
#include "Timer_pwm_priv.h"
#include "Timer_pwm_config.h"



void MGTimer_void_Init(TIMERN_t Copy_Timer_No ,CHANNE_t Copy_Timer_Channel)
{
	switch(Copy_Timer_No)
	{
	case TIMER2:

		switch(Copy_Timer_Channel)
		{
		case CHANNEL1:

			/*Select output mode*/
			CLR_BIT(TIMER2_BASE -> CCMR1, 0);
			CLR_BIT(TIMER2_BASE -> CCMR1, 1);
			/*Select polarity as Active High*/
			CLR_BIT(TIMER2_BASE -> CCER, CCER_CC1P);
			/*Select PWM mode 1*/
#if 	PWM_MODE == PWM_MODE1
			CLR_BIT(TIMER2_BASE -> CCMR1,4);
			SET_BIT(TIMER2_BASE -> CCMR1,5);
			SET_BIT(TIMER2_BASE -> CCMR1,6);
#elif 	PWM_MODE == PWM_MODE2
			SET_BIT(TIMER2_BASE -> CCMR1,4);
			SET_BIT(TIMER2_BASE -> CCMR1,5);
			SET_BIT(TIMER2_BASE -> CCMR1,6);
#endif
			/*Set preload value*/
			SET_BIT(TIMER2_BASE -> CCMR1,CCMR1_OC1PE);
			/*Enable capture compare*/
			SET_BIT(TIMER2_BASE -> CCER, CCER_CC1E);
			break;
		case CHANNEL2:
			/*Select output mode*/
			CLR_BIT(TIMER2_BASE -> CCMR1, 8);
			CLR_BIT(TIMER2_BASE -> CCMR1, 9);
			/*Select polarity as Active High*/
			CLR_BIT(TIMER2_BASE -> CCER, CCER_CC2P);
			/*Select PWM mode 1*/
#if 	PWM_MODE == PWM_MODE1
			CLR_BIT(TIMER2_BASE -> CCMR1,12);
			SET_BIT(TIMER2_BASE -> CCMR1,13);
			SET_BIT(TIMER2_BASE -> CCMR1,14);
#elif 	PWM_MODE == PWM_MODE2
			SET_BIT(TIMER2_BASE -> CCMR1,12);
			SET_BIT(TIMER2_BASE -> CCMR1,13);
			SET_BIT(TIMER2_BASE -> CCMR1,14);
#endif
			SET_BIT(TIMER2_BASE -> CCMR1,CCMR1_OC2PE);
			/*Enable capture compare*/
			SET_BIT(TIMER2_BASE -> CCER, CCER_CC2E);
			break;
		case CHANNEL3:
			/*Select output mode*/
			CLR_BIT(TIMER2_BASE -> CCMR2, 0);
			CLR_BIT(TIMER2_BASE -> CCMR2, 1);
			/*Select polarity as Active High*/
			CLR_BIT(TIMER2_BASE -> CCER, CCER_CC3P);
			/*Select PWM mode 1*/
#if 	PWM_MODE == PWM_MODE1
			CLR_BIT(TIMER2_BASE -> CCMR2,4);
			SET_BIT(TIMER2_BASE -> CCMR2,5);
			SET_BIT(TIMER2_BASE -> CCMR2,6);
#elif 	PWM_MODE == PWM_MODE2
			SET_BIT(TIMER2_BASE -> CCMR2,4);
			SET_BIT(TIMER2_BASE -> CCMR2,5);
			SET_BIT(TIMER2_BASE -> CCMR2,6);
#endif
			SET_BIT(TIMER2_BASE -> CCMR2,CCMR2_OC3PE);
			/*Enable capture compare*/
			SET_BIT(TIMER2_BASE -> CCER, CCER_CC3E);
			break;
		case CHANNEL4:
			/*Select output mode*/
			CLR_BIT(TIMER2_BASE -> CCMR2, 8);
			CLR_BIT(TIMER2_BASE -> CCMR2, 9);
			/*Select polarity as Active High*/
			CLR_BIT(TIMER2_BASE -> CCER, CCER_CC2P);
			/*Select PWM mode 1*/
#if 	PWM_MODE == PWM_MODE1
			CLR_BIT(TIMER2_BASE -> CCMR2,12);
			SET_BIT(TIMER2_BASE -> CCMR2,13);
			SET_BIT(TIMER2_BASE -> CCMR2,14);
#elif 	PWM_MODE == PWM_MODE2
			SET_BIT(TIMER2_BASE -> CCMR2,12);
			SET_BIT(TIMER2_BASE -> CCMR2,13);
			SET_BIT(TIMER2_BASE -> CCMR2,14);
#endif
			SET_BIT(TIMER2_BASE -> CCMR2,CCMR2_OC4PE);
			/*Enable capture compare*/
			SET_BIT(TIMER2_BASE -> CCER, CCER_CC4E);
			break;
		default: 								break;
		}
		SET_BIT(TIMER2_BASE -> CR1,CR1_ARPE);
		/*Select counting mode*/
		CLR_BIT(TIMER2_BASE -> CR1,4);
		CLR_BIT(TIMER2_BASE -> CR1,5);
		CLR_BIT(TIMER2_BASE -> CR1,6);
		break;
		case TIMER3:
			switch(Copy_Timer_Channel)
			{
			case CHANNEL1:

				/*Select output mode*/
				CLR_BIT(TIMER3_BASE -> CCMR1, 0);
				CLR_BIT(TIMER3_BASE -> CCMR1, 1);
				/*Select polarity as Active High*/
				CLR_BIT(TIMER3_BASE -> CCER, CCER_CC1P);
				/*Select PWM mode 1*/
	#if 	PWM_MODE == PWM_MODE1
				CLR_BIT(TIMER3_BASE -> CCMR1,4);
				SET_BIT(TIMER3_BASE -> CCMR1,5);
				SET_BIT(TIMER3_BASE -> CCMR1,6);
	#elif 	PWM_MODE == PWM_MODE2
				SET_BIT(TIMER3_BASE -> CCMR1,4);
				SET_BIT(TIMER3_BASE -> CCMR1,5);
				SET_BIT(TIMER3_BASE -> CCMR1,6);
	#endif
				SET_BIT(TIMER3_BASE -> CCMR1,CCMR1_OC1PE);
				/*Enable capture compare*/
				SET_BIT(TIMER3_BASE -> CCER, CCER_CC1E);
				break;
			case CHANNEL2:
				/*Select output mode*/
				CLR_BIT(TIMER3_BASE -> CCMR1, 8);
				CLR_BIT(TIMER3_BASE -> CCMR1, 9);
				/*Select polarity as Active High*/
				CLR_BIT(TIMER3_BASE -> CCER, CCER_CC2P);
				/*Select PWM mode 1*/
	#if 	PWM_MODE == PWM_MODE1
				CLR_BIT(TIMER3_BASE -> CCMR1,12);
				SET_BIT(TIMER3_BASE -> CCMR1,13);
				SET_BIT(TIMER3_BASE -> CCMR1,14);
	#elif 	PWM_MODE == PWM_MODE2
				SET_BIT(TIMER3_BASE -> CCMR1,12);
				SET_BIT(TIMER3_BASE -> CCMR1,13);
				SET_BIT(TIMER3_BASE -> CCMR1,14);
	#endif
				SET_BIT(TIMER3_BASE -> CCMR1,CCMR1_OC2PE);
				/*Enable capture compare*/
				SET_BIT(TIMER3_BASE -> CCER, CCER_CC2E);
				break;
			case CHANNEL3:
				/*Select output mode*/
				CLR_BIT(TIMER3_BASE -> CCMR2, 0);
				CLR_BIT(TIMER3_BASE -> CCMR2, 1);
				/*Select polarity as Active High*/
				CLR_BIT(TIMER3_BASE -> CCER, CCER_CC3P);
				/*Select PWM mode 1*/
	#if 	PWM_MODE == PWM_MODE1
				CLR_BIT(TIMER3_BASE -> CCMR2,4);
				SET_BIT(TIMER3_BASE -> CCMR2,5);
				SET_BIT(TIMER3_BASE -> CCMR2,6);
	#elif 	PWM_MODE == PWM_MODE2
				SET_BIT(TIMER3_BASE -> CCMR2,4);
				SET_BIT(TIMER3_BASE -> CCMR2,5);
				SET_BIT(TIMER3_BASE -> CCMR2,6);
	#endif
				SET_BIT(TIMER3_BASE -> CCMR2,CCMR2_OC3PE);
				/*Enable capture compare*/
				SET_BIT(TIMER3_BASE -> CCER, CCER_CC3E);
				break;
			case CHANNEL4:
				/*Select output mode*/
				CLR_BIT(TIMER3_BASE -> CCMR2, 8);
				CLR_BIT(TIMER3_BASE -> CCMR2, 9);
				/*Select polarity as Active High*/
				CLR_BIT(TIMER3_BASE -> CCER, CCER_CC2P);
				/*Select PWM mode 1*/
	#if 	PWM_MODE == PWM_MODE1
				CLR_BIT(TIMER3_BASE -> CCMR2,12);
				SET_BIT(TIMER3_BASE -> CCMR2,13);
				SET_BIT(TIMER3_BASE -> CCMR2,14);
	#elif 	PWM_MODE == PWM_MODE2
				SET_BIT(TIMER3_BASE -> CCMR2,12);
				SET_BIT(TIMER3_BASE -> CCMR2,13);
				SET_BIT(TIMER3_BASE -> CCMR2,14);
	#endif
				SET_BIT(TIMER3_BASE -> CCMR2,CCMR2_OC4PE);
				/*Enable capture compare*/
				SET_BIT(TIMER3_BASE -> CCER, CCER_CC4E);
				break;
			default: 								break;
			}
			SET_BIT(TIMER3_BASE -> CR1,CR1_ARPE);
			/*Select counting mode*/
			CLR_BIT(TIMER3_BASE -> CR1,4);
			CLR_BIT(TIMER3_BASE -> CR1,5);
			CLR_BIT(TIMER3_BASE -> CR1,6);
			break;
			case TIMER4:

				switch(Copy_Timer_Channel)
				{
				case CHANNEL1:

					/*Select output mode*/
					CLR_BIT(TIMER4_BASE -> CCMR1, 0);
					CLR_BIT(TIMER4_BASE -> CCMR1, 1);
					/*Select polarity as Active High*/
					CLR_BIT(TIMER4_BASE -> CCER, CCER_CC1P);
					/*Select PWM mode 1*/
		#if 	PWM_MODE == PWM_MODE1
					CLR_BIT(TIMER4_BASE -> CCMR1,4);
					SET_BIT(TIMER4_BASE -> CCMR1,5);
					SET_BIT(TIMER4_BASE -> CCMR1,6);
		#elif 	PWM_MODE == PWM_MODE2
					SET_BIT(TIMER4_BASE -> CCMR1,4);
					SET_BIT(TIMER4_BASE -> CCMR1,5);
					SET_BIT(TIMER4_BASE -> CCMR1,6);
		#endif
					SET_BIT(TIMER4_BASE -> CCMR1,CCMR1_OC1PE);
					/*Enable capture compare*/
					SET_BIT(TIMER4_BASE -> CCER, CCER_CC1E);
					break;
				case CHANNEL2:
					/*Select output mode*/
					CLR_BIT(TIMER4_BASE -> CCMR1, 8);
					CLR_BIT(TIMER4_BASE -> CCMR1, 9);
					/*Select polarity as Active High*/
					CLR_BIT(TIMER4_BASE -> CCER, CCER_CC2P);
					/*Select PWM mode 1*/
		#if 	PWM_MODE == PWM_MODE1
					CLR_BIT(TIMER4_BASE -> CCMR1,12);
					SET_BIT(TIMER4_BASE -> CCMR1,13);
					SET_BIT(TIMER4_BASE -> CCMR1,14);
		#elif 	PWM_MODE == PWM_MODE2
					SET_BIT(TIMER4_BASE -> CCMR1,12);
					SET_BIT(TIMER4_BASE -> CCMR1,13);
					SET_BIT(TIMER4_BASE -> CCMR1,14);
		#endif
					SET_BIT(TIMER4_BASE -> CCMR1,CCMR1_OC2PE);
					/*Enable capture compare*/
					SET_BIT(TIMER4_BASE -> CCER, CCER_CC2E);
					break;
				case CHANNEL3:
					/*Select output mode*/
					CLR_BIT(TIMER4_BASE -> CCMR2, 0);
					CLR_BIT(TIMER4_BASE -> CCMR2, 1);
					/*Select polarity as Active High*/
					CLR_BIT(TIMER4_BASE -> CCER, CCER_CC3P);
					/*Select PWM mode 1*/
		#if 	PWM_MODE == PWM_MODE1
					CLR_BIT(TIMER4_BASE -> CCMR2,4);
					SET_BIT(TIMER4_BASE -> CCMR2,5);
					SET_BIT(TIMER4_BASE -> CCMR2,6);
		#elif 	PWM_MODE == PWM_MODE2
					SET_BIT(TIMER4_BASE -> CCMR2,4);
					SET_BIT(TIMER4_BASE -> CCMR2,5);
					SET_BIT(TIMER4_BASE -> CCMR2,6);
		#endif
					SET_BIT(TIMER4_BASE -> CCMR2,CCMR2_OC3PE);
					/*Enable capture compare*/
					SET_BIT(TIMER4_BASE -> CCER, CCER_CC3E);
					break;
				case CHANNEL4:
					/*Select output mode*/
					CLR_BIT(TIMER4_BASE -> CCMR2, 8);
					CLR_BIT(TIMER4_BASE -> CCMR2, 9);
					/*Select polarity as Active High*/
					CLR_BIT(TIMER4_BASE -> CCER, CCER_CC2P);
					/*Select PWM mode 1*/
		#if 	PWM_MODE == PWM_MODE1
					CLR_BIT(TIMER4_BASE -> CCMR2,12);
					SET_BIT(TIMER4_BASE -> CCMR2,13);
					SET_BIT(TIMER4_BASE -> CCMR2,14);
		#elif 	PWM_MODE == PWM_MODE2
					SET_BIT(TIMER4_BASE -> CCMR2,12);
					SET_BIT(TIMER4_BASE -> CCMR2,13);
					SET_BIT(TIMER4_BASE -> CCMR2,14);
		#endif
					SET_BIT(TIMER4_BASE -> CCMR2,CCMR2_OC4PE);
					/*Enable capture compare*/
					SET_BIT(TIMER4_BASE -> CCER, CCER_CC4E);
					break;
				default: 								break;
				}
				SET_BIT(TIMER4_BASE -> CR1,CR1_ARPE);
				/*Select counting mode*/
				CLR_BIT(TIMER4_BASE -> CR1,4);
				CLR_BIT(TIMER4_BASE -> CR1,5);
				CLR_BIT(TIMER4_BASE -> CR1,6);
				break;

				case TIMER5:
				switch(Copy_Timer_Channel)
					{
				case CHANNEL1:

					/*Select output mode*/
					CLR_BIT(TIMER5_BASE -> CCMR1, 0);
					CLR_BIT(TIMER5_BASE -> CCMR1, 1);
					/*Select polarity as Active High*/
					CLR_BIT(TIMER5_BASE -> CCER, CCER_CC1P);
					/*Select PWM mode 1*/
		#if 	PWM_MODE == PWM_MODE1
					CLR_BIT(TIMER5_BASE -> CCMR1,4);
					SET_BIT(TIMER5_BASE -> CCMR1,5);
					SET_BIT(TIMER5_BASE -> CCMR1,6);
		#elif 	PWM_MODE == PWM_MODE2
					SET_BIT(TIMER5_BASE -> CCMR1,4);
					SET_BIT(TIMER5_BASE -> CCMR1,5);
					SET_BIT(TIMER5_BASE -> CCMR1,6);
		#endif
					SET_BIT(TIMER5_BASE -> CCMR1,CCMR1_OC1PE);
					/*Enable capture compare*/
					SET_BIT(TIMER5_BASE -> CCER, CCER_CC1E);
					break;
				case CHANNEL2:
					/*Select output mode*/
					CLR_BIT(TIMER5_BASE -> CCMR1, 8);
					CLR_BIT(TIMER5_BASE -> CCMR1, 9);
					/*Select polarity as Active High*/
					CLR_BIT(TIMER5_BASE -> CCER, CCER_CC2P);
					/*Select PWM mode 1*/
		#if 	PWM_MODE == PWM_MODE1
					CLR_BIT(TIMER5_BASE -> CCMR1,12);
					SET_BIT(TIMER5_BASE -> CCMR1,13);
					SET_BIT(TIMER5_BASE -> CCMR1,14);
		#elif 	PWM_MODE == PWM_MODE2
					SET_BIT(TIMER5_BASE -> CCMR1,12);
					SET_BIT(TIMER5_BASE -> CCMR1,13);
					SET_BIT(TIMER5_BASE -> CCMR1,14);
		#endif
					SET_BIT(TIMER5_BASE -> CCMR1,CCMR1_OC2PE);
					/*Enable capture compare*/
					SET_BIT(TIMER5_BASE -> CCER, CCER_CC2E);
					break;
				case CHANNEL3:
					/*Select output mode*/
					CLR_BIT(TIMER5_BASE -> CCMR2, 0);
					CLR_BIT(TIMER5_BASE -> CCMR2, 1);
					/*Select polarity as Active High*/
					CLR_BIT(TIMER5_BASE -> CCER, CCER_CC3P);
					/*Select PWM mode 1*/
		#if 	PWM_MODE == PWM_MODE1
					CLR_BIT(TIMER5_BASE -> CCMR2,4);
					SET_BIT(TIMER5_BASE -> CCMR2,5);
					SET_BIT(TIMER5_BASE -> CCMR2,6);
		#elif 	PWM_MODE == PWM_MODE2
					SET_BIT(TIMER5_BASE -> CCMR2,4);
					SET_BIT(TIMER5_BASE -> CCMR2,5);
					SET_BIT(TIMER5_BASE -> CCMR2,6);
		#endif
					SET_BIT(TIMER5_BASE -> CCMR2,CCMR2_OC3PE);
					/*Enable capture compare*/
					SET_BIT(TIMER5_BASE -> CCER, CCER_CC3E);
					break;
				case CHANNEL4:
					/*Select output mode*/
					CLR_BIT(TIMER5_BASE -> CCMR2, 8);
					CLR_BIT(TIMER5_BASE -> CCMR2, 9);
					/*Select polarity as Active High*/
					CLR_BIT(TIMER5_BASE -> CCER, CCER_CC2P);
					/*Select PWM mode 1*/
		#if 	PWM_MODE == PWM_MODE1
					CLR_BIT(TIMER5_BASE -> CCMR2,12);
					SET_BIT(TIMER5_BASE -> CCMR2,13);
					SET_BIT(TIMER5_BASE -> CCMR2,14);
		#elif 	PWM_MODE == PWM_MODE2
					SET_BIT(TIMER5_BASE -> CCMR2,12);
					SET_BIT(TIMER5_BASE -> CCMR2,13);
					SET_BIT(TIMER5_BASE -> CCMR2,14);
		#endif
					SET_BIT(TIMER5_BASE -> CCMR2,CCMR2_OC4PE);
					/*Enable capture compare*/
					SET_BIT(TIMER5_BASE -> CCER, CCER_CC4E);
					break;
				default: 								break;
				}
				SET_BIT(TIMER5_BASE -> CR1,CR1_ARPE);
				/*Select counting mode*/
				CLR_BIT(TIMER5_BASE -> CR1,4);
				CLR_BIT(TIMER5_BASE -> CR1,5);
				CLR_BIT(TIMER5_BASE -> CR1,6);
				break;
				default: 										break;
	}
}
void MGTimer_void_Prescaller(TIMERN_t Copy_Timer_No , u16 Copy_u16Prescaller)
{
	switch(Copy_Timer_No)
	{
	case TIMER2:
		TIMER2_BASE -> PSC =Copy_u16Prescaller;
		break;
	case TIMER3:
		TIMER3_BASE -> PSC =Copy_u16Prescaller;
		break;
	case TIMER4:
		TIMER4_BASE -> PSC =Copy_u16Prescaller;
		break;
	case TIMER5:
		TIMER5_BASE -> PSC =Copy_u16Prescaller;
		break;
	default:
		break;
	}
}
void MGTimer_void_PeriodValue(TIMERN_t Copy_Timer_No , u16 Copy_u16Value)
{
	switch(Copy_Timer_No)
	{
	case TIMER2:
		TIMER2_BASE -> ARR =Copy_u16Value;
		break;
	case TIMER3:
		TIMER3_BASE -> ARR =Copy_u16Value;
		break;
	case TIMER4:
		TIMER4_BASE -> ARR =Copy_u16Value;
		break;
	case TIMER5:
		TIMER5_BASE -> ARR =Copy_u16Value;
		break;
	default:
		break;
	}
}
void MGTimer_void_CompValue(TIMERN_t Copy_Timer_No , CHANNE_t Copy_Timer_Channel, u16 Copy_u16Value)
{
	switch(Copy_Timer_No)
	{

	case TIMER2:
		switch(Copy_Timer_Channel)
		{
		case CHANNEL1:
			TIMER2_BASE -> CCR1 =Copy_u16Value;
			break;
		case CHANNEL2:
			TIMER2_BASE -> CCR2 =Copy_u16Value;
			break;
		case CHANNEL3:
			TIMER2_BASE -> CCR3 =Copy_u16Value;
			break;
		case CHANNEL4:
			TIMER2_BASE -> CCR4 =Copy_u16Value;
			break;
		default:
			break;
		}
		break;
	case TIMER3:
		switch(Copy_Timer_Channel)
		{
		case CHANNEL1:
			TIMER3_BASE -> CCR1 =Copy_u16Value;
			break;
		case CHANNEL2:
			TIMER3_BASE -> CCR2 =Copy_u16Value;
			break;
		case CHANNEL3:
			TIMER3_BASE -> CCR3 =Copy_u16Value;
			break;
		case CHANNEL4:
			TIMER3_BASE -> CCR4 =Copy_u16Value;
			break;
		default:
			break;
		}
		break;
	case TIMER4:
		switch(Copy_Timer_Channel)
		{
		case CHANNEL1:
			TIMER4_BASE -> CCR1 =Copy_u16Value;
			break;
		case CHANNEL2:
			TIMER4_BASE -> CCR2 =Copy_u16Value;
			break;
		case CHANNEL3:
			TIMER4_BASE -> CCR3 =Copy_u16Value;
			break;
		case CHANNEL4:
			TIMER4_BASE -> CCR4 =Copy_u16Value;
			break;
		default:
			break;
		}
		break;
	case TIMER5:
		switch(Copy_Timer_Channel)
		{
		case CHANNEL1:
			TIMER5_BASE -> CCR1 =Copy_u16Value;
			break;
		case CHANNEL2:
			TIMER5_BASE -> CCR2 =Copy_u16Value;
			break;
		case CHANNEL3:
			TIMER5_BASE -> CCR3 =Copy_u16Value;
			break;
		case CHANNEL4:
			TIMER5_BASE -> CCR4 =Copy_u16Value;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
void MGTimer_voidStartTimer(TIMERN_t Copy_Timer_No)
{
	/*Enable Counter*/
	switch(Copy_Timer_No)
	{
	case TIMER2:
		SET_BIT(TIMER2_BASE -> CR1, CR1_CEN);
		break;
	case TIMER3:
		SET_BIT(TIMER3_BASE -> CR1, CR1_CEN);
		break;
	case TIMER4:
		SET_BIT(TIMER4_BASE -> CR1, CR1_CEN);
		break;
	case TIMER5:
		SET_BIT(TIMER5_BASE -> CR1, CR1_CEN);
		break;
	}
}




void MGTimer_voidStopTimer(TIMERN_t Copy_Timer_No)
{
	switch(Copy_Timer_No)
	{
	case TIMER2:
		CLR_BIT(TIMER2_BASE -> CR1, CR1_CEN);
		break;
	case TIMER3:
		CLR_BIT(TIMER3_BASE -> CR1, CR1_CEN);
		break;
	case TIMER4:
		CLR_BIT(TIMER4_BASE -> CR1, CR1_CEN);
		break;
	case TIMER5:
		CLR_BIT(TIMER5_BASE -> CR1, CR1_CEN);
		break;
	}
}
