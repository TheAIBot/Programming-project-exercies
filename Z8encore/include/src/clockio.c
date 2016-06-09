#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "clockio.h"

volatile char LEDupdateFlag = 0;
char runClock = 1;
unsigned long halfmiliseconds = 0; // assumes the click runs with 2000hz

void delay(int times)
{
	int i;
	for(i = 0; i < times; i++)
	{
		waitOnce();
	}
}

void waitOnce()
{
	while(LEDupdateFlag == 0) {	}
}

#pragma interrupt
void timer0int() {
	if (runClock == 1)
	{
		LEDupdateFlag = 1;
	}
	halfmiliseconds++;
}

void initClock() // need to add an argument to set the time interval
{
	//interupt vector
	SET_VECTOR(TIMER0, timer0int);

	//Timer
	DI();
	T0CTL = 0x39; //00111001b -> TEN = 1 TPOL = 0 PRES = 111 TMODE = 001.
	T0H = 0x00; //00000000; starting value
	T0L = 0x01; //00000001 - 0000000000000001
	T0RH = 0x00;
	T0RL = 0x48;

	//Set interrupt
	IRQ0ENH &= 0xDF; //enable Timer 0 interrupt, and set nominal priority
	IRQ0ENL |= 0x20; 

	//Enable timer
	T0CTL = 0xB9; //10111001
	EI();
}

void startClock()
{
	runClock = 1;
}

void stopClock()
{
	runClock = 0;
}

unsigned long getMiliseconds()
{
	return halfmiliseconds / 2;
}