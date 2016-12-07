
#ifndef MACRO_H
#define MACRO_H

//port
#define PORT(x)  XPORT(x)
#define XPORT(x) (PORT##x)

//pin
#define PIN(x)  XPIN(x)
#define XPIN(x) (PIN##x)

//ddr
#define DDR(x)  XDDR(x)
#define XDDR(x) (DDR##x)

#define NOP() {asm volatile("nop"::);}

#endif //MACRO_H
