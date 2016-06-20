#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "buttonio.h"
#include "clockio.h"
#include "joystick.h"
#include "game.h"
#include "clockio.h"
#include "sound.h"
#include "tests.h"
#include "charset.h"

void main() {
	//uncomment this to run the game
	
	struct TGame game;

	init_uart(_UART0, _DEFFREQ, 115200);

	initGame(&game);
	while(1)
	{
		runGame(&game);
	}
	/*
	initSoundPin();
	initClock();
	initSoundClock();
	
	playGameWinSound();
	while(1){}
*/
	//runAllTests();
}
