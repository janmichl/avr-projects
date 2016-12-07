
#ifndef HARDDEF_H
#define HARDDEF_H

//defines LCD
#define LCD_RS     0
#define LCD_RSPORT B
#define LCD_E      1
#define LCD_EPORT  B
#define LCD_DPORT  A
// other LCD defines
#define LCDMaxLines 2
#define LCDMaxChars 16
#define LineOne     0x80
#define LineTwo     0xc0
#define BlankSpace  ' '

//defines I2C
#define I2C_SDAPORT D
#define I2C_SDA     6
#define I2C_SCLPORT D
#define I2C_SCL     5
#define I2C_SPEED   100000

//define PWM
#define PWM_DPORT D
#define PWM_GREEN 7

#endif //HARDDEF_H
