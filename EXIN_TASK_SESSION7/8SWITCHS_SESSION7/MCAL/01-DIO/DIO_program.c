#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATHS.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

#include <util/delay.h>
void DIO_voidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction) {
	switch (Copy_u8Port) {
	case DIO_u8_PORTA:
		DDRA = Copy_u8Direction;
		break;
	case DIO_u8_PORTB:
		DDRB = Copy_u8Direction;
		break;
	case DIO_u8_PORTC:
		DDRC = Copy_u8Direction;
		break;
	case DIO_u8_PORTD:
		DDRD = Copy_u8Direction;
		break;
	}
}

void DIO_voidSetPortValue(u8 Copy_u8Port, u8 Copy_u8Value) {
	switch (Copy_u8Port) {
	case DIO_u8_PORTA:
		PORTA = Copy_u8Value;
		break;
	case DIO_u8_PORTB:
		PORTB = Copy_u8Value;
		break;
	case DIO_u8_PORTC:
		PORTC = Copy_u8Value;
		break;
	case DIO_u8_PORTD:
		PORTD = Copy_u8Value;
		break;
	}

}

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction) {

	switch (Copy_u8Port) {

	case DIO_u8_PORTA:

		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
			CLR_BIT(DDRA, Copy_u8Pin);
			break;
		case DIO_u8_OUTPUT:
			SET_BIT(DDRA, Copy_u8Pin);
			break;
		}
		break;
	case DIO_u8_PORTB:

		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
			CLR_BIT(DDRB, Copy_u8Pin);
			break;
		case DIO_u8_OUTPUT:
			SET_BIT(DDRB, Copy_u8Pin);
			break;
		}

		break;
	case DIO_u8_PORTC:

		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
			CLR_BIT(DDRC, Copy_u8Pin);
			break;
		case DIO_u8_OUTPUT:
			SET_BIT(DDRC, Copy_u8Pin);
			break;
		}

		break;
	case DIO_u8_PORTD:

		switch (Copy_u8Direction) {
		case DIO_u8_INPUT:
			CLR_BIT(DDRD, Copy_u8Pin);
			break;
		case DIO_u8_OUTPUT:
			SET_BIT(DDRD, Copy_u8Pin);
			break;
		}

		break;
	}
}

void DIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value) {
	switch (Copy_u8Port) {

	case DIO_u8_PORTA:

		switch (Copy_u8Value) {
		case DIO_u8_LOW:
			CLR_BIT(PORTA, Copy_u8Pin);
			break;
		case DIO_u8_HIGH:
			SET_BIT(PORTA, Copy_u8Pin);
			break;
		}
		break;
	case DIO_u8_PORTB:

		switch (Copy_u8Value) {
		case DIO_u8_LOW:
			CLR_BIT(PORTB, Copy_u8Pin);
			break;
		case DIO_u8_HIGH:
			SET_BIT(PORTB, Copy_u8Pin);
			break;
		}

		break;
	case DIO_u8_PORTC:

		switch (Copy_u8Value) {
		case DIO_u8_LOW:
			CLR_BIT(PORTC, Copy_u8Pin);
			break;
		case DIO_u8_HIGH:
			SET_BIT(PORTC, Copy_u8Pin);
			break;
		}

		break;
	case DIO_u8_PORTD:

		switch (Copy_u8Value) {
		case DIO_u8_LOW:
			CLR_BIT(PORTD, Copy_u8Pin);
			break;
		case DIO_u8_HIGH:
			SET_BIT(PORTD, Copy_u8Pin);
			break;
		}

		break;
	}
}


u8 DIO_u8ReadPinValue(u8 Copy_u8Port, u8 Copy_u8Pin){
	u8 LOC_u8PinState = 0;
	switch(Copy_u8Port){
	case DIO_u8_PORTA:
		LOC_u8PinState = GET_BIT(PINA , Copy_u8Pin);
		break;
	case DIO_u8_PORTB:
		LOC_u8PinState = GET_BIT(PINB , Copy_u8Pin);
		break;
	case DIO_u8_PORTC:
		LOC_u8PinState = GET_BIT(PINC , Copy_u8Pin);
		break;
	case DIO_u8_PORTD:
		LOC_u8PinState = GET_BIT(PIND , Copy_u8Pin);
		break;
	}

	return LOC_u8PinState;
}


void DIO_voidActivePullUp(u8 Copy_u8Port, u8 Copy_u8Pin){

	switch(Copy_u8Port){
	case DIO_u8_PORTA:
		CLR_BIT(DDRA,Copy_u8Pin);
		SET_BIT(PORTA,Copy_u8Pin);
		break;
	case DIO_u8_PORTB:
		CLR_BIT(DDRB,Copy_u8Pin);
		SET_BIT(PORTB,Copy_u8Pin);
		break;
	case DIO_u8_PORTC:
		CLR_BIT(DDRC,Copy_u8Pin);
		SET_BIT(PORTC,Copy_u8Pin);
		break;
	case DIO_u8_PORTD:
		CLR_BIT(DDRD,Copy_u8Pin);
		SET_BIT(PORTD,Copy_u8Pin);
		break;
	}
}
void DIO_voidTogglePin(u8 Copy_u8Port , u8 Copy_u8Pin){
	switch(Copy_u8Port){
	case DIO_u8_PORTA:
		TOGGLE_BIT(PORTA,Copy_u8Pin);
		break;
	case DIO_u8_PORTB:
		TOGGLE_BIT(PORTB,Copy_u8Pin);

		break;
	case DIO_u8_PORTC:
		TOGGLE_BIT(PORTC,Copy_u8Pin);

		break;
	case DIO_u8_PORTD:
		TOGGLE_BIT(PORTD,Copy_u8Pin);

		break;
	}
}

void DIO_voidFlash(u8 Copy_u8Port)
{
    for(u8 i=0 ; i<8 ; i++)
    {
        DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_HIGH);
    }
    _delay_ms(delay);
    for(u8 i=0 ; i<8 ; i++)
    {
        DIO_voidSetPinValue(DIO_u8_PORTA,i,0);
    }
    _delay_ms(delay);
}
void DIO_voidShiftRight(u8 Copy_u8Port)
{
	DIO_voidSetPortValue(DIO_u8_PORTA,DIO_u8_PORT_LOW);
    for(u8 i=0 ; i<8 ; i++)
    {
        DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_HIGH);
        _delay_ms(delay);
    }
    DIO_voidSetPortValue(DIO_u8_PORTA,DIO_u8_PORT_LOW);
    _delay_ms(delay);
}
void DIO_voidShiftLeft(u8 Copy_u8Port)
{
    for(int i=0,j=7; i<4&&j>3; i++,j--)
    {
        DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_HIGH);
        DIO_voidSetPinValue(DIO_u8_PORTA,j,DIO_u8_HIGH);
        _delay_ms(delay);
    }
    DIO_voidSetPortValue(DIO_u8_PORTA,DIO_u8_PORT_LOW);
    _delay_ms(delay);
}
void DIO_voidMedium(u8 Copy_u8Port)
{
    for(int i=3,j=4; i>=0&&j<8; i--,j++)
    {
        DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_HIGH);
        DIO_voidSetPinValue(DIO_u8_PORTA,j,DIO_u8_HIGH);
        _delay_ms(delay);
    }
    DIO_voidSetPortValue(DIO_u8_PORTA,DIO_u8_PORT_LOW);
    _delay_ms(delay);
}
void DIO_voidRightLeft(u8 Copy_u8Port)
{
	DIO_voidSetPortValue(DIO_u8_PORTA,DIO_u8_PORT_LOW);
    for(u8 i=7 ; i>0 ; i--)
    {
        DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_HIGH);
        _delay_ms(delay);
    }
    DIO_voidSetPinValue(DIO_u8_PORTA,0,DIO_u8_HIGH);
    _delay_ms(delay);
    DIO_voidSetPortValue(DIO_u8_PORTA,DIO_u8_PORT_LOW);
}
