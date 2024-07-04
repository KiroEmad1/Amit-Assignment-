/*
 * ADC_interface.h
 *
 * Created: 15/03/2024 23:00:53
 *  Author: AMIT
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_


/* channel  */

#define   ADC_0        0
#define   ADC_1        1
#define   ADC_2        2
#define   ADC_3        3
#define   ADC_4        4
#define   ADC_5        5
#define   ADC_6        6
#define   ADC_7        7

/* Select prescaler  */
         
#define Division_2           1 
#define Division_4           2  
/*#define Division_8           3  */
#define Division_16          4  
#define Division_32          5  
/*#define Division_64          6 */ 
#define Division_128         7   

#define  ADC_PRESCALER     Division_128
void ADC_voidInit(void) ; 

u16 ADC_u16ReadChannel(u8 copy_u8channel) ; 





#endif /* ADC_INTERFACE_H_ */