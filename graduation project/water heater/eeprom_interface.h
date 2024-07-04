/*
 * eeprom_interface.h
 *
 * Created: 7/4/2024 12:23:01 AM
 *  Author: kirol
 */ 
#ifndef eeprom_interface_h
#define eeprom_interface_h
void EEPROM_write(u8 uiAddress, u8 ucData);
u8 EEPROM_read(u32 uiAddress);
#endif