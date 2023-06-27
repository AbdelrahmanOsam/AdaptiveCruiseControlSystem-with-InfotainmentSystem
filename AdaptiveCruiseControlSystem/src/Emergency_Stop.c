#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include 	"led_matrix_int.h"
#include	"Emergency_stop.h"
#include 	"Delay.h"

extern volatile u16 Ultrasonic_Distance;
extern volatile u16 Speed_Level;
/* In this function implement auto braking if the range of car is equal to colliison distance*/
void Emergency_StopvoidInit(void)
{
	HLEDMAT_voidInit();
	u8 arraystop[8] = {0, 0,60,66,126,66,60,0};
	u8 arraystoppp[8] = {0};
	if(Ultrasonic_Distance <= COLLISION_DISTANCE)
	{
		Speed_Level = 100;		/*Stop the car */
		HLEDMAT_voidDisplay(&arraystoppp);
		_delay_ms(10);
		HLEDMAT_voidDisplay(&arraystop);
		//mode = OFFCC;
	}
	else
	{
		/* Do Nothing*/
	}
}
