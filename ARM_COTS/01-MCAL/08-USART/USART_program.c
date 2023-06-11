/*******************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 6 June , 2023
* SWC	  : USART
* Layer	  : MCAL
* MC 	  : STM32F401CC
* Version : V1.0
*******************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void MUSART_voidInit(void)
{
	/*********************** USART1 configurations ***********************/
	
	
	/* Set Oversampling mode*/
	#if MUSART1_OVERSAMPLING_SELECTION == SIXTEEN_OVERSAMPLING_MODE
		CLEAR_BIT(MUSART1->CR1,MUSART_CR1_OVER8);
	#elif MUSART1_OVERSAMPLING_SELECTION == EIGHT_OVERSAMPLING_MODE
		SET_BIT(MUSART1->CR1,MUSART_CR1_OVER8);
	#else
		#error "Configuration error : USART1 oversampling mode selection"
	#endif
	
	/* Set The Data size */
	#if MUSART1_WORD_SIZE_SELECTION == EIGHT_BIT_MODE
		CLEAR_BIT(MUSART1->CR1,MUSART_CR1_M);
	#elif MUSART1_WORD_SIZE_SELECTION == NINE_BIT_MODE
		SET_BIT(MUSART1->CR1,MUSART_CR1_M);
	#else 
		#error "Configuration error : USART1 word size selection error"
	#endif
	
	/* Set The wake up method */
	#if MUSART1_WAKEUP_METHOD == IDLE_LINE_METHOD
		CLEAR_BIT(MUSART1->CR1,MUSART1_CR1_WAKE);
	#elif MUSART1_WAKEUP_METHOD == ADDRESS_MARK_METHOD
		SET_BIT(MUSART1->CR1,MUSART1_CR1_WAKE);	
	#else
		#error "Configuration error : USART1 wakeup method error"
	#endif
	
	/* Set The parity bit enablement */
	#if MUSART1_PARITY_ENABLEMENT == ENABLED
		SET_BIT(MUSART1->CR1,MUSART_CR1_PCE);
	#elif MUSART1_PARITY_ENABLEMENT == DISABLED
		CLEAR_BIT(MUSART1->CR1,MUSART_CR1_PCE);
	#else
		#error "Configuration error : USART1 Parity Enabled error "
	#endif
	
	/* set parity selection */
	#if MUSART1_PARITY_SELECTION == EVEN_PARITY_MODE
		CLEAR_BIT(MUSART1->CR1,MUSART_CR1_PS)
	#elif MUSART1_PARITY_SELECTION == ODD_PARITY_MODE
		SET_BIT(MUSART1->CR1,MUSART_CR1_PS)
	#else
		#error "Configuration error : USART1 parity selection error"
	#endif
	
	/* Set Parity error interrupt enablement*/
	#if MUSART1_PARRITY_INTERRUPT_SELECTION == ENABLED
		SET_BIT(MUSART1->CR1,MUSART_CR1_PEIE);
	#elif MUSART1_PARRITY_INTERRUPT_SELECTION == DISABLED
		CLEAR_BIT(MUSART1->CR1,MUSART_CR1_PEIE);
	#else
		#error "Configuration error : USART1 parity interrupt enablement"
	#endif
	
	/* Set transmission register empty interrupt enablement*/
	#if MUSART1_TXE_INTERRUPT_SELECTION == ENABLED
		SET_BIT(MUSART1->CR1,MUSART_CR1_TXEIE);
	#elif MUSART1_TXE_INTERRUPT_SELECTION == DISABLED
		CLEAR_BIT(MUSART1->CR1,MUSART_CR1_TXEIE);
	#else
		#error "Configuration error : USART1 transmission register interrupt enablement"
	#endif
	
	/* Set transmission complete interrupt enablement */
	#if MUSART1_TRANSMISSION_COMPLETED_INTERRUPT_SELECTION == ENABLED
		SET_BIT(MUSART1->CR1,MUSART_CR1_TCIE);
	#elif MUSART1_TRANSMISSION_COMPLETED_INTERRUPT_SELECTION == DISABLED
		CLEAR_BIT(MUSART1->CR1,MUSART_CR1_TCIE);
	#else
		#error "Configuration error : USART1 transmission complete interrupt enablement error"
	#endif
	
	/* Set receiver not completed interrupt enablement */
	#if MUSART1_RXNE_INTERRUPT_SELECTION == ENABLED
		SET_BIT(MUSART1->CR1,MUSART_CR1_RXNEIE);
	#elif MUSART1_RXNE_INTERRUPT_SELECTION == DISABLED
		CLEAR_BIT(MUSART1->CR1,MUSART_CR1_RXNEIE);
	#else
		#error "Configuration error : USART1 receive not completed interrupt enablement error"
	#endif
	
	/* Set IDLE interrupr enable */
	#if MUSART1_IDLE_INTERRUPT_SELECTION == ENABLE
		SET_BIT(MUSART1->CR1,MUSART_CR1_IDLEIE);
	#elif MUSART1_IDLE_INTERRUPT_SELECTION == DISABLED
		CLEAR_BIT(MUSART1->CR1,MUSART_CR1_IDLEIE);
	#else
		#error "Configuration error : USART1 IDLE interrupt selection error"
	#endif
	
	/* Set Receiver Wakup mode */
	#if MUSART1_RECEIVER_WAKEUP_MODE_SELECTION == ACTIVE_MODE
		CLEAR_BIT(MUSART1->CR1,MUSART_CR1_RWU);
	#elif MUSART1_RECEIVER_WAKEUP_MODE_SELECTION == MUTE_MODE
		SET_BIT(MUSART1->CR1,MUSART_CR1_RWU);
	#else
		#error "Configuration error : USART1 Receiver wakeup mode error"
	#endif
	
	/* Set send break mode */
	#if MUSART1_SEND_BREAK_ENABLEMENT == ENABLED
		SET_BIT(MUSART1->CR1,MUSART_CR1_SBK);
	#elif MUSART1_SEND_BREAK_ENABLEMENT == DISABLED
		CLEAR_BIT(MUSART1->CR1,MUSART_CR1_SBK);
	#else
		#error "Configuration error : USART1 send break enablement error"
	#endif
	
	/* Set stop bit */
	#if MUSART1_STOP_BIT_SELECTION == HALF_STOP_BIT
		SET_BIT(MUSART1->CCR2,MYSART_CR2_STOP0);
		CLEAR_BIT(MUSART1->CCR2,MYSART_CR2_STOP1);
	#elif MUSART1_STOP_BIT_SELECTION == ONE_STOP_BIT
		CLEAR_BIT(MUSART1->CCR2,MYSART_CR2_STOP0);
		CLEAR_BIT(MUSART1->CCR2,MYSART_CR2_STOP1);
	#elif MUSART1_STOP_BIT_SELECTION == TWO_STOP_BIT
		CLEAR_BIT(MUSART1->CCR2,MYSART_CR2_STOP0);
		SET_BIT(MUSART1->CCR2,MYSART_CR2_STOP1);
	#elif MUSART1_STOP_BIT_SELECTION == ONE_HALF_STOP_BIT
		SET_BIT(MUSART1->CCR2,MYSART_CR2_STOP0);
		SET_BIT(MUSART1->CCR2,MYSART_CR2_STOP1);
	#else
		#error "Configuration error : USART1 stop bit selection error"
	#endif
	
	/* Set Usart1 Mode by Enable or disable clock*/
	#if MUSART1_MODE_SELECTION == ASYNCHRONOUS_MODE
			/* Disable Clock*/
		CLEAR_BIT(MUSART1->CR2,MUSART_CR2_CLKEN);
	#elif MUSART1_MODE_SELECTION == SYNCHRONOUS_MODE
			/* Enable clock */
		SET_BIT(MUSART1->CR2,MUSART_CR2_CLKEN);
	#else 
		#error "Configuration error : USART1 mode selection error"
	#endif
	
	/* Set Clock polarity */
	#if MUSART1_CLOCK_POLARITY_SELECTION == STEADY_LOW_MODE
		CLEAR_BIT(MUSART1->CR2,MUSART_CR2_CPOL);
	#elif MUSART1_CLOCK_POLARITY_SELECTION == STEADY_HIGH_MODE
		SET_BIT(MUSART1->CR2,MUSART_CR2_CPOL);
	#else
		#error "Configuration error : Clock polarity selection error"
	#endif
	
	/* Set Tha baud rate assign clock source 16 MHZ & OVER8 = 1*/
	#if MUSART1_BAUD_RATE_SELECTION == BAUD_RATE_1.2KBPS
		MUSART1->BPR = 
	#elif ProcessorClock == CLOCK_SPEED_16MHZ
		#if
	
		/* Set baudrate */
    u32 Local_u32Mantissa = UART_CLK/(BAUDRATE*16);
	u32 Local_u32Fraction = (UART_CLK%(BAUDRATE*16))*; 
    u32 Local_u32DIV      = (((UART_CLK*100/(16*BAUDRATE))%100)*16)/100;
    UART1->BRR |= (Local_u32DIV<<BRR_FRC);
    UART1->BRR |= (Local_u32Mantissa<<BRR_MNTS);
	/* Set The baud rate */
	#if MUSART1_BAUD_RATE_SELECTION == 
	
	#if MUSART1
	#elif MUSART1
	#else
		#error "Configuration error : "
	#endif
	
	/* Enable USART1 */
	SET_BIT(MUSART1->CR1,MUSART_CR1_UE);
	
}
void MUSART_voidTransmitDataSynchronous(u16 Copy_u8Data)
{
	/* Polling (busy wait) On the Transmit data empty flag */
	while(GET_BIT(MUSART1->SR,MUSART_SR_TXE) == 0);
	
	/* Copy Tha data to DR register */
	MUSART->DR &=~ 0b111111111;
	MUSART->DR |= Copy_u8Data;
	
	/* Polling (busy wait) On the TC flag*/
	while(GET_BIT(MUSART1->SR,MUSART_CR1_TC) == 0);
	
	/* Clear the TC flag */
	SET_BIT(MUSART1->SR,MUSART_CR1_TC);
}
void MUSART_u8ReceiveDataSynchronous(u8 *Copy_u8ReceivedData)
{
	/* Polling (busy wait) On the RXNE flag*/
	while(GET_BIT(MUSART1->SR,MUSART_SR_RXNE) == 0);
		/* Get the received data and assign it to tha passed variable*/
	*Copy_u8ReceivedData = MUSRT1->DR;
}
