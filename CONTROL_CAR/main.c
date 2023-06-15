/***********************************************************************************
************************************************************************************
* Author          Ahmed Saeid Abdall
* Data            15 jun,2023
* Compiler        ARM GNU GCC
*Controller       STM32F401CC
*******************************************************************************
Author                     Data          Version            Controller       
Ahmed saeid abdalla       15,jun          v1.0             STM32F401CC
*******************************************************************************/

#include "USART_interface.h"
#include "Driver_interface.h"


void main (void)
{
     Moter_VoidCarInit();
     MUSART_voidInit();
    

        if (MUSART_u8ReceiveDataSynchronous == 'F')
        {
            
             Moter_VoidCarForword();

        }

        else if (MUSART_u8ReceiveDataSynchronous == 'B')
        {
             Moter_VoidCarBackword();
        }

         else if (MUSART_u8ReceiveDataSynchronous == 'R')
        {
            Moter_VoidCarRight();
        }

         else if (MUSART_u8ReceiveDataSynchronous == 'L')
        {
             Moter_VoidCarLeft();

        }

         else if (MUSART_u8ReceiveDataSynchronous == 'S')
        {
            Moter_VoidCarStop();

        }
        
    

}