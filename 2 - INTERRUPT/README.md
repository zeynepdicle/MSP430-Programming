This repository contains the English translation of an article called [MSP430 Programming with TI (Texas Instruments) LaunchPad – INTERRUPT](https://sisterslab.co/ti-texas-instruments-launchpad-ile-msp430-programlama-interrupt/) which was written by me at [SistersLab](https://sisterslab.co/).

[![](https://img.shields.io/badge/YouTubeVideo-passing-880414)](https://www.youtube.com/shorts/WCnWrJF-mnI) 

## :closed_book:What is INTERRUPT
Interrupts are a key feature of microcontrollers like the MSP430, and are used for fast response, scalability, and detection of rare events. In embedded programming, interrupts are triggers that cause the interrupt code to deviate from the main code flow and execute in a specific order. These triggers can be internal variables or external connections. Interrupts play an important role in performing cutting operations in the peripheral unit.

## :globe_with_meridians: INTERRUPT on MSP430
When programming any microcontroller, it is important to refer to the technical documents published by the manufacturer and write the code based on the information provided. Interrupts are a useful feature of the MSP430 microcontroller because they allow the CPU to respond faster and divide its time more efficiently between processing and power management. Interrupts can be used to detect when a button is pressed, when data is received from a sensor, when there are oscillator errors, and in other situations. Using interrupts in the MSP430 can improve the performance and power efficiency of the device.

The MSP430 microcontroller has three types of interrupts available for use.

### ⤷ SYSTEM RESET

This interrupt will cause the system to reset when triggered.

### ⤷(NON)-MASKABLE NMI

These interrupts cannot be masked and are used to indicate critical states or fault conditions, such as oscillator faults and flash access violations. They are used as fault handlers.

### ⤷MASKABLE

The MSP430 has a type of interrupt called the peripheral interrupt, which is the most commonly used type. It is triggered by peripherals with interrupt capability, such as the watchdog timer (WDT).

## :book:Interrupt Priorities
It is possible that there may be multiple interrupt states in the algorithm of our project. In this case, the MSP430 microcontroller has fixed interrupt priorities to handle this situation. The priority table can be found in the user guide document. Since the table is large, it will not be included here. You can write your code according to your algorithm and the priorities listed in the table.

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
