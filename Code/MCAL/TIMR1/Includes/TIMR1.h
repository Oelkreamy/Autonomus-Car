/*
 * TIMR1.h
 *
 * Created: 1/25/2023 2:43:05 PM
 *  Author: Lenovo
 */ 


#ifndef TIMR1_H_
#define TIMR1_H_
#include "TIMR1_HW.h"
#include "TIMR1_Config.h"
#include "DIO.h"

//timer_functions
void TIMR1_INIT(TIMER1_Modes mode);
void TIMR1_Start(Uint16 prescaler);
void TIMR1_Stop(void);
void TIMR1_Preload(Uint16 preload);
Uint16 TIMR1_GetPreload(void);
void TIMR1_Enable_Interrupt(INT_Modes MODE);
void TIMR1_Disable_Interrupt(INT_Modes MODE );
void TIMR1_SetCompare_Value(Uint16 CompareValue , TIMR1_TYPES timer_type);
void TIMR1_PWM(Uint8 dutyCycle , Uint16 TIMER_TOP , TIMR1_TYPES timer_type);
void TIMER1_Clear(void);
void TIMER1_PreLoad(Uint16 PreLoad);
void TIMER1_CaptureMode(CaptureMode C_mode , TIMR1_TYPES timer_type);

#endif /* TIMR1_H_ */