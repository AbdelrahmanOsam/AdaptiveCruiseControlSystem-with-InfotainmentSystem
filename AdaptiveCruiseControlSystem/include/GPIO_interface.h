/*******************************************************************
* AUTHOR  : Abdelrahman Osam Khaled
* DATE	  : 2 May , 2023
* SWC 	  : GPIO
* MC 	  : STM32F401X
* LAYER   : MCAL
* VERSION : V1.0
********************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

	/* Initialize GPIO */
void MGPIO_voidInit(void);
	/* Set Pin Mode */
void MGPIO_voidSetPinMode(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinMode);
	/* Set output mode for the output pins */
void MGPIO_voidSetOutputPinMode(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8OutputPinMode);
	/* Set speed for the output pins */
void MGPIO_voidSetOutputPinSpeed(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8OutputPinSpeed);
	/* Set pull mode for input pins */
void MGPIO_voidSetPinPullMode(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinPullMode);
	/* Set pin value for output pins */
void MGPIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue);
	/* Get the value of pin */
u8 MGPIO_voidGetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID);
	/* set the value of pin */
void MGPIO_voidAtomicSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue);
	/* Set the alternative mode for the AF pin */
void MGPIO_voidSetAlternativeMode(u8 Copy_u8PortID, u8 Copy_u8PinID, u8 Copy_u8AlternativeMode);

/*** Macros for PORT ***/
#define GPIO_PORTA						0
#define GPIO_PORTB						1
#define GPIO_PORTC						2

/*** Macros for PIN ***/
#define GPIO_PIN0						0
#define GPIO_PIN1						1
#define GPIO_PIN2						2
#define GPIO_PIN3						3
#define GPIO_PIN4						4
#define GPIO_PIN5						5
#define GPIO_PIN6						6
#define GPIO_PIN7						7
#define GPIO_PIN8						8
#define GPIO_PIN9						9
#define GPIO_PIN10						10
#define GPIO_PIN11						11
#define GPIO_PIN12						12
#define GPIO_PIN13						13
#define GPIO_PIN14						14
#define GPIO_PIN15  					15

/*** Macros for Atomic PIN ***/
#define GPIO_ATOMIC_PIN0				0
#define GPIO_ATOMIC_PIN1				1
#define GPIO_ATOMIC_PIN2				2
#define GPIO_ATOMIC_PIN3				3
#define GPIO_ATOMIC_PIN4				4
#define GPIO_ATOMIC_PIN5				5
#define GPIO_ATOMIC_PIN6				6
#define GPIO_ATOMIC_PIN7				7
#define GPIO_ATOMIC_PIN8				8
#define GPIO_ATOMIC_PIN9				9
#define GPIO_ATOMIC_PIN10				10
#define GPIO_ATOMIC_PIN11				11
#define GPIO_ATOMIC_PIN12				12
#define GPIO_ATOMIC_PIN13				13
#define GPIO_ATOMIC_PIN14				14
#define GPIO_ATOMIC_PIN15  				15

/*** Macros for Pin mode ***/
#define GPIO_MODE_INPUT					0b00
#define GPIO_MODE_OUTPUT				0b01
#define GPIO_MODE_AF					0b10
#define GPIO_MODE_ANALOG				0b11

/*** Macros for output modes ***/
#define GPIO_OUTPUT_PUSH_PULL			0
#define GPIO_OUTPUT_OPEN_DRAIN			1

/*** Macros for Output pin speed ***/
#define GPIO_LOW_SPEED					0b00
#define GPIO_MEDIUM_SPEED				0b01
#define GPIO_HIGH_SPEED					0b10
#define GPIO_VERY_HIGH_SPEED			0b11

/*** Macros for Pull mode ***/
#define GPIO_NO_PULL					0b00
#define GPIO_PULL_UP					0b01
#define GPIO_PULL_DOWN					0b10

/*** Macros for pin value ***/
#define GPIO_LOW						0
#define GPIO_HIGH						1

/*** Macros for Alternative modes ***/
#define MGPIO_AF_SPI	0b0101

#endif
