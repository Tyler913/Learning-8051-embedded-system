#include "at24c02.h"

void at24c02_write_byte(u8 data_sent, u8 address) {
    i2c_start();
    i2c_write_data(0xA0);
    i2c_wait_acknowledge();
    i2c_write_data(address);
    i2c_wait_acknowledge();
    i2c_write_data(data_sent);
    i2c_wait_acknowledge();
    i2c_stop();
    delay_10us(1000);
}

u8 at24c02_read_byte(address) {
    u8 temp = 0;

    i2c_start();
    i2c_write_data(0xA0);
    i2c_wait_acknowledge();
    i2c_write_data(address);
    i2c_wait_acknowledge();
    i2c_start();
    i2c_write_data(0xA1);
    i2c_wait_acknowledge();
    temp = i2c_read_data(0);
    i2c_stop();

    return temp;
}
