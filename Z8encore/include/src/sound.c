#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "clockio.h"

volatile char SoundUpdateFlag = 0;


void waitOnceSound()
{
	while(SoundUpdateFlag == 0) 
	{	
	}
	SoundUpdateFlag = 0;
}

void delaySound(int times)
{
	int i;
	for(i = 0; i < times; i++)
	{
		waitOnceSound();
	}
}


#pragma interrupt
void timer1int() {
	SoundUpdateFlag = 1;
}

void initSoundPin()
{
	//Initialize af knapper
	//Button PD2 output
	PDADDR = 0x01;
	PDCTL = ~0x04;
}

void playBounceSound(char h)
{
	int i;
	for (i = 0; i<100 - h * 10;i++){
		PDOUT = ~PDOUT;
		delaySound(20 + h * 10);
	}
}

void playWallSound()
{
	playBounceSound(0);
}

void playDeathBallSound() {
	int i;
	for (i = 0; i<50;i++){
		PDOUT = ~PDOUT;
		delaySound(100);
	}
}

void playDeathBrickSound(){
	int i;
	for (i = 0; i<50;i++){
		PDOUT = ~PDOUT;
		delaySound(50);
	}
}

void playStartGameSound()
{
	int i;
	for (i = 100; i>-400;i--){
		PDOUT = ~PDOUT;
		delaySound(i);
	}
}

void playGameOverSound()
{
	int i;
	for (i = 40; i<350;i++){
		PDOUT = ~PDOUT;
		delaySound(i);
	}
}

void playGameWinSound()
{
	int i;
	for (i = 80; i>-10000;i--){
		PDOUT = ~PDOUT;
		delaySound(i);
	}
	delay(100);
	for (i = 0; i<100;i++){
		PDOUT = ~PDOUT;
		delaySound(40);
	}
	delay(100);
	for (i = 0; i<600;i++){
		PDOUT = ~PDOUT;
		delaySound(20);
	}
}


void initSoundClock() // need to add an argument to set the time interval
{
	//interupt vector and timer
	SET_VECTOR(TIMER1, timer1int);

	//Disable interupt
	DI();
	//Disable timer
	T1CTL = 0x39; //00111001b -> TEN = 1 TPOL = 0 PRES = 111 TMODE = 001.

	//Set timer High and Low
	T1H = 0x00; //00000000; starting value
	T1L = 0x01; //00000001

	/*PWM value
	T1PWMH = 0x00;
	T1PWML = 0x40;*/


	//reload value
	T1RH = 0x00;
	T1RL = 0x04;

	//Set interrupt
	IRQ0ENL &= 0xBF; //enable Timer 0 interrupt, and set nominal priority
	IRQ0ENH |= 0x40; 

	//Enable timer
	T1CTL = 0xB9; //10111001

	//Enable Interupt
	EI();
}
