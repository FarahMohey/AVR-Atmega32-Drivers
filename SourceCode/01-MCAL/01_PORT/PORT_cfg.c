/*
 ============================================================================
 Name        : PORT_cfg.c
 Author		 : Farah Mohey
 Description : 
 Created	 : 12-Dec-23	 12:25:59 PM
=============================================================================
 */ 
#include "PORT_cfg.h"
#include "PORT.h"

/*If the User Choose Post_Compile_Configuration*/
#if (CONFIGURATION_TYPE == POST_Compile_Configuration)

/*Allocate an global array of TOTAL NUMBER OF PINS=(NUM_OF_PORTS * NUM_OF_PINS)*/
PORT_enumpinopt_t PORT_PINcfg [NUM_OF_PORTS * NUM_OF_PINS] =
{	PORT_enumINPUT_EXTERNALPD,	/* PortA_Pin0 */
	PORT_enumINPUT_EXTERNALPD,	/* PortA_Pin1 */
	PORT_enumINPUT_EXTERNALPD,	/* PortA_Pin2 */
	PORT_enumINPUT_EXTERNALPD,	/* PortA_Pin3 */
	PORT_enumINPUT_EXTERNALPD,	/* PortA_Pin4 */
	PORT_enumINPUT_EXTERNALPD,	/* PortA_Pin5 */
	PORT_enumINPUT_EXTERNALPD,	/* PortA_Pin6 */
	PORT_enumINPUT_EXTERNALPD,	/* PortA_Pin7 */	/*PORTB*/
	PORT_enumINPUT_EXTERNALPD,	/* PortB_Pin0 */
	PORT_enumINPUT_EXTERNALPD,	/* PortB_Pin1 */
	PORT_enumOUTPUT_LOW,		/* PortB_Pin2 */
	PORT_enumINPUT_EXTERNALPD,	/* PortB_Pin3 */
	PORT_enumINPUT_EXTERNALPD,	/* PortB_Pin4 */
	PORT_enumINPUT_EXTERNALPD,	/* PortB_Pin5 */
	PORT_enumINPUT_EXTERNALPD,	/* PortB_Pin6 */
	PORT_enumINPUT_EXTERNALPD,	/* PortB_Pin7 */	/*PORTC*/
	PORT_enumINPUT_EXTERNALPD,	/* PortC_Pin0 */
	PORT_enumINPUT_EXTERNALPD,	/* PortC_Pin1 */
	PORT_enumINPUT_EXTERNALPD,	/* PortC_Pin2 */
	PORT_enumINPUT_EXTERNALPD,	/* PortC_Pin3 */
	PORT_enumINPUT_EXTERNALPD,	/* PortC_Pin4 */
	PORT_enumINPUT_EXTERNALPD,	/* PortC_Pin5 */
	PORT_enumINPUT_EXTERNALPD,	/* PortC_Pin6 */
	PORT_enumINPUT_EXTERNALPD,	/* PortC_Pin7 */	/*PORTD*/
	PORT_enumINPUT_EXTERNALPD,	/* PortD_Pin0 */
	PORT_enumINPUT_EXTERNALPD,	/* PortD_Pin1 */
	PORT_enumINPUT_EXTERNALPD,	/* PortD_Pin2 */
	PORT_enumINPUT_EXTERNALPD,	/* PortD_Pin3 */
	PORT_enumINPUT_EXTERNALPD,	/* PortD_Pin4 */
	PORT_enumINPUT_EXTERNALPD,	/* PortD_Pin5 */
	PORT_enumINPUT_EXTERNALPD,	/* PortD_Pin6 */
	PORT_enumINPUT_EXTERNALPD,	/* PortD_Pin7 */
};

#endif