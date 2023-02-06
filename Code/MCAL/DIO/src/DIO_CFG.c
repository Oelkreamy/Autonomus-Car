/*
* DIO_CFG.c
*
* Created: 9/24/2022 8:44:38 PM
*  Author: user
*/

#include "DIO_CFG.h"

DIO_PinCfg PinCfg[] = {
	//PORTA
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTB
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTC
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Input,STD_High},
	{Output,STD_High},
	{Output,STD_Low},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTD
	{Input,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Input,STD_High},
	{Input,STD_Low},
	{Output,STD_Low},
	{Input,STD_Low},
	{Output,STD_Low}
};

void DIO_Init(void){
	DIO_ChannelTypes count = DIO_ChannelA0;
	DIO_PortTypes Portx;
	DIO_ChannelTypes BitNo;
	for (count = DIO_ChannelA0;count<PINCOUNT;count++)
	{
		Portx = count/8;
		BitNo = count%8;
		switch(Portx){
			case DIO_PortA:
			if (PinCfg[count].PinDir == Output)
			{
				SetBit(DDRA_Reg,BitNo);
			}
			else{
				ClearBit(DDRA_Reg,BitNo);
			}
			break;
			case DIO_PortB:
			if (PinCfg[count].PinDir == Output)
			{
				SetBit(DDRB_Reg,BitNo);
			}
			else{
				ClearBit(DDRB_Reg,BitNo);
			}
			break;
			case DIO_PortC:
			if (PinCfg[count].PinDir == Output)
			{
				SetBit(DDRC_Reg,BitNo);
			}
			else{
				ClearBit(DDRC_Reg,BitNo);
			}
			break;
			case DIO_PortD:
			if (PinCfg[count].PinDir == Output)
			{
				SetBit(DDRD_Reg,BitNo);
			}
			else{
				ClearBit(DDRD_Reg,BitNo);
			}
			break;
		}
	}
}