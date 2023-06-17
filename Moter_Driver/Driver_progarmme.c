/***********************************************************************************
************************************************************************************
* Author          Ahmed Saeid Abdall
* Data            15 jun,2023
* Compiler        ARM GNU GCC
*******************************************************************************
Author                     Data          Version   
Ahmed saeid abdalla       15,jun          v1.0
*******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "Driver_interface.h"
#include "Driver_private.h"
#include "Driver_configer.h"


/*
                    M2 -->>    ***************    <<--M4 
                               ***************
                               ***************
                               ***************
                               ***************
                    M1 -->>    ***************    <<--M3   
                        

* Made THE IN1 Control THE M1 -->> Left Moter Revese   and IN2 CONTROL M2 -->> LIFT Moter 
* Made THE IN3 Control THE M3 -->> Righ Moter Revese   and IN4 CONTROL M4 -->> RIGHT Moter 

*PIN0 -->>>>>>>  
*PIN1 -->>>>>>> 
*PIN2 -->>>>>>> 
*PIN3 -->>>>>>> 

*/

void Moter_VoidCarInit(void)
{
    /************************  Intilization The PORTA PINS To BE OUTPUT ********************************/
    MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_MODE_OUTPUT);
    MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN1,GPIO_MODE_OUTPUT);
    MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_MODE_OUTPUT);
    MGPIO_voidSetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_MODE_OUTPUT);
    /***********************  Made The Car Go Forword In Mediuem Speed **********************************************************/

}

void Moter_VoidCarForword(void)
{
    /********************* Control Moter Using H_Bridge ***********************************/
  /*********************** Make The OUTPUT HIGH TO Move The Car In Forward Direction ****************************************************************/
    MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);    // Put IN1 High  
    MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);     // Put IN2 LOW 
    MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);    // Put IN3 High  
    MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);     // Put IN4 LOW 
}
void Moter_VoidCarBackword(void)
{
   /******************************  Made The Car Go The Reverse Direaction  *********************************************/
    MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);   // PUT IN1 LOW 
    MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);  // PUT IN2 HIGH
    MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);   // PUT IN3 LOW 
    MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);  // PUT IN4 HIGH

}
void Moter_VoidCarStop(void)
{
    /******************************* TO Stop The Car *************************************/
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);         // PUT The IN1 LOW
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);        // PUT The IN2 LOW
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);       // PUT The IN3 LOW
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);      // PUT The IN4 LOW
}
void Moter_VoidCarRight(void)
{
    /******************************* TO MADE The Car GO Right *************************************/
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_HIGH);         // PUT IN1 HIGH M1
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_LOW);         // PUT IN2 LOW  M1
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_HIGH);       // PUT IN1 HIGH M2
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_LOW);       // PUT IN2 LOW  M2

}
void Moter_VoidCarLeft(void)
{
    /******************************* TO MADE The Car GO Lift  *************************************/
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_LOW);           // PUT IN1 HIGH M1
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN1,GPIO_HIGH);         // PUT IN2 LOW  M1
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN2,GPIO_LOW);         // PUT IN1 HIGH M2
   MGPIO_voidSetPinValue(GPIO_PORTA,GPIO_PIN3,GPIO_HIGH);       // PUT IN2 LOW  M2
}

