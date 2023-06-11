/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 4 June , 2023
* SWC 	  : SPI
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/
#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define MSPI1_MOSI_PORTPIN		MGPIO_PORTA,MGPIO_PIN7
#define MSPI1_MISO_PORTPIN		MGPIO_PORTA,MGPIO_PIN6
#define MSPI1_SCK_PORTPIN		MGPIO_PORTA,MGPIO_PIN5
#define MSPI1_NSS_PORTPIN		MGPIO_PORTA,MGPIO_PIN4

#endif