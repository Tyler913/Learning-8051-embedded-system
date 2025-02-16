// #ifndef _digital_tube_H
// #define _digital_tube_H

// #include "public.h"

// #define SMG_A_DP_PORT   P0

// sbit LSA = P2^2;
// sbit LSB = P2^3;
// sbit LSC = P2^4;

// void smg_display(u8 data_input[], u8 position);

// extern u8 gsmg_code[17];

// #endif


#ifndef _smg_H
#define _smg_H

#include "public.h"


#define SMG_A_DP_PORT	P0	//使用宏定义数码管段码口

//定义数码管位选信号控制脚
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

extern u8 gsmg_code[17];

void smg_display(u8 dat[],u8 pos);

#endif