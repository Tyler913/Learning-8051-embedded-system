#ifndef _DS1302_H
#define _DS1302_H

#include "public.h"

sbit DS1302_RST = P3 ^ 5;
sbit DS1302_CLK = P3 ^ 6;
sbit DS1302_IO = P3 ^ 4;


extern g_WRITE_RTC_ADDRESS[7];
extern g_READ_RTC_ADDRESS[7];
extern g_DS1302_TIME[7];


void DS1302_write_byte(u8 address, u8 data_sent);

u8 DS1302_read_byte(u8 address);

void DS1302_set_initial_time();

void DS1302_read_time();

#endif
