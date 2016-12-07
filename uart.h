
#ifndef UART_H
#define UART_H

#define BAUDRATE(clockFreq, baud) ((uint16_t)(clockFreq/(16L*(baud))-1))

void initUART()
{
   // baudrate
   uint16_t baud = BAUDRATE(F_CPU, 9600);
   UBRRH = (uint8_t)(baud >> 8);
   UBRRL = (uint8_t)(baud);
   // no parity, 1 stopbit, charsize 8
   UCSRC |= (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
   // enable receiver and transmitter
   UCSRB |= (1 << RXEN) | (1 << TXEN);
}

void sendByteUART(uint8_t data)
{
    while(!(UCSRA & (1 << UDRE)))
    {
    }
    
    UDR = data;
}

uint8_t receiveByteUART()
{
    while(!(UCSRA & (1 << RXC)))
    {
    }

    return(UDR);
}


#endif //UART_H
