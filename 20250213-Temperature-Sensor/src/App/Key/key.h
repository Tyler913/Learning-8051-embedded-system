#ifndef _key_H
#define _key_H

#include "public.h"


sbit KEY1 = P3 ^ 1;
sbit KEY2 = P3 ^ 0;
sbit KEY3 = P3 ^ 2;
sbit KEY4 = P3 ^ 3;

#define DEFAULT_KEY1 1
#define DEFAULT_KEY2 2
#define DEFAULT_KEY3 3
#define DEFAULT_KEY4 4
#define DEFAULT_KEY_UNPRESSED 0


unsigned char key_scan(u8 mode);

#endif
