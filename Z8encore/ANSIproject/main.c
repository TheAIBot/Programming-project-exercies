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

#define GAMESIZEX 150
#define GAMESIZEY 60


void main() {
	//standard instanser
	struct TBall vball;
	struct TStriker vStriker;

	long velocity = 0;
	int angle = 45;
	int initialx = GAMESIZEX >> 1;
	int initialy = GAMESIZEY - 1;
	int initl = 31;
	unsigned char index = 0;
	char initNewBall = 1;
	char difficulty = 1;
	int hzscale = 0;
	int score = 0;
	int lives = 10;
	char title[] = "Brick Breaker\0";
	char onboard[] = "Brick Breaker!\0";
	struct TBrick bricks[] = 
	{
		{{1, 2}, {10,1}, 1, {0,0}, 0}, 
		{{12,2}, {10,1}, 1, {0,0}, 0}, 
		{{24,2}, {10,1}, 1, {0,0}, 0}, 
		{{36,2}, {10,1}, 1, {0,0}, 0},
		{{48,2}, {10,1}, 1, {0,0}, 0}, 
		{{1, 4}, {10,1}, 1, {0,0}, 0}, 
		{{12,4}, {10,1}, 1, {0,0}, 0}, 
		{{24,4}, {10,1}, 1, {0,0}, 0}, 
		{{36,4}, {10,1}, 1, {0,0}, 0},
		{{48,4}, {10,1}, 1, {0,0}, 0}, 
		{{1, 6}, {10,1}, 1, {0,0}, 0}, 
		{{12,6}, {10,1}, 1, {0,0}, 0}, 
		{{24,6}, {10,1}, 1, {0,0}, 0}, 
		{{36,6}, {10,1}, 1, {0,0}, 0},
		{{48,6}, {10,1}, 1, {0,0}, 0}, 
	};
	int brickCount = 16;
	//LEDsetString("Pong Game \0");

	init_uart(_UART0,_DEFFREQ,115200);
	
	LEDinit();  //setup 1000-2000 HZ
	initButtons();
	//LEDinit();
	color(FCOLOR_WHITE, BCOLOR_BLACK);
	LEDsetString(onboard);
	enablecursor('0');
	//initLevel
	/*printFix(cos(0));
	printFix(cos(45));
	printFix(cos(-78));
	printFix(cos(649));
	printFix(cos(40));
	printFix(sin(40));
	while(1){}*/
	while(1) {
		// begin main loop, selecting difficulty level
		clrscr();
		window(0, 0, GAMESIZEX, GAMESIZEY, '0', title);
		gotoxy((GAMESIZEX/2)-15, (GAMESIZEY/2));
	    printf("Welcome to Brick Breaker!");
	    gotoxy((GAMESIZEX/2)-15, (GAMESIZEY/2)-2);
	    printf("Select difficulty level by pressing left/right button (max. 5): %5d", difficulty);
	    gotoxy((GAMESIZEX/2)-15, (GAMESIZEY/2)-3);
	    printf("Press center button to start game.");
		while(1){
			scrollText();
			if(hzscale == 19){ //100 Hz
				hzscale = 0;
				if(isd3Pressed()){
					difficulty++;
					gotoxy((GAMESIZEX/2)-15, (GAMESIZEY/2)-2);
		            printf("Select difficulty level by pressing left/right button: %5d", difficulty);
				}
				if( isf7Pressed() && difficulty > 1){
					difficulty--;
					gotoxy((GAMESIZEX/2)-15, (GAMESIZEY/2)-2);
		        	printf("Select difficulty level by pressing left/right button: %5d", difficulty);
				}
				if(isf6Pressed() || difficulty == 5){break;}
	    	}
			hzscale++;
		}

		clrscr();
		hzscale = 0;
		initNewBall = 1;
		//initialize game objects
		initBall(&vball,initialx, initialy - 1, FCOLOR_WHITE, angle, velocity*difficulty);
		initStriker(&vStriker,initialx, initialy ,initl);
		initBricks(bricks, brickCount);
		fgcolor(FCOLOR_WHITE);
		window(0, 0, GAMESIZEX, GAMESIZEY, '0', title);
		fgcolor(FCOLOR_WHITE);
		//TIMER !!!!
	
		// initialize game data
		gotoxy(0,GAMESIZEY+1);
		printf("Difficulty: %5d\n", difficulty);
		printf("Total score: %5d\n",score);
		printf("Lives: %5d",lives);
		//TID??
		while(1) {
			/*if (LEDupdateFlag == 1) {//1000Hz
				updateFlag = 0;
				//Vi kan have andre ting vist på skærmen på boardet nu
			
			    hzscale++;
				}
			if (hzscale == 9) {//100Hz
			*/
			delay(20);
			if(initNewBall)
			{
				while(!isf6Pressed())
				{
					moveStrikerPreShot(&vball, &vStriker, GAMESIZEX, isd3Pressed(), isf7Pressed());
					//delay(100);
				}
				initNewBall = 0;
			}
			else
			{
				setBallColor(&vball);
				updateBall(&vball);
				moveStriker(&vStriker, GAMESIZEX, isf7Pressed(), isd3Pressed());
				impact(&vball, &vStriker, GAMESIZEX, GAMESIZEY);
				bounceStriker(&vStriker, &vball);
				handleBrickCollisions(bricks, &vball, brickCount);
				if(isBallDead(&vball, GAMESIZEY))
				{
					clearStriker(vStriker.position.x,vStriker.position.y, vStriker.length); 
					clearBall(vball.position.x,vball.position.y);
					initBall(&vball,initialx, initialy - 1, FCOLOR_WHITE, angle, velocity);
					initStriker(&vStriker,initialx,initialy ,initl);
					initNewBall = 1;
				}
				//bla bla bla code
			}
		}
		while(1) {}
	}
}
