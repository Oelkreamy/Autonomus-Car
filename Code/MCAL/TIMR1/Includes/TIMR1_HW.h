/*
 * TIMR1_HW.h
 *
 * Created: 1/25/2023 2:43:23 PM
 *  Author: Lenovo
 */ 


#ifndef TIMR1_HW_H_
#define TIMR1_HW_H_

#include "DIO.h"
#include "STD_Types.h"

#define TIMER1_TCCR1A_REG (*(volatile Uint8 *)0x4F)
#define TIMER1_TCCR1B_REG (*(volatile Uint8 *)0x4E)
#define TIMER1_TCNT1H_REG (*(volatile Uint8 *)0x4D)
#define TIMER1_TCNT1L_REG (*(volatile Uint8 *)0x4C)
#define TIMER1_OCR1AH_REG (*(volatile Uint8 *)0x4B)
#define TIMER1_OCR1AL_REG (*(volatile Uint8 *)0x4A)
#define TIMER1_OCR1BH_REG (*(volatile Uint8 *)0x49)
#define TIMER1_OCR1BL_REG (*(volatile Uint8 *)0x48)
#define TIMER1_ICR1H_REG (*(volatile Uint8 *)0x47)
#define TIMER1_ICR1L_REG (*(volatile Uint8 *)0x46)
#define TIMER1_TIMSK_REG (*(volatile Uint8 *)0x59)
#define TIMER1_TIFR_REG (*(volatile Uint8 *)0x58)




#endif /* TIMR1_HW_H_ */