#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "clockio.h"

//used to communicate with other code that the timers interrupt has run once
//it's volatile because the interrupt can execute at any time which means that the variable can change at any time
volatile char LEDupdateFlag = 0;
//used to keep count on how many half miliseconds has passed since the clock started
//it's volatile because the interrupt can execute at any time which means that the variable can change at any time
volatile unsigned long halfmiliseconds = 0; // assumes the click runs with 2000hz

//delays any further code by 0.5ms * times ms
void delay(int times)
{
	int i;
	for(i = 0; i < times; i++)
	{
		waitOnce();
	}
}

//waits for one clock
void waitOnce()
{
	//when the clock runs LEDupdateFlag is set to 1
	//so break when LEDupdateFlag == 1
	while(LEDupdateFlag == 0) 
	{	
	}
	//set LEDupdateFlag back to 0 so when this code runs again it will wait for LEDupdateFlag to be 1
	LEDupdateFlag = 0;
}

//timer 0 interrupt method
//it's called every half second
#pragma interrupt
void timer0int() {
	LEDupdateFlag = 1;
	halfmiliseconds++;
}

//starts the clock
void initClock()
{
	//interupt vector
	SET_VECTOR(TIMER0, timer0int);

	//Timer
	DI(); //Diable interrupt

	//Disable Timer0
	T0CTL = 0x39; //00111001b -> TEN = 1 TPOL = 0 PRES = 111 TMODE = 001.
	
	//Set staring value for counter
	T0H = 0x00; //00000000
	T0L = 0x01; //00000001 
	
	//reload value
	T0RH = 0x00;
	T0RL = 0x48;

	//Set interrupt
	IRQ0ENL |= 0x20; //enable Timer 0 interrupt, and set HIGH priority
	IRQ0ENH |= 0x20; 

	//Enable timer
	T0CTL = 0xB9; //10111001

	EI(); //Enable interrupt
}

//returns the amount of miliseconds has passed since the clock started
unsigned long getMiliseconds()
{
	return halfmiliseconds / 2;
}
