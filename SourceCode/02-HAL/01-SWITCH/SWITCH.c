/*
 ============================================================================
 Name        : SWITCH.c
 Author      : Farah Mohey
 Description : Source file for SWITCH Driver
 Created	 : 27-Dec-23	
 ============================================================================
 */


#include "SWITCH.h"


/* Extern for global configuration Array*/
extern SWITCH_strCfg SWITCHES_Cfg[NUM_OF_SWITCHES];


/*
 *@brief  : Function to Configure the Pins of SWITCH.
 *@param  :	Void.
 *@return : Error State                                                                    
 */
SWITCH_enumErrorStatus_t SWITCH_enumInit(void)
{
	
	/* Declare variables to store error states for DIO and SWITCH  */
	DIO_enumError_t Loc_enumReturnDIOErrorState = DIO_enumOK;
	SWITCH_enumErrorStatus_t Loc_enumReturnSWITCHErrorState = SWITCH_enumOK;
	
	
	if (NUM_OF_SWITCHES >= NUM_OF_PORTS * NUM_OF_PINS){
		 /*User entered invalid Number of SWITCHES greater than the Number of pins in the target */
		 /*Number of valid SWITCHES= NUM_OF_PORTS=4 * NUM_OF_PINS=8 */
		Loc_enumReturnSWITCHErrorState = SWITCH_enumWrongPin;	/* Set SWITCH error state to WrongPin */
	}
	else
	{
		Loc_enumReturnSWITCHErrorState = SWITCH_enumOK;		/* Set SWITCH error state to OK */
	}
	
	//For loop on the current number of SWITCHES
	for(u8 Loc_u8Counter = 0;( Loc_u8Counter < NUM_OF_SWITCHES ) && ( Loc_enumReturnSWITCHErrorState == SWITCH_enumOK ); Loc_u8Counter++)
	{
		 /* Set the DIO pin configuration for SWITCHES */
		 switch ( SWITCHES_Cfg[Loc_u8Counter].ConfigStatus )
		 {
			case DIO_enumINPUT_PULLDOWN: 
			 
				 /* Set DIO Pin Configuration As PullDown */ 
				Loc_enumReturnDIOErrorState = DIO_enumSetPinConfig( SWITCHES_Cfg[Loc_u8Counter].Port , SWITCHES_Cfg[Loc_u8Counter].Pin , DIO_enumINPUT_PULLDOWN );
			
				/*Switch case to handle DIO error states in SWITCH error states*/
				switch (Loc_enumReturnDIOErrorState)
				{
				case DIO_enumWrongPort:
				Loc_enumReturnSWITCHErrorState = SWITCH_enumWrongPort;		/* Set SWITCH error state to WrongPort */
				break;
				
				case DIO_enumWrongPin:
				Loc_enumReturnSWITCHErrorState = SWITCH_enumWrongPin;		/* Set SWITCH error state to WrongPin */
				break;
				
				default:
				Loc_enumReturnSWITCHErrorState = SWITCH_enumOK;		/* Set SWITCH error state to OK */
				break;
				}
			break; 	
			
			case DIO_enumINPUT_PULLUP: 	
				 /* Set DIO Pin Configuration As PullUP */
				 Loc_enumReturnDIOErrorState = DIO_enumSetPinConfig( SWITCHES_Cfg[Loc_u8Counter].Port , SWITCHES_Cfg[Loc_u8Counter].Pin , DIO_enumINPUT_PULLUP );
				 
				 /*Switch case to handle DIO error states in SWITCH error states*/
				 switch (Loc_enumReturnDIOErrorState)
				 {
					 case DIO_enumWrongPort:
					 Loc_enumReturnSWITCHErrorState = SWITCH_enumWrongPort;		/* Set SWITCH error state to WrongPort */
					 break;
					 
					 case DIO_enumWrongPin:
					 Loc_enumReturnSWITCHErrorState = SWITCH_enumWrongPin;		/* Set SWITCH error state to WrongPin */
					 break;
					 
					 default:
					 Loc_enumReturnSWITCHErrorState = SWITCH_enumOK;			/* Set SWITCH error state to OK */
					 break;
				 }
				 
				break; 	
				 
				default:
				Loc_enumReturnSWITCHErrorState = SWITCH_enumWrongConfig;		/* Set SWITCH error state to Wrong Configuration NOT PullUP OR PullDOWN */
				break; 
		 }
	}
	return Loc_enumReturnSWITCHErrorState ;
}
		 

/*
 *@brief  : Function to read value from specific SWITCH
 *@param  : SWITCH number , Value of this SWITCH
 *@return : Error State                                                                      
 */
SWITCH_enumErrorStatus_t SWITCH_enumReadValue(u8 Copy_u8SWITCHNumber, DIO_enumLogicState_t* Add_PenumSwitchState)
{
	
	/* Declare variables to store error state for SWITCH  */
	SWITCH_enumErrorStatus_t Loc_enumReturnSWITCHErrorState = SWITCH_enumOK;
	
	
	if ( Copy_u8SWITCHNumber > NUM_OF_SWITCHES )		/*User entered invalid Number of SWITCHES greater than the Number of defined SWITCHES */
	{	
		Loc_enumReturnSWITCHErrorState = SWITCH_enumWrongSWITCH;		/*Invalid SWITCH Number ,Doesn't exist*/
	}
	
	else if ( Add_PenumSwitchState == NULL )
	{
		Loc_enumReturnSWITCHErrorState = SWITCH_enumNullPointer;		/* NULL Pointer is passed */
	}
	
	else
	{	/* Calling DIO Read state function */
		Loc_enumReturnSWITCHErrorState = DIO_enumReadState(SWITCHES_Cfg[Copy_u8SWITCHNumber].Port , SWITCHES_Cfg[Copy_u8SWITCHNumber].Pin , Add_PenumSwitchState );
		
	}
	
	return Loc_enumReturnSWITCHErrorState;
}
