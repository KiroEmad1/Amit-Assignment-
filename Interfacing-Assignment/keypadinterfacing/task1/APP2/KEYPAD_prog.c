/*
 * KEYPAD_prog.c
 *
 * Created: 02/03/2024 18:43:15
 *  Author: AMIT
 */ 
#include "BIT_MATH.h" 
#include "STD_TYPE.h" 
#include "DIO_interface.h" 
#include "KEYPAD_config.h"


u8 keypad_keys[4][4]={{7,8,9,'/'},
	                  {4,5,6,'*'},
					  {1,2,3,'-',},	
					   {'C',0,'=','+'}  
	                  
} ; 

void KEYPAD_voidInit(void){
	
	u8 COL_PINS[4]={KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN} ; 
	u8 ROW_PINS[4]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN} ; 
	u8 col=0 ; 
	u8 row=0 ; 
	
	 /* config CLO PINS AS OUTPUT HIGH  */		
	    for (col=0 ; col<4;col++)
	    {
			  /* MAKE COL PINS AS OUTPUT  */
			DIO_voidSetPinDir(KEYPAD_COLPORT,COL_PINS[col],OUTPUT) ; 
			/* MAKE COL PINS AS  HIGH  */
			DIO_voidSetPinVal(KEYPAD_COLPORT,COL_PINS[col],HIGH) ; 
	    }
	/* config ROW PINS AS INPUT HIGH ( to active pullup resistor )  */
	       for (row=0 ; row<4;row++)
	       {
	       	/* MAKE ROW PINS AS INPUT  */
	       	DIO_voidSetPinDir(KEYPAD_ROWPORT,ROW_PINS[row],INPUT) ;
	       	/* MAKE ROW PINS AS  HIGH  */
	       	DIO_voidSetPinVal(KEYPAD_ROWPORT,ROW_PINS[row],HIGH) ;
	       }
	       
}

u8 KEYPAD_u8GetKey(void){
	u8 key_val=0xff ; 
	
	u8 COL_PINS[4]={KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN} ;
	u8 ROW_PINS[4]={KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN} ;
	u8 col=0 ;
	u8 row=0 ;
	
	for(col=0;col<4;col++){
		
		/*  */
		DIO_voidSetPinVal(KEYPAD_COLPORT,COL_PINS[col],LOW) ; 
		
		for(row=0 ; row<4;row++){
			
			if(DIO_void_Get_PinVal(KEYPAD_ROWPORT,ROW_PINS[row])==0){
				
				key_val=keypad_keys[row][col] ; 
				
				while(DIO_void_Get_PinVal(KEYPAD_ROWPORT,ROW_PINS[row])==0) ; 
				
				return key_val ; 
			}
			
			
		}
		
		DIO_voidSetPinVal(KEYPAD_COLPORT,COL_PINS[col],HIGH) ;
		
		
		
	}
	
	
	
	return key_val ; 
	
}