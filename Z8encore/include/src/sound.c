#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "clockio.h"

//the max frequency the speaker can make with this timers interval
#define MAX_SOUND_FREQUENCY 9000

//used to communicate that the timers interrupt has run
volatile char SoundUpdateFlag = 0;


//waits for the  sound clock interrupt to run once
void waitOnceSound()
{
	//the interupt sets the flag to 1 
	//so wait until it's 1
	while(SoundUpdateFlag == 0) 
	{	
	}
	//reset flag
	SoundUpdateFlag = 0;
}

//wait for a specific amount of clock cycles
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

//set the sounds pin ti output mode
void initSoundPin()
{
	PDADDR = 0x01;
	PDCTL = ~0x04;
}

//outputs a tone with a specific frequency for a certain amount of miliseconds
void tone(int freq, int msLength)
{
	//how many clock cycles to wait for to get the correct frequency
	int sleep = MAX_SOUND_FREQUENCY / freq;
	//how many times to output the tone in the specified amount of miliseconds
	long loops = ((long)msLength * freq / 1000);
	int i;
	for(i = 0; i < loops; i++)
	{
		//inverts the output of the speakers input
		PDOUT = ~PDOUT;
		delaySound(sleep);
	}
}

//plays a different tone depending on h
void playBounceSound(char h)
{
	tone(MAX_SOUND_FREQUENCY / (20 + h * 10), 400);
}

void playWallSound()
{
	playBounceSound(0);
}

void playIndestructibleBrickSound()
{
	playBounceSound(5);
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
	//outputs a tone that becomes higher and higher
	//by decreasing the delay
	//when the delay is negative there is no delay
	for (i = 100; i > -400;i--){
		PDOUT = ~PDOUT;
		delaySound(i);
	}
}

void playGameOverSound()
{
	int i;
	//outputs a tone that becomes lower and lower
	//by increasing the delays
	for (i = 40; i < 350;i++){
		PDOUT = ~PDOUT;
		delaySound(i);
	}
}

void playBossDeathSound()
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
	//outputs a tone that becomes higher and higher
	//by decreasing the delay
	//when the delay is negative there is no delay
	for (i = 80; i>-10000;i--){
		PDOUT = ~PDOUT;
		delaySound(i);
	}
	delay(100);
	tone(225, 400);
	delay(100);
	tone(450, 400);
}

//start the clock that controls the sound and sets it to run at 18khz
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
	IRQ0ENL &= 0xBF; 
	IRQ0ENH |= 0x40; //enable Timer 1 interrupt, and set nominal priority

	//Enable timer
	T1CTL = 0xB9; //10111001

	//Enable Interupt
	EI();
}
