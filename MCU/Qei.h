/********************************************\
* @Module       : QEI Driver.
* @FileName     : Qei.h
* @Version      : 1.0.0
* @Author       : Ahmed Omar Sallam
* @Description  :  
\********************************************/




#ifndef QEI_H
#define QEI_H


#include"Std_Types.h"


		/*=============================================*/
typedef uint8 Qei_DirectionType;

#define QEI_FORWARD_DIRECTION  ( (Qei_DirectionType)(0x00) ) 
#define QEI_REVERSE_DIRECTION  ( (Qei_DirectionType)(0x01) ) 

/*=============================================*/


typedef uint8 Qei_ModuleType;

#define QEI_MODULE_0     ( ( (Qei_ModuleType) 0x00 ) ) 
#define QEI_MODULE_1     ( ( (Qei_ModuleType) 0x01 ) ) 

		/*=============================================*/

typedef uint8 Qei_ModeType;

#define	QEI_QUADRATURE_PHASE_MODE  ( (Qei_ModeType)(0x00) ) 
#define	QEI_CLOCK_DIRECTION_MODE   ( (Qei_ModeType)(0x01) ) 
	
		/*=============================================*/

typedef uint8 Qei_CaptureModeType;

#define QEI_ONE_EDGE_COUNTED      ( (Qei_CaptureModeType)(0x00)) 
#define QEI_BOTH_EDGES_COUNTED    ( (Qei_CaptureModeType)(0x01)) 



typedef struct{

	Qei_ModuleType 			QeiModuleNumber;
	Qei_ModeType 			QeiMode;
	Qei_CaptureModeType     QeiCaptureMode;
	
}Qei_ConfigType;


extern const Qei_ConfigType Qei_Configuration[];


/*=========================+-------------------------------+=========================*/
/*=========================|      Function definitions     |=========================*/
/*=========================+-------------------------------+=========================*/



void Qie_Init(const Qei_ConfigType* ConfigPtr);


Qei_DirectionType Qei_GetRotatingDirection(Qei_ModuleType Qei_Module);


#endif
