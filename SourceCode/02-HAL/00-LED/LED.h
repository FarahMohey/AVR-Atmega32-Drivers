/*
 ============================================================================
 Name        : LED.H
 Author      : Farah Mohey
 Description : Header file for LED Driver
 Created	 : 24-Dec-23	
 ============================================================================
 */



#ifndef LED_H_
#define LED_H_
#include "D:\AVR_Tasks\Lab1\SourceCode\00-LIB\STD_TYPES.h"
#include "LED_cfg.h"
#include "D:\AVR_Tasks\Lab1\SourceCode\01-MCAL\01_PORT\PORT_cfg.h"



/*Enum for the returned error state*/
typedef enum
{
	LED_enumNOK,				/*Everything Not Ok, Function had Not Performed Correctly */
	LED_enumOK,					/*Everything Ok, Function had  Performed Correctly */
	LED_enumWrongPort,			/*Selected Port Doesn't Exist */
	LED_enumWrongPin,			/*Selected Pin Doesn't Exist */
	LED_enumWrongConfig,		/*Selected Configuration type Not Found */
	LED_enumWrongLogicState,	/*Selected Logic state type Not Found*/
	LED_enumWrongLed,			/*Selected LED is not Found*/
	LED_enumNullPointer,		/*NULL Pointer is passed*/
	LED_enumWrongActiveStatus,	/*Selected Active state doesn't exist*/
	LED_enumWrongOutputState	/*Selected Output state doesn't exist*/
	
} LED_enumErrorStatus_t;




/*
 *@brief  : Function to Configure the Pins of LEDS.
 *@param  :	Void.
 *@return : Error State                                                                    
 */
LED_enumErrorStatus_t LED_enumInit(void);


/*
 *@brief  : Function to set value to specific LED
 *@param  : LED number , Value of Output of this LED
 *@return : Error State                                                                      
 */
LED_enumErrorStatus_t LED_enumSetLedState(u8 Copy_u8LedNumber, LED_enumOutputStatus_t LED_enumOutputStatus);


#endif /* LED_H_ */