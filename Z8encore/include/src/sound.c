#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "clockio.h"

#define MAX_SOUND_FREQUENCY 9000

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

void tone(int freq, int msLength)
{
	int sleep = MAX_SOUND_FREQUENCY / freq;
	long loops = ((long)msLength * freq / 1000);
	int i;
	for(i = 0; i < loops; i++)
	{
		PDOUT = ~PDOUT;
		delaySound(sleep);
	}
}

void playBounceSound(char h)
{
	tone(MAX_SOUND_FREQUENCY / (20 + h * 10), 400);
}

void playWallSound()
{
	playBounceSound(0);
}

void playDeathBallSound() {
	tone(90, 400);
}

void playDeathBrickSound(){
	tone(180, 400);
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

void playBoosDeathSound()
{
	tone(100, 500);
	delay(10);
	tone(100, 500);
	delay(10);
	tone(100, 500);
	delay(10);
	tone(50, 2000);
}

void playGameWinSound()
{
	int i;
	for (i = 80; i>-10000;i--){
		PDOUT = ~PDOUT;
		delaySound(i);
	}
	delay(100);
	tone(225, 400);
	delay(100);
	tone(450, 400);
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

	//18k hz
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
