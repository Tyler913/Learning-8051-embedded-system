#include "digital_tube.h"
#include "xpt2046.h"
#include "public.h"


void main(void) {

    u16 adc_value = 0;
    float adc_voltage = 0;
    u8 adc_buffer[3];

    while (1) {
        adc_value = XPT2046_read_adc_value(0x94);
        adc_voltage = 5.0 * adc_value / 4096;
        adc_value = adc_voltage * 10;

        adc_buffer[0] = gsmg_code[adc_value / 10] | 0x80;
        adc_buffer[1] = gsmg_code[adc_value % 10];
        adc_buffer[2] = 0x3e;
        smg_display(adc_buffer, 6);
    }
}
