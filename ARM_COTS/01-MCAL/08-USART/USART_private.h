/*******************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 6 June , 2023
* SWC	  : USART
* Layer	  : MCAL
* MC 	  : STM32F401CC
* Version : V1.0
*******************************************************/

#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

typedef struct
{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BPR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR
}USART_t;

#define MUSART1	((volatile USART_t *)0x40011000)

/* Macros for bits of SR register */
#define MUSART_SR_PE		0
#define MUSART_SR_FE     	1
#define MUSART_SR_NF     	2
#define MUSART_SR_ORE    	3
#define MUSART_SR_IDLE   	4
#define MUSART_SR_RXNE   	5
#define MUSART_SR_TC     	6
#define MUSART_SR_TXE    	7
#define MUSART_SR_LBD    	8
#define MUSART_SR_CTS    	9

/* Macros for bits of CR1 register */
#define MUSART_CR1_SBK		0
#define MUSART_CR1_RWU		1
#define MUSART_CR1_RE		2
#define MUSART_CR1_TE		3
#define MUSART_CR1_IDLEIE	4
#define MUSART_CR1_RXNEIE	5
#define MUSART_CR1_TCIE		6
#define MUSART_CR1_TXEIE	7
#define MUSART_CR1_PEIE		8
#define MUSART_CR1_PS		9
#define MUSART_CR1_PCE		10
#define MUSART_CR1_WAKE		11
#define MUSART_CR1_M		12
#define MUSART_CR1_UE		13
#define MUSART_CR1_OVER8	15

/* Macros for bits of CR2 register */
#define MUSART_CR2_ADD0		0
#define MUSART_CR2_ADD1		1
#define MUSART_CR2_ADD2		2
#define MUSART_CR2_ADD3		3
#define MUSART_CR2_LBDL		5
#define MUSART_CR2_LBDIE	6
#define MUSART_CR2_LBCL		8
#define MUSART_CR2_CPHA		9
#define MUSART_CR2_CPOL		10
#define MUSART_CR2_CLKEN	11
#define MUSART_CR2_STOP0	12
#define MUSART_CR2_STOP1	13
#define MUSART_CR2_LINEN	14

/* Macros for bits of CR3 register */
#define MUSART_CR3_EIE		0
#define MUSART_CR3_IREN     1
#define MUSART_CR3_IRLP     2
#define MUSART_CR3_HDSEL    3
#define MUSART_CR3_NACK     4
#define MUSART_CR3_SCEN     5
#define MUSART_CR3_DMAR     6
#define MUSART_CR3_DMAT     7
#define MUSART_CR3_RTSE     8
#define MUSART_CR3_CTSE     9
#define MUSART_CR3_CTSIE    10
#define MUSART_CR3_ONEBIT   11

#endif