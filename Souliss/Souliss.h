/**************************************************************************
	Souliss
    Copyright (C) 2013  Veseo

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
	
	Originally developed by Dario Di Maio
	
***************************************************************************/
/*!
    \file 
    \ingroup
*/
#ifndef SOULISSSKETCHMODE_H
#define SOULISSSKETCHMODE_H

/*************************************/
/*!	
	All code is compiled into the sketch, without creating middle
	object files. This let use #define that are globally recognized
	in the whole code, including sub-libraries.
*/

#include <Arduino.h>
#include "src/types.h"
#include "GetConfig.h"			// need : ethUsrCfg.h, vNetCfg.h, SoulissCfg.h, MaCacoCfg.h

#include "frame/MaCaco/MaCaco.h"
#include "frame/vNet/vNet.h"

#if(HTTPSERVER && VNET_MEDIA1_ENABLE && (ETH_W5100 || ETH_W5200))
#	include "gateway/HTTP.h"
#elif(HTTPSERVER && VNET_MEDIA1_ENABLE && ETH_ENC28J60)
#	include "gateway/HTTP_uIP.h"
#endif

// Include IO definitions and drivers for supported hardware
#include "hardware/IOdef.h"
#include "src/IEEE754/float16.h"
#include "sensors/sensors.h"

#include "base/SoulissBase.h"

#include "frame/MaCaco/MaCaco.cpp"
#include "frame/vNet/vNet.cpp"

#if(HTTPSERVER && VNET_MEDIA1_ENABLE && (ETH_W5100 || ETH_W5200))
	#include "gateway/HTTP.cpp"
#elif(HTTPSERVER && VNET_MEDIA1_ENABLE && ETH_ENC28J60)
	#include "gateway/HTTP_uIP.cpp"
#endif
	
// Include IO definitions and drivers for supported hardware
#include "hardware/IOdef.cpp"

// Include methods for half-precision floating points
#include "src/IEEE754/float16.c"

// Include drivers for supported sensors
#include "sensors/sensors.cpp"

// Include Souliss code base and typicals
#include "base/SoulissBase.cpp"
#include "base/T1n.cpp"
#include "base/T2n.cpp"
#include "base/T3n.cpp"
#include "base/T4n.cpp"
#include "base/T5n.cpp"

#endif