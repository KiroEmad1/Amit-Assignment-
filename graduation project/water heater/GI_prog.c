
#include "STD_TYPE.h" 
#include "BIT_MATH.h"
#include "GI_reg.h" 

void GI_voidEnable(){
	SET_BIT(SREG_REG,L_BIT) ; 
	
}

void GI_voidDisable(void){
	
	CLR_BIT(SREG_REG,L_BIT) ; 
} 
