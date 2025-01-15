#include "reg52.h"


typedef unsigned char u8;
typedef unsigned int u16;


#define DIGITAL_TUBE_A_DP_PORT P0
sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;


u8 g_digital_tube_number[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x8f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};


void delay(u16 number) {
	while (number--);
}


void digital_tube_display(void) {
	u8 i = 0;
	for (i = 7 ; i >= 0 ; i--) {
		switch (i) {
			case 0:
				LSC = 1;
				LSB = 1;
				LSA = 1;
				break;
			
			case 1:
				LSC = 1;
				LSB = 1;
				LSA = 0;
				break;
			
			case 2:
				LSC = 1;
				LSB = 0;
				LSA = 1;
				break;
			
			case 3:
				LSC = 1;
				LSB = 0;
				LSA = 0;
				break;
			
			case 4:
				LSC = 0;
				LSB = 1;
				LSA = 1;
				break;
			
			case 5:
				LSC = 0;
				LSB = 1;
				LSA = 0;
				break;
			
			case 6:
				LSC = 0;
				LSB = 0;
				LSA = 1;
				break;
			
			case 7:
				LSC = 0;
				LSB = 0;
				LSA = 0;
				break;
				
		}
		
		DIGITAL_TUBE_A_DP_PORT = g_digital_tube_number[7 - i];
		delay(100);
		DIGITAL_TUBE_A_DP_PORT = 0x00;
	}
}


void main() {
	digital_tube_display();

}
