/*
 ============================================================================
 Name        : Main for Task1
 Author      : Farah Mohey
 Description : Test Switch configurations for SWITCH Driver
  Created	 : 27-Dec-23	
 ============================================================================
 */

#include "D:\AVR_Tasks\Lab1\SourceCode\02-HAL\01-SWITCH\SWITCH.h"
#include "D:\AVR_Tasks\Lab1\SourceCode\02-HAL\00-LED\LED.h"


void SWITCH_Task1(void);

void SWITCH_Task1(void)
{
	u8 switch0 = 0;
	u8 switch1 = 0;
	SWITCH_enumInit();
	
    while(1)
    {
		/*SWITCH0 --> Input PULLDOWN */
		
		/*Read Switch value of switch 0*/
		SWITCH_enumReadValue(SWITCH0,&switch0);
		if (switch0)
		{
			/*for debouncing handle*/
			DIO_DelayMs (30);
			SWITCH_enumReadValue(SWITCH0 , &switch0);
			/*Check if switch pressed or not */
	    if (switch0)
		{
			LED_enumSetLedState(LED2, LED_enumON);
	    }
		}
		
		
		/*SWITCH1 --> Input PULLUP */
			
		/*Read Switch value of switch 1*/
		SWITCH_enumReadValue(SWITCH1,&switch1);
		if (!switch1)
		{
		/*for debouncing handle*/
		DIO_DelayMs (30);
		SWITCH_enumReadValue(SWITCH1 , &switch1);
		/*Check if switch pressed or not */
		if (!switch1)
		{
			LED_enumSetLedState(LED1, LED_enumON);
		}
		}
	}
}