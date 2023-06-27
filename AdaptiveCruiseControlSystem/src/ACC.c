#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include 	"timer_interface.h"
#include 	"led_matrix_int.h"
#include	"ACC.h"
#include 	"Delay.h"

volatile u8 User_Range;
extern volatile u16 Ultrasonic_Distance;
volatile u8 User_SpeedSelcted;
volatile u16 User_SpeedSelected_PWM;
volatile u16 Speed_Level;

static u8 ACC_u8UpperLimit , ACC_u8LowerLimit ;


void ACC_voidInit(void)
{
	HLEDMAT_voidInit();
	u8 arrayplus[8]={0, 0, 16, 16, 56, 16, 16, 0};
	u8 arrayminus[8] = {8, 8, 8, 8, 8, 8, 8, 8};
	u8 arraystop[8] = {0};
	/********** Distance upper and lower limits configuration **********/
	switch(User_Range)
	{
		case FAR:
			ACC_u8UpperLimit = UPPER_FAR;
			ACC_u8LowerLimit = LOWER_FAR;
			break;
		case MEDIUM:
			ACC_u8UpperLimit = UPPER_MEDIUM;
			ACC_u8LowerLimit = LOWER_MEDIUM;
			break;
		case CLOSE:
			ACC_u8UpperLimit = UPPER_CLOSE;
			ACC_u8LowerLimit = LOWER_CLOSE;
			break;
		default:
			// nothing
			break;
	}

	User_Range = ' ';

	User_SpeedSelected_PWM = ((User_SpeedSelcted * 20) + 100) ;

	/**********  Checking if the distance is within the selected range **********/
	if(Ultrasonic_Distance > ACC_u8UpperLimit)
	{
		Speed_Level += 10 ;
		HLEDMAT_voidDisplay(&arraystop);
		_delay_ms(10);
		HLEDMAT_voidDisplay(&arrayplus);
	}
	else if((Ultrasonic_Distance < ACC_u8LowerLimit) && (Ultrasonic_Distance > COLLISION_DISTANCE) )
	{
		Speed_Level -= 10;
		HLEDMAT_voidDisplay(&arraystop);
		_delay_ms(10);
		HLEDMAT_voidDisplay(&arrayminus);
	}
	else
	{
		HLEDMAT_voidDisplay(&arraystop);

		// The car is in the selected range and the speed is maintained
	}

	/**********  Checking if the speed selected is within the range **********/

	if(User_SpeedSelected_PWM > 1000)
	{
		User_SpeedSelected_PWM = 1000;
	}
	else if(User_SpeedSelected_PWM < 100)
	{
		User_SpeedSelected_PWM = 100;
	}
	else
	{
		// The speed selected is within the range
	}

	/********** Checking if the speed level is maintained in the selected speed range **********/
	if(Speed_Level > User_SpeedSelected_PWM)
	{
		Speed_Level = User_SpeedSelected_PWM;
	}
	else
	{
		// The speed level is within the range
	}
}
