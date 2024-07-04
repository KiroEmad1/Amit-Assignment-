/*
 * LCD_config.h
 *
 * Created: 24/02/2024 20:16:24
 *  Author: AMIT
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_


#define  LCD_CPORT     DIO_PORTB 
#define  LCD_RS_PIN     DIO_PIN1 
#define  LCD_RW_PIN     DIO_PIN2
#define  LCD_EN_PIN     DIO_PIN3  

#if LCD_MODE == LCD_4BIT 
#define  LCD_DPORT       DIO_PORTA 

#define LCD_D4_PIN       DIO_PIN4 
#define LCD_D5_PIN       DIO_PIN5 
#define LCD_D6_PIN       DIO_PIN6 
#define LCD_D7_PIN       DIO_PIN7 

#elif LCD_MODE == LCD_8BIT 
#define  LCD_DPORT       DIO_PORTB 

#endif 


#endif /* LCD_CONFIG_H_ */