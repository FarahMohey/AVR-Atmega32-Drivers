/*
 ============================================================================
 Name        : Seven_SEG_Task.c
 Author      : Farah Mohey
 Description : Seven Segment Task to Check on the 3 functions in The 7SEG Driver.
 Created	 : 04-Jan-24	
 ============================================================================
 */

#include "D:\AVR_Tasks\Lab1\SourceCode\02-HAL\02-Seven_SEG\Seven_SEG.h"


void Seven_SEG_Task(void);

void Seven_SEG_Task(void)
{
	Seven_SEG_enumInit();
    while(1)
    {
	/*		
		DIO_DelayMs(50);
		Seven_SEG_enumSetValue(Seven_SEG0 , 6);
		
		DIO_DelayMs(50);
		Seven_SEG_enumSetValue(Seven_SEG1 , 8);
	*/
		Seven_SEG_enumSetValueForAll(9);
	}
}