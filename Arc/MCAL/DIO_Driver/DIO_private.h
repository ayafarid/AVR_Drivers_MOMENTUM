#ifndef _DIO_PRIVATE_H
#define _DIO_PRIVATE_H

// Part A RIGISTER
#define DDRA * ( (u8 volatile *) 0x3A )
#define PORTA * ( (u8 volatile *) 0x3B )
#define PINA * ( (u8 volatile *) 0x39 )

// Part B RIGISTER
#define DDRB * ( (u8 volatile *) 0x37)
#define PORTB * ( (u8 volatile *) 0x38 )
#define PINB * ( (u8 volatile *) 0x36 )

// Part C RIGISTER
#define DDRC * ( (u8 volatile *) 0x34)
#define PORTC * ( (u8 volatile *) 0x35 )
#define PINC * ( (u8 volatile *) 0x33 )

// Part D RIGISTER
#define DDRD * ( (u8 volatile *) 0x31)
#define PORTD * ( (u8 volatile *) 0x32 )
#define PIND * ( (u8 volatile *) 0x30 )
#endif
