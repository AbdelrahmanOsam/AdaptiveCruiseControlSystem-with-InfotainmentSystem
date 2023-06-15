/*******************************************************
* Author  : Abdelrahman Osam Khaled
* Date	  : 6 June , 2023
* SWC	  : USART
* Layer	  : MCAL
* MC 	  : STM32F401CC
* Version : V1.0
*******************************************************/

#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

void MUSART_voidInit(void);
void MUSART_voidTransmitDataSynchronous(u8 Copy_u8Data);
void MUSART_u8ReceiveDataSynchronous(u8 *Copy_u8ReceivedData);

#endif