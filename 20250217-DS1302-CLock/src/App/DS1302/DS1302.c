#include "DS1302.h"
#include "INTRINS.H"


// second, minute, hour, day, month, week, year
u8 g_WRITE_RTC_ADDRESS[7] = {0x80, 0x82, 0x84, 0x86, 0x88,0x8A, 0x8C};
u8 g_READ_RTC_ADDRESS[7] = {0x81, 0x83, 0x85, 0x87, 0x89,0x8B, 0x8D};
u8 g_DS1302_TIME[7] = {0x47, 0x51, 0x13, 0x03, 0x07, 0x06, 0x21};


void DS1302_write_byte(u8 addr, u8 data_sent) {
    u8 i = 0;

    DS1302_RST = 0;
    _nop_();
    DS1302_CLK = 0;
    _nop_();
    DS1302_RST = 1;
    _nop_();

    for (i = 0 ; i < 8 ; i++) {
        DS1302_IO = addr & 0x01;
        addr >>= 1;
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

u8 DS1302_read_byte(u8 addr) {
    u8 i = 0;
    u8 temp = 0;
    u8 value = 0;

    DS1302_RST = 0;
    _nop_();
    DS1302_CLK = 0; 
    _nop_();
    DS1302_RST = 1;
    _nop_();

    for (i = 0 ; i < 8 ; i++) {
        DS1302_IO = addr & 0x01;
        addr >>= 1;
        DS1302_CLK = 1;
        _nop_();
        DS1302_CLK = 0;
        _nop_();
    }

    for (i = 0 ; i < 8 ; i++) {
        temp = DS1302_IO;
        value >>= 1;
        value = (temp << 7) | (value >> 1);
        DS1302_CLK = 1;
        _nop_();
        DS1302_CLK = 0;
        _nop_();
    }

    DS1302_RST = 0;
    _nop_();
    DS1302_CLK = 1;
    _nop_();
    DS1302_IO = 0;
    _nop_();
    DS1302_IO = 1;
    _nop_();

    return value;
}

void DS1302_set_initial_time() {
    u8 i = 0;

    DS1302_write_byte(0x8e, 0x00);
    for (i = 0 ; i < 8 ; i++) {
        DS1302_write_byte(g_WRITE_RTC_ADDRESS[i], g_DS1302_TIME[i]);
    }

    DS1302_write_byte(0x8e, 0x80);
}

void DS1302_read_time() {
    u8 i = 0;

    for (i = 0 ; i < 8 ; i++) {
        g_DS1302_TIME[i] = DS1302_read_byte(g_READ_RTC_ADDRESS[i]);
    }
}
