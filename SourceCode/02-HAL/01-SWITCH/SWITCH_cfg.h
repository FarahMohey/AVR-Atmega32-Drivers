/*
 ============================================================================
 Name        : SWITCH_cfg.h
 Author      : Farah Mohey
 Description : Header file for Configuring SWITCH_cfg Driver
 Created	 : 27-Dec-23	
 ============================================================================
 */



#ifndef SWITCH_CFG_H_
#define SWITCH_CFG_H_

#include "D:\AVR_Tasks\Lab1\SourceCode\01-MCAL\00-DIO\DIO.h"



/* Defined SWITCHES */
#define SWITCH0 0
#define SWITCH1 1
#define INC_SWITCH 2
#define DEC_SWITCH 3
#define RESET_SWITCH 4

/*Total Number of Defined SWITCHES */
#define NUM_OF_SWITCHES 5


/*Struct To Represent Each SWITCH*/
typedef struct
{
	DIO_enumPorts_t Port;	/*Ports A , B, C, D*/
	DIO_enumPins_t Pin ;	/*Pins 0,1,2,3,4,5,6,7*/
	DIO_enumConfig_t ConfigStatus; 	/*Internal PullUP OR External PullDOWN*/

}SWITCH_strCfg;


#endif /* SWITCH_CFG_H_ */