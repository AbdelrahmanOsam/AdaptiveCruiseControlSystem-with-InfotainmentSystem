/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 21 May , 2023
* SWC 	  : NVIC
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidInit(void);
void MNVIC_voidEnablePeripheralInterrupt(u8 Copy_u8PeripheralID);
void MNVIC_voidDisablePeripheralInterrupt(u8 Copy_u8PeripheralID);
void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID);
void MNVIC_voidClearPendingFlag(u8 Copy_u8PeripheralID);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8PeripheralID);
void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority);

/* Macros for peripheral Position on vector table*/
#define	MNVIC_WWDG					0
#define MNVIC_EXTI16_PVD			1
#define MNVIC_EXTI21_TAMP_STAMP		2
#define MNVIC_EXTI22_RTC_WKUP		3
#define MNVIC_FLASH					4
#define MNVIC_RCC					5
#define MNVIC_EXTI0					6
#define MNVIC_EXTI1					7
#define MNVIC_EXTI2					8
#define MNVIC_EXTI3					9
#define MNVIC_EXTI4					10
#define MNVIC_DMA1_STREAM0			11
#define MNVIC_DMA1_STREAM1			12
#define MNVIC_DMA1_STREAM2			13
#define MNVIC_DMA1_STREAM3			14
#define MNVIC_DMA1_STREAM4			15
#define MNVIC_DMA1_STREAM5			16
#define MNVIC_DMA1_STREAM6			17
#define MNVIC_ADC					18
#define MNVIC_EXTI9_5				23
#define MNVIC_TIM1_BRK_TIM9			24
#define MNVIC_TIM1_UP_TIM10			25
#define MNVIC_TIM1_TRG_COM_TIM11	26
#define MNVIC_TIM1_CC				27
#define MNVIC_TIM2					28
#define MNVIC_TIM3					29
#define MNVIC_TIM4					30
#define MNVIC_I2C1_EV				31
#define MNVIC_I2C1_ER				32
#define MNVIC_I2C2_EV				33
#define MNVIC_I2C2_ER				34
#define MNVIC_SPI1					35
#define MNVIC_SPI2					36
#define MNVIC_USART1				37
#define MNVIC_USART2				38
#define MNVIC_EXTI15_10				40
#define MNVIC_EXTI17_RTC_ALARM		41
#define MNVIC_EXTI18_OTG_FS_WKUP	42
#define MNVIC_DMA1_STREAM7			47
#define MNVIC_SDIO					49
#define MNVIC_TIM5					50
#define MNVIC_SPI3					51
#define MNVIC_DMA2_STREAM0			56
#define MNVIC_DMA2_STREAM1			57
#define MNVIC_DMA2_STREAM2			58
#define MNVIC_DMA2_STREAM3			59
#define MNVIC_DMA2_STREAM4			60
#define MNVIC_OTG_FS				67
#define MNVIC_DMA2_STREAM5			68
#define MNVIC_DMA2_STREAM6			69
#define MNVIC_DMA2_STREAM7			70
#define MNVIC_USART6				71
#define MNVIC_I2C3_EV				72
#define MNVIC_I2C3_ER				73
#define MNVIC_FPU					81
#define MNVIC_SPI4					84

#endif