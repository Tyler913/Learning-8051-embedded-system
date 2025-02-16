// #ifndef _public_H
// #define _public_H

// #include "REG52.H"

// typedef unsigned char u8;
// typedef unsigned int u16;

// void delay(u16 times);

// #endif


#ifndef _public_H
#define _public_H

#include "reg52.h"

typedef unsigned int u16;	//��ϵͳĬ���������ͽ����ض���
typedef unsigned char u8;


void delay_10us(u16 ten_us);
void delay_ms(u16 ms);

#endif
