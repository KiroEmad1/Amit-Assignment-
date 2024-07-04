/*
 * ADC_prog.c
 *
 * Created: 15/03/2024 23:00:24
 *  Author: AMIT
 */ 
#include "BIT_MATH.h" 
#include "STD_TYPE.h" 
#include "ADC_reg.h" 
#include "ADC_interface.h"

void ADC_voidInit(void){
	
	/* 1-select AREFF: AVCC with external capacitor at AREF pin */
	SET_BIT(ADMUX_REG,6) ; 
	CLR_BIT(ADMUX_REG,7) ; 
	
	/*2- select prescaler  */
	 ADCSRA_REG &=0b11111000 ; 
	 ADCSRA_REG|=ADC_PRESCALER ; 
	
	/* 3-ENABLE ADC  */
	SET_BIT(ADCSRA_REG,7) ; 
	
}
u16 ADC_u16ReadChannel(u8 copy_u8channel){
	
	/* select ADC Channel */
	ADMUX_REG&=0b11100000;
	ADMUX_REG|=copy_u8channel ; 
	
	/* start conversion */
	SET_BIT(ADCSRA_REG,6) ; 
	
	while(GET_BIT(ADCSRA_REG,4)==0) ; 
	SET_BIT(ADCSRA_REG,4) ; // clr adc flage
	
	
return ADC_REG ;  
}