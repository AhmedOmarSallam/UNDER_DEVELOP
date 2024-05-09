/********************************************\
* @Module       : PWM Driver.
* @FileName     : Pwm.c
* @Version      : 1.0.0
* @Author       : Ahmed Omar Sallam
* @Description  :  
\********************************************/


#include"Pwm.h"
#include"tm4c123gh6pm_registers.h"
#include"Std_BitMath.h"



const static Pwm_ConfigType *Pwm_ConfigPtr = NULL_PTR;



/*=========================+-------------------------------+=========================*/
/*=========================|      Functions Defination     |=========================*/
/*=========================+-------------------------------+=========================*/



/*************************************************************************\
* Service Name       : Pwm_Init.                                          *
* Service ID [hex]   : 0x00.                                              *
* Sync/Async         : Synchronous.                                       *
* Reentrancy         : Non Reentrant.                                     *
* Parameters (in)    : (ConfigPtr) --> Pointer to configuration set.      *
* Parameters (inout) : None.                                              *
* Parameters (out)   : None.                                              *
* Return value       : None.                                              *
* Description        : Service for PWM initialization.                    *
* Available via      : Pwm.h                                              *
\*************************************************************************/

void Pwm_Init(const Pwm_ConfigType* ConfigPtr){

	
	/* Iterator for the PWM channels. */
	uint8 Pwm_ChannelIterator = 0;
	
    volatile PWM_TYPE *PWM_ModulePtr   = NULL_PTR;
	
	volatile uint32 *PWMnCTL_Ptr   = NULL_PTR;
	volatile uint32 *PWMnLOAD_Ptr  = NULL_PTR;
	volatile uint32 *PWMnCMPA_Ptr  = NULL_PTR;
	volatile uint32 *PWMnCMPB_Ptr  = NULL_PTR;
	volatile uint32 *PWMnGENA_Ptr  = NULL_PTR;
	volatile uint32 *PWMnGENB_Ptr  = NULL_PTR;
		
	 	
	
//	volatile uint32 *PWMnCOUNT_Ptr = NULL_PTR;


		
	Pwm_ConfigPtr = ConfigPtr;


/*	for(Pwm_ChannelIterator = 0; Pwm_ChannelIterator <= 15; Pwm_ChannelIterator++){*/

	
     /*----
      * Assigning the PWM_ModulePtr pointer to a specific PWM module structure based on the PWM configuration structure.
      * The structure containing the memory addresses of the PWM registers of each module.
      *----------------*/	
	switch(Pwm_ConfigPtr[Pwm_ChannelIterator].PwmModuleNumber){
	
		case PWM_MODULE0: PWM_ModulePtr = PWM_M0;    break;
		case PWM_MODULE1: PWM_ModulePtr = PWM_M1;    break;
		default: /* Do nothing. */                   break;
	
	}

	
	/*************************************************************************************************************/

     /*----
	  * Assigns pointers to control, load, compare A, and compare B registers 
	  * based on the PWM channel number for the corresponding PWM generator block.
      *----------------*/	
	switch(Pwm_ConfigPtr[Pwm_ChannelIterator].PwmChannelNumber){
		
		
		/* PWM Generator 0 block. */
		case PWM_MnPWM0:
		case PWM_MnPWM1:			
			PWMnCTL_Ptr   = &(PWM_ModulePtr->PWM0CTL);
			PWMnLOAD_Ptr  = &(PWM_ModulePtr->PWM0LOAD);
			PWMnCMPA_Ptr  = &(PWM_ModulePtr->PWM0CMPA);	
			PWMnCMPB_Ptr  = &(PWM_ModulePtr->PWM0CMPB);

		break;
		
		
		/* PWM Generator 1 block. */
		case PWM_MnPWM2:
		case PWM_MnPWM3:			
			PWMnCTL_Ptr   = &(PWM_ModulePtr->PWM1CTL);
			PWMnLOAD_Ptr  = &(PWM_ModulePtr->PWM1LOAD);
			PWMnCMPA_Ptr  = &(PWM_ModulePtr->PWM1CMPA);	
			PWMnCMPB_Ptr  = &(PWM_ModulePtr->PWM1CMPB);

		break;		
		
		
		/* PWM Generator 2 block. */
		case PWM_MnPWM4:
		case PWM_MnPWM5:			
			PWMnCTL_Ptr   = &(PWM_ModulePtr->PWM2CTL);
			PWMnLOAD_Ptr  = &(PWM_ModulePtr->PWM2LOAD);
			PWMnCMPA_Ptr  = &(PWM_ModulePtr->PWM2CMPA);	
			PWMnCMPB_Ptr  = &(PWM_ModulePtr->PWM2CMPB);

		break;		


		/* PWM Generator 3 block. */
		case PWM_MnPWM6:
		case PWM_MnPWM7:			
			PWMnCTL_Ptr   = &(PWM_ModulePtr->PWM3CTL);
			PWMnLOAD_Ptr  = &(PWM_ModulePtr->PWM3LOAD);
			PWMnCMPA_Ptr  = &(PWM_ModulePtr->PWM3CMPA);	
			PWMnCMPB_Ptr  = &(PWM_ModulePtr->PWM3CMPB);

		break;			
		
		
		default:
			/* Do nothing. */
		break;
	
	}
	
	
	/*************************************************************************************************************/

	
     /*----
	  * Assigns pointers to the control registers (GENA or GENB) 
	  * based on the PWM channel number for the corresponding PWM generator block.
      *----------------*/	
	switch(Pwm_ConfigPtr[Pwm_ChannelIterator].PwmChannelNumber){
		
		case PWM_MnPWM0:	PWMnGENA_Ptr  = &(PWM_ModulePtr->PWM0GENA);	break;
		case PWM_MnPWM2:	PWMnGENA_Ptr  = &(PWM_ModulePtr->PWM1GENA);	break;
		case PWM_MnPWM4:	PWMnGENA_Ptr  = &(PWM_ModulePtr->PWM2GENA);	break;
		case PWM_MnPWM6:	PWMnGENA_Ptr  = &(PWM_ModulePtr->PWM3GENA);	break;
		
		case PWM_MnPWM1:	PWMnGENA_Ptr  = &(PWM_ModulePtr->PWM0GENB);	break;
		case PWM_MnPWM3:	PWMnGENA_Ptr  = &(PWM_ModulePtr->PWM1GENB);	break;
		case PWM_MnPWM5:	PWMnGENA_Ptr  = &(PWM_ModulePtr->PWM2GENB);	break;
		case PWM_MnPWM7:	PWMnGENA_Ptr  = &(PWM_ModulePtr->PWM3GENB);	break;

		default: 	/* Do nothing. */									break;
		
	}
	

	/*************************************************************************************************************/
	
     /*----	
	  * Enale the generator. 
      *----------------*/	
	
	SET_REG(*(PWMnCTL_Ptr), PWM_BLOCK_ENABLE_BIT);
	

	
	/*************************************************************************************************************/

	
     /*----	
	  * Enable the PWM Output signal. 
      *----------------*/	
	SET_REG(PWM_ModulePtr->PWMENABLE, ConfigPtr[Pwm_ChannelIterator].PwmChannelNumber);
	
	
	/*************************************************************************************************************/

	
	
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/	
	
	
	
	



	
	
	
	
	
	
	
	
	
	
    /*----
	* NOTE!!!
	* THIS SECTION IS FOR CONFIGURATION OF THE CLOCK WHICH SHOULD BE IN THE MCU DRIVER!!!!
    * ......!!!!
    *----------------*/	
//    SET_REG(RCGCPWM, ConfigPtr[Loc_itr].PwmModuleNumber);
	
	
	*(PWMnLOAD_Ptr) |=  0x63F;
//	*(PWMnCMPB_Ptr) |=  0x000;
	*(PWMnGENB_Ptr) |=  0x80C;

	
	/* Configure the counter mode. */
//	switch(ConfigPtr[Loc_itr].PwmCounterMode){
//		case PWM_COUNT_DOWN:    CLR_REG(*(PWMnCTL_Ptr), PWM_COUNTER_MODE_BIT); break;
//		case PWM_COUNT_UP_DOWN: SET_REG(*(PWMnCTL_Ptr), PWM_COUNTER_MODE_BIT); break;
//		default: /* Do nothing. */                                             break;
//	}
	
	
	
	
    /*----
	 * Assign a default polarity for each PWM signal.
     * 
     *----------------*/	
//	switch(ConfigPtr[Pwm_ChannelIterator].PwmDefaultPolarity){
							          
//		case PWM_ACTIVE_LOW:   SET_REG(PWM_ModulePtr->PWMINVERT, ConfigPtr[Pwm_ChannelIterator].PwmModuleNumber);  break;
//		case PWM_ACTIVE_HIGH:  CLR_REG(PWM_ModulePtr->PWMINVERT, ConfigPtr[Pwm_ChannelIterator].PwmModuleNumber);  break;
//		default:    /* Do nothing. */              break;
	
//	}
	
	








/*	}*/

		

}




/************************************************************************\
* Service Name      : Pwm_SetDutyCycle.                                  *
* Service ID [hex]  : 0x02.                                              *
* Sync/Async        : Asynchronous.                                      *
* Reentrancy        : Reentrant.                                         *
* Parameters (in)   : (ChannelNumber) --> Numeric identifier of the PWM. *
*                     (DutyCycle)     -->                                *
* Parameters (inout): None.                                              *
* Parameters (out)  : None.                                              *
* Return value      : None.                                              *
* Description       : Service sets the duty cycle of the PWM channel.    *
* Available via     : Pwm.h                                              *
\************************************************************************/

/* [SWS_Pwm_20082] */
#if(STD_ON == PWM_SET_DUTY_CYCLE_AP)

void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle){

	volatile uint32 i = 0;
	uint16 AbslouteDutyCycle = DutyCycle;
	volatile PWM_TYPE *ModulePtr = NULL_PTR;
	
//	volatile uint32 *PWMnCTL_Ptr   = NULL_PTR;
//	volatile uint32 *PWMnLOAD_Ptr  = NULL_PTR;
//	volatile uint32 *PWMnCOUNT_Ptr = NULL_PTR;
	volatile uint32 *PWMnCMPA_Ptr  = NULL_PTR;
	volatile uint32 *PWMnCMPB_Ptr  = NULL_PTR;
	volatile uint32 *PWMnGENA_Ptr  = NULL_PTR;
	volatile uint32 *PWMnGENB_Ptr  = NULL_PTR;
	
	
	if(ChannelNumber >= 0 && ChannelNumber <= 7){
		
		ModulePtr = PWM_M0;
	}else if(ChannelNumber > 7 && ChannelNumber <= 15){
	
		ModulePtr = PWM_M1;
	}else{
		/* Do nothing. */
	}
	
		
	
	
	switch(ChannelNumber){
		
		case PWM_M0PWM0_CHANNEL: 
		case PWM_M0PWM1_CHANNEL: 
		case PWM_M1PWM0_CHANNEL: 
		case PWM_M1PWM1_CHANNEL: 
			
//			PWMnCTL_Ptr   = &(ModulePtr->PWM0CTL);
//			PWMnLOAD_Ptr  = &(ModulePtr->PWM0LOAD);
//			PWMnCOUNT_Ptr = &(ModulePtr->PWM0COUNT);
			PWMnCMPA_Ptr  = &(ModulePtr->PWM0CMPA);
			PWMnCMPB_Ptr  = &(ModulePtr->PWM0CMPB);

//		if(PWM_MOPWM0_CHANNEL == ChannelNumber || PWM_M1PWM0_CHANNEL == ChannelNumber){
						
//			PWMnCMPA_Ptr  = &(ModulePtr->PWM0CMPA);
//			*(PWMnCMPA_Ptr) = 
//		}else if(PWM_MOPWM1_CHANNEL == ChannelNumber || PWM_M1PWM1_CHANNEL == ChannelNumber){ 
//			PWMnCMPB_Ptr  = &(ModulePtr->PWM0CMPB);
//		}else{
			/* Do nothig. */
//		}
		break;
		
		
		case PWM_M0PWM2_CHANNEL: 
		case PWM_M0PWM3_CHANNEL: 
		case PWM_M1PWM2_CHANNEL: 
		case PWM_M1PWM3_CHANNEL: 
			
//			PWMnCTL_Ptr   = &(ModulePtr->PWM1CTL);
//			PWMnLOAD_Ptr  = &(ModulePtr->PWM1LOAD);
//			PWMnCOUNT_Ptr = &(ModulePtr->PWM1COUNT);
			PWMnCMPA_Ptr  = &(ModulePtr->PWM1CMPA);	
			PWMnCMPB_Ptr  = &(ModulePtr->PWM1CMPB);		
			PWMnGENA_Ptr  = &(ModulePtr->PWM1GENA);		
			PWMnGENB_Ptr  = &(ModulePtr->PWM1GENB);	
			
		break;
		
		case PWM_M0PWM4_CHANNEL: 
		case PWM_M0PWM5_CHANNEL: 
		case PWM_M1PWM4_CHANNEL: 
		case PWM_M1PWM5_CHANNEL: 
			
//			PWMnCTL_Ptr   = &(ModulePtr->PWM2CTL);
//			PWMnLOAD_Ptr  = &(ModulePtr->PWM2LOAD);	
//			PWMnCOUNT_Ptr = &(ModulePtr->PWM2COUNT);
			PWMnCMPA_Ptr  = &(ModulePtr->PWM2CMPA);	
			PWMnCMPB_Ptr  = &(ModulePtr->PWM2CMPB);		
			PWMnGENA_Ptr  = &(ModulePtr->PWM2GENA);		
			PWMnGENB_Ptr  = &(ModulePtr->PWM2GENB);		
			
		break;
		
		
		case PWM_M0PWM6_CHANNEL: 
		case PWM_M0PWM7_CHANNEL: 
		case PWM_M1PWM6_CHANNEL: 
		case PWM_M1PWM7_CHANNEL: 
			
//			PWMnCTL_Ptr   = &(ModulePtr->PWM3CTL);
//			PWMnLOAD_Ptr  = &(ModulePtr->PWM3LOAD);
//			PWMnCOUNT_Ptr = &(ModulePtr->PWM3COUNT);
			PWMnCMPA_Ptr  = &(ModulePtr->PWM3CMPA);	
			PWMnCMPB_Ptr  = &(ModulePtr->PWM3CMPB);				
			PWMnGENA_Ptr  = &(ModulePtr->PWM3GENA);		
			PWMnGENB_Ptr  = &(ModulePtr->PWM3GENB);		
			
		break;		
	
		default: 
			/* Do nothing. */
		break;
	
	}
	
	
	
	switch(ChannelNumber){
		
			case PWM_M0PWM0_CHANNEL: 
			case PWM_M0PWM2_CHANNEL: 
			case PWM_M0PWM4_CHANNEL: 
			case PWM_M0PWM6_CHANNEL: 
				
			case PWM_M1PWM0_CHANNEL: 
			case PWM_M1PWM2_CHANNEL: 
			case PWM_M1PWM4_CHANNEL: 
			case PWM_M1PWM6_CHANNEL: 
				
			*(PWMnCMPA_Ptr) = ((uint32)(AbslouteDutyCycle * 0x63F)) >>15;
			
			PWMnGENA_Ptr  = &(ModulePtr->PWM0GENA);
				
			break;
			
			
			
			case PWM_M0PWM1_CHANNEL: 
			case PWM_M0PWM3_CHANNEL: 
			case PWM_M0PWM5_CHANNEL: 
			case PWM_M0PWM7_CHANNEL: 
				
			case PWM_M1PWM1_CHANNEL: 
			case PWM_M1PWM3_CHANNEL: 
			case PWM_M1PWM5_CHANNEL: 
			case PWM_M1PWM7_CHANNEL: 
				
			*(PWMnCMPB_Ptr) = DutyCycle;

			
	//		PWMnGENB_Ptr  = &(ModulePtr->PWM0GENA);
	//		*(PWMnGENB_Ptr) |=  0x80C;

				
			break;
			


	
		
	}
	
	
	

}

#endif




