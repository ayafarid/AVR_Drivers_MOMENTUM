#include "../../Services/BIT_MATHS.h"
#include "../../Services/STD_TYPES.h"

#include "GIE_interface.h"
#include "GIE_private.h"
#include "GIE_config.h"


void GIE_voidEnable(void){
	SET_BIT(SREG_REG , GIE_BIT);
}

void GIE_voidDisable(void){
	CLR_BIT(SREG_REG , GIE_BIT);
}

