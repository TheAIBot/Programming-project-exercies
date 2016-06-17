#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "buttonio.h"
#include "clockio.h"
#include "joystick.h"
#include "game.h"
#include "clockio.h"
#include "sound.h"

#define GAME_SIZE_X 100
#define GAME_SIZE_Y 40
#define STRIKER_LENGTH 21
#define GAME_UPDATE_RATE 30

#define C1_BIT 0x02

void main() {
	/*
	init_uart(_UART0, _DEFFREQ, 115200);

	initSoundPin();
	initClock();
	initSoundClock();
	while(1)
	{
	int i;
	for (i = 0; i<50;i++){
		PDOUT = ~PDOUT;
		delaySound(50);
	}
		delay(4000);
	}
	*/


	//uncomment this to run the game
	
	struct TGame game;

	init_uart(_UART0, _DEFFREQ, 115200);

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
