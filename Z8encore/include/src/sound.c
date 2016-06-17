#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"

#pragma interrupt
void timer1int() {

}

void initSoundClock() // need to add an argument to set the time interval
{
	//interupt vector and timer
	SET_VECTOR(TIMER1, timer1int);

	//Disable interupt
	DI();
	//Disable timer
	T1CTL = 0x3B; //00111011b -> TEN = 1 TPOL = 0 PRES = 111 TMODE = 001.

	//Set timer High and Low
	T1H = 0x00; //00000000; starting value
	T1L = 0x01; //00000001

	//PWM value
	T1PWMH = 0x00;
	T1PWML = 0x40;


	//reload value
	T1RH = 0x00;
	T1RL = 0x80;

	//Set interrupt
	IRQ0ENL &= 0xBF; //enable Timer 0 interrupt, and set nominal priority
	IRQ0ENH |= 0x40; 

	//Enable timer
	T1CTL = 0xBB; //10111011

	//Enable Interupt
	EI();
}