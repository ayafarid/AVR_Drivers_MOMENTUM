#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include <util/delay.h>
int main(void)
{
	DIO_voidSetPortDirection(DIO_u8_PORTA,DIO_u8_PORT_OUTPUT);
	DIO_voidSetPortDirection(DIO_u8_PORTC,DIO_u8_INPUT);
	DIO_voidSetPortDirection(DIO_u8_PORTD,DIO_u8_INPUT);
	u8 switch_1_value,switch_2_value,switch_3_value,switch_4_value;
	DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN_01,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN_03,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PORTC,DIO_u8_PIN_07,DIO_u8_HIGH);
	DIO_voidSetPinValue(DIO_u8_PORTD,DIO_u8_PIN_01,DIO_u8_HIGH);
    while(1)
    {
    	switch_1_value=DIO_voidGetPinValue(DIO_u8_PORTC,DIO_u8_PIN_01);
    	switch_2_value=DIO_voidGetPinValue(DIO_u8_PORTC,DIO_u8_PIN_03);
    	switch_3_value=DIO_voidGetPinValue(DIO_u8_PORTC,DIO_u8_PIN_07);
    	switch_4_value=DIO_voidGetPinValue(DIO_u8_PORTD,DIO_u8_PIN_01);
    	if(switch_1_value==0&&switch_2_value==1&&switch_3_value==1&&switch_4_value==1)
    	{
    		for(u8 i=0 ; i<8 ; i++)
    		{
    			DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_HIGH);
    		}
    		_delay_ms(500);
    		for(u8 i=0 ; i<8 ; i++)
    		{
    			DIO_voidSetPinValue(DIO_u8_PORTA,i,0);
    		}
    		_delay_ms(500);
    	}
    	else
    	{
    		DIO_voidSetPortValue(DIO_u8_PORTA,DIO_u8_PORT_LOW);
    	}
    	if(switch_1_value==1&&switch_2_value==0&&switch_3_value==1&&switch_4_value==1)
    	{
    		for(u8 i=0 ; i<8 ; i++)
    		{
    			DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_HIGH);
    		    _delay_ms(200);
    		}
    	    for(u8 i=7 ; i>0 ; i--)
    	    {
    			DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_LOW);
    		    _delay_ms(200);
    		}
    	    DIO_voidSetPinValue(DIO_u8_PORTA,0,DIO_u8_LOW);
    	    _delay_ms(200);
    	}
    	else
    	{
    		DIO_voidSetPortValue(DIO_u8_PORTA,DIO_u8_PORT_LOW);
    	}
    	if(switch_1_value==1&&switch_2_value==1&&switch_3_value==0&&switch_4_value==1)
    	{
    		for(int i=0,j=7;i<4&&j>3;i++,j--)
    		{
    			DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_HIGH);
    			DIO_voidSetPinValue(DIO_u8_PORTA,j,DIO_u8_HIGH);
    		    _delay_ms(500);
    		}
    		DIO_voidSetPortValue(DIO_u8_PORTA,DIO_u8_PORT_LOW);
    		_delay_ms(500);
    	}
    	else
    	{
    		DIO_voidSetPortValue(DIO_u8_PORTA,DIO_u8_PORT_LOW);
    	}
    	if(switch_1_value==1&&switch_2_value==1&&switch_3_value==1&&switch_4_value==0)
    	{
    		for(int i=3,j=4;i>=0&&j<8;i--,j++)
    		{
    			DIO_voidSetPinValue(DIO_u8_PORTA,i,DIO_u8_HIGH);
    			DIO_voidSetPinValue(DIO_u8_PORTA,j,DIO_u8_HIGH);
    		    _delay_ms(500);
    		}
    		DIO_voidSetPortValue(DIO_u8_PORTA,DIO_u8_PORT_LOW);
    		_delay_ms(500);
    	}
    	else
    	{
    		DIO_voidSetPortValue(DIO_u8_PORTA,DIO_u8_PORT_LOW);
    	}
    }
  return 0;
}
