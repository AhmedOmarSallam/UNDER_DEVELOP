



#ifndef UART_TM4C123GH6PM_REGISTERS_H
#define UART_TM4C123GH6PM_REGISTERS_H





#include"Std_Types.h"


#define UART0_BASE_ADDRESS         (0x4000C000)
#define UART1_BASE_ADDRESS         (0x4000D000)
#define UART2_BASE_ADDRESS         (0x4000E000)
#define UART3_BASE_ADDRESS         (0x4000F000)
#define UART4_BASE_ADDRESS         (0x40010000)
#define UART5_BASE_ADDRESS         (0x40011000)
#define UART6_BASE_ADDRESS         (0x40012000)
#define UART7_BASE_ADDRESS         (0x40013000)




typedef struct{

	
	volatile uint32 UARTDR;
	volatile uint32 UARTRSR_UARTECR;	/*<______*/
	volatile uint32 RESERVED_1[4];
		
	volatile uint32 UARTFR;
	volatile uint32 RESERVED_2;
	volatile uint32 UARTILPR;
		
	volatile uint32 UARTIBRD;
	volatile uint32 UARTFBRD;
	volatile uint32 UARTLCRH;
		
	volatile uint32 UARTCTL;
	volatile uint32 UARTIFLS;
	volatile uint32 UARTIM;
		
	volatile uint32 UARTRIS;
	volatile uint32 UARTMIS;
	volatile uint32 UARTICR;
	
	volatile uint32 UARTDMACTL;
	volatile uint32 RESERVED_3[22];
	volatile uint32 UART9BITADDR;
	
	volatile uint32 UART9BITAMASK;
	volatile uint32 RESERVED_4[965];
	volatile uint32 UARTPP;
	
	volatile uint32 RESERVED_5;
	volatile uint32 UARTCC;

/*
volatile uint32 RESERVED_6;
volatile uint32 UARTPeriphID4;
volatile uint32 UARTPeriphID5;
volatile uint32 UARTPeriphID6;
volatile uint32 UARTPeriphID7;
volatile uint32 UARTPeriphID0;
volatile uint32 UARTPeriphID1;
volatile uint32 UARTPeriphID2;
volatile uint32 UARTPeriphID3;
volatile uint32 UARTPCellID0;
volatile uint32 UARTPCellID1;
volatile uint32 UARTPCellID2;
volatile uint32 UARTPCellID3;
*/	
	


}UART_TYPE;




#define UART0    ( (volatile UART_TYPE*)(UART0_BASE_ADDRESS) ) 
#define UART1    ( (volatile UART_TYPE*)(UART1_BASE_ADDRESS) ) 
#define UART2    ( (volatile UART_TYPE*)(UART2_BASE_ADDRESS) ) 
#define UART3    ( (volatile UART_TYPE*)(UART3_BASE_ADDRESS) ) 
#define UART4    ( (volatile UART_TYPE*)(UART4_BASE_ADDRESS) ) 
#define UART5    ( (volatile UART_TYPE*)(UART5_BASE_ADDRESS) ) 
#define UART6    ( (volatile UART_TYPE*)(UART6_BASE_ADDRESS) ) 
#define UART7    ( (volatile UART_TYPE*)(UART7_BASE_ADDRESS) ) 
	



#define UART_ENABLE_BIT         0


#define PARITY_ENABLE_BIT       1
#define EVEN_PARITY_SELECT_BIT  2
#define STOP_BITS_SELECT_BIT    3   

#define TRANSMITT_ENABLE_BIT    8
#define RECEIVE_ENABLE_BIT      9



#endif
