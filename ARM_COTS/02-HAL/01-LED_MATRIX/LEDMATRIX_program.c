/*******************************************************************
* Author  : Abdelrahman Osam Khaled
* Date    : 7 May , 2023
* SWC     : LED Matrix
* MC 	  : STM32F401X
* Layer   : HAL
* Version : 2.0
*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SYSTICK_interface.h"

u8 Globale_u8StopDisplay = 0;

void HLEDMATRIX_voidInit(LED_MATRIX *LED_MatrixObj)
{
		/*** set the rows and columns pins mode ***/
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row0,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row1,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row2,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row3,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row4,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row5,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row6,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row7,GPIO_MODE_OUTPUT);

	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col0,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col1,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col2,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col3,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col4,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col5,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col6,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col7,GPIO_MODE_OUTPUT);
	
		/***set rows and columns pins output mode ***/
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row0,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row1,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row2,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row3,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row4,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row5,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row6,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row7,OUTPUT_PUSH_PULL);

	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col0,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col1,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col2,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col3,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col4,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col5,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col6,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col7,OUTPUT_PUSH_PULL);
	
	/*** set rows and columns pins speed ***/
	
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row0,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row1,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row2,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row3,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row4,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row5,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row6,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row7,MEDIUM_SPEED);

	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col0,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col1,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col2,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col3,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col4,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col5,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col6,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col7,MEDIUM_SPEED);
}

static void HLEDMATRIX_voidDisableAllCols(LED_MATRIX *LED_MatrixObj)
{
		/*** Disable all cols ***/
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col0,GPIO_HIGH);
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col1,GPIO_HIGH);
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col2,GPIO_HIGH);
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col3,GPIO_HIGH);
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col4,GPIO_HIGH);
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col5,GPIO_HIGH);
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col6,GPIO_HIGH);
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col7,GPIO_HIGH);
}

static void HLEDMATRIX_voidSetRowValue(LED_MATRIX *LED_MatrixObj,u8 Copy_u8RowValue)
{
	u8 Local_ColBit;
		/*** Split the frame into bits***/
	Local_ColBit = GET_BIT(Copy_u8ColValue,0);
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row0,Local_ColBit);

	Local_ColBit = GET_BIT(Copy_u8ColValue,1);    
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row1,Local_ColBit);

	Local_ColBit = GET_BIT(Copy_u8ColValue,2); 
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row2,Local_ColBit);

	Local_ColBit = GET_BIT(Copy_u8ColValue,3); 
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row3,Local_ColBit);

	Local_ColBit = GET_BIT(Copy_u8ColValue,4); 
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row4,Local_ColBit);

	Local_ColBit = GET_BIT(Copy_u8ColValue,5);
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row5,Local_ColBit);

	Local_ColBit = GET_BIT(Copy_u8ColValue,6); 
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row6,Local_ColBit);

	Local_ColBit = GET_BIT(Copy_u8ColValue,7); 
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_RowPort,LED_MatrixObj->LED_MATRIX_Row7,Local_ColBit);
}

void HLEDMATRIX_voidDisplay(LED_MATRIX *LED_MatrixObj,u32 *Copy_pu32Data)
{	
		/* Disable all columns */
	HLEDMATRIX_voidDisableAllCols();
		/* Enable the current column */
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col0,GPIO_LOW);
		/* set the entered value to row */
	HLEDMATRIX_voidSetRowValue(LED_MATRIX *LED_MatrixObj,Copy_pu32Data[0]);
		/* Delay for 25 msec*/
	MSTK_voidSetBusyWait(2500);
	
	HLEDMATRIX_voidDisableAllCols();
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col1,GPIO_LOW);
	HLEDMATRIX_voidSetRowValue(LED_MATRIX *LED_MatrixObj,Copy_pu32Data[1]);
	MSTK_voidSetBusyWait(2500);
	
	HLEDMATRIX_voidDisableAllCols();
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col2,GPIO_LOW);
	HLEDMATRIX_voidSetRowValue(LED_MATRIX *LED_MatrixObj,Copy_pu32Data[2]);
	MSTK_voidSetBusyWait(2500);
	
	HLEDMATRIX_voidDisableAllCols();
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col3,GPIO_LOW);
	HLEDMATRIX_voidSetRowValue(LED_MATRIX *LED_MatrixObj,Copy_pu32Data[3]);
	MSTK_voidSetBusyWait(2500);
	
	HLEDMATRIX_voidDisableAllCols();
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col4,GPIO_LOW);
	HLEDMATRIX_voidSetRowValue(LED_MATRIX *LED_MatrixObj,Copy_pu32Data[4]);
	MSTK_voidSetBusyWait(2500);
	
	HLEDMATRIX_voidDisableAllCols();
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col5,GPIO_LOW);
	HLEDMATRIX_voidSetRowValue(LED_MATRIX *LED_MatrixObj,Copy_pu32Data[5]);
	MSTK_voidSetBusyWait(2500);
	
	HLEDMATRIX_voidDisableAllCols();
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col6,GPIO_LOW);
	HLEDMATRIX_voidSetRowValue(LED_MATRIX *LED_MatrixObj,Copy_pu32Data[6]);
	MSTK_voidSetBusyWait(2500);
	
	HLEDMATRIX_voidDisableAllCols();
	MGPIO_voidSetPinValue(LED_MatrixObj->LED_MATRIX_ColPort,LED_MatrixObj->LED_MATRIX_Col7,GPIO_LOW);
	HLEDMATRIX_voidSetRowValue(LED_MATRIX *LED_MatrixObj,Copy_pu32Data[7]);
	MSTK_voidSetBusyWait(2500);
}