 /********************************************\
Module:       TM4C123GH6PM Registers.
File name:    tm4c123gh6pm_registers.h
Version:      1.0.0
Author:       Ahmed Omar Sallam
Description:  
\********************************************/



#ifndef TM4C123GH6PM_REGISTERS_H
#define TM4C123GH6PM_REGISTERS_H


#include "Std_Types.h"


#define SYS_CONTROL_BASE_ADD 							0x400FE000

/*----------------------------------*/

#define RCC 			( *( (volatile uint32*)(SYS_CONTROL_BASE_ADD + 0X060) ))			/* Run-Mode Clock Configuration, RCC */
#define RCC2 			( *( (volatile uint32*)(SYS_CONTROL_BASE_ADD + 0X070) ))	    /* Run-Mode Clock Configuration 2, RCC2 */


#define RCGCGPIO 		( *( (volatile uint32*)(SYS_CONTROL_BASE_ADD + 0x608) ))	    /* General-Purpose Input/Output Run Mode Clock Gating Control */

/*----
 * Run Mode Clock Gating Control Register 0.
 *----------------*/
#define RCGC0       ( *( (volatile uint32*)(SYS_CONTROL_BASE_ADD + 0x100) ))   

#define RCGC2 		( *( (volatile uint32*)(SYS_CONTROL_BASE_ADD + 0x108) ))	    /* Run Mode Clock Gating Control Register 2 */



/*----
 * Pulse Width Modulator Run Mode Clock Gating Control.
 *----------------*/
#define RCGCPWM    ( *( (volatile uint32*)(SYS_CONTROL_BASE_ADD + 0x640) ))


 



/*----
 * Universal Asynchronous Receiver/Transmitter Run Mode Clock Gating Control.
 *----------------*/
#define RCGCUART     ( *( (volatile uint32*)(SYS_CONTROL_BASE_ADD + 0x618) ))





















/*=========================+-------------------------------+=========================*/
/*=========================|      GPT Register Map         |=========================*/
/*=========================+-------------------------------+=========================*/







#define TIMER_0_16_32_BIT_BASE_ADDRESS                     0x40030000
#define TIMER_1_16_32_BIT_BASE_ADDRESS                     0x40031000
#define TIMER_2_16_32_BIT_BASE_ADDRESS                     0x40032000
#define TIMER_3_16_32_BIT_BASE_ADDRESS                     0x40033000
#define TIMER_4_16_32_BIT_BASE_ADDRESS                     0x40034000
#define TIMER_5_16_32_BIT_BASE_ADDRESS                     0x40035000

#define TIMER_0_32_64_BIT_BASE_ADDRESS                     0x40036000
#define TIMER_1_32_64_BIT_BASE_ADDRESS                     0x40037000
#define TIMER_2_32_64_BIT_BASE_ADDRESS                     0x4004C000
#define TIMER_3_32_64_BIT_BASE_ADDRESS                     0x4004D000
#define TIMER_4_32_64_BIT_BASE_ADDRESS                     0x4004E000
#define TIMER_5_32_64_BIT_BASE_ADDRESS                     0x4004F000

typedef struct{
	
    volatile uint32 GPTMCFG;
    volatile uint32 GPTMTAMR;
    volatile uint32 GPTMTBMR;
    volatile uint32 GPTMCTL;
    volatile uint32 GPTMSYNC;
	volatile uint32 RESERVED_1;
    volatile uint32 GPTMIMR;
    volatile uint32 GPTMRIS;
    volatile uint32 GPTMMIS;
    volatile uint32 GPTMICR;
    volatile uint32 GPTMTAILR;
    volatile uint32 GPTMTBILR;
    volatile uint32 GPTMTAMATCHR;
    volatile uint32 GPTMTBMATCHR;
    volatile uint32 GPTMTAPR;
    volatile uint32 GPTMTBPR;
    volatile uint32 GPTMTAPMR;
    volatile uint32 GPTMTBPMR;
    volatile uint32 GPTMTAR;
    volatile uint32 GPTMTBR;
    volatile uint32 GPTMTAV;
    volatile uint32 GPTMTBV;
    volatile uint32 GPTMRTCPD;
    volatile uint32 GPTMTAPS;
    volatile uint32 GPTMTBPS;
    volatile uint32 GPTMTAPV;
    volatile uint32 GPTMTBPV;
	volatile uint32 RESERVED_2[981];
    volatile uint32 GPTMPP;
	
}TIMER_TYPE;


#define TIMER0_16_32         ( (volatile TIMER_TYPE*)( TIMER_0_16_32_BIT_BASE_ADDRESS ) )
#define TIMER1_16_32         ( (volatile TIMER_TYPE*)( TIMER_1_16_32_BIT_BASE_ADDRESS ) )
#define TIMER2_16_32         ( (volatile TIMER_TYPE*)( TIMER_2_16_32_BIT_BASE_ADDRESS ) )
#define TIMER3_16_32         ( (volatile TIMER_TYPE*)( TIMER_3_16_32_BIT_BASE_ADDRESS ) )
#define TIMER4_16_32         ( (volatile TIMER_TYPE*)( TIMER_4_16_32_BIT_BASE_ADDRESS ) )
#define TIMER5_16_32         ( (volatile TIMER_TYPE*)( TIMER_5_16_32_BIT_BASE_ADDRESS ) )

#define TIMER0_32_16         ( (volatile TIMER_TYPE*)( TIMER_0_32_64_BIT_BASE_ADDRESS ) )
#define TIMER1_32_16         ( (volatile TIMER_TYPE*)( TIMER_1_32_64_BIT_BASE_ADDRESS ) )
#define TIMER2_32_16         ( (volatile TIMER_TYPE*)( TIMER_2_32_64_BIT_BASE_ADDRESS ) )
#define TIMER3_32_16         ( (volatile TIMER_TYPE*)( TIMER_3_32_64_BIT_BASE_ADDRESS ) )
#define TIMER4_32_16         ( (volatile TIMER_TYPE*)( TIMER_4_32_64_BIT_BASE_ADDRESS ) )
#define TIMER5_32_16         ( (volatile TIMER_TYPE*)( TIMER_5_32_64_BIT_BASE_ADDRESS ) )





/*=========================+-------------------------------+=========================*/
/*=========================|      PWM Register Map         |=========================*/
/*=========================+-------------------------------+=========================*/




#define PWM0_BASE_ADDRESS               0x40028000
#define PWM1_BASE_ADDRESS               0x40029000


typedef struct{
	
    volatile uint32 PWMCTL;
    volatile uint32 PWMSYNC;
    volatile uint32 PWMENABLE;
    volatile uint32 PWMINVERT;
	
    volatile uint32 PWMFAULT;
    volatile uint32 PWMINTEN;
    volatile uint32 PWMRIS;
    volatile uint32 PWMISC;
	
    volatile uint32 PWMSTATUS;
    volatile uint32 PWMFAULTVAL;
    volatile uint32 PWMENUPD;
	volatile uint32 RESERVED_1[5];
	
    volatile uint32 PWM0CTL;
    volatile uint32 PWM0INTEN;
    volatile uint32 PWM0RIS;
    volatile uint32 PWM0ISC;
	
    volatile uint32 PWM0LOAD;
    volatile uint32 PWM0COUNT;
    volatile uint32 PWM0CMPA;
    volatile uint32 PWM0CMPB;
	
    volatile uint32 PWM0GENA;
    volatile uint32 PWM0GENB;
    volatile uint32 PWM0DBCTL;
    volatile uint32 PWM0DBRISE;
	
    volatile uint32 PWM0DBFALL;
    volatile uint32 PWM0FLTSRC0;
    volatile uint32 PWM0FLTSRC1;
    volatile uint32 PWM0MINFLTPER; /**/
	
	
    volatile uint32 PWM1CTL;
    volatile uint32 PWM1INTEN;
    volatile uint32 PWM1RIS;
    volatile uint32 PWM1ISC;
    volatile uint32 PWM1LOAD;
    volatile uint32 PWM1COUNT;
    volatile uint32 PWM1CMPA;
    volatile uint32 PWM1CMPB;
    volatile uint32 PWM1GENA;
    volatile uint32 PWM1GENB;
    volatile uint32 PWM1DBCTL;
    volatile uint32 PWM1DBRISE;
    volatile uint32 PWM1DBFALL;
    volatile uint32 PWM1FLTSRC0;
    volatile uint32 PWM1FLTSRC1;
    volatile uint32 PWM1MINFLTPER;
    volatile uint32 PWM2CTL;
    volatile uint32 PWM2INTEN;
    volatile uint32 PWM2RIS;
    volatile uint32 PWM2ISC;
    volatile uint32 PWM2LOAD;
    volatile uint32 PWM2COUNT;
    volatile uint32 PWM2CMPA;
    volatile uint32 PWM2CMPB;
    volatile uint32 PWM2GENA;
    volatile uint32 PWM2GENB;
    volatile uint32 PWM2DBCTL;
    volatile uint32 PWM2DBRISE;
    volatile uint32 PWM2DBFALL;
    volatile uint32 PWM2FLTSRC0;
    volatile uint32 PWM2FLTSRC1;
    volatile uint32 PWM2MINFLTPER;
    volatile uint32 PWM3CTL;
    volatile uint32 PWM3INTEN;
    volatile uint32 PWM3RIS;
    volatile uint32 PWM3ISC;
    volatile uint32 PWM3LOAD;
    volatile uint32 PWM3COUNT;
    volatile uint32 PWM3CMPA;
    volatile uint32 PWM3CMPB;
    volatile uint32 PWM3GENA;
    volatile uint32 PWM3GENB;
    volatile uint32 PWM3DBCTL;
    volatile uint32 PWM3DBRISE;
    volatile uint32 PWM3DBFALL;
    volatile uint32 PWM3FLTSRC0;
    volatile uint32 PWM3FLTSRC1;
    volatile uint32 PWM3MINFLTPER;
	
	volatile uint32 RESERVED_2[432];
	
    volatile uint32 PWM0FLTSEN;
    volatile uint32 PWM0FLTSTAT0;
    volatile uint32 PWM0FLTSTAT1;
	volatile uint32 RESERVED_3[29];
    volatile uint32 PWM1FLTSEN;
    volatile uint32 PWM1FLTSTAT0;
    volatile uint32 PWM1FLTSTAT1;
	volatile uint32 RESERVED_4[30];
    volatile uint32 PWM2FLTSTAT0;
    volatile uint32 PWM2FLTSTAT1;
	volatile uint32 RESERVED_5[30];
    volatile uint32 PWM3FLTSTAT0;
    volatile uint32 PWM3FLTSTAT1;
	volatile uint32 RESERVED_6[397];	
    volatile uint32 PWMPP;
	
}PWM_TYPE;


#define PWM_M0 					( ( (volatile PWM_TYPE*)(PWM0_BASE_ADDRESS) ) )
#define PWM_M1 					( ( (volatile PWM_TYPE*)(PWM1_BASE_ADDRESS) ) )




#define PWM_BLOCK_ENABLE_BIT  0
#define PWM_COUNTER_MODE_BIT  1





#endif	/* TM4C123GH6PM_REGISTERS_H */





































