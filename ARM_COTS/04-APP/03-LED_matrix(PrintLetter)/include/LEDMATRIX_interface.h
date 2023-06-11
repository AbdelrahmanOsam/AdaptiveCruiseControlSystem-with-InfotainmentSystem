/*******************************************************************
* Author  : Abdelrahman Osam Khaled
* Date    : 14 May , 2023
* SWC     : LED Matrix
* MC 	  : STM32F401X
* Layer   : HAL
* Version : 2.0
*******************************************************************/

#ifndef LEDMATRIX_INTERFACE_H
#define LEDMATRIX_INTERFACE_H

void HLEDMATRIX_voidInit();
void HLEDMATRIX_voidDisplay(u8 *Copy_pu8Data);


#endif