#include "public.h"
#include "digital_tube.h"
#include "infrared.h"


void main() {
    u8 infrared_buffer[3];

        infrared_init();

    while (1) {
        infrared_buffer[0] =gsmg_code[g_infrared_data[2] / 16];
        infrared_buffer[1] =gsmg_code[g_infrared_data[2] % 16];
        infrared_buffer[2] =gsmg_code[0x76];

        smg_display(infrared_buffer, 6);
    }
}
