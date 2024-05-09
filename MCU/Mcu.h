/********************************************\
@Module:       MCU Driver.
@File name:    Mcu.h
@Version:      1.0.0
@Author:       Ahmed Omar Sallam
@Description:  
\********************************************/



#ifndef RCC_H
#define RCC_H



#include "Std_Types.h"



/**************************+-------------------------------+**************************/
/**************************|        Type definitions       |**************************/
/**************************+-------------------------------+**************************/



/* [SWS_Mcu_00249] */
typedef struct{

	
}Mcu_ConfigType;




/* [SWS_Mcu_00250] */
/* [SWS_Mcu_00231] */
typedef enum {
    MCU_PLL_LOCKED,
    MCU_PLL_UNLOCKED,
    MCU_PLL_STATUS_UNDEFINED
} Mcu_PllStatusType;	/* This is a status value returned by the function Mcu_GetPllStatus of the MCU module. */



/* [SWS_Mcu_00251] */
/* [SWS_Mcu_00233] */
/* [SWS_Mcu_00232] */
typedef uint8 Mcu_ClockType;	/* (ID) for a clock setting, which is configured in the configuration structure */



/* [SWS_Mcu_00252] */
/* [SWS_Mcu_00234] */
/* [SWS_Mcu_00134] */
typedef enum{
		MCU_POWER_ON_RESET,
		MCU_WATCHDOG_RESET,
		MCU_SW_RESET,
		MCU_RESET_UNDEFINED
}Mcu_ResetType;		/* This is the type of the reset enumerator containing the subset of reset types */ 



/* [SWS_Mcu_00253] */
typedef uint8 Mcu_RawResetType;		/* This type specifies the reset reason in raw register format read from a reset status register. */


/* [SWS_Mcu_00254] */
typedef uint8 Mcu_ModeType;


/* [SWS_Mcu_00255] */
typedef uint8 Mcu_RamSectionType;


/* [SWS_Mcu_00256] */
typedef enum{
		MCU_RAMSTATE_INVALID,
		MCU_RAMSTATE_VALID	
}Mcu_RamStateType;



/*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/

/**************************+-------------------------------+**************************/
/**************************|       Symbol definitions      |**************************/
/**************************+-------------------------------+**************************/




/**************************+-------------------------------+**************************/
/**************************|      Function definitions     |**************************/
/**************************+-------------------------------+**************************/



/* [SWS_Mcu_00153] */
void Mcu_Init(const Mcu_ConfigType* ConfigPtr);


/* [SWS_Mcu_00154] */
Std_ReturnType Mcu_InitRamSection (Mcu_RamSectionType RamSection);


/* [SWS_Mcu_00155] */
Std_ReturnType Mcu_InitClock (Mcu_ClockType ClockSetting);


/* [SWS_Mcu_00156] */
Std_ReturnType Mcu_DistributePllClock(void);

/* [SWS_Mcu_00157] */
Mcu_PllStatusType Mcu_GetPllStatus (void);

/* [SWS_Mcu_00158] */
Mcu_ResetType Mcu_GetResetReason (void);

/* [SWS_Mcu_00159] */
Mcu_RawResetType Mcu_GetResetRawValue (void);

/* [SWS_Mcu_00160] */
void Mcu_PerformReset (void);

/* [SWS_Mcu_00161] */
void Mcu_SetMode (Mcu_ModeType McuMode);

/* [SWS_Mcu_00162] */
void Mcu_GetVersionInfo (Std_VersionInfoType* versioninfo);

/* [SWS_Mcu_00207] */
Mcu_RamStateType Mcu_GetRamState (void);



/**************************+-------------------------------+**************************/
/**************************|      Error classification     |**************************/
/**************************+-------------------------------+**************************/


				/*--- Development Errors ---*/

/* [SWS_Mcu_00012] */
/* API service called with wrong parameter. */

#define MCU_E_PARAM_CONFIG			      0x0A		 
#define MCU_E_PARAM_CLOCK             0x0B    
#define MCU_E_PARAM_MODE              0x0C    
#define MCU_E_PARAM_RAMSECTION        0x0D   
#define MCU_E_PLL_NOT_LOCKED          0x0E     
#define MCU_E_UNINIT                  0x0F    
#define MCU_E_PARAM_POINTER           0x10    
#define MCU_E_INIT_FAILED             0x11    




#endif



















/********************************************\
Module:       DIODriver
File name:    Dio.h
Version:      1.0.0
Author:       Ahmed Omar Sallam
Description:  
\********************************************/


