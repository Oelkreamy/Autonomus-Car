 /********************************
 * File  	:  Timer0.h
 * Date	 	:  Mar 23, 2021
 * Target	:  ATMEGA32
 * Author	:  Eng_Fawzi
 ********************************/
#ifndef TIMER0_H_
#define TIMER0_H_
#include "STD_Types.h"
#include "DIO.h"
/************************************************************
 * 			TIMER0 OPERATION MODES							*
 ************************************************************/
#define TIMER0_MODE_NONE            		(0)
#define TIMER0_MODE_INTERVAL             	(1)
#define TIMER0_MODE_CTC          			(2)
#define TIMER0_MODE_FAST_PWM        		(3)
#define TIMER0_MODE_PWM_PHASE_CORRECT		(4)
/*
 * TIMER0_MODE_NONE
 * TIMER0_MODE_INTERVAL
 * TIMER0_MODE_CTC
 * TIMER0_MODE_FAST_PWM
 * TIMER0_MODE_PWM_PHASE_CORRECT
 */
#define TIMER_OPERATION_MODE TIMER0_MODE_CTC

/***************************************************/
/*	TIMER0 Operation Modes	*/
#define TIMER0_INTERVAL_MODE				((Uint8)0<<3)
#define TIMER0_CTC_MODE						((Uint8)1<<3)
#define TIMER0_PWM_FAST						((Uint8)9<<3)
#define TIMER0_PWM_PHASE_CORRECT			((Uint8)8<<3)
											  
/*	TIMER0 Clock Select Prescaler	*/		  
#define TIMER0_CS_DISABLED					((Uint8)0<<0)	/* Timer0 Stopped */
#define TIMER0_CS_NO_PRESCALER				((Uint8)1<<0)
#define TIMER0_CS_8_PRESCALER				((Uint8)2<<0)
#define TIMER0_CS_64_PRESCALER				((Uint8)3<<0)
#define TIMER0_CS_256_PRESCALER				((Uint8)4<<0)
#define TIMER0_CS_1024_PRESCALER			((Uint8)5<<0)
#define TIMER0_CS_External_FAILING_EDGE		((Uint8)6<<0)
#define TIMER0_CS_External_RISING_EDGE		((Uint8)7<<0)
											  
/*	CTC Modes	*/							  
#define CTC_OC0_DISCONNECTED				((Uint8)0<<4)
#define CTC_OC0_TOGGLE						((Uint8)1<<4)
#define CTC_OC0_LOW							((Uint8)2<<4)
#define CTC_OC0_HIGH						((Uint8)3<<4)
											  
/*	Fast PWM Modes	*/						  
#define PWM_FAST_OC0_DISCONNECTED			((Uint8)0<<4)
#define PWM_FAST_OC0_NON_INVERTED			((Uint8)2<<4)
#define PWM_FAST_OC0_INVERTED				((Uint8)3<<4)
											  
/*	Phase Correct PWM Modes	*/				  
#define PWM_PHASE_CORRECT_OC0_DISCONNECTED	((Uint8)0<<4)
#define PWM_PHASE_CORRECT_OC0_NON_INVERTED	((Uint8)2<<4)
#define PWM_PHASE_CORRECT_OC0_INVERTED		((Uint8)3<<4)

/*	Timer0 Interrupt Enable	Bits */
#define TIMER0_INTERVAL_INT_ENABLE_BIT_NO		(0)
#define TIMER0_CTC_INT_ENABLE_BIT_NO			(1)

/*	Timer0 Top Value	*/
#define TIMER0_TOP 			(255u)
/***************************************************/

void TIMER0_INIT(void);

void TIMER0_StartTimer(Uint8 prescaler);
void TIMER0_StopTimer(void);

void TIMER0_SetPreLoad(Uint8 value);
Uint8 TIMER0_GetPreload(void);

void TIMER0_EnableInterrupt(void);
void TIMER0_DisableInterrupt(void);
void TIMER0_PWM(Uint8 freq, Uint8 dutyCycle);
#endif  /* TIMER0_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Timer0.h
 *********************************************************************************************************************/
