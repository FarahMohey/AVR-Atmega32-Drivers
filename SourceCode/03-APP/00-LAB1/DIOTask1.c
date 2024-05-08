/*
* DIOTask1.c
* 
*
* Created: 25-Nov-23 11:26:39 AM
*  Author: Farah
*/

#include "D:\AVR_Tasks\Lab1\SourceCode\01-MCAL\00-DIO\DIO.h"

 void DIOTask1(void);

void DIOTask1(void)
{
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin0 , DIO_enumOUTPUT);
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin1 , DIO_enumOUTPUT);
	
	while(1)
	{
		DIO_enumSetPin(DIO_enumPortA , DIO_enumPin0 , DIO_enumLOGIC_HIGH);
		DIO_enumSetPin(DIO_enumPortA , DIO_enumPin1 , DIO_enumLOGIC_LOW);
		
		DIO_DelayMs(250);
		
		DIO_enumSetPin(DIO_enumPortA , DIO_enumPin0 , DIO_enumLOGIC_LOW);
		DIO_enumSetPin(DIO_enumPortA , DIO_enumPin1 , DIO_enumLOGIC_HIGH);
		
		DIO_DelayMs(250);
	}
	
}