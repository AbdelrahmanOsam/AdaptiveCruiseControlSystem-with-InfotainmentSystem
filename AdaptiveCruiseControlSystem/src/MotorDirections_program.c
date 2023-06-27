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
#include "MotorDirections_config.h"
#include "MotorDirections_interface.h"
#include "MotorDirections_private.h"

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
	MGPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN10,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN11,GPIO_MODE_OUTPUT);
//	MGPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN3,GPIO_MODE_OUTPUT);
//	MGPIO_voidSetPinMode(GPIO_PORTB,GPIO_PIN4,GPIO_MODE_OUTPUT);

	MGPIO_voidSetOutputPinMode(GPIO_PORTB,GPIO_PIN10,GPIO_OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(GPIO_PORTB,GPIO_PIN11,GPIO_OUTPUT_PUSH_PULL);
//	MGPIO_voidSetOutputPinMode(GPIO_PORTB,GPIO_PIN3,GPIO_OUTPUT_PUSH_PULL);
//	MGPIO_voidSetOutputPinMode(GPIO_PORTB,GPIO_PIN4,GPIO_OUTPUT_PUSH_PULL);

	MGPIO_voidSetOutputPinSpeed(GPIO_PORTB,GPIO_PIN10,GPIO_HIGH_SPEED);
	MGPIO_voidSetOutputPinSpeed(GPIO_PORTB,GPIO_PIN11,GPIO_HIGH_SPEED);
//	MGPIO_voidSetOutputPinSpeed(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH_SPEED);
//	MGPIO_voidSetOutputPinSpeed(GPIO_PORTB,GPIO_PIN4,GPIO_HIGH_SPEED);

    /***********************  Made The Car Go Forword In Mediuem Speed **********************************************************/

}

void Moter_VoidCarForword(void)
{
    /********************* Control Moter Using H_Bridge ***********************************/
  /*********************** Make The OUTPUT HIGH TO Move The Car In Forward Direction ****************************************************************/

	MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN10,GPIO_HIGH);    // Left forward
    MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN11,GPIO_HIGH);     // Right forward
//    MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);    // right backward
//    MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN4,GPIO_LOW);     // left backward
}
void Moter_VoidCarBackword(void)
{
   /******************************  Made The Car Go The Reverse Direaction  *********************************************/

//	MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN10,GPIO_LOW);  // Left forward
//    MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN11,GPIO_LOW);   // Right forward
    MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN10,GPIO_HIGH);  // right backward
    MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN11,GPIO_HIGH);   // left backward

}
void Moter_VoidCarStop(void)
{
    /******************************* TO Stop The Car *************************************/
   MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);      // Left forward
   MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);       // Right forward
   MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);     // right backward
   MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN4,GPIO_LOW);      // left backward
}
//void Moter_VoidCarRight(void)
//{
//    /******************************* TO MADE The Car GO Right *************************************/
//
//   MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_HIGH);       // Left forward
//   MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_LOW);         // Right forward
//   MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_LOW);       // right backward
//   MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN4,GPIO_HIGH);       // left backward
//
//}
//void Moter_VoidCarLeft(void)
//{
//    /******************************* TO MADE The Car GO Lift  *************************************/
//   MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN1,GPIO_LOW);        // Left forward
//   MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN2,GPIO_HIGH);        // Right forward
//   MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN3,GPIO_HIGH);       // right backward
//   MGPIO_voidSetPinValue(GPIO_PORTB,GPIO_PIN4,GPIO_LOW);       // left backward
//}

