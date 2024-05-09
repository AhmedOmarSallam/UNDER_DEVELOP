/********************************************\
* @Module       : UART Driver.
* @FileName     : Uart.h
* @Version      : 1.0.0
* @Author       : Ahmed Omar Sallam
* @Description  :  
\********************************************/


#ifndef UART_H
#define UART_H


#include"Std_Types.h"




/*=========================+-------------------------------+=========================*/
/*=========================|        Type definitions       |=========================*/
/*=========================+-------------------------------+=========================*/


typedef uint8 Uart_ModuleType;

#define UART_MODULE0 	( (Uart_ModuleType)(0x00) )
#define UART_MODULE1 	( (Uart_ModuleType)(0x01) )
#define UART_MODULE2 	( (Uart_ModuleType)(0x02) )
#define UART_MODULE3 	( (Uart_ModuleType)(0x03) )
#define UART_MODULE4 	( (Uart_ModuleType)(0x04) )
#define UART_MODULE5 	( (Uart_ModuleType)(0x05) )
#define UART_MODULE6 	( (Uart_ModuleType)(0x06) )
#define UART_MODULE7 	( (Uart_ModuleType)(0x07) )

					/*===================-----===================*/

typedef enum{

	NO_PARITY   = 0x00U,
	PARITY_EVEN = 0x01U,
	PARITY_ODD  = 0x02U

}Uart_ParityType;

					/*===================-----===================*/

typedef enum{

	ONE_STOP_BIT  = 0x00U,
	TWO_STOP_BITS = 0x01U
	
}Uart_StopBitsType;

					/*===================-----===================*/


typedef enum{

	DATA_5_BITS = 0x00U,
	DATA_6_BITS = 0x01U,
	DATA_7_BITS = 0x02U,
	DATA_8_BITS = 0x03U,
	
}Uart_WordLengthType;

					/*===================-----===================*/

typedef enum{
	
	UART_TRANSMITT 			   = 0x00U,
	UART_RECEIVE   			   = 0x01U,
	UART_TRANSMITT_AND_RECEIVE = 0x02U
	
}Uart_ReceiveOrTransmittType;

					/*===================-----===================*/


typedef uint32 Uart_BaudRateType;

#define BAUD_RATE_9600	    ( (Uart_BaudRateType)(9600) )
#define BAUD_RATE_115200	( (Uart_BaudRateType)(115200) )



					/*===================-----===================*/

typedef struct{

	Uart_ModuleType 	          UartModule;
						          
	Uart_ParityType  	          UartParity;
						          
	Uart_StopBitsType	          UartStopBits;	
						          
	Uart_WordLengthType           UartWordLength;
						          
	Uart_BaudRateType             UartBaudRate;
							      
	Uart_ReceiveOrTransmittType   UartReceiveOrTransmitt;
							      
}Uart_ConfigType;


extern const Uart_ConfigType Uart_Configuration[];


/*=========================+-------------------------------+=========================*/
/*=========================|      Function definitions     |=========================*/
/*=========================+-------------------------------+=========================*/


void Uart_Init(const Uart_ConfigType* ConfigPtr);


void Uart_Transmitt(Uart_ModuleType UartModule, uint8 Data);

uint32 Uart_Receive(Uart_ModuleType UartModule);

					/*===================-----===================*/
					/*===================-----===================*/
					/*===================-----===================*/



#endif
