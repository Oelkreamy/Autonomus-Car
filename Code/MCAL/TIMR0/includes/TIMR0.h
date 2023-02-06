/*
 * TIMR0.h
 *
 * Created: 12/15/2022 11:42:51 PM
 *  Author: Lenovo
 */ 


#ifndef TIMR0_H_
#define TIMR0_H_
#include "TIMR_HW.h"
#include "TIMR0_Config.h"
#include "DIO.h"
//timer_functions
void TIMR0_INIT(TIMR0_Modes MODE);
void TIMR0_Start(Uint16 prescaler , EXT_Clk Exteranl_Clk_Src);
void TIMR0_Stop(void);
void TIMR0_Preload(Uint8 preload);
Uint8 TIMR0_Get_Preload(void);
void TIMR0_Enable_Interrupt(TIMR0_Modes MODE);
void TIMR0_Disable_Interrupt(TIMR0_Modes MODE);
void TIMR0_SetCompare_Value(Uint8 CompareValue);
void TIMR0_Clear(void);
void TIMR0_PWM(Uint8 dutyCycle , Uint8 TIMER_TOP , CaptureMode0 Compare_OUT_MOD);

#endif /* TIMR0_H_ */