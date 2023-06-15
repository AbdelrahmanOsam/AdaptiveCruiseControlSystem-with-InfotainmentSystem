/*******************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 6 June , 2023
* SWC	  : USART
* Layer	  : MCAL
* MC 	  : STM32F401CC
* Version : V1.0
*******************************************************/

#ifndef USART_CONFIG_H
#define USART_CONFIG_H

/* Select Over sampling */
#define MUSART1_OVERSAMPLING_SELECTION			EIGHT_OVERSAMPLING_MODE
/* Options :-
		SIXTEEN_OVERSAMPLING_MODE
		EIGHT_OVERSAMPLING_MODE
	*/
/* Select the word size that will transmitted */
#define MUSART1_WORD_SIZE_SELECTION				EIGHT_BIT_MODE
/* Options :-	
		EIGHT_BIT_MODE
		NINE_BIT_MODE
	*/

/* Select the wakeup mode for the frame */
#define MUSART1_WAKEUP_METHOD					IDLE_LINE_METHOD
/* Options :-
		IDLE_LINE_METHOD
		ADDRESS_MARK_METHOD
	*/
		
/* Select Enable parity bit or no */
#define MUSART1_PARITY_ENABLEMENT				DISABLED
/* Options :-
		ENABLED
		DISABLED
	*/

/* Select no of bits for tha parity */
#define MUSART1_PARITY_SELECTION				EVEN_PARITY_MODE
/* Options :-
		EVEN_PARITY_MODE
		ODD_PARITY_MODE
	*/
	
/* Select to enable or disable Parity interrupt */
#define MUSART1_PARRITY_INTERRUPT_SELECTION		DISABLED
/* Options :-
		ENABLED
		DISABLED
	*/

/* Select to enable or disable transmission register empty interrupt */
#define MUSART1_TXE_INTERRUPT_SELECTION			DISABLED
/* options :-
		ENABLED
		DISABLED
	*/

/* Select to enable or disable transmission completed interrupt */	
#define MUSART1_TRANSMISSION_COMPLETED_INTERRUPT_SELECTION	DISABLED
/* options :-
		ENABLED
		DISABLED
	*/

/* Select to enable or disable receiver not empty interrupt */
#define MUSART1_RXNE_INTERRUPT_SELECTION		DISABLED
/* options :-
		ENABLED
		DISABLED
	*/

/* Select to enable or disable IDLE interrupt */
#define MUSART1_IDLE_INTERRUPT_SELECTION		DISABLED
/* options :-
		ENABLED
		DISABLED
	*/

/* Select receiver wakeup mode */	
#define MUSART1_RECEIVER_WAKEUP_MODE_SELECTION	MUTE_MODE
/* options :-
		ACTIVE_MODE
		MUTE_MODE
	*/

/* Select to enable or disable send break */
#define MUSART1_SEND_BREAK_ENABLEMENT			DISABLED
/* options :-
		ENABLED
		DISABLED
	*/

/* select tha stop bit size */
#define MUSART1_STOP_BIT_SELECTION				ONE_STOP_BIT
/* Options :-
		HALF_STOP_BIT
		ONE_STOP_BIT
		TWO_STOP_BIT
		ONE_HALF_STOP_BIT
	*/

/* Select the USART mode */
#define MUSART1_MODE_SELECTION					ASYNCHRONOUS_MODE
/* Options :-
		ASYNCHRONOUS_MODE
		SYNCHRONOUS_MODE
	*/
	
/* Select clock polarity mode */
#define MUSART1_CLOCK_POLARITY_SELECTION		STEADY_LOW_MODE
/* Options :-
		STEADY_LOW_MODE
		STEADY_HIGH_MODE
	*/
#endif