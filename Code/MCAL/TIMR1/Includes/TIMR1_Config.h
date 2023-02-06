/*
 * TIMR1_Config.h
 *
 * Created: 1/25/2023 2:43:49 PM
 *  Author: Lenovo
 */ 


#ifndef TIMR1_CONFIG_H_
#define TIMR1_CONFIG_H_


#define TCCR1A_WGM10 0
#define TCCR1A_WGM11 1
#define TCCR1A_F0C1B 2
#define TCCR1A_F0C1A 3
#define TCCR1A_COM1B0 4
#define TCCR1A_COM1B1 5
#define TCCR1A_COM1A0 6
#define TCCR1A_COM1A1 7
#define TCCR1B_CS10 0
#define TCCR1B_CS11 1
#define TCCR1B_CS12 2
#define TCCR1B_WGM12 3
#define TCCR1B_WGM13 4
#define TCCR1B_ICES1 6
#define TCCR1B_ICNC1 7
#define TIMSK_TICIE1 5 
#define TIMSK_OCIE1A 4
#define TIMSK_OCIE1B 3 
#define TIMSK_TOIE1 2


/* modes:
1- normal mode
2- pwm,phase mode
3- ctc mode
4- fast pwm mode*/

//modes in detail 
typedef enum{
 NORMAL, 
 PWM_PHASE_CORRECT_8BIT, 
 PWM_PHASE_CORRECT_9BIT, 
 PWM_PHASE_CORRECT_10BIT, 
 CTC_OCR1A, 
 FAST_PWM_8BIT, 
 FAST_PWM_9BIT,
 FAST_PWM_10BIT, 
 CTC_ICR1, 
 FAST_PWM_ICR1, 
 FAST_PWM_OCR1A 
}TIMER1_Modes;


//capture modes 
typedef enum{
	normal1,
	toggle,
	rising, //clear on compare match
	failing //set on compare match 
	}CaptureMode;
	
typedef enum{
	INPUT_Capture,
	OUTPUT_Comare_A,
	OUTPUT_Comare_B,
	Overflow_EN
}INT_Modes;

typedef enum{
	TIMR1_A,
	TIMR1_B
	
}TIMR1_TYPES;


#endif /* TIMR1_CONFIG_H_ */