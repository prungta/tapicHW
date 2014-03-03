 /*
 * File:   main.c
 * Author: Pranay
 *
 * Created on February 10, 2014, 7:57 PM
 */

#include <xc.h>

//#pragma config FOSC = LP  // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA4/OSC2/CLKOUT pin, I/O function on RA5/OSC1/CLKIN)
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Selection bits (BOR enabled)
#pragma config FOSC = HS       // Config Osc

#define _XTAL_FREQ 16000000 // oscillator frequency for _delay() 16 Mhz

void delay(int d); // prototype declaration for the delay function
void adinit();
unsigned int ADCRead(unsigned char ch);
unsigned int adc_result;
int main()
{
    //printf("%s","Starting Program");
    TRISA = 1;
    TRISB = 0;
    
    //TRISCbits.TRISC6 = 0; //set trasmitter on C6 as an output
    adinit();
    while (1){
        PORTBbits.RB4 = 0;
        PORTBbits.RB2 = 0;
        __delay_ms(100);
        GO_DONE = 1;
        while(GO_DONE){
        PORTBbits.RB4 = 0;
        PORTBbits.RB2 = 0;
        }
        adc_result = ADRES;
        if(ADRES & 1)
        {
        PORTBbits.RB4 = 1;
        }
        if(!(ADRES & 1))
        {
        PORTBbits.RB2 = 1;
        }
        __delay_ms(50);



    }
    return 0;
}

void delay(int d)
{
    int i;  // Declare variable to be used in the loop

    while(d)    // While d > 0
    {
        i = 100;    // set i to 100 for inner loop
        while(i)    // while i > 0
        {
            i--;    // decrement i (e.g. i will equal 99, 98, 97,...)
        }

        d--;    // decrement d
    }
}

void adinit()
{
    ADCON1 = 0x00;
    CHS2 = 0;
    CHS1 = 0;
    CHS0 = 0;
    ADCS1 = 0;
    ADCS0 = 1;
    ADON = 1;
    
}
/*
unsigned int ADCRead(unsigned char ch)
{
   if(ch>13) return 0;  //Invalid Channel

   ADCON0=0x00;

   ADCON0=(ch<<2);   //Select ADC Channel

   ADON=1;  //switch on the adc module

   GO_DONE=1;//Start conversion

   while(GO_DONE); //wait for the conversion to finish

   ADON=0;  //switch off adc

   return ADRES;
}*/
