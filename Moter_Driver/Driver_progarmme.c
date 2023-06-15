/***********************************************************************************
************************************************************************************
* Author          Ahmed Saeid Abdall
* Data            15 jun,2023
* Compiler        ARM GNU GCC
*******************************************************************************
Author                     Data          Version   
Ahmed saeid abdalla       15,jun          v1.0
*******************************************************************************/

#include " STD_TYPES.h"
#include " BIT_MATH.h"

#include "Driver_interface.h"
#include "Driver_private.h"
#include "Driver_configer.h"
#include "GPIO_interface.h"



/*

*PIN0 Left Moter
*PIN1 Left Moter Revese  
*PIN3 Righ Moter 
*PIN4 Righ Moter Revese


*/

void Moter_VoidCarInit(void)
{
    /************************  Intilization The PORTA PINS To BE OUTPUT ********************************/
    MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_MODE_OUTPUT);
    MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_MODE_OUTPUT);
    MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_MODE_OUTPUT);
    MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_MODE_OUTPUT);
    /***********************  Made The Car Go Forword In Mediuem Speed **********************************************************/
    MGPIO_voidSetOutputPinSpeed(GPIO_PORTA,GPIO_PIN0,GPIO_MEDIUM_SPEED);
    MGPIO_voidSetOutputPinSpeed(GPIO_PORTA,GPIO_PIN1,GPIO_MEDIUM_SPEED);
    MGPIO_voidSetOutputPinSpeed(GPIO_PORTA,GPIO_PIN2,GPIO_MEDIUM_SPEED);
    MGPIO_voidSetOutputPinSpeed(GPIO_PORTA,GPIO_PIN3,GPIO_MEDIUM_SPEED);

}

void Moter_VoidCarForword(void)
{
  /*********************** Make The OUTPUT HIGH TO Move The Car In Forward Direction ****************************************************************/
    MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);
    MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);
}
void Moter_VoidCarBackword(void)
{
   
    MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);
    MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);

}
void Moter_VoidCarStop(void)
{
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);
}
void Moter_VoidCarRight(void)
{
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);


}
void Moter_VoidCarLeft(void)
{
     MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);
}

