#include "reg52.h"

sbit LED1 = P2^0;

void delay(int time) {
	while (time--);
}

void main() {
	while (1) {
		LED1 = 1;
		delay(500000);
		LED1 = 0;
		delay(500000);
	}
}
