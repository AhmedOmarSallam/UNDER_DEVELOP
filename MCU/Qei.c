#include"Qei.h"
#include"Std_Types.h"
#include"Std_BitMath.h"
#include"Qei_TM4C123GH6PM_Registers.h"



static const Qei_ConfigType* Qei_ConfigPtr = NULL_PTR;







/*=========================+-------------------------------+=========================*/
/*=========================|      Functions Defination     |=========================*/
/*=========================+-------------------------------+=========================*/



void Qie_Init(const Qei_ConfigType* ConfigPtr){

	/* Iterator Variable to iterate over the QEI modules. */
	uint8 Qei_ModuleItrator = 0;
	
	volatile QEI_TYPE* Qei_ModulePtr = NULL_PTR;
	
	
	Qei_ConfigPtr = ConfigPtr;
	
	
	
//for(Qei_ModuleItr; Qei_ModuleItr <= 1; Qei_ModuleItr++){
	
	
//}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*--------
	 * Enabaling the the QEI module.
	 *------------------*/
	SET_REG(Qei_ModulePtr->QEICTL, QEI_ENABLE_BIT);
	
	
	
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++=*/	
	
	
	
	/*************************************************************************************************************/
	
	
	/*--------
	 * Select the base address of the QEI module based on the QeiModuleNumber in the configuration.
	 *------------------*/
	switch(Qei_ConfigPtr[Qei_ModuleItrator].QeiModuleNumber){
	
		case QEI_MODULE_0: Qei_ModulePtr = QEI0; break;
		case QEI_MODULE_1: Qei_ModulePtr = QEI0; break;
		default: break;		
	
	}
	
	
	/*************************************************************************************************************/
	
	
	/*--------
	 * Select the Mode of operation of the QEI module based on the QeiMode in the configuration.
	 *------------------*/	
	switch(Qei_ConfigPtr[Qei_ModuleItrator].QeiMode){
			
		/* The internal PhA and PhB signals operate as quadrature phase signals. */
		case QEI_QUADRATURE_PHASE_MODE : 	CLR_REG(Qei_ModulePtr->QEICTL, QEI_SIGNAL_MODE_BIT); 	break;
		
		
		/* The internal PhA input operates as the clock (CLK) signal and the internal 
		 * PhB input operates as the direction (DIR) signal */	
	    case QEI_CLOCK_DIRECTION_MODE  :    SET_REG(Qei_ModulePtr->QEICTL, QEI_SIGNAL_MODE_BIT);    break;
		
		
	    default:  /* Do nothing. */                                                                 break;	
	}
	
	
	
	/*--------
	 * Configure the capture mode based on the QeiCaptureMode in the configuration.
	 *------------------*/	
	switch(Qei_ConfigPtr[Qei_ModuleItrator].QeiCaptureMode){
		
		/* Only the PhA edges are counted. */
		case QEI_ONE_EDGE_COUNTED: 	 CLR_REG(Qei_ModulePtr->QEICTL, QEI_CAPTURE_MODE_BIT);			 break;
		
		
		/* The PhA and PhB edges are counted, providing twice the positional resolution but half the range */
		case QEI_BOTH_EDGES_COUNTED: CLR_REG(Qei_ModulePtr->QEICTL, QEI_CAPTURE_MODE_BIT);			 break;
		
		
		default:	/* Do nothing. */ break;
	}
	
	
	



}



//Qei_DirectionType Qei_GetRotatingDirection(Qei_ModuleType Qei_Module){


//	switch(Qei_Module){
//		case QEI_MODULE_0: break;
//		case QEI_MODULE_1: break;
//		default: break;
//	}

	
//}









