#include "../Services/STD_TYPES.h"
#include "../Services/BIT_MATHS.h"

#include "../MCAL/01-DIO/DIO_interface.h"
#include "../MCAL/02-GIE/GIE_interface.h"
#include "../MCAL/03-EXTI/EXTI_interface.h"
#include "../MCAL/03-EXTI/EXTI_private.h"

#include <util/delay.h>
volatile u8 CopyCounter=0;
void TOG_LED_ISR1(void);
int main(void){
	DIO_voidSetPortDirection(DIO_u8_PORTA,DIO_u8_PORT_OUTPUT);
	DIO_voidActivePullUp(DIO_u8_PORTD , DIO_u8_PIN_03);
	EXTI_voidCallBack(TOG_LED_ISR1 , EXTI_u8_LINE1);
	EXTI_voidEnable(EXTI_u8_LINE1,EXTI_u8_ON_CHANGE);
	GIE_voidEnable();
	while(1){
	}


	return 0;
}
void TOG_LED_ISR1(void){
	switch(CopyCounter)
	{
	case DIO__u8FlashState:
		DIO_voidFlash(DIO_u8_PORTA);
		break;
	case DIO_u8ShiftRight:
		DIO_voidShiftRight(DIO_u8_PORTA);
		break;
	case DIO_u8RightLeft:
		DIO_voidShiftLeft(DIO_u8_PORTA);
		break;
	case DIO_U8ShiftLeft:
		DIO_voidRightLeft(DIO_u8_PORTA);
		break;
	case DIO_u8Mediume:
		DIO_voidMedium(DIO_u8_PORTA);
		break;
	}
}
