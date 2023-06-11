/*******************************************************************
* Author  : Abdelrahman Osam Khaled
* Date    : 14 May , 2023
* SWC     : LED Matrix
* MC 	  : STM32F401X
* Layer   : HAL
* Version : 2.0
*******************************************************************/

#ifndef LEDMATRIX_CONFIG_H
#define LEDMATRIX_CONFIG_H

/* Macros for row pins */
#define HLEDMATRIX_ROW_PORT		GPIOA

#define HLEDMATRIX_R0_PIN		GPIO_PIN0
#define HLEDMATRIX_R1_PIN		GPIO_PIN1
#define HLEDMATRIX_R2_PIN		GPIO_PIN2
#define HLEDMATRIX_R3_PIN		GPIO_PIN3
#define HLEDMATRIX_R4_PIN		GPIO_PIN4
#define HLEDMATRIX_R5_PIN		GPIO_PIN5
#define HLEDMATRIX_R6_PIN		GPIO_PIN6
#define HLEDMATRIX_R7_PIN		GPIO_PIN7

/* Macros for Col pins */
#define HLEDMATRIX_COLUMN_PORT		GPIOB

#define HLEDMATRIX_C0_PIN		GPIO_PIN0
#define HLEDMATRIX_C1_PIN		GPIO_PIN1
#define HLEDMATRIX_C2_PIN		GPIO_PIN2
#define HLEDMATRIX_C3_PIN		GPIO_PIN3
#define HLEDMATRIX_C4_PIN		GPIO_PIN4
#define HLEDMATRIX_C5_PIN		GPIO_PIN5
#define HLEDMATRIX_C6_PIN		GPIO_PIN6
#define HLEDMATRIX_C7_PIN		GPIO_PIN7
/****************************************/
#endif
