#ifndef XPT2046_H
#define XPT2046_H

#include "public.h"


sbit DOUT = P3^7;
sbit CLK = P3^6;
sbit DIN = P3^4;
sbit CS = P3^5;


void XPT2046_write_bit(u8 dat);

u16 XPT2046_read_bit(void);

u16 XPT2046_read_adc_value(u8 cmd);

#endif
