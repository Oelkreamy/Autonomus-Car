/*
 * TIMR0_Config.h
 *
 * Created: 1/24/2023 9:56:38 PM
 *  Author: Lenovo
 */ 


#ifndef TIMR0_CONFIG_H_
#define TIMR0_CONFIG_H_

#define TCCR0_F0C0 7 
#define TCCR0_WGM00 6
#define TCCR0_COM01 5
#define TCCR0_COM00 4
#define TCCR0_WGM01 3
#define TCCR0_CS02 2
#define TCCR0_CS01 1
#define TCCR0_CS00 0
#define TIMSK_OCIE0 1
#define TIMSK_TOIE0 0

/* modes:
1- normal mode
2- pwm,phase mode
3- ctc mode
4- fast pwm mode*/
typedef enum{
	 Normal_Mode ,
	 PWM_Phase_Mode ,
	 CTC_Mode,
	 Fast_PWM_Mode	
	}TIMR0_Modes;
	
//use external clock 
 typedef enum{
	 EXT_T0_Failling_edge,
	 EXT_T0_rising_edge,
	 NONE
	 
	 }EXT_Clk;


 //capture modes
 typedef enum{
	 normal,
	 Clear_CompareMatch,
	 set_CompareMatch
 }CaptureMode0;  



#endif /* TIMR0_CONFIG_H_ */