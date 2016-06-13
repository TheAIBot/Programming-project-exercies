#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "SineLUT.h"
#include "SuperIO.h"
#include "screenio.h"
#include "buttonio.h"
#include "timer.h"
#include "game.h"
#include "level.h"
#include "ball.h"
#include "striker.h"
#include "brick.h"
#include "boss.h"
#include "powerup.h"
#include "color.h"
#include "clockio.h"

#define GAMESIZE 70


char updateFlag = 0;

#pragma interrupt
void timer0int(){
	updateFlag = 1;
}

/*
void printVector(struct TVector v)
{
	printf("\n");
	printFix(expand(v.x));
	printf("\n");
	printFix(expand(v.y));
	printf("\n");
}*/

void main() {
	//standard instanser
	struct TBall vball;
	struct TStriker vStriker;

	int deathcount = 0;
	int velocity = 0;
	int angle = 40;
	int initialx = GAMESIZE >> 1;
	int initialy = GAMESIZE - 1;
	int initl = 5;
	unsigned char index = 0;
	int times = 0;
	int i;
	int j;
	int k;
	int prevPressed = 0;
	int oldI;
	char initNewBall = 1;
	char difficulty = 1;
	int hzscale = 0;
	int score = 0;
	int lives = 10;
	char title[] = "Brick Breaker\0";
	char onboard[] = "Brick Breaker!\0";
	//LEDsetString("Pong Game \0");

	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	
	initClock();  //setup 1000-2000 HZ
	initButtons();
	//LEDinit();
	color(FCOLOR_BLACK, BCOLOR_GRAY);
	enablecursor('1');
	
	//initLevel
	while(1) {
		// begin main loop, selecting difficulty level
		clrscr();
		window(0, 0, GAMESIZE, GAMESIZE, '0', title);
		gotoxy((GAMESIZE/2)-15, (GAMESIZE/2));
	    printf("Welcome to Brick Breaker!");
	    gotoxy((GAMESIZE/2)-15, (GAMESIZE/2)-2);
	    printf("Select difficulty level by pressing left/right button: %5d", difficulty);
	    gotoxy((GAMESIZE/2)-15, (GAMESIZE/2)-3);
	    printf("Press center button to start game.");
	   
	  	stringLED = "Brick Breaker!";
		while(1){
			if(updateFlag == 1){ // 1000 Hz
				updateFlag = 0;
				LEDsetString(onboard);
				LEDupdate();
				scrollText();
				hzscale++;
			}
			if(hzscale > 99){ //100 Hz
				hzscale = 0;
				if(isd3Pressed()){
					difficulty++;
					gotoxy((GAMESIZE/2)-15, (GAMESIZE/2)-2);
		            printf("Select difficulty level by pressing left/right button: %5d", difficulty);
				}
				if( isf7Pressed() && difficulty > 1){
					difficulty--;
					gotoxy((GAMESIZE/2)-15, (GAMESIZE/2)-2);
		        	printf("Select difficulty level by pressing left/right button: %5d", difficulty);
				}
				if(isf6Pressed()){break;}
	    	}
		}

	clrscr();
	hzscale = 0;
	//initialize game objects
	initBall(&vball,initialx, initialy - 1, FCOLOR_BLUE, angle, velocity*difficulty);
	initStriker(&vStriker,initialx, initialy ,initl);
	window(0, 0, GAMESIZE, GAMESIZE, '0', title);
	TIMER !!!!

	// initialize game data
	gptoxy(4,GAMESIZE+1);
	printf("Difficulty: %5d\n", difficulty);
	printf("Total score: %5d\n",score);
	printf("Lives: %5d",lives);
	TID??
	while(1) {
		if (updateFlag == 1) {//1000Hz
			updateFlag = 0;
			//Vi kan have andre ting vist på skærmen på boardet nu
		
		hzscale++;
			}
		if (hzscale > 99) {
		if(initNewBall)
		{
			while(!isf6Pressed())
			{
				moveStrikerPreShot(&vball, &vStriker, GAMESIZE, isd3Pressed(), isf7Pressed());
				//delay(100);
			}
			initNewBall = 0;
			vball.velocity = 1;
		}
		else
		{
			updateBall(&vball);
			delay(100);
			if(isBallDead(&vball, &vStriker, GAMESIZE))
			{
				clearStriker(vStriker.position.x,vStriker.position.y, vStriker.length); 
				clearBall(vball.position.x,vball.position.y);
				initBall(&vball,initialx, initialy - 1, FCOLOR_BLUE, angle, velocity);
				initStriker(&vStriker,initialx,initialy ,initl);
				deathcount++;
				initNewBall = 1;
			}
			//bla bla bla code
		}
	}
	while(1) {}
}

}
