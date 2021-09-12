#ifndef HAL_01__CLCD_CLCD_CONFIG_H_
#define HAL_01__CLCD_CLCD_CONFIG_H_

/*
 * CLCD_DATA_PORT -> OPTIONS
 *
 * 1- DIO_u8_PORTA
 * 2- DIO_u8_PORTB
 * 3- DIO_u8_PORTC
 * 4- DIO_u8_PORTD
 */


#define CLCD_DATA_PORT		DIO_u8_PORTA

/*
 * CLCD_CONTROL_PORT -> OPTIONS
 *
 * 1- DIO_u8_PORTA
 * 2- DIO_u8_PORTB
 * 3- DIO_u8_PORTC
 * 4- DIO_u8_PORTD
 */


#define CLCD_CONTROL_PORT	DIO_u8_PORTB


/*
 * CLCD_RS_PIN , CLCD_EN_PIN -> OPTIONS
 *
 * 1- DIO_u8_PIN_00
 * 2- DIO_u8_PIN_01
 * 3- DIO_u8_PIN_02
 * 4- DIO_u8_PIN_03
 * 5- DIO_u8_PIN_04
 * 6- DIO_u8_PIN_05
 * 7- DIO_u8_PIN_06
 * 8- DIO_u8_PIN_07
 */


#define CLCD_RS_PIN			DIO_u8_PIN_00
#define CLCD_RW_PIN			DIO_u8_PIN_02
#define CLCD_EN_PIN			DIO_u8_PIN_01





static u8 LOC_u8StaticArr [] = {
		  0x11,0x0E,0x00,0x04,0x04,0x04,0x04,0x04,					//First Character
		  0x00,0x00,0x01,0x01,0x01,0x1F,0x00,0x0A,					//Second Character
		  0x00,0x1C,0x14,0x1C,0x04,0x07,0x00,0x00,					//Third Character
		  0x02,0x07,0x05,0x07,0x01,0x1F,0x00,0x00,					//Fourth Character
		  0x00,0x00,0x00,0x00,0x00,0x02,0x04,0x08,					//Fifth Character
		  0x00,0x00,0x00,0x02,0x02,0x1E,0x00,0x00,					//sixth Character
		  0x0E,0x0A,0x0E,0x04,0x04,0x0A,0x0A,0x1F
};
/*
 * CLCD_u8_INTEFACE_DATA_LENGTH -> OPTIONS
 *
 * 1- CLCD_u8_4_DATA_LENGTH
 * 2- CLCD_u8_8_DATA_LENGTH

 */
#define CLCD_u8_INTEFACE_DATA_LENGTH		CLCD_u8_4_DATA_LENGTH


















#endif /* HAL_01__CLCD_CLCD_CONFIG_H_ */
