/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 4 June , 2023
* SWC 	  : SPI
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI1_voidInit(void);
u8 MSPI_u8TrancieveSynchronous(u8 Copy_u8Data, u8 * Copy_pu8ReceivedData);

#endif