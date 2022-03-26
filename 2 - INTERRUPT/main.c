#include <msp430g2553.h>

#define LED BIT6    //red led
#define BUTTON BIT3 //button

void main(void)
{
    WDTCTL = WDTPW + WDTHOLD;  // stop watchdog time
    P1DIR = LED;    // Set direction of the LED
    P1REN = BUTTON;
    P1OUT = BUTTON;
    P1IE = BUTTON;
    __enable_interrupt();
    while(1);
}

#pragma vector=PORT1_VECTOR   // Port 1 interrupt service routine 
__interrupt void Port_1(void)
{
    P1OUT ^= LED;
    P1IFG = ~BIT3;
}