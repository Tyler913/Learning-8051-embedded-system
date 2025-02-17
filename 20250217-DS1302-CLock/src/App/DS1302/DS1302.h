#ifndef _DS1302_H
#define _DS1302_H

#include "public.h"

sbit DS1302_RST = P3 ^ 5;
sbit DS1302_CLK = P3 ^ 6;
sbit DS1302_IO = P3 ^ 4;

#endif
