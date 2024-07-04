/*
 * LCD_prog.c
 *
 * Created: 24/02/2024 20:16:40
 *  Author: AMIT
 */ 

#include "STD_TYPE.h" 
#include "BIT_MATH.h" 
#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#define  F_CPU 16000000UL 
#include <util/delay.h>

               
void LCD_void_SHD(u8 copy_u8data){
	   
	u8 LCD_data[4]={LCD_D4_PIN,LCD_D5_PIN,LCD_D6_PIN,LCD_D7_PIN} ; 
	u8 LOC_u8_in=0 ; 
	
		for (LOC_u8_in=0 ; LOC_u8_in<4;LOC_u8_in++)
		{
			  DIO_voidSetPinVal(LCD_DPORT,LCD_data[LOC_u8_in],GET_BIT(copy_u8data,LOC_u8_in));
		}
	
}

void LCD_SendEnable(){
	
	
	/* SEND enable pulse  */
	DIO_voidSetPinVal(LCD_CPORT,LCD_EN_PIN,HIGH) ;
	_delay_ms(2) ;
	DIO_voidSetPinVal(LCD_CPORT,LCD_EN_PIN,LOW) ;
}
void LCD_voidInit(void){
	
	
	_delay_ms(40) ; 
	
	#if LCD_MODE == LCD_4BIT 
	   LCD_void_SHD(0b0010) ; 
	   LCD_SendEnable() ; 
	   LCD_void_SHD(0b0010) ;
	   LCD_SendEnable() ;
	   LCD_void_SHD(0b1000) ;
	   LCD_SendEnable() ;
	#elif LCD_MODE == LCD_8BIT    
	/* send function set command  */
	LCD_voidSendCommand(0b00111000) ; 
	#endif 
	/*send Display on/off command  */
    LCD_voidSendCommand(0b00001100) ; 
	/* send clr command  */
    LCD_voidSendCommand(0x01) ; 
	
}

void LCD_voidSendData(u8 copy_u8data){
	                
	/* SET RS ---> HIGH  to send DATA  */
	DIO_voidSetPinVal(LCD_CPORT,LCD_RS_PIN,HIGH) ;
	/*set RW --->low  to write  */
	DIO_voidSetPinVal(LCD_CPORT,LCD_RW_PIN,LOW) ;
	
	#if LCD_MODE == LCD_4BIT 
	 /* send MSB data  */
	 LCD_void_SHD(copy_u8data>>4) ; 
	 LCD_SendEnable() ; 
	 /* send LSB data  */
	 LCD_void_SHD(copy_u8data) ;
	 LCD_SendEnable() ;
	#elif LCD_MODE == LCD_8BIT 
	/* send command  */
	DIO_voidSetPortVal(LCD_DPORT,copy_u8data) ;
          LCD_SendEnable() ;
	#endif 	  
	
	
	
}
void LCD_voidSendCommand(u8 copy_u8command){
	
	/* SET RS ---> low  to send command  */
	 DIO_voidSetPinVal(LCD_CPORT,LCD_RS_PIN,LOW) ; 
	 /*set RW --->low  to write  */
	DIO_voidSetPinVal(LCD_CPORT,LCD_RW_PIN,LOW) ; 
	#if LCD_MODE == LCD_4BIT
	/* send MSB data  */
	LCD_void_SHD(copy_u8command>>4) ;
	LCD_SendEnable() ;
	/* send LSB data  */
	LCD_void_SHD(copy_u8command) ;
	LCD_SendEnable() ;
	#elif LCD_MODE == LCD_8BIT
	/* send command  */
	DIO_voidSetPortVal(LCD_DPORT,copy_u8command) ;
	LCD_SendEnable() ;
	#endif
	
	 
	
}

void LCD_voidSendString(u8 *copy_string){
	
	u8 i=0 ; 
	while(copy_string[i]!='\0'){
		
		LCD_voidSendData(copy_string[i]) ; 
		_delay_ms(5); 
		i++ ; 
	}
	
	
	
}


void LCD_voidGotoX_Y(u8 copy_u8x, u8 copy_u8_y){
	
	u8 DDRAM_address=0 ; 
	
	if (copy_u8_y==0)
	{
		DDRAM_address=copy_u8x ; 
	}
	else{
		DDRAM_address=copy_u8x+0x40 ; 
	}
	// DDRAM_address= copy_u8x+(copy_u8_y *0x40) 
	// set DDRAM addrsss 
	SET_BIT(DDRAM_address,7) ; 
	LCD_voidSendCommand(DDRAM_address) ; 
}

                       // 0----> 7 
void LCD_voidDraw_data(u8 copy_u8_pattern, u8*data, u8 x , u8 y ){
	
	u8 CGRAM_address=copy_u8_pattern * 8 ; 
	u8  i =0 ; 
	// set CGRAM_address 
	CLR_BIT(CGRAM_address,7) ; 
	SET_BIT(CGRAM_address,6) ; 
	LCD_voidSendCommand(CGRAM_address) ; 
	 // send data 
	for (i=0 ; i<8;i++)
	{
		LCD_voidSendData(data[i]) ; 
	}
	// set DDRAM 
	
	LCD_voidGotoX_Y(x,y) ; 
	LCD_voidSendData(copy_u8_pattern) ; 
}
void LCD_Vid_Send_number(u32 data){
	
	s8 i=0;
	u8 array[10] ;
	
	if(data==0){
		
		LCD_Vid_Send_Data('0') ;
		return ;
	}
	for(i=0; data!=0 ;i++){
		
		array[i]= data % 10 + 48 ;
		data /= 10 ;
		
	}
	i-- ;
	while(i >= 0){
		
		LCD_Vid_Send_Data(array[i]) ;
		i-- ;
		
	}
}