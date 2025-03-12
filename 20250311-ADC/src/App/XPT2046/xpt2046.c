#include "xpt2046.h"
#include "intrins.h"


void XPT2046_write_bit(u8 dat) {
    u8 i = 0;

    CLK = 0;
    _nop_();
    
    for (i = 0; i < 8; i++) {
        DIN = dat >> 7;
        CLK = 1;
        _nop_();
        CLK = 0;
        _nop_();

        dat <<= 1;
    }
}

u16 XPT2046_read_bit(void) {
    u8 i = 0;
    u16 dat = 0;

    CLK = 0;
    _nop_();

    for (i = 0; i < 12; i++) {
        CLK = 1;
        _nop_();
        CLK = 0;
        _nop_();

        dat |= DOUT;
        dat <<= 1;
    }

    return dat;
}

u16 XPT2046_read_adc_value(u8 cmd) {
    u16 adc_value = 0;

    CS = 0;
    CLK = 0;

    XPT2046_write_bit(cmd);

    CLK = 0;
    _nop_();
    CLK = 1;
    _nop_();

    adc_value = XPT2046_read_bit();

    CS = 1;

    return adc_value;
}
