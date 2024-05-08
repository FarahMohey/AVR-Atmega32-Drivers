/*
 ============================================================================
 Name        : Seven_SEG_cfg.h
 Author      : Farah Mohey
 Description : Header file for Configuring Seven Segment Driver
 Created	 : 04-Jan-24	
 ============================================================================
 */

#ifndef SEVEN_SEG_CFG_H_
#define SEVEN_SEG_CFG_H_

#include "D:\AVR_Tasks\Lab1\SourceCode\01-MCAL\00-DIO\DIO.h"

/* Defined SevenSegments */
#define Seven_SEG0 0
#define Seven_SEG1 1

/*Total Number of Defined SevenSegments */
#define NUM_OF_SevenSEG 2

/*Total Number of Pins Per 1 SevenSegment */
#define NUM_OF_PINS_PER_SevenSEG 8		/*Each SevenSegment Requires 8 Pins to be Configured */


/*Enum to represent ActiveState of the Seven_SEG */
typedef enum
{
	Seven_SEG_enumCommonCathode,
	Seven_SEG_enumCommonAnode
	
}Seven_SEG_enumActiveState_t;



/* Names of LEDS in SevenSegment */
typedef enum 
{
	Seven_SEG_enumLedA ,
	Seven_SEG_enumLedB ,
	Seven_SEG_enumLedC ,
	Seven_SEG_enumLedD ,
	Seven_SEG_enumLedE ,
	Seven_SEG_enumLedF ,
	Seven_SEG_enumLedG ,
	Seven_SEG_enumLedDP 
}Seven_SEG_enumLedID_t;

/*Enum of Numbers to be displayed in Seven Segment */
typedef enum
{
	
	Seven_SEG_enumNumberZero,		/* Number 0 */
	Seven_SEG_enumNumberOne,		/* Number 1 */
	Seven_SEG_enumNumberTwo,		/* Number 2 */
	Seven_SEG_enumNumberThree,		/* Number 3 */	
	Seven_SEG_enumNumberFour,		/* Number 4 */
	Seven_SEG_enumNumberFive,		/* Number 5 */	
	Seven_SEG_enumNumberSix,		/* Number 6 */
	Seven_SEG_enumNumberSeven,		/* Number 7 */
	Seven_SEG_enumNumberEight,		/* Number 8 */
	Seven_SEG_enumNumberNine		/* Number 9 */
	
}
Seven_SEG_enum_NumbersDisplayed_Sev_SEG_t;


/*Struct To Represent Each SevenSegment*/
typedef struct
{	
	/* Set Port & Pin number for each LED */
	/* LED A */ 
	DIO_enumPorts_t LedA_Port;		/*Set Port number for LEDA */
	DIO_enumPins_t LedA_Pin ;		/*Set Pin number for LEDA */
	
	/* LED B */	
	DIO_enumPorts_t LedB_Port;		/*Set Port number for LEDB */
	DIO_enumPins_t LedB_Pin ;		/*Set Pin number for LEDB */
	
	/* LED C */
	DIO_enumPorts_t LedC_Port;		/*Set Port number for LEDC */
	DIO_enumPins_t LedC_Pin ;		/*Set Pin number for LEDC */
	
	/* LED D */
	DIO_enumPorts_t LedD_Port;		/*Set Port number for LEDD */
	DIO_enumPins_t LedD_Pin ;		/*Set Pin number for LEDD */
	
	/* LED E */
	DIO_enumPorts_t LedE_Port;		/*Set Port number for LEDE */
	DIO_enumPins_t LedE_Pin ;		/*Set Pin number for LEDE */
	
	/* LED F */
	DIO_enumPorts_t LedF_Port;		/*Set Port number for LEDF */
	DIO_enumPins_t LedF_Pin ;		/*Set Pin number for LEDF */
	
	/* LED G */
	DIO_enumPorts_t LedG_Port;		/*Set Port number for LEDG */
	DIO_enumPins_t LedG_Pin ;		/*Set Pin number for LEDG */
	
	/* LED DP */
	DIO_enumPorts_t LedDP_Port;		/*Set Port number for LEDDP */
	DIO_enumPins_t LedDP_Pin ;		/*Set Pin number for LEDDP */
	
	Seven_SEG_enumActiveState_t Seven_SEG_ActiveStatus;	/*ActiveState Common Cathode OR Common Anode*/

}Seven_SEG_strCfg;



#endif /* SEVEN_SEG_CFG_H_ */