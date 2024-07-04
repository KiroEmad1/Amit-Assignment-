/*
 * lcd_interfacind.c
 *
 * Created: 6/26/2024 3:36:26 PM
 * Author : kirolos Emad Awni
 */ 

#include "STD_TYPE.h"
#include "BIT_MATH.h"
#include "DIO_reg.h"
#include "DIO_interface.h"

#include "LCD_config.h"
#include "LCD_interface.h"
#define  F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
	
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN4,INPUT);
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN5,INPUT);
	DIO_voidSetPinDir(DIO_PORTB,DIO_PIN6,INPUT);
	DIO_voidSetPinVal(DIO_PORTB,DIO_PIN4,HIGH);
	DIO_voidSetPinVal(DIO_PORTB,DIO_PIN5,HIGH);
	DIO_voidSetPinVal(DIO_PORTB,DIO_PIN6,HIGH);
	DIO_voidSetPortDir(LCD_DPORT,0xf0) ;
	DIO_voidSetPortDir(LCD_CPORT,0x0E) ;
	LCD_voidInit();
	u8 player[8] = {
		0b00100,
		0b01110,
		0b00100,
		0b01110,
		0b10101,
		0b00100,
		0b01010,
		0b10001
	};
	u8 ball[8] = {
		0b00000,
		0b00100,
		0b01110,
		0b11111,
		0b01110,
		0b00100,
		0b00000,
		0b00000
	};
	u8 GOAL[8] = {
		 0b11111,
		 0b00001,
		 0b00001,
		 0b00001,
		 0b00001,
		 0b00001,
		 0b11111,
		 0b00000
	 };
	 u8 player1[8] = {
		 0b00100,
		 0b01110,
		 0b00100,
		 0b01110,
		 0b10101,
		 0b00100,
		 0b01010,
		 0b10001
	 };

	 u8 player2[8] = {
		 0b00100,
		 0b01110,
		 0b00100,
		 0b01110,
		 0b00100,
		 0b10101,
		 0b01010,
		 0b00100
	 };

u8 letter1[8]={
	  0b11111,
	  0b10000,
	  0b01000,
	  0b00100,
	  0b00010,
	  0b11111,
	  0b00000,
	  0b00000
};

u8 letter2[8]={
	  0b00000,
	  0b00000,
	  0b00000,
	  0b00001,
	  0b00001,
	  0b11111,
	  0b00110,
	  0b00000
};

u8 letter3[8]={
	0b00000,
	0b00000,
	0b00000,
	0b00000,
	0b00010,
	0b00011,
	0b00100,
	0b11000
};

u8 letter4[8]={
  0b00000,
  0b00000,
  0b01110,
  0b01010,
  0b01111,
  0b00010,
  0b00100,
  0b11000
};




	LCD_voidGotoX_Y(0,0);
	LCD_voidSendString(" play football ");
	LCD_voidGotoX_Y(8,1);
	LCD_voidSendString("run");
	LCD_voidGotoX_Y(1,1);
	LCD_voidSendString("DANCE");
	
   while (1) {
	   
	    if (DIO_void_Get_PinVal(DIO_PORTB,DIO_PIN4)==0 ) {
			
			 LCD_voidSendCommand(0x01);
			 _delay_ms(10);
			LCD_voidDraw_data(0,player,0,0);
			LCD_voidDraw_data(1,ball,1,0);
			LCD_voidDraw_data(2,GOAL,15,0);
			_delay_ms(10);
			LCD_voidGotoX_Y(0,1);
			LCD_voidSendString("GAME STARTED");
			
			 _delay_ms(50);
	  
		}
					
					
 
	    if (DIO_void_Get_PinVal(DIO_PORTB,DIO_PIN5)==0) {
		     LCD_voidSendCommand(0x01);
			_delay_ms(10);
			
			LCD_voidDraw_data(2,GOAL,15,0);
			u8 x =0;
			for (u8 count =0;count<=14;count++){
				LCD_voidSendCommand(0x01);
				LCD_voidDraw_data(1,ball,x+1,0);
				LCD_voidDraw_data(0,player,x,0);
			    _delay_ms(80);
				x++;	
			}
			LCD_voidDraw_data(2,GOAL,15,0);

		   }
  

 	    

	    if (DIO_void_Get_PinVal(DIO_PORTB,DIO_PIN6)==0) {
		   _delay_ms(10);
		  LCD_voidSendCommand(0x01);
		  LCD_voidGotoX_Y(0,1);
		  LCD_voidSendString("GOAL");
		   for (u8 count=0 ;count<=5;count++)
		   {
			    LCD_voidGotoX_Y(8,0);
			    LCD_voidDraw_data(0,player1,8,0);
				_delay_ms(50);
				LCD_voidDraw_data(4,player2,8,0);
		   }
		 
			LCD_voidGotoX_Y(0,1);
			LCD_voidSendString("GOAL");
	    }
// 		LCD_voidDraw_data(0,letter1,8,0); //uncomment this and comment the above for task2
// 	    LCD_voidDraw_data(1,letter2,7,0);
// 		LCD_voidDraw_data(2,letter3,6,0);
// 		LCD_voidDraw_data(3,letter4,5,0);
 }
 }

