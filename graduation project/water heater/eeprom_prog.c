/*
 * eeprom_prog.c
 *
 * Created: 7/4/2024 12:22:20 AM
 *  Author: kirol
 */ 
#include "STD_TYPE.h"
#include "EEPROM_reg.h"
#include "eeprom_interface.h"
void EEPROM_write(u8 uiAddress, u8 ucData)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address and data registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMWE */
	EECR |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EECR |= (1<<EEWE);
}
u8 EEPROM_read(u32 uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EERE);
	/* Return data from data register */
	return EEDR;
}