/*
 * main.c
 *
 * Created: 25-Nov-23 11:26:39 AM
 *  Author: Farah
 */ 

void DIOTask2(void);

#include "D:\AVR_Tasks\Lab1\SourceCode\01-MCAL\00-DIO\DIO.h"

DIO_enumLogicState_t Loc_u8PINB7State=DIO_enumLOGIC_LOW;


void DIOTask2(void)
{
	 /*Configure pins 0-3 of port A as output pins*/
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin0, DIO_enumOUTPUT);
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin1, DIO_enumOUTPUT);
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin2, DIO_enumOUTPUT);
	DIO_enumSetPinConfig(DIO_enumPortA, DIO_enumPin3, DIO_enumOUTPUT);

	/*Set pins 0-3 of port A to logic low */
	DIO_enumSetPin(DIO_enumPortA, DIO_enumPin0, DIO_enumLOGIC_LOW);
	DIO_enumSetPin(DIO_enumPortA, DIO_enumPin1, DIO_enumLOGIC_LOW);
	DIO_enumSetPin(DIO_enumPortA, DIO_enumPin2, DIO_enumLOGIC_LOW);
	DIO_enumSetPin(DIO_enumPortA, DIO_enumPin3, DIO_enumLOGIC_LOW);

	/* Configure pin 7 of port B as an input with internal pull-up resistor */
	DIO_enumSetPinConfig(DIO_enumPortB, DIO_enumPin7, DIO_enumINPUT_PULLDOWN);

	/* Initialize variables */
	u8 Number = 0;
	u8 Button = 0;

	
	while (1)
	{
		// Read the state of pin 4 of port C into the 'Button' variable
		DIO_enumReadState(DIO_enumPortB, DIO_enumPin7, &Button);

		// Check if the button is pressed (low)
		if (Button)
		{
			// Delay for debouncing
			DIO_DelayMs(20);

			// Re-check the button state after the delay
			DIO_enumReadState(DIO_enumPortB, DIO_enumPin7, &Button);

			// Check if the button is still pressed
			if (Button)
			{
				// If 'Number' is already 15, reset it to 0; otherwise, increment it
				if (Number == 15)
				{
					Number = 0;
				}
				else
				{
					Number++;
				}
				/*Rest Pins to zero */
				DIO_enumSetPin(DIO_enumPortA, DIO_enumPin0, DIO_enumLOGIC_LOW);
				DIO_enumSetPin(DIO_enumPortA, DIO_enumPin1, DIO_enumLOGIC_LOW);
				DIO_enumSetPin(DIO_enumPortA, DIO_enumPin2, DIO_enumLOGIC_LOW);
				DIO_enumSetPin(DIO_enumPortA, DIO_enumPin3, DIO_enumLOGIC_LOW);
				// Display the lower nibble of 'Number' on pins 0-3 of port C
				if (Number & (1<<DIO_enumPin0))
				DIO_enumSetPin(DIO_enumPortA, DIO_enumPin0, DIO_enumLOGIC_HIGH);
				else {}
				if (Number & (1<<DIO_enumPin1))
				DIO_enumSetPin(DIO_enumPortA, DIO_enumPin1, DIO_enumLOGIC_HIGH);
				else {}
				if (Number & (1<<DIO_enumPin2))
				DIO_enumSetPin(DIO_enumPortA, DIO_enumPin2, DIO_enumLOGIC_HIGH);
				else {}
				if (Number & (1<<DIO_enumPin3))
				DIO_enumSetPin(DIO_enumPortA, DIO_enumPin3, DIO_enumLOGIC_HIGH);
				else {}

				// Wait until the button is released before proceeding
				while (Button)
				{
					// Re-read the button state
					DIO_enumReadState(DIO_enumPortB, DIO_enumPin7, &Button);
				}
			}
		}
	}
}