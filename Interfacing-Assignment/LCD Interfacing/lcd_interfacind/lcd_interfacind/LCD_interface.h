/*
 * LCD_interface.h
 *
 * Created: 24/02/2024 20:16:05
 *  Author: AMIT
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

/* lcd modes  */
#define  LCD_4BIT     0 
#define  LCD_8BIT     1

#define  LCD_MODE     LCD_4BIT

void LCD_voidInit(void) ; 

void LCD_voidSendData(u8 copy_u8data) ; 
void LCD_voidSendCommand(u8 copy_u8command) ; 

void LCD_voidSendString(u8 *copy_string) ; 

void LCD_voidGotoX_Y(u8 copy_u8x, u8 copy_u8_y) ; 

void LCD_voidDraw_data(u8 copy_u8_pattern, u8*data, u8 x , u8 y ) ; 

void LCD_Vid_Send_number(u32 data) ; 
#endif /* LCD_INTERFACE_H_ */