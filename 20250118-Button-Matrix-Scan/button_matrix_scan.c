#include "reg52.h"


typedef unsigned char u8;
typedef unsigned int u16;


#define DIGITAL_TUBE_PORT P0
u8 g_digital_tube_code[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71};

#define MATRIX_KEY_PORT P1


void delay(u16 number) {
	while (number--);
}


u8 matrix_key_scan() {
	u8 key_value = 0;
	MATRIX_KEY_PORT = 0xf7;
	// unsigned char key_value = 0;
	
	if (MATRIX_KEY_PORT != 0xf7) {
		delay(5000);
		
		switch(MATRIX_KEY_PORT) {
			case 0x77:
				key_value = 1;
				break;
			
			case 0xb7:
				key_value = 5;
				break;
			
			case 0xd7:
				key_value = 9;
				break;
			
			case 0xe7:
				key_value = 13;
				break;
		}
	}
	
	while (MATRIX_KEY_PORT != 0xf7);
	
	MATRIX_KEY_PORT = 0xfb;
	//u8 key_value = 0;
	
	if (MATRIX_KEY_PORT != 0xfb) {
		delay(5000);
		
		switch(MATRIX_KEY_PORT) {
			case 0x7b:
				key_value = 2;
				break;
			
			case 0xbb:
				key_value = 6;
				break;
			
			case 0xdb:
				key_value = 10;
				break;
			
			case 0xeb:
				key_value = 14;
				break;
		}
	}
	
	while (MATRIX_KEY_PORT != 0xfb);
	
	MATRIX_KEY_PORT = 0xfd;
	// u8 key_value = 0;
	
	if (MATRIX_KEY_PORT != 0xfd) {
		delay(5000);
		
		switch(MATRIX_KEY_PORT) {
			case 0x7d:
				key_value = 3;
				break;
			
			case 0xbd:
				key_value = 7;
				break;
			
			case 0xdd:
				key_value = 11;
				break;
			
			case 0xed:
				key_value = 15;
				break;
		}
	}
	
	while (MATRIX_KEY_PORT != 0xfd);
	
	MATRIX_KEY_PORT = 0xfe;
	// u8 key_value = 0;
	
	if (MATRIX_KEY_PORT != 0xfe) {
		delay(5000);
		
		switch(MATRIX_KEY_PORT) {
			case 0x7e:
				key_value = 4;
				break;
			
			case 0xbe:
				key_value = 8;
				break;
			
			case 0xde:
				key_value = 12;
				break;
			
			case 0xee:
				key_value = 16;
				break;
		}
	}
	
	while (MATRIX_KEY_PORT != 0xfe);
	
	return key_value;
}


void main() {
	
	u8 key_value_returned = 0;
	
	while (1) {
		key_value_returned = matrix_key_scan();
		
		DIGITAL_TUBE_PORT = g_digital_tube_code[key_value_returned - 1];
		delay(10000);
	}
}
