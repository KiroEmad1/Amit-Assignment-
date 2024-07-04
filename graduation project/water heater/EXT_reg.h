/*
 * EXT_reg.h
 *
 * Created: 08/03/2024 20:40:14
 *  Author: AMIT
 */ 


#ifndef EXT_REG_H_
#define EXT_REG_H_


#define MCUCR_REG      *((volatile u8*)0x55)
#define GICR_REG       *((volatile u8*)0x5B)
#define MCUCSR_REG     *((volatile u8*)0x54)

#endif /* EXT_REG_H_ */