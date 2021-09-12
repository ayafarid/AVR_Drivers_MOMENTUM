#include "../Services/STD_TYPES.h"
#include "../Services/BIT_MATHS.h"

#include "../MCAL/01-DIO/DIO_interface.h"
#include "../MCAL/02-GIE/GIE_interface.h"
#include "../MCAL/03-EXTI/EXTI_interface.h"
#include "../MCAL/03-EXTI/EXTI_private.h"

#include <util/delay.h>

void TOG_LED_ISR1(void);

void TOG_LED_ISR0(void);

int main(void){
	DIO_voidSetPinDirection(DIO_u8_PORTA , DIO_u8_PIN_00 , DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTA , DIO_u8_PIN_04 , DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(DIO_u8_PORTA , DIO_u8_PIN_07 , DIO_u8_OUTPUT);
	DIO_voidActivePullUp(DIO_u8_PORTD , DIO_u8_PIN_02);
	DIO_voidActivePullUp(DIO_u8_PORTD , DIO_u8_PIN_01);
	EXTI_voidCallBack(TOG_LED_ISR1 , EXTI_u8_LINE1);
	EXTI_voidCallBack(TOG_LED_ISR0 , EXTI_u8_LINE0);
	EXTI_voidEnable(EXTI_u8_LINE1,EXTI_u8_ON_CHANGE);
	EXTI_voidEnable(EXTI_u8_LINE0,EXTI_u8_ON_CHANGE);
	GIE_voidEnable();


	while(1){
		DIO_voidSetPinValue(DIO_u8_PORTA , DIO_u8_PIN_04,DIO_u8_HIGH);
		_delay_ms(500);
		DIO_voidSetPinValue(DIO_u8_PORTA , DIO_u8_PIN_04,DIO_u8_LOW);
		_delay_ms(500);
	}


	return 0;
}
void TOG_LED_ISR1(void){
	DIO_voidTogglePin(DIO_u8_PORTA , DIO_u8_PIN_07);
}
void TOG_LED_ISR0(void){
	DIO_voidTogglePin(DIO_u8_PORTA , DIO_u8_PIN_00);
}
