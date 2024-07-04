/*
 * EXT_interface.h
 *
 * Created: 08/03/2024 20:39:57
 *  Author: AMIT
 */ 


#ifndef EXT_INTERFACE_H_
#define EXT_INTERFACE_H_


/* INTERRUPT PINS  */

#define  INT_0       0 
#define  INT_1       1 
#define  INT_2       2

/* SENS control  */ 

#define  RISING_EDGE               0 
#define  FALLING_EDGE              1
#define  ANY_LOGICAL_CHANGE        2
#define  LOW_LEVEL                 3 

void EXT_voidInit(u8 copy_u8SensControl , u8 copy_u8INT) ; 
void EXT_voidSetCallBack(u8 copy_u8ptr , void(*ptr)(void)) ; 
void EXT_voidINT0Enable(void) ; 
void EXT_voidINT0Disable(void) ;
void EXT_voidINT1Enable(void) ;
void EXT_voidINT1Disable(void) ;
void EXT_voidINT2Enable(void) ;
void EXT_voidINT2Disable(void) ;
#endif /* EXT_INTERFACE_H_ */