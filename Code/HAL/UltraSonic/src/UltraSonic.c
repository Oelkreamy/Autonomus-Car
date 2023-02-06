/*
 * UltraSonic.c
 *
 * Created: 1/25/2023 12:14:58 AM
 *  Author: Lenovo
 */ 




#include "UltraSonic.h"
#include "LCD.h"

volatile Uint16 Timer_Overflow;
Uint8 interrupt = 0 ;
Uint8 sensor_in_work = 0 ;

void ultrasonic_init(void){

DIO_WriteChannel(DIO_ChannelD3 , STD_High); // PULLUP
TIMR0_INIT(Normal_Mode);
TIMR0_Enable_Interrupt(Normal_Mode);


}


void Measure_Distance (DIO_ChannelTypes trig_ChannelID){
	if(sensor_in_work == 0) {
	TIMR0_Clear();
	sensor_in_work = 1 ;  
	Ext_INT_Sncontrol(Ext_INT1,Both_Edge);
	Ext_INT_Enable(Ext_INT1);
	DIO_WriteChannel(trig_ChannelID , STD_High); //send 10us to start measuring 
	_delay_ms(10);
	DIO_WriteChannel(trig_ChannelID ,STD_Low);	
}
}

uint64 get_distance(DIO_ChannelTypes trig_ChannelID)
{
	Measure_Distance(trig_ChannelID);
	_delay_ms(15);
	return distance;
}
  
  
  
void compare_distance(uint64 left1 , uint64 right1){
	if (left1 > 30 || right1 > 30){
	if (left1 > right1)
	{   LCD_Clear();
		LCD_String("moving left...");
		_delay_ms(1000);
		left();
		_delay_ms(200);
		servo_angle(0 , 64 , TIMR1_A);
	    }
	
	else{
		LCD_Clear();
		LCD_String("moving right...");
		right();
		_delay_ms(200);
		servo_angle(0 , 64 , TIMR1_A);
		_delay_ms(1000);
	}
	
	}
	
	else{
		
		LCD_Clear();
		LCD_String("turning...");
		backward();
		_delay_ms(800);
		 turn();
		_delay_ms(500);
		servo_angle(0 ,64 , TIMR1_A);
		_delay_ms(1000);
		stop();
	}
	
}