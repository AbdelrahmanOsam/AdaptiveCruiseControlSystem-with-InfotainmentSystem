/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 1 May , 2023
* SWC 	  : RCC
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define RCC_BASE_ADDRESS	0x40023800

#define RCC_CR				*((volatile u32 *)(RCC_BASE_ADDRESS+0x00))
#define RCC_PLLCFGR     	*((volatile u32 *)(RCC_BASE_ADDRESS+0x04))
#define RCC_CFGR        	*((volatile u32 *)(RCC_BASE_ADDRESS+0x08))
#define RCC_CIR         	*((volatile u32 *)(RCC_BASE_ADDRESS+0x0C))
#define RCC_AHB1RSTR    	*((volatile u32 *)(RCC_BASE_ADDRESS+0x10))
#define RCC_AHB2RSTR    	*((volatile u32 *)(RCC_BASE_ADDRESS+0x14))
#define RCC_APB1RSTR    	*((volatile u32 *)(RCC_BASE_ADDRESS+0x20))
#define RCC_APB2RSTR    	*((volatile u32 *)(RCC_BASE_ADDRESS+0x24))
#define RCC_AHB1ENR     	*((volatile u32 *)(RCC_BASE_ADDRESS+0x30))
#define RCC_AHB2ENR     	*((volatile u32 *)(RCC_BASE_ADDRESS+0x34))
#define RCC_APB1ENR     	*((volatile u32 *)(RCC_BASE_ADDRESS+0x40))
#define RCC_APB2ENR     	*((volatile u32 *)(RCC_BASE_ADDRESS+0x44))
#define RCC_AHB1LPENR   	*((volatile u32 *)(RCC_BASE_ADDRESS+0x50))
#define RCC_AHB2LPENR   	*((volatile u32 *)(RCC_BASE_ADDRESS+0x54))
#define RCC_APB1LPENR   	*((volatile u32 *)(RCC_BASE_ADDRESS+0x60))
#define RCC_APB2LPENR   	*((volatile u32 *)(RCC_BASE_ADDRESS+0x64))
#define RCC_BDCR        	*((volatile u32 *)(RCC_BASE_ADDRESS+0x70))
#define RCC_CSR         	*((volatile u32 *)(RCC_BASE_ADDRESS+0x74))
#define RCC_SSCGR       	*((volatile u32 *)(RCC_BASE_ADDRESS+0x80))
#define RCC_PLLI2SCFGR  	*((volatile u32 *)(RCC_BASE_ADDRESS+0x84))
#define RCC_DCKCFGR			*((volatile u32 *)(RCC_BASE_ADDRESS+0x8C))

/********** Macros For RCC_CR *******/
#define RCC_CR_HSION			0
#define RCC_CR_HSITRM0			3
#define RCC_CR_HSITRM1			4
#define RCC_CR_HSITRM2			5
#define RCC_CR_HSITRM3			6
#define RCC_CR_HSITRM4			7
#define RCC_CR_HSEON			16
#define RCC_CR_HSEBYP			18
#define RCC_CR_CSSON			19
#define RCC_CR_PLLON			24
#define RCC_CR_PLLI2S			26

/*********** Macros for RCC_PLLCFGR *********/
#define RCC_PLLCFGR_PLLM0		0
#define RCC_PLLCFGR_PLLM1		1
#define RCC_PLLCFGR_PLLM2		2
#define RCC_PLLCFGR_PLLM3		3
#define RCC_PLLCFGR_PLLM4		4
#define RCC_PLLCFGR_PLLM5		5
#define RCC_PLLCFGR_PLLN0		6
#define RCC_PLLCFGR_PLLN1		7
#define RCC_PLLCFGR_PLLN2		8
#define RCC_PLLCFGR_PLLN3		9
#define RCC_PLLCFGR_PLLN4		10
#define RCC_PLLCFGR_PLLN5		11
#define RCC_PLLCFGR_PLLN6		12
#define RCC_PLLCFGR_PLLN7		13
#define RCC_PLLCFGR_PLLN8		14
#define RCC_PLLCFGR_PLLP0		16
#define RCC_PLLCFGR_PLLP1		17	
#define RCC_PLLCFGR_PLLSRC		22
#define RCC_PLLCFGR_PLLQ0		24
#define RCC_PLLCFGR_PLLQ1		25
#define RCC_PLLCFGR_PLLQ2		26
#define RCC_PLLCFGR_PLLQ3		27

/*********** Macros for RCC_CFGR *********/
#define RCC_CFGR_SW0			0
#define RCC_CFGR_SW1			1
#define RCC_CFGR_SWS0			2
#define RCC_CFGR_SWS1			3
#define RCC_CFGR_HPRE0			4
#define RCC_CFGR_HPRE1			5
#define RCC_CFGR_HPRE2			6
#define RCC_CFGR_HPRE3			7
#define RCC_CFGR_PPRE10			10
#define RCC_CFGR_PPRE11			11
#define RCC_CFGR_PPRE12			12
#define RCC_CFGR_PPRE20			13
#define RCC_CFGR_PPRE21			14
#define RCC_CFGR_PPRE22			15
#define RCC_CFGR_RTCPRE0		16
#define RCC_CFGR_RTCPRE1		17
#define RCC_CFGR_RTCPRE2		18
#define RCC_CFGR_RTCPRE3		19
#define RCC_CFGR_RTCPRE4		20
#define RCC_CFGR_MCO10			21
#define RCC_CFGR_MCO11			22
#define RCC_CFGR_I2SSCR			23
#define RCC_CFGR_MCO1PRE0		24
#define RCC_CFGR_MCO1PRE1		25
#define RCC_CFGR_MCO1PRE2		26
#define RCC_CFGR_MCO2PRE0		27
#define RCC_CFGR_MCO2PRE1		28
#define RCC_CFGR_MCO2PRE2		29
#define RCC_CFGR_MCO20			30
#define RCC_CFGR_MCO21			31


/****** Macros for SYSTEM_CLOCK_SELECTION *****/
#define RCC_HSI					0
#define RCC_HSE					1
#define RCC_PLL					2

/*** Macros for Prescaler selection ***/
#define NO_PRESCALER				0
#define PRESCALER_DIVIDED_BY_2		1
#define PRESCALER_DIVIDED_BY_3		2
#define PRESCALER_DIVIDED_BY_4		3
#define PRESCALER_DIVIDED_BY_5 		4
#define PRESCALER_DIVIDED_BY_8		5
#define PRESCALER_DIVIDED_BY_16		6
#define PRESCALER_DIVIDED_BY_64		7
#define PRESCALER_DIVIDED_BY_128	8
#define PRESCALER_DIVIDED_BY_256	9
#define PRESCALER_DIVIDED_BY_512	10

/********Another way to write the addresses of Register **********/
/* e7na 3mlna struct feha el registers bta3 RCC peripheral bl tarteb w m3aha el reserved slots
	w 3mlna pointer to struct y4awr ela awl element fe el struct w lma ngm3  3la el pointer hayro7 ll register */
/*
typedef struct
{
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;     
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
	volatile u32 RESEVED1[2];
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR;
	volatile u32 RESEVED2[2];
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR; 
	volatile u32 RESEVED3[2];
	volatile u32 APB1ENR; 
	volatile u32 APB2ENR;
	volatile u32 RESEVED4[2];
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	volatile u32 RESEVED5[2];
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
	volatile u32 RESEVED6[2];
	volatile u32 BDCR;    
	volatile u32 CSR;   
	volatile u32 RESEVED7[2];
	volatile u32 SSCGR;   
	volatile u32 PLLI2CFGR;
	volatile u32 RESEVED8;
	volatile u32 DCKCFGR;	
}RCC_t

#define RCC	(volatile RCC_t*)RCC_BASE_ADDRESS
*/
#endif
