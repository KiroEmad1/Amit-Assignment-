/*
 * APP2.c
 *
 * Created: 21/03/2024 22:16:56
 * Author : kirolos Emad Awni
 */ 
#include "BIT_MATH.h" 
#include "STD_TYPE.h" 
#include "DIO_interface.h" 
#include "LCD_config.h" 
#include "LCD_interface.h" 
#include "KEYPAD_interface.h"

u8 simple_cal(u8 num1 ,u8 op ,u8 num2) ; 
u8 get_key() ;
int main(void)
{  
	u8 num1 , num2 ,op , result ; 
	u8 key=0xff  ; 
	u8 key1 ;
	  /* lcd init */
	  DIO_voidSetPortDir(LCD_DPORT,0xF0) ; 
	  DIO_voidSetPortDir(LCD_CPORT,0x0E) ; 
	  LCD_voidInit() ; 
	  /* KEYPAD init  */
        KEYPAD_voidInit() ; 
		      
    while (1) 
    {
		  num1 =get_key() ; 
		  LCD_voidSendnumber(num1) ; 
		  
		  op=get_key() ; 
		  LCD_voidSendData(op) ; 
		  num2=get_key() ; 
		  LCD_voidSendnumber(num2) ; 
		  
		  result=simple_cal(num1,op,num2) ; 
		  
		  key=get_key() ; 
		  if (key=='=')
		  {
			  LCD_voidSendData('=') ; 
			  LCD_voidSendnumber(result) ; 
		  }
		  key1=get_key() ;
		  if (key1=='C')
		  {
			 
			  LCD_voidSendCommand(0x001) ;
		  }
		
		
		
    }
}

u8 simple_cal(u8 num1 ,u8 op ,u8 num2){
	
	u8 result=0 ; 
	switch(op){
		
		case '+':result=num1+num2 ; break;
		case '-':result=num1-num2 ; break;
		case '*':result=num1*num2 ; break;
		case '/':result=num1/num2 ; break ; 
	}
	
	return result ; 
	
}

u8 get_key(){
	
	u8 key=0xff ; 
	do
	{
		key=KEYPAD_u8GetKey() ;
	} while (key==0xff);
	
	return key ; 
}