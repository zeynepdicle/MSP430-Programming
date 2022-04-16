This repo contains the English translation of the article [MSP430 Programming with TI (Texas Instruments) LaunchPad – GPIO](https://sisterslab.co/ti-launchpad-ile-msp430-programlama-gpio/) that I wrote on [SistersLab](https://sisterslab.co/).

[![](https://img.shields.io/badge/YouTubeVideo-passing-880414)](https://www.youtube.com/watch?v=iGFOYuTLY2k) 

## :closed_book:What is GPIO(General Purpose Input/Output)
GPIO is a general purpose input and output pin. We can perform many different operations with these pins. With the GPIO pin, you can do many operations such as led blink, reading data from the button, driving a motor, reading the data from the sensor. Each microcontroller has a different number of GPIO pin connections. The MSP430G22553 microcontroller we use has 16 GPIO pins.

## :globe_with_meridians:	GPIO on MSP430
While programming the microcontroller, we will use the [technical document](https://www.ti.com/product/MSP430G2553#tech-docs) published by manufacturer to users. We can examine the [datasheet](https://www.ti.com/lit/ds/symlink/msp430g2553.pdf?ts=1638097936795) and [user guide](https://www.ti.com/lit/ug/slau144j/slau144j.pdf?ts=1638097764802&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FMSP430G2553%253FkeyMatch%253DMSP430G2553%2526tisearch%253Dsearch-everything%2526usecase%253DGPN) documents published for the MSP430G2X53 microcontroller family. We will use these documents when programming microcontrollers.

The pinout of the MSP430G22553 microcontroller, which is in the TI LaunchPad MSP430 development kit, is shown below.

![This is an image](https://github.com/zeynepdicle/MSP430-Programming/blob/main/1%20%E2%80%93%20GPIO/ti-pinout.JPG)

It uses the following configurations when defining these pins as GPIO pins. 

### ⤷OUTPUT REGISTERS `PxOUT`
In this configuration, pin is set as output. Output operations are read-write. The value corresponding to the bit in this operation;

Bit = 0: LOW

Bit = 1: HIGH  is in the form.

### ⤷INPUT REGISTERS `PxIN`
In this configuration, pin is set as input. The value corresponding to the bit in this operation;

Bit = 0: LOW

Bit = 1: HIGH  is in the form.

### ⤷DIRECTION REGISTER `PxDIR` 
In this configuration, it is possible to select our pin as an input/output regardless of the selected configuration.

Bit = 1: The pin is set as output.
Bit = 0: Pin is set as input.

### ⤷PULLUP/PULLDOWN RESISTOR ENABLE REGISTER `PxEN`
This configuration enables or disables the Pullup/Pulldown resistor of the corresponding input/output pin of our pin.

Bit = 0: Pullup/pulldown resistor disabled
Bit = 1: Pullup/pulldown resistor active

⤷Other than these, pins; Function Select Registers `PxSEL` and `PxSEL2` can also be configured as Pin Oscillator, `P1` and `P2` Interrupts, Configuring Unused Port Pins.

## :rocket:Code
We will write your code to flash the green led on the development board. In this software, we will use the Code Composer Studio IDE development environment. After downloading and installing the application, we click on the "new project" tab and create a new project.
Make sure you choose the right microcontroller here. It is connected to the P1.0 pin of our green led microcontroller on the development board we use.

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
