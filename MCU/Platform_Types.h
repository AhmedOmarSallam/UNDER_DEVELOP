/********************************************\
@Module:       Platform types
@File Name:    Platform_Types.h
@Version:      1.0.0
@Author:       Ahmed Omar Sallam
@Description:  
\********************************************/




#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H





/**************************+-------------------------------+**************************/
/**************************|        Type definitions       |**************************/
/**************************+-------------------------------+**************************/






/* [SWS_Platform_00026] */
/* [SWS_Platform_00027] */
typedef unsigned char             boolean;			    /*	TRUE or FALSE */



											       /*  --AUTOSAR Integer Data Types, Fixed size guaranteed-- */
 
/* SWS_Platform_00013 */
typedef unsigned char             uint8; 		    /* 	                0..255 	                 */
 	 	 	 	 	 	 	 	 	 	 
/* SWS_Platform_00014 */
typedef unsigned short int        uint16; 		   /*                  0..65535                  */

/* SWS_Platform_00015 */
typedef unsigned long int         uint32; 		   /*               0..4294967295                */

/* SWS_Platform_00066 */
typedef unsigned long long        uint64;		     /*           0..18446744073709551615          */

/* SWS_Platform_00016 */
typedef signed char               sint8; 		     /*				         	-128..127                  */

/* SWS_Platform_00017 */
typedef signed short int          sint16; 		   /*	              -32768..32767                */

/* SWS_Platform_00018 */
typedef signed long int           sint32;		     /*	 	       -2147483648..2147483647           */

/* SWS_Platform_00067 */
typedef signed long long          sint64; 		   /*	-9223372036854775808..9223372036854775807    */

					/*--------------------------*/					/*--------------------------*/
 
/*  AUTOSAR Integer Data Types, Minimum size guaranteed. */

 /* SWS_Platform_00020 */
typedef unsigned char       uint8_least;


/* SWS_Platform_00021 */
typedef unsigned short int  uint16_least;


/* SWS_Platform_00022 */
typedef unsigned long int   uint32_least;


/* SWS_Platform_00023 */
typedef signed char         sint8_least;


/* SWS_Platform_00024 */
typedef signed char         sint16_least;

					/*--------------------------*/					/*--------------------------*/
					
/* SWS_Platform_00041 */
typedef float 							float32;

/* SWS_Platform_00042 */
typedef double 							float64;
	
					/*--------------------------*/					/*--------------------------*/

/* [SWS_Platform_91001] */
typedef void* 						  VoidPtr;

/* [SWS_Platform_91002] */
typedef const void*         ConstVoidPtr;

					/*--------------------------*/					/*--------------------------*/



#define UINT8_MIN             0
#define UINT8_MAX             255
													    
#define UINT16_MIN            0
#define UINT16_MAX            65535
													    
#define UINT32_MIN            0
#define UINT32_MAX            4294967295
													    
#define UINT64_MIN            0
#define UINT64_MAX            18446744073709551615
													    
													    
#define SINT8_MIN             -128
#define SINT8_Max             127
													    
#define SINT16_MIN            -32768
#define SINT16_Max            32767
													    
#define SINT32_MIN            -2147483648
#define SINT32_Max            2147483647
													    
#define SINT64_MIN            -9223372036854775808
#define SINT64_Max            9223372036854775807
													    
															
#define FLOAT32_MIN           1.17549435e-38
#define FLOAT32_MAX           3.40282347e+38
#define FLOAT32_EPSILON       1.19209290e-07

												
#define FLOAT64_MIN           2.2250738585072014e-308
#define FLOAT64_MAX           1.7976931348623157e+308
#define FLOAT64_EPSILON       2.2204460492503131e-16


/**************************+-------------------------------+**************************/
/**************************|      Symbol definitions       |**************************/
/**************************+-------------------------------+**************************/


#define CPU_TYPE_8 					    8		  /* Indicating a 8 bit processor.  */
#define CPU_TYPE_16 				    16		/* Indicating a 16 bit processor. */
#define CPU_TYPE_32 				    32		/* Indicating a 32 bit processor. */
#define CPU_TYPE_64 				    64		/* Indicating a 64 bit processor. */
														    
 
 
#define MSB_FIRST				        0		/* The most significant bit is the first bit of the bit sequence. */
#define LSB_FIRST				        1		/* The least significant bit is the first bit of the bit sequence. */

#define HIGH_BYTE_FIRST 		   	0		/* Within uint16, the high byte is located before the low byte */
#define LOW_BYTE_FIRST			  	1		/* Within uint16, the low byte is located before the high byte. */


/* [SWS_Platform_00056] */
/* [SWS_Platform_00054] */

#ifndef TRUE
#define TRUE   0x01
#endif
#ifndef FALSE
#define FALSE  0x00
#endif



		/*-- For TM4C Microcontroller platforms. --*/

/* [SWS_Platform_00064] */ 
#define CPU_TYPE		 			CPU_TYPE_32

/* [SWS_Platform_00038] */
#define CPU_BIT_ORDER	  	LSB_FIRST

/* [SWS_Platform_00039] */
#define CPU_BYTE_ORDER		LOW_BYTE_FIRST

 
 



#endif	/* PLATFORM_TYPES_H */ 
