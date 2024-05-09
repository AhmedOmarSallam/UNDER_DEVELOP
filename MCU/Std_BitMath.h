


#ifndef STD_BITMATH_H
#define STD_BITMATH_H




/* 
 * Sets a specefied bit in a specified register.
 * Parmeters: 'REG'               -> This will be a register in the microcontroller.
 *            'BIT_FIELD_NUMBER'  -> Represent the bit number in the register.
 */
#define SET_REG(REG, BIT_FIELD_NUMBER)    (REG |= (1 << BIT_FIELD_NUMBER))

/* 
 * Clears a specefied bit in a specified register.
 * Parmeters: 'REG'               -> This will be a register in the microcontroller.
 *            'BIT_FIELD_NUMBER'  -> Represent the bit number in the register.
 */
#define CLR_REG(REG, BIT_FIELD_NUMBER)    (REG &= (~((uint32)1 << BIT_FIELD_NUMBER)))




#endif
