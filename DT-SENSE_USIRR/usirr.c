/*****************************************************
Chip type               : ATmega16A
Program type            : Application
AVR Core Clock frequency: 4.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16a.h>

// I2C Bus functions
#include <i2c.h>

// Standard Input/Output functions
#include <stdio.h>
#include <delay.h>

#define sigPORT     PORTB.3
#define sigPIN      PINB.3
#define sigDDR      DDRB.3

#define busyPORT    PORTB.2
#define busyPIN     PINB.2
#define busyDDR     DDRB.2

// Declare your global variables here
typedef unsigned char  uint8_t;
typedef unsigned int   uint16_t;

uint16_t US,IR1,IR2,PUL; 
uint8_t control,cal1,cal2,cal3;

void readReg(void)
{
    i2c_start();
    i2c_write(0xEE);
    i2c_write(3);
    i2c_stop();

    i2c_start();
    i2c_write(0xEF);
    
    control=i2c_read(1);
    cal1=i2c_read(1);
    cal2=i2c_read(1);
    cal3=i2c_read(0);
    i2c_stop();
}

void writeReg(uint8_t cReg,uint8_t cUS,uint8_t cIR1,uint8_t cIR2)
{
    i2c_start();
    i2c_write(0xEE);
    i2c_write(2);
    i2c_write(cReg);
    i2c_write(cUS);
    i2c_write(cIR1);
    i2c_write(cIR2);
    i2c_stop();
}

void startRanging(void)
{
    i2c_start();
    i2c_write(0xEE);
    i2c_write(0);
    i2c_stop();
}

void readData(void)
{
    uint8_t k;
    i2c_start();
    i2c_write(0xEE);
    i2c_write(1);
    i2c_stop();

    i2c_start();
    i2c_write(0xEF);

    k=i2c_read(1);
    US = k * 256;
    k=i2c_read(1);
    US = US + k;

    k=i2c_read(1);
    IR1 = k * 256;
    k=i2c_read(1);
    IR1 = IR1 + k;

    k=i2c_read(1);
    IR2 = k * 256;
    k=i2c_read(0);
    IR2 = IR2 + k;

    i2c_stop();
}

void sendData(void)
{
    putchar('I');putchar('2');putchar('C');putchar('=');
    putchar((US/1000)%10 + 0x30 );
    putchar((US/100)%10  + 0x30 );
    putchar((US%100)/10  + 0x30 );
    putchar((US%10)      + 0x30 );

    putchar(0x20);

    putchar('P');putchar('U');putchar('L');putchar('=');
    putchar((PUL/1000)%10 + 0x30 );
    putchar((PUL/100)%10  + 0x30 );
    putchar((PUL%100)/10  + 0x30 );
    putchar((PUL%10)      + 0x30 );

    putchar(0x20);

    putchar('I');putchar('R');putchar('1');putchar('=');
    putchar((IR1/1000)%10 + 0x30 );
    putchar((IR1/100)%10  + 0x30 );
    putchar((IR1%100)/10  + 0x30 );
    putchar((IR1%10)      + 0x30 );

    putchar(0x20);

    putchar('I');putchar('R');putchar('2');putchar('=');
    putchar((IR2/1000)%10 + 0x30 );
    putchar((IR2/100)%10  + 0x30 );
    putchar((IR2%100)/10  + 0x30 );
    putchar((IR2%10)      + 0x30 );

    putchar(0x0D);
}

void main(void)
{
// Declare your local variables here

// USART initialization
// Communication Parameters: 8 Data, 1 Stop, No Parity
// USART Receiver: On
// USART Transmitter: On
// USART Mode: Asynchronous
// USART Baud Rate: 9600
UCSRA=0x00;
UCSRB=0x18;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x19;

// I2C Bus initialization
// I2C Port: PORTC
// I2C SDA bit: 1
// I2C SCL bit: 0
// Bit Rate: 65 kHz
// Note: I2C settings are specified in the
// Project|Configure|C Compiler|Libraries|I2C menu.
i2c_init();

busyPORT = 1;
busyDDR  = 0;

sigPORT = 1;
sigDDR  = 1;

delay_ms(500);

writeReg(0x0F,128,128,128);

startRanging();
while (busyPIN);
while (!busyPIN);
readData();

writeReg(0x09,128,128,128);
delay_ms(500);

sigDDR  = 1;    // set SIG pin as output

sigPORT  = 0;    //
delay_us(20);    // send start pulse
sigPORT  = 1;    //

sigDDR   = 0;    // set SIG pin as input

TCNT0=0;
while (sigPIN);     // wait for return pulse

TCCR0=0x02;        // start timer (timer period = 2uS)
while ((!sigPIN) && !(TIFR & 0x80));    // timing the return pulse
TCCR0=0x00;        // stop timer
PUL = TCNT0;         // save timer value to variable US

PUL = PUL/5;          // convert to milimeters

sendData();

readReg();
if ((control!=0x09) || (cal1!=128) || (cal2!=128) || (cal3!=128))
   {
//   writeReg(0x09,128,128,128);
   }
else
   {
   putchar('O');
   putchar('K');
   putchar(0x0D);
   }

while (1)
      {
      // Place your code here

      }
}
