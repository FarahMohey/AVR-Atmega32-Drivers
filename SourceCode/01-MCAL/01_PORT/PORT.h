/*
 ============================================================================
 Name        : PORT.h
 Author		 : Farah Mohey
 Description : Header File for the PORT driver
 Created	 : 12-Dec-23	 12:25:59 PM
=============================================================================
 */ 


#ifndef PORT_H_
#define PORT_H_
#include "PORT_cfg.h"
#include "D:\AVR_Tasks\Lab1\SourceCode\00-LIB\STD_TYPES.h"
#include "D:\AVR_Tasks\Lab1\SourceCode\00-LIB\Bit_Math.h"
#include "D:\AVR_Tasks\Lab1\SourceCode\00-LIB\AVR_Registers.h"

extern PORT_enumpinopt_t PORT_PINcfg [NUM_OF_PORTS * NUM_OF_PINS];


/**
 @brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin and to configure them by PRE or POST Configuration.
 @param  : Nothing
 @return : Nothing                                               
 */	
void Init_PORT(void);


#endif /* PORT_H_ */
