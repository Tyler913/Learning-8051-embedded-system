#include "reg52.h"


typedef unsigned char u8;
typedef unsigned int u16;


sbit SRCLK = P3^6;
sbit rCLK = P3^5;
sbit SER = P3^4;


#define LED_MATRIX_COLUMB_PORT P0


u8 g_led_row[] = {0x00, 0x7c, 0x82, 0x82, 0x82, 0x7c, 0x00, 0x00};
u8 g_led_column[] = {0x7f, 0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe};


void delay(u16 time) {
	while (time--);
}


void chip_74hc595_send_data(u8 input) {
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
	
	while (1) {
		for (i = 0 ; i < 8 ; i++) {
			LED_MATRIX_COLUMB_PORT = g_led_column[i];
			chip_74hc595_send_data(g_led_row[i]);
			delay(10000);
			chip_74hc595_send_data(0x00);
		}
	}
}
