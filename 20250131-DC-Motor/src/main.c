#include "REG52.H"


typedef unsigned char u8;
typedef unsigned int u16;


sbit DC_Motor = P1 ^ 0;


void delay(u16 time) {
    while (time--);
}


void main() {

    DC_Motor = 1;

    while (1)
    {
        DC_Motor = 1;
        delay(5000000);
        DC_Motor = 0;
        delay(5000000);
    }
    
}
