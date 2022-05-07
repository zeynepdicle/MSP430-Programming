# MSP430 Programming
I am blogging at SistersLab. Series [getting to know peripherals with MSP430 programming](https://sisterslab.co/texas-instruments-launchpad-ile-msp430-mikrodenetleyicisi-programlamaya-giris/). This series translate in English in this repo. 
- [GPIO](https://github.com/zeynepdicle/MSP430-Programming/tree/main/1%20%E2%80%93%20GPIO)
- [INTERRUPT](https://github.com/zeynepdicle/MSP430-Programming/tree/main/2%20-%20INTERRUPT)
- [ADC](https://github.com/zeynepdicle/MSP430-Programming/tree/main/3%20%E2%80%93%20ADC)

Texas Instruments (TI) MSP-EXP430G2ET development board is used. Sample applications have been developed by recognizing the peripherals with the C programming language.

## :closed_book:What is MSP430 ?
MSP (Mixed Signal Processor) microcontrollers have a 16-bit RISC architecture. The most important feature of these microcontrollers is their low power consumption. There are many different series of MSP430 microcontrollers. This series, it has programmed the MSP430G2553 series microcontroller. You can view the [datasheet](https://www.ti.com/tool/MSP-EXP430G2) of the microcontroller here.

![This is an image](https://github.com/zeynepdicle/MSP430-Programming/blob/main/LaunchPad.png)

## :computer:Code Composer Studio IDE
Code Composer Studio IDE (CCStudio or CCS Integrated Development Environment) is used to program our TI LaunchPad MSP430 development board. CCS is used to program TI products.

This development environment is based on the Eclipse open source development environment. It has many features such as C/C++ compiler, source code editor, project build environment and debugger.

MSP430 is programmed at the registers level. The reason for this TI does not have a published library.
