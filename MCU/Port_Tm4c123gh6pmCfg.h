

#ifndef PORT_TM4C123GH6PM_CFG_H
#define PORT_TM4C123GH6PM_CFG_H



typedef enum{
	
	/* PORTA pins. */
	PA0,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,
	
	/* PORTB pins. */	
	PB0,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,

	/* PORTC pins. */	
	PC0,
	PC1,
	PC2,
	PC3,
	PC4,
	PC5,
	PC6,
	PC7,	

	/* PORTD pins. */	
	PD0,
	PD1,
	PD2,
	PD3,
	PD4,
	PD5,
	PD6,
	PD7,
	
	/* PORTE pins. */		
	PE0,
	PE1,
	PE2,
	PE3,
	PE4,
	PE5,
	
	/* PORTF pins. */	
	PF0,
	PF1,
	PF2,
	PF3,
	PF4,
	
}GPIO_PINS;




				/*-------------------------------------------------------------*/

#define PORT_M0PWM0_PIN   PB6
#define PORT_M0PWM1_PIN   PB7

#define PORT_M0PWM2_PIN   PB4
#define PORT_M0PWM3_PIN   PB5

#define PORT_M0PWM4_PIN   PE4
#define PORT_M0PWM5_PIN   PE5

#define PORT_M0PWM6_PIN   PC4
#define PORT_M0PWM7_PIN   PC5
/**/
#define PORT_M1PWM0_PIN   PD0
#define PORT_M1PWM1_PIN   PD1

#define PORT_M1PWM2_PIN   PA6
#define PORT_M1PWM3_PIN   PA7

#define PORT_M1PWM4_PIN   PF0
#define PORT_M1PWM5_PIN   PF1

#define PORT_M1PWM6_PIN   PF2
#define PORT_M1PWM7_PIN   PF3



#define PORT_M0PWM_N_MUX_ENCODING  4
/*#define PORT_M0PWM1_MUX_ENCODING  4
#define PORT_M0PWM2_MUX_ENCODING  4
#define PORT_M0PWM3_MUX_ENCODING  4
#define PORT_M0PWM4_MUX_ENCODING  4
#define PORT_M0PWM5_MUX_ENCODING  4
#define PORT_M0PWM6_MUX_ENCODING  4
#define PORT_M0PWM7_MUX_ENCODING  4*/

#define PORT_M1PWM0_MUX_ENCODING  5
#define PORT_M1PWM1_MUX_ENCODING  5
#define PORT_M1PWM2_MUX_ENCODING  5
#define PORT_M1PWM3_MUX_ENCODING  5
#define PORT_M1PWM4_MUX_ENCODING  5
#define PORT_M1PWM5_MUX_ENCODING  5
#define PORT_M1PWM6_MUX_ENCODING  5
#define PORT_M1PWM7_MUX_ENCODING  5



/*=========================================================================*/
#define PORT_ENCODING_MUX_VALUE_1     0x01 
#define PORT_ENCODING_MUX_VALUE_2     0x02 
#define PORT_ENCODING_MUX_VALUE_3     0x03 

#define PORT_ENCODING_MUX_VALUE_4     0x04
#define PORT_ENCODING_MUX_VALUE_5     0x05
#define PORT_ENCODING_MUX_VALUE_6     0x06

#define PORT_ENCODING_MUX_VALUE_7     0x07
#define PORT_ENCODING_MUX_VALUE_8     0x08
#define PORT_ENCODING_MUX_VALUE_9     0x09

#define PORT_ENCODING_MUX_VALUE_A     0x0A
#define PORT_ENCODING_MUX_VALUE_B     0x0B
#define PORT_ENCODING_MUX_VALUE_C     0x0C

#define PORT_ENCODING_MUX_VALUE_D     0x0D
#define PORT_ENCODING_MUX_VALUE_E     0x0E
#define PORT_ENCODING_MUX_VALUE_F     0x0F






#endif
