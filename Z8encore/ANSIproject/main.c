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

void main() {

	//uncomment this to run the game
	
	struct TGame game;

	init_uart(_UART0, _DEFFREQ, 115200);

	initGame(&game, GAME_SIZE_X, GAME_SIZE_Y, STRIKER_LENGTH, GAME_UPDATE_RATE);
	while(1)
	{
		runGame(&game);
	}
}
