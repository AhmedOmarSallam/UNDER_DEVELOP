/********************************************\
* @Module       : PWM Driver.
* @FileName     : Pwm.h
* @Version      : 1.0.0
* @Author       : Ahmed Omar Sallam
* @Description  :  
\********************************************/

#ifndef PWM_H
#define PWM_H


#include"Std_Types.h"
#include"Pwm_Cfg.h"








/*=========================+-------------------------------+=========================*/
/*=========================|        Type definitions       |=========================*/
/*=========================+-------------------------------+=========================*/


/*
 * [SWS_Pwm_00106]
 * Numeric identifier of a PWM channel.
 * For the TM4C123GH6PM, 16 PWM channels are only available --> uint8 is sufficiant.
 */
typedef uint8 Pwm_ChannelType;


					/*===================-----===================*/


/*
 * [SWS_Pwm_00107]
 * Definition of the period of a PWM channel.
 */
typedef uint16 Pwm_PeriodType;


					/*===================-----===================*/
					
					
/*
 * [SWS_Pwm_00108]
 * Output state of a PWM channel.
 */
typedef enum{
 
	PWM_HIGH = 0x00U,    /* The PWM channel is in high state. */
	PWM_LOW  = 0x01U     /* The PWM channel is in low state. */
	
}Pwm_OutputStateType;


					/*===================-----===================*/


					/*===================-----===================*/
					/*===================-----===================*/
					/*===================-----===================*/
typedef uint8 Pwm_ModuleType;

/* There are two modules for the generation of PWM. */
#define PWM_MODULE0         ( (Pwm_ModuleType)(0x00U) )
#define PWM_MODULE1         ( (Pwm_ModuleType)(0x01U) )



/* In each module, there is 8 PWM signals. */
#define PWM_MnPWM0   		( (Pwm_ChannelType)(0x00U) )
#define PWM_MnPWM1   		( (Pwm_ChannelType)(0x01U) )
#define PWM_MnPWM2   		( (Pwm_ChannelType)(0x02U) )
#define PWM_MnPWM3   		( (Pwm_ChannelType)(0x03U) )
#define PWM_MnPWM4   		( (Pwm_ChannelType)(0x04U) )
#define PWM_MnPWM5   		( (Pwm_ChannelType)(0x05U) )
#define PWM_MnPWM6   		( (Pwm_ChannelType)(0x06U) )
#define PWM_MnPWM7   		( (Pwm_ChannelType)(0x07U) )



typedef uint8 Pwm_CounterModeType;

#define PWM_COUNT_DOWN         ( (Pwm_CounterModeType)(0x00U) )
#define PWM_COUNT_UP_DOWN      ( (Pwm_CounterModeType)(0x01U) )


    

typedef uint8 Pwm_PolarityType;

#define PWM_ACTIVE_LOW       ( (Pwm_PolarityType)(0x00U) )
#define PWM_ACTIVE_HIGH      ( (Pwm_PolarityType)(0x01U) )
					/*===================-----===================*/
//typedef uint16 Pwm_DutyCycleType;		

/*===================-----===================*/


					/*===================-----===================*/


/*
 * [SWS_Pwm_00111]
 * Definition of the type of edge notification of a PWM channel.
 */
typedef struct{

	Pwm_ModuleType      PwmModuleNumber;
					    
	Pwm_ChannelType     PwmChannelNumber;
	
	Pwm_PolarityType    PwmDefaultPolarity;
	
	uint16 				PwmDefaultDutyCycle;
	
	uint16				PwmDefaultPeriod;
					    
/*	Pwm_CounterModeType  PwmCounterMode;*/
	
	
	
/*	Pwm_OutputStateType PwmPolarity;*/
    
}Pwm_ConfigType;

					/*===================-----===================*/

extern const Pwm_ConfigType Pwm_Configuration[];
 




/*=========================+-------------------------------+=========================*/
/*=========================|      Function definitions     |=========================*/
/*=========================+-------------------------------+=========================*/



/* [SWS_Pwm_00095] */
void Pwm_Init(const Pwm_ConfigType* ConfigPtr);

					/*===================-----===================*/



#if(STD_ON == PWM_SET_DUTY_CYCLE_AP)

/* [SWS_Pwm_91000] */
void Pwm_SetDutyCycle(Pwm_ChannelType ChannelNumber, uint16 DutyCycle);

#endif











/*=========================+-------------------------------+=========================*/
/*=========================|      Error classification     |=========================*/
/*=========================+-------------------------------+=========================*/














#define PWM_M0PWM0_CHANNEL 	 ((Pwm_ChannelType)(0x00U))
#define PWM_M0PWM1_CHANNEL 	 ((Pwm_ChannelType)(0x01U))
#define PWM_M0PWM2_CHANNEL 	 ((Pwm_ChannelType)(0x02U))
#define PWM_M0PWM3_CHANNEL 	 ((Pwm_ChannelType)(0x03U))
#define PWM_M0PWM4_CHANNEL 	 ((Pwm_ChannelType)(0x04U))
#define PWM_M0PWM5_CHANNEL 	 ((Pwm_ChannelType)(0x05U))
#define PWM_M0PWM6_CHANNEL 	 ((Pwm_ChannelType)(0x06U))
#define PWM_M0PWM7_CHANNEL 	 ((Pwm_ChannelType)(0x07U))

#define PWM_M1PWM0_CHANNEL 	 ((Pwm_ChannelType)(0x08U))
#define PWM_M1PWM1_CHANNEL 	 ((Pwm_ChannelType)(0x09U))
#define PWM_M1PWM2_CHANNEL 	 ((Pwm_ChannelType)(0x0AU))
#define PWM_M1PWM3_CHANNEL 	 ((Pwm_ChannelType)(0x0BU))
#define PWM_M1PWM4_CHANNEL 	 ((Pwm_ChannelType)(0x0CU))
#define PWM_M1PWM5_CHANNEL 	 ((Pwm_ChannelType)(0x0DU))
#define PWM_M1PWM6_CHANNEL 	 ((Pwm_ChannelType)(0x0EU))
#define PWM_M1PWM7_CHANNEL 	 ((Pwm_ChannelType)(0x0FU))



#define PWM_DUTY_CYCLE_MIN	 ((uint16) (0x0000))
#define PWM_DUTY_CYCLE_MAX   ((uint16) (0x8000))








/*=========================+-------------------------------+=========================*/
/*=========================|           Services ID         |=========================*/
/*=========================+-------------------------------+=========================*/



#define PWM_INIT_SERVICE_ID        0x00









/*
 * [SWS_Pwm_00109]
 * Definition of the type of edge notification of a PWM channel.
 */
typedef enum{

    PWM_RISING_EDGE  = 0x00U,    /* Notification will be called when a rising edge occurs on the PWM output signal. */
    PWM_FALLING_EDGE = 0x01U,    /* Notification will be called when a falling edge occurs on the PWM output signal. */
    PWM_BOTH_EDGES   = 0x02U     /* Notification will be called when either a rising edge or faling edge occur on the PWM output signal. */

}Pwm_EdgeNotificationType;

					/*===================-----===================*/

/*
 * [SWS_Pwm_00110]
 * Defines the class of a PWM channel.
 */
typedef enum{

    PWM_VARIABLE_PERIOD      = 0x00U,    /* The PWM channel has a variable period. The duty cycle and the period can be changed. */
    PWM_FIXED_PERIOD         = 0x01U,    /* The PWM channel has a fixed period. Only the duty cycle can be changed. */
    PWM_FIXED_PERIOD_SHIFTED = 0x02U     /* Notification will be called when either a rising edge or faling edge occur on the PWM output signal. */

}Pwm_ChannelClassType;
	
	

					/*===================-----===================*/



/*
 * [SWS_Pwm_00165]
 * Result of the requests related to power state transitions.
 */
typedef enum{

    PWM_SERVICE_ACCEPTED     = 0x00U,    /* Power state change executed. */
    PWM_NOT_INIT             = 0x01U,    /* PWM Module not initialized. */
    PWM_SEQUENCE_ERROR       = 0x02U,    /* Wrong API call sequence. */
    PWM_HW_FAILURE           = 0x03U,    /* The HW module has a failure which prevents it to enter the required power state. */
	PWM_POWER_STATE_NOT_SUPP = 0x04U,    /* PWM Module does not support the requested power state. */
	PWM_TRANS_NOT_POSSIBLE   = 0X05U     /* PWM Module cannot transition directly from the
                                            current power state to the requested power state 
                                            or the HW peripheral is still busy */ 
}Pwm_PowerStateRequestResultType;





					/*===================-----===================*/
					/*===================-----===================*/
					/*===================-----===================*/











void Pwm_DeInit(void);




void Pwm_SetPeriodAndDuty(Pwm_ChannelType ChannelNumber, Pwm_PeriodType Period, uint16 DutyCycle);


void Pwm_SetOutputToIdle(Pwm_ChannelType ChannelNumber);


Pwm_OutputStateType Pwm_GetOutputState(Pwm_ChannelType ChannelNumber);

void Pwm_DisableNotification(Pwm_ChannelType ChannelNumber);

void Pwm_EnableNotification(Pwm_ChannelType ChannelNumber, Pwm_EdgeNotificationType Notification);

Std_ReturnType Pwm_SetPowerState(Pwm_PowerStateRequestResultType* Result);

/*  

Std_ReturnType Pwm_GetCurrentPowerState(Pwm_PowerStateType* CurrentPowerState, Pwm_PowerStateRequestResultType* Result);


Std_ReturnType Pwm_GetTargetPowerState(Pwm_PowerStateType* TargetPowerState, Pwm_PowerStateRequestResultType* Result);

Std_ReturnType Pwm_PreparePowerState(Pwm_PowerStateType PowerState, Pwm_PowerStateRequestResultType* Result);


*/

void Pwm_GetVersionInfo(Std_VersionInfoType* versioninfo);

void Pwm_Main_PowerTransitionManager(void);

					/*===================-----===================*/




















#endif
