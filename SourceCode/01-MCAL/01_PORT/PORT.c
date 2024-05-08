/*
============================================================================
Name        : PORT.c
Author		 : Farah Mohey
Description : Source file for the PORT driver
Created	 : 12-Dec-23	 12:25:59 PM
=============================================================================
*/
#include "PORT.h"
#include "PORT_cfg.h"


/**
@brief  : Function to Configure the Pins to be INPUT pin or OUTPUT pin and tc configure them by PrE or POST Configuration.
@param  : Nothing
@return : Nothing
*/
void Init_PORT(void)
{
	/*If the User Choose Pre_Compile_Configuration*/
	#if(CONFIGURATION_TYPE == Pre_Compile_Configuration)
	
	/****************************** The least number of ports & pins the user can choose ************************************/
	/************************************* 2 ports  & 6 pins ****************************************************************/
	#if ((NUM_OF_PORTS == TWO_PORTS) ||(NUM_OF_PORTS == THREE_PORTS) || (NUM_OF_PORTS == FOUR_PORTS))
	
	/*************************PortA Configuration*********************************/
	/* PIN0 Configuration */
	#if (PORT_PortA_Pin0 == INPUT_INTERNALPU)		/* Set PIN0 as an input with internal pull-up enabled */
	#define PIN0_DDRA  PORT_LOW						/* INPUT_PULLUP--> DDRA=0 */
	#define PIN0_PORTA PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortA_Pin0 == INPUT_EXTERNALPD )	/* Set PIN0 as an input with external pull-down */
	#define PIN0_DDRA  PORT_LOW						/* INPUT_PULLDown--> DDRA=0 */
	#define PIN0_PORTA PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortA_Pin0 == OUTPUT_HIGH)			/* Set PIN0 as an output with high value */
	#define PIN0_DDRA  PORT_HIGH						/* OUTPUT--> DDRA=1 */
	#define PIN0_PORTA PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortA_Pin0 == OUTPUT_LOW)			/* Set PIN0 as an output with low value */
	#define PIN0_DDRA PORT_HIGH						/* OUTPUT--> DDRA=1 */
	#define PIN0_PORTA PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"						/* Error for an invalid configuration for PIN0 */
	#endif
	
	/* PIN1 Configuration */
	#if (PORT_PortA_Pin1 == INPUT_INTERNALPU)		/* Set PIN1 as an input with internal pull-up enabled */
	#define PIN1_DDRA  PORT_LOW						/* INPUT_PULLUP--> DDRA=0 */
	#define PIN1_PORTA PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortA_Pin1 == INPUT_EXTERNALPD )	/* Set PIN1 as an input with external pull-down */
	#define PIN1_DDRA  PORT_LOW						/* INPUT_PULLDown--> DDRA=0 */
	#define PIN1_PORTA PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortA_Pin1 == OUTPUT_HIGH)			/* Set PIN1 as an output with high value */
	#define PIN1_DDRA  PORT_HIGH						/* OUTPUT--> DDRA=1 */
	#define PIN1_PORTA PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortA_Pin1 == OUTPUT_LOW)			/* Set PIN1 as an output with low value */
	#define PIN1_DDRA PORT_HIGH						/* OUTPUT--> DDRA=1 */
	#define PIN1_PORTA PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN1 */
	#endif
	
	
	
	/* PIN2 Configuration */
	#if (PORT_PortA_Pin2 == INPUT_INTERNALPU)		/* Set PIN2 as an input with internal pull-up enabled */
	#define PIN2_DDRA  PORT_LOW						/* INPUT_PULLUP--> DDRA=0 */
	#define PIN2_PORTA PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortA_Pin2 == INPUT_EXTERNALPD )	/* Set PIN2 as an input with external pull-down */
	#define PIN2_DDRA  PORT_LOW						/* INPUT_PULLDown--> DDRA=0 */
	#define PIN2_PORTA PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortA_Pin2 == OUTPUT_HIGH)			/* Set PIN2 as an output with high value */
	#define PIN2_DDRA  PORT_HIGH						/* OUTPUT--> DDRA=1 */
	#define PIN2_PORTA PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortA_Pin2 == OUTPUT_LOW)			/* Set PIN2 as an output with low value */
	#define PIN2_DDRA PORT_HIGH						/* OUTPUT--> DDRA=1 */
	#define PIN2_PORTA PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN2 */
	#endif
	
	/* PIN3 Configuration */
	#if (PORT_PortA_Pin3 == INPUT_INTERNALPU)		/* Set PIN3 as an input with internal pull-up enabled */
	#define PIN3_DDRA  PORT_LOW						/* INPUT_PULLUP--> DDRA=0 */
	#define PIN3_PORTA PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortA_Pin3 == INPUT_EXTERNALPD )	/* Set PIN3 as an input with external pull-down */
	#define PIN3_DDRA  PORT_LOW						/* INPUT_PULLDown--> DDRA=0 */
	#define PIN3_PORTA PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortA_Pin3 == OUTPUT_HIGH)			/* Set PIN3 as an output with high value */
	#define PIN3_DDRA  PORT_HIGH						/* OUTPUT--> DDRA=1 */
	#define PIN3_PORTA PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortA_Pin3 == OUTPUT_LOW)			/* Set PIN3 as an output with low value */
	#define PIN3_DDRA  PORT_HIGH						/* OUTPUT--> DDRA=1 */
	#define PIN3_PORTA PORT_LOW						/* LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN3 */
	#endif
	
	/* PIN4 Configuration */
	#if (PORT_PortA_Pin4 == INPUT_INTERNALPU)		/* Set PIN4 as an input with internal pull-up enabled */
	#define PIN4_DDRA  PORT_LOW						/* INPUT_PULLUP--> DDRA=0 */
	#define PIN4_PORTA PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortA_Pin4 == INPUT_EXTERNALPD )	/* Set PIN4 as an input with external pull-down */
	#define PIN4_DDRA  PORT_LOW						/* INPUT_PULLDown--> DDRA=0 */
	#define PIN4_PORTA PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortA_Pin4 == OUTPUT_HIGH)			/* Set PIN4 as an output with high value */
	#define PIN4_DDRA  PORT_HIGH						/* OUTPUT--> DDRA=1 */
	#define PIN4_PORTA PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortA_Pin4 == OUTPUT_LOW)			/* Set PIN4 as an output with low value */
	#define PIN4_DDRA  PORT_HIGH						/* OUTPUT--> DDRA=1 */
	#define PIN4_PORTA PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN4 */
	#endif
	
	
	/* PIN5 Configuration */
	#if (PORT_PortA_Pin5 == INPUT_INTERNALPU)		/* Set PIN5 as an input with internal pull-up enabled */
	#define PIN5_DDRA  PORT_LOW						/* INPUT_PULLUP--> DDRA=0 */
	#define PIN5_PORTA PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortA_Pin5 == INPUT_EXTERNALPD )	/* Set PIN5 as an input with external pull-down */
	#define PIN5_DDRA  PORT_LOW						/* INPUT_PULLDown--> DDRA=0 */
	#define PIN5_PORTA PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortA_Pin5 == OUTPUT_HIGH)			/* Set PIN5 as an output with high value */
	#define PIN5_DDRA  PORT_HIGH						/* OUTPUT--> DDRA=1 */
	#define PIN5_PORTA PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortA_Pin5 == OUTPUT_LOW)			/* Set PIN5 as an output with low value */
	#define PIN5_DDRA PORT_HIGH						/* OUTPUT--> DDRA=1 */
	#define PIN5_PORTA PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN5 */
	#endif
	
	/***********************************PortB Configuration*************************************/
	
	/* PIN0 Configuration */
	#if (PORT_PortB_Pin0 == INPUT_INTERNALPU)		/* Set PIN0 as an input with internal pull-up enabled */
	#define PIN0_DDRB  PORT_LOW						/* INPUT_PULLUP--> DDRB=0 */
	#define PIN0_PORTB PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortB_Pin0 == INPUT_EXTERNALPD )	/* Set PIN0 as an input with external pull-down */
	#define PIN0_DDRB  PORT_LOW						/* INPUT_PULLDown--> DDRB=0 */
	#define PIN0_PORTB PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortB_Pin0 == OUTPUT_HIGH)			/* Set PIN0 as an output with high value */
	#define PIN0_DDRB  PORT_HIGH						/* OUTPUT--> DDRB=1 */
	#define PIN0_PORTB PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortB_Pin0 == OUTPUT_LOW)			/* Set PIN0 as an output with low value */
	#define PIN0_DIR PORT_HIGH						/* OUTPUT--> DDRB=1 */
	#define PIN0_PORTB PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"						/* Error for an invalid configuration for PIN0 */
	#endif
	
	/* PIN1 Configuration */
	#if (PORT_PortB_Pin1 == INPUT_INTERNALPU)		/* Set PIN1 as an input with internal pull-up enabled */
	#define PIN1_DDRB  PORT_LOW						/* INPUT_PULLUP--> DDRB=0 */
	#define PIN1_PORTB PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortB_Pin1 == INPUT_EXTERNALPD )	/* Set PIN1 as an input with external pull-down */
	#define PIN1_DDRB  PORT_LOW						/* INPUT_PULLDown--> DDRB=0 */
	#define PIN1_PORTB PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortB_Pin1 == OUTPUT_HIGH)			/* Set PIN1 as an output with high value */
	#define PIN1_DDRB  PORT_HIGH						/* OUTPUT--> DDRB=1 */
	#define PIN1_PORTB PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortB_Pin1 == OUTPUT_LOW)			/* Set PIN1 as an output with low value */
	#define PIN1_DDRB PORT_HIGH						/* OUTPUT--> DDRB=1 */
	#define PIN1_PORTB PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN1 */
	#endif
	
	
	
	/* PIN2 Configuration */
	#if (PORT_PortB_Pin2 == INPUT_INTERNALPU)		/* Set PIN2 as an input with internal pull-up enabled */
	#define PIN2_DDRB  PORT_LOW						/* INPUT_PULLUP--> DDRB=0 */
	#define PIN2_PORTB PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortB_Pin2 == INPUT_EXTERNALPD )	/* Set PIN2 as an input with external pull-down */
	#define PIN2_DDRB  PORT_LOW						/* INPUT_PULLDown--> DDRB=0 */
	#define PIN2_PORTB PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortB_Pin2 == OUTPUT_HIGH)			/* Set PIN2 as an output with high value */
	#define PIN2_DDRB  PORT_HIGH						/* OUTPUT--> DDRB=1 */
	#define PIN2_PORTB PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortB_Pin2 == OUTPUT_LOW)			/* Set PIN2 as an output with low value */
	#define PIN2_DDRB PORT_HIGH						/* OUTPUT--> DDRB=1 */
	#define PIN2_PORTB PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN2 */
	#endif
	
	/* PIN3 Configuration */
	#if (PORT_PortB_Pin3 == INPUT_INTERNALPU)		/* Set PIN3 as an input with internal pull-up enabled */
	#define PIN3_DDRB  PORT_LOW						/* INPUT_PULLUP--> DDRB=0 */
	#define PIN3_PORTB PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortB_Pin3 == INPUT_EXTERNALPD )	/* Set PIN3 as an input with external pull-down */
	#define PIN3_DDRB  PORT_LOW						/* INPUT_PULLDown--> DDRB=0 */
	#define PIN3_PORTB PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortB_Pin3 == OUTPUT_HIGH)			/* Set PIN3 as an output with high value */
	#define PIN3_DDRB  PORT_HIGH						/* OUTPUT--> DDRB=1 */
	#define PIN3_PORTB PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortB_Pin3 == OUTPUT_LOW)			/* Set PIN3 as an output with low value */
	#define PIN3_DDRB  PORT_HIGH						/* OUTPUT--> DDRB=1 */
	#define PIN3_PORTB PORT_LOW						/* LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN3 */
	#endif
	
	/* PIN4 Configuration */
	#if (PORT_PortB_Pin4 == INPUT_INTERNALPU)		/* Set PIN4 as an input with internal pull-up enabled */
	#define PIN4_DDRB  PORT_LOW						/* INPUT_PULLUP--> DDRB=0 */
	#define PIN4_PORTB PORT_HIGH					/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortB_Pin4 == INPUT_EXTERNALPD )	/* Set PIN4 as an input with external pull-down */
	#define PIN4_DDRB  PORT_LOW						/* INPUT_PULLDown--> DDRB=0 */
	#define PIN4_PORTB PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortB_Pin4 == OUTPUT_HIGH)			/* Set PIN4 as an output with high value */
	#define PIN4_DDRB  PORT_HIGH					/* OUTPUT--> DDRB=1 */
	#define PIN4_PORTB PORT_HIGH					/* High logic--> PORT=1 */
	
	#elif (PORT_PortB_Pin4 == OUTPUT_LOW)			/* Set PIN4 as an output with low value */
	#define PIN4_DDRB  PORT_HIGH					/* OUTPUT--> DDRB=1 */
	#define PIN4_PORTB PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN4 */
	#endif
	
	
	/* PIN5 Configuration */
	#if (PORT_PortB_Pin5 == INPUT_INTERNALPU)		/* Set PIN5 as an input with internal pull-up enabled */
	#define PIN5_DDRB  PORT_LOW						/* INPUT_PULLUP--> DDRB=0 */
	#define PIN5_PORTB PORT_HIGH					/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortB_Pin5 == INPUT_EXTERNALPD )	/* Set PIN5 as an input with external pull-down */
	#define PIN5_DDRB  PORT_LOW						/* INPUT_PULLDown--> DDRB=0 */
	#define PIN5_PORTB PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortB_Pin5 == OUTPUT_HIGH)			/* Set PIN5 as an output with high value */
	#define PIN5_DDRB  PORT_HIGH					/* OUTPUT--> DDRB=1 */
	#define PIN5_PORTB PORT_HIGH					/* High logic--> PORT=1 */
	
	#elif (PORT_PortB_Pin5 == OUTPUT_LOW)			/* Set PIN5 as an output with low value */
	#define PIN5_DDRB PORT_HIGH						/* OUTPUT--> DDRB=1 */
	#define PIN5_PORTB PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN5 */
	#endif
	
	
	#if (NUM_OF_PINS > SIX_PINS)
	
	/* PortA_PIN6 Configuration */
	#if (PORT_PortA_Pin6 == INPUT_INTERNALPU)			/* Set PIN6 as an input with internal pull-up enabled */
	#define PIN6_DDRA  PORT_LOW							/* INPUT_PULLUP--> DDRA=0 */
	#define PIN6_PORTA PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortA_Pin6 == INPUT_EXTERNALPD )		/* Set PIN6 as an input with external pull-down */
	#define PIN6_DDRA  PORT_LOW							/* INPUT_PULLDown--> DDRA=0 */
	#define PIN6_PORTA PORT_LOW							/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortA_Pin6== OUTPUT_HIGH)				/* Set PIN6 as an output with high value */
	#define PIN6_DDRA  PORT_HIGH						/* OUTPUT--> DDRA=1 */
	#define PIN6_PORTA PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortA_Pin6 == OUTPUT_LOW)				/* Set PIN6 as an output with low value */
	#define PIN6_DDRA PORT_HIGH							/* OUTPUT--> DDRA=1 */
	#define PIN6_PORTA PORT_LOW							/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN6 */
	#endif
	
	//#endif
	
	/* PortB_PIN6 Configuration */
	#if (PORT_PortB_Pin6 == INPUT_INTERNALPU)		/* Set PIN6 as an input with internal pull-up enabled */
	#define PIN6_DDRB  PORT_LOW						/* INPUT_PULLUP--> DDRB=0 */
	#define PIN6_PORTB PORT_HIGH					/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortB_Pin6 == INPUT_EXTERNALPD )	/* Set PIN6 as an input with external pull-down */
	#define PIN6_DDRB  PORT_LOW						/* INPUT_PULLDown--> DDRB=0 */
	#define PIN6_PORTB PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortB_Pin6== OUTPUT_HIGH)			/* Set PIN6 as an output with high value */
	#define PIN6_DDRB  PORT_HIGH					/* OUTPUT--> DDRB=1 */
	#define PIN6_PORTB PORT_HIGH					/* High logic--> PORT=1 */
	
	#elif (PORT_PortB_Pin6 == OUTPUT_LOW)			/* Set PIN6 as an output with low value */
	#define PIN6_DDRB PORT_HIGH						/* OUTPUT--> DDRB=1 */
	#define PIN6_PORTB PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN6 */
	#endif
	#endif
	
	#if (NUM_OF_PINS > SEVEN_PINS)
	/* PortA_PIN7 Configuration */
	#if (PORT_PortA_Pin7 == INPUT_INTERNALPU)		/* Set PIN7 as an input with internal pull-up enabled */
	#define PIN7_DDRA  PORT_LOW						/* INPUT_PULLUP--> DDRA=0 */
	#define PIN7_PORTA PORT_HIGH					/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortA_Pin7 == INPUT_EXTERNALPD )	/* Set PIN7 as an input with external pull-down */
	#define PIN7_DDRA  PORT_LOW						/* INPUT_PULLDown--> DDRA=0 */
	#define PIN7_PORTA PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortA_Pin7 == OUTPUT_HIGH)			/* Set PIN7 as an output with high value */
	#define PIN7_DDRA  PORT_HIGH					/* OUTPUT--> DDRA=1 */
	#define PIN7_PORTA PORT_HIGH					/* High logic--> PORT=1 */
	
	#elif (PORT_PortA_Pin7 == OUTPUT_LOW)			/* Set PIN7 as an output with low value */
	#define PIN7_DDRA PORT_HIGH						/* OUTPUT--> DDRA=1 */
	#define PIN7_PORTA PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN7 */
	#endif
	
	/* PortB_PIN7 Configuration */
	#if (PORT_PortB_Pin7 == INPUT_INTERNALPU)		/* Set PIN7 as an input with internal pull-up enabled */
	#define PIN7_DDRB  PORT_LOW						/* INPUT_PULLUP--> DDRB=0 */
	#define PIN7_PORTB PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortB_Pin7 == INPUT_EXTERNALPD)		/* Set PIN7 as an input with external pull-down */
	#define PIN7_DDRB  PORT_LOW						/* INPUT_PULLDown--> DDRB=0 */
	#define PIN7_PORTB PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortB_Pin7 == OUTPUT_HIGH)			/* Set PIN7 as an output with high value */
	#define PIN7_DDRB  PORT_HIGH						/* OUTPUT--> DDRB=1 */
	#define PIN7_PORTB PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortB_Pin7 == OUTPUT_LOW)			/* Set PIN7 as an output with low value */
	#define PIN7_DDRB PORT_HIGH						/* OUTPUT--> DDRB=1 */
	#define PIN7_PORTB PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN7 */
	#endif
	
	
	#endif
	
	//#endif
	
	/**********************************************************THREE_PORTS Case**********************************************************/
	
	#elif ((NUM_OF_PORTS == THREE_PORTS) || (NUM_OF_PORTS == FOUR_PORTS))
	
	/* Previous Code of 2Ports With 6 or 7 or 8 Pins Already Included */
	/* Port A_Pin 0--> 5 or 6 or 7 */
	/* Port B_Pin 0--> 5 or 6 or 7 */
	
	/***********************************PortC Configuration*************************************/
	/* Port C_Pin 0--> 5 CONFIGURATION */
	
	/* PIN0 Configuration */
	#if (PORT_PortC_Pin0 == INPUT_INTERNALPU)		/* Set PIN0 as an input with internal pull-up enabled */
	#define PIN0_DDRC  PORT_LOW						/* INPUT_PULLUP--> DDRC=0 */
	#define PIN0_PORTC PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortC_Pin0 == INPUT_EXTERNALPD )	/* Set PIN0 as an input with external pull-down */
	#define PIN0_DDRC  PORT_LOW						/* INPUT_PULLDown--> DDRC=0 */
	#define PIN0_PORTC PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortC_Pin0 == OUTPUT_HIGH)			/* Set PIN0 as an output with high value */
	#define PIN0_DDRC  PORT_HIGH						/* OUTPUT--> DDRC=1 */
	#define PIN0_PORTC PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortC_Pin0 == OUTPUT_LOW)			/* Set PIN0 as an output with low value */
	#define PIN0_DIR PORT_HIGH						/* OUTPUT--> DDRC=1 */
	#define PIN0_PORTC PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"						/* Error for an invalid configuration for PIN0 */
	#endif
	
	/* PIN1 Configuration */
	#if (PORT_PortC_Pin1 == INPUT_INTERNALPU)		/* Set PIN1 as an input with internal pull-up enabled */
	#define PIN1_DDRC  PORT_LOW						/* INPUT_PULLUP--> DDRC=0 */
	#define PIN1_PORTC PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortC_Pin1 == INPUT_EXTERNALPD )	/* Set PIN1 as an input with external pull-down */
	#define PIN1_DDRC  PORT_LOW						/* INPUT_PULLDown--> DDRC=0 */
	#define PIN1_PORTC PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortC_Pin1 == OUTPUT_HIGH)			/* Set PIN1 as an output with high value */
	#define PIN1_DDRC  PORT_HIGH						/* OUTPUT--> DDRC=1 */
	#define PIN1_PORTC PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortC_Pin1 == OUTPUT_LOW)			/* Set PIN1 as an output with low value */
	#define PIN1_DDRC PORT_HIGH						/* OUTPUT--> DDRC=1 */
	#define PIN1_PORTC PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN1 */
	#endif
	
	
	
	/* PIN2 Configuration */
	#if (PORT_PortC_Pin2 == INPUT_INTERNALPU)		/* Set PIN2 as an input with internal pull-up enabled */
	#define PIN2_DDRC  PORT_LOW						/* INPUT_PULLUP--> DDRC=0 */
	#define PIN2_PORTC PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortC_Pin2 == INPUT_EXTERNALPD )	/* Set PIN2 as an input with external pull-down */
	#define PIN2_DDRC  PORT_LOW						/* INPUT_PULLDown--> DDRC=0 */
	#define PIN2_PORTC PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortC_Pin2 == OUTPUT_HIGH)			/* Set PIN2 as an output with high value */
	#define PIN2_DDRC  PORT_HIGH						/* OUTPUT--> DDRC=1 */
	#define PIN2_PORTC PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortC_Pin2 == OUTPUT_LOW)			/* Set PIN2 as an output with low value */
	#define PIN2_DDRC PORT_HIGH						/* OUTPUT--> DDRC=1 */
	#define PIN2_PORTC PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN2 */
	#endif
	
	/* PIN3 Configuration */
	#if (PORT_PortC_Pin3 == INPUT_INTERNALPU)		/* Set PIN3 as an input with internal pull-up enabled */
	#define PIN3_DDRC  PORT_LOW						/* INPUT_PULLUP--> DDRC=0 */
	#define PIN3_PORTC PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortC_Pin3 == INPUT_EXTERNALPD )	/* Set PIN3 as an input with external pull-down */
	#define PIN3_DDRC  PORT_LOW						/* INPUT_PULLDown--> DDRC=0 */
	#define PIN3_PORTC PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortC_Pin3 == OUTPUT_HIGH)			/* Set PIN3 as an output with high value */
	#define PIN3_DDRC  PORT_HIGH						/* OUTPUT--> DDRC=1 */
	#define PIN3_PORTC PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortC_Pin3 == OUTPUT_LOW)			/* Set PIN3 as an output with low value */
	#define PIN3_DDRC  PORT_HIGH						/* OUTPUT--> DDRC=1 */
	#define PIN3_PORTC PORT_LOW						/* LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN3 */
	#endif
	
	/* PIN4 Configuration */
	#if (PORT_PortC_Pin4 == INPUT_INTERNALPU)		/* Set PIN4 as an input with internal pull-up enabled */
	#define PIN4_DDRC  PORT_LOW						/* INPUT_PULLUP--> DDRC=0 */
	#define PIN4_PORTC PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortC_Pin4 == INPUT_EXTERNALPD )	/* Set PIN4 as an input with external pull-down */
	#define PIN4_DDRC  PORT_LOW						/* INPUT_PULLDown--> DDRC=0 */
	#define PIN4_PORTC PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortC_Pin4 == OUTPUT_HIGH)			/* Set PIN4 as an output with high value */
	#define PIN4_DDRC  PORT_HIGH						/* OUTPUT--> DDRC=1 */
	#define PIN4_PORTC PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortC_Pin4 == OUTPUT_LOW)			/* Set PIN4 as an output with low value */
	#define PIN4_DDRC  PORT_HIGH						/* OUTPUT--> DDRC=1 */
	#define PIN4_PORTC PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN4 */
	#endif
	
	
	/* PIN5 Configuration */
	#if (PORT_PortC_Pin5 == INPUT_INTERNALPU)		/* Set PIN5 as an input with internal pull-up enabled */
	#define PIN5_DDRC  PORT_LOW						/* INPUT_PULLUP--> DDRC=0 */
	#define PIN5_PORTC PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortC_Pin5 == INPUT_EXTERNALPD )	/* Set PIN5 as an input with external pull-down */
	#define PIN5_DDRC  PORT_LOW						/* INPUT_PULLDown--> DDRC=0 */
	#define PIN5_PORTC PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortC_Pin5 == OUTPUT_HIGH)			/* Set PIN5 as an output with high value */
	#define PIN5_DDRC  PORT_HIGH						/* OUTPUT--> DDRC=1 */
	#define PIN5_PORTC PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortC_Pin5 == OUTPUT_LOW)			/* Set PIN5 as an output with low value */
	#define PIN5_DDRC PORT_HIGH						/* OUTPUT--> DDRC=1 */
	#define PIN5_PORTC PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN5 */
	#endif
	
	
	#if (NUM_OF_PINS > SIX_PINS)
	
	/* PIN6 Configuration */
	#if (PORT_PortC_Pin6 == INPUT_INTERNALPU)			/* Set PIN6 as an input with internal pull-up enabled */
	#define PIN6_DDRC PORT_LOW							/* INPUT_PULLUP--> DDRC=0 */
	#define PIN6_PORTC PORT_HIGH							/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortC_Pin6 == INPUT_EXTERNALPD )		/* Set PIN6 as an input with external pull-down */
	#define PIN6_DDRC  PORT_LOW							/* INPUT_PULLDown--> DDRC=0 */
	#define PIN6_PORTC PORT_LOW							/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortC_Pin6== OUTPUT_HIGH)				/* Set PIN6 as an output with high value */
	#define PIN6_DDRC  PORT_HIGH							/* OUTPUT--> DDRC=1 */
	#define PIN6_PORTC PORT_HIGH							/* High logic--> PORT=1 */
	
	#elif (PORT_PortC_Pin6 == OUTPUT_LOW)				/* Set PIN6 as an output with low value */
	#define PIN6_DDRC PORT_HIGH							/* OUTPUT--> DDRC=1 */
	#define PIN6_PORTC PORT_LOW							/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN6 */
	#endif
	
	#endif
	
	
	#if (NUM_OF_PINS > SEVEN_PINS)
	
	/* PIN7 Configuration */
	#if (PORT_PortC_Pin7 == INPUT_INTERNALPU)		/* Set PIN7 as an input with internal pull-up enabled */
	#define PIN7_DDRC  PORT_LOW						/* INPUT_PULLUP--> DDRC=0 */
	#define PIN7_PORTC PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortC_Pin7 == INPUT_EXTERNALPD )	/* Set PIN7 as an input with external pull-down */
	#define PIN7_DDRC  PORT_LOW						/* INPUT_PULLDown--> DDRC=0 */
	#define PIN7_PORTC PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortC_Pin7 == OUTPUT_HIGH)			/* Set PIN7 as an output with high value */
	#define PIN7_DDRC  PORT_HIGH						/* OUTPUT--> DDRC=1 */
	#define PIN7_PORTC PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortC_Pin7 == OUTPUT_LOW)			/* Set PIN7 as an output with low value */
	#define PIN7_DDRC PORT_HIGH						/* OUTPUT--> DDRC=1 */
	#define PIN7_PORTC PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN7 */
	#endif
	
	#endif
	#endif

	
	/**********************************************************FOUR_PORTS Case**********************************************************/
	#if (NUM_OF_PORTS == FOUR_PORTS)
	
	/* Previous Code of 3Ports With 6 or 7 or 8 Pins Already Included */
	/* PortA_Pin 0--> 5 or 6 or 7 */
	/* PortB_Pin 0--> 5 or 6 or 7 */
	/* PortC_Pin 0--> 5 or 6 or 7 */
	/***********************************PortD Configuration*************************************/
	/* PortD_Pin 0--> 5 CONFIGURATION */
	
	/* PIN0 Configuration */
	#if (PORT_PortD_Pin0 == INPUT_INTERNALPU)		/* Set PIN0 as an input with internal pull-up enabled */
	#define PIN0_DDRD  PORT_LOW						/* INPUT_PULLUP--> DDRD=0 */
	#define PIN0_PORTD PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortD_Pin0 == INPUT_EXTERNALPD )	/* Set PIN0 as an input with external pull-down */
	#define PIN0_DDRD  PORT_LOW						/* INPUT_PULLDown--> DDRD=0 */
	#define PIN0_PORTD PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortD_Pin0 == OUTPUT_HIGH)			/* Set PIN0 as an output with high value */
	#define PIN0_DDRD  PORT_HIGH						/* OUTPUT--> DDRD=1 */
	#define PIN0_PORTD PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortD_Pin0 == OUTPUT_LOW)			/* Set PIN0 as an output with low value */
	#define PIN0_DIR PORT_HIGH						/* OUTPUT--> DDRD=1 */
	#define PIN0_PORTD PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"						/* Error for an invalid configuration for PIN0 */
	#endif
	
	/* PIN1 Configuration */
	#if (PORT_PortD_Pin1 == INPUT_INTERNALPU)		/* Set PIN1 as an input with internal pull-up enabled */
	#define PIN1_DDRD  PORT_LOW						/* INPUT_PULLUP--> DDRD=0 */
	#define PIN1_PORTD PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortD_Pin1 == INPUT_EXTERNALPD )	/* Set PIN1 as an input with external pull-down */
	#define PIN1_DDRD  PORT_LOW						/* INPUT_PULLDown--> DDRD=0 */
	#define PIN1_PORTD PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortD_Pin1 == OUTPUT_HIGH)			/* Set PIN1 as an output with high value */
	#define PIN1_DDRD  PORT_HIGH						/* OUTPUT--> DDRD=1 */
	#define PIN1_PORTD PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortD_Pin1 == OUTPUT_LOW)			/* Set PIN1 as an output with low value */
	#define PIN1_DDRD PORT_HIGH						/* OUTPUT--> DDRD=1 */
	#define PIN1_PORTD PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN1 */
	#endif
	
	
	
	/* PIN2 Configuration */
	#if (PORT_PortD_Pin2 == INPUT_INTERNALPU)		/* Set PIN2 as an input with internal pull-up enabled */
	#define PIN2_DDRD  PORT_LOW						/* INPUT_PULLUP--> DDRD=0 */
	#define PIN2_PORTD PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortD_Pin2 == INPUT_EXTERNALPD )	/* Set PIN2 as an input with external pull-down */
	#define PIN2_DDRD  PORT_LOW						/* INPUT_PULLDown--> DDRD=0 */
	#define PIN2_PORTD PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortD_Pin2 == OUTPUT_HIGH)			/* Set PIN2 as an output with high value */
	#define PIN2_DDRD  PORT_HIGH						/* OUTPUT--> DDRD=1 */
	#define PIN2_PORTD PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortD_Pin2 == OUTPUT_LOW)			/* Set PIN2 as an output with low value */
	#define PIN2_DDRD PORT_HIGH						/* OUTPUT--> DDRD=1 */
	#define PIN2_PORTD PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN2 */
	#endif
	
	/* PIN3 Configuration */
	#if (PORT_PortD_Pin3 == INPUT_INTERNALPU)		/* Set PIN3 as an input with internal pull-up enabled */
	#define PIN3_DDRD  PORT_LOW						/* INPUT_PULLUP--> DDRD=0 */
	#define PIN3_PORTD PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortD_Pin3 == INPUT_EXTERNALPD )	/* Set PIN3 as an input with external pull-down */
	#define PIN3_DDRD  PORT_LOW						/* INPUT_PULLDown--> DDRD=0 */
	#define PIN3_PORTD PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortD_Pin3 == OUTPUT_HIGH)			/* Set PIN3 as an output with high value */
	#define PIN3_DDRD  PORT_HIGH						/* OUTPUT--> DDRD=1 */
	#define PIN3_PORTD PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortD_Pin3 == OUTPUT_LOW)			/* Set PIN3 as an output with low value */
	#define PIN3_DDRD  PORT_HIGH						/* OUTPUT--> DDRD=1 */
	#define PIN3_PORTD PORT_LOW						/* LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN3 */
	#endif
	
	/* PIN4 Configuration */
	#if (PORT_PortD_Pin4 == INPUT_INTERNALPU)		/* Set PIN4 as an input with internal pull-up enabled */
	#define PIN4_DDRD  PORT_LOW						/* INPUT_PULLUP--> DDRD=0 */
	#define PIN4_PORTD PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortD_Pin4 == INPUT_EXTERNALPD )	/* Set PIN4 as an input with external pull-down */
	#define PIN4_DDRD  PORT_LOW						/* INPUT_PULLDown--> DDRD=0 */
	#define PIN4_PORTD PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortD_Pin4 == OUTPUT_HIGH)			/* Set PIN4 as an output with high value */
	#define PIN4_DDRD  PORT_HIGH						/* OUTPUT--> DDRD=1 */
	#define PIN4_PORTD PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortD_Pin4 == OUTPUT_LOW)			/* Set PIN4 as an output with low value */
	#define PIN4_DDRD  PORT_HIGH						/* OUTPUT--> DDRD=1 */
	#define PIN4_PORTD PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN4 */
	#endif
	
	
	/* PIN5 Configuration */
	#if (PORT_PortD_Pin5 == INPUT_INTERNALPU)		/* Set PIN5 as an input with internal pull-up enabled */
	#define PIN5_DDRD  PORT_LOW						/* INPUT_PULLUP--> DDRD=0 */
	#define PIN5_PORTD PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortD_Pin5 == INPUT_EXTERNALPD )	/* Set PIN5 as an input with external pull-down */
	#define PIN5_DDRD  PORT_LOW						/* INPUT_PULLDown--> DDRD=0 */
	#define PIN5_PORTD PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortD_Pin5 == OUTPUT_HIGH)			/* Set PIN5 as an output with high value */
	#define PIN5_DDRD  PORT_HIGH						/* OUTPUT--> DDRD=1 */
	#define PIN5_PORTD PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortD_Pin5 == OUTPUT_LOW)			/* Set PIN5 as an output with low value */
	#define PIN5_DDRD PORT_HIGH						/* OUTPUT--> DDRD=1 */
	#define PIN5_PORTD PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN5 */
	#endif
	
	
	#if (NUM_OF_PINS > SIX_PINS)
	
	/* PIN6 Configuration */
	#if (PORT_PortD_Pin6 == INPUT_INTERNALPU)			/* Set PIN6 as an input with internal pull-up enabled */
	#define PIN6_DDRD  PORT_LOW							/* INPUT_PULLUP--> DDRD=0 */
	#define PIN6_PORTD PORT_HIGH							/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortD_Pin6 == INPUT_EXTERNALPD )		/* Set PIN6 as an input with external pull-down */
	#define PIN6_DDRD  PORT_LOW							/* INPUT_PULLDown--> DDRD=0 */
	#define PIN6_PORTD PORT_LOW							/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortD_Pin6== OUTPUT_HIGH)				/* Set PIN6 as an output with high value */
	#define PIN6_DDRD  PORT_HIGH							/* OUTPUT--> DDRD=1 */
	#define PIN6_PORTD PORT_HIGH							/* High logic--> PORT=1 */
	
	#elif (PORT_PortD_Pin6 == OUTPUT_LOW)				/* Set PIN6 as an output with low value */
	#define PIN6_DDRD PORT_HIGH							/* OUTPUT--> DDRD=1 */
	#define PIN6_PORTD PORT_LOW							/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN6 */
	#endif
	
	#endif
	
	#if (NUM_OF_PINS > SEVEN_PINS)
	
	/* PIN7 Configuration */
	#if (PORT_PortD_Pin7 == INPUT_INTERNALPU)		/* Set PIN7 as an input with internal pull-up enabled */
	#define PIN7_DDRD  PORT_LOW						/* INPUT_PULLUP--> DDRD=0 */
	#define PIN7_PORTD PORT_HIGH						/* INPUT_PULLUP--> PORT=1 */
	
	#elif (PORT_PortD_Pin7 == INPUT_EXTERNALPD)	/* Set PIN7 as an input with external pull-down */
	#define PIN7_DDRD  PORT_LOW						/* INPUT_PULLDown--> DDRD=0 */
	#define PIN7_PORTD PORT_LOW						/* INPUT_PULLDown--> PORT=0 */
	
	#elif (PORT_PortD_Pin7 == OUTPUT_HIGH)			/* Set PIN7 as an output with high value */
	#define PIN7_DDRD  PORT_HIGH						/* OUTPUT--> DDRD=1 */
	#define PIN7_PORTD PORT_HIGH						/* High logic--> PORT=1 */
	
	#elif (PORT_PortD_Pin7 == OUTPUT_LOW)			/* Set PIN7 as an output with low value */
	#define PIN7_DDRD PORT_HIGH						/* OUTPUT--> DDRD=1 */
	#define PIN7_PORTD PORT_LOW						/*LOW logic--> PORT=0 */
	
	#else
	#error "InvalidConfig"			/* Error for an invalid configuration for PIN7 */
	#endif

	#endif
	#endif
	
	
	/**********************************************************SET DDR AND PORT Registers**********************************************************/
	/**********************************************************TWO_PORTS Case**********************************************************/
	#if (NUM_OF_PORTS == TWO_PORTS)
	{
		#if (NUM_OF_PINS == SIX_PINS)
		DDRA  = CONCAT_Six(PIN5_DDRA,PIN4_DDRA,PIN3_DDRA,PIN2_DDRA,PIN1_DDRA,PIN0_DDRA);
		PORTA = CONCAT_Six(PIN5_PORTA,PIN4_PORTA,PIN3_PORTA,PIN2_PORTA,PIN1_PORTA,PIN0_PORTA);
		
		DDRB  = CONCAT_Six(PIN5_DDRB,PIN4_DDRB,PIN3_DDRB,PIN2_DDRB,PIN1_DDRB,PIN0_DDRB);
		PORTB = CONCAT_Six(PIN5_PORTB,PIN4_PORTB,PIN3_PORTB,PIN2_PORTB,PIN1_PORTB,PIN0_PORTB);


		#elif (NUM_OF_PINS == SEVEN_PINS)
		DDRA  = CONCAT_Seven(PIN6_DDRA,PIN5_DDRA,PIN4_DDRA,PIN3_DDRA,PIN2_DDRA,PIN1_DDRA,PIN0_DDRA);
		PORTA = CONCAT_Seven(PIN6_PORTA,PIN5_PORTA,PIN4_PORTA,PIN3_PORTA,PIN2_PORTA,PIN1_PORTA,PIN0_PORTA);
		
		DDRB  = CONCAT_Seven(PIN6_DDRB,PIN5_DDRB,PIN4_DDRB,PIN3_DDRB,PIN2_DDRB,PIN1_DDRB,PIN0_DDRB);
		PORTB = CONCAT_Seven(PIN6_PORTB,PIN5_PORTB,PIN4_PORTB,PIN3_PORTB,PIN2_PORTB,PIN1_PORTB,PIN0_PORTB);


		#elif (NUM_OF_PINS == EIGHT_PINS)
		DDRA  = CONCAT_Eight(PIN7_DDRA,PIN6_DDRA,PIN5_DDRA,PIN4_DDRA,PIN3_DDRA,PIN2_DDRA,PIN1_DDRA,PIN0_DDRA);
		PORTA = CONCAT_Eight(PIN7_PORTA,PIN6_PORTA,PIN5_PORTA,PIN4_PORTA,PIN3_PORTA,PIN2_PORTA,PIN1_PORTA,PIN0_PORTA);
		
		DDRB  = CONCAT_Eight(PIN7_DDRB,PIN6_DDRB,PIN5_DDRB,PIN4_DDRB,PIN3_DDRB,PIN2_DDRB,PIN1_DDRB,PIN0_DDRB);
		PORTB = CONCAT_Eight(PIN7_PORTB,PIN6_PORTB,PIN5_PORTB,PIN4_PORTB,PIN3_PORTB,PIN2_PORTB,PIN1_PORTB,PIN0_PORTB);
		
		#endif

	}
	#endif
	/**********************************************************THREE_PORTS Case**********************************************************/
	#if (NUM_OF_PORTS == THREE_PORTS)
	{
		#if (NUM_OF_PINS == SIX_PINS)
		DDRA  = CONCAT_Six(PIN5_DDRA,PIN4_DDRA,PIN3_DDRA,PIN2_DDRA,PIN1_DDRA,PIN0_DDRA);
		PORTA = CONCAT_Six(PIN5_PORTA,PIN4_PORTA,PIN3_PORTA,PIN2_PORTA,PIN1_PORTA,PIN0_PORTA);
		
		DDRB  = CONCAT_Six(PIN5_DDRB,PIN4_DDRB,PIN3_DDRB,PIN2_DDRB,PIN1_DDRB,PIN0_DDRB);
		PORTB = CONCAT_Six(PIN5_PORTB,PIN4_PORTB,PIN3_PORTB,PIN2_PORTB,PIN1_PORTB,PIN0_PORTB);
		
		DDRC  = CONCAT_Six(PIN5_DDRC,PIN4_DDRC,PIN3_DDRC,PIN2_DDRC,PIN1_DDRC,PIN0_DDRC);
		PORTC = CONCAT_Six(PIN5_PORTC,PIN4_PORTC,PIN3_PORTC,PIN2_PORTC,PIN1_PORTC,PIN0_PORTC);
		
		#elif( NUM_OF_PINS == SEVEN_PINS)
		DDRA  = CONCAT_Seven(PIN6_DDRA,PIN5_DDRA,PIN4_DDRA,PIN3_DDRA,PIN2_DDRA,PIN1_DDRA,PIN0_DDRA);
		PORTA = CONCAT_Seven(PIN6_PORTA,PIN5_PORTA,PIN4_PORTA,PIN3_PORTA,PIN2_PORTA,PIN1_PORTA,PIN0_PORTA);
		
		DDRB  = CONCAT_Seven(PIN6_DDRB,PIN5_DDRB,PIN4_DDRB,PIN3_DDRB,PIN2_DDRB,PIN1_DDRB,PIN0_DDRB);
		PORTB = CONCAT_Seven(PIN6_PORTB,PIN5_PORTB,PIN4_PORTB,PIN3_PORTB,PIN2_PORTB,PIN1_PORTB,PIN0_PORTB);
		
		DDRC  = CONCAT_Seven(PIN6_DDRC,PIN5_DDRC,PIN4_DDRC,PIN3_DDRC,PIN2_DDRC,PIN1_DDRC,PIN0_DDRC);
		PORTC = CONCAT_Seven(PIN6_PORTC,PIN5_PORTC,PIN4_PORTC,PIN3_PORTC,PIN2_PORTC,PIN1_PORTC,PIN0_PORTC);
		

		#elif( NUM_OF_PINS == EIGHT_PINS)
		DDRA	= CONCAT_Eight(PIN7_DDRA,PIN6_DDRA,PIN5_DDRA,PIN4_DDRA,PIN3_DDRA,PIN2_DDRA,PIN1_DDRA,PIN0_DDRA);
		PORTA 	= CONCAT_Eight(PIN7_PORTA,PIN6_PORTA,PIN5_PORTA,PIN4_PORTA,PIN3_PORTA,PIN2_PORTA,PIN1_PORTA,PIN0_PORTA);
		
		DDRB 	= CONCAT_Eight(PIN7_DDRB,PIN6_DDRB,PIN5_DDRB,PIN4_DDRB,PIN3_DDRB,PIN2_DDRB,PIN1_DDRB,PIN0_DDRB);
		PORTB 	= CONCAT_Eight(PIN7_PORTB,PIN6_PORTB,PIN5_PORTB,PIN4_PORTB,PIN3_PORTB,PIN2_PORTB,PIN1_PORTB,PIN0_PORTB);
		
		DDRC 	= CONCAT_Eight(PIN7_DDRC,PIN6_DDRC,PIN5_DDRC,PIN4_DDRC,PIN3_DDRC,PIN2_DDRC,PIN1_DDRC,PIN0_DDRC);
		PORTC 	= CONCAT_Eight(PIN7_PORTC,PIN6_PORTC,PIN5_PORTC,PIN4_PORTC,PIN3_PORTC,PIN2_PORTC,PIN1_PORTC,PIN0_PORTC);
		#endif
	}
	#endif
	
	/**********************************************************FOUR_PORTS Case**********************************************************/
	#if (NUM_OF_PORTS == FOUR_PORTS)
	{
		#if (NUM_OF_PINS == SIX_PINS)
		DDRA  = CONCAT_Six(PIN5_DDRA,PIN4_DDRA,PIN3_DDRA,PIN2_DDRA,PIN1_DDRA,PIN0_DDRA);
		PORTA = CONCAT_Six(PIN5_PORTA,PIN4_PORTA,PIN3_PORTA,PIN2_PORTA,PIN1_PORTA,PIN0_PORTA);
		
		DDRB  = CONCAT_Six(PIN5_DDRB,PIN4_DDRB,PIN3_DDRB,PIN2_DDRB,PIN1_DDRB,PIN0_DDRB);
		PORTB = CONCAT_Six(PIN5_PORTB,PIN4_PORTB,PIN3_PORTB,PIN2_PORTB,PIN1_PORTB,PIN0_PORTB);
		
		DDRC  = CONCAT_Six(PIN5_DDRC,PIN4_DDRC,PIN3_DDRC,PIN2_DDRC,PIN1_DDRC,PIN0_DDRC);
		PORTC = CONCAT_Six(PIN5_PORTC,PIN4_PORTC,PIN3_PORTC,PIN2_PORTC,PIN1_PORTC,PIN0_PORTC);
		
		DDRD  = CONCAT_Six(PIN5_DDRD,PIN4_DDRD,PIN3_DDRD,PIN2_DDRD,PIN1_DDRD,PIN0_DDRD);
		PORTD = CONCAT_Six(PIN5_PORTD,PIN4_PORTD,PIN3_PORTD,PIN2_PORTD,PIN1_PORTD,PIN0_PORTD);


		#elif(NUM_OF_PINS==SEVEN_PINS)
		DDRA  = CONCAT_Seven(PIN6_DDRA,PIN5_DDRA,PIN4_DDRA,PIN3_DDRA,PIN2_DDRA,PIN1_DDRA,PIN0_DDRA);
		PORTA = CONCAT_Seven(PIN6_PORTA,PIN5_PORTA,PIN4_PORTA,PIN3_PORTA,PIN2_PORTA,PIN1_PORTA,PIN0_PORTA);
		
		DDRB  = CONCAT_Seven(PIN6_DDRB,PIN5_DDRB,PIN4_DDRB,PIN3_DDRB,PIN2_DDRB,PIN1_DDRB,PIN0_DDRB);
		PORTB = CONCAT_Seven(PIN6_PORTB,PIN5_PORTB,PIN4_PORTB,PIN3_PORTB,PIN2_PORTB,PIN1_PORTB,PIN0_PORTB);
		
		DDRC  = CONCAT_Seven(PIN6_DDRC,PIN5_DDRC,PIN4_DDRC,PIN3_DDRC,PIN2_DDRC,PIN1_DDRC,PIN0_DDRC);
		PORTC = CONCAT_Seven(PIN6_PORTC,PIN5_PORTC,PIN4_PORTC,PIN3_PORTC,PIN2_PORTC,PIN1_PORTC,PIN0_PORTC);
		
		DDRD  = CONCAT_Seven(PIN6_DDRD,PIN5_DDRD,PIN4_DDRD,PIN3_DDRD,PIN2_DDRD,PIN1_DDRD,PIN0_DDRD);
		PORTD = CONCAT_Seven(PIN6_PORTD,PIN5_PORTD,PIN4_PORTD,PIN3_PORTD,PIN2_PORTD,PIN1_PORTD,PIN0_PORTD);


		#elif(NUM_OF_PINS==EIGHT_PINS)
		
		DDRA  = CONCAT_Eight(PIN7_DDRA,PIN6_DDRA,PIN5_DDRA,PIN4_DDRA,PIN3_DDRA,PIN2_DDRA,PIN1_DDRA,PIN0_DDRA);
		PORTA = CONCAT_Eight(PIN7_PORTA,PIN6_PORTA,PIN5_PORTA,PIN4_PORTA,PIN3_PORTA,PIN2_PORTA,PIN1_PORTA,PIN0_PORTA);
		
		DDRB  = CONCAT_Eight(PIN7_DDRB,PIN6_DDRB,PIN5_DDRB,PIN4_DDRB,PIN3_DDRB,PIN2_DDRB,PIN1_DDRB,PIN0_DDRB);
		PORTB = CONCAT_Eight(PIN7_PORTB,PIN6_PORTB,PIN5_PORTB,PIN4_PORTB,PIN3_PORTB,PIN2_PORTB,PIN1_PORTB,PIN0_PORTB);
		
		DDRC  = CONCAT_Eight(PIN7_DDRC,PIN6_DDRC,PIN5_DDRC,PIN4_DDRC,PIN3_DDRC,PIN2_DDRC,PIN1_DDRC,PIN0_DDRC);
		PORTC = CONCAT_Eight(PIN7_PORTC,PIN6_PORTC,PIN5_PORTC,PIN4_PORTC,PIN3_PORTC,PIN2_PORTC,PIN1_PORTC,PIN0_PORTC);
		
		DDRD  = CONCAT_Eight(PIN7_DDRD,PIN6_DDRD,PIN5_DDRD,PIN4_DDRD,PIN3_DDRD,PIN2_DDRD,PIN1_DDRD,PIN0_DDRD);
		PORTD = CONCAT_Eight(PIN7_PORTD,PIN6_PORTD,PIN5_PORTD,PIN4_PORTD,PIN3_PORTD,PIN2_PORTD,PIN1_PORTD,PIN0_PORTD) ;
		#endif
	}
	
	#endif
	
	


	//POST_Compile_Configuration
	#elif (CONFIGURATION_TYPE==POST_Compile_Configuration)
	{
		extern PORT_enumpinopt_t PORT_PINcfg [NUM_OF_PINS*NUM_OF_PORTS];
		/* Iterate through all pins*/
		for (int i =0 ; i < (NUM_OF_PINS*NUM_OF_PORTS) ; i++ )
		{
			/* Determine the port number from pin number with index*/
			PORT_enumPortNum_t Loc_enumPortNum = (PORT_enumPortNum_t)(i / NUM_OF_PINS);		/*Casting to return port number enum , i=0-->7 =0 ---> PortA*/
			
			/* Determine the pin number from the index*/
			u8 Loc_U8PinNum = (u8)(i % NUM_OF_PINS);	/* PIN2 % 8 = 2 ,GETTING PIN NUMBER FROM INDEX*/
			
			/*Switch based on the port number*/
			switch(Loc_enumPortNum)
			{
				case PORT_enumPortA:
				{
					/*Switch based on the pin configuration*/
					switch (PORT_PINcfg[i])
					{
						case PORT_enumINPUT_INTERNALPU:		/*Input with Internal pull-up enabled*/
						{
							CLR_BIT(DDRA,Loc_U8PinNum);		/* INPUT_PULLUP--> DDRA=0 */
							SET_BIT(PORTA,Loc_U8PinNum);	/* INPUT_PULLUP--> PORTA=1 */
							break;
						}
						case PORT_enumINPUT_EXTERNALPD:		/*Set the pin as an input with external PullDown*/
						{
							CLR_BIT(DDRA,Loc_U8PinNum);		/* INPUT_PULLUP--> DDRA=0 */
							CLR_BIT(PORTA,Loc_U8PinNum);	/* INPUT_PULLUP--> PORTA=0 */
							break;
						}
						case PORT_enumOUTPUT_HIGH:			/*Set the pin as an output with high value*/
						{
							SET_BIT(DDRA,Loc_U8PinNum);		/* OUTPUT_HIGH--> DDRA=1 */
							SET_BIT(PORTA,Loc_U8PinNum);	/* OUTPUT_HIGH--> PORTA=1 */
							break;
						}
						case PORT_enumOUTPUT_LOW:			/*Set the pin as an output with low value*/
						{
							SET_BIT(DDRA,Loc_U8PinNum);		/* OUTPUT_LOW--> DDRA=1 */
							CLR_BIT(PORTA,Loc_U8PinNum);	/* OUTPUT_LOW--> PORTA=0 */
							break;
						}
						default :
						break ;
					}
					break ;
				}
				
				case PORT_enumPortB:
				{
					
					/*Switch based on the pin configuration*/
					switch (PORT_PINcfg[i])
					{
						case PORT_enumINPUT_INTERNALPU:		/*Input with Internal pull-up enabled*/
						{
							CLR_BIT(DDRB,Loc_U8PinNum);		/* INPUT_PULLUP--> DDRB=0 */
							SET_BIT(PORTB,Loc_U8PinNum);	/* INPUT_PULLUP--> PORTB=1 */
							break;
						}
						case PORT_enumINPUT_EXTERNALPD:		/*Set the pin as an input with external PullDown*/
						{
							CLR_BIT(DDRB,Loc_U8PinNum);		/* INPUT_PULLUP--> DDRB=0 */
							CLR_BIT(PORTB,Loc_U8PinNum);	/* INPUT_PULLUP--> PORTB=0 */
							break;
						}
						case PORT_enumOUTPUT_HIGH:			/*Set the pin as an output with high value*/
						{
							SET_BIT(DDRB,Loc_U8PinNum);		/* OUTPUT_HIGH--> DDRB=1 */
							SET_BIT(PORTB,Loc_U8PinNum);	/* OUTPUT_HIGH--> PORTB=1 */
							break;
						}
						case PORT_enumOUTPUT_LOW:			/*Set the pin as an output with low value*/
						{
							SET_BIT(DDRB,Loc_U8PinNum);		/* OUTPUT_LOW--> DDRB=1 */
							CLR_BIT(PORTB,Loc_U8PinNum);	/* OUTPUT_LOW--> PORTB=0 */
							break;
						}
						default :
						break ;
					}
					break ;
				}
				case PORT_enumPortC:
				{
					/*Switch based on the pin configuration*/
					switch (PORT_PINcfg[i])
					{
						case PORT_enumINPUT_INTERNALPU:		/*Input with Internal pull-up enabled*/
						{
							CLR_BIT(DDRC,Loc_U8PinNum);		/* INPUT_PULLUP--> DDRC=0 */
							SET_BIT(PORTC,Loc_U8PinNum);	/* INPUT_PULLUP--> PORTC=1 */
							break;
						}
						case PORT_enumINPUT_EXTERNALPD:		/*Set the pin as an input with external PullDown*/
						{
							CLR_BIT(DDRC,Loc_U8PinNum);		/* INPUT_PULLUP--> DDRC=0 */
							CLR_BIT(PORTC,Loc_U8PinNum);	/* INPUT_PULLUP--> PORTC=0 */
							break;
						}
						case PORT_enumOUTPUT_HIGH:			/*Set the pin as an output with high value*/
						{
							SET_BIT(DDRC,Loc_U8PinNum);		/* OUTPUT_HIGH--> DDRC=1 */
							SET_BIT(PORTC,Loc_U8PinNum);	/* OUTPUT_HIGH--> PORTC=1 */
							break;
						}
						case PORT_enumOUTPUT_LOW:			/*Set the pin as an output with low value*/
						{
							SET_BIT(DDRC,Loc_U8PinNum);		/* OUTPUT_LOW--> DDRC=1 */
							CLR_BIT(PORTC,Loc_U8PinNum);	/* OUTPUT_LOW--> PORTC=0 */
							break;
						}
						default :
						break ;
					}
					break ;
				}
				case PORT_enumPortD:
				{
					/*Switch based on the pin configuration*/
					switch (PORT_PINcfg[i])
					{
						case PORT_enumINPUT_INTERNALPU:		/*Input with Internal pull-up enabled*/
						{
							CLR_BIT(DDRD,Loc_U8PinNum);		/* INPUT_PULLUP--> DDRD=0 */
							SET_BIT(PORTD,Loc_U8PinNum);	/* INPUT_PULLUP--> PORTD=1 */
							break;
						}
						case PORT_enumINPUT_EXTERNALPD:		/*Set the pin as an input with external PullDown*/
						{
							CLR_BIT(DDRD,Loc_U8PinNum);		/* INPUT_PULLUP--> DDRD=0 */
							CLR_BIT(PORTD,Loc_U8PinNum);	/* INPUT_PULLUP--> PORTD=0 */
							break;
						}
						case PORT_enumOUTPUT_HIGH:			/*Set the pin as an output with high value*/
						{
							SET_BIT(DDRD,Loc_U8PinNum);		/* OUTPUT_HIGH--> DDRD=1 */
							SET_BIT(PORTD,Loc_U8PinNum);	/* OUTPUT_HIGH--> PORTD=1 */
							break;
						}
						case PORT_enumOUTPUT_LOW:			/*Set the pin as an output with low value*/
						{
							SET_BIT(DDRD,Loc_U8PinNum);		/* OUTPUT_LOW--> DDRD=1 */
							CLR_BIT(PORTD,Loc_U8PinNum);	/* OUTPUT_LOW--> PORTD=0 */
							break;
						}
						default :
						break ;
					}
					break ;
				}
				default:
				break;
			}
			
			
			
		}
		
	}
	
	
	#endif
}


/***************************************************CONCAT TO SET DDR AND PORT Registers**********************************************************/

#define BINARY_HELPER_Eight(p7,p6,p5,p4,p3,p2,p1,p0)			((p7 << 7) | (p6 << 6) | (p5 << 5) | (p4 << 4) | (p3 << 3) | (p2 << 2) | (p1 << 1) | (p0))
#define CONCAT_HELPER_Eight(p7,p6,p5,p4,p3,p2,p1,p0)			BINARY_HELPER_Eight(p7,p6,p5,p4,p3,p2,p1,p0)
#define CONCAT_Eight(p7,p6,p5,p4,p3,p2,p1,p0)					CONCAT_HELPER_Eight(p7,p6,p5,p4,p3,p2,p1,p0)

#define BINARY_HELPER_Seven(p6,p5,p4,p3,p2,p1,p0)				((p6 << 6) | (p5 << 5) | (p4 << 4) | (p3 << 3) | (p2 << 2) | (p1 << 1) | (p0))
#define CONCAT_HELPER_Seven(p6,p5,p4,p3,p2,p1,p0)				BINARY_HELPER_Seven(p6,p5,p4,p3,p2,p1,p0)
#define CONCAT_Seven(p6,p5,p4,p3,p2,p1,p0)						CONCAT_HELPER_Seven(p6,p5,p4,p3,p2,p1,p0)

#define BINARY_HELPER_Six(p5,p4,p3,p2,p1,p0)					((p5 << 5) | (p4 << 4) | (p3 << 3) | (p2 << 2) | (p1 << 1) | (p0))
#define CONCAT_HELPER_Six(p5,p4,p3,p2,p1,p0)					BINARY_HELPER_Six(p5,p4,p3,p2,p1,p0)
#define CONCAT_Six(p5,p4,p3,p2,p1,p0)							CONCAT_HELPER_Six(p5,p4,p3,p2,p1,p0)

