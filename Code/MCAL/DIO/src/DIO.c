/*
* DIO.c
*
* Created: 9/24/2022 8:25:11 PM
*  Author: user
*/

#include "DIO.h"

void DIO_WriteChannel(DIO_ChannelTypes ChannelId,STD_LevelTypes Level){
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes BitNo = ChannelId%8;
	switch (Portx)
	{
		case DIO_PortA:
		if (Level == STD_High)
		{
			SetBit(PORTA_Reg,BitNo);
		}
		else{
			ClearBit(PORTA_Reg,BitNo);
		}
		break;
		case DIO_PortB:
		if (Level == STD_High)
		{
			SetBit(PORTB_Reg,BitNo);
		}
		else{
			ClearBit(PORTB_Reg,BitNo);
		}
		break;
		case DIO_PortC:
		if (Level == STD_High)
		{
			SetBit(PORTC_Reg,BitNo);
		}
		else{
			ClearBit(PORTC_Reg,BitNo);
		}
		break;
		case DIO_PortD:
		if (Level == STD_High)
		{
			SetBit(PORTD_Reg,BitNo);
		}
		else{
			ClearBit(PORTD_Reg,BitNo);
		}
		break;
	}
}
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes ChannelId){
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes BitNo = ChannelId%8;
	STD_LevelTypes BitValue = STD_Low;
	switch(Portx){
		case DIO_PortA:
		BitValue = GetBit(PINA_Reg,BitNo);
		break;
		case DIO_PortB:
		BitValue = GetBit(PINB_Reg,BitNo);
		break;
		case DIO_PortC:
		BitValue = GetBit(PINC_Reg,BitNo);
		break;
		case DIO_PortD:
		BitValue = GetBit(PIND_Reg,BitNo);
		break;
	}
	return BitValue;
}

Uint8 DIO_ReadPort(DIO_PortTypes PortId){
	Uint8 PortValue = 0;
	switch(PortId){
		case DIO_PortA:
		PortValue = PORTA_Reg;
		break;
		case DIO_PortB:
		PortValue = PORTB_Reg;
		break;
		case DIO_PortC:
		PortValue = PORTC_Reg;
		break;
		case DIO_PortD:
		PortValue = PORTD_Reg;
		break;
	}
	return PortValue;
}

void DIO_WritePort(DIO_PortTypes PortId,Uint8 PortValue){
	switch(PortId){
		case DIO_PortA:
		PORTA_Reg = PortValue;
		break;
		case DIO_PortB:
		PORTB_Reg = PortValue;
		break;
		case DIO_PortC:
		PORTC_Reg = PortValue;
		break;
		case DIO_PortD:
		PORTD_Reg = PortValue;
		break;
	}
}


void DIO_ToggleChannel(DIO_ChannelTypes ChannelId){
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes BitNo = ChannelId%8;
	switch (Portx)
	{
		case DIO_PortA:
		if (DIO_ReadChannel(ChannelId) == STD_Low)
		{
			SetBit(PORTA_Reg,BitNo);
		}
		else{
			ClearBit(PORTA_Reg,BitNo);
		}
		break;
		case DIO_PortB:
		if (DIO_ReadChannel(ChannelId) == STD_Low)
		{
			SetBit(PORTB_Reg,BitNo);
		}
		else{
			ClearBit(PORTB_Reg,BitNo);
		}
		break;
		case DIO_PortC:
		if (DIO_ReadChannel(ChannelId) == STD_Low)
		{
			SetBit(PORTC_Reg,BitNo);
		}
		else{
			ClearBit(PORTC_Reg,BitNo);
		}
		break;
		case DIO_PortD:
		if (DIO_ReadChannel(ChannelId) == STD_Low)
		{
			SetBit(PORTD_Reg,BitNo);
		}
		else{
			ClearBit(PORTD_Reg,BitNo);
		}
		break;
	}
}