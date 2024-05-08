/*
 ============================================================================
 Name        : Seven_SEG.c
 Author      : Farah Mohey
 Description : Source file for Configuring Seven Segment Driver
 Created	 : 04-Jan-24	
 ============================================================================
 */

#include "Seven_SEG_cfg.h"

Seven_SEG_strCfg Seven_SEG[NUM_OF_SevenSEG] = 
{
	/*Configuration of Port , Pin , Config Status for each LED in Seven_SEG0 */
	[Seven_SEG0] =
	{
		.LedA_Port = DIO_enumPortD,
		.LedA_Pin  = DIO_enumPin0,
		
		.LedB_Port = DIO_enumPortD,
		.LedB_Pin  = DIO_enumPin1,
		
		.LedC_Port = DIO_enumPortD,
		.LedC_Pin  = DIO_enumPin2,
		
		.LedD_Port = DIO_enumPortD,
		.LedD_Pin  = DIO_enumPin3,
		
		.LedE_Port = DIO_enumPortD,
		.LedE_Pin  = DIO_enumPin4,
		
		.LedF_Port = DIO_enumPortD,
		.LedF_Pin  = DIO_enumPin5,
		
		.LedG_Port = DIO_enumPortD,
		.LedG_Pin  = DIO_enumPin6,
		
		.LedDP_Port = DIO_enumPortD,
		.LedDP_Pin  = DIO_enumPin7,
		
		.Seven_SEG_ActiveStatus = Seven_SEG_enumCommonCathode
	},
	
	/*Configuration of Port , Pin , Config Status for each LED in Seven_SEG1 */ 
	[Seven_SEG1] = {
		.LedA_Port = DIO_enumPortC,
		.LedA_Pin  = DIO_enumPin0,
		
		.LedB_Port = DIO_enumPortC,
		.LedB_Pin  = DIO_enumPin1,		
		
		.LedC_Port = DIO_enumPortC,
		.LedC_Pin  = DIO_enumPin2,
		
		.LedD_Port = DIO_enumPortC,
		.LedD_Pin  = DIO_enumPin3,
		
		.LedE_Port = DIO_enumPortC,
		.LedE_Pin  = DIO_enumPin4,
		
		.LedF_Port = DIO_enumPortC,
		.LedF_Pin  = DIO_enumPin5,
		
		.LedG_Port = DIO_enumPortC,
		.LedG_Pin  = DIO_enumPin6,		
		
		.LedDP_Port = DIO_enumPortC,
		.LedDP_Pin  = DIO_enumPin7,		
		
		.Seven_SEG_ActiveStatus = Seven_SEG_enumCommonCathode
	}
	

	
};