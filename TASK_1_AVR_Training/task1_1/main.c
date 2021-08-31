/*
 * main.c
 *
 *  Created on: Aug 22, 2021
 *      Author: Aya farid
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#define DDRA  *((u8 *) (0x3A))
#define PORTA *((u8 *) (0x3B))

int main(void){
  DDRA = 0xFF;  //--> 0b11111111  --> 255
  u16 DELAY=100;
  while(1){
    for(u8 i=0 ; i<8 ; i++)
    {
      SET_BIT(PORTA,i);
      _delay_ms(DELAY);
    }
    for(u8 i=7 ; i>0 ; i--)
    {
      CLEAR_BIT(PORTA,i);
      _delay_ms(DELAY);
    }
    CLEAR_BIT(PORTA,0);
    _delay_ms(DELAY);
  }

  return 0;
}
/*
* main.c
*
*  Created on: Aug 22, 2021
*      Author: Aya farid
*/
/*
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

#define DDRA  *((u8 *) (0x3A))
#define PORTA *((u8 *) (0x3B))

int main(void){
  DDRA = 0xFF;  //--> 0b11111111  --> 255
  u16 DELAY=200;
  while(1){
    for(u8 i=0 ; i<8 ; i++)
    {
      SET_BIT(PORTA,i);
      _delay_ms(DELAY);
      CLEAR_BIT(PORTA,i);
    }
    for(u8 i=6 ; i>0 ; i--)
    {
      SET_BIT(PORTA,i);
      _delay_ms(DELAY);
      CLEAR_BIT(PORTA,i);
    }
  }

  return 0;
}
 */
