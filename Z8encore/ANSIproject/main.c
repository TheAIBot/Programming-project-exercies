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
#include "joystick.h"

#define GAME_SIZE_X 150
#define GAME_SIZE_Y 60

void main() {
	//uncomment this to run the game
	/*
	struct TGame game;
	initGame(&game, GAME_SIZE_X, GAME_SIZE_Y, 31, 40);
	while(1)
	{
		runGame(&game);
	}
	*/


	//to test the joystick
	init_uart(_UART0,_DEFFREQ,115200);
	color(FCOLOR_WHITE, BCOLOR_BLACK);
	initClock();
	initJoystick(); // change this to update more than once
	
	while(1)
	{
		printf("%d %d\n", joystickXAxis(), isButton1Pressed());
		delay(100);
	}
}
