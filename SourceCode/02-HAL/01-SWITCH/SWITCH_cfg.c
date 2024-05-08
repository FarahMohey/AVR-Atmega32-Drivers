/*
 ============================================================================
 Name        : SWITCH_cfg.c
 Author      : Farah Mohey
 Description : Source file for Configuring SWITCH Driver
 Created	 : 27-Dec-23	
 ============================================================================
 */

#include "SWITCH_cfg.h"


/*Initializing Array of struct for each SWITCH*/

/**** Struct takes *****/
/*Port from Port Options Port A,B,C,D */
/*Pin from Pins Options From Pin0-->7 */
/*Configuration Status Options Are:
								  Internal PullUP 
								  External PullDOWN */


SWITCH_strCfg SWITCHES_Cfg[NUM_OF_SWITCHES] ={
		[SWITCH0]={.Port= DIO_enumPortB , .Pin= DIO_enumPin7 , .ConfigStatus = DIO_enumINPUT_PULLDOWN},
		[SWITCH1]={.Port= DIO_enumPortB , .Pin= DIO_enumPin4 , .ConfigStatus = DIO_enumINPUT_PULLUP }, 
	 [INC_SWITCH]={.Port= DIO_enumPortB , .Pin= DIO_enumPin6 , .ConfigStatus = DIO_enumINPUT_PULLUP},
	 [DEC_SWITCH]={.Port= DIO_enumPortB , .Pin= DIO_enumPin5 , .ConfigStatus = DIO_enumINPUT_PULLUP}, 
   [RESET_SWITCH]={.Port= DIO_enumPortB , .Pin= DIO_enumPin3 , .ConfigStatus = DIO_enumINPUT_PULLUP}
};

