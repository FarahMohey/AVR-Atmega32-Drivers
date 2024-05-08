/*
 ============================================================================
 Name        : PORT_cfg.h
 Author		 : Farah Mohey
 Description : Header Configuration file for the PORT driver
 Created	 : 12-Dec-23	 12:25:59 PM
=============================================================================
 */ 


#ifndef PORT_CFG_H_
#define PORT_CFG_H_

#include "D:\AVR_Tasks\Lab1\SourceCode\00-LIB\STD_TYPES.h"

/********************** Options **********************/

/* NUMBER OF PORTS Options  */
#define TWO_PORTS 		2
#define THREE_PORTS		3
#define FOUR_PORTS 		4

/* NUMBER OF PINS Options  */
#define SIX_PINS			6
#define SEVEN_PINS			7
#define EIGHT_PINS			8

/*PIN_CONFIGURATION Options */
#define INPUT_INTERNALPU 	1
#define INPUT_EXTERNALPD 	2
#define OUTPUT_HIGH			3
#define OUTPUT_LOW 			4

/*LOGIC_CONFIGURATION Options */
#define PORT_HIGH	1  
#define PORT_LOW	0

/*Post_ & Pre_ CONFIGURATION Options */  
#define Pre_Compile_Configuration		1
#define POST_Compile_Configuration		0

/********************** Micro Configuration **********************/
#define NUM_OF_PORTS			FOUR_PORTS					/*Place one of NUM_OF_PORTS Options*/
#define NUM_OF_PINS 			EIGHT_PINS					/*Place one of NUM_OF_PINS*/
#define TOTAL_NUM_OF_PINS_PER_SYSTEM	NUM_OF_PORTS * NUM_OF_PINS	/*Total number of pins in controller */
#define CONFIGURATION_TYPE		POST_Compile_Configuration	/*Place one of Post_&Pre_CONFIGURATION Options*/



/**********************PINS Configuration**********************/  
#define	PORT_PortA_Pin0 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortA_Pin1 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortA_Pin2 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortA_Pin3			INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortA_Pin4 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortA_Pin5 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortA_Pin6 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortA_Pin7 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */

#define PORT_PortB_Pin0 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortB_Pin1 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortB_Pin2 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortB_Pin3			INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortB_Pin4 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortB_Pin5 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortB_Pin6 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortB_Pin7 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */

#define PORT_PortC_Pin0 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortC_Pin1 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortC_Pin2 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortC_Pin3			INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortC_Pin4 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortC_Pin5 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortC_Pin6 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortC_Pin7 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */

#define PORT_PortD_Pin0 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortD_Pin1 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortD_Pin2 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortD_Pin3			INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortD_Pin4 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortD_Pin5 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortD_Pin6 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */
#define PORT_PortD_Pin7 		INPUT_EXTERNALPD/*Place one of PIN_CONFIGURATION Options */

/**********************Post compile configuration**********************/
typedef enum
{
	PORT_enumINPUT_INTERNALPU,
	PORT_enumINPUT_EXTERNALPD,
	PORT_enumOUTPUT_HIGH,
	PORT_enumOUTPUT_LOW,
}PORT_enumpinopt_t;

typedef enum
{
	PORT_enumPortA,
	PORT_enumPortB,
	PORT_enumPortC,
	PORT_enumPortD,
}PORT_enumPortNum_t;



#endif /* PORT_CFG_H_ */