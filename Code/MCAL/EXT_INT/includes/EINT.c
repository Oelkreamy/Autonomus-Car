/*
* EINT.c
*
* Created: 10/7/2022 9:06:13 PM
*  Author: user
*/
#include "EINT.h"

void Ext_INT_Enable(Ext_INT_Types INTId){
	switch(INTId){
		case Ext_INT0:
		SetBit(GICR_Reg,GICR_INT0_Bit);
		break;
		case Ext_INT1:
		SetBit(GICR_Reg,GICR_INT1_Bit);
		break;
		case Ext_INT2:
		SetBit(GICR_Reg,GICR_INT2_Bit);
		break;
	}
}
void Ext_INT_Disable(Ext_INT_Types INTId){
	switch(INTId){
		case Ext_INT0:
		ClearBit(GICR_Reg,GICR_INT0_Bit);
		break;
		case Ext_INT1:
		ClearBit(GICR_Reg,GICR_INT1_Bit);
		break;
		case Ext_INT2:
		ClearBit(GICR_Reg,GICR_INT2_Bit);
		break;
	}
}
void Ext_INT_Sncontrol(Ext_INT_Types INTId,Ext_ISC_Types mode){
	switch(INTId){
		case Ext_INT0:
		//each gray bits you must get away from it  OR as you like
		MCUCR_Reg |= (mode<<0);
		break;
		case Ext_INT1:
		MCUCR_Reg |= (mode<<2);
		break;
		case Ext_INT2:
		if (mode == Falling_Edge)
		{
			ClearBit(MCUCSR_Reg,MCUCSR_INT2_ISC2_Bit);
		}
		else if(mode == Rising_Edge){
			SetBit(MCUCSR_Reg,MCUCSR_INT2_ISC2_Bit);
		}
		else{
			
		}
		break;
	}
}