/*
 * seg.h
 *
 * Created: 3/7/2024 10:14:43 PM
 *  Author: Saeed
 */ 


#ifndef SEG_H_
#define SEG_H_
typedef enum
{
	Left7Seg,
	Right7Seg
} BCDSevenSegment_Pos;

/* Function to initialize 7Segment component */
void BCDSevenSegment_Initialization(void);

/* Fuion to write a number on one of the 7 segments */
void BCDSevenSegment_WriteNumberAndSelect(u8 Value, BCDSevenSegment_Pos Select7Seg);
/* Fuion to write a number on 7 segment */
void BCDSevenSegment_WriteNumber(u8 Value , f32 delay_sec);
/* Fuion to enable 7segment 1 */
void BCDSevenSegment_Enable1(void);
/* Fuion to enable 7segment 2 */
void BCDSevenSegment_Enable2(void);
/* Fuion to disable 7segment 1 */
void BCDSevenSegment_Disable1(void);
/* Fuion to disable 7segment 2 */
void BCDSevenSegment_Disable2(void);




#endif /* SEG_H_ */