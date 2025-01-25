#include "reg52.h"


typedef unsigned char u8;
typedef unsigned int u16;


sbit SRCLK = P3^6;
sbit rCLK = P3^5;
sbit SER = P3^4;


#define LED_MATRIX_COLUMN_PORT P0


void delay(u16 number) {
	while (number--);
}


void chip_74hc595_send_data(u8 input) {
	u8 i = 0;
	
	for (i = 0 ; i < 8 ; i++) {
		SER = input >> 7;
		input = input << 1;
		
		SRCLK = 0;
		delay(0);
		SRCLK = 1;
		delay(1);
	}
	
	rCLK = 0;
	delay(1);
	rCLK = 1;
	delay(1);
}


void main() {
	
	LED_MATRIX_COLUMN_PORT = 0x7f;
	
	while (1) {
		chip_74hc595_send_data(0x80);
	}
}
