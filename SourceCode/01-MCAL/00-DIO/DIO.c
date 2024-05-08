/*
 * Driver  : DIO
 * File    : DIO.c
 * Created: 29-Nov-23 3:14:35 PM
 * Author: Farah
 */ 

#include "DIO.h"
	
/**
 *@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin.
 *@param  : Port Number,Pin Number,Configuration type(Input/Output).
 *@return : Error State                                               
 */	
DIO_enumError_t DIO_enumSetPinConfig(DIO_enumPorts_t Copy_enumPortNum , DIO_enumPins_t Copy_enumPinNum , DIO_enumConfig_t Copy_enumConfig){
	
	DIO_enumError_t DIO_ErrorState= DIO_enumNOK ;			/*Everything Not Ok, initial value */
	
	if(Copy_enumPortNum < DIO_enumPortA || Copy_enumPortNum > DIO_enumPortD)	/*User Entered Invalid PortNum */
	{
		DIO_ErrorState = DIO_enumWrongPort;			/*Selected Port Doesn't Exist As Defined Ports Are A,B,C,D only */
	}
	
	else if (Copy_enumPinNum < DIO_enumPin0 || Copy_enumPinNum > DIO_enumPin7)	/*User Entered Invalid PinNum */
	{
		DIO_ErrorState = DIO_enumWrongPin;		/*Selected Pin Doesn't Exist As Defined Pins Are 0,1,2,3,4,5,6,7 only */
	} 
	
	else if (Copy_enumConfig < DIO_enumOUTPUT || Copy_enumConfig > DIO_enumINPUT_PULLDOWN)	/*User Entered Invalid Configuration Type */
	{
		DIO_ErrorState= DIO_enumWrongConfig;	/*Selected Config Doesn't Exist */
	} 
	
	else{
		switch(Copy_enumPortNum){	/*Switch Cases For Each Port */
		
			case DIO_enumPortA:			/*Each Case has Switch Cases For The Configuration */
				switch(Copy_enumConfig)
				{
					case DIO_enumOUTPUT:
					SET_BIT(DDRA,Copy_enumPinNum);		/*Output--> DDR=1 */
					break;
					
					case DIO_enumINPUT_PULLUP:
					CLR_BIT(DDRA,Copy_enumPinNum);		/* INPUT_PULLUP--> DDR=0 */
					SET_BIT(PORTA,Copy_enumPinNum);		/* INPUT_PULLUP--> PORT=1 */
					break;
					
					case DIO_enumINPUT_PULLDOWN:
					CLR_BIT(DDRA,Copy_enumPinNum);		/* INPUT_PULLDown--> DDR=0 */
					CLR_BIT(PORTA,Copy_enumPinNum);		/* INPUT_PULLDown--> PORT=0 */
					break;
					
					default:
					break;
				}
				break;
				
				
			case DIO_enumPortB:		/*Each Case has Switch Cases For The Configuration */
				switch(Copy_enumConfig)
				{
					case DIO_enumOUTPUT:
					SET_BIT(DDRB,Copy_enumPinNum);		/*Output--> DDR=1 */
					break;
					
					case DIO_enumINPUT_PULLUP:
					CLR_BIT(DDRB,Copy_enumPinNum);		/* INPUT_PULLUP--> DDR=0 */
					SET_BIT(PORTB,Copy_enumPinNum);		/* INPUT_PULLUP--> PORT=1 */
					break;
					
					case DIO_enumINPUT_PULLDOWN:
					CLR_BIT(DDRB,Copy_enumPinNum);		/* INPUT_PULLDown--> DDR=0 */
					CLR_BIT(PORTB,Copy_enumPinNum);		/* INPUT_PULLDown--> PORT=0 */
					break;
					
					default:
					break;
				}
				break;	
						
						
			case DIO_enumPortC:		/*Each Case has Switch Cases For The Configuration */
				switch(Copy_enumConfig)
				{
					case DIO_enumOUTPUT:
					SET_BIT(DDRC,Copy_enumPinNum);		/*Output--> DDR=1 */
					break;
					
					case DIO_enumINPUT_PULLUP:
					CLR_BIT(DDRC,Copy_enumPinNum);		/* INPUT_PULLUP--> DDR=0 */
					SET_BIT(PORTC,Copy_enumPinNum);		/* INPUT_PULLUP--> PORT=1 */
					break;
					
					case DIO_enumINPUT_PULLDOWN:
					CLR_BIT(DDRC,Copy_enumPinNum);		/* INPUT_PULLDown--> DDR=0 */
					CLR_BIT(PORTC,Copy_enumPinNum);		/* INPUT_PULLDown--> PORT=0 */
					break;
					
					default:
					break;
				}
				break;
				
				
			case DIO_enumPortD:		/*Each Case has Switch Cases For The Configuration */
				switch(Copy_enumConfig)
				{
					case DIO_enumOUTPUT:
					SET_BIT(DDRD,Copy_enumPinNum);		/*Output--> DDR=1 */
					break;
					
					case DIO_enumINPUT_PULLUP:
					CLR_BIT(DDRD,Copy_enumPinNum);		/* INPUT_PULLUP--> DDR=0 */
					SET_BIT(PORTD,Copy_enumPinNum);		/* INPUT_PULLUP--> PORT=1 */
					break;
					
					case DIO_enumINPUT_PULLDOWN:
					CLR_BIT(DDRD,Copy_enumPinNum);		/* INPUT_PULLDown--> DDR=0 */
					CLR_BIT(PORTD,Copy_enumPinNum);		/* INPUT_PULLDown--> PORT=0 */
					break;
					
					default:
					break;
				}
				break;		
				
				default:
				break;	
		}
			DIO_ErrorState = DIO_enumOK;
	}	
	return DIO_ErrorState;
}

/**
 *@brief  : Function to Configure the whole Port(8 pins) at one time to be INPUT or OUTPUT port.
 *@param  : Port Number,Configuration type(Input/Output).
 *@return : Error State                                                                      
 */
DIO_enumError_t DIO_enumSetPortConfig(DIO_enumPorts_t Copy_enumPortNum,DIO_enumConfig_t Copy_enumConfig){
	
	DIO_enumError_t DIO_ErrorState= DIO_enumNOK ;	/*Everything Not Ok, initial value */
	
	if(Copy_enumPortNum < DIO_enumPortA || Copy_enumPortNum > DIO_enumPortD)	/*User Entered Invalid PortNum */
	{
		DIO_ErrorState = DIO_enumWrongPort;			/*Selected Port Doesn't Exist As Defined Ports Are A,B,C,D only */
	}
	
	else if (Copy_enumConfig < DIO_enumOUTPUT || Copy_enumConfig > DIO_enumINPUT_PULLDOWN)	/*User Entered Invalid Configuration Type */
	{
		DIO_ErrorState= DIO_enumWrongConfig;	/*Selected Config Doesn't Exist */
	}
	else{
		switch(Copy_enumPortNum){	/*Switch Cases For Each Port */
			
			case DIO_enumPortA:		/*Each Case has Switch Cases For The Configuration */
			switch(Copy_enumConfig)
			{
				case DIO_enumOUTPUT:
				ASSIGN_REG(DDRA,0xFF);		/*Output--> DDR=1 */
				break;
				
				case DIO_enumINPUT_PULLUP:
				ASSIGN_REG(DDRA,0x00);		/* INPUT_PULLUP--> DDR=0 */
				ASSIGN_REG(PORTA,0xFF);		/* INPUT_PULLUP--> PORT=1 */
				break;
				
				case DIO_enumINPUT_PULLDOWN:
				ASSIGN_REG(DDRA,0x00);		/* INPUT_PULLDown--> DDR=0 */
				ASSIGN_REG(PORTA,0x00);		/* INPUT_PULLDown--> PORT=0 */
				break;
				
				default:
				break;
			}
			break;
			
			case DIO_enumPortB:		/*Each Case has Switch Cases For The Configuration */
			switch(Copy_enumConfig)
			{
				case DIO_enumOUTPUT:
				ASSIGN_REG(DDRB,0xFF);		/*Output--> DDR=1 */
				break;
				
				case DIO_enumINPUT_PULLUP:
				ASSIGN_REG(DDRB,0x00);		/* INPUT_PULLUP--> DDR=0 */
				ASSIGN_REG(PORTB,0xFF);		/* INPUT_PULLUP--> PORT=1 */
				break;
				
				case DIO_enumINPUT_PULLDOWN:
				ASSIGN_REG(DDRB,0x00);		/* INPUT_PULLDown--> DDR=0 */
				ASSIGN_REG(PORTB,0x00);		/* INPUT_PULLDown--> PORT=0 */
				break;
				
				default:
				break;
			}
			break;
			
			case DIO_enumPortC:		/*Each Case has Switch Cases For The Configuration */
			switch(Copy_enumConfig)
			{
				case DIO_enumOUTPUT:
				ASSIGN_REG(DDRC,0xFF);		/*Output--> DDR=1 */
				break;
				
				case DIO_enumINPUT_PULLUP:
				ASSIGN_REG(DDRC,0x00);		/* INPUT_PULLUP--> DDR=0 */
				ASSIGN_REG(PORTC,0xFF);		/* INPUT_PULLUP--> PORT=1 */
				break;
				
				case DIO_enumINPUT_PULLDOWN:
				ASSIGN_REG(DDRC,0x00);		/* INPUT_PULLDown--> DDR=0 */
				ASSIGN_REG(PORTC,0x00);		/* INPUT_PULLDown--> PORT=0 */
				break;
				
				default:
				break;
			}
			break;
			
			case DIO_enumPortD:		/*Each Case has Switch Cases For The Configuration */
			switch(Copy_enumConfig)
			{
				case DIO_enumOUTPUT:
				ASSIGN_REG(DDRD,0xFF);		/*Output--> DDR=1 */
				break;
				
				case DIO_enumINPUT_PULLUP:
				ASSIGN_REG(DDRD,0x00);		/* INPUT_PULLUP--> DDR=0 */
				ASSIGN_REG(PORTD,0xFF);		/* INPUT_PULLUP--> PORT=1 */
				break;
				
				case DIO_enumINPUT_PULLDOWN:
				ASSIGN_REG(DDRD,0x00);		/* INPUT_PULLDown--> DDR=0 */
				ASSIGN_REG(PORTD,0x00);		/* INPUT_PULLDown--> PORT=0 */
				break;
				
				default:
				break;
			}
			break;
			
			default:
			break;
		}
		DIO_ErrorState = DIO_enumOK;
	}
	return DIO_ErrorState;
}

/**
 *@brief  : Function to Set the Pins to be Logic HIGH  or Logic LOW.
 *@param  : Port Number,Pin Number,Logic State(HIGH/LOW).
 *@return : Error State                                                                      
 */	
DIO_enumError_t DIO_enumSetPin(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t DIO_ErrorState= DIO_enumNOK ;	/*Everything Not Ok, initial value */
	
	if(Copy_enumPortNum < DIO_enumPortA || Copy_enumPortNum > DIO_enumPortD)	/*User Entered Invalid PortNum */
	{
		DIO_ErrorState = DIO_enumWrongPort;			/*Selected Port Doesn't Exist As Defined Ports Are A,B,C,D only */
	}

	else if (Copy_enumPinNum < DIO_enumPin0 || Copy_enumPinNum > DIO_enumPin7)	/*User Entered Invalid PinNum */
	{
	DIO_ErrorState = DIO_enumWrongPin;		/*Selected Pin Doesn't Exist As Defined Pins Are 0,1,2,3,4,5,6,7 only */
	}
	
	else if (Copy_enumLogicState < DIO_enumLOGIC_LOW || Copy_enumLogicState > DIO_enumLOGIC_HIGH )	/*User Entered Invalid LogicState */
	{
		DIO_ErrorState= DIO_enumWrongLogicState;	/*Selected LogicState Doesn't Exist */
	}
	
	else
	{
		
		switch(Copy_enumPortNum){	/*Switch Cases For Each Port */
			
			case DIO_enumPortA:			/*Each Case has Switch Cases For The Logic State */
			switch(Copy_enumLogicState)
			{
				case DIO_enumLOGIC_LOW:
				CLR_BIT(PORTA,Copy_enumPinNum);		/*Write On PORT Register LOW LogicState */
				break;
				
				case DIO_enumLOGIC_HIGH:
				SET_BIT(PORTA,Copy_enumPinNum);		/*Write On PORT Register HIGH LogicState */
				break;
				
				default:
				break;
			}
			break;
			
			case DIO_enumPortB:			/*Each Case has Switch Cases For The Logic State */
			switch(Copy_enumLogicState)
			{
				case DIO_enumLOGIC_LOW:
				CLR_BIT(PORTB,Copy_enumPinNum);		/*Write On PORT Register LOW LogicState */
				break;
				
				case DIO_enumLOGIC_HIGH:
				SET_BIT(PORTB,Copy_enumPinNum);		/*Write On PORT Register HIGH LogicState */
				break;
				
				default:
				break;
			}
			break;
			
			case DIO_enumPortC:			/*Each Case has Switch Cases For The Logic State */
			switch(Copy_enumLogicState)
			{
				case DIO_enumLOGIC_LOW:
				CLR_BIT(PORTC,Copy_enumPinNum);		/*Write On PORT Register LOW LogicState */
				break;
				
				case DIO_enumLOGIC_HIGH:
				SET_BIT(PORTC,Copy_enumPinNum);		/*Write On PORT Register HIGH LogicState */
				break;
				
				default:
				break;
			}
			break;
			
			case DIO_enumPortD:			/*Each Case has Switch Cases For The Logic State */
			switch(Copy_enumLogicState)
			{
				case DIO_enumLOGIC_LOW:
				CLR_BIT(PORTD,Copy_enumPinNum);		/*Write On PORT Register LOW LogicState */
				break;
				
				case DIO_enumLOGIC_HIGH:
				SET_BIT(PORTD,Copy_enumPinNum);		/*Write On PORT Register HIGH LogicState */
				break;
				
				default:
				break;
			}
			break;
			
			default:
			break;	
		}
		DIO_ErrorState= DIO_enumOK;
	}
	
	return DIO_ErrorState;
}

/**
 *@brief : Function to Set the whole Port(8 pins) at one time to be Logic HIGH  or Logic LOW.
 *@param : Port Number,Logic State(HIGH/LOW).
 *@return: Error State.                                                                      
 */
DIO_enumError_t DIO_enumSetPort(DIO_enumPorts_t Copy_enumPortNum,DIO_enumLogicState_t Copy_enumLogicState)
{
	DIO_enumError_t DIO_ErrorState= DIO_enumNOK ;	/*Everything Not Ok, initial value */
	
	if(Copy_enumPortNum < DIO_enumPortA || Copy_enumPortNum > DIO_enumPortD)	/*User Entered Invalid PortNum */
	{
		DIO_ErrorState = DIO_enumWrongPort;			/*Selected Port Doesn't Exist As Defined Ports Are A,B,C,D only */
	}
	
	else if (Copy_enumLogicState < DIO_enumLOGIC_LOW || Copy_enumLogicState > DIO_enumLOGIC_HIGH )	/*User Entered Invalid LogicState */
	{
		DIO_ErrorState= DIO_enumWrongLogicState;	/*Selected LogicState Doesn't Exist */
	}
	else{
		switch(Copy_enumPortNum){	/*Switch Cases For Each Port */
			
			case DIO_enumPortA:			/*Each Case has Switch Cases For The Logic State */
			switch(Copy_enumLogicState)
			{
				case DIO_enumLOGIC_LOW:
				ASSIGN_REG(PORTA,0x00);			/*Write On PORT Register LOW LogicState */
				break;
				
				case DIO_enumLOGIC_HIGH:
				ASSIGN_REG(PORTA,0xFF);			/*Write On PORT Register HIGH LogicState */
				break;
				
				default:
				break;
			}
			break;
			
			case DIO_enumPortB:			/*Each Case has Switch Cases For The Logic State */
			switch(Copy_enumLogicState)
			{
				case DIO_enumLOGIC_LOW:
				ASSIGN_REG(PORTB,0x00);			/*Write On PORT Register LOW LogicState */
				break;
				
				case DIO_enumLOGIC_HIGH:
				ASSIGN_REG(PORTB,0xFF);			/*Write On PORT Register HIGH LogicState */
				break;
				
				default:
				break;
			}
			break;
			
			case DIO_enumPortC:			/*Each Case has Switch Cases For The Logic State */
			switch(Copy_enumLogicState)
			{
				case DIO_enumLOGIC_LOW:
				ASSIGN_REG(PORTC,0x00);			/*Write On PORT Register LOW LogicState */
				break;
				
				case DIO_enumLOGIC_HIGH:
				ASSIGN_REG(PORTC,0xFF);			/*Write On PORT Register HIGH LogicState */
				break;
				
				default:
				break;
			}
			break;
			
			case DIO_enumPortD:			/*Each Case has Switch Cases For The Logic State */
			switch(Copy_enumLogicState)
			{
				case DIO_enumLOGIC_LOW:
				ASSIGN_REG(PORTD,0x00);			/*Write On PORT Register LOW LogicState */
				break;
				
				case DIO_enumLOGIC_HIGH:
				ASSIGN_REG(PORTD,0xFF);			/*Write On PORT Register HIGH LogicState */
				break;
				
				default:
				break;
			}
			break;
			
			default:
			break;
		}
		DIO_ErrorState = DIO_enumOK;
	}
	
	return DIO_ErrorState;
} 

DIO_enumError_t DIO_enumSetPortValue(DIO_enumPorts_t Copy_enumPortNum,u8 Copy_u8Value)
{
	DIO_enumError_t  Ret_enumErrorStatus= DIO_enumNOK;
	
	if(Copy_enumPortNum < DIO_enumPortA || Copy_enumPortNum > DIO_enumPortD) //The user entered an invalid pin
	{
		Ret_enumErrorStatus = DIO_enumWrongPort;
	}
	else if(Copy_u8Value > 0xFF || Copy_u8Value < 0x00) //1111 1111 or 0000 0000
	{
		Ret_enumErrorStatus= DIO_enumWrongValue;
	}
	else
	{
		switch(Copy_enumPortNum) //Switch cases for the port number
		{
			case DIO_enumPortA:
			ASSIGN_REG(PORTA,Copy_u8Value);
			break;
			
			case DIO_enumPortB:
			ASSIGN_REG(PORTB,Copy_u8Value);
			break;
			
			case DIO_enumPortC:
			ASSIGN_REG(PORTC,Copy_u8Value);
			break;
			
			case DIO_enumPortD:
			ASSIGN_REG(PORTD,Copy_u8Value);
			break;
			
			default:
			break;
		}
		
		Ret_enumErrorStatus= DIO_enumOK;
	}
	return Ret_enumErrorStatus;
}


/**
 *@brief  : Function to Read the Logic State of the Pin (Is it HIGH or LOW).
 *@param  : Port Number,Pin Number, Pointer points to unsigned char passed by address (to return the value of pin state).
 *@return : Error State                                                                     
 */
DIO_enumError_t DIO_enumReadState(DIO_enumPorts_t Copy_enumPortNum,DIO_enumPins_t Copy_enumPinNum,DIO_enumLogicState_t* Add_Pu8PinValue)
{
	DIO_enumError_t DIO_ErrorState= DIO_enumNOK ;	/*Everything Not Ok, initial value */
	
	if(Copy_enumPortNum < DIO_enumPortA || Copy_enumPortNum > DIO_enumPortD)	/*User Entered Invalid PortNum */
	{
		DIO_ErrorState = DIO_enumWrongPort;			/*Selected Port Doesn't Exist As Defined Ports Are A,B,C,D only */
	}
	
	else if (Copy_enumPinNum < DIO_enumPin0 || Copy_enumPinNum > DIO_enumPin7)	/*User Entered Invalid PinNum */
	{
		DIO_ErrorState = DIO_enumWrongPin;		/*Selected Pin Doesn't Exist As Defined Pins Are 0,1,2,3,4,5,6,7 only */
	}
	
	else if (Add_Pu8PinValue == NULL )		/* Doesn't have Address*/
	{
		DIO_ErrorState= DIO_enumNullPointer;	/*Null Pointer */
	}
	else
	{
		switch(Copy_enumPortNum){	/*Switch Cases For Each Port */
			
			case DIO_enumPortA:				/*Each Case has Switch Cases For The Logic State */
			
			*Add_Pu8PinValue = GET_BIT(PINA,Copy_enumPinNum);	/*Read From PIN Register*/
			break;
			
			case DIO_enumPortB:			/*Each Case has Switch Cases For The Logic State */
			*Add_Pu8PinValue = GET_BIT(PINB,Copy_enumPinNum);	/*Read From PIN Register*/
			break ;
			
			case DIO_enumPortC:				/*Each Case has Switch Cases For The Logic State */
			*Add_Pu8PinValue = GET_BIT(PINC,Copy_enumPinNum);	/*Read From PIN Register*/
			break;
			
			case DIO_enumPortD:				/*Each Case has Switch Cases For The Logic State */
			*Add_Pu8PinValue = GET_BIT(PIND,Copy_enumPinNum);	/*Read From PIN Register*/
			break;
			
			default:
			break;
		}
	}
	return DIO_ErrorState;
}



void DIO_DelayMs(u32 Copy_u32TimeMs){
	
	for (int i =0 ; i<(50*Copy_u32TimeMs) ; i++)	/*50 for the nop instruction*/
	{
		
		asm volatile("nop");						/*Do Nothing*/
	}
	
}



