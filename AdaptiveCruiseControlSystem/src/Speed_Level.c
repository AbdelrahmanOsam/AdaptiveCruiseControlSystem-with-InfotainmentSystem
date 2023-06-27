#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include 	"timer_interface.h"
#include	"SpeedLevel.h"
#include 	"Delay.h"

extern volatile u16 Speed_Level;


void SpeedLevel_voidInit(void)
{
	u16 ACC_u8ONValue;

	/* Check if the speed selected is within the range */
	if(Speed_Level > 1000)
	{
		Speed_Level = 1000;
	}
	else if(Speed_Level < 100)
	{
		Speed_Level = 100;
	}
	else
	{
		// The speed level is within the range
	}

	if(Speed_Level < 150)
	{
		ACC_u8ONValue = 100;
	}
	else
	{
		ACC_u8ONValue = Speed_Level;
	}
	MGTimer2_void_CompValue(ACC_u8ONValue);
	MGTimer2_voidStartTimer();
	_delay_ms(10);
}
