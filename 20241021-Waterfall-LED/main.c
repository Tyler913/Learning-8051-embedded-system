#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

#define LED_PORT	P2

void delay_10us(u16 time) {
	while (time--);
}

void main() {
	
	u8 i = 0;
	
	while (1) {
		
		for (i = 0 ; i < 8 ; ++i) {
			LED_PORT = ~(0x1 << i);
			delay_10us(50000);
		}
		
		for (i = 6 ; i >= 0 ; --i) {
			LED_PORT = ~(0x1 << i);
			delay_10us(50000);
		}
	}
}
