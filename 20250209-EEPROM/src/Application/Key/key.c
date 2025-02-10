#include "key.h"


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
