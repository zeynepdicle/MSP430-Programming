This repo contains the English translation of the article [MSP430 Programming with TI (Texas Instruments) LaunchPad – INTERRUPT](https://sisterslab.co/ti-texas-instruments-launchpad-ile-msp430-programlama-interrupt/) that I wrote on [SistersLab](https://sisterslab.co/).

[![](https://img.shields.io/badge/YouTubeVideo-passing-880414)](https://www.youtube.com/shorts/WCnWrJF-mnI) 

## :closed_book:What is INTERRUPT
It is the peripheral unit where we perform the cutting operations. Interrupt plays an important role in microcontrollers such as MSP430. It is used for rapid response, scalability and detection of rare events. In embedded programming, they are usually triggers that cause the interrupt code to deviate as its instructions continue in the order in which they are specified. The reason for entering the interrupt here may be due to the internal variable, it may be with an external connection.

## :globe_with_meridians: INTERRUPT on MSP430
While programming all the microcontrollers we use, we make use of the technical documents published by the manufacturers and write our code according to the information there. Using interrupts in the MSP430 makes our microcontroller respond faster and allows the CPU to divide more time to processing as well as take advantage of lower power. MSP430 uses interrupt to detect when a button is pressed or data comes from a sensor, oscillator errors and other conditions.

The MSP430 microcontroller we use has three types of interrupts.

### ⤷ SYSTEM RESET

The system resets when this interrupt is triggered.

### ⤷(NON)-MASKABLE NMI

These interrupts cannot be masked. This interrupt indicates critical state these are fault handlers such as oscillator faults and flash access violation.

### ⤷MASKABLE

MSP430 is the most used interrupt type among interrupt types. It is caused by peripherals with interrupt capability, including WDT (Watchdog Timer).

## :book:Interrupt Priorities
It is possible that there is more than one interrupt state in the algorithm in our project. In this case, our microcontroller has interrupt priorities. For the MSP340 these are fixed. For this, there is a priority table in the user guide document. Since the table is large, I will not repeat it here. You can write your code in your own project according to your algorithm.

## :rocket:Code
```c
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
```

You can watch the video [YouTube](https://www.youtube.com/shorts/WCnWrJF-mnI?&ab_channel=Dicle)
