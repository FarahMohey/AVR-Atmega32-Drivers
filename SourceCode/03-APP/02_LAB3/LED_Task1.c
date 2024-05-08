/*
 ============================================================================
 Name        : Main for Task1
 Author      : Farah Mohey
 Description : Toggle led for LED Driver
  Created	 : 27-Dec-23	
 ============================================================================
 */

#include "D:\AVR_Tasks\Lab1\SourceCode\02-HAL\00-LED\LED.h"
void LED_Task1(void);

void LED_Task1(void)
{
	LED_enumInit();

    while(1)
    {
		/*Toggle LED0 --> Activated As ActiveLow */
		LED_enumSetLedState( LED0 , LED_enumON);
		DIO_DelayMs(500);
		LED_enumSetLedState( LED0 , LED_enumOFF);
		DIO_DelayMs(500);
		
		/*Toggle LED1 --> Activated As ActiveHigh */
		LED_enumSetLedState( LED1 , LED_enumON);
		DIO_DelayMs(500);
		LED_enumSetLedState( LED1 , LED_enumOFF);
		DIO_DelayMs(500);
		
    }
	//return 0;
}