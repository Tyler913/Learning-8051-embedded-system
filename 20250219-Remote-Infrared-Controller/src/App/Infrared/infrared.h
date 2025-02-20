#ifndef _infrared_H
#define _infrared_H

#include "public.h"


extern u8 g_infrared_data[4];


sbit INFRARED_PORT = P3 ^ 2;


void infrared_init();

#endif
