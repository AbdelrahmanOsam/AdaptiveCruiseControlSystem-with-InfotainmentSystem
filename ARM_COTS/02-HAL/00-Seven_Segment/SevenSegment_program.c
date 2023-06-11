/*******************************************************************
* Author  : Abdelrahman Osam Khaled
* Date    : 7 May , 2023
* SWC     : Seven segment numbers
* MC 	  : STM32F401X
* Layer   : HAL
* Version : 2.0
*******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SevenSegment_interface.h"
#include "SevenSegment_private.h"
#include "SevenSegment_config.h"

#include "GPIO_interface.h"

void SevenSegment_voidInit(SevenSegment *SevenSegmentobj)
{
		/* Set seven segment mode */
	MGPIO_voidSetPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin0,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin1,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin2,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin3,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin4,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin5,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin6,GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin7,GPIO_MODE_OUTPUT);
	
		/* Set the output pin mode */
	MGPIO_voidSetOutputPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin0,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin1,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin2,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin3,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin4,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin5,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin6,OUTPUT_PUSH_PULL);
	MGPIO_voidSetOutputPinMode(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin7,OUTPUT_PUSH_PULL);

		/* set seven segment speed pins */
	MGPIO_voidSetOutputPinSpeed(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin0,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin1,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin2,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin3,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin4,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin5,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin6,MEDIUM_SPEED);
	MGPIO_voidSetOutputPinSpeed(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin7,MEDIUM_SPEED);
	
}

void SevenSegment_voidDisplayNumber0(SevenSegment *SevenSegmentobj)
{
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin0,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin1,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin2,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin3,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin4,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin5,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin6,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin7,GPIO_HIGH);
}

void SevenSegment_voidDisplayNumber1(SevenSegment *SevenSegmentobj)
{
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin0,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin1,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin2,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin3,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin4,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin5,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin6,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin7,GPIO_LOW);
}

void SevenSegment_voidDisplayNumber2(SevenSegment *SevenSegmentobj)
{
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin0,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin1,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin2,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin3,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin4,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin5,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin6,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin7,GPIO_LOW);
}

void SevenSegment_voidDisplayNumber3(SevenSegment *SevenSegmentobj)
{
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin0,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin1,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin2,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin3,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin4,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin5,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin6,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin7,GPIO_LOW);
}

void SevenSegment_voidDisplayNumber4(SevenSegment *SevenSegmentobj)
{
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin0,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin1,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin2,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin3,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin4,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin5,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin6,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin7,GPIO_LOW);
}

void SevenSegment_voidDisplayNumber5(SevenSegment *SevenSegmentobj)
{
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin0,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin1,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin2,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin3,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin4,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin5,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin6,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin7,GPIO_LOW);
}

void SevenSegment_voidDisplayNumber6(SevenSegment *SevenSegmentobj)
{

	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin0,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin1,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin2,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin3,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin4,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin5,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin6,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin7,GPIO_LOW);
}

void SevenSegment_voidDisplayNumber7(SevenSegment *SevenSegmentobj)
{
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin0,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin1,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin2,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin3,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin4,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin5,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin6,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin7,GPIO_LOW);
}

void SevenSegment_voidDisplayNumber8(SevenSegment *SevenSegmentobj)
{
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin0,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin1,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin2,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin3,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin4,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin5,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin6,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin7,GPIO_LOW);
}

void SevenSegment_voidDisplayNumber9(SevenSegment *SevenSegmentobj)
{
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin0,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin1,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin2,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin3,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin4,GPIO_LOW);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin5,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin6,GPIO_HIGH);
	MGPIO_voidSetPinValue(SevenSegmentobj->SevenSegment_PORT,SevenSegmentobj->SevenSegment_Pin7,GPIO_LOW);
}
