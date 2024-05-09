#include"Uart.h"
#include"Std_Types.h"
#include"Std_BitMath.h"
#include"Uart_TM4C123GH6PM_Registers.h"



#define SysClk  ( (uint32)(16000000) )
#define ClkDiv  16


const static Uart_ConfigType *Uart_ConfigPtr = NULL_PTR;





/*---------------------------------------------------|--------------------------|---------------------------------------------------*/
/*---------------------------------------------------| FUNCTIONS IMPLEMENTATION |---------------------------------------------------*/
/*---------------------------------------------------|--------------------------|---------------------------------------------------*/





/*************************************************************************\
* Service Name       : Uart_Init.                                         *
* Service ID [hex]   : 0x00.                                              *
* Sync/Async         : Synchronous.                                       *		---<
* Reentrancy         : Non Reentrant.                                     *     ---<
* Parameters (in)    : (ConfigPtr) --> Pointer to configuration set.      *
* Parameters (inout) : None.                                              *
* Parameters (out)   : None.                                              *
* Return value       : None.                                              *
* Description        : Initializes the Uart Driver module.                *
* Available via      : Uart.h                                             *
\*************************************************************************/

void Uart_Init(const Uart_ConfigType* ConfigPtr){


	uint32 BaudRateDivisor;
	uint32 BRDI;
	float32 BRDF;
	uint32 UARTFBRD_DIVFRAC;
	
	uint8 Uart_ModuleIterator = 1;
    volatile UART_TYPE *Uart_ModulePtr = NULL_PTR;

	
	Uart_ConfigPtr = ConfigPtr;
	
	


//for(Uart_ModuleIterator = 0; Uart_ModuleIterator <= 7; Uart_ModuleIterator++){

	
	
	/*************************************************************************************************************/
	

	/*----
    * Assigning the Uart_ModulePtr pointer to a specific Uart module structure based on the UART configuration structure.
    * The structure containing the memory addresses of the UART registers of each module.
    *----------------*/	
	switch(Uart_ConfigPtr[Uart_ModuleIterator].UartModule){
	
	case UART_MODULE0: Uart_ModulePtr = UART0;    break;
	case UART_MODULE1: Uart_ModulePtr = UART1;    break;
	case UART_MODULE2: Uart_ModulePtr = UART2;    break;
	case UART_MODULE3: Uart_ModulePtr = UART3;    break;
	case UART_MODULE4: Uart_ModulePtr = UART4;    break;
	case UART_MODULE5: Uart_ModulePtr = UART5;    break;
	case UART_MODULE6: Uart_ModulePtr = UART6;    break;
	case UART_MODULE7: Uart_ModulePtr = UART7;    break;
	default: /* Do nothing. */                    break;
	
	}
		

	/*************************************************************************************************************/
	
	
	/*************************************************************************************************************/
	
	
	/*----
	*	Disable the UART Module.
    *----------------*/		
	CLR_REG(Uart_ModulePtr->UARTCTL, UART_ENABLE_BIT);
	
	/*************************************************************************************************************/
	
	
	/*************************************************************************************************************/
	
	
	/*----
	*	Set the baud rate.
    *----------------*/		

	/* Calculate the baud rate divisor. */
	BaudRateDivisor = (SysClk / (ClkDiv * Uart_ConfigPtr[Uart_ModuleIterator].UartBaudRate));  

    /* Separate integer and fractional parts of BRD */
	BRDI = BaudRateDivisor;
    BRDF = ((float32)SysClk / (ClkDiv * (float32)Uart_ConfigPtr[Uart_ModuleIterator].UartBaudRate)) - (float32)BRDI;
 
    /* Calculate the 6-bit fractional number for UARTFBRD */
//    UARTFBRD_DIVFRAC = (uint32)(BRDF * 64 + 0.5);
  
	/* Set the integer part of the baud rate divisor. */
	Uart_ModulePtr->UARTIBRD = BRDI;	
	
	/* Set the fractional part of the baud rate divisor */
	Uart_ModulePtr->UARTFBRD = 11;  
	
	
	/*************************************************************************************************************/
	
		
	/*************************************************************************************************************/
				
	/*----
	*
	*
    *----------------*/		
	switch(Uart_ConfigPtr[Uart_ModuleIterator].UartParity){
	
	case NO_PARITY:     CLR_REG(Uart_ModulePtr->UARTLCRH, PARITY_ENABLE_BIT);       break;
		
	case PARITY_EVEN:   SET_REG(Uart_ModulePtr->UARTLCRH, PARITY_ENABLE_BIT); 
						SET_REG(Uart_ModulePtr->UARTLCRH, EVEN_PARITY_SELECT_BIT);  break;
		
	case PARITY_ODD:    SET_REG(Uart_ModulePtr->UARTLCRH, PARITY_ENABLE_BIT); 
						CLR_REG(Uart_ModulePtr->UARTLCRH, EVEN_PARITY_SELECT_BIT);  break;

	default:            /* Do nothing. */                                           break;
	
	}
	
	
			/*************************************************************************************************************/
	
	
	/*----
	*
	*
    *----------------*/		
	switch(Uart_ConfigPtr[Uart_ModuleIterator].UartStopBits){
	
	case ONE_STOP_BIT:  CLR_REG(Uart_ModulePtr->UARTLCRH, STOP_BITS_SELECT_BIT);     break;
	case TWO_STOP_BITS: SET_REG(Uart_ModulePtr->UARTLCRH, STOP_BITS_SELECT_BIT);     break;
	default:            /* Do nothing. */                                            break;
	
	}	
	
	
			/*************************************************************************************************************/
	
	
	/*----
	*
	*
    *----------------*/		
//	switch(Uart_ConfigPtr[Uart_ModuleIterator].UartWordLength){
	
//	case DATA_5_BITS:  CLR_REG(Uart_ModulePtr->UARTLCRH, STOP_BITS_SELECT_BIT);     break;
//	case TWO_STOP_BITS: SET_REG(Uart_ModulePtr->UARTLCRH, STOP_BITS_SELECT_BIT);     break;
//	default:            /* Do nothing. */                                            break;
	
//	}	
//	Uart_ModulePtr->UARTLCRH |= 0x00000060;
	
	/*************************************************************************************************************/
	
	
	
	Uart_ModulePtr->UARTCC |= 5; 
	
	/*************************************************************************************************************/
	
	/*----
	*	Enable the UART Receive, Transmitt, or both.
    *----------------*/	
	switch(Uart_ConfigPtr[Uart_ModuleIterator].UartReceiveOrTransmitt){
	
	case UART_RECEIVE:  			 SET_REG(Uart_ModulePtr->UARTCTL, RECEIVE_ENABLE_BIT);     break;
		
	case UART_TRANSMITT: 			 SET_REG(Uart_ModulePtr->UARTCTL, TRANSMITT_ENABLE_BIT);   break;
		
	case UART_TRANSMITT_AND_RECEIVE: SET_REG(Uart_ModulePtr->UARTCTL, TRANSMITT_ENABLE_BIT);    
									 SET_REG(Uart_ModulePtr->UARTCTL, RECEIVE_ENABLE_BIT);     break;

	default:            /* Do nothing. */                                            break;
	
	}	
	
	
	
		
	
	/*************************************************************************************************************/


	/*************************************************************************************************************/

	
	/*----
	*	Enable the UART.
    *----------------*/		
	SET_REG(Uart_ModulePtr->UARTCTL, UART_ENABLE_BIT);
	
	/*************************************************************************************************************/
	
	
	/*************************************************************************************************************/
		
	
		
		
//}
	



	

}





void Uart_Transmitt(Uart_ModuleType UartModule, uint8 Data){

    volatile UART_TYPE *Uart_ModulePtr = NULL_PTR;
	
	
	/*************************************************************************************************************/
	

	/*----
    * Assigning the Uart_ModulePtr pointer to a specific Uart module structure based on the UART configuration structure.
    * The structure containing the memory addresses of the UART registers of each module.
    *----------------*/	
	switch(UartModule){
	
	case UART_MODULE0: Uart_ModulePtr = UART0;    break;
	case UART_MODULE1: Uart_ModulePtr = UART1;    break;
	case UART_MODULE2: Uart_ModulePtr = UART2;    break;
	case UART_MODULE3: Uart_ModulePtr = UART3;    break;
	case UART_MODULE4: Uart_ModulePtr = UART4;    break;
	case UART_MODULE5: Uart_ModulePtr = UART5;    break;
	case UART_MODULE6: Uart_ModulePtr = UART6;    break;
	case UART_MODULE7: Uart_ModulePtr = UART7;    break;
	default: /* Do nothing. */                    break;
	
	}
		

	/*************************************************************************************************************/
	
	
	
    // Wait until the transmit buffer is not full
    while ((Uart_ModulePtr->UARTFR & (1 << 5))) {}

    // Send the data
    Uart_ModulePtr->UARTDR = Data;	
	
	
}
	





uint32 Uart_Receive(Uart_ModuleType UartModule){

    volatile UART_TYPE *Uart_ModulePtr = NULL_PTR;
	
	
	/*************************************************************************************************************/
	

	/*----
    * Assigning the Uart_ModulePtr pointer to a specific Uart module structure based on the UART configuration structure.
    * The structure containing the memory addresses of the UART registers of each module.
    *----------------*/	
	switch(UartModule){
	
	case UART_MODULE0: Uart_ModulePtr = UART0;    break;
	case UART_MODULE1: Uart_ModulePtr = UART1;    break;
	case UART_MODULE2: Uart_ModulePtr = UART2;    break;
	case UART_MODULE3: Uart_ModulePtr = UART3;    break;
	case UART_MODULE4: Uart_ModulePtr = UART4;    break;
	case UART_MODULE5: Uart_ModulePtr = UART5;    break;
	case UART_MODULE6: Uart_ModulePtr = UART6;    break;
	case UART_MODULE7: Uart_ModulePtr = UART7;    break;
	default: /* Do nothing. */                    break;
	
	}
		

	/*************************************************************************************************************/
	
	
	
    /* Wait until the receive buffer is not empty */
    while ((Uart_ModulePtr->UARTFR & (1 << 4)) !=0) {}
	
		for(volatile int i =0; i<5; i++){}
    /* Receive the data */
    return (Uart_ModulePtr->UARTDR & 0xFF);	
	
   
}






