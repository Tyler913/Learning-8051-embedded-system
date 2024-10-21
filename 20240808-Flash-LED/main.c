#include "reg52.h"

#define LED_PORT	P2


void delay(int time) {
	while (time--);
}


int main() {
	
	
	
	while (1) {
		char i = 0;
		for (; i < 8 ; i++) {
			LED_PORT = ~(0x1<<i);
			delay(50000);
		}
	}
}
