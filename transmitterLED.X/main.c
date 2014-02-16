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

void delay(int d); // prototype declaration for the delay function

int main()
{
    TRISBbits.TRISB4 = 0; //set LED on B4 as an output
    //TRISCbits.TRISC6 = 0; //set trasmitter on C6 as an output
    while (1){
        PORTBbits.RB4 = 1;  //set high
        //PORTCbits.RC6 = 1;   // set high
        delay(500);
        PORTBbits.RB4 = 0;  //set low
        //PORTCbits.RC6 = 0;   // set low
        delay(1000);
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