/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 2 May , 2023
* SWC 	  : GPIO
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#ifndef GPIO_CONFIG_H
#define GPIO_CONFIG_H

#define GPIOA_OUTPUT_MODE_SELECTION		OUTPUT_PUSH_PULL
#define GPIOB_OUTPUT_MODE_SELECTION		OUTPUT_PUSH_PULL
#define GPIOC_OUTPUT_MODE_SELECTION		OUTPUT_PUSH_PULL
/* Options :-
			OUTPUT_PUSH_PULL
			OUTPUT_OPEN_DRAIN
	*/
#define GPIOA_OUTPUT_SPEED_SELECTION	LOW_SPEED
#define GPIOB_OUTPUT_SPEED_SELECTION	MEDIUM_SPEED
#define GPIOC_OUTPUT_SPEED_SELECTION	HIGH_SPEED
/* Options :-
			LOW_SPEED
			MEDIUM_SPEED
			HIGH_SPEED
			VERY_HIGH_SPEED
	*/
#define GPIOA_PULL_MODE_SELECTION	NO_PULL	
#define GPIOB_PULL_MODE_SELECTION	PULL_UP
#define GPIOC_PULL_MODE_SELECTION	PULL_DOWN
/* Options :-
			NO_PULL	
			PULL_UP
			PULL_DOWN
	*/
#endif
