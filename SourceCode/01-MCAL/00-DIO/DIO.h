/*
 * Driver  : DIO
 * File    : DIO.h
 * Created: 29-Nov-23 3:14:35 PM
 * Author: Farah
 */ 




#ifndef DIO_H_
#define DIO_H_

#include "D:\AVR_Tasks\Lab1\SourceCode\00-LIB\STD_TYPES.h"
#include "D:\AVR_Tasks\Lab1\SourceCode\00-LIB\Bit_Math.h"
#include "D:\AVR_Tasks\Lab1\SourceCode\00-LIB\AVR_Registers.h"

/*Enum for the returned error state*/

typedef enum 
{
	DIO_enumNOK,				/*Everything Not Ok, Function had Not Performed Correctly */
	DIO_enumOK,					/*Everything Ok, Function had  Performed Correctly */
	DIO_enumWrongPort,			/*Selected Port Doesn't Exist */
	DIO_enumWrongPin,			/*Selected Pin Doesn't Exist */
	DIO_enumWrongConfig,		/*Selected Configuration type Not Found */
	DIO_enumWrongLogicState,	/*Selected Logic state type Not Found*/
	DIO_enumWrongValue,
	DIO_enumNullPointer			/*NULL Pointer is passed*/
	
	} DIO_enumError_t;


/*Enum to represent the ports Type of the AVR Atmega32*/
typedef enum 
{
	DIO_enumPortA, 
	DIO_enumPortB,
	DIO_enumPortC,
	DIO_enumPortD
	} DIO_enumPorts_t;
	
	
/*Enum to represent the pins for each port in AVR Atmega32*/
typedef enum 
{
	DIO_enumPin0, 
	DIO_enumPin1, 
	DIO_enumPin2, 
	DIO_enumPin3, 
	DIO_enumPin4, 
	DIO_enumPin5, 
	DIO_enumPin6, 
	DIO_enumPin7
	} DIO_enumPins_t;
	
	
/*Enum to configure the direction of Pins/Ports (input or output)*/	
typedef enum 
{
	DIO_enumOUTPUT,				/*Pin Configuration to be Output*/
	DIO_enumINPUT_PULLUP ,		/*Pin Configuration to be Internal Input PullUp*/
	DIO_enumINPUT_PULLDOWN		/*Pin Configuration to be External Input PullDown*/
	} DIO_enumConfig_t;
	
	
/*Enum to represent the Logic State Type of Pins/Ports (high or low)*/	
typedef enum
{
	DIO_enumLOGIC_LOW, 
	DIO_enumLOGIC_HIGH
	}DIO_enumLogicState_t;
	
/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumConfig_t Copy_enumConfig);

/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig);

/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState);

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState); 

/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue);


DIO_enumError_t DIO_enumSetPortValue(DIO_enumPorts_t Copy_enumPortNum,u8 Copy_u8Value);



void DIO_DelayMs(u32 Copy_u32TimeMs);



#endif /* DIO_H_ */