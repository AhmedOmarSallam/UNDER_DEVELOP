/********************************************\
* Module       : Port Driver.
* FileName     : Port.c
* Version      : 1.0.0
* Author       : Ahmed Omar Sallam
* Description  :  
\********************************************/




#include"Port.h"
#include"Port_TM4C123GH6PM_Registers.h"
#include"Std_BitMath.h"







const static Port_ConfigType *Port_ConfigPtr = NULL_PTR;






/*==============================+-------------------------------+==============================*/
/*==============================|      Functions Defination     |==============================*/
/*==============================+-------------------------------+==============================*/



/*************************************************************************\
* Service Name       : Port_Init.                                         *
* Service ID [hex]   : 0x00.                                              *
* Sync/Async         : Synchronous.                                       *
* Reentrancy         : Non Reentrant.                                     *
* Parameters (in)    : (ConfigPtr) --> Pointer to configuration set.      *
* Parameters (inout) : None.                                              *
* Parameters (out)   : None.                                              *
* Return value       : None.                                              *
* Description        : Initializes the Port Driver module.                *
* Available via      : Dio.h                                              *
\*************************************************************************/

void Port_Init(const Port_ConfigType* ConfigPtr){

	
	
	volatile GPIO_TYPE *Loc_PortPtr = NULL_PTR;
	
	/* FOR TEST!!!!!! */
    uint8 Port_GPIO_PinItr = 30;		/* FOR TEST!!!!!! */

	
	

	/*  */
	Port_ConfigPtr = ConfigPtr;

//for(Port_GPIO_PinItr = 0; Port_GPIO_PinItr <= 42; Port_GPIO_PinItr++){
	


	/*-------	
	 * Assign the Loc_PortPtr to appropriate GPIO PORTn pointer to structure. 
	 *-----------------*/
    switch(Port_ConfigPtr[Port_GPIO_PinItr].PortType){
        case PORT_A:      Loc_PortPtr = GPIO_PORT_A_APB;   break;	 /* Use Loc_PortPtr to access PORT_A */
        case PORT_B:      Loc_PortPtr = GPIO_PORT_B_APB;   break;    /* Use Loc_PortPtr to access PORT_B */
        case PORT_C:      Loc_PortPtr = GPIO_PORT_C_APB;   break;    /* Use Loc_PortPtr to access PORT_C */
        case PORT_D:      Loc_PortPtr = GPIO_PORT_D_APB;   break;    /* Use Loc_PortPtr to access PORT_D */
        case PORT_E:      Loc_PortPtr = GPIO_PORT_E_APB;   break;    /* Use Loc_PortPtr to access PORT_E */
        case PORT_F:      Loc_PortPtr = GPIO_PORT_F_APB;   break;    /* Use Loc_PortPtr to access PORT_F */
//        case PORT_A_AHB:  Loc_PortPtr = GPIO_PORT_A_AHB;  /* Use Loc_PortPtr to access PORT_A_AHB */  break;
//        case PORT_B_AHB:  Loc_PortPtr = GPIO_PORT_B_AHB;  /* Use Loc_PortPtr to access PORT_B_AHB */  break;
//       case PORT_C_AHB:  Loc_PortPtr = GPIO_PORT_C_AHB;  /* Use Loc_PortPtr to access PORT_C_AHB */  break;
//        case PORT_D_AHB:  Loc_PortPtr = GPIO_PORT_D_AHB;  /* Use Loc_PortPtr to access PORT_D_AHB */  break;
//        case PORT_E_AHB:  Loc_PortPtr = GPIO_PORT_E_AHB;  /* Use Loc_PortPtr to access PORT_E_AHB */  break;
//        case PORT_F_AHB:  Loc_PortPtr = GPIO_PORT_F_AHB;  /* Use Loc_PortPtr to access PORT_F_AHB */  break;
        default: break;
    }
	
	
	
	
	
	/*-------
     * Check if the Port pin is configured as GPIO or alternate function pin.
	 * 
	 *-----------------*/
	if(PORT_PIN_MODE_DIO == Port_ConfigPtr[Port_GPIO_PinItr].PinMode){
		
		/* Configure the port pin to  */
		CLR_REG(Loc_PortPtr->GPIOAFSEL, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber);
			
	}else{
		
		/* Configure the Port pin to be an alternate function. */ 
		SET_REG(Loc_PortPtr->GPIOAFSEL, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber);
		
		/* Check what alternate function will be assigned to the Port Pin. */
		switch(Port_ConfigPtr[Port_GPIO_PinItr].PinMode){
		
			/* In case the pin is configured to be an PWM signal. */
			case PORT_PIN_MODE_PWM: 
				switch(Port_ConfigPtr[Port_GPIO_PinItr].PortType){
					case PORT_A:
		            case PORT_D:
		            case PORT_F:	
						Loc_PortPtr->GPIOPCTL |=((uint32)PORT_ENCODING_MUX_VALUE_5 << ((Port_ConfigPtr[Port_GPIO_PinItr].PinNumber)*4));
						break; 
			
		            case PORT_B:
		            case PORT_C: 
		            case PORT_E: 			
						Loc_PortPtr->GPIOPCTL |=((uint32)PORT_ENCODING_MUX_VALUE_4 << ((Port_ConfigPtr[Port_GPIO_PinItr].PinNumber)*4));	
						break; 
		            
					default:
						/* Do nothing. */
						break;
				}
				break;
				
					/*------------------------------------------------------------------*/
				
			/* In case the pin is configured to be an PWM signal. */				
			case PORT_PIN_MODE_QEI:
						Loc_PortPtr->GPIOPCTL |=((uint32)PORT_ENCODING_MUX_VALUE_6 << ((Port_ConfigPtr[Port_GPIO_PinItr].PinNumber)*4));	
				break;
			
					/*------------------------------------------------------------------*/			
			
			case PORT_PIN_MODE_UART:
				
					if((Port_ConfigPtr[Port_GPIO_PinItr].PortType == PORT_C && Port_ConfigPtr[Port_GPIO_PinItr].PinNumber == PORT_C_PIN_4)\
						|| (Port_ConfigPtr[Port_GPIO_PinItr].PortType == PORT_C && Port_ConfigPtr[Port_GPIO_PinItr].PinNumber == PORT_C_PIN_5)){
						
							Loc_PortPtr->GPIOPCTL |=((uint32)PORT_ENCODING_MUX_VALUE_2 << ((Port_ConfigPtr[Port_GPIO_PinItr].PinNumber)*4));	
						
						}else{
							Loc_PortPtr->GPIOPCTL |=((uint32)PORT_ENCODING_MUX_VALUE_1 << ((Port_ConfigPtr[Port_GPIO_PinItr].PinNumber)*4));	
						}
				
				break;
						
					/*------------------------------------------------------------------*/			

				
		
			default: break;
		}
		
		
	}
	
	
	/*************************************************************************************************************/
		
	
	/*-------	
	 * Set the pin direction to either input or output. 
	 *--------------*/
	if(PORT_PIN_MODE_DIO == Port_ConfigPtr[Port_GPIO_PinItr].PinMode){
						
		/* Set the pin direction to either input or output. */
		switch(Port_ConfigPtr[Port_GPIO_PinItr].PinDirection){
			
			/* Port Pin is input. */
			case PORT_PIN_IN:  
				CLR_REG(Loc_PortPtr -> GPIODIR, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber); 
			break;	  
			
			/* Port Pin is output. */
			case PORT_PIN_OUT: 
				
				/* Set the pin direction as output. */
				SET_REG(Loc_PortPtr -> GPIODIR, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber); 
			
				/* [SWS_Port_00055] 
				 * Ensures that the default level is immediately output on the port pin when it is set to an output port pin.
				 */
				switch(Port_ConfigPtr[Port_GPIO_PinItr].PortPinLevelValue){
					case PORT_PIN_LEVEL_LOW:  CLR_REG(Loc_PortPtr -> GPIODATA, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber);   break;
					case PORT_PIN_LEVEL_HIGH: SET_REG(Loc_PortPtr -> GPIODATA, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber);   break;
					default: /* Do nothing. */                                                 break;
			
				}
			
		    break; 
			
		default: /* Do nothing. */     break;
		
		}		
		
		}else{
			/* Do nothing. */
		}
	
	
	
	/*************************************************************************************************************/
	
	
	/*-------
     * Switch on the Port pin to either enabaling or disabling the digital function of the corresponding pin. 
	 *--------------*/
	switch(Port_ConfigPtr[Port_GPIO_PinItr].PinMode){
		
		case PORT_PIN_MODE_DIO:
		case PORT_PIN_MODE_PWM:
		case PORT_PIN_MODE_QEI:	
		case PORT_PIN_MODE_UART:				
			
			/* Enable the digital functionality of the pin. */
			SET_REG(Loc_PortPtr -> GPIODEN, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber); 	
		break;
		
		
		default:
					
		    /* Disable the digital functionality of the pin. */
			CLR_REG(Loc_PortPtr -> GPIODEN, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber);
		break; 				
	
	
	}
	
	
	/*************************************************************************************************************/
	
	
	Port_GPIO_PinItr = 39;	

	/*-------	
	 * Assign the Loc_PortPtr to appropriate GPIO PORTn pointer to structure. 
	 *-----------------*/
    switch(Port_ConfigPtr[Port_GPIO_PinItr].PortType){
        case PORT_A:      Loc_PortPtr = GPIO_PORT_A_APB;   break;	 /* Use Loc_PortPtr to access PORT_A */
        case PORT_B:      Loc_PortPtr = GPIO_PORT_B_APB;   break;    /* Use Loc_PortPtr to access PORT_B */
        case PORT_C:      Loc_PortPtr = GPIO_PORT_C_APB;   break;    /* Use Loc_PortPtr to access PORT_C */
        case PORT_D:      Loc_PortPtr = GPIO_PORT_D_APB;   break;    /* Use Loc_PortPtr to access PORT_D */
        case PORT_E:      Loc_PortPtr = GPIO_PORT_E_APB;   break;    /* Use Loc_PortPtr to access PORT_E */
        case PORT_F:      Loc_PortPtr = GPIO_PORT_F_APB;   break;    /* Use Loc_PortPtr to access PORT_F */
//        case PORT_A_AHB:  Loc_PortPtr = GPIO_PORT_A_AHB;  /* Use Loc_PortPtr to access PORT_A_AHB */  break;
//        case PORT_B_AHB:  Loc_PortPtr = GPIO_PORT_B_AHB;  /* Use Loc_PortPtr to access PORT_B_AHB */  break;
//       case PORT_C_AHB:  Loc_PortPtr = GPIO_PORT_C_AHB;  /* Use Loc_PortPtr to access PORT_C_AHB */  break;
//        case PORT_D_AHB:  Loc_PortPtr = GPIO_PORT_D_AHB;  /* Use Loc_PortPtr to access PORT_D_AHB */  break;
//        case PORT_E_AHB:  Loc_PortPtr = GPIO_PORT_E_AHB;  /* Use Loc_PortPtr to access PORT_E_AHB */  break;
//        case PORT_F_AHB:  Loc_PortPtr = GPIO_PORT_F_AHB;  /* Use Loc_PortPtr to access PORT_F_AHB */  break;
        default: break;
    }
	
	
	
	
	
	/*-------
     * Check if the Port pin is configured as GPIO or alternate function pin.
	 * 
	 *-----------------*/
	if(PORT_PIN_MODE_DIO == Port_ConfigPtr[Port_GPIO_PinItr].PinMode){
		
		/* Configure the port pin to  */
		CLR_REG(Loc_PortPtr->GPIOAFSEL, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber);
			
	}else{
		
		/* Configure the Port pin to be an alternate function. */ 
		SET_REG(Loc_PortPtr->GPIOAFSEL, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber);
		
		/* Check what alternate function will be assigned to the Port Pin. */
		switch(Port_ConfigPtr[Port_GPIO_PinItr].PinMode){
		
			/* In case the pin is configured to be an PWM signal. */
			case PORT_PIN_MODE_PWM: 
				switch(Port_ConfigPtr[Port_GPIO_PinItr].PortType){
					case PORT_A:
		            case PORT_D:
		            case PORT_F:	
						Loc_PortPtr->GPIOPCTL |=((uint32)PORT_ENCODING_MUX_VALUE_5 << ((Port_ConfigPtr[Port_GPIO_PinItr].PinNumber)*4));
						break; 
			
		            case PORT_B:
		            case PORT_C: 
		            case PORT_E: 			
						Loc_PortPtr->GPIOPCTL |=((uint32)PORT_ENCODING_MUX_VALUE_4 << ((Port_ConfigPtr[Port_GPIO_PinItr].PinNumber)*4));	
						break; 
		            
					default:
						/* Do nothing. */
						break;
				}
				break;
				
					/*------------------------------------------------------------------*/
				
			/* In case the pin is configured to be an PWM signal. */				
			case PORT_PIN_MODE_QEI:
						Loc_PortPtr->GPIOPCTL |=((uint32)PORT_ENCODING_MUX_VALUE_6 << ((Port_ConfigPtr[Port_GPIO_PinItr].PinNumber)*4));	
				break;
			
					/*------------------------------------------------------------------*/			
			
			case PORT_PIN_MODE_UART:
				
					if((Port_ConfigPtr[Port_GPIO_PinItr].PortType == PORT_C && Port_ConfigPtr[Port_GPIO_PinItr].PinNumber == PORT_C_PIN_4)\
						|| (Port_ConfigPtr[Port_GPIO_PinItr].PortType == PORT_C && Port_ConfigPtr[Port_GPIO_PinItr].PinNumber == PORT_C_PIN_5)){
						
							Loc_PortPtr->GPIOPCTL |=((uint32)PORT_ENCODING_MUX_VALUE_2 << ((Port_ConfigPtr[Port_GPIO_PinItr].PinNumber)*4));	
						
						}else{
							Loc_PortPtr->GPIOPCTL |=((uint32)PORT_ENCODING_MUX_VALUE_1 << ((Port_ConfigPtr[Port_GPIO_PinItr].PinNumber)*4));	
						}
				
				break;
						
					/*------------------------------------------------------------------*/			

				
		
			default: break;
		}
		
		
	}
	
	
	/*************************************************************************************************************/
		
	
	/*-------	
	 * Set the pin direction to either input or output. 
	 *--------------*/
	if(PORT_PIN_MODE_DIO == Port_ConfigPtr[Port_GPIO_PinItr].PinMode){
						
		/* Set the pin direction to either input or output. */
		switch(Port_ConfigPtr[Port_GPIO_PinItr].PinDirection){
			
			/* Port Pin is input. */
			case PORT_PIN_IN:  
				CLR_REG(Loc_PortPtr -> GPIODIR, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber); 
			break;	  
			
			/* Port Pin is output. */
			case PORT_PIN_OUT: 
				
				/* Set the pin direction as output. */
				SET_REG(Loc_PortPtr -> GPIODIR, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber); 
			
				/* [SWS_Port_00055] 
				 * Ensures that the default level is immediately output on the port pin when it is set to an output port pin.
				 */
				switch(Port_ConfigPtr[Port_GPIO_PinItr].PortPinLevelValue){
					case PORT_PIN_LEVEL_LOW:  CLR_REG(Loc_PortPtr -> GPIODATA, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber);   break;
					case PORT_PIN_LEVEL_HIGH: SET_REG(Loc_PortPtr -> GPIODATA, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber);   break;
					default: /* Do nothing. */                                                 break;
			
				}
			
		    break; 
			
		default: /* Do nothing. */     break;
		
		}		
		
		}else{
			/* Do nothing. */
		}
	
	
	
	/*************************************************************************************************************/
	
	
	/*-------
     * Switch on the Port pin to either enabaling or disabling the digital function of the corresponding pin. 
	 *--------------*/
	switch(Port_ConfigPtr[Port_GPIO_PinItr].PinMode){
		
		case PORT_PIN_MODE_DIO:
		case PORT_PIN_MODE_PWM:
		case PORT_PIN_MODE_QEI:	
		case PORT_PIN_MODE_UART:				
			
			/* Enable the digital functionality of the pin. */
			SET_REG(Loc_PortPtr -> GPIODEN, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber); 	
		break;
		
		
		default:
					
		    /* Disable the digital functionality of the pin. */
			CLR_REG(Loc_PortPtr -> GPIODEN, Port_ConfigPtr[Port_GPIO_PinItr].PinNumber);
		break; 				
	
	
	}
	
	
	/*************************************************************************************************************/
	
	
	
	
}


	

//}


/*777777777777777777&&&&&&&&&&&&&&&&&&&&&&7*/
	

























































/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/
					/*----------------------------------------------------------------------------------------------*/
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^*/







/* [ECUC_Port_00131] */
#if(STD_ON == PortSetPinDirectionApi)


/*************************************************************************\
* Service Name       : Port_SetPinDirection.                              *
* Service ID [hex]   : 0x01.                                              *
* Sync/Async         : Synchronous.                                       *
* Reentrancy         : Reentrant.                                         *
* Parameters (in)    : (Pin)       --> Port Pin ID number.                *
*                      (Direction) --> Port Pin Direction                 *
* Parameters (inout) : None.                                              *
* Parameters (out)   : None.                                              *
* Return value       : None.                                              *
* Description        : Sets the port pin direction.                       *
* Available via      : Dio.h                                              *
\*************************************************************************/

void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction){

	volatile GPIO_TYPE *Loc_PortPtr = NULL_PTR;
	uint8 PinNumber;
	
	
	/*-------	
	 * Assign the Loc_PortPtr to appropriate GPIO PORTn pointer to structure. 
	 *-----------------*/	
	switch(Pin){
		
		/* PORTA Pins */
		case PA0:	case PA1:	case PA2:	case PA3:	case PA4:	case PA5:	case PA6:	case PA7:
			Loc_PortPtr = GPIO_PORT_A_APB;		PinNumber = Pin - PA0;		break;

		/* PORTB Pins */
		case PB0:	case PB1:	case PB2:	case PB3:	case PB4:	case PB5:	case PB6:	case PB7:
			Loc_PortPtr = GPIO_PORT_B_APB;		PinNumber = Pin - PB0;		break;

		/* PORTC Pins */
		case PC0:	case PC1:	case PC2:	case PC3:	case PC4:	case PC5:	case PC6:	case PC7:
			Loc_PortPtr = GPIO_PORT_C_APB;		PinNumber = Pin - PC0;		break;

		/* PORTD Pins */
		case PD0:	case PD1:	case PD2:	case PD3:	case PD4:	case PD5:	case PD6:	case PD7:
			Loc_PortPtr = GPIO_PORT_D_APB;		PinNumber = Pin - PD0;		break;

		/* PORTE Pins */
		case PE0:	case PE1:	case PE2:	case PE3:	case PE4:	case PE5:
			Loc_PortPtr = GPIO_PORT_E_APB;		PinNumber = Pin - PE0;		break;

		/* PORTF Pins */
		case PF0:	case PF1:	case PF2:	case PF3:	case PF4:	
			Loc_PortPtr = GPIO_PORT_F_APB;		PinNumber = Pin - PF0;		break;
		
		default: /* Do nothing. */											break;
			
	}
	
	
	/*-------	
	 * Set the pin direction to either input or output. 
	 *--------------*/
						
	/* Set the pin direction to either input or output. */
	switch(Direction){
		
		/* Port Pin is input. */
		case PORT_PIN_IN:  
			
			CLR_REG(Loc_PortPtr -> GPIODIR, PinNumber); 	break;	  
		
		/* Port Pin is output. */
		case PORT_PIN_OUT: 
			
			SET_REG(Loc_PortPtr -> GPIODIR, PinNumber); 	break; 
		
	default: /* Do nothing. */     break;

	}

		
}

#endif





 

#if (STD_ON == PortSetPinModeApi)

/* [SWS_Port_00145] */

void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode){

		volatile GPIO_TYPE *Loc_PortPtr = NULL_PTR;
	uint8 PinNumber;
	
	
	/*-------	
	 * Assign the Loc_PortPtr to appropriate GPIO PORTn pointer to structure. 
	 *-----------------*/	
	switch(Pin){
		
		/* PORTA Pins */
		case PA0:	case PA1:	case PA2:	case PA3:	case PA4:	case PA5:	case PA6:	case PA7:
			Loc_PortPtr = GPIO_PORT_A_APB;		PinNumber = Pin - PA0;		break;

		/* PORTB Pins */
		case PB0:	case PB1:	case PB2:	case PB3:	case PB4:	case PB5:	case PB6:	case PB7:
			Loc_PortPtr = GPIO_PORT_B_APB;		PinNumber = Pin - PB0;		break;

		/* PORTC Pins */
		case PC0:	case PC1:	case PC2:	case PC3:	case PC4:	case PC5:	case PC6:	case PC7:
			Loc_PortPtr = GPIO_PORT_C_APB;		PinNumber = Pin - PC0;		break;

		/* PORTD Pins */
		case PD0:	case PD1:	case PD2:	case PD3:	case PD4:	case PD5:	case PD6:	case PD7:
			Loc_PortPtr = GPIO_PORT_D_APB;		PinNumber = Pin - PD0;		break;

		/* PORTE Pins */
		case PE0:	case PE1:	case PE2:	case PE3:	case PE4:	case PE5:
			Loc_PortPtr = GPIO_PORT_E_APB;		PinNumber = Pin - PE0;		break;

		/* PORTF Pins */
		case PF0:	case PF1:	case PF2:	case PF3:	case PF4:	
			Loc_PortPtr = GPIO_PORT_F_APB;		PinNumber = Pin - PF0;		break;
		
		default: /* Do nothing. */											break;
			
	}
	
	
	
	
	
	/*-------
     * Check if the Port pin is configured as GPIO or alternate function pin.
	 * 
	 *-----------------*/
	if(PORT_PIN_MODE_DIO == Mode){
		
		/* Configure the port pin to  */
		CLR_REG(Loc_PortPtr->GPIOAFSEL, PinNumber);
			
	}else{
		
		/* Configure the Port pin to be an alternate function. */ 
		SET_REG(Loc_PortPtr->GPIOAFSEL, PinNumber);
		
		/* Check what alternate function will be assigned to the Port Pin. */
		switch(Mode){
		
			/* In case the pin is configured to be an PWM signal. */
			case PORT_PIN_MODE_PWM: 
				switch(Pin){
					
						case PA6:	case PA7:	case PF0:	case PF1:	case PF2:	case PF3:								
						Loc_PortPtr->GPIOPCTL |= ((uint32)PORT_ENCODING_MUX_VALUE_5 << (PinNumber * 4));			break; 
			
					case PB4:	case PB5:	case PB6:	case PB7:	case PC4:	case PC5:	
			
						Loc_PortPtr->GPIOPCTL |=((uint32)PORT_ENCODING_MUX_VALUE_4 << (PinNumber * 4));	
					/*---->*/           /*Write somecode!!!*/
						break; 
					
		            case PD0:	case PD1:	case PE4:	case PE5:
						/* Do something. */
						break;
					
					default:
						/* Do nothing. */
						break;
				}
				break;
				
					/*------------------------------------------------------------------*/
				
			/* In case the pin is configured to be an QEI signal. */				
			case PORT_PIN_MODE_QEI:
						Loc_PortPtr->GPIOPCTL |=((uint32)PORT_ENCODING_MUX_VALUE_6 << (PinNumber * 4) );	
				break;
			
					/*------------------------------------------------------------------*/			
			
			case PORT_PIN_MODE_UART:
				
					if((Pin == PC4) || (Pin == PC4)){
						
							Loc_PortPtr->GPIOPCTL |=((uint32)PORT_ENCODING_MUX_VALUE_2 << (PinNumber * 4));	
						
					}else{
							Loc_PortPtr->GPIOPCTL |=((uint32)PORT_ENCODING_MUX_VALUE_1 << (PinNumber * 4));	
					}
				
				break;
						
					/*------------------------------------------------------------------*/			

					
			default: break;
		}
		
		
	}
	
	
	
	
	
}

#endif




