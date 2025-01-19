#include "reg52.h"


typedef unsigned char u8;
typedef unsigned int u16;


#define DIGITAL_TUBE_PORT P0
u8 g_digital_tube_code[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

#define MATRIX_KEY_PORT P1


void delay(u16 number) {
	while (number--);
}


u8 matrix_key_scan_reserved() {
	static u8 key_value = 0;
	
	MATRIX_KEY_PORT = 0x0f;
	
	if (MATRIX_KEY_PORT != 0x0f) {
		delay(1000);
		
		if (MATRIX_KEY_PORT != 0x0f) {
			switch (MATRIX_KEY_PORT) {
				case 0x07:
					key_value = 1;
					break;
				
				case 0x0b:
					key_value = 2;
					break;
				
				case 0x0d:
					key_value = 3;
					break;
				
				case 0x0e:
					key_value = 4; 
					break;
			}
			
			MATRIX_KEY_PORT = 0xf0;
			switch (MATRIX_KEY_PORT) {
				case 0x70:
					key_value += 0;
					break;
				
				case 0xb0:
					key_value += 4;
					break;
				
				case 0xd0:
					key_value += 8;
					break;
				
				case 0xe0:
					key_value += 12;
					break;
			}
			
			while (MATRIX_KEY_PORT != 0xf0);
		}
	}
	else {
		key_value = 0;
	}
	
	return key_value;
}


void main() {
	
	u8 key_value_returned = 0;
	
	while (1) {
		key_value_returned = matrix_key_scan_reserved();
		
		DIGITAL_TUBE_PORT = g_digital_tube_code[key_value_returned - 1];
		delay(10000);
	}
}
