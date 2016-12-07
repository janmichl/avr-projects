
#ifndef PWM_H
#define PWM_H

void initPWM()
{
    DDR(PWM_DPORT) |= (1 << PD4)    | (1 << PD5)    | (1 << PD7);
    TCCR2          |= (1 << CS00)   | (1 << WGM00)  | (1 << WGM01)  | (1 << COM01)  | (1 << COM00); 
	TCCR1A         |= (1 << COM1A0) | (1 << COM1A1) | (1 << COM1B0) | (1 << COM1B1) | (1 << WGM10);
	TCCR1B         |= (1 << CS10);
	
    OCR1A = 255;
	OCR1B = 128;
	OCR2  = 0;
}

void runPWM()
{
	while(1)
    {
		OCR1A = ((OCR1A + 1) & 0x00FF);
		OCR1B = ((OCR1B + 1) & 0x00FF);
		OCR2++;
		_delay_ms(100);
	}
}

#endif //PWM_H
