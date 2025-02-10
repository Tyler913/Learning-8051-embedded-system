#include "public.h"
#include "key.h"
#include "digital_tube.h"
#include "at24c02.h"


#define EEPROM_ADDRESS 0


void main() {

    u8 key_temp = 1;
    u8 save_data = 0;
    u8 save_buf[3];

    while (1)
    {
        key_temp = key_scan(0);

        if (key_temp == DEFAULT_KEY1) {
            at24c02_write_byte(EEPROM_ADDRESS, save_data);
        }
        else if (key_temp == DEFAULT_KEY2) {
            save_data = at24c02_read_byte(EEPROM_ADDRESS);
        }
        else if (key_temp == DEFAULT_KEY3) {
            if (save_data == 255) {
                save_data = 255;
            }
            else {
                save_data ++;
            }
        }
        else if (key_temp == DEFAULT_KEY4) {
            save_data = 0;
        }

        save_buf[0] = save_data / 100;
        save_buf[1] = save_data % 100 / 10;
        save_buf[2] = save_data % 100 % 10;

        smg_display(save_buf, 6);
    }
    
}
