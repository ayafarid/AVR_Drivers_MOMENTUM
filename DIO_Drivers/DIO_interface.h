#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

#define DIO_u8_PORTA 0
#define DIO_u8_PORTB 1
#define DIO_u8_PORTC 2
#define DIO_u8_PORTD 3

#define DIO_u8_PIN_00	0
#define DIO_u8_PIN_01	1
#define DIO_u8_PIN_02	2
#define DIO_u8_PIN_03	3
#define DIO_u8_PIN_04	4
#define DIO_u8_PIN_05	5
#define DIO_u8_PIN_06	6
#define DIO_u8_PIN_07	7

#define DIO_u8_INPUT       0
#define DIO_u8_PORT_OUTPUT 0xff

#define DIO_u8_PORT_HIGH    0xff
#define DIO_u8_PORT_LOW     0

#define DIO_u8_OUTPUT  1
#define DIO_U8_INPUT   0

#define DIO_u8_LOW  0
#define DIO_u8_HIGH 1

#define NOK 0
#define OK  1
// Port
void DIO_voidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction);
void DIO_voidSetPortValue(u8 Copy_u8Port , u8 Copy_u8value);
// Pin
void DIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8PinNum,u8 Copy_u8PinDirection);
void DIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNum,u8 Copy_u8PinValue);
u8 DIO_voidGetPinValue(u8 Copy_u8Port,u8 Copy_u8PinNum);
void DIO_voidActivePullUp(u8 Copy_u8Port,u8 Copy_u8PinNum);

#endif
