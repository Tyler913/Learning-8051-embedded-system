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


#define SMG_A_DP_PORT	P0	//ʹ�ú궨������ܶ����

//���������λѡ�źſ��ƽ�
sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

extern u8 gsmg_code[17];

void smg_display(u8 dat[],u8 pos);

#endif