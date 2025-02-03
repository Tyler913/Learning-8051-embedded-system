#include "REG52.H"


typedef unsigned char u8;
typedef unsigned int u16;


sbit key3 = P3^2;
sbit led1 = P2^0;


void delay(u16 time) {
    while (time--);
}


void init_external_interrupt() {
    EA = 1;
    EX0 = 1;
    IT0 = 1;
}


void external_interrupt() interrupt 0 {
    delay(1000);

    if (key3 == 0) {
        led1 = !led1;
    }
}


void main() {

    init_external_interrupt();

    while (1)
    {
    
    }
    
}
