#include "DS1302.h"
#include "INTRINS.H"

void DS1302_write_byte(u8 address, u8 data_sent) {
    u8 i = 0;
    u8 temp = 0;

    DS1302_RST = 0;
    _nop_();
    DS1302_CLK = 0;
    _nop_();
    DS1302_RST = 1;
    _nop_();

    for (i = 0 ; i < 8 ; i++) {
        DS1302_IO = address & 0x01;
        address >>= 1;
        DS1302_CLK = 1;
        _nop_();
        DS1302_CLK = 0;
        _nop_();
    }

    for (i = 0 ; i < 8 ; i++) {
        DS1302_IO = data_sent & 0x01;
        data_sent >>= 1;
        DS1302_CLK = 1;
        _nop_();
        DS1302_CLK = 0;
        _nop_();
    }

    DS1302_RST = 0;
    _nop_();
}
