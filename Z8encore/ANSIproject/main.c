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
	char title[] = "Pong game\0";
	//LEDsetString("Pong Game \0");

	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	
	initClock();
	initButtons();
	//LEDinit();
	color(FCOLOR_BLACK, BCOLOR_GRAY);
	clrscr();
	
	window(0, 0, GAMESIZE, GAMESIZE, '0', title);
	initBall(&vball,initialx, initialy - 1, FCOLOR_BLUE, angle, velocity);
	initStriker(&vStriker,initialx, initialy ,initl);
	//initLevel

	while(1)
	{
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
