/*
 * Login system.c
 *
 * Created: 6/29/2024 6:05:40 AM
 * Author : kirolos Emad Awni
 */ 

#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "DIO_interface.h"
#include "LCD_config.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include <string.h>
#define F_CPU 16000000UL
#include <util/delay.h>


u8 get_key(void);

	int main(void) {
	u8 password[4] = {1, 2, 3, 4};  
		u8 input[5];  
		/* lcd init */
		DIO_voidSetPortDir(LCD_DPORT,0xF0) ;
		DIO_voidSetPortDir(LCD_CPORT,0x0E) ;
		LCD_voidInit() ;
		//keypad init
		KEYPAD_voidInit();  

		while (1) {
			LCD_voidGotoX_Y(0,0);
			LCD_voidSendString("Enter password: ");
			u8 x =0;
			u8 y =0;
			u8 count =0;
			_delay_ms(800);
			LCD_voidSendCommand(0x01);
	
			for (u8 i = 0; i < 4; ++i) {
			
				input[i] = get_key();
				
				LCD_voidGotoX_Y(x,y);
				LCD_voidSendData('*');
				
				x++;
				_delay_ms(20);
				count++;
				
			}
			u8 is_correct = 1;
			for (u8 i = 0; i < 4; ++i) {
				if (input[i] != password[i]) {
					is_correct = 0;
					break;
				}
			}
			
			if (is_correct) {
				LCD_voidGotoX_Y(1,0);
				LCD_voidSendString("Welcome!");
				
				break; 
				} else {
				LCD_voidGotoX_Y(0,1);
				LCD_voidSendString("try again. ");
				_delay_ms(600);
				LCD_voidSendCommand(0x01);
				
			}
		}

		

		return 0;
	}
u8 get_key(){
	
	u8 key=0xff ;
	do
	{
		key=KEYPAD_u8GetKey() ;
		_delay_ms(15);
	} while (key==0xff);
	
	return key ;
}


