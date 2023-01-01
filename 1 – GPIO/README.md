This repository contains the English translation of the article [MSP430 Programming with TI (Texas Instruments) (https://sisterslab.co/ti-launchpad-ile-msp430-programlama-gpio/) LaunchPad – GPIO that I wrote at [SistersLab](https://sisterslab.co/).

[![](https://img.shields.io/badge/YouTubeVideo-passing-880414)](https://www.youtube.com/watch?v=iGFOYuTLY2k) 

## :closed_book:What is GPIO(General Purpose Input/Output)
GPIO (general purpose input and output) is a type of pin that is used for a wide range of tasks. These pins can be used to perform functions such as blinking an LED, reading data from a button, driving a motor, or reading data from a sensor. The number of GPIO pin connections varies among microcontrollers. For example, the MSP430G22553 microcontroller has 16 GPIO pins.

## :globe_with_meridians:GPIO on MSP430
When programming the microcontroller, it is important to refer to the [technical documents](https://www.ti.com/product/MSP430G2553#tech-docs) published by the manufacturer. For the MSP430G2X53 microcontroller family, these documents include the [datasheet](https://www.ti.com/lit/ds/symlink/msp430g2553.pdf?ts=1638097936795) and [user guide](https://www.ti.com/lit/ug/slau144j/slau144j.pdf?ts=1638097764802&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FMSP430G2553%253FkeyMatch%253DMSP430G2553%2526tisearch%253Dsearch-everything%2526usecase%253DGPN). These documents provide important information that is necessary for programming the microcontroller.

The MSP430G22553 microcontroller, which is contained within the TI LaunchPad MSP430 development kit, has the following pin configuration, shown below

![This is an image](https://github.com/zeynepdicle/MSP430-Programming/blob/main/1%20%E2%80%93%20GPIO/ti-pinout.JPG)

When using these pins as GPIO (general-purpose input/output) pins, the following configurations are used.

### ⤷OUTPUT REGISTERS `PxOUT`
In this configuration, the pin is set as an output. Output operations can be read and written. The value of the bit in this operation is either LOW (bit = 0) or HIGH (bit = 1).

### ⤷INPUT REGISTERS `PxIN`
In this configuration, the pin is set as an input. The value of the bit in this operation is either LOW (bit = 0) or HIGH (bit = 1).

### ⤷DIRECTION REGISTER `PxDIR` 
In this configuration, it is possible to select the pin as either an input or output, regardless of the selected configuration. A value of 1 sets the pin as an output, while a value of 0 sets it as an input.

### ⤷PULLUP/PULLDOWN RESISTOR ENABLE REGISTER `PxEN`
This configuration enables or disables the pullup/pulldown resistor of the corresponding input/output pin. A value of 0 disables the resistor, while a value of 1 enables it.

⤷In addition to these configurations, the Function Select Registers PxSEL and PxSEL2 can also be used to configure the pin as an oscillator, P1 and P2 interrupts, and to configure unused port pins.

## :rocket:Code
This code will make the green LED on the development board blink. It is written using the Code Composer Studio IDE development environment. After downloading and installing the application, click on the "New Project" tab and create a new project. 
Be sure to select the correct microcontroller for your project.

```c
#include <msp430.h>				

void main(void) {
	WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
	P1DIR |= 0x01;   // configure P1.0 as output

	volatile unsigned int i;   // volatile to prevent optimization

	while(1)
	{
		P1OUT ^= 0x01;   // toggle P1.0
		for(i=50000; i>0; i--);   // delay
	}
}
```
You can watch the video [YouTube](https://www.youtube.com/watch?v=iGFOYuTLY2k) 
