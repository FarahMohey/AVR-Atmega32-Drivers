/*
 ============================================================================
 Name        : Seven_SEG.h
 Author      : Farah Mohey
 Description : Header file for Seven Segment Driver
 Created	 : 04-Jan-24	
 ============================================================================
 */


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_

#include "D:\AVR_Tasks\Lab1\SourceCode\00-LIB\STD_TYPES.h"
#include "Seven_SEG_cfg.h"
#include "D:\AVR_Tasks\Lab1\SourceCode\01-MCAL\01_PORT\PORT_cfg.h"


/*Enum for the returned error state*/
typedef enum
{
	Seven_SEG_enumNOK,				  /*Everything Not Ok, Function had Not Performed Correctly */
	Seven_SEG_enumOK,				  /*Everything Ok, Function had  Performed Correctly */
	Seven_SEG_enumWrongPort,	 	  /*Selected Port Doesn't Exist */
	Seven_SEG_enumWrongPin,		 	  /*Selected Pin Doesn't Exist  */
	Seven_SEG_enumWrongConfig,		  /*Selected Configuration type Not Found (Not OUTPUT )*/
	Seven_SEG_enumWrongActiveState,	  /*Selected Active State Not Found (Not Common Cathode OR Common Anode) */
	Seven_SEG_enumWrongSevenSEG,	  /*Selected Seven_SEG is not Found */
	Seven_SEG_enumWrongValue,		  /*Selected Value can't be handled */
	Seven_SEG_enumWrongLedID,		  /*Selected Led ID not found */
	Seven_SEG_enumWrongNumOfSevenSEG, /*Selected Value Exceeding number of pins in the Controller */

} Seven_SEG_enumErrorStatus_t;

/*
 *@brief  : Function to Configure the Pins of SevenSegment.
 *@param  :Void.
 *@return : Error State                                               
 */	
Seven_SEG_enumErrorStatus_t Seven_SEG_enumInit (void);


/*
 *@brief  : Function to set value of specific SevenSegment
 *@param  : SevenSegment number , Value of Output of this SevenSegment
 *@return : Error State                                                                      
 */
Seven_SEG_enumErrorStatus_t Seven_SEG_enumSetValue(u8 Copy_u8Seven_SEGNum, u8 Copy_u8Seven_SEGValue);


/*
 * @brief   Function to set a common value for all SevenSegment displays.
 * @param   Value: The value to be displayed on all SevenSegment displays.
 * @return  Error State indicating the success or failure of the operation.
 * 
 */
Seven_SEG_enumErrorStatus_t Seven_SEG_enumSetValueForAll(u32 Copy_u32Seven_SEG_ALLValue);




#endif /* SEVEN_SEG_H_ */