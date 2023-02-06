/*
* TIMR0.c
*
* Created: 12/15/2022 11:43:11 PM
*  Author: Lenovo
*/



#include "TIMR0.h"

void TIMR0_INIT(TIMR0_Modes MODE){
     TIMER0_TCCR0_REG &= 0b10110111;
	switch (MODE)
	{
		case Normal_Mode:
		TIMER0_TCCR0_REG &=~ ((1<<TCCR0_WGM00) | (1<<TCCR0_WGM01));
		break;
		case PWM_Phase_Mode:
		TIMER0_TCCR0_REG |= (1<<TCCR0_WGM00);
		break;
		case CTC_Mode:
		TIMER0_TCCR0_REG |= (1<<TCCR0_WGM01);
		break;
		case Fast_PWM_Mode:
		TIMER0_TCCR0_REG |= ((1<<TCCR0_WGM00) | (1<<TCCR0_WGM01));
		break;
	}
}

void TIMR0_Start(Uint16 prescaler , EXT_Clk Exteranl_Clk_Src ){
	//as soon as you set the prescaler the timer is on
	TIMER0_TCCR0_REG &= 0b11111000;
	switch (prescaler)
	{
		case 0 :
		TIMER0_TCCR0_REG &=~ ((1<<TCCR0_CS00)| (1<<TCCR0_CS01) | (1<<TCCR0_CS02));
		break;
		case 1 :
		TIMER0_TCCR0_REG |= (1<<TCCR0_CS00);
		break;
		
		case 8 :
		TIMER0_TCCR0_REG |= (1<<TCCR0_CS01);
		break;
		
		case 64 :
		TIMER0_TCCR0_REG |= ((1<<TCCR0_CS00) | (1<<TCCR0_CS01));
		break;
		
		case 256 :
		TIMER0_TCCR0_REG |= (1<<TCCR0_CS02);
		break;
		
		case 1024:
		TIMER0_TCCR0_REG |= ((1<<TCCR0_CS00) | (1<<TCCR0_CS02));
		break;
	}

}


void TIMR0_Stop(void)
{
		TIMER0_TCCR0_REG  &= 0b11111000; //stop
}



void TIMR0_Preload(Uint8 preload){
	TIMER0_TCNT0_REG = preload ;
}


Uint8 TIMR0_Get_Preload(void){
	return TIMER0_TCNT0_REG ;
}


void TIMR0_Enable_Interrupt(TIMR0_Modes MODE){
	if (MODE == Normal_Mode){
	SetBit (TIMER0_TIMSK_REG ,TIMSK_TOIE0);// overflow interrupt enable
	
	}
	else if (MODE == CTC_Mode){
	SetBit (TIMER0_TIMSK_REG ,TIMSK_OCIE0); // compare match interrupt enable
	}
	
}

void TIMR0_Disable_Interrupt(TIMR0_Modes MODE){
		if (MODE == Normal_Mode){
			ClearBit (TIMER0_TIMSK_REG ,TIMSK_TOIE0);// overflow interrupt enable
		}
		else if (MODE == CTC_Mode){
			ClearBit (TIMER0_TIMSK_REG ,TIMSK_OCIE0); // compare match interrupt enable
		}
}



void TIMR0_SetCompare_Value(Uint8 CompareValue){
	TIMER0_OCR0_REG = CompareValue ;
}


void TIMR0_Clear(void){
	
	TIMER0_TCNT0_REG = 0 ; 
}


void TIMR0_PWM(Uint8 dutyCycle , Uint8 TIMER_TOP , CaptureMode0 Compare_OUT_MOD)
{  
	switch (Compare_OUT_MOD)
{
    case normal :
    TIMER0_TCCR0_REG = 0b11001111;
	break;
	case Clear_CompareMatch:
	TIMER0_TCCR0_REG |= (1<<TCCR0_COM01);
	break;
	case set_CompareMatch:
	TIMER0_TCCR0_REG |= (1<<TCCR0_COM01) | (1<<TCCR0_COM00);
	break;
}
	 
	Uint16 result =0;
	result = (dutyCycle * TIMER_TOP)/100;
	TIMER0_OCR0_REG = result;

}

