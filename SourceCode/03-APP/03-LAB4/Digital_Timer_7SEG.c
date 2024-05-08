/*
 ============================================================================
 Name        : Digital_Timer_7SEG.c
 Author      : Farah Mohey
 Description : 
 Created	 : 09-Feb-24	
 ============================================================================
 */

#include "D:\AVR_Tasks\Lab1\SourceCode\02-HAL\02-Seven_SEG\Seven_SEG.h"
#include "D:\AVR_Tasks\Lab1\SourceCode\02-HAL\01-SWITCH\SWITCH.h"
#include "D:\AVR_Tasks\Lab1\SourceCode\02-HAL\00-LED\LED.h"



void Digital_Timer_7SEG(void);

void Digital_Timer_7SEG(void)
{
	LED_enumInit();
	SWITCH_enumInit();
	Seven_SEG_enumInit();
	
	/*Counter to be Displayed*/
	u8 Loc_u8Counter=0;
	/*State of the Increment Switch*/
	u8 Loc_u8IncSwitchState;
	/*State of the Decrement Switch*/
	u8 Loc_u8DecSwitchState;
	/*State of the Start Switch*/
	u8 Loc_u8StartSwitchState;
	
	while (1)
	{
		/*If Increment Switch is Pressed, Increment the Counter*/
		SWITCH_enumReadValue(INC_SWITCH,&Loc_u8IncSwitchState);

		if(!Loc_u8IncSwitchState)
		{
			/*Debouncing*/
			DIO_DelayMs(200);
			SWITCH_enumReadValue(INC_SWITCH,&Loc_u8IncSwitchState);
			
			if(!Loc_u8IncSwitchState)
			{
				Loc_u8Counter++;
				Seven_SEG_enumSetValueForAll(Loc_u8Counter);
			}
		}
		
		
		/*If Decrement Switch is Pressed, Decrement the Counter*/
		SWITCH_enumReadValue(DEC_SWITCH,&Loc_u8DecSwitchState);
		if(!Loc_u8DecSwitchState)
		{
			/*Debouncing*/
			DIO_DelayMs(200);
			SWITCH_enumReadValue(DEC_SWITCH,&Loc_u8DecSwitchState);
			
			if(!Loc_u8DecSwitchState)
			{
				//	if(Loc_u8Counter)
				//{
				Loc_u8Counter--;
				Seven_SEG_enumSetValueForAll(Loc_u8Counter);
				//	}
				
			}
		}
		
		/*If Reset Switch is Pressed, Decrement the Counter*/
		SWITCH_enumReadValue(RESET_SWITCH,&Loc_u8StartSwitchState);
		if(!Loc_u8StartSwitchState)
		{
			/*Debouncing*/
			DIO_DelayMs(200);
			SWITCH_enumReadValue(RESET_SWITCH,&Loc_u8StartSwitchState);
			
			if(!Loc_u8StartSwitchState)
			{
				/*While Counter is Bigger Than Zero, Decrement and Display*/
				while(Loc_u8Counter > 0)
				{
					DIO_DelayMs(1000);	 //Wait 1 Sec
					Seven_SEG_enumSetValueForAll(Loc_u8Counter);
					Loc_u8Counter--;
				}
				/*Wait One Second and Display Zero*/ 
				DIO_DelayMs(1000); 
				Seven_SEG_enumSetValueForAll(Loc_u8Counter);
				
				/*Set the LED for 5 Seconds*/
				LED_enumSetLedState(LED0,LED_enumON);
				DIO_DelayMs(5000);
				LED_enumSetLedState(LED0,LED_enumOFF);
			}
		}	
	}
}
