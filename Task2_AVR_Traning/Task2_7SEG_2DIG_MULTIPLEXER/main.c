// 7-seg code
#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include <util/delay.h>
char ch[2];
int main(void)
{
  // COMMON 1 -> PB0
  // COMMON 2 -> PB1
  char array[]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,0b0000111,0b1111111,0b1101111};
  DIO_voidSetPortDirection(DIO_u8_PORTA,DIO_u8_PORT_OUTPUT);
  DIO_voidSetPortDirection(DIO_u8_PORTB,DIO_u8_PORT_OUTPUT);
  while(1)
  {
	  DIO_voidSetPortValue(DIO_u8_PORTC,array[0]);
	  DIO_voidSetPortValue(DIO_u8_PORTB,array[0]);
	  DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN_00,DIO_u8_LOW);
	  DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN_05,DIO_u8_HIGH);

	  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_02,DIO_u8_HIGH);
	  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_03,DIO_u8_LOW);
	  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_04,DIO_u8_LOW);
	  for(int i=1 ; i<=20 ; i++)
	  {
		  u8 temp=i;
		  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_00,DIO_u8_HIGH);
		  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_01,DIO_u8_LOW);
		  DIO_voidSetPortValue(DIO_u8_PORTA,array[temp%10]);
	 	  _delay_ms(100);
		  temp/=10;
		  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_00,DIO_u8_LOW);
		  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_01,DIO_u8_HIGH);
		  DIO_voidSetPortValue(DIO_u8_PORTA,array[temp]);
		  _delay_ms(100);
	  }

	  DIO_voidSetPortValue(DIO_u8_PORTC,array[0]);
	  DIO_voidSetPortValue(DIO_u8_PORTB,array[0]);
	  DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN_00,DIO_u8_LOW);
	  DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN_05,DIO_u8_HIGH);

	  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_02,DIO_u8_LOW);
	  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_03,DIO_u8_HIGH);
	  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_04,DIO_u8_LOW);
	  for(int i=1 ; i<=8 ; i++)
	  {
		  u8 temp=i;
		  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_00,DIO_u8_HIGH);
		  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_01,DIO_u8_LOW);
		  DIO_voidSetPortValue(DIO_u8_PORTA,array[temp%10]);
	 	  _delay_ms(100);
		  temp/=10;
		  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_00,DIO_u8_LOW);
		  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_01,DIO_u8_HIGH);
		  DIO_voidSetPortValue(DIO_u8_PORTA,array[temp]);
		  _delay_ms(100);
	  }

	  DIO_voidSetPortValue(DIO_u8_PORTC,array[0]);
	  DIO_voidSetPortValue(DIO_u8_PORTB,array[0]);
	  DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN_00,DIO_u8_LOW);
	  DIO_voidSetPinValue(DIO_u8_PORTA,DIO_u8_PIN_05,DIO_u8_HIGH);

	  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_02,DIO_u8_LOW);
	  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_03,DIO_u8_LOW);
	  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_04,DIO_u8_HIGH);
	  for(int i=1 ; i<=10 ; i++)
	  {
		  u8 temp=i;
		  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_00,DIO_u8_HIGH);
		  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_01,DIO_u8_LOW);
		  DIO_voidSetPortValue(DIO_u8_PORTA,array[temp%10]);
	 	  _delay_ms(100);
		  temp/=10;
		  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_00,DIO_u8_LOW);
		  DIO_voidSetPinValue(DIO_u8_PORTB,DIO_u8_PIN_01,DIO_u8_HIGH);
		  DIO_voidSetPortValue(DIO_u8_PORTA,array[temp]);
		  _delay_ms(100);
	  }
  }
  return 0;
}
