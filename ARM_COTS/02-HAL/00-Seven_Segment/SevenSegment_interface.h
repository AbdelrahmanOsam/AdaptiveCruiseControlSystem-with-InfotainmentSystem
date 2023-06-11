/*******************************************************************
* Author  : Abdelrahman Osam Khaled
* Date    : 7 May , 2023
* SWC     : Seven segment numbers
* MC 	  : STM32F401X
* Layer   : HAL
* Version : 2.0
*******************************************************************/

#ifndef SEVEN_SEGMENT_INTERFACE_H
#define SEVEN_SEGMENT_INTERFACE_H

typedef struct
{
	u8 SevenSegment_PORT;
	u8 SevenSegment_Pin0;
	u8 SevenSegment_Pin1;
	u8 SevenSegment_Pin2;
	u8 SevenSegment_Pin3;
	u8 SevenSegment_Pin4;
	u8 SevenSegment_Pin5;
	u8 SevenSegment_Pin6;
	u8 SevenSegment_Pin7;
}SevenSegment;

void SevenSegment_voidInit(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber0(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber1(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber2(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber3(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber4(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber5(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber6(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber7(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber8(SevenSegment *SevenSegmentobj);

void SevenSegment_voidDisplayNumber9(SevenSegment *SevenSegmentobj);

#endif
