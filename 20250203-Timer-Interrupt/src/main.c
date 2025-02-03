#include "REG52.H"


typedef unsigned char u8;
typedef unsigned int u16;


sbit led = P2 ^ 0;


void init_timer0() {
    TMOD |= 0x01;
    TH0 = 0xFC;
    TL0 = 0x66;
    ET0 = 1;
    EA = 1;
    TR0 = 1;
}


void timer0_interrupt() interrupt 1 {
    static u16 total_time = 0;

    TH0 = 0xFC;
    TL0 = 0x66;

    total_time += 1;

    if (total_time == 1000) {
        led = !led;
        total_time = 0;
    }
}


void main() {

    init_timer0();

    while (1)
    {
        /* code */

    }
    
}
