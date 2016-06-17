#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "buttonio.h"
#include "clockio.h"
#include "joystick.h"
#include "game.h"
#include "clockio.h"
#include "sound.h"

#define GAME_SIZE_X 150
#define GAME_SIZE_Y 60
#define STRIKER_LENGTH 31
#define GAME_UPDATE_RATE 40

#define C1_BIT 0x02

void main() {
	/*
	int i = 0;
	PCADDR = 0x02;
	PCCTL &= 0x02;
	PCOUT = C1_BIT;
	//char d2 = (~PDOUT & D2_BIT) >> 1;
	while(1) 
	{ 

		PCOUT;
		printf("%d", PCOUT);

	}

	*/
		/*	for(i = 0; i < 1000; i++)
		{
			PDOUT = (i % 2) << D2_BIT;
			delay(i);
		}*/
	//uncomment this to run the game
	
	struct TGame game;

	init_uart(_UART0,_DEFFREQ,115200);

	initGame(&game, GAME_SIZE_X, GAME_SIZE_Y, STRIKER_LENGTH, GAME_UPDATE_RATE);
	while(1)
	{
		runGame(&game);
	}
	

	/*
	//to test the joystick
	init_uart(_UART0,_DEFFREQ,115200);
	initClock();
	initJoystick(); // change this to update more than once
	
	while(1)
	{
		printf("%d %d\n", joystickXAxis(), isButton1Pressed());
		delay(100);
	}
	*/
}
