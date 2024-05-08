/*
 ============================================================================
 Name        : Seven_SEG.c
 Author      : Farah Mohey
 Description : Source file for Seven Segment Driver
 Created	 : 04-Jan-24	
 ============================================================================
 */

#include "Seven_SEG_cfg.h"
#include "Seven_SEG.h"

/* Extern for global configuration Array*/
extern Seven_SEG_strCfg Seven_SEG[NUM_OF_SevenSEG];


/*
 *@brief  : Function to Configure the Pins of SevenSegment.
 *@param  :Void.
 *@return : Error State                                               
 */	
Seven_SEG_enumErrorStatus_t Seven_SEG_enumInit (void){
	/* Declare variables to store DIO error states and SevenSegment error states */
	DIO_enumError_t Loc_enumReturnDIOErrorState = DIO_enumOK;
	Seven_SEG_enumErrorStatus_t ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK; 
		
	/* Declare variable to store the number of SevenSegments */
	u8 Loc_U8SevenSegmentNum = 0 ;
	/* Declare variables to store current LED in Seven Segment */
	Seven_SEG_enumLedID_t Loc_u8LedID ;
		
	/*Declare counter to Loop on Each LED in Each SevenSegment*/
	u8 Loc_u8Counter_init = 0;
		
	/* Declare local variable to store Active Status ,will be used in SevenSegment Configuration */
	u8 Loc_u8SevenSegmentActiveStatus = 0 ;
		
		
	/*Check on number of SevenSegments if exceeding total number of pins existing in controller */
	if( (NUM_OF_SevenSEG * NUM_OF_PINS_PER_SevenSEG) <= TOTAL_NUM_OF_PINS_PER_SYSTEM)
	{
		/*For loop to initialize each LED in SevenSegment */
		for (Loc_u8Counter_init = 0; ((Loc_u8Counter_init < NUM_OF_SevenSEG * NUM_OF_PINS_PER_SevenSEG) && (ReturnError_enumSevenSegErrorState == Seven_SEG_enumOK)); Loc_u8Counter_init++)
		{
			
			/*Divide --> To detect which SevenSegment I work on now */
			Loc_U8SevenSegmentNum = (u8)(Loc_u8Counter_init / NUM_OF_PINS_PER_SevenSEG) ; /*Casting --> cause #define NUM_OF_PINS_PER_SevenSEG */
			/*Modulus --> To detect which LED in the SevenSegment I work on now */
			Loc_u8LedID = (u8)(Loc_u8Counter_init % NUM_OF_PINS_PER_SevenSEG) ;  		  /*Casting --> cause #define NUM_OF_PINS_PER_SevenSEG */


			/* Check the ActiveState of the Seven Segment (Common Cathode or Common Anode) */
			/*Common Cathode case*/
			if (Seven_SEG[Loc_U8SevenSegmentNum].Seven_SEG_ActiveStatus == Seven_SEG_enumCommonCathode)
			{
				ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK; /*Set 7SEG error With OK */
				 
				/*Initialize Common Cathode Led by 0 at first , then will be = 1*/
				Loc_u8SevenSegmentActiveStatus = DIO_enumLOGIC_LOW;
			}
			
			/*Common Anode case*/
			else if (Seven_SEG[Loc_U8SevenSegmentNum].Seven_SEG_ActiveStatus == Seven_SEG_enumCommonAnode)
			{
				ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK; /*Set 7SEG error With OK */
				
				/*Initialize Common Anode Led by 1 at first , then will be = 0*/
				Loc_u8SevenSegmentActiveStatus = DIO_enumLOGIC_HIGH;
			}
			
			/*Invalid option other than Defined Active State Cases  (Common Cathode or Common Anode) */
			else
			{
				/* Return error status with wrong Active State not equal Common Cathode or Common Anode */
				ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongActiveState;
			}
			
			/*Check if Seven Segment error state is OK */
			if(ReturnError_enumSevenSegErrorState == Seven_SEG_enumOK)
			{
				/*Switch on LED ID to set the configuration for each LED in each Seven Segment */
				switch (Loc_u8LedID)
				{
					case Seven_SEG_enumLedA:	/* Setting Configuration of LED A */
					Loc_enumReturnDIOErrorState = DIO_enumSetPinConfig(Seven_SEG[Loc_U8SevenSegmentNum].LedA_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedA_Pin , DIO_enumOUTPUT);
					
					/*Handling errors if DIO SetPinConfig is not OK , For Validation */
					if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)		/*Invalid Pin Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongConfig)	/*Invalid Configuration for this LED (NOT OUTPUT)*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongConfig ;
					}
					
					else
					{	
						/* Setting Seven Segment Error State with OK after checking on DIO SetPinConfig is OK & DIO Error State is OK */
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;	
						
						/*Calling Set DIO SetPin And Passing (Loc_u8SevenSegmentActiveStatus) Depending on Active State if Common Cathode or Common Anode 0 or 1 */ 	
						Loc_enumReturnDIOErrorState = DIO_enumSetPin( Seven_SEG[Loc_U8SevenSegmentNum].LedA_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedA_Pin , Loc_u8SevenSegmentActiveStatus);
						
						/*Handling errors if DIO SetPin is not OK , For Validation */
						if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)	/*Invalid Pin Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongLogicState )		/*Invalid ActiveStatus for this LED (NOT logic High or Low)*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongActiveState ;	/*Invalid ActiveStatus for this LED (NOT Common Cathode OR Common Anode)*/
						}
						
						else
						{
							/* Setting Seven Segment Error State with OK after checking on DIO SetPin is OK & DIO Error State is OK */
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;
						}
					
					}	
					break; 
					
					case Seven_SEG_enumLedB:	/* Setting Configuration of LED B */
					Loc_enumReturnDIOErrorState = DIO_enumSetPinConfig(Seven_SEG[Loc_U8SevenSegmentNum].LedB_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedB_Pin , DIO_enumOUTPUT);
					
					/*Handling errors if DIO SetPinConfig is not OK , For Validation */
					if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)		/*Invalid Pin Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongConfig)	/*Invalid Configuration for this LED (NOT OUTPUT)*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongConfig ;
					}
					
					else
					{	
						/* Setting Seven Segment Error State with OK after checking on DIO SetPinConfig is OK & DIO Error State is OK */
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;	
						
						/*Calling Set DIO SetPin And Passing (Loc_u8SevenSegmentActiveStatus) Depending on Active State if Common Cathode or Common Anode 0 or 1 */ 	
						Loc_enumReturnDIOErrorState = DIO_enumSetPin( Seven_SEG[Loc_U8SevenSegmentNum].LedB_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedB_Pin , Loc_u8SevenSegmentActiveStatus);
						
						/*Handling errors if DIO SetPin is not OK , For Validation */
						if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)	/*Invalid Pin Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongLogicState )		/*Invalid ActiveStatus for this LED (NOT logic High or Low)*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongActiveState ;	/*Invalid ActiveStatus for this LED (NOT Common Cathode OR Common Anode)*/
						}
						
						else
						{
							/* Setting Seven Segment Error State with OK after checking on DIO SetPin is OK & DIO Error State is OK */
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;
						}
					
					}	
					break; 
					
					case Seven_SEG_enumLedC:	/* Setting Configuration of LED C*/
					Loc_enumReturnDIOErrorState = DIO_enumSetPinConfig(Seven_SEG[Loc_U8SevenSegmentNum].LedC_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedC_Pin , DIO_enumOUTPUT);
					
					/*Handling errors if DIO SetPinConfig is not OK , For Validation */
					if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)		/*Invalid Pin Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongConfig)	/*Invalid Configuration for this LED (NOT OUTPUT)*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongConfig ;
					}
					
					else
					{
						/* Setting Seven Segment Error State with OK after checking on DIO SetPinConfig is OK & DIO Error State is OK */
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;
						
						/*Calling Set DIO SetPin And Passing (Loc_u8SevenSegmentActiveStatus) Depending on Active State if Common Cathode or Common Anode 0 or 1 */
						Loc_enumReturnDIOErrorState = DIO_enumSetPin( Seven_SEG[Loc_U8SevenSegmentNum].LedC_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedC_Pin , Loc_u8SevenSegmentActiveStatus);
						
						/*Handling errors if DIO SetPin is not OK , For Validation */
						if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)	/*Invalid Pin Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongLogicState )		/*Invalid ActiveStatus for this LED (NOT logic High or Low)*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongActiveState ;	/*Invalid ActiveStatus for this LED (NOT Common Cathode OR Common Anode)*/
						}
						
						else
						{
							/* Setting Seven Segment Error State with OK after checking on DIO SetPin is OK & DIO Error State is OK */
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;
						}
						
					}
					break; 	
					
								
					case Seven_SEG_enumLedD:	/* Setting Configuration of LED D*/
					Loc_enumReturnDIOErrorState = DIO_enumSetPinConfig(Seven_SEG[Loc_U8SevenSegmentNum].LedD_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedD_Pin , DIO_enumOUTPUT);
					
					/*Handling errors if DIO SetPinConfig is not OK , For Validation */
					if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)		/*Invalid Pin Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongConfig)	/*Invalid Configuration for this LED (NOT OUTPUT)*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongConfig ;
					}
					
					else
					{
						/* Setting Seven Segment Error State with OK after checking on DIO SetPinConfig is OK & DIO Error State is OK */
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;
						
						/*Calling Set DIO SetPin And Passing (Loc_u8SevenSegmentActiveStatus) Depending on Active State if Common Cathode or Common Anode 0 or 1 */
						Loc_enumReturnDIOErrorState = DIO_enumSetPin( Seven_SEG[Loc_U8SevenSegmentNum].LedD_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedD_Pin , Loc_u8SevenSegmentActiveStatus);
						
						/*Handling errors if DIO SetPin is not OK , For Validation */
						if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)	/*Invalid Pin Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongLogicState )		/*Invalid ActiveStatus for this LED (NOT logic High or Low)*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongActiveState ;	/*Invalid ActiveStatus for this LED (NOT Common Cathode OR Common Anode)*/
						}
						
						else
						{
							/* Setting Seven Segment Error State with OK after checking on DIO SetPin is OK & DIO Error State is OK */
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;
						}
						
					}
					break; 				
									
					case Seven_SEG_enumLedE:	/* Setting Configuration of LED E*/
					Loc_enumReturnDIOErrorState = DIO_enumSetPinConfig(Seven_SEG[Loc_U8SevenSegmentNum].LedE_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedE_Pin , DIO_enumOUTPUT);
					
					/*Handling errors if DIO SetPinConfig is not OK , For Validation */
					if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)		/*Invalid Pin Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongConfig)	/*Invalid Configuration for this LED (NOT OUTPUT)*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongConfig ;
					}
					
					else
					{
						/* Setting Seven Segment Error State with OK after checking on DIO SetPinConfig is OK & DIO Error State is OK */
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;
						
						/*Calling Set DIO SetPin And Passing (Loc_u8SevenSegmentActiveStatus) Depending on Active State if Common Cathode or Common Anode 0 or 1 */
						Loc_enumReturnDIOErrorState = DIO_enumSetPin( Seven_SEG[Loc_U8SevenSegmentNum].LedE_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedE_Pin , Loc_u8SevenSegmentActiveStatus);
						
						/*Handling errors if DIO SetPin is not OK , For Validation */
						if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)	/*Invalid Pin Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongLogicState )		/*Invalid ActiveStatus for this LED (NOT logic High or Low)*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongActiveState ;	/*Invalid ActiveStatus for this LED (NOT Common Cathode OR Common Anode)*/
						}
						
						else
						{
							/* Setting Seven Segment Error State with OK after checking on DIO SetPin is OK & DIO Error State is OK */
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;
						}
						
					}
					break; 
					
					case Seven_SEG_enumLedF:	/* Setting Configuration of LED F*/
					Loc_enumReturnDIOErrorState = DIO_enumSetPinConfig(Seven_SEG[Loc_U8SevenSegmentNum].LedF_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedF_Pin , DIO_enumOUTPUT);
					
					/*Handling errors if DIO SetPinConfig is not OK , For Validation */
					if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)		/*Invalid Pin Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongConfig)	/*Invalid Configuration for this LED (NOT OUTPUT)*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongConfig ;
					}
					
					else
					{
						/* Setting Seven Segment Error State with OK after checking on DIO SetPinConfig is OK & DIO Error State is OK */
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;
						
						/*Calling Set DIO SetPin And Passing (Loc_u8SevenSegmentActiveStatus) Depending on Active State if Common Cathode or Common Anode 0 or 1 */
						Loc_enumReturnDIOErrorState = DIO_enumSetPin( Seven_SEG[Loc_U8SevenSegmentNum].LedF_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedF_Pin , Loc_u8SevenSegmentActiveStatus);
						
						/*Handling errors if DIO SetPin is not OK , For Validation */
						if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)	/*Invalid Pin Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongLogicState )		/*Invalid ActiveStatus for this LED (NOT logic High or Low)*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongActiveState ;	/*Invalid ActiveStatus for this LED (NOT Common Cathode OR Common Anode)*/
						}
						
						else
						{
							/* Setting Seven Segment Error State with OK after checking on DIO SetPin is OK & DIO Error State is OK */
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;
						}
						
					}
					break; 	
					
					case Seven_SEG_enumLedG:	/* Setting Configuration of LED G*/
					Loc_enumReturnDIOErrorState = DIO_enumSetPinConfig(Seven_SEG[Loc_U8SevenSegmentNum].LedG_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedG_Pin , DIO_enumOUTPUT);
					
					/*Handling errors if DIO SetPinConfig is not OK , For Validation */
					if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)		/*Invalid Pin Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongConfig)	/*Invalid Configuration for this LED (NOT OUTPUT)*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongConfig ;
					}
					
					else
					{
						/* Setting Seven Segment Error State with OK after checking on DIO SetPinConfig is OK & DIO Error State is OK */
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;
						
						/*Calling Set DIO SetPin And Passing (Loc_u8SevenSegmentActiveStatus) Depending on Active State if Common Cathode or Common Anode 0 or 1 */
						Loc_enumReturnDIOErrorState = DIO_enumSetPin( Seven_SEG[Loc_U8SevenSegmentNum].LedG_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedG_Pin , Loc_u8SevenSegmentActiveStatus);
						
						/*Handling errors if DIO SetPin is not OK , For Validation */
						if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)	/*Invalid Pin Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongLogicState )		/*Invalid ActiveStatus for this LED (NOT logic High or Low)*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongActiveState ;	/*Invalid ActiveStatus for this LED (NOT Common Cathode OR Common Anode)*/
						}
						
						else
						{
							/* Setting Seven Segment Error State with OK after checking on DIO SetPin is OK & DIO Error State is OK */
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;
						}
						
					}
					break; 		
					
					case Seven_SEG_enumLedDP:	/* Setting Configuration of LED DP*/
					Loc_enumReturnDIOErrorState = DIO_enumSetPinConfig(Seven_SEG[Loc_U8SevenSegmentNum].LedDP_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedDP_Pin , DIO_enumOUTPUT);
					
					/*Handling errors if DIO SetPinConfig is not OK , For Validation */
					if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)		/*Invalid Pin Number for this LED*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
					}
					
					else if (Loc_enumReturnDIOErrorState == DIO_enumWrongConfig)	/*Invalid Configuration for this LED (NOT OUTPUT)*/
					{
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongConfig ;
					}
					
					else
					{
						/* Setting Seven Segment Error State with OK after checking on DIO SetPinConfig is OK & DIO Error State is OK */
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;
						
						/*Calling Set DIO SetPin And Passing (Loc_u8SevenSegmentActiveStatus) Depending on Active State if Common Cathode or Common Anode 0 or 1 */
						Loc_enumReturnDIOErrorState = DIO_enumSetPin( Seven_SEG[Loc_U8SevenSegmentNum].LedDP_Port , Seven_SEG[Loc_U8SevenSegmentNum].LedDP_Pin , Loc_u8SevenSegmentActiveStatus);
						
						/*Handling errors if DIO SetPin is not OK , For Validation */
						if (Loc_enumReturnDIOErrorState == DIO_enumWrongPort)		/*Invalid Port Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPort ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongPin)	/*Invalid Pin Number for this LED*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongPin ;
						}
						
						else if (Loc_enumReturnDIOErrorState == DIO_enumWrongLogicState )		/*Invalid ActiveStatus for this LED (NOT logic High or Low)*/
						{
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongActiveState ;	/*Invalid ActiveStatus for this LED (NOT Common Cathode OR Common Anode)*/
						}
						
						else
						{
							/* Setting Seven Segment Error State with OK after checking on DIO SetPin is OK & DIO Error State is OK */
							ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK ;
						}
						
					}
					break; 		
					
					default:
						/* Wrong Led ID is passed other than LED A,B,C,D,E,F,G, DP */
						ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongLedID;
					break;																		
	
				}
				
			}
			
			else  
			{
				/* Seven Segment is NOT OK */
				ReturnError_enumSevenSegErrorState = Seven_SEG_enumNOK ; 
			}
			
		}
	}
	
	else
	{
		/*Selected Value Exceeding number of pins in the Controller */
		ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongNumOfSevenSEG ; 	
	}
	return ReturnError_enumSevenSegErrorState ; 
}


/*
 *@brief  : Function to set value of specific SevenSegment
 *@param  : SevenSegment number , Value of Output of this SevenSegment
 *@return : Error State                                                                      
 */
Seven_SEG_enumErrorStatus_t Seven_SEG_enumSetValue(u8 Copy_u8Seven_SEGNum, Seven_SEG_enum_NumbersDisplayed_Sev_SEG_t Copy_u8Seven_SEGValue)
{
	/* Declare variable to store SevenSegment error states */
	Seven_SEG_enumErrorStatus_t ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK;
	
	/* Declare local variable to store Active Status ,will be used in SevenSegment Configuration */
	u8 Loc_u8SevenSegmentActiveStatus = 0 ;
	
	/*Check if provided Seven Segment is within Defined range or not */
	if (Copy_u8Seven_SEGNum > NUM_OF_SevenSEG)
	{
		/*Wrong Seven Segment not existing out of range */
		ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongSevenSEG ;
	}
	
	/* Check if the provided value is within the valid range (0-9) */
	else if ( (Copy_u8Seven_SEGValue < Seven_SEG_enumNumberZero ) || (Copy_u8Seven_SEGValue > Seven_SEG_enumNumberNine) )
	{
		/*Wrong Value not existing out of the valid range (0-9) */
		ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongValue ;
	}
	
	else	/* Check the ActiveState of the Seven Segment (Common Cathode or Common Anode) */
	{
		/*Common Cathode case*/
		if (Seven_SEG[Copy_u8Seven_SEGNum].Seven_SEG_ActiveStatus == Seven_SEG_enumCommonCathode)
		{
			ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK; /*Set 7SEG error With OK */
			
		/*Set a value in Loc_u8SevenSegmentActiveStatus Of 7 Segment to Illuminate LEDS in Common Cathode = 1*/
			Loc_u8SevenSegmentActiveStatus = DIO_enumLOGIC_HIGH;
		}
		
		/*Common Anode case*/
		else if (Seven_SEG[Copy_u8Seven_SEGNum].Seven_SEG_ActiveStatus == Seven_SEG_enumCommonAnode)
		{
			ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK; /*Set 7SEG error With OK */
			
			/*Set a value in Loc_u8SevenSegmentActiveStatus Of 7 Segment to Illuminate LEDS in Common Anode = 0*/
			Loc_u8SevenSegmentActiveStatus = DIO_enumLOGIC_LOW;
		}
		
		else	/*Invalid option other than Defined Active State Cases (Common Cathode or Common Anode) */
		{
			/* Return error status with wrong Active State not equal Common Cathode or Common Anode */
			ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongActiveState;
		}
		
		/*Check if Seven Segment error state is OK */
		if(ReturnError_enumSevenSegErrorState == Seven_SEG_enumOK)
		{
			/*Switch on Values set each LED in the desired Seven Segment */
			switch (Copy_u8Seven_SEGValue)
			{
				/* Number 0 */
				case Seven_SEG_enumNumberZero:
					DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedA_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedA_Pin , Loc_u8SevenSegmentActiveStatus);
					DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedB_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedB_Pin , Loc_u8SevenSegmentActiveStatus);
					DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedC_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedC_Pin , Loc_u8SevenSegmentActiveStatus);
					DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedD_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedD_Pin , Loc_u8SevenSegmentActiveStatus);
					DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedE_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedE_Pin , Loc_u8SevenSegmentActiveStatus);
					DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedF_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedF_Pin , Loc_u8SevenSegmentActiveStatus);
					DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedG_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedG_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED G OFF */
					DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Port, Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Pin, !Loc_u8SevenSegmentActiveStatus);	/*LED DP OFF */

				break ;  
				
				
				/* Number 1 */
				case Seven_SEG_enumNumberOne:
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedA_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedA_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED A OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedB_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedB_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedC_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedC_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedD_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedD_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED D OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedE_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedE_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED E OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedF_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedF_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED F OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedG_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedG_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED G OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Port, Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Pin, !Loc_u8SevenSegmentActiveStatus);	/*LED DP OFF */

				break ;  
				
				/* Number 2 */
				case Seven_SEG_enumNumberTwo:
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedA_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedA_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedB_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedB_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedC_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedC_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED C OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedD_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedD_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedE_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedE_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedF_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedF_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED F OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedG_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedG_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Port, Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Pin, !Loc_u8SevenSegmentActiveStatus);	/*LED DP OFF */

				break ;  
				
				/* Number 3 */
				case Seven_SEG_enumNumberThree:
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedA_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedA_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedB_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedB_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedC_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedC_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedD_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedD_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedE_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedE_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED E OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedF_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedF_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED F OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedG_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedG_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Port, Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Pin, !Loc_u8SevenSegmentActiveStatus);	/*LED DP OFF */

				break ; 
				
				/* Number 4 */
				case Seven_SEG_enumNumberFour:
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedA_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedA_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED A OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedB_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedB_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedC_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedC_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedD_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedD_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED D OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedE_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedE_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED E OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedF_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedF_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedG_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedG_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Port, Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Pin, !Loc_u8SevenSegmentActiveStatus);	/*LED DP OFF */

				break ;  
				
				/* Number 5 */
				case Seven_SEG_enumNumberFive:
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedA_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedA_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedB_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedB_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED B OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedC_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedC_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedD_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedD_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedE_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedE_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED E OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedF_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedF_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedG_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedG_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Port, Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Pin, !Loc_u8SevenSegmentActiveStatus);	/*LED DP OFF */

				break ;  
				
				/* Number 6 */
				case Seven_SEG_enumNumberSix:
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedA_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedA_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedB_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedB_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED B OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedC_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedC_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedD_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedD_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedE_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedE_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedF_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedF_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedG_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedG_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Port, Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Pin, !Loc_u8SevenSegmentActiveStatus);	/*LED DP OFF */

				break ; 
				
				/* Number 7 */
				case Seven_SEG_enumNumberSeven:
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedA_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedA_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedB_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedB_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedC_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedC_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedD_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedD_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED D OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedE_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedE_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED E OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedF_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedF_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED F OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedG_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedG_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED G OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Port, Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Pin, !Loc_u8SevenSegmentActiveStatus);	/*LED DP OFF */

				break ; 
				
				/* Number 8 */
				case Seven_SEG_enumNumberEight:
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedA_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedA_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedB_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedB_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedC_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedC_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedD_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedD_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedE_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedE_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedF_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedF_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedG_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedG_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Port, Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Pin, !Loc_u8SevenSegmentActiveStatus);	/*LED DP OFF */

				break ;  
				
				/* Number 9 */
				case Seven_SEG_enumNumberNine:
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedA_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedA_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedB_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedB_Pin , Loc_u8SevenSegmentActiveStatus);	
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedC_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedC_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedD_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedD_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedE_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedE_Pin , !Loc_u8SevenSegmentActiveStatus);	/*LED E OFF */
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedF_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedF_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedG_Port , Seven_SEG[Copy_u8Seven_SEGNum].LedG_Pin , Loc_u8SevenSegmentActiveStatus);
				DIO_enumSetPin(Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Port, Seven_SEG[Copy_u8Seven_SEGNum].LedDP_Pin, !Loc_u8SevenSegmentActiveStatus);	/*LED DP OFF */

				break ;  
				
				default:
				break;
			}
		}
		else
		{
			/*error state is NOT OK As function failed to set LEDS */
			ReturnError_enumSevenSegErrorState = Seven_SEG_enumNOK ; 
		}
	}
	
	return ReturnError_enumSevenSegErrorState ;
}


/*
 * @brief   Function to set a common value for all SevenSegment displays.
 * @param   Value: The value to be displayed on all SevenSegment displays.
 * @return  Error State indicating the success or failure of the operation.
 */
Seven_SEG_enumErrorStatus_t Seven_SEG_enumSetValueForAll(u32 Copy_u32Seven_SEG_ALLValue)
{
	
	/* Declare variable to store SevenSegment error states */
	Seven_SEG_enumErrorStatus_t ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK;
	
	/* Declare variables to store the get the Digit value which we are operating on */
	u32 Loc_u32CountNumberOfDigits = Copy_u32Seven_SEG_ALLValue ;

	/* Declare a counter for looping*/
	u8 Loc_u8Counter_ForDigits =0 ;
	
	/*Count number of digits for given decimal number from value variable*/
	while (Loc_u32CountNumberOfDigits>=1)
	{
		Loc_u8Counter_ForDigits ++ ;   /* counter to count num of digits */
		Loc_u32CountNumberOfDigits = Loc_u32CountNumberOfDigits/10 ; /*Dividing num by 10 to get another digit */
	}
	
	/*Check if the value exceed uint32 range and if the number is suitable for number of seven segment or not*/
	if ( NUM_OF_SevenSEG < Loc_u8Counter_ForDigits )
	{
		ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongValue ;
	}
	else
	{
		ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK;
		
		/*Declare counter variable to assign values to the suitable seven segment*/
		u8 Loc_u8Counter_ForAssign = 0 ;
		
		/*Reassign Loc_u32CountNumberOfDigits with value*/
		Loc_u32CountNumberOfDigits = Copy_u32Seven_SEG_ALLValue ;
		
		/* If number of digits in the value was greater than number of defined seven segments */
		if ( NUM_OF_SevenSEG < Loc_u8Counter_ForDigits )
		{
			ReturnError_enumSevenSegErrorState = Seven_SEG_enumWrongValue;
		}
		else 
		{
			ReturnError_enumSevenSegErrorState = Seven_SEG_enumOK;
			/***********This Code to Print Number on 7 SEG & If Number of digits less than Defined 7 SEG *********/
			/*********** --> Then the rest of 7 Segments will be 0 **************/
			
			/*Assign each digit in suitable seven segment for it*/
			for (Loc_u8Counter_ForAssign =0 ;  Loc_u8Counter_ForAssign <= NUM_OF_SevenSEG ; Loc_u8Counter_ForAssign++)
			{
				/*Detect the number while be assigned it the current seven segment */
				Copy_u32Seven_SEG_ALLValue = Loc_u32CountNumberOfDigits % 10 ;
				
				/*Assign the number in the current seven segment*/
				Seven_SEG_enumSetValue(Loc_u8Counter_ForAssign , Copy_u32Seven_SEG_ALLValue);
				
				/*Calculate the new number for next iterate*/
				Loc_u32CountNumberOfDigits = Loc_u32CountNumberOfDigits /10 ;
			}
				
				
				/***********This Code to Print Number on 7 SEG & If Number of digits less than Defined 7 SEG *********/
				/*********** --> Then the rest of 7 Segments will be 0 **************/
				/*
			for (Loc_u8Counter_ForAssign =0 ;  Loc_u8Counter_ForAssign < Loc_u8Counter_ForDigits ; Loc_u8Counter_ForAssign++)
			{
				//*Detect the number while be assigned it the current seven segment*
				Copy_u32Seven_SEG_ALLValue = Loc_u32CountNumberOfDigits % 10 ;
				
				//*Assign the number in the current seven segment*
				Seven_SEG_enumSetValue(Loc_u8Counter_ForAssign , Copy_u32Seven_SEG_ALLValue);
				//*Calculate the new number for next iterate*
				Loc_u32CountNumberOfDigits = Loc_u32CountNumberOfDigits /10 ;
			}
			*/
		}
		
	}
	/*Return error status*/
	return ReturnError_enumSevenSegErrorState ; 
	
	
}

