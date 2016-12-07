
#define F_CPU 1000000UL

// system includes - must go first
#include <util/delay.h>
#include <avr/io.h>
#include <inttypes.h>
#include <avr/pgmspace.h>
#include <stdlib.h>

// local includes
#include "macros.h"
#include "harddef.h"
#include "lcd.h"
#include "pwm.h"
#include "uart.h"

// main
int main(void)
{
    initPWM();
    runPWM();

	return(0);
}
