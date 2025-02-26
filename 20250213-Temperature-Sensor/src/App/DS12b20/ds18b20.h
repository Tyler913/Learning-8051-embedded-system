// #ifndef _ds18b20_H
// #define _ds18b20_H

// #include "public.h"

// sbit DS18B20_PORT = P3 ^ 7;


// void ds18b20_reset();

// u8 ds18b20_check();

// u8 ds18b20_init();

// void ds18b20_write_data(u8 data_input);

// u8 ds18b20_read_data_one_bit();

// u8 ds18b20_read_data_one_byte();

// void ds18b20_start();

// float ds18b20_read_temperature();



// #endif


#ifndef _ds18b20_H
#define _ds18b20_H

#include "public.h"

//管脚定义
sbit DS18B20_PORT=P3^7;	//DS18B20数据口定义


//函数声明
u8 ds18b20_init(void);
float ds18b20_read_temperture(void);

#endif