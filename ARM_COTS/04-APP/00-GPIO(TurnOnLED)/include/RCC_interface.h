/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 1 May , 2023
* SWC 	  : RCC
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

void MRCC_voidInit(void);
void MRCC_voidEnablePeripheralClock(u8 Copy_u8PeripheralBus,u8 Copy_u8PeripheralID);
void MRCC_voidDisablePeripheralClock(u8 Copy_u8PeripheralBus,u8 Copy_u8PeripheralID);


#define RCC_AHB1		0
#define RCC_AHB2		1
#define RCC_APB1		2
#define RCC_APB2		3

/*** Macros of peripherals of RCC_AHB1 ***/
#define RCC_GPIOA		0
#define RCC_GPIOB		1
#define RCC_GPIOC		2
#define RCC_GPIOD		3
#define RCC_GPIOE		4
#define RCC_GPIOH		7
#define RCC_CRC			12
#define RCC_DMA1		21
#define RCC_DMA2		22

/*** Macros of peripherals of RCC_AHB2 ***/
#define RCC_OTGFS		7

/*** Macros of peripherals of RCC_APB1 ***/
#define RCC_TIMER2		0
#define RCC_TIMER3		1
#define RCC_TIMER4		2
#define RCC_TIMER5		3
#define RCC_WWDG		11	
#define RCC_SPI2		14
#define RCC_SPI3		15
#define RCC_USART2		17
#define RCC_I2C1		21
#define RCC_I2C2		22
#define RCC_I2C3		23
#define RCC_PWR			28

/*** Macros of peripherals of RCC_APB2 ***/
#define RCC_TIMER1		0
#define RCC_USART1		4
#define RCC_USART6		5
#define RCC_ADC1		8
#define RCC_SDIO		11
#define RCC_SPI1		12
#define RCC_SPI4		13
#define RCC_SYSCFG		14
#define RCC_TIMER9		16
#define RCC_TIMER10		17
#define RCC_TIMER11		18

#endif
