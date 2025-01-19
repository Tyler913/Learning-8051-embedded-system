#include "reg52.h"


typedef unsigned char u8;
typedef unsigned int u16;


sbit KEY1 = P3^1;
sbit KEY2 = P3^0;
sbit KEY3 = P3^2;
sbit KEY4 = P3^3;

sbit LED1 = P2^0;


#define DEFAULT_KEY1 1
#define DEFAULT_KEY2 2
#define DEFAULT_KEY3 3
#define DEFAULT_KEY4 4
#define DEFAULT_KEY_UNPRESSED 0


void delay(u16 number) {
	while (number--);
}


unsigned char key_scan(u8 mode) {
	
	static u8 key = 1;
	
	if (mode) {
		key = 1;
	}
	
	if (key == 1 && (KEY1 == 0 || KEY2 == 0 || KEY3 == 0 || KEY4 == 0)) {
		delay(10000);
		
		key = 0;
		
		if (KEY1 == 0) {
			return DEFAULT_KEY1;
		}
		else if (KEY2 == 0) {
			return DEFAULT_KEY2;
		}
		else if (KEY3 == 0) {
			return DEFAULT_KEY3;
		}
		else if (KEY4 == 0) {
			return DEFAULT_KEY4;
		}
	}
	else if (KEY1 == 0 && KEY2 == 0 && KEY3 == 0 && KEY4 == 0) {
		key = 1;
	}
	
	return DEFAULT_KEY_UNPRESSED;
}


void main() {
	
	u8 key = 0;
	
	while(1) {
		key = key_scan(1);
		
		if (key == DEFAULT_KEY1) {
			LED1 = !LED1;
		}
	}
}
