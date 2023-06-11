/*******************************************************************
* Author  : Abdelrahman Osam Khaled
* Date    : 7 May , 2023
* SWC     : LED Matrix
* MC 	  : STM32F401X
* Layer   : HAL
* Version : 2.0
*******************************************************************/
#ifndef LEDMATRIX_PRIVATE_H
#define LEDMATRIX_PRIVATE_H

static void HLEDMATRIX_voidDisableAllCols(LED_MATRIX *LED_MatrixObj);

static void HLEDMATRIX_voidSetRowValue(LED_MATRIX *LED_MatrixObj,u8 Copy_u8RowValue);

#endif