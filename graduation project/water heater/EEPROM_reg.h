
/*
 * EEPROM_reg.h
 *
 * Created: 7/4/2024 4:18:29 AM
 *  Author: kirol
 */ 
#ifndef EEPROM_reg_H
#define EEPROM_reg_H
// EEPROM Control Register (EECR) bits
#define EERE  0 // EEPROM Read Enable
#define EEWE  1 // EEPROM Write Enable
#define EEMWE 2 // EEPROM Master Write Enable
#define EECR_EERIE 3 // EEPROM Ready Interrupt Enable
// EEPROM Data Register (EEDR)
#define EEDR (*(volatile u8 *)0x3D)

// EEPROM Address Register (EEAR) - 16-bit register
#define EEAR  (*(volatile u16 *)0x3E)
#define EEARL (*(volatile u8 *)0x3E)
#define EEARH (*(volatile u8 *)0x3F)

// EEPROM Control Register (EECR)
#define EECR  (*(volatile u8 *)0x3C)
#endif