#ifndef HAL_01__CLCD_CLCD_INTERFACE_H_
#define HAL_01__CLCD_CLCD_INTERFACE_H_

	/* ROWS	*/
#define CLCD_u8_ROW_00		0
#define CLCD_u8_ROW_01		1

	/*COLOUMS*/
#define CLCD_u8_COL_00      0
#define CLCD_u8_COL_01      1
#define CLCD_u8_COL_02      2
#define CLCD_u8_COL_03      3
#define CLCD_u8_COL_04      4
#define CLCD_u8_COL_05      5
#define CLCD_u8_COL_06      6
#define CLCD_u8_COL_07      7
#define CLCD_u8_COL_08      8
#define CLCD_u8_COL_09      9
#define CLCD_u8_COL_10      10
#define CLCD_u8_COL_11      11
#define CLCD_u8_COL_12      12
#define CLCD_u8_COL_13      13
#define CLCD_u8_COL_14      14
#define CLCD_u8_COL_15      15


void CLCD_voidInit(void);

void CLCD_voidSendData(u8 Copy_u8Data);
void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendString(u8 * Copy_u8PtrString);

/*Send Number*/
void CLCD_voidSendNumber(u64 Copy_u64Number);

/*Set Position*/
void CLCD_voidSetPosition(u8 Copy_u8Row , u8 Copy_u8Coloum);
/*Extra Character*/
void CLCD_voidSendExtraChar(void);
/*Clear LCD*/
void CLCD_voidClearLCD(void);
#endif /* HAL_01__CLCD_CLCD_INTERFACE_H_ */
