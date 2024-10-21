#include "reg52.h"

typedef unsigned char u8;
typedef unsigned int u16;

#define LED_PORT	P2

void main() {
	
	u8 i = 0;
	
	while (1) {
		for (i - 0 ; i < 8 ; ++i) {
			LED_POART = ~(0x1= << i);
		}
	}
}
