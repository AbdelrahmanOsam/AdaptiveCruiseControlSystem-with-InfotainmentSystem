/*******************************************************************
* Author  : Abdelrahman Osam Khaled
* Date    : 7 May , 2023
* SWC     : LED Matrix
* MC 	  : STM32F401X
* Layer   : HAL
* Version : 2.0
*******************************************************************/

#ifndef LEDMATRIX_INTERFACE_H
#define LEDMATRIX_INTERFACE_H

typedef struct 
{
	u8 LED_MATRIX_RowPort;
	u8 LED_MATRIX_ColPort;
	
	u8 LED_MATRIX_Row0;
	u8 LED_MATRIX_Row1;
	u8 LED_MATRIX_Row2;
	u8 LED_MATRIX_Row3;
	u8 LED_MATRIX_Row4;
	u8 LED_MATRIX_Row5;
	u8 LED_MATRIX_Row6;
	u8 LED_MATRIX_Row7;

	u8 LED_MATRIX_Col0;
	u8 LED_MATRIX_Col1;
	u8 LED_MATRIX_Col2;
	u8 LED_MATRIX_Col3;
	u8 LED_MATRIX_Col4;
	u8 LED_MATRIX_Col5;
	u8 LED_MATRIX_Col6;
	u8 LED_MATRIX_Col7;
}LED_MATRIX

void HLEDMATRIX_voidInit(LED_MATRIX *LED_MatrixObj);
void HLEDMATRIX_voidDisplay(LED_MATRIX *LED_MatrixObj,u32 *Copy_pu32Data);

#endif