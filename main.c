
#define F_CPU 1000000UL

#include <util/delay.h>
#include <avr/io.h>
#include <inttypes.h>
#include <avr/pgmspace.h>
#include <stdlib.h>

#include "macros.h"
#include "harddef.h"
#include "lcd.h"

#define BAUDRATE(clockFreq, baud) ((uint16_t)(clockFreq/(16L*(baud))-1))

void initUART()
{
   // baudrate
   uint16_t baud = BAUDRATE(F_CPU, 9600);
   UBRRH = (uint8_t)(baud >> 8);
   UBRRL = (uint8_t)(baud);
   // no parity, 1 stopbit, charsize 8
   UCSRC |= (1 << URSEL) | (3 << UCSZ0);
   // enable receiver and transmitter
   UCSRB |= (1 << RXEN) | (1 << TXEN);
}

void initPWM()
{
    DDR(PWM_DPORT) |= (1<<PD4)|(1<<PD5)|(1<<PD7);
    TCCR2          |= (1<<CS00)|(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<COM00); 
	TCCR1A         |= (1<<COM1A0)|(1<<COM1A1)|(1<<COM1B0)|(1<<COM1B1)|(1<<WGM10);
	TCCR1B         |= (1<<CS10);
	
    OCR1A=255;
	OCR1B=128;
	OCR2 =0;
}


//main
int main(void)
{
    initPWM();

	while(1){
		OCR1A=((OCR1A+1)&0x00FF);
		OCR1B=((OCR1B+1)&0x00FF);
		OCR2++;
		_delay_ms(100);
	}

	return(0);
}
