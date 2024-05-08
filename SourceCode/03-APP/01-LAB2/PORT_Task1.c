/*
============================================================================
Name        : main.c
Author		 : Farah Mohey
Description : Task1 for the PORT driver
Created	 : 18-Dec-23
=============================================================================
*/

void PORT_Task1(void);

#include "util/delay.h"
#include "D:\AVR_Tasks\Lab1\SourceCode\01-MCAL\01_PORT\PORT.h"
#include "D:\AVR_Tasks\Lab1\SourceCode\01-MCAL\01_PORT\PORT_cfg.h"

void PORT_Task1(void){
	
	/*(POST Compile Configuration)*/
	
	Init_PORT();
	while(1){
		/*Change Pin2 In PORTB status to HIGH*/
		for (int i=0 ; i<(NUM_OF_PINS*NUM_OF_PORTS) ; i++)
		{
			if (((i/NUM_OF_PINS)== PORT_enumPortB )&&((i%NUM_OF_PINS)== PORT_PortB_Pin2))
			{
				PORT_PINcfg[i]=PORT_enumOUTPUT_HIGH;
			}

		}
		
		Init_PORT();
		_delay_ms(500);
		
		/*Change Pin2 In PORTB status to LOW*/
		for (int i=0 ; i<(FOUR_PORTS*EIGHT_PINS); i++)
		{
			if (((i/NUM_OF_PINS)== PORT_enumPortB )&&((i%NUM_OF_PINS)== PORT_PortB_Pin2))
			{
				PORT_PINcfg[i]=PORT_enumOUTPUT_LOW;
			}

		}
		
		Init_PORT();
		_delay_ms(500);

		
		
	}
	
}