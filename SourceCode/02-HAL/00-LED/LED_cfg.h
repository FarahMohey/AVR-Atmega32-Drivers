/*
 ============================================================================
 Name        : LED_cfg.H
 Author      : Farah Mohey
 Description : Header file for Configuring LED Driver
 Created	 : 24-Dec-23	
 ============================================================================
 */

#ifndef LED_CFG_H_
#define LED_CFG_H_
#include "D:\AVR_Tasks\Lab1\SourceCode\01-MCAL\00-DIO\DIO.h"



/* Defined LEDS */
#define LED0 0
#define LED1 1
#define LED2 2


/*Total Number of Defined LEDS */
#define NUM_OF_LEDS 3


/*Enum to represent Active State Type (Configuration of the LED) */
typedef enum
{
	LED_enumActiveLow,
	LED_enumActiveHigh
	
}LED_enumActiveState_t;



/* Enum to represent OutputStatus: ON  or OFF */
typedef enum
{
	LED_enumOFF,	/*ActiveLow_OFF = 1		, ActiveHigh_OFF= 0*/
	LED_enumON		/* ActiveLow_ON = 0		, ActiveHigh_ON = 1*/
}LED_enumOutputStatus_t;

/*Struct To Represent Each LED*/
typedef struct
{
	DIO_enumPorts_t Port;	/*Ports A , B, C, D*/
	DIO_enumPins_t Pin ;	/*Pins 0,1,2,3,4,5,6,7*/
	LED_enumActiveState_t ActiveState ;		/*Active LOW OR HIGH*/
	LED_enumOutputStatus_t OutputStatus ;	/*Output ON OR OFF*/
}LED_strCfg;






#endif /* LED_CFG_H_ */

