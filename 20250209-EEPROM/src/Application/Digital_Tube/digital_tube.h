#ifndef _digital_tube_H
#define _digital_tube_H

#include "public.h"


#define SMG_A_DP_PORT	P0

sbit LSA=P2^2;
sbit LSB=P2^3;
sbit LSC=P2^4;

void smg_display(u8 data_input[], u8 position);

#endif
