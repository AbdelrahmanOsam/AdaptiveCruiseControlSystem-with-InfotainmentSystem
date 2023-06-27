#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"
#include "SYSCFG_interface.h"
#include "IR_interface.h"
#include "MotorDirections_interface.h"
#include "ACC2OFF.h"


void ACCOFF_voidInit(void)
{
	switch(Global_u8ButtonData)
	{
		// OFF Button
		case 69:
		Moter_VoidCarStop();
		break;
		//Button Number (1) For Led Light
		case 12:
		Moter_VoidCarForword();
		break;
		//Button Number (2) For GREEN Light
		case 24:
		Moter_VoidCarBackword();
		break;
		//Button Number (3) For BLUE Light
		case 94:
		Moter_VoidCarRight();
		break;
		//Button Number (4) For BLUE Light
		case 8:
		Moter_VoidCarLeft();
		break;
		//Button Number (5) For BLUE Light
		case 28:
		Moter_VoidCarStop();
		break;
		//Button Number (6) For BLUE Light
		case 90:
		Moter_VoidCarStop();
		break;
		default :
		Moter_VoidCarStop();
		break;
	}
}
