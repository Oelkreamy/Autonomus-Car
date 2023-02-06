/*
 * EINT.h
 *
 * Created: 10/7/2022 9:06:00 PM
 *  Author: user
 */ 


#ifndef EINT_H_
#define EINT_H_

#include "BitMath.h"
#include "EINT_HW.h"
#include "EINT_Types.h"

void Ext_INT_Enable(Ext_INT_Types INTId);
void Ext_INT_Disable(Ext_INT_Types INTId);
void Ext_INT_Sncontrol(Ext_INT_Types INTId,Ext_ISC_Types mode);


#endif /* EINT_H_ */