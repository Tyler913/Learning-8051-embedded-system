#include "public.h"
#include "Digital_Tube/digital_tube.h"
#include "DS1302/DS1302.h"

void main() {
    u8 time_buffer[8];

    DS1302_set_initial_time();
    while (1) {
        time_buffer[0] = gsmg_code[g_DS1302_TIME[2] / 16];
        time_buffer[1] = gsmg_code[g_DS1302_TIME[2] % 16];
        time_buffer[2] = 0x40;
        time_buffer[3] = gsmg_code[g_DS1302_TIME[1] / 16];
        time_buffer[4] = gsmg_code[g_DS1302_TIME[1] % 16];
        time_buffer[5] = 0x40;
        time_buffer[6] = gsmg_code[g_DS1302_TIME[0] / 16];
        time_buffer[7] = gsmg_code[g_DS1302_TIME[0] % 16];

        smg_display(time_buffer, 1);
    }
}
