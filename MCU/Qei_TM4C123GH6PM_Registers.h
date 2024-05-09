/********************************************\
* @Module       : QEI Driver.
* @FileName     : Qei_TM4C123GH6PM_Registers.h
* @Version      : 1.0.0
* @Author       : Ahmed Omar Sallam
* @Description  :  
\********************************************/



#ifndef QEI_TM4C123GH6PM_REGISTERS_H
#define QEI_TM4C123GH6PM_REGISTERS_H


#include"Std_Types.h"



#define QEI0_BASE_ADDRESS 	(0x4002C000)
#define QEI1_BASE_ADDRESS 	(0x4002D000)



typedef struct{

    volatile uint32 QEICTL;
    volatile uint32 QEISTAT;
    volatile uint32 QEIPOS;
    volatile uint32 QEIMAXPOS;
    volatile uint32 QEILOAD;
    volatile uint32 QEITIME;
    volatile uint32 QEICOUNT;
    volatile uint32 QEISPEED;
    volatile uint32 QEIINTEN;
    volatile uint32 QEIRIS;
    volatile uint32 QEIISC;

}QEI_TYPE;


#define QEI0     ( (volatile QEI_TYPE*)(QEI0_BASE_ADDRESS) )
#define QEI1     ( (volatile QEI_TYPE*)(QEI1_BASE_ADDRESS) )


	/*=========================================================================*/

#define QEI_ENABLE_BIT       0
#define QEI_SIGNAL_MODE_BIT  2
#define QEI_CAPTURE_MODE_BIT 3


#endif
