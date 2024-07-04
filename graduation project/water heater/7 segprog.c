/*
 * lol.c
 *
 * Created: 3/7/2024 10:21:36 PM
 *  Author: kirolos
 */ 
#include "BIT_MATH.h"
#include "STD_TYPE.h"
#include "Seg.h"
#include "DIO_interface.h"
#include <util/delay.h>
//#define F_CPU 16000000UL
#define seg_port DIO_PORTC
/* Function to initialize 7Segment component */
void BCDSevenSegment_Initialization(void){
	/* Decoder inputs are set as output pins */
	DIO_voidSetPinDir(seg_port,DIO_PIN7,OUTPUT); //D
	DIO_voidSetPinDir(seg_port,DIO_PIN6,OUTPUT); //C
	DIO_voidSetPinDir(seg_port,DIO_PIN5,OUTPUT); //B
	DIO_voidSetPinDir(seg_port,DIO_PIN4,OUTPUT); //A

	/* Set direction for 7segment enable pins */
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN4,OUTPUT); //DIP
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN0,OUTPUT); //En 1
	DIO_voidSetPinDir(DIO_PORTD,DIO_PIN1,OUTPUT); //En 2
}

/* Function to write a number on one of the 7 segments */
void BCDSevenSegment_WriteNumberAndSelect(u8 Value, BCDSevenSegment_Pos Select7Seg)
{
	BCDSevenSegment_Disable1();
	BCDSevenSegment_Disable2();

	if(Value < 10)
	{
		
		/* Input Value to decoder (A, B, C, D) */
		/* Value of decoder input A */
		DIO_voidSetPinVal(seg_port, DIO_PIN4, GET_BIT(Value,0));
		/* Value of decoder input B */
		DIO_voidSetPinVal(seg_port, DIO_PIN5, GET_BIT(Value,1));
		/* Value of decoder input C */
		DIO_voidSetPinVal(seg_port, DIO_PIN6, GET_BIT(Value,2));
		/* Value of decoder input D */
		DIO_voidSetPinVal(seg_port, DIO_PIN7, GET_BIT(Value,3));

		switch(Select7Seg)
		{
			case Left7Seg:
			BCDSevenSegment_Enable1();
			break;
			case Right7Seg:
			BCDSevenSegment_Enable2();
		}
	}


}
// u8 decimalToBCD(u8 decimal) {
// 	u8 bcd = 0;
// 	u8 shift = 0;
// 
// 	while (decimal > 0) {
// 		// Extract the last decimal digit
// 		u8 digit = decimal % 10;
// 		// Convert the digit to BCD and shift to the correct position
// 		bcd |= (digit << (shift * 4));
// 		shift++;
// 		// Remove the last decimal digit
// 		decimal /= 10;
// 	}
// 
// 	return bcd;
// }
// /* Function to write a number on 7 segment */
// void BCDSevenSegment_WriteNumber1(){
// 	
// }






void BCDSevenSegment_WriteNumber(u8 Value , float delay_sec)
{
	u8 SevenSegOne, SevenSegTwo;

	if (Value < 100){
		u16 time = delay_sec*1000;

		/* 53 / 10 = 5 */
		SevenSegOne = Value / 10;
		/* 53 % 10 = 3*/
		SevenSegTwo = Value % 10;
		for (int x =0 ; x <= (time/20) ; x++){
			/* Disable seven segment 1 */
			BCDSevenSegment_Disable1();
			/* Disable seven segment 2 */
			BCDSevenSegment_Disable2();

			/* 5 --> 0b 0000 0101 (bit7 bit6 bit5  .. bit0) --> A = 1, B = 0, C = 1, D = 0 */
			/* Input Value to decoder (A, B, C, D) */
			/* Value of decoder input A */
			DIO_voidSetPinVal(seg_port, DIO_PIN4, GET_BIT(SevenSegOne,0));
			/* Value of decoder input B */
			DIO_voidSetPinVal(seg_port, DIO_PIN5, GET_BIT(SevenSegOne,1));
			/* Value of decoder input C */
			DIO_voidSetPinVal(seg_port, DIO_PIN6, GET_BIT(SevenSegOne,2));
			/* Value of decoder input D */
			DIO_voidSetPinVal(seg_port, DIO_PIN7, GET_BIT(SevenSegOne,3));

			/* Enable seven segment 1 */
			BCDSevenSegment_Enable1();

			/* 10 mSec delay */
			_delay_ms(10);

			/* Disable seven segment 1 */
			BCDSevenSegment_Disable1();

			/* 3 --> 0b 0000 0011 (bit7 bit6 bit5  .. bit0) --> A = 1, B = 1, C = 0, D = 0 */
			/* Input Value to decoder (A, B, C, D) */
			/* Value of decoder input A */
			DIO_voidSetPinVal(seg_port, DIO_PIN4, GET_BIT(SevenSegTwo,0));
			/* Value of decoder input B */
			DIO_voidSetPinVal(seg_port, DIO_PIN5, GET_BIT(SevenSegTwo,1));
			/* Value of decoder input C */
			DIO_voidSetPinVal(seg_port, DIO_PIN6, GET_BIT(SevenSegTwo,2));
			/* Value of decoder input D */
			DIO_voidSetPinVal(seg_port ,DIO_PIN7, GET_BIT(SevenSegTwo,3));

			/* Enable seven segment 2 */
			BCDSevenSegment_Enable2();

			/* 10 mSec delay */
			_delay_ms(10);

		}

	}

}

/* Function to enable 7segment 1 */
void BCDSevenSegment_Enable1(void)
{
	/* PinB2 is High */
	DIO_voidSetPinVal(DIO_PORTD,DIO_PIN0,HIGH);
}

/* Function to disable 7segment 1 */
void BCDSevenSegment_Disable1(void)
{
	/* PinB2 is Low */
	DIO_voidSetPinVal(DIO_PORTD,DIO_PIN0,LOW);
}
/* Function to enable 7segment 2 */
void BCDSevenSegment_Enable2(void)
{
	/* PinB1 is High */
	DIO_voidSetPinVal(DIO_PORTD,DIO_PIN1,HIGH);
}

/* Function to disable 7segment 2 */
void BCDSevenSegment_Disable2(void)
{
	/* PinB1 is High */
		DIO_voidSetPinVal(DIO_PORTD,DIO_PIN1,LOW);

}
