/*
 * EXT_prog.c
 *
 * Created: 08/03/2024 20:40:31
 *  Author: AMIT
 */ 
#include "BIT_MATH.h" 
#include "STD_TYPE.h"
#include "EXT_interface.h" 
#include "EXT_reg.h" 


/* pointer to function  */

void(*ptr_fun1)(void)=0 ; 
void(*ptr_fun2)(void)=0 ; 
void(*ptr_fun3)(void)=0 ; 
void EXT_voidInit(u8 copy_u8SensControl , u8 copy_u8INT){
	
	
	switch(copy_u8INT){
		
		case INT_0 : 
		             if (copy_u8SensControl==RISING_EDGE)
		             {
						 /* rising edge for INT0  */
						SET_BIT(MCUCR_REG,0) ; 
						SET_BIT(MCUCR_REG,1) ;  
		             }
		             else if (copy_u8SensControl==FALLING_EDGE)
		             {
						 /* falling edge for INT0  */
						 CLR_BIT(MCUCR_REG,0) ;
						 SET_BIT(MCUCR_REG,1) ;
		             }
			 else if(copy_u8SensControl==ANY_LOGICAL_CHANGE){
						 
						 /* any logical change for INT0  */
						 SET_BIT(MCUCR_REG,0) ;
						 CLR_BIT(MCUCR_REG,1) ;
					 }
					 else{
						 /* LOW LEVEL for INT0  */
						 CLR_BIT(MCUCR_REG,0) ;
						 CLR_BIT(MCUCR_REG,1) ;
					 }
					 break ; 
		
		case INT_1 :
		if (copy_u8SensControl==RISING_EDGE)
		{
			/* rising edge for INT0  */
			SET_BIT(MCUCR_REG,2) ;
			SET_BIT(MCUCR_REG,3) ;
		}
		else if (copy_u8SensControl==FALLING_EDGE)
		{
			/* falling edge for INT0  */
			CLR_BIT(MCUCR_REG,2) ;
			SET_BIT(MCUCR_REG,3) ;
		}
		else if(copy_u8SensControl==ANY_LOGICAL_CHANGE){
			
			/* any logical change for INT0  */
			SET_BIT(MCUCR_REG,2) ;
			CLR_BIT(MCUCR_REG,3) ;
		}
		else{
			/* LOW LEVEL for INT0  */
			CLR_BIT(MCUCR_REG,2) ;
			CLR_BIT(MCUCR_REG,3) ;
		}
		break ; 
		
	case INT_2 : 	
		if (copy_u8SensControl==RISING_EDGE)
		{
			/* rising edge for INT2 */
			SET_BIT(MCUCSR_REG,6) ;
		
		}
		else if (copy_u8SensControl==FALLING_EDGE)
		{
			/* falling edge for INT2 */
			CLR_BIT(MCUCSR_REG,6) ;
		}
		else{
			// DO nothing
		}
		break; 
	}
	
	
	
	
}

void EXT_voidINT0Enable(void) {
	SET_BIT(GICR_REG,6); 
}
void EXT_voidINT0Disable(void){
	CLR_BIT(GICR_REG,6); 
	
}

void EXT_voidINT1Enable(void){
	SET_BIT(GICR_REG,7); 
	
}
void EXT_voidINT1Disable(void){
	CLR_BIT(GICR_REG,7); 
}
void EXT_voidINT2Enable(void){
		SET_BIT(GICR_REG,5);
}
void EXT_voidINT2Disable(void){
	CLR_BIT(GICR_REG,5); 
}
void EXT_voidSetCallBack(u8 copy_u8ptr , void(*ptr)(void)){
	
	
	if (copy_u8ptr==INT_0)
	{
		ptr_fun1=ptr ; 
	}
	 if(copy_u8ptr==INT_1){
		 ptr_fun2=ptr ; 
	 }
	if (copy_u8ptr==INT_2)
	{
		ptr_fun3=ptr ; 
	}
}

void __vector_1 (void ) __attribute__ ((signal));
void __vector_1 (void){
	
ptr_fun1() ;  
	
}

void __vector_2 (void ) __attribute__ ((signal));
void __vector_2 (void){
	
	
	ptr_fun2() ; 
	
}

void __vector_3 (void ) __attribute__ ((signal));
void __vector_3 (void){
	
	
	ptr_fun3() ;
	
}
