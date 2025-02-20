#include "infrared.h"


u8 g_infrared_data[4];


void infrared_init() {
    IT0 = 1;
    EX0 = 1;
    EA = 1;
    INFRARED_PORT = 1;
}

void infrared() interrupt 0 {
    u16 time_out = 0;
    u8 i = 0;
    u8 j = 0;
    u8 high_v = 0;

    if (INFRARED_PORT == 0) {
        time_out = 500;
        while ((!INFRARED_PORT) && (time_out)) {
            delay_10us(1);
            time_out --;
            if (time_out == 0) {
                return;
            }
        }

        if (INFRARED_PORT == 1) {
            time_out = 250;
            while (INFRARED_PORT && time_out) {
                delay_10us(1);
                time_out --;
                if (time_out == 0) {
                    return;
                }
            }

            for (i = 0 ; i < 8 ; i++) {
                for (j = 0 ; j < 8 ; j++) {
                    time_out = 30;
                    while (time_out && !INFRARED_PORT) {
                        delay_10us(1);
                        time_out --;
                        if (time_out == 0) {
                            return;
                        }
                    }

                    time_out = 20;
                    while (INFRARED_PORT && time_out) {
                        delay_10us(10);
                        time_out --;
                        high_v ++;
                        if (high_v >= 20) {
                            return;
                        }
                    }

                    g_infrared_data[i] >>= 1;

                    if (high_v >= 8) {
                        g_infrared_data[i] |= 0x80;
                        high_v = 0;
                    }
                }
            }
        }

        if (g_infrared_data[2] != ~ g_infrared_data[3]) {
            for (i = 0 ; i < 4 ; i++) {
                g_infrared_data[i] = 0x00;
            }
            return;
        }
    }
}
