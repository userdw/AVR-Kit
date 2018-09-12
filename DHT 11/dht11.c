/*****************************************************
Chip type               : ATmega16A
Program type            : Application
AVR Core Clock frequency: 4.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16a.h>
#include <delay.h>
#include <stdio.h>
#include <stdlib.h>
#include <alcd.h>

#define DHT11_DDR DDRD.6
#define DHT11_PORT PORTD.6
#define DHT11_PIN PIND.6

typedef unsigned char  uint8_t;
uint8_t c=0, I_RH, D_RH, I_Temp, D_Temp, checksum;

// Declare your global variables here
void request(){
    // resetport
    DHT11_DDR = 1;
    DHT11_PORT = 1;
    delay_ms(100);
    
	DHT11_DDR = 1;
	DHT11_PORT = 0;
	delay_ms(20);
	DHT11_PORT = 1;
}

void response(){
	DHT11_DDR = 0;
    while(PIND & (1<<6));
	while((PIND & (1<<6))==0);
	while(PIND & (1<<6));
}

uint8_t receive_data(){
	unsigned int q,r;
    for (r=0; r<5; r++){

	    for (q=0; q<8; q++){
		    while((PIND & (1<<6)) == 0);
		    delay_us(30);
		    if(PIND & (1<<6)){
		    c = (c<<1)|(0x01);
		    }
            else{
		    c = (c<<1);
		    }
            while(PIND & (1<<6));
	    }
	        return c;
    }
}

void main(void)
{
// Declare your local variables here
char data[5];
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
lcd_init(16);

request();
response();
I_RH = receive_data();
D_RH = receive_data();
I_Temp = receive_data();
D_Temp = receive_data();
checksum = receive_data();

if ((I_RH + D_RH + I_Temp + D_Temp)!=checksum){
	putchar('E');putchar('r');putchar('r');putchar('o');putchar('r');
	putchar(0x0D);	
}

else{

	itoa(I_RH,data);
    putchar('H');putchar('u');putchar('m');putchar('=');
    puts(data);
    putchar('R');putchar('H');putchar(' ');
//    itoa(D_RH,data);
//	puts(data);
	itoa(I_Temp,data);
    putchar('T');putchar('e');putchar('m');putchar('=');
	puts(data);
    putchar(',');
	itoa(D_Temp,data);
	puts(data);
    putchar('C');
//	itoa(checksum,data);
//	puts(data);
    }  
delay_ms(1000);

while (1)
      {
      // Place your code here

      }
}

