/*
 ============================================================================
 Name        : LED_cfg.c
 Author      : Farah Mohey
 Description : Source file for Configuring LED Driver
 Created	 : 24-Dec-23	
 ============================================================================
 */

#include "LED_cfg.h"

/*Initializing Array of struct for each LED*/

/**** Struct takes *****/
/*Port from Port Options Port A,B,C,D */
/*Pin from Pins Options From Pin0-->7 */
/*Active_OutputStatus Options Are:
								ActiveLow_ON 
								ActiveLow_OFF
								ActiveHigh_ON
								ActiveHigh_OFF	*/

LED_strCfg LEDS_Cfg[NUM_OF_LEDS] ={
	[LED0]={.Port= DIO_enumPortA , .Pin= DIO_enumPin0 , .ActiveState = LED_enumActiveHigh , .OutputStatus = LED_enumOFF},
	[LED1]={.Port= DIO_enumPortA , .Pin= DIO_enumPin1 , .ActiveState = LED_enumActiveHigh  , .OutputStatus = LED_enumOFF},
	[LED2]={.Port= DIO_enumPortA , .Pin= DIO_enumPin3 , .ActiveState = LED_enumActiveHigh , .OutputStatus = LED_enumOFF}
			
};

