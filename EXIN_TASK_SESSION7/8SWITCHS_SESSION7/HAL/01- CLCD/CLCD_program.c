#include "../../Services/STD_TYPES.h"
#include "../../Services/BIT_MATHS.h"

#include "../../MCAL/01-DIO/DIO_interface.h"

#include <util/delay.h>
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "CLCD_private.h"

void CLCD_voidInit(void) {


#if CLCD_u8_INTEFACE_DATA_LENGTH == CLCD_u8_8_DATA_LENGTH
	DIO_voidSetPortDirection(CLCD_DATA_PORT, DIO_u8_PORT_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT, CLCD_RS_PIN, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT, CLCD_EN_PIN, DIO_u8_OUTPUT);
	_delay_ms(50);
	CLCD_voidSendCommand(CLCD_u8_SET_FUNCTION);
	_delay_ms(1);
	CLCD_voidSendCommand(CLCD_u8_DISPLAY_CONTROL);
	_delay_ms(1);
	CLCD_voidSendCommand(CLCD_u8_DISPLAY_CLEAR);
	_delay_ms(5);
	CLCD_voidSendCommand(CLCD_u8_Entry_MODE);
#elif CLCD_u8_INTEFACE_DATA_LENGTH == CLCD_u8_4_DATA_LENGTH
	DIO_voidSetPortDirection(CLCD_DATA_PORT, DIO_u8_PORT_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT, CLCD_RS_PIN, DIO_u8_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT, CLCD_EN_PIN, DIO_u8_OUTPUT);
	_delay_ms(50);
	CLCD_voidSendCommand(CLCD_u8_SET_FUNCTION);
	_delay_ms(1);
	CLCD_voidSendCommand(CLCD_u8_DISPLAY_CONTROL);
	_delay_ms(1);
	CLCD_voidSendCommand(CLCD_u8_DISPLAY_CLEAR);
	_delay_ms(5);
	CLCD_voidSendCommand(CLCD_u8_Entry_MODE);
#endif

}

void CLCD_voidSendData(u8 Copy_u8Data) {

	DIO_voidSetPortValue(CLCD_DATA_PORT, Copy_u8Data);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_RS_PIN, DIO_u8_HIGH);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN_PIN, DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN_PIN, DIO_u8_LOW);
	_delay_ms(1);

}

void CLCD_voidSendCommand(u8 Copy_u8Command) {

	DIO_voidSetPortValue(CLCD_DATA_PORT, Copy_u8Command);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_RS_PIN, DIO_u8_LOW);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN_PIN, DIO_u8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT, CLCD_EN_PIN, DIO_u8_LOW);
	_delay_ms(1);

}

void CLCD_voidSendString(u8 *Copy_u8PtrString) {
	u8 LOC_u8Iterator = 0;
	while (Copy_u8PtrString[LOC_u8Iterator] != '\0') {
		CLCD_voidSendData(Copy_u8PtrString[LOC_u8Iterator]);
		LOC_u8Iterator++;
	}
}

void CLCD_voidSendNumber(u64 Copy_u64Number) {

	u64 LOC_u64Reversed = 1;
	if (Copy_u64Number == 0) {
		CLCD_voidSendData('0');
	} else {
		while (Copy_u64Number != 0) {
			LOC_u64Reversed = (LOC_u64Reversed * 10) + (Copy_u64Number % 10);
			Copy_u64Number = Copy_u64Number / 10;
		}
		while (LOC_u64Reversed != 1) {

			CLCD_voidSendData((LOC_u64Reversed % 10) + '0');
			LOC_u64Reversed /= 10;
		}
	}

}



void CLCD_voidSetPosition(u8 Copy_u8Row , u8 Copy_u8Coloum){

	if(Copy_u8Row == CLCD_u8_ROW_00){
		CLCD_voidSendCommand(CLCD_u8_DDRAM_OFFSET + Copy_u8Coloum);

	}
	else{
		CLCD_voidSendCommand(CLCD_u8_DDRAM_OFFSET + CLCD_u8_DDRAM_ROW2_OFFSET + Copy_u8Coloum);
	}


}



void CLCD_voidSendExtraChar(void){
	CLCD_voidSendCommand(CLCD_u8_CGRAM_OFFSET);
	u8 LOC_u8Iterator = 0;

	for(LOC_u8Iterator = 0 ; LOC_u8Iterator < (sizeof(LOC_u8StaticArr) / sizeof(LOC_u8StaticArr[LOC_u8Iterator])); LOC_u8Iterator++){
		CLCD_voidSendData(LOC_u8StaticArr[LOC_u8Iterator]);
	}
}


void CLCD_voidClearLCD(void){
	CLCD_voidSendCommand(CLCD_u8_CLEAR_LCD_COMMAND);
}
