#ifndef _i2c_H
#define _i2c_H

#include "public.h"


sbit i2c_SCL = P2 ^ 1;
sbit i2c_SDA = P2 ^ 0;


void i2c_start(void);

void i2c_stop(void);

void i2c_acknowledge(void);

void i2c_no_acknowledge(void);

u8 i2c_wait_acknowledge(void);

void i2c_write_data(u8 data_sent);

u8 i2c_read_data(u8 ack);

#endif
