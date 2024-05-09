/********************************************\
* @Module       : Port Driver.
* @FileName     : Port.h
* @Version      : 1.0.0
* @Author       : Ahmed Omar Sallam
* @Description  :  
\********************************************/

#ifndef PORT_H
#define PORT_H



/* [SWS_BSW_00059] */

	/* Software version 1.0.0 */
#define PORT_SW_MAJOR_VERSION                  (1U)
#define PORT_SW_MINOR_VERSION                  (0U)
#define PORT_SW_PATCH_VERSION                  (0U)

	/* AUTOSAR version 4.8.0 */
#define PORT_AR_RELEASE_MAJOR_VERSION      	   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION          (8U)
#define PORT_AR_RELEASE_REVISION_VERSION       (0U)


#define PORT_VENDOR_ID                         50
#define PORT_MODULE_ID   					   127



#include"Std_Types.h"
#include"Port_Cfg.h"
#include"Port_Tm4c123gh6pmCfg.h"







/*=========================+-------------------------------+=========================*/
/*=========================|      Error classification     |=========================*/
/*=========================+-------------------------------+=========================*/

/* [SWS_Port_00051] */

/* Invalid Port Pin ID requested. */
#define PORT_E_PARAM_PIN							          0x0A

/* Port Pin not configured as changeable. */
#define PORT_E_DIRECTION_UNCHANGEABLE 					      0x0B

/* API Port_Init service called with wrong parameter. */
#define PORT_E_INIT_FAILED 									  0x0C

/* API Port_SetPinMode service called when mode is unchangeable. */
#define PORT_E_PARAM_INVALID_MODE 							  0x0D

/* API Port_SetPinMode service called when mode is unchangeable. */
#define PORT_E_MODE_UNCHANGEABLE 							  0x0E

/* API service called without module initialization. */
#define PORT_E_UNINIT 										  0x0F

/* APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER 								  0x10



/*=========================+-------------------------------+=========================*/
/*=========================|        Type definitions       |=========================*/
/*=========================+-------------------------------+=========================*/


/* 
 * [SWS_Port_00229]
 * Data type for the symbolic name of a port pin.
 * The user shall use the symbolic names provided by the configuration tool.
 */
typedef uint8 Port_PinType; 

					/*===================-----===================*/
/* 
 * [SWS_Port_00231] 
 * Different port pin modes.
 */
typedef uint8 Port_PinModeType;



#define     PORT_PIN_MODE_ADC		( (Port_PinModeType) (0x00) )    /* Port Pin used by ADC. */
#define     PORT_PIN_MODE_CAN       ( (Port_PinModeType) (0x01) )    /* Port Pin used for CAN. */
#define     PORT_PIN_MODE_DIO       ( (Port_PinModeType) (0x02) )    /* Port Pin configured for DIO. It shall be used under control of the DIO driver. */
#define     PORT_PIN_MODE_DIO_GPT   ( (Port_PinModeType) (0x03) )    /* Port Pin configured for DIO. It shall be used under control of the general purpose timer driver. */
#define     PORT_PIN_MODE_DIO_WDG   ( (Port_PinModeType) (0x04) )    /* Port Pin configured for DIO. It shall be used under control of the watchdog driver. */
#define     PORT_PIN_MODE_ICU       ( (Port_PinModeType) (0x05) )    /* Port Pin used by ICU. */
#define     PORT_PIN_MODE_LIN       ( (Port_PinModeType) (0x06) )    /* Port Pin used for LIN. */
#define     PORT_PIN_MODE_MEM       ( (Port_PinModeType) (0x07) )    /* Port Pin used for external memory under control of a memory driver. */
#define     PORT_PIN_MODE_PWM       ( (Port_PinModeType) (0x08) )    /* Port Pin used by PWM. */
#define     PORT_PIN_MODE_SPI       ( (Port_PinModeType) (0x09) )    /* Port Pin used by SPI. */
#define     PORT_PIN_MODE_QEI       ( (Port_PinModeType) (0x0A) )    /* Port Pin used by QEI. */ 
#define     PORT_PIN_MODE_UART      ( (Port_PinModeType) (0x0B) )    /* Port Pin used by UART. */ 


					/*===================-----===================*/

/* [SWS_Port_00230] 
 * [SWS_Port_00220] 
 * Possible directions of a port pin.
 */
typedef enum{

	PORT_PIN_IN  = 0x00U, 	/* Sets port pin as input. */
	PORT_PIN_OUT = 0x01U   /* Sets port pin as output. */
		
}Port_PinDirectionType;				

					/*===================-----===================*/    	
					/*===================-----===================*/    	

typedef uint8 Port_PinLevelValueType;
typedef uint8 Port_DriveStrengthType;
typedef uint8 Port_PortType;
typedef uint8 Port_PullType;


#define PORT_PIN_PULL_UP    ( (Port_PullType)(0x00))
#define PORT_PIN_PULL_DOWN  ( (Port_PullType)(0x01))


					/*===================-----===================*/    	
					/*===================-----===================*/    	




/* [SWS_Port_00228] */
typedef struct{	
	
	/* Represent the Port Id. Example: PORT_A, PORT_D_AHB...  */
	Port_PortType 			PortType;
	
	/* Represent the Pin Id. Example: PORT_A_PIN_0, PORT_C_PIN_4, ... */
	Port_PinType            PinNumber;
	
	Port_PinDirectionType   PinDirection;
     
	Port_PinModeType        PinMode;
	
	Port_PinLevelValueType  PortPinLevelValue; 
		
	Port_DriveStrengthType  Drive_Strength;
	
	Port_PullType           Pulling;
	
}Port_ConfigType;


extern const Port_ConfigType Port_Coniguration[];

	
/*=========================+-------------------------------+=========================*/
/*=========================|      Function definitions     |=========================*/
/*=========================+-------------------------------+=========================*/


/* [SWS_Port_00140] */
void Port_Init(const Port_ConfigType* ConfigPtr);

					/*===================-----===================*/

/* [SWS_Port_00142] */
void Port_RefreshPortDirection(void);

					/*===================-----===================*/




/* [ECUC_Port_00131] */
#if(TRUE == PortSetPinDirectionApi)

/* [SWS_Port_00141]  */
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);

#endif

					/*===================-----===================*/

#if (TRUE == PortSetPinModeApi)

/* [SWS_Port_00145] */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);

#endif

					/*===================-----===================*/

#if(TRUE == PortVersionInfoApi)

/* [SWS_Port_00143] */
void Port_GetVersionInfo(Std_VersionInfoType* versioninfo);

#endif

					/*===================-----===================*/


#endif
