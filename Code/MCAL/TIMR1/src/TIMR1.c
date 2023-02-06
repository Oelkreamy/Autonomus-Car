/*
* TIMR1.c
*
* Created: 1/25/2023 2:47:34 PM
*  Author: Lenovo
*/


#include "TIMR1.h"

//per-build_configuration

void TIMR1_INIT(TIMER1_Modes mode){
	TIMER1_TCCR1A_REG &= 0b11111100;
	TIMER1_TCCR1B_REG &= 0b11100111;
	switch (mode)
	{
		case NORMAL :
		
		break;
		case PWM_PHASE_CORRECT_8BIT :
		SetBit(TIMER1_TCCR1A_REG , TCCR1A_WGM10);
		break;
		case PWM_PHASE_CORRECT_9BIT :
		SetBit(TIMER1_TCCR1A_REG , TCCR1A_WGM11);
		break;
		case PWM_PHASE_CORRECT_10BIT :
		SetBit(TIMER1_TCCR1A_REG , TCCR1A_WGM10 );
		SetBit(TIMER1_TCCR1A_REG , TCCR1A_WGM11);
		
		break;
		case CTC_OCR1A :
		SetBit(TIMER1_TCCR1B_REG , TCCR1B_WGM12 );
		
		break;
		case FAST_PWM_8BIT :
		SetBit(TIMER1_TCCR1A_REG , TCCR1A_WGM10 );
		SetBit(TIMER1_TCCR1B_REG , TCCR1B_WGM12 );
		
		break;
		
		case FAST_PWM_9BIT :
		SetBit(TIMER1_TCCR1A_REG , TCCR1A_WGM11);
		SetBit(TIMER1_TCCR1B_REG , TCCR1B_WGM12 );
		break;
		case FAST_PWM_10BIT :
		SetBit(TIMER1_TCCR1A_REG , TCCR1A_WGM10 );
		SetBit(TIMER1_TCCR1A_REG , TCCR1A_WGM11);
		SetBit(TIMER1_TCCR1B_REG , TCCR1B_WGM12 );
		break;
		case CTC_ICR1 :
		SetBit(TIMER1_TCCR1B_REG , TCCR1B_WGM12 );
		SetBit(TIMER1_TCCR1B_REG , TCCR1B_WGM13 );
		break;
		
		case FAST_PWM_ICR1 :
		SetBit(TIMER1_TCCR1A_REG , TCCR1A_WGM11);
		SetBit(TIMER1_TCCR1B_REG , TCCR1B_WGM12 );
		SetBit(TIMER1_TCCR1B_REG , TCCR1B_WGM13 );
		break;
		case FAST_PWM_OCR1A :
		SetBit(TIMER1_TCCR1A_REG , TCCR1A_WGM10 );
		SetBit(TIMER1_TCCR1A_REG , TCCR1A_WGM11);
		SetBit(TIMER1_TCCR1B_REG , TCCR1B_WGM12 );
		SetBit(TIMER1_TCCR1B_REG , TCCR1B_WGM13 );
		
		break;
	}

}




void TIMR1_Start(Uint16 prescaler){
	TIMER1_TCCR1B_REG &= 0b11111000;
	switch (prescaler)
	{
		case 0 :
		TIMER1_TCCR1B_REG &=~ ((1<<TCCR1B_CS10)| (1<<TCCR1B_CS11) | (1<<TCCR1B_CS12));
		break;
		case 1 :
		TIMER1_TCCR1B_REG |= (1<<TCCR1B_CS10);
		break;
		
		case 8 :
		TIMER1_TCCR1B_REG |= (1<<TCCR1B_CS11);
		break;
		
		case 64 :
		TIMER1_TCCR1B_REG |= ((1<<TCCR1B_CS10) | (1<<TCCR1B_CS11));
		break;
		
		case 256 :
		TIMER1_TCCR1B_REG |= (1<<TCCR1B_CS12);
		break;
		
		case 1024:
		TIMER1_TCCR1B_REG |= ((1<<TCCR1B_CS10) | (1<<TCCR1B_CS12));
		break;
	}
	
	
}




void TIMR1_Stop(void){
	TIMER1_TCCR1B_REG  &= 0b11111000; //stop
}




void TIMR1_Preload(Uint16 preload){
	TIMER1_TCNT1L_REG = preload ; //load in high register
	TIMER1_TCNT1H_REG |= (preload>>8);//load in low register
}




Uint16  TIMR1_GetPreload(void){
	Uint16 counter_value = TIMER1_TCNT1H_REG;
	counter_value = (counter_value<<8);
	counter_value |= TIMER1_TCNT1L_REG;
	
	return counter_value;
}



void TIMR1_Enable_Interrupt(INT_Modes MODE){
	if (MODE == INPUT_Capture){
		SetBit (TIMER1_TIMSK_REG ,TIMSK_TICIE1);// INput capture interrupt enable
		
	}
	else if (MODE == OUTPUT_Comare_A){
		SetBit (TIMER1_TIMSK_REG ,TIMSK_OCIE1A); // compare match interrupt enable A
	}
	
	else if (MODE == OUTPUT_Comare_B){
		SetBit (TIMER1_TIMSK_REG ,TIMSK_OCIE1B); // compare match interrupt enable B
	}
	else if (MODE == Overflow_EN){
		SetBit (TIMER1_TIMSK_REG ,TIMSK_TOIE1); // overflow INT EN
	}
}

void TIMR1_Disable_Interrupt(INT_Modes MODE ){
	if (MODE == INPUT_Capture){
		ClearBit (TIMER1_TIMSK_REG ,TIMSK_TICIE1);// INput capture interrupt enable
		
	}
	else if (MODE == OUTPUT_Comare_A){
		ClearBit (TIMER1_TIMSK_REG ,TIMSK_OCIE1A); // compare match interrupt enable A
	}
	
	else if (MODE == OUTPUT_Comare_B){
		ClearBit (TIMER1_TIMSK_REG ,TIMSK_OCIE1B); // compare match interrupt enable B
	}
	else if (MODE == Overflow_EN){
		ClearBit (TIMER1_TIMSK_REG ,TIMSK_TOIE1); // overflow INT EN
	}
	
}



void TIMR1_SetCompare_Value(Uint16 CompareValue , TIMR1_TYPES timer_type){
	if (timer_type == TIMR1_A)
	{
		TIMER1_OCR1AH_REG = (CompareValue>>8);
		TIMER1_OCR1AL_REG = (CompareValue);
	}

	else if (timer_type == TIMR1_B)
	{
		TIMER1_OCR1BH_REG = (CompareValue>>8);
		TIMER1_OCR1BL_REG = (CompareValue);
	}
}





void TIMR1_PWM(Uint8 dutyCycle , Uint16 TIMER_TOP , TIMR1_TYPES timer_type)
{
	Uint16 result =0;
	
	result = (dutyCycle * TIMER_TOP)/100;
	if (timer_type == TIMR1_A)
	{
		TIMER1_OCR1AH_REG = (result>>8);
		TIMER1_OCR1AL_REG = result;
	}
	else if (timer_type == TIMR1_B)
	{
		TIMER1_OCR1BH_REG = (result>>8);
		TIMER1_OCR1BL_REG = result;
	}
	
	
}



void TIMER1_Clear(void){
	TIMER1_TCNT1H_REG = 0 ;
	TIMER1_TCNT1L_REG = 0 ;
}


void TIMER1_PreLoad(Uint16 PreLoad){
	TIMER1_TCNT1H_REG = ( PreLoad>>8);
	TIMER1_TCNT1L_REG =  PreLoad ;
}


void TIMER1_CaptureMode(CaptureMode C_mode , TIMR1_TYPES timer_type){
  TIMER1_TCCR1A_REG &= 0b00111111;
	switch (timer_type)
	{
		case TIMR1_A:
		switch (C_mode)
		{   case normal1:
			TIMER1_TCCR1A_REG &=~ ((1<<TCCR1A_COM1A0)|(1<<TCCR1A_COM1A1));
			break;
			case toggle:
			TIMER1_TCCR1A_REG |= 0b01000000;
			break;
			case rising:
			TIMER1_TCCR1A_REG |= 0b10000000;
			break;
			case failing:
			TIMER1_TCCR1A_REG |= 0b11000000;
			break;
		}
		break;
		case TIMR1_B:
		switch (C_mode)
		{   case normal1:
			TIMER1_TCCR1A_REG &=~ ((1<<TCCR1A_COM1B0)|(1<<TCCR1A_COM1B1));
			break;
			case toggle:
			TIMER1_TCCR1A_REG |= 0b00010000;
			break;
			case rising:
			TIMER1_TCCR1A_REG |= 0b01000000;
			break;
			case failing:
			TIMER1_TCCR1A_REG |= 0b00110000;
			break;
		}
		break;
	}
	
}