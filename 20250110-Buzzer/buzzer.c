#include "reg52.h"


typedef unsigned char u8;
typedef unsigned int u16;


sbit buzzer_pin = P2^5;


void delay(u16 number) {
	while (number--);
}


void main() {
	
	u16 i = 2000;
	
	while(1) {
		
		while (i--) {
			// buzzer_pin = !buzzer_pin;
			// delay(10);
			buzzer_pin = 0;
			delay(1);
			buzzer_pin = 1;
			delay(100);
		}
		
		i = 0;
		buzzer_pin = 0;
	}
}
