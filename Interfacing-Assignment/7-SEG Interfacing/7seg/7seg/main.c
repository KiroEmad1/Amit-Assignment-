/*
 * 7seg.c
 *
 * Created: 6/24/2024 6:44:43 PM
 * Author : kirol
 */ 
#include "STD_TYPE.h"
#include "DIO_reg.h"
#include "DIO_interface.h"
#include "seg.h"
#include <util/delay.h>

#define GREEN_LED_PORT DIO_PORTD
#define GREEN_LED_PIN  DIO_PIN3
#define YELLOW_LED_PORT DIO_PORTC
#define YELLOW_LED_PIN  DIO_PIN7
#define RED_LED_PORT DIO_PORTC
#define RED_LED_PIN DIO_PIN2

void delay_seconds(u8 seconds) {
	for (u8 i = seconds; i > 0; --i) {
		u8 tens = i / 10;
		u8 ones = i % 10;
		for (u8 j = 0; j < 100; ++j) {
			BCDSevenSegment_WriteNumberAndSelect(tens, Left7Seg);
			_delay_ms(5);
			BCDSevenSegment_WriteNumberAndSelect(ones, Right7Seg);
			_delay_ms(5);
			_delay_ms(100);
		}
	}
}

int main(void)
{
	
	// Initialize DIO
	DIO_voidSetPinDir(GREEN_LED_PORT, GREEN_LED_PIN, OUTPUT);
	DIO_voidSetPinDir(YELLOW_LED_PORT, YELLOW_LED_PIN, OUTPUT);
	DIO_voidSetPinDir(RED_LED_PORT, RED_LED_PIN, OUTPUT);

	// Initialize 7-segment displays
	BCDSevenSegment_Initialization();
    
	while (1)
	{
		// Green light on, others off
		DIO_voidSetPinVal(GREEN_LED_PORT, GREEN_LED_PIN, HIGH);
		DIO_voidSetPinVal(YELLOW_LED_PORT, YELLOW_LED_PIN, LOW);
		DIO_voidSetPinVal(RED_LED_PORT, RED_LED_PIN, LOW);
		delay_seconds(60);

		// Yellow light on, others off
		DIO_voidSetPinVal(GREEN_LED_PORT, GREEN_LED_PIN, LOW);
		DIO_voidSetPinVal(YELLOW_LED_PORT, YELLOW_LED_PIN, HIGH);
		DIO_voidSetPinVal(RED_LED_PORT, RED_LED_PIN, LOW);
		delay_seconds(5);

		// Red light on, others off
		DIO_voidSetPinVal(GREEN_LED_PORT, GREEN_LED_PIN, LOW);
		DIO_voidSetPinVal(YELLOW_LED_PORT, YELLOW_LED_PIN, LOW);
		DIO_voidSetPinVal(RED_LED_PORT, RED_LED_PIN, HIGH);
		delay_seconds(60);
	}

	return 0;
}

