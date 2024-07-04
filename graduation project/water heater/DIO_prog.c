/*
 * DIO_prog.c
 *
 * Created: 23/02/2024 21:06:30
 *  Author: AMIT
 */ 
#include "BIT_MATH.h" 
#include "STD_TYPE.h" 
#include "DIO_reg.h" 
#include "DIO_interface.h"


void DIO_voidSetPinDir(u8 copy_u8port, u8 copy_u8pin,u8 copy_u8dir){
	
	if(copy_u8dir==OUTPUT){
		
		switch(copy_u8port){
			case DIO_PORTA:SET_BIT(DDRA_REG,copy_u8pin);break ;
			case DIO_PORTB:SET_BIT(DDRB_REG,copy_u8pin);break ;
			case DIO_PORTC:SET_BIT(DDRC_REG,copy_u8pin);break ;
			case DIO_PORTD:SET_BIT(DDRD_REG,copy_u8pin);break ; 
			
		
		}
		
	}
	else if(copy_u8dir==INPUT){
		
		switch(copy_u8port){
			case DIO_PORTA:CLR_BIT(DDRA_REG,copy_u8pin);break ;
			case DIO_PORTB:CLR_BIT(DDRB_REG,copy_u8pin);break ;
			case DIO_PORTC:CLR_BIT(DDRC_REG,copy_u8pin);break ;
			case DIO_PORTD:CLR_BIT(DDRD_REG,copy_u8pin);break ;
			
			
		}
		
	}
	else{
		//do nothing 
	}
	
	
	
	
	
	
}

void DIO_voidSetPinVal(u8 copy_u8port, u8 copy_u8pin,u8 copy_u8value){
	
	if(copy_u8value==HIGH){
		
		switch(copy_u8port){
			case DIO_PORTA:SET_BIT(PORTA_REG,copy_u8pin);break ;
			case DIO_PORTB:SET_BIT(PORTB_REG,copy_u8pin);break ;
			case DIO_PORTC:SET_BIT(PORTC_REG,copy_u8pin);break ;
			case DIO_PORTD:SET_BIT(PORTD_REG,copy_u8pin);break ;
			
			
		}
		
	}
	else if(copy_u8value==LOW){
		
		switch(copy_u8port){
			case DIO_PORTA:CLR_BIT(PORTA_REG,copy_u8pin);break ;
			case DIO_PORTB:CLR_BIT(PORTB_REG,copy_u8pin);break ;
			case DIO_PORTC:CLR_BIT(PORTC_REG,copy_u8pin);break ;
			case DIO_PORTD:CLR_BIT(PORTD_REG,copy_u8pin);break ;
			
			
		}
		
	}
	else{
		//do nothing
	}
	
	
	
	
}

u8 DIO_void_Get_PinVal(u8 copy_u8port,u8 copy_u8pin){
	
	u8 copy_u8state=0 ; 
		switch(copy_u8port){
			case DIO_PORTA:copy_u8state=GET_BIT(PINA_REG,copy_u8pin);break ;
			case DIO_PORTB:copy_u8state=GET_BIT(PINB_REG,copy_u8pin);break ;
			case DIO_PORTC:copy_u8state=GET_BIT(PINC_REG,copy_u8pin);break  ;
			case DIO_PORTD:copy_u8state=GET_BIT(PIND_REG,copy_u8pin);break   ;
			
			
		}
	
	return copy_u8state ; 
	
	
}

/*
void DIO_void_Get_PinVal(u8 copy_u8port,u8 copy_u8pin,u8*copyu8val){
	
	switch(copy_u8port){
		case DIO_PORTA:*copyu8val=GET_BIT(PINA_REG,copy_u8pin);break ;
		case DIO_PORTB:*copyu8val=GET_BIT(PINB_REG,copy_u8pin);break ;
		case DIO_PORTC:*copyu8val=GET_BIT(PINC_REG,copy_u8pin);break ;
		case DIO_PORTD:*copyu8val=GET_BIT(PIND_REG,copy_u8pin);break ;
	}
	
}*/

void DIO_voidSetPortDir(u8 copy_u8port,u8 copy_u8dir){
	switch(copy_u8port){
		case DIO_PORTA:DDRA_REG=copy_u8dir;break ;
		case DIO_PORTB:DDRB_REG=copy_u8dir;break ;
		case DIO_PORTC:DDRC_REG=copy_u8dir;break ;
		case DIO_PORTD:DDRD_REG=copy_u8dir;break ;
		
		
	}
	
}
void DIO_voidSetPortVal(u8 copy_u8port,u8 copy_u8val){
	
	switch(copy_u8port){
		case DIO_PORTA:PORTA_REG=copy_u8val;break ;
		case DIO_PORTB:PORTB_REG=copy_u8val;break ;
		case DIO_PORTC:PORTC_REG=copy_u8val;break ;
		case DIO_PORTD:PORTD_REG=copy_u8val;break ;
		
		
	}
	
	
}
