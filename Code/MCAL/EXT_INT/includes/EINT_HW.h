/*
 * EINT_HW.h
 *
 * Created: 10/7/2022 9:05:46 PM
 *  Author: user
 */ 


#ifndef EINT_HW_H_
#define EINT_HW_H_

#include "STD_Types.h"

#define GICR_Reg (*(volatile Uint8 *)0x5B)
#define GIFR_Reg (*(volatile Uint8 *)0x5A)
#define MCUCR_Reg (*(volatile Uint8 *)0x55)
#define MCUCSR_Reg (*(volatile Uint8 *)0x54)

#endif /* EINT_HW_H_ */