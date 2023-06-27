/*
 * Ultrasonic.h
 *
 *  Created on: 10 Feb 2023
 *      Author: user
 */


/***************************************************************************************/
/*                            Standard Types LIB                                       */
/***************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"


/***************************************************************************************/
/*                            Guard of file will call on time in c file                */
/***************************************************************************************/


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

void Ultrsonic_Trigger(void);
u32  Get_Distance(void);




#endif /* ULTRASONIC_H_ */
