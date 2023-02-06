/*
 * LCD.h
 *
 * Created: 9/30/2022 9:01:48 PM
 *  Author: user
 */ 


#ifndef LCD_H_
#define LCD_H_

#include "Clock.h"
#include "DIO.h"

#define LCD_RS DIO_ChannelB1//data|command 
#define LCD_RW DIO_ChannelB2//read|write
#define LCD_E DIO_ChannelB3//pulse to make the LCD fetch data 

#define LCD_DataPort DIO_PortA

void LCD_Init(void);
void LCD_Cmd(Uint8 cmd);
void LCD_Char(int8 data);
void LCD_String(int8 * string);
void LCD_SetPos(Uint8 LineNo,Uint8 Pos);
void LCD_Custome_Char(Uint8 Memloc,Uint8 * msg);
void LCD_Clear(void);

#endif /* LCD_H_ */