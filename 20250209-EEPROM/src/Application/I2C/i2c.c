#include "i2c.h"

void i2c_start() {
    i2c_SCL = 1;
    i2c_SDA = 1;
    delay(1);
    i2c_SDA = 0;
    delay(1);
    i2c_SCL = 0;
}

void i2c_stop() {
    i2c_SCL = 1;
    i2c_SDA = 0;
    delay(1);
    i2c_SDA = 1;
    delay(1);
    i2c_SCL = 1;
}

void i2c_acknowledge() {
    i2c_SCL = 0;
    i2c_SDA = 0;
    delay(1);
    i2c_SCL = 1;
    delay(1);
    i2c_SCL = 0;
}

void i2c_no_acknowledge() {
    i2c_SCL = 0;
    i2c_SDA = 1;
    delay(1);
    i2c_SCL = 1;
    delay(1);
    i2c_SCL = 0;
}

u8 i2c_wait_acknowledge() {
    u8 time_temp = 0;

    i2c_SCL = 1;
    delay(1);
    
    while (i2c_SDA) {
        time_temp ++;
        if (time_temp > 100) {
            i2c_stop();
            return 1;
        }
    }

    i2c_SCL = 0;
    return 0;
}


void i2c_write_data(u8 data_sent) {
    u8 i = 0;

    i2c_SCL = 0;
    for (i = 0 ; i < 8 ; i++) {
        if ((data_sent & 0x80) > 0) {
            i2c_SDA = 1;
        }
        else {
            i2c_SDA = 0;
        }

        data_sent <<= 1;
        i2c_SCL = 1;
        delay(1);
        i2c_SCL = 0;
        delay(1);
    }
}

u8 i2c_read_data(u8 ack) {
    u8 i = 0;

    u8 received = 0;
    for (i = 0 ; i < 8 ; i++) {
        i2c_SCL = 0;
        delay(1);
        i2c_SCL = 1;
        delay(1);

        received <<= 1;

        if (i2c_SDA) {
            received ++;
        }
    }

    if (!ack) {
        i2c_no_acknowledge();
    }
    else {
        i2c_acknowledge();
    }

    return received;
}
