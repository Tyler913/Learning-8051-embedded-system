#ifndef _at24c02_H
#define _at24c02_H

#include "public.h"
#include "i2c.h"


void at24c02_write_byte(u8 data_sent, u8 address);

u8 at24c02_read_byte(address);

#endif
