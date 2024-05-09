#include"Port.h"
#include"Uart.h"


#include"tm4c123gh6pm_registers.h"
#include"Port_TM4C123GH6PM_Registers.h"

//#include"TM4C123GH6PM.h"

int main(void){

	uint32 charac;
	
	/* Enable the clock for the PORT A. */
	RCGCGPIO |= 1<<0;
	
	/* Enable the clock for the PORT F. */
	RCGCGPIO |= 1<<5;
	
	/* Enable the clock for the PORT D. */
	RCGCGPIO |= 1<<3;
	
	/* Enable UART Module 0 Run Mode Clock Gating Control */
	RCGCUART |= 1<<0;
	
		/* Enable UART Module 1 Run Mode Clock Gating Control */
	RCGCUART |= 1<<1;


	Port_Init(Port_Coniguration);		
	
	Uart_Init(Uart_Configuration);
	
//			GPIO_PORT_F_APB->GPIODATA = 2;

//	Uart_Transmitt(UART_MODULE1, 'a');
	
//Port_SetPinMode(PF2, PORT_PIN_MODE_PWM);	
while(1){
//	Uart_Transmitt(UART_MODULE0, 'a');

	
	charac = Uart_Receive(UART_MODULE1);
	for(volatile int i = 0; i < 10; i++){}
	if(charac == 'a'){
			GPIO_PORT_F_APB->GPIODATA = 2;
	}else if(charac == 'b'){
			GPIO_PORT_F_APB->GPIODATA = 0;
	}else{}
	
}

	


}


