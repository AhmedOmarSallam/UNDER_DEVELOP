/********************************************\
Module:       DIO Driver
File name:    Dio.h
Version:      1.0.0
Author:       Ahmed Omar Sallam
Description:  
\********************************************/





#include"Dio.h"
#include"tm4c123gh6pm_registers.h"


/********************************************************************\
* Service Name:		 	  Dio_WriteChannel                           *
* Service ID [hex]:		0x01                                         *
* Sync/Async:				  Synchronous                            *
* Reentrancy          Reentrant                                      *
* Parameters (in):    'ChannelId' --> ID of DIO channel              *
*                     'Level'     --> Value to be written            *
* Parameters (inout): None                                           *
* Parameters (out):   None                                           *
* Return value:       None                                           *
* Description:        Service to set a level of a channel.           *
* Available via:      Dio.h                                          *
\********************************************************************/









