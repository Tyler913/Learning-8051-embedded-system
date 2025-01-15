#include "reg52.h"


typedef unsigned char u8;
typedef unsigned int u16;


#define DIGITAL_TUBE_A_DP_PORT P0


u8 g_digital_tube_num[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x8f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};


void delay(u16 number) {
	while(number--);
}


void main() {
	
	DIGITAL_TUBE_A_DP_PORT = g_digital_tube_num[1];
	
	while (1) {
		
	}
}
