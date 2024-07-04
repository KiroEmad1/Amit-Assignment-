/*
 * water heater.c
 *
 * Created: 6/23/2024 11:51:18 PM
 * Author : kirolos Emad Awni
 */
#include "STD_TYPE.h" 
#include "DIO_interface.h"
#include "DIO_reg.h"
#include "ADC_interface.h"
#include "ADC_reg.h"
#include "BIT_MATH.h"
#include "EXT_reg.h"
#include "EXT_interface.h"
#include "seg.h"
#include "GI_reg.h"
#include "GI_interface.h"
#include "EEPROM_reg.h"
#include "eeprom_interface.h"
#define F_CPU 16000000UL 
#include <util/delay.h>



// Pin Definitions
#define UP_BUTTON_PIN       DIO_PIN3
#define DOWN_BUTTON_PIN     DIO_PIN2
#define ON_OFF_BUTTON_PIN   DIO_PIN3
#define HEATER_PIN          DIO_PIN4
#define COOLER_PIN          DIO_PIN5
#define HEATER_LED_PIN      DIO_PIN6

// ADC Channel for Temperature Sensor
#define TEMP_SENSOR_CHANNEL ADC_0

// EEPROM Address for storing the set temperature
#define EEPROM_ADDRESS      0x00

// Temperature Settings
#define MIN_TEMP            35
#define MAX_TEMP            75
#define DEFAULT_TEMP        60

// Global Variables
static u8 current_temp = 60;
u8 set_temp = DEFAULT_TEMP;
BOOL heater_state = False;
BOOL temp_setting_mode = False;
u8 count = 0;
u8 time5s = 0;
u8 countled = 0;

// Function Prototypes
void ledtoggle(void);
void intialize_system(void);
void updateTemperature(void);
void handleUpButton(void);
void handleDownButton(void);
void handleOnOffButton(void);
void displayTemperature(void);
void checkHeaterCoolerState(void);

int main(void) {
	// Initialize system
	intialize_system();

	while(1) {
		// Only operate heater and cooler if heater is turned on
		if (heater_state == 1) {
			updateTemperature();
			checkHeaterCoolerState();
			displayTemperature();
		}
	}

	return 0;
}

void intialize_system(void) {
	// Set up button pins as input
	DIO_voidSetPinDir(DIO_PORTB, UP_BUTTON_PIN, INPUT);
	DIO_voidSetPinDir(DIO_PORTA, DIO_PIN0, INPUT);
	DIO_voidSetPinDir(DIO_PORTD, DOWN_BUTTON_PIN, INPUT);
	DIO_voidSetPinDir(DIO_PORTD, ON_OFF_BUTTON_PIN, INPUT);

	// Set up heater, cooler, and LED pins as output
	DIO_voidSetPinDir(DIO_PORTA, HEATER_PIN, OUTPUT);
	DIO_voidSetPinDir(DIO_PORTA, COOLER_PIN, OUTPUT);
	DIO_voidSetPinDir(DIO_PORTA, HEATER_LED_PIN, OUTPUT);

	// Initialize 7-segment display and ADC
	BCDSevenSegment_Initialization();
	ADC_voidInit();

	// Read the set temperature from EEPROM
	set_temp = EEPROM_read(EEPROM_ADDRESS);
	if(set_temp < MIN_TEMP || set_temp > MAX_TEMP) {
		set_temp = DEFAULT_TEMP;
	}

	// Enable global interrupts
	GI_voidEnable();

	// Initialize external interrupts for buttons
	EXT_voidInit(RISING_EDGE, INT_0);
	EXT_voidInit(RISING_EDGE, INT_1);
	EXT_voidInit(RISING_EDGE, INT_2);

	// Enable external interrupts
	EXT_voidINT0Enable();
	EXT_voidINT1Enable();
	EXT_voidINT2Enable();

	// Set callbacks for button interrupts
	EXT_voidSetCallBack(INT_0, handleUpButton);
	EXT_voidSetCallBack(INT_1, handleDownButton);
	EXT_voidSetCallBack(INT_2, handleOnOffButton);
}

void updateTemperature(void) {
	u16 sum = 0;
	u8 val = 0;
	u16 temp = 0;

	// Take 10 readings from the ADC and average them
	for (u8 index = 0; index < 10; index++) {
		temp = ADC_u16ReadChannel(ADC_0);
		val = temp * 500 / 1023;
		sum += val;

		// Display the current temperature on the 7-segment display
		for (u8 index1 = 0; index1 < 10; index1++) {
			u8 tens = current_temp / 10;
			u8 ones = current_temp % 10;
			BCDSevenSegment_WriteNumberAndSelect(ones, Left7Seg);
			_delay_ms(5);
			BCDSevenSegment_WriteNumberAndSelect(tens, Right7Seg);
			_delay_ms(5);
		}
	}

	// Update the current temperature with the averaged value
	current_temp = sum / 10;
}

void handleUpButton(void) {
	// Handle the up button press
	if (temp_setting_mode) {
		// Increase the set temperature by 5 if within the allowed range
		if (set_temp + 5 <= MAX_TEMP) {
			set_temp += 5;
			EEPROM_write(EEPROM_ADDRESS, set_temp);
			_delay_ms(15);
		}
		} else {
		temp_setting_mode = True;
	}
	time5s = 0;
}

void handleDownButton(void) {
	// Handle the down button press
	if (temp_setting_mode) {
		// Decrease the set temperature by 5 if within the allowed range
		if (set_temp - 5 >= MIN_TEMP) {
			set_temp -= 5;
			EEPROM_write(EEPROM_ADDRESS, set_temp);
			_delay_ms(15);
		}
		} else {
		temp_setting_mode = True;
	}
	time5s = 0;
}

void handleOnOffButton(void) {
	// Toggle the heater state
	heater_state = !heater_state;
	if (!heater_state) {
		// Turn off the heater, cooler, and LED, and disable 7-segment display
		DIO_voidSetPinVal(DIO_PORTA, HEATER_PIN, LOW);
		DIO_voidSetPinVal(DIO_PORTA, COOLER_PIN, LOW);
		DIO_voidSetPinVal(DIO_PORTA, HEATER_LED_PIN, LOW);
		BCDSevenSegment_Disable1();
		BCDSevenSegment_Disable2();
	}
}

void displayTemperature(void) {
	// Display the set or current temperature on the 7-segment display
	if (temp_setting_mode && heater_state) {
		// Blink the set temperature for 5 seconds
		while (time5s < 5) {
			for (u8 count6 = 0; count6 < 45; count6++) {
				u8 tens = set_temp / 10;
				u8 ones = set_temp % 10;
				BCDSevenSegment_WriteNumberAndSelect(ones, Left7Seg);
				_delay_ms(10);
				BCDSevenSegment_WriteNumberAndSelect(tens, Right7Seg);
				_delay_ms(10);
			}
			BCDSevenSegment_Disable1();
			BCDSevenSegment_Disable2();
			_delay_ms(100);
			time5s++;
		}
		temp_setting_mode = False;
		} else if (heater_state) {
		// Display the current temperature
		u8 tens = current_temp / 10;
		u8 ones = current_temp % 10;
		BCDSevenSegment_WriteNumberAndSelect(ones, Left7Seg);
		_delay_ms(5);
		BCDSevenSegment_WriteNumberAndSelect(tens, Right7Seg);
		_delay_ms(5);
		} else if (!heater_state) {
		// Turn off the 7-segment display if heater is off
		BCDSevenSegment_Disable1();
		BCDSevenSegment_Disable2();
	}
}

void checkHeaterCoolerState(void) {
	// Control the heater and cooler based on the current temperature
	if (current_temp <= set_temp - 5) {
		// Turn on the heater and off the cooler
		DIO_voidSetPinVal(DIO_PORTA, HEATER_PIN, HIGH);
		DIO_voidSetPinVal(DIO_PORTA, COOLER_PIN, LOW);
		ledtoggle();
		} else if (current_temp >= set_temp + 5) {
		// Turn off the heater and on the cooler
		DIO_voidSetPinVal(DIO_PORTA, HEATER_PIN, LOW);
		DIO_voidSetPinVal(DIO_PORTA, COOLER_PIN, HIGH);
		DIO_voidSetPinVal(DIO_PORTA, HEATER_LED_PIN, HIGH);
		} else if (current_temp == set_temp) {
		// Turn off both the heater and cooler
		DIO_voidSetPinVal(DIO_PORTA, HEATER_PIN, LOW);
		DIO_voidSetPinVal(DIO_PORTA, COOLER_PIN, LOW);
		DIO_voidSetPinVal(DIO_PORTA, HEATER_LED_PIN, LOW);
	}

	if (!heater_state) {
		// Ensure everything is off if heater is off
		DIO_voidSetPinVal(DIO_PORTA, HEATER_PIN, LOW);
		DIO_voidSetPinVal(DIO_PORTA, COOLER_PIN, LOW);
		DIO_voidSetPinVal(DIO_PORTA, HEATER_LED_PIN, LOW);
	}
}

void ledtoggle(void) {
	// Toggle the heater LED
	if (!countled) {
		DIO_voidSetPinVal(DIO_PORTA, HEATER_LED_PIN, HIGH);
		countled = 1;
		} else {
		DIO_voidSetPinVal(DIO_PORTA, HEATER_LED_PIN, LOW);
		countled = 0;
	}
}

 