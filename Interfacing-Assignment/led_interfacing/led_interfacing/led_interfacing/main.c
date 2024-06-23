/*
 * led_interfacing.c
 *
 * 
 * Author : kirolos Emad Awni
 */ 
#include "STD_TYPE.h"
#include "DIO_reg.h"
#include "DIO_interface.h"
#define F_CPU 16000000UL
#include <util/delay.h>


// Define the number of LEDs
#define NUM_LEDS 10

// Define ports and pins for the LEDs
#define LED_PORT DIO_PORTB
#define LED_PORT_A DIO_PORTA  
#define LED_PORT_B DIO_PORTB  
void flash_leds();
void shift_left();
void shift_right();
void ping_pong();
void snake_effect();

int main(void)
{
	// Set all LED pins to output
	DIO_voidSetPortDir(LED_PORT, 0xFF); // Set entire port to output
	DIO_voidSetPortDir(DIO_PORTA, 0b11000000); 
	while (1)
	{
		flash_leds();
		shift_left();
		shift_right();
		ping_pong();
		snake_effect();
	}
}

void flash_leds()
{
	for (int i = 0; i < 10; i++) {
		DIO_voidSetPortVal(LED_PORT, 0xFF);
		DIO_voidSetPortVal(DIO_PORTA, 0b11000000); // Turn all LEDs on
		_delay_ms(500);
		DIO_voidSetPortVal(LED_PORT, 0x00);
		DIO_voidSetPortVal(DIO_PORTA, 0x00); // Turn all LEDs off
		_delay_ms(500);
	}
}

void shift_left()
{
	for (u8 i = 0; i < 8; i++) {
		DIO_voidSetPortVal(LED_PORT, (1 << i)); // Shift left
		_delay_ms(100);
	}
	DIO_voidSetPortVal(LED_PORT, 0b00000000);
	DIO_voidSetPortVal(DIO_PORTA, 0b01000000); 
	_delay_ms(100);
	DIO_voidSetPortVal(DIO_PORTA, 0b10000000);
	_delay_ms(100);
	DIO_voidSetPortVal(DIO_PORTA, 0b00000000);
}

void shift_right()
{
	DIO_voidSetPortVal(DIO_PORTA, 0b10000000);
	_delay_ms(100);
	DIO_voidSetPortVal(DIO_PORTA, 0b01000000);
	_delay_ms(90);
	DIO_voidSetPortVal(DIO_PORTA, 0b00000000);
	for (int i = 0; i < 10; i++) {
		DIO_voidSetPortVal(LED_PORT, (1 << (NUM_LEDS - 1 - i))); // Shift right
		_delay_ms(100);
	}
	
	DIO_voidSetPortVal(LED_PORT,0b00000000);
}

void ping_pong()
{
	shift_left();
	shift_right();
}

void snake_effect()
{
	u16 snake = 0b1111; // 4-LED snake
	for (int i = 0; i <= NUM_LEDS - 4; i++) {
		DIO_voidSetPortVal(LED_PORT, (snake << i)); // Shift snake left
		_delay_ms(100);
	}
	 DIO_voidSetPinVal(DIO_PORTA,DIO_PIN6,HIGH);
	 _delay_ms(100);
	  DIO_voidSetPinVal(DIO_PORTA,DIO_PIN7,HIGH);
	  _delay_ms(200);
	  DIO_voidSetPinVal(DIO_PORTA,DIO_PIN7,LOW);
	  _delay_ms(100);
	  DIO_voidSetPinVal(DIO_PORTA,DIO_PIN6,LOW);
	  _delay_ms(100);
	for (int i = NUM_LEDS - 4; i >= 0; i--) {
		DIO_voidSetPortVal(LED_PORT, (snake << i)); // Shift snake right
		_delay_ms(100);
	}
}
