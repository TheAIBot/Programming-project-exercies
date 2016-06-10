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
	struct TStriker vstriker;

	int velocity = 0;
	int angle = 40;
	int size = 150;
	int initialx = 75; 
	int initialy = size + 1;
	int initialstrikery = size;
	int initl = 5;
	unsigned char index = 0;
	int times = 0;
	int i;
	int j;
	int k;
	int prevPressed = 0;
	int oldI;
	char title[] = "Pong game\0";
	LEDsetString("Pong Game \0");

	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	
	initButtons();
	LEDinit();
	clrscr();
	
	
	initBall(&vball,initialx, initialy, FCOLOR_BLUE, angle, velocity);
	initStriker(&vstriker,initialx,initialstrikery ,initl);
	window(0, 0, size, size, '0', title);
	//initLevel
	moveStrikerPreShot(&vball, &vstriker, size, isd3Pressed(), isf7Pressed(), isf6Pressed());
}
