/* Include File services */
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction)
{
	u8 LOC_ERROR_STATE = NOK;
	switch(Copy_u8Port)
	{
	case DIO_u8_PORTA:
		LOC_ERROR_STATE=OK;
		DDRA=Copy_u8Direction;
		break;
	case DIO_u8_PORTB:
		LOC_ERROR_STATE=OK;
		DDRB=Copy_u8Direction;
		break;
	case DIO_u8_PORTC:
		LOC_ERROR_STATE=OK;
		DDRC=Copy_u8Direction;
		break;
	case DIO_u8_PORTD:
		LOC_ERROR_STATE=OK;
		DDRD=Copy_u8Direction;
		break;
	}
}
void DIO_voidSetPortValue(u8 Copy_u8Port , u8 Copy_u8value)
{
	u8 LOC_ERROR_STATE = NOK;
	switch(Copy_u8Port)
	{
	case DIO_u8_PORTA:
		LOC_ERROR_STATE=OK;
		PORTA=Copy_u8value;
		break;
	case DIO_u8_PORTB:
		LOC_ERROR_STATE=OK;
		PORTB=Copy_u8value;
		break;
	case DIO_u8_PORTC:
		LOC_ERROR_STATE=OK;
		PORTC=Copy_u8value;
		break;
	case DIO_u8_PORTD:
		LOC_ERROR_STATE=OK;
		PORTD=Copy_u8value;
		break;
	}
}

void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8PinNum,u8 Copy_u8PinDirection)
{
	u8 LOC_ERROR_STATE = NOK;
		switch(Copy_u8Port)
		{
		case DIO_u8_PORTA:
			LOC_ERROR_STATE=OK;
			switch(Copy_u8PinDirection)
			{
			case DIO_u8_INPUT:
				CLEAR_BIT(PORTA,Copy_u8PinNum);
				break;
			case DIO_u8_OUTPUT:
				SET_BIT(PORTA,Copy_u8PinNum);
				break;
			}
		    break;
		case DIO_u8_PORTB:
			LOC_ERROR_STATE=OK;
			switch(Copy_u8PinDirection)
			{
			case DIO_u8_INPUT:
				CLEAR_BIT(PORTB,Copy_u8PinNum);
				break;
			case DIO_u8_OUTPUT:
				SET_BIT(PORTB,Copy_u8PinNum);
				break;
			}
		    break;
		case DIO_u8_PORTC:
			LOC_ERROR_STATE=OK;
			switch(Copy_u8PinDirection)
			{
			case DIO_u8_INPUT:
				CLEAR_BIT(PORTC,Copy_u8PinNum);
				break;
			case DIO_u8_OUTPUT:
				SET_BIT(PORTC,Copy_u8PinNum);
				break;
			}
		    break;
		case DIO_u8_PORTD:
			LOC_ERROR_STATE=OK;
			switch(Copy_u8PinDirection)
			{
			case DIO_u8_INPUT:
				CLEAR_BIT(PORTD,Copy_u8PinNum);
				break;
			case DIO_u8_OUTPUT:
				SET_BIT(PORTD,Copy_u8PinNum);
				break;
			}
		    break;
		}
}
void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNum,u8 Copy_u8PinValue)
{
	u8 LOC_ERROR_STATE = NOK;
		switch(Copy_u8Port)
		{
		case DIO_u8_PORTA:
			LOC_ERROR_STATE=OK;
			switch(Copy_u8PinValue)
			{
			case DIO_u8_LOW:
				CLEAR_BIT(PORTA,Copy_u8PinNum);
				break;
			case DIO_u8_HIGH:
				SET_BIT(PORTA,Copy_u8PinNum);
				break;
			}
		    break;
		case DIO_u8_PORTB:
			LOC_ERROR_STATE=OK;
			switch(Copy_u8PinValue)
			{
			case DIO_u8_LOW:
				CLEAR_BIT(PORTB,Copy_u8PinNum);
				break;
			case DIO_u8_HIGH:
				SET_BIT(PORTB,Copy_u8PinNum);
				break;
			}
		    break;
		case DIO_u8_PORTC:
			LOC_ERROR_STATE=OK;
			switch(Copy_u8PinValue)
			{
			case DIO_u8_LOW:
				CLEAR_BIT(PORTC,Copy_u8PinNum);
				break;
			case DIO_u8_HIGH:
				SET_BIT(PORTC,Copy_u8PinNum);
				break;
			}
		    break;
		case DIO_u8_PORTD:
			LOC_ERROR_STATE=OK;
			switch(Copy_u8PinValue)
			{
			case DIO_u8_LOW:
				CLEAR_BIT(PORTD,Copy_u8PinNum);
				break;
			case DIO_u8_HIGH:
				SET_BIT(PORTD,Copy_u8PinNum);
				break;
			}
		    break;
		}
}
u8 DIO_voidGetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNum)
{
	u8 u8_PinState = 0;
	switch(Copy_u8Port)
	{
	case DIO_u8_PORTA:
		u8_PinState=GET_BIT(PORTA,Copy_u8PinNum);
	    break;
	case DIO_u8_PORTB:
		u8_PinState=GET_BIT(PORTB,Copy_u8PinNum);
	    break;
	case DIO_u8_PORTC:
		u8_PinState=GET_BIT(PORTC,Copy_u8PinNum);
	    break;
	case DIO_u8_PORTD:
		u8_PinState=GET_BIT(PORTD,Copy_u8PinNum);
	    break;
	}
	return u8_PinState;
}
void DIO_voidActivePullUp(u8 Copy_u8Port,u8 Copy_u8PinNum)
{
	switch(Copy_u8Port)
	{
	case DIO_u8_PORTA:
		CLEAR_BIT(DDRA,Copy_u8PinNum);
		SET_BIT(DDRA,Copy_u8PinNum);
	    break;
	case DIO_u8_PORTB:
		CLEAR_BIT(DDRB,Copy_u8PinNum);
		SET_BIT(DDRB,Copy_u8PinNum);
	    break;
	case DIO_u8_PORTC:
		CLEAR_BIT(DDRC,Copy_u8PinNum);
		SET_BIT(DDRC,Copy_u8PinNum);
	    break;
	case DIO_u8_PORTD:
		CLEAR_BIT(DDRD,Copy_u8PinNum);
		SET_BIT(DDRD,Copy_u8PinNum);
	    break;
	}
}
