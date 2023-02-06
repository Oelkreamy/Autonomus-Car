/*
 * servo.c
 *
 * Created: 1/30/2023 9:58:53 PM
 *  Author: Lenovo
 */ 


#include "servo.h"
#include <avr/io.h>	
#include <stdio.h>	
#include <util/delay.h>	

void servo_init(Uint16 prescaler){
	Uint16 TOP ;
	TIMER1_Clear(); //clear
	TOP = (16000000/(50*prescaler))-1; //4999 50hz 
	TIMER1_ICR1H_REG = (TOP>>8); // define top value in ICR register 
	TIMER1_ICR1L_REG = (TOP); 
	TIMER1_CaptureMode(rising , TIMR1_A); 
	TIMR1_INIT(FAST_PWM_ICR1); //Timer Modes 
	TIMR1_Start(prescaler); // set prescaler and start the timer 
}

void servo_angle(Uint16 angle , Uint8 prescaler , TIMR1_TYPES PWM_pin){
	
		double tick_time = (64.0/16000000); //calculate tick_time
		float HIGH_Time = 0 ;
		switch ((int)angle)
		{
			case -90:
			HIGH_Time = 0.52;
			break;
			case 0:
			HIGH_Time = 1.4;
			break;
			case 90:
			HIGH_Time =2.4;
			break;
		}
	
		double result = HIGH_Time*(pow(10 , 3))/(tick_time*pow(10 , 6)); // calculate OCR value 

	switch (PWM_pin)
	{
		case TIMR1_A:
		OCR1A = result ;  // set the OCR value  
		break;
		case TIMR1_B:
		OCR1B = result ; 
		break;
	}
	
	
	
}