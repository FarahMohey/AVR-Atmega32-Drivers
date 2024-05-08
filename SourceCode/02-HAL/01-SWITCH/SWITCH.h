/*
 ============================================================================
 Name        : SWITCH.h
 Author      : Farah Mohey
 Description : Header file for SWITCH Driver
 Created	 : 27-Dec-23	
 ============================================================================
 */



#ifndef SWITCH_H_
#define SWITCH_H_


#include "D:\AVR_Tasks\Lab1\SourceCode\00-LIB\STD_TYPES.h"
#include "SWITCH_cfg.h"
#include "D:\AVR_Tasks\Lab1\SourceCode\01-MCAL\01_PORT\PORT_cfg.h"



/*Enum for the returned error state*/
typedef enum
{
	SWITCH_enumNOK,				/*Everything Not Ok, Function had Not Performed Correctly */
	SWITCH_enumOK,				/*Everything Ok, Function had  Performed Correctly */
	SWITCH_enumWrongPort,		/*Selected Port Doesn't Exist */
	SWITCH_enumWrongPin,		/*Selected Pin Doesn't Exist */
	SWITCH_enumWrongConfig,		/*Selected Configuration type Not Found */
	SWITCH_enumWrongSWITCH,		/*Selected SWITCH is not Found*/
	SWITCH_enumNullPointer		/*NULL Pointer is passed*/
	
} SWITCH_enumErrorStatus_t;




/*
 *@brief  : Function to Configure the Pins of SWITCH.
 *@param  :	Void.
 *@return : Error State                                                                    
 */
SWITCH_enumErrorStatus_t SWITCH_enumInit(void);


/*
 *@brief  : Function to read value from specific SWITCH
 *@param  : SWITCH number , Value of this SWITCH
 *@return : Error State                                                                      
 */
SWITCH_enumErrorStatus_t SWITCH_enumReadValue(u8 Copy_u8SWITCHNumber, DIO_enumLogicState_t* Add_PenumSwitchState);



#endif /* SWITCH_H_ */