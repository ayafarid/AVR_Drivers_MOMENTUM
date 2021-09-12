/*
 *
 *  Created on: Sep 11, 2021
 *      Author: Aya farid
 */

#include "../../Services/BIT_MATHS.h"
#include "../../Services/STD_TYPES.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"

#include "../02-GIE/GIE_interface.h"
#include "../02-GIE/GIE_private.h"

void EXTI_voidInit(void) {

	/*INTERRUPT LINE 0*/
#ifdef EXTI_LINE_0_EN
	/*INTERRUPT LINE 0 - FALLING EDGE*/

#if EXTI_LINE_0_CONFIG == EXTI_u8_FALLING_EDGE
	SET_BIT(MCUCR , ISC01);
	CLR_BIT(MCUCR , ISC00);
#endif
	/*INTERRUPT LINE 0 - RISING EDGE*/

#if EXTI_LINE_0_CONFIG == EXTI_u8_RISING_EDGE
	SET_BIT(MCUCR , ISC01);
	SET_BIT(MCUCR , ISC00);
#endif

	/*INTERRUPT LINE 0 - ON CHANGE*/

#if EXTI_LINE_0_CONFIG == EXTI_u8_ON_CHANGE
	CLR_BIT(MCUCR , ISC01);
	SET_BIT(MCUCR , ISC00);
#endif

	/*INTERRUPT LINE 0 - LOW LEVEL*/
#if EXTI_LINE_0_CONFIG == EXTI_u8_LOW_LEVEL
	CLR_BIT(MCUCR , ISC01);
	CLR_BIT(MCUCR , ISC00);
#endif

	/*SET PIE OF INTERRUPT LINE 0*/
	SET_BIT(GICR,INT0);

#endif

	/*INTERRUPT LINE 1*/

#ifdef EXTI_LINE_1_EN
	/*INTERRUPT LINE 1 - FALLING EDGE*/

#if EXTI_LINE_1_CONFIG == EXTI_u8_FALLING_EDGE
	SET_BIT(MCUCR, ISC11);
	CLR_BIT(MCUCR, ISC10);
#endif
	/*INTERRUPT LINE 1 - RISING EDGE*/

#if EXTI_LINE_1_CONFIG == EXTI_u8_RISING_EDGE
	SET_BIT(MCUCR , ISC11);
	SET_BIT(MCUCR , ISC10);
#endif

	/*INTERRUPT LINE 1 - ON CHANGE*/

#if EXTI_LINE_1_CONFIG == EXTI_u8_ON_CHANGE
	CLR_BIT(MCUCR , ISC11);
	SET_BIT(MCUCR , ISC10);
#endif

	/*INTERRUPT LINE 1 - LOW LEVEL*/

#if EXTI_LINE_1_CONFIG == EXTI_u8_LOW_LEVEL
	CLR_BIT(MCUCR , ISC11);
	CLR_BIT(MCUCR , ISC10);
#endif

	/*SET PIE OF INTERRUPT LINE 1*/
	SET_BIT(GICR,INT1);

#endif

	/*INTERRUPT LINE 2*/
#ifdef EXTI_LINE_2_EN
	/*INTERRUPT LINE 2 - FALLING EDGE*/

#if EXTI_LINE_0_CONFIG == EXTI_u8_FALLING_EDGE
	CLR_BIT(MCUCSR , ISC2);

#endif
	/*INTERRUPT LINE 2 - RISING EDGE*/

#if EXTI_LINE_0_CONFIG == EXTI_u8_RISING_EDGE
	SET_BIT(MCUCSR , ISC2);
#endif
	/*SET PIE OF INTERRUPT LINE 2*/
	SET_BIT(GICR,INT2);
#endif
}

void EXTI_voidEnable(u8 Copy_u8Line , u8 Copy_u8SenseMode){
	switch(Copy_u8Line)
	{
	case EXTI_u8_LINE0 :
		SET_BIT(SREG_REG , GIE_BIT);
		SET_BIT(GICR,INT0);
		switch(Copy_u8SenseMode)
		{
		case EXTI_u8_FALLING_EDGE:
			SET_BIT(MCUCR , ISC01);
			CLR_BIT(MCUCR , ISC00);
			break;
		case EXTI_u8_RISING_EDGE:
			SET_BIT(MCUCR , ISC01);
			CLR_BIT(MCUCR , ISC00);
			break;
		case EXTI_u8_ON_CHANGE:
			CLR_BIT(MCUCR , ISC01);
			SET_BIT(MCUCR , ISC00);
			break;
		case EXTI_u8_LOW_LEVEL:
			CLR_BIT(MCUCR , ISC01);
			CLR_BIT(MCUCR , ISC00);
			break;
		}
		break;
	case EXTI_u8_LINE1:
		SET_BIT(SREG_REG , GIE_BIT);
		SET_BIT(GICR,INT1);
		switch(Copy_u8SenseMode)
		{
		case EXTI_u8_FALLING_EDGE:
			SET_BIT(MCUCR, ISC11);
			CLR_BIT(MCUCR, ISC10);
			break;
		case EXTI_u8_RISING_EDGE:
			SET_BIT(MCUCR, ISC11);
			SET_BIT(MCUCR, ISC10);
			break;
		case EXTI_u8_ON_CHANGE:
			CLR_BIT(MCUCR, ISC11);
			SET_BIT(MCUCR, ISC10);
			break;
		case EXTI_u8_LOW_LEVEL:
			CLR_BIT(MCUCR, ISC11);
			CLR_BIT(MCUCR, ISC10);
			break;
		}
		break;
	case EXTI_u8_LINE2:
		SET_BIT(SREG_REG , GIE_BIT);
		SET_BIT(GICR,INT2);
		switch(Copy_u8SenseMode)
		{
		case EXTI_u8_FALLING_EDGE:
			CLR_BIT(MCUCSR , ISC2);
			break;
		case EXTI_u8_RISING_EDGE:
			SET_BIT(MCUCSR , ISC2);
			break;
		}
		break;
	}
}


void EXTI_voidDisable(u8 Copy_u8Line){
	switch(Copy_u8Line)
	{
	case EXTI_u8_LINE0:
		CLR_BIT(GICR,INT0);
		break;
	case EXTI_u8_LINE1:
		CLR_BIT(GICR,INT1);
		break;
	case EXTI_u8_LINE2:
		CLR_BIT(GICR,INT2);
		break;
	}
}


void EXTI_voidClearFlag(u8 Copy_u8Line){
	switch(Copy_u8Line)
	{
	case EXTI_u8_LINE0:
		SET_BIT(GIFR,INT0);
		break;
	case EXTI_u8_LINE1:
		SET_BIT(GIFR,INT1);
		break;
	case EXTI_u8_LINE2:
		SET_BIT(GIFR,INT2);
		break;
	}
}


void EXTI_voidCallBack(void (*Copy_pvoidCallBack)(void), u8 Copy_u8Line) {
	if (Copy_pvoidCallBack != NULL) {
		EXTI_CallBack[Copy_u8Line] = Copy_pvoidCallBack;
	}
}
//INTERRUPT LINE 0 ISR
void __vector_1(void) {
	if (EXTI_CallBack[EXTI_u8_LINE0] != NULL) {
		EXTI_CallBack[EXTI_u8_LINE0]();
	}
	//CLEAR THE FLAG
}

//INTERRUPT LINE 1 ISR

void __vector_2(void) {
	if (EXTI_CallBack[EXTI_u8_LINE1]) {
		EXTI_CallBack[EXTI_u8_LINE1]();
	}

}

//INTERRUPT LINE 2 ISR

void __vector_3(void) {
	if (EXTI_CallBack[EXTI_u8_LINE2]) {
		EXTI_CallBack[EXTI_u8_LINE2]();
	}
}
