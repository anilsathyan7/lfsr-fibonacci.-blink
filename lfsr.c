#include <stdint.h>
#include<msp430.h>
uint16_t lfsr = 0xACE1u;
unsigned bit;
unsigned period = 0;


void delay()
{
unsigned int i = 0;
while(++i < 22000);
}
main()
{
 do 
   {
 
  bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
  lfsr =  (lfsr >> 1) | (bit << 15);
  ++period;

	P1DIR=BIT6;
	P1OUT=lfsr & BIT6;
	delay();


   } while(lfsr != 0xACE1u);}
