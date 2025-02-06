#include "REG52.H"


typedef unsigned char u8;
typedef unsigned int u16;


void uart_init(u8 baud_rate) {
    TMOD |= 0x20;
    SCON = 0x50;
    PCON = 0x80;
    TH1 = baud_rate;
    TL1 = baud_rate;
    ES = 1;
    EA = 1;
    TR1 = 1;
}


void uart_interrupt() interrupt 4 {
    u8 data_received = 0;

    RI = 0;
    data_received = SBUF;

    SBUF = data_received;
    while (!TI);
    TI = 0;
    
}


void main() {

    uart_init(0xFA);

    while (1)
    {
        
    }
    
}
