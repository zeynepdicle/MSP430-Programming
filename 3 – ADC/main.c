#include "msp430g2553.h"

void main(void)
{
  WDTCTL = WDTPW + WDTHOLD; 

  ADC10CTL0 = ADC10ON + ADC10IE; 

  ADC10CTL1 = ADC10DIV_7; 
 
  ADC10AE0 = INCH_0;  // channel A0

  ADC10CTL0 |= ENC + ADC10SC;

  _BIS_SR(LPM0_bits + GIE); 
}

#pragma vector = ADC10_VECTOR
__interrupt void adc10_interrupt(void)
{
  ADC10CTL0 |= ENC + ADC10SC; 
}
