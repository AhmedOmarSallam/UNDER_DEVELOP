/********************************************\
Module:       DIO Driver.
File name:    Dio.c
Version:      1.0.0
Author:       Ahmed Omar Sallam
Description:  
\********************************************/




#ifndef DIO_H
#define DIO_H





/* [SWS_BSW_00059] */

	/* Software version 1.0.0 */
#define DIO_SW_MAJOR_VERSION                  1
#define DIO_SW_MINOR_VERSION                  0
#define DIO_SW_PATCH_VERSION                  0

	/* AUTOSAR version 4.8.0 */
#define DIO_AR_RELEASE_MAJOR_VERSION      	  4
#define DIO_AR_RELEASE_MINOR_VERSION          8
#define DIO_AR_RELEASE_REVISION_VERSION       0


#define DIO_VENDOR_ID                         50
#define DIO_MODULE_ID   					  120











#include"Std_Types.h"





/**************************+-------------------------------+**************************/
/**************************|      Error classification     |**************************/
/**************************+-------------------------------+**************************/



			/*-- Development Error --*/

/* [SWS_Dio_91001] */

#define DIO_E_PARAM_INVALID_CHANNEL_ID            0x0A     		/* Invalid channel requested. */
#define DIO_E_PARAM_INVALID_PORT_ID               0x14        /* Invalid port requested. */
#define DIO_E_PARAM_INVALID_GROUP                 0x1F        /* Invalid channel group requested. */
#define DIO_E_PARAM_POINTER                       0x20        /* API service called with a NULL pointer. */



/**************************+-------------------------------+**************************/
/**************************|         APIs Service ID       |**************************/
/**************************+-------------------------------+**************************/



#define DIO_WRITE_CHANNEL_SER_ID		0x01





/**************************+-------------------------------+**************************/
/**************************|        Type definitions       |**************************/
/**************************+-------------------------------+**************************/



/* [SWS_Dio_00182] */
typedef uint8 Dio_ChannelType;	   /* Numeric ID of a DIO channel */
																   
																   
/* [SWS_Dio_00183] */              
typedef uint8 Dio_PortType;	       /* Numeric ID of a DIO port. */
																   
																   
/* [SWS_Dio_00185] */              
typedef uint8 Dio_LevelType;		   /* These are the possible levels a DIO channel can have input or output */
																   
																   
/* [SWS_Dio_00186] */              
typedef uint8 Dio_PortLevelType;   /* If the Microcontroller owns ports of different port widths (e.g. 4, 8,16...Bit)
																   	  Dio_PortLevelType inherits the size of the largest port. */
																   
/* [SWS_Dio_00184] */              
typedef struct{                    
																   
    uint8 mask;						  		   /* This element mask which defines the positions of the channel group. */
																   
  	uint8 offset;	                 /* This element shall be the position of the Channel Group on the port,
                                      counted from the LSB */
																   
	  Dio_PortType port;	           /* This shall be the port on which the Channel group is defined. */
																   
}Dio_ChannelGroupType;	           /* Type for the definition of a channel group, which consists of 
                                      several adjoining channels within a port. */




/**************************+-------------------------------+**************************/
/**************************|      Function definitions     |**************************/
/**************************+-------------------------------+**************************/


/* [SWS_Dio_00133] */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);


/* [SWS_Dio_00134] */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);


/* [SWS_Dio_00135] */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);


/* [SWS_Dio_00136] */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);


/* [SWS_Dio_00137] */
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr);


/* [SWS_Dio_00138] */
void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr, Dio_PortLevelType Level);


/* [SWS_Dio_00139] */
void Dio_GetVersionInfo(Std_VersionInfoType* VersionInfo);




/* [SWS_Dio_00300] */
void Dio_MaskedWritePort(Dio_PortType PortId, Dio_PortLevelType Level, Dio_PortLevelType Mask);


					/*--------------------------*/					/*--------------------------*/


#include "Dio_Cfg.h"



#if (DioFlipChannelApi == STD_ON)

/* [SWS_Dio_00190] */
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

#endif










#endif 

