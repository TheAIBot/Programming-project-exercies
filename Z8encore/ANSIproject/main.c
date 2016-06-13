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

void main() {
	struct TGame game;
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	
	initClock(); //needed to use delay which the buttons use
	initButtons();

	initGame(&game, GAMESIZE);

	while(1)
	{
		updateGame(&game);
	}
}
