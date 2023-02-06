/*
 * DIO.h
 *
 * Created: 9/24/2022 8:22:26 PM
 *  Author: user
 */ 


#ifndef DIO_H_
#define DIO_H_
#include "clock.h"
#include "BitMath.h"
#include "STD_Types.h"
#include "DIO_HW.h"
#include "DIO_Types.h"
#include "DIO_CFG.h"

void DIO_WriteChannel(DIO_ChannelTypes ChannelId,STD_LevelTypes Level);
STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes ChannelId);
Uint8 DIO_ReadPort(DIO_PortTypes PortId);
void DIO_WritePort(DIO_PortTypes PortId,Uint8 PortValue);
void DIO_ToggleChannel(DIO_ChannelTypes ChannelId);
#endif /* DIO_H_ */