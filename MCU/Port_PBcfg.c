


#include"Port.h"







const Port_ConfigType Port_Coniguration[] = {
	
	/* Port_A_Pin_0 */
	{
		.PortType           = PORT_A,
		.PinNumber          = PORT_A_PIN_0,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_UART,
		.PortPinLevelValue  = PORT_PIN_LEVEL_HIGH,
		.Drive_Strength     = DRIVE_2_MA,				    					    
	},                      
						    
	/* Port_A_Pin_1 */      
	{
		.PortType           = PORT_A,		
		.PinNumber          = PORT_A_PIN_1,
		.PinDirection       = PORT_PIN_OUT,
		.PinMode            = PORT_PIN_MODE_UART,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},
	
	/* Port_A_Pin_2 */
	{
		.PortType           = PORT_A,
		.PinNumber          = PORT_A_PIN_2,
		.PinDirection       = PORT_PIN_OUT,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_HIGH,
		.Drive_Strength     = DRIVE_2_MA,  
	},
	
	/* Port_A_Pin_3 */	
	{
		.PortType           = PORT_A,		
		.PinNumber 		    = PORT_A_PIN_3,
		.PinDirection 		= PORT_PIN_IN,
		.PinMode      		= PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},	
	
	/* Port_A_Pin_4 */			
	{
		.PortType           = PORT_A,		
		.PinNumber          = PORT_A_PIN_4,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},	
	
	/* Port_A_Pin_5 */			
    {
		.PortType           = PORT_A,		
		.PinNumber          = PORT_A_PIN_5,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},	
	
	/* Port_A_Pin_6 */				
	{
		.PortType           = PORT_A,
		.PinNumber          = PORT_A_PIN_6,
		.PinDirection       = PORT_PIN_OUT,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_HIGH,
		.Drive_Strength     = DRIVE_2_MA,  
	},	
	
	/* Port_A_Pin_7 */					
	{
		.PortType           = PORT_A,		
		.PinNumber          = PORT_A_PIN_7,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},	
	
					/*===================-----===================*/
	
	/* Port_B_Pin_0 */
	{
		.PortType           = PORT_B,
		.PinNumber          = PORT_B_PIN_0,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,
	},
	
	/* Port_B_Pin_1 */
	{
		.PortType           = PORT_B,		
		.PinNumber          = PORT_B_PIN_1,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},
	
	/* Port_B_Pin_2 */
	{
		.PortType           = PORT_B,				
		.PinNumber          = PORT_B_PIN_2,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,
	},
	
	/* Port_B_Pin_3 */
	{
		.PortType           = PORT_B,				
		.PinNumber          = PORT_B_PIN_3,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},	

	/* Port_B_Pin_4 */	
	{
		.PortType           = PORT_B,				
		.PinNumber          = PORT_B_PIN_4,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},	

	/* Port_B_Pin_5 */	
    {
		.PortType           = PORT_B,				
		.PinNumber          = PORT_B_PIN_5,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},	

	/* Port_B_Pin_6 */	
	{
		.PortType           = PORT_B,				
		.PinNumber          = PORT_B_PIN_6,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},	
	
	/* Port_B_Pin_7 */	
	{
		.PortType           = PORT_B,		
		.PinNumber          = PORT_B_PIN_7,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},	
	
					/*===================-----===================*/

	
	/* Port_C_Pin_0 */
	{
		.PortType           = PORT_C,				
		.PinNumber          = PORT_C_PIN_0,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},
	
	/* Port_C_Pin_1 */
	{
		.PortType           = PORT_C,						
		.PinNumber          = PORT_C_PIN_1,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},
	
	/* Port_C_Pin_2 */
	{
		.PortType           = PORT_C,						
		.PinNumber          = PORT_C_PIN_2,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},
	
	/* Port_C_Pin_3 */
	{
		.PortType           = PORT_C,						
		.PinNumber          = PORT_C_PIN_3,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},	
	
	/* Port_C_Pin_4 */
	{
		.PortType           = PORT_C,						
		.PinNumber          = PORT_C_PIN_4,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},	

	/* Port_C_Pin_5 */
    {
		.PortType           = PORT_C,				
		.PinNumber          = PORT_C_PIN_5,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},	
	
	/* Port_C_Pin_6 */
	{
		.PortType           = PORT_C,						
		.PinNumber          = PORT_C_PIN_6,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},	
	
	/* Port_C_Pin_7 */
	{
		.PortType           = PORT_C,					
		.PinNumber          = PORT_C_PIN_7,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},	

			/*===================-----===================*/
	
	/* Port_D_Pin_0 */
	{
		.PortType           = PORT_D,				
		.PinNumber          = PORT_D_PIN_0,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},

	/* Port_D_Pin_1 */	
	{
		.PortType           = PORT_D,						
		.PinNumber          = PORT_D_PIN_1,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},

	/* Port_D_Pin_2 */	
	{
		.PortType           = PORT_D,						
		.PinNumber          = PORT_D_PIN_2,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},

	/* Port_D_Pin_3 */	
	{
		.PortType           = PORT_D,						
		.PinNumber          = PORT_D_PIN_3,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},	

	/* Port_D_Pin_4 */		
	{
		.PortType           = PORT_D,						
		.PinNumber          = PORT_D_PIN_4,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},	

	/* Port_D_Pin_5 */
    {
		.PortType           = PORT_D,						
		.PinNumber          = PORT_D_PIN_5,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},	

	/* Port_D_Pin_6 */	
	{
		.PortType           = PORT_D,						
		.PinNumber          = PORT_D_PIN_6,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_UART,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},	

	/* Port_D_Pin_7 */	
	{
		.PortType           = PORT_D,						
		.PinNumber          = PORT_D_PIN_7,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_UART,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},	

			/*===================-----===================*/
	
	/* Port_E_Pin_0 */
	{
		.PortType           = PORT_E,							
		.PinNumber          = PORT_E_PIN_0,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,
	},

	/* Port_E_Pin_1 */	
	{
		.PortType           = PORT_E,									
		.PinNumber          = PORT_E_PIN_1,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},

	/* Port_E_Pin_2 */		
	{
		.PortType           = PORT_E,									
		.PinNumber          = PORT_E_PIN_2,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},

	/* Port_E_Pin_3 */		
	{
		.PortType           = PORT_E,									
		.PinNumber          = PORT_E_PIN_3,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},	
	
	/* Port_E_Pin_4 */			
	{
		.PortType           = PORT_E,									
		.PinNumber          = PORT_E_PIN_4,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,
	},	

	/* Port_E_Pin_5 */	
    {
		.PortType           = PORT_E,									
		.PinNumber          = PORT_E_PIN_5,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},	

		/*===================-----===================*/
	
    /* Port_F_Pin_0 */
	{
		.PortType           = PORT_F,									
		.PinNumber          = PORT_F_PIN_0,
		.PinDirection       = PORT_PIN_OUT,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},
	
    /* Port_F_Pin_1 */	
	{
		.PortType           = PORT_F,											
		.PinNumber          = PORT_F_PIN_1,
		.PinDirection       = PORT_PIN_OUT,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
//		.Pulling            = 
	},

    /* Port_F_Pin_2 */	
	{
		.PortType           = PORT_F,											
		.PinNumber          = PORT_F_PIN_2,
		.PinDirection       = PORT_PIN_OUT,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},

    /* Port_F_Pin_3 */	
	{
		.PortType           = PORT_F,											
		.PinNumber          = PORT_F_PIN_3,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA, 
	},	

    /* Port_F_Pin_4 */		
	{
		.PortType           = PORT_F,											
		.PinNumber          = PORT_F_PIN_4,
		.PinDirection       = PORT_PIN_IN,
		.PinMode            = PORT_PIN_MODE_DIO,
		.PortPinLevelValue  = PORT_PIN_LEVEL_LOW,
		.Drive_Strength     = DRIVE_2_MA,  
	},	

	
};

