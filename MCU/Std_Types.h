/********************************************\
@Module:       STD Types.
@File name:    Std_Types.h
@Version:      1.0.0
@Author:       Ahmed Omar Sallam
@Description:  
\********************************************/



/*
#include "Compiler.h"
*/

/* [SWS_Std_00014] */
#ifndef STD_TYPES_H
#define STD_TYPES_H


#include "Platform_Types.h"



/**************************+-------------------------------+**************************/
/**************************|        Type definitions       |**************************/
/**************************+-------------------------------+**************************/

/* [SWS_Std_00005] */
typedef uint8 Std_ReturnType;

/* SWS_Std_00015 */
typedef struct{

	uint16 vendorID;
	uint16 moduleID;
	uint8 sw_major_version;
	uint8 sw_minor_version;
	uint8 sw_patch_version;

}Std_VersionInfoType;	/* used to request the version of a BSW module using the <Module name>_Get VersionInfo() function. */


/* [SWS_Std_00022] */
typedef uint8 Std_TransformerErrorCode;

/* [SWS_Std_00024] */
typedef enum {
    STD_TRANSFORMER_UNSPECIFIED = 0x00,  // Transformer of an unspecified class
    STD_TRANSFORMER_SERIALIZER  = 0x01,  // Transformer of a serializer class
    STD_TRANSFORMER_SAFETY      = 0x02,  // Transformer of a safety class
    STD_TRANSFORMER_SECURITY    = 0x03,  // Transformer of a security class
    STD_TRANSFORMER_CUSTOM      = 0xFF   // Transformer of a custom class not standardized by AUTOSAR
} Std_TransformerClass;

/* [SWS_Std_00021] */
typedef struct{

	Std_TransformerErrorCode errorCode; 
	Std_TransformerClass transformerClass;
	
}Std_TransformerError;

/* [SWS_Std_00029] */
typedef uint8 Std_TransformerForwardCode; 

/* [SWS_Std_91001] */
typedef uint8 Std_MessageTypeType;

/* [SWS_Std_91002]  */
typedef uint8 Std_MessageResultType;





/**************************+-------------------------------+**************************/
/**************************|       Symbol definitions      |**************************/
/**************************+-------------------------------+**************************/

	
/* [SWS_Std_00006] */
#ifndef STATUSTYPEDEFINED		/* Because E_OK is already defined within OSEK, the symbol E_OK has to be shared. To avoid name clashes and redefinition problems */
#define STATUSTYPEDEFINED

#define E_OK     0x00u

typedef unsigned char StatusType; /* OSEK compliance */
#endif

#define E_NOT_OK 0x01u

					/*--------------------------*/					/*--------------------------*/

/* [SWS_Std_00007] */
#define STD_HIGH	    	0x01U 	/* Physical state 5V or 3.3V */
#define STD_LOW 		  	0x00U 	/* Physical state 0V */

					/*--------------------------*/					/*--------------------------*/

/* [SWS_Std_00013] */
#define STD_ACTIVE 			0x01U 	/* Logical state active */
#define STD_IDLE				0x00U 	/* Logical state idle */

					/*--------------------------*/					/*--------------------------*/

/* [SWS_Std_00010] */
#define STD_ON 	  			0x01U
#define STD_OFF   			0x00U

					/*--------------------------*/					/*--------------------------*/
					
/* [SWS_Std_00031] */					
#define NULL_PTR  	  ((void *)0)



#endif	/* STD_TYPES_H */
