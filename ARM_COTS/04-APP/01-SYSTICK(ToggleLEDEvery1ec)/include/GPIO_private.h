/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 2 May , 2023
* SWC 	  : GPIO
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS		0x40020000
#define GPIOB_BASE_ADDRESS		0x40020400
#define GPIOC_BASE_ADDRESS		0x40020800


#define GPIOA_MODER				*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x00))
#define GPIOA_OTYPER			*((volatile u32 *)(GPIOA_BASE_ADDRESS+0x04))
#define GPIOA_OSPEEDR          *((volatile u32 *)(GPIOA_BASE_ADDRESS+0x08))
#define GPIOA_PUPDR             *((volatile u32 *)(GPIOA_BASE_ADDRESS+0x0C))
#define GPIOA_IDR               *((volatile u32 *)(GPIOA_BASE_ADDRESS+0x10))
#define GPIOA_ODR               *((volatile u32 *)(GPIOA_BASE_ADDRESS+0x14))
#define GPIOA_BSRR              *((volatile u32 *)(GPIOA_BASE_ADDRESS+0x18))
#define GPIOA_LCKR              *((volatile u32 *)(GPIOA_BASE_ADDRESS+0x1C))
#define GPIOA_AFRL              *((volatile u32 *)(GPIOA_BASE_ADDRESS+0x20))
#define GPIOA_AFRH              *((volatile u32 *)(GPIOA_BASE_ADDRESS+0x24))

#define GPIOB_MODER				*((volatile u32 *)(GPIOB_BASE_ADDRESS+0x00))
#define GPIOB_OTYPER            *((volatile u32 *)(GPIOB_BASE_ADDRESS+0x04))
#define GPIOB_OSPEEDR          *((volatile u32 *)(GPIOB_BASE_ADDRESS+0x08))
#define GPIOB_PUPDR             *((volatile u32 *)(GPIOB_BASE_ADDRESS+0x0C))
#define GPIOB_IDR               *((volatile u32 *)(GPIOB_BASE_ADDRESS+0x10))
#define GPIOB_ODR               *((volatile u32 *)(GPIOB_BASE_ADDRESS+0x14))
#define GPIOB_BSRR              *((volatile u32 *)(GPIOB_BASE_ADDRESS+0x18))
#define GPIOB_LCKR              *((volatile u32 *)(GPIOB_BASE_ADDRESS+0x1C))
#define GPIOB_AFRL              *((volatile u32 *)(GPIOB_BASE_ADDRESS+0x20))
#define GPIOB_AFRH              *((volatile u32 *)(GPIOB_BASE_ADDRESS+0x24))

#define GPIOC_MODER				*((volatile u32 *)(GPIOC_BASE_ADDRESS+0x00))
#define GPIOC_OTYPER            *((volatile u32 *)(GPIOC_BASE_ADDRESS+0x04))
#define GPIOC_OSPEEDR          *((volatile u32 *)(GPIOC_BASE_ADDRESS+0x08))
#define GPIOC_PUPDR             *((volatile u32 *)(GPIOC_BASE_ADDRESS+0x0C))
#define GPIOC_IDR               *((volatile u32 *)(GPIOC_BASE_ADDRESS+0x10))
#define GPIOC_ODR               *((volatile u32 *)(GPIOC_BASE_ADDRESS+0x14))
#define GPIOC_BSRR              *((volatile u32 *)(GPIOC_BASE_ADDRESS+0x18))
#define GPIOC_LCKR              *((volatile u32 *)(GPIOC_BASE_ADDRESS+0x1C))
#define GPIOC_AFRL              *((volatile u32 *)(GPIOC_BASE_ADDRESS+0x20))
#define GPIOC_AFRH              *((volatile u32 *)(GPIOC_BASE_ADDRESS+0x24))


/*******macros for output mode value ********/
#define OUTPUT_PUSH_PULL_VALUE		0b0000000000000000
#define OUTPUT_OPEN_DRAIN_VALUE		0b1111111111111111

/*** macros for speed value ***/
#define LOW_SPEED_VALUE				0b00000000000000000000000000000000
#define MEDIUM_SPEED_VALUE			0b01010101010101010101010101010101
#define HIGH_SPEED_VALUE			0b10101010101010101010101010101010
#define VERY_HIGH_SPEED_VALUE		0b11111111111111111111111111111111

/*** macros for PLL mode ***/
#define NO_PULL_VALUE				0b00000000000000000000000000000000
#define PULL_UP_VALUE				0b01010101010101010101010101010101
#define PULL_DOWN_VALUE				0b10101010101010101010101010101010

#endif