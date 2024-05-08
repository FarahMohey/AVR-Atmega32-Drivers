/*
 ============================================================================
 Name        : LED.c
 Author      : Farah Mohey
 Description : Source file for LED Driver
 Created	 : 24-Dec-23	
 ============================================================================
 */


#include "LED.h"

/* Extern for global configuration Array*/
extern LED_strCfg LEDS_Cfg[NUM_OF_LEDS];

/*
 *@brief  : Function to Configure the Pins of LEDS.
 *@param  :	Void.
 *@return : Error State                                                                    
 */
LED_enumErrorStatus_t LED_enumInit(void){
	
	/* Declare variables to store error states for DIO and LED  */
	DIO_enumError_t Loc_enumReturnDIOErrorState = DIO_enumOK;
	LED_enumErrorStatus_t Loc_enumReturnLEDErrorState = LED_enumOK; ///check again 
	
	
	if (NUM_OF_LEDS >= NUM_OF_PORTS * NUM_OF_PINS){
		 /*User entered invalid Number of LEDS greater than the Number of pins in the target */
		 /*Number of valid LEDS= NUM_OF_PORTS=4 * NUM_OF_PINS=8 */
		Loc_enumReturnLEDErrorState = LED_enumWrongPin;
	}
	else{
		Loc_enumReturnLEDErrorState = LED_enumOK;
	}
	
	//For loop on the current number of LEDS
	for(u8 Loc_u8Counter = 0;( Loc_u8Counter < NUM_OF_LEDS ) && ( Loc_enumReturnLEDErrorState == LED_enumOK ); Loc_u8Counter++)
	{
		 /* Set the DIO pin configuration for LEDS */
		 Loc_enumReturnDIOErrorState = DIO_enumSetPinConfig (LEDS_Cfg[Loc_u8Counter].Port, LEDS_Cfg[Loc_u8Counter].Pin, DIO_enumOUTPUT);
	
		/*Switch case for setting DIO error states in LED error states*/
		switch (Loc_enumReturnDIOErrorState)
		{
			case DIO_enumWrongPort:
			Loc_enumReturnLEDErrorState = LED_enumWrongPort;	/* Set LED error state to WrongPort */
			break;
			
			case DIO_enumWrongPin:
			Loc_enumReturnLEDErrorState = LED_enumWrongPin;		/* Set LED error state to WrongPin */
			break;
			
			case DIO_enumWrongConfig:
			/* Set LED error state to WrongConfig */
			Loc_enumReturnLEDErrorState = LED_enumWrongConfig;	/* Set LED error state to WrongConfig-->Input , RightConfig-->OUTPUT */
			break;
			
			default:
			Loc_enumReturnLEDErrorState = LED_enumOK;		/* Set LED error state to OK */
			break;
		}
		
		/* If LED is OK and configured on right Port, Pin, Output configuration THEN configure the LED's active state and output status */
		if (Loc_enumReturnLEDErrorState == LED_enumOK){
			
			/*Switch case for Active State--> LOW OR HIGH */
			switch(LEDS_Cfg[Loc_u8Counter].ActiveState)
			{
				case LED_enumActiveHigh:	/*ActiveHigh_ON = 1		, ActiveHigh_OFF = 0 */
				
				/*Switch case for Output Status--> ON OR OFF */
				switch(LEDS_Cfg[Loc_u8Counter].OutputStatus)
				{
					case LED_enumON:		/*ActiveHigh_ON = 1*/
					Loc_enumReturnLEDErrorState = DIO_enumSetPin(LEDS_Cfg[Loc_u8Counter].Port , LEDS_Cfg[Loc_u8Counter].Pin , DIO_enumLOGIC_HIGH);
					break;
					
					case LED_enumOFF:	/* ActiveHigh_OFF = 0 */
					Loc_enumReturnLEDErrorState = DIO_enumSetPin(LEDS_Cfg[Loc_u8Counter].Port , LEDS_Cfg[Loc_u8Counter].Pin , DIO_enumLOGIC_LOW);
					break;
					
					default:		/* User choose invalid option other than ON & OFF */
					Loc_enumReturnLEDErrorState = LED_enumWrongOutputState;
					break;
				}
				
				break;
				
				case LED_enumActiveLow:		/* ActiveLow_ON = 0		, ActiveLow_OFF = 1	*/
				
				/*Switch case for Output Status--> ON OR OFF */
				switch(LEDS_Cfg[Loc_u8Counter].OutputStatus)
				{
					case LED_enumON:		/* ActiveLow_ON = 0	*/
					Loc_enumReturnLEDErrorState = DIO_enumSetPin(LEDS_Cfg[Loc_u8Counter].Port , LEDS_Cfg[Loc_u8Counter].Pin , DIO_enumLOGIC_LOW);
					break;
					
					case LED_enumOFF:	/* ActiveLow_OFF = 1 */
					Loc_enumReturnLEDErrorState = DIO_enumSetPin(LEDS_Cfg[Loc_u8Counter].Port , LEDS_Cfg[Loc_u8Counter].Pin , DIO_enumLOGIC_HIGH);
					break;
					
					default:		/* User choose invalid option other than ON & OFF */
					Loc_enumReturnLEDErrorState = LED_enumWrongOutputState;
					break;
				}
				
				break;
				
				default:	/* User choose invalid option other than Active LOW OR HIGH */
				Loc_enumReturnLEDErrorState = LED_enumWrongActiveStatus;
				break;
			}
		}
		else {
			/***** DO NOTHING LED ERROR STATE IS NOT OK****/
		}	
	}
	return Loc_enumReturnLEDErrorState;
}



/*
 *@brief  : Function to set value to specific LED
 *@param  : LED number , Value of Output of this LED
 *@return : Error State                                                                      
 */
LED_enumErrorStatus_t LED_enumSetLedState(u8 Copy_u8LedNumber, LED_enumOutputStatus_t LED_enumOutputStatus){
	
	/* Declare variables to store error states for DIO and LED  */
	//DIO_enumError_t Loc_enumReturnDIOErrorState = DIO_enumOK;
	LED_enumErrorStatus_t Loc_enumReturnLEDErrorState = LED_enumOK;
	
	
	if ( Copy_u8LedNumber > NUM_OF_LEDS )		/*User entered invalid Number of LEDS greater than the Number of defined LEDS */
	{	
		Loc_enumReturnLEDErrorState = LED_enumWrongLed;		/*Invalid LED Number ,Doesn't exist*/
	}
	
	else if (LED_enumOutputStatus > LED_enumON || LED_enumOutputStatus < LED_enumOFF )
	{
		Loc_enumReturnLEDErrorState = LED_enumWrongOutputState;		/*Invalid Output State ,Doesn't exist , Valid Output State --> ON or OFF*/
	}
	
	else
	{
		Loc_enumReturnLEDErrorState = LED_enumOK;
		
		/*Switch case on Active State--> Active LOW OR HIGH */
		switch( LEDS_Cfg[Copy_u8LedNumber].ActiveState ){
			
			case LED_enumActiveHigh:		/*ActiveHigh_ON = 1		, ActiveHigh_OFF = 0 */
			
			/*Switch case for Output Status--> ON OR OFF */
			switch( LED_enumOutputStatus )
			{
				case LED_enumON:	/* ActiveHigh_ON = 1 */
				Loc_enumReturnLEDErrorState = DIO_enumSetPin(LEDS_Cfg[Copy_u8LedNumber].Port , LEDS_Cfg[Copy_u8LedNumber].Pin , DIO_enumLOGIC_HIGH);
				break;
				
				case LED_enumOFF:	/* ActiveHigh_OFF = 0 */
				Loc_enumReturnLEDErrorState = DIO_enumSetPin(LEDS_Cfg[Copy_u8LedNumber].Port , LEDS_Cfg[Copy_u8LedNumber].Pin , DIO_enumLOGIC_LOW);
				break;
				
				default: /* User entered Invalid Ouput State other than ON , OFF */
				Loc_enumReturnLEDErrorState = LED_enumWrongOutputState;
				break;
			}
			
			break;
			
			case LED_enumActiveLow:		/* ActiveLow_ON = 0		, ActiveLow_OFF = 1	*/ 
			
				/*Switch case for Output Status--> ON OR OFF */
				switch( LED_enumOutputStatus ){
					case LED_enumON:	/* ActiveLow_ON = 0	*/ 
					Loc_enumReturnLEDErrorState = DIO_enumSetPin(LEDS_Cfg[Copy_u8LedNumber].Port , LEDS_Cfg[Copy_u8LedNumber].Pin , DIO_enumLOGIC_LOW);
					break;
					
					case LED_enumOFF:	/* ActiveLow_OFF = 1 */	
					Loc_enumReturnLEDErrorState = DIO_enumSetPin(LEDS_Cfg[Copy_u8LedNumber].Port , LEDS_Cfg[Copy_u8LedNumber].Pin , DIO_enumLOGIC_HIGH);
					break;
					
					default:	/* User entered Invalid Ouput State other than ON , OFF */
					Loc_enumReturnLEDErrorState = LED_enumWrongOutputState;
					break;
				}
				break;
				
			default:	/* User entered Invalid Active State other than ActiveLOW , Active HIGH */
			Loc_enumReturnLEDErrorState = LED_enumWrongActiveStatus; 
			break;
			
		}
		Loc_enumReturnLEDErrorState = LED_enumOK;
	}
	
	return Loc_enumReturnLEDErrorState;
}
