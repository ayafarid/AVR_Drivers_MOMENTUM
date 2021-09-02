// Switches code
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
// 7-seg code
/*
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include <util/delay.h>
char ch[2];
int main(void)
{
  char array[]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};
  DIO_voidSetPortDirection(DIO_u8_PORTA,DIO_u8_PORT_OUTPUT);
  DIO_voidSetPortDirection(DIO_u8_PORTB,DIO_u8_PORT_OUTPUT);
  DIO_voidSetPortDirection(DIO_u8_PORTC,DIO_u8_PORT_OUTPUT);
  while(1)
  {
    DIO_voidSetPortValue(DIO_u8_PORTC,array[0]);
    DIO_voidSetPortValue(DIO_u8_PORTB,array[0]);

    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN_00,DIO_u8_HIGH);
    for(int i=1 ; i<=20 ; i++)
    {
      u8 temp=i;
      DIO_voidSetPortValue(DIO_u8_PORTB,array[temp%10]);
      temp/=10;
      DIO_voidSetPortValue(DIO_u8_PORTC,array[temp]);
      _delay_ms(1000);
      DIO_voidSetPortValue(DIO_u8_PORTC,DIO_u8_PORT_LOW);
    }
    DIO_voidSetPortValue(DIO_u8_PORTC,array[0]);
    DIO_voidSetPortValue(DIO_u8_PORTB,array[0]);
    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN_00,DIO_u8_LOW);
    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN_05,DIO_u8_HIGH);
    for(int i=1 ; i<=3 ; i++)
    {
      u8 temp=i;
      DIO_voidSetPortValue(DIO_u8_PORTB,array[temp%10]);
      temp/=10;
      DIO_voidSetPortValue(DIO_u8_PORTC,array[temp]);
      _delay_ms(1000);
      DIO_voidSetPortValue(DIO_u8_PORTC,DIO_u8_PORT_LOW);
    }
    DIO_voidSetPortValue(DIO_u8_PORTC,array[0]);
    DIO_voidSetPortValue(DIO_u8_PORTB,array[0]);
    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN_05,DIO_u8_LOW);
    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN_07,DIO_u8_HIGH);
    for(int i=1 ; i<=10 ; i++)
    {
      u8 temp=i;
      DIO_voidSetPortValue(DIO_u8_PORTB,array[temp%10]);
      temp/=10;
      DIO_voidSetPortValue(DIO_u8_PORTC,array[temp]);
      _delay_ms(1000);
      DIO_voidSetPortValue(DIO_u8_PORTC,DIO_u8_PORT_LOW);
    }
    DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN_07,DIO_u8_LOW);
  }
    return 0;
}
*/
