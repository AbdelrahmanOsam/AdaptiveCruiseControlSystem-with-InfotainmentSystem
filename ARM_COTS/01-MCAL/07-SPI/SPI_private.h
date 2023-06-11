/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 4 June , 2023
* SWC 	  : SPI
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H



typedef struct
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 CRCPR;
    volatile u32 RXCRCR;
    volatile u32 TXCRCR;
    volatile u32 I2SCFGR;
    volatile u32 I2SPR;
}SPI_t;


#define     SPI1         ((volatile SPI_t *)0x40013000)


#endif
