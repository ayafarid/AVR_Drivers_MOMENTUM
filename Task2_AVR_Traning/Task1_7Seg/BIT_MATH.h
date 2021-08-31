#ifndef _BIT_MATH_H
#define _BIT_MATH_H

#define SET_BIT(BYTE,BIT_NO) BYTE |= (0x01 << BIT_NO)
#define CLEAR_BIT(BYTE,BIT_NO) BYTE &= ~(1 << BIT_NO)
#define TOG_BIT(BYTE,BIT_NO) BYTE ^= (1 << BIT_NO)
#define GET_BIT(BYTE,BIT_NO) (0x01 & (BYTE >> BIT_NO))

#endif
