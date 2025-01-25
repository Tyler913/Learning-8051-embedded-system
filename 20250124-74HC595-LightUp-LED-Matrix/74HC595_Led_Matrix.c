#include "reg52.h"


typedef unsigned char u8;
typedef unsigned int u16;


sbit SRCLK = P3^6;
sbit rCLK = P3^5;
sbit SER = P3^4;

#define COLUMN_LED_MATRIX_PORT P0

u8 g_hc595_send_buffer[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};


void delay(u16 number) {
	while (--number);
}


void hc595_write_data(u8 input) {
	u8 i = 0;
	
	for (i = 0 ; i < 8 ; i++) {
		SER = input >> 7;
		input = input << 1;
		SRCLK = 0;
		delay(1);
		SRCLK = 1;
		delay(1);
	}
	
	rCLK = 0;
	delay(1); 
	rCLK = 1;
	delay(1);
}


void main() {
	
	u8 i = 0;
	
	COLUMN_LED_MATRIX_PORT = 0x00;
	
	while (1) {
		for (i = 0 ; i < 8 ; i++) {
			hc595_write_data(0x00);
			hc595_write_data(g_hc595_send_buffer[i]);
			delay(10000);
		}
	}
}
