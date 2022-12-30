# MSP430 Programming
As a blogger at [SistersLab](https://sisterslab.co/texas-instruments-launchpad-ile-msp430-mikrodenetleyicisi-programlamaya-giris/), I am currently exploring the peripherals available on MSP430 microcontrollers through a programming series. The series, which delves into the use of GPIO, interrupts, and ADC, is translated into English and housed in this repository.
- [GPIO](https://github.com/zeynepdicle/MSP430-Programming/tree/main/1%20%E2%80%93%20GPIO)
- [INTERRUPT](https://github.com/zeynepdicle/MSP430-Programming/tree/main/2%20-%20INTERRUPT)
- [ADC](https://github.com/zeynepdicle/MSP430-Programming/tree/main/3%20%E2%80%93%20ADC)

The Texas Instruments (TI) MSP-EXP430G2ET development board is utilized in the creation of sample applications that utilize the C programming language to showcase the capabilities of the various peripherals.

## :closed_book:What is MSP430 ?

MSP (Mixed Signal Processor) microcontrollers are equipped with a 16-bit RISC architecture and are known for their low power consumption. There are numerous series of MSP430 microcontrollers, and this series focuses on programming the MSP430G2553 series microcontroller. You can view the [datasheet](https://www.ti.com/tool/MSP-EXP430G2) for this microcontroller here.

![This is an image](https://github.com/zeynepdicle/MSP430-Programming/blob/main/LaunchPad.png)


## :computer:Code Composer Studio IDE
The Code Composer Studio IDE (CCStudio or CCS Integrated Development Environment) is used to program the TI LaunchPad MSP430 development board. CCS is specifically designed for programming TI products and is built on the Eclipse open source development environment. It includes a C/C++ compiler, source code editor, project build environment, and debugger.

MSP430 microcontrollers are programmed at the register level as TI does not have a published library for them.
