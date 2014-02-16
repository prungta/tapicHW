/* 
 * File:   main.c
 * Author: Pranay
 *
 * Created on February 11, 2014, 7:57 PM
 */

#include <xc.h>
#pragma config WDTE = OFF        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config BOREN = ON       // Brown-out Reset Selection bits (BOR enabled)
#pragma config FOSC = HS       // Config Osc

/*
 * 
 */
int main() {

    TRISBbits.TRISB4 = 0; //set LED on B4 as an output
    while(1){
        
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

void interrupt receivedOne(){
    if(PORTCbits.RC6 == 1)
    {
        PORTBbits.RB4 = 1;
        delay(1000);
        PORTBbits.RB4 = 0;
    }
}

