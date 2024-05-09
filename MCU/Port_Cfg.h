/********************************************\
Module:       Port Driver.
File name:    Port_Cfg.h
Version:      1.0.0
Author:       Ahmed Omar Sallam
Description:  
\********************************************/



#ifndef PORT_CFG_H
#define PORT_CFG_H



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


					/*===================-----===================*/

/* [ECUC_Port_00123] 
 * Switches the development error detection and notification on or off.
 */
#define PortDevErrorDetect          FALSE

					/*===================-----===================*/

/* [ECUC_Port_00131] 
 * Pre-processor switch to enable / disable the use of the function Port_SetPinDirection().
 */
#define PortSetPinDirectionApi	    TRUE

					/*===================-----===================*/

/* [ECUC_Port_00132] 
 * Pre-processor switch to enable / disable the use of the function Port_SetPinMode().
 */
#define PortSetPinModeApi 			TRUE

					/*===================-----===================*/

/* [ECUC_Port_00133] 
 * Pre-processor switch to enable / disable the API to read out the modules version information.
 */
#define PortVersionInfoApi          FALSE

					/*===================-----===================*/



					/*===================-----===================*/

/* [ECUC_Port_00129]
 * Port Pin Level value from Port pin list.
 */

typedef enum{

    PORT_PIN_LEVEL_HIGH,	/* Port Pin level is High. */
    PORT_PIN_LEVEL_LOW    /* Port Pin level is Low. */
	
}PortPinLevelValue;


					/*===================-----===================*/

/* [ECUC_Port_00134]
 * Parameter to indicate if the mode is changeable on a port pin during runtime.
 */
#define PortPinModeChangeable		FALSE

					/*===================-----===================*/






/*=========================+-------------------------------+=========================*/
/*=========================|      PortPins Symbolic Ids    |=========================*/
/*=========================+-------------------------------+=========================*/

/* PORT A Symbolic names. */
typedef enum{

	PORT_A_PIN_0,
	PORT_A_PIN_1,
	PORT_A_PIN_2,
	PORT_A_PIN_3,
	PORT_A_PIN_4,
	PORT_A_PIN_5,
	PORT_A_PIN_6,
	PORT_A_PIN_7
	
}PORT_A_PINS;

					/*===================-----===================*/

/* PORT B Symbolic names. */
typedef enum{

	PORT_B_PIN_0,
	PORT_B_PIN_1,
	PORT_B_PIN_2,
	PORT_B_PIN_3,
	PORT_B_PIN_4,
	PORT_B_PIN_5,
	PORT_B_PIN_6,
	PORT_B_PIN_7
	
}PORT_B_PINS;

					/*===================-----===================*/
	
/* PORT C Symbolic names. */
typedef enum{

	PORT_C_PIN_0,
	PORT_C_PIN_1,
	PORT_C_PIN_2,
	PORT_C_PIN_3,
	PORT_C_PIN_4,
	PORT_C_PIN_5,
	PORT_C_PIN_6,
	PORT_C_PIN_7
	
}PORT_C_PINS;

					/*===================-----===================*/

/* PORT D Symbolic names. */
typedef enum{

	PORT_D_PIN_0,
	PORT_D_PIN_1,
	PORT_D_PIN_2,
	PORT_D_PIN_3,
	PORT_D_PIN_4,
	PORT_D_PIN_5,
	PORT_D_PIN_6,
	PORT_D_PIN_7
	
}PORT_D_PINS;

					/*===================-----===================*/

/* PORT E Symbolic names. */
typedef enum{

	PORT_E_PIN_0,
	PORT_E_PIN_1,
	PORT_E_PIN_2,
	PORT_E_PIN_3,
	PORT_E_PIN_4,
	PORT_E_PIN_5

}PORT_E_PINS;

					/*===================-----===================*/
/* PORT F Symbolic names. */
typedef enum{

	PORT_F_PIN_0,
	PORT_F_PIN_1,
	PORT_F_PIN_2,
	PORT_F_PIN_3,
	PORT_F_PIN_4

}PORT_F_PINS;


/*=========================+-------------------------------+=========================*/
/*=========================|        Ports Symbolic Ids     |=========================*/
/*=========================+-------------------------------+=========================*/

typedef enum{
    PORT_A,
    PORT_B,	
    PORT_C,	
    PORT_D,	
    PORT_E,	
    PORT_F,
	PORT_A_AHB,
    PORT_B_AHB,	
    PORT_C_AHB,	
    PORT_D_AHB,	
    PORT_E_AHB,	
    PORT_F_AHB
	
}TM4C_Ports;




typedef enum{
	DRIVE_2_MA,
	DRIVE_4_MA,
	DRIVE_8_MA
}TM4C_DriveStrength;






					/*===================-----===================*/
					/*===================-----===================*/
					/*===================-----===================*/








#endif
