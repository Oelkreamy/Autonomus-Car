/*
 * TIMR_HW.h
 *
 * Created: 1/25/2023 5:23:34 PM
 *  Author: Lenovo
 */ 


#ifndef TIMR_HW_H_
#define TIMR_HW_H_

#include "DIO.h"
#include "STD_Types.h"

#define TIMER0_TCCR0_REG (*(volatile Uint8 *)0x53) 
#define TIMER0_TCNT0_REG (*(volatile Uint8 *)0x52)
#define TIMER0_OCR0_REG (*(volatile Uint8 *)0x5C)
#define TIMER0_TIMSK_REG (*(volatile Uint8 *)0x59)
#define TIMER0_TIFR_REG (*(volatile Uint8 *)0x58)





#endif /* TIMR_HW_H_ */