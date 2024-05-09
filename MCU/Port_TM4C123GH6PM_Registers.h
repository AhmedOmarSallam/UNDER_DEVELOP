




#ifndef PORT_TM4C123GH6PM_REGISTERS_H
#define PORT_TM4C123GH6PM_REGISTERS_H


#include"Std_Types.h"


/*=========================+-------------------------------+=========================*/
/*=========================|      GPIO Register Map        |=========================*/
/*=========================+-------------------------------+=========================*/


#define GPIO_PORT_A_APB_BASE_ADDRESS 		   0x40004000
#define GPIO_PORT_B_APB_BASE_ADDRESS           0x40005000
#define GPIO_PORT_C_APB_BASE_ADDRESS           0x40006000
#define GPIO_PORT_D_APB_BASE_ADDRESS           0x40007000
#define GPIO_PORT_E_APB_BASE_ADDRESS           0x40024000
#define GPIO_PORT_F_APB_BASE_ADDRESS           0x40025000

#define GPIO_PORT_A_AHB_BASE_ADDRESS           0x40058000
#define GPIO_PORT_B_AHB_BASE_ADDRESS           0x40059000
#define GPIO_PORT_C_AHB_BASE_ADDRESS           0x4005A000
#define GPIO_PORT_D_AHB_BASE_ADDRESS           0x4005B000
#define GPIO_PORT_E_AHB_BASE_ADDRESS           0x4005C000
#define GPIO_PORT_F_AHB_BASE_ADDRESS           0x4005D000




typedef struct{

    uint32 RESSERVED_1[255];
	uint32 GPIODATA; 
/**/
    uint32 GPIODIR;                  
    uint32 GPIOIS;                   
    uint32 GPIOIBE;                  
    uint32 GPIOIEV;                  
    uint32 GPIOIM;                   
    uint32 GPIORIS;                  
    uint32 GPIOMIS;                  
	uint32 GPIOICR;                  
    uint32 GPIOAFSEL;
    uint32 RESERVED_2[55]; 	
    uint32 GPIODR2R;                 
    uint32 GPIODR4R;                 
    uint32 GPIODR8R;                 
    uint32 GPIOODR;                  
    uint32 GPIOPUR;                  
    uint32 GPIOPDR;                  
    uint32 GPIOSLR;                  
    uint32 GPIODEN;                  
    uint32 GPIOLOCK;                 
    uint32 GPIOCR;                   
    uint32 GPIOAMSEL;                
    uint32 GPIOPCTL;                 
    uint32 GPIOADCCTL;               
    uint32 GPIODMACTL; 
/**/		
    uint32 GPIOPeriphID4;            
    uint32 GPIOPeriphID5;            
    uint32 GPIOPeriphID6;            
    uint32 GPIOPeriphID7;            
    uint32 GPIOPeriphID0;            
    uint32 GPIOPeriphID1;            
    uint32 GPIOPeriphID2;            
    uint32 GPIOPeriphID3;            
	uint32 GPIOPCellID0;             
    uint32 GPIOPCellID1;             
    uint32 GPIOPCellID2;             
    uint32 GPIOPCellID3;             
    	
}GPIO_TYPE;



#define GPIO_PORT_A_APB         ( (volatile GPIO_TYPE*)( GPIO_PORT_A_APB_BASE_ADDRESS ) )
#define GPIO_PORT_B_APB         ( (volatile GPIO_TYPE*)( GPIO_PORT_B_APB_BASE_ADDRESS ) )
#define GPIO_PORT_C_APB         ( (volatile GPIO_TYPE*)( GPIO_PORT_C_APB_BASE_ADDRESS ) )

#define GPIO_PORT_D_APB         ( (volatile GPIO_TYPE*)( GPIO_PORT_D_APB_BASE_ADDRESS ) )
#define GPIO_PORT_E_APB         ( (volatile GPIO_TYPE*)( GPIO_PORT_E_APB_BASE_ADDRESS ) )
#define GPIO_PORT_F_AHB         ( (volatile GPIO_TYPE*)( GPIO_PORT_F_AHB_BASE_ADDRESS ) )
	
#define GPIO_PORT_A_AHB         ( (volatile GPIO_TYPE*)( GPIO_PORT_A_AHB_BASE_ADDRESS ) )
#define GPIO_PORT_B_AHB         ( (volatile GPIO_TYPE*)( GPIO_PORT_B_AHB_BASE_ADDRESS ) )
#define GPIO_PORT_C_AHB         ( (volatile GPIO_TYPE*)( GPIO_PORT_C_AHB_BASE_ADDRESS ) )

#define GPIO_PORT_D_AHB         ( (volatile GPIO_TYPE*)( GPIO_PORT_D_AHB_BASE_ADDRESS ) )
#define GPIO_PORT_E_AHB         ( (volatile GPIO_TYPE*)( GPIO_PORT_E_AHB_BASE_ADDRESS ) )
#define GPIO_PORT_F_APB         ( (volatile GPIO_TYPE*)( GPIO_PORT_F_APB_BASE_ADDRESS ) )



#define GPIOLOCK_KEY 				( (uint32)0x4C4F434B )
#define GPIOLOCK_UNLOCKED_STATUS    ( (uint32)0x00 )







#endif
