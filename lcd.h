
#ifndef LCD_H
#define LCD_H

// LCD defines
#define LCDMaxLines 2
#define LCDMaxChars 16
#define LineOne     0x80
#define LineTwo     0xc0
#define BlankSpace  ' '

#include "macros.h"
#include "harddef.h"

void commandLCD(uint8_t command)
{
	PORT(LCD_RSPORT) &= ~(1 << LCD_RS);
	PORT(LCD_DPORT)   =  command;
	_delay_ms(1);
	PORT(LCD_EPORT)  |=  (1 << LCD_E);
	_delay_ms(1);
	PORT(LCD_EPORT)  &= ~(1 << LCD_E);
}

void initLCD(void)
{
	commandLCD(0x38);   // LCD 2lines, 5*7 matrix
	commandLCD(0x0E);	// Display ON cursor ON
	commandLCD(0x01);	// Clear the LCD
	commandLCD(0x80);	// Move the Cursor to First line First Position
}

void writeLCD(uint8_t data)
{
	PORT(LCD_RSPORT) |=  (1 << LCD_RS);
	PORT(LCD_DPORT)   =  data;
	_delay_ms(1);
	PORT(LCD_EPORT)  |=  (1 << LCD_E);
	_delay_ms(1);
	PORT(LCD_EPORT)  &= ~(1 << LCD_E);
}

void clearLCD()
{
	commandLCD(0x01);
	commandLCD(LineOne);
}

void goToLineOneLCD()
{
	commandLCD(LineOne);
}

void goToLineTwoLCD()
{
	commandLCD(LineTwo);
}

void writeStringLCD(const char* string)
{
	int n = 0;
	while(string[n] != 0)
	{
		writeLCD(string[n]);
		++n;
	}
}

void writeDecLCD(int dec)
{
	char buffer[7];
	writeStringLCD(itoa(dec, buffer, 10));
}
#endif //LCD_H
