#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
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

void initBallStriker(struct TBall *ball, struct TStriker *striker, int gameSize)
{
	int initialx = gameSize / 2;
	int initialStrikerY = gameSize - 1;
	int initialBallY = initialStrikerY - 1;
	int velocity = 0;
	int angle = 40;
	int strikerLength = 5;

	initBall(ball, initialx, initialBallY, FCOLOR_BLUE, angle, velocity, 1); // need to know why -3 and -2 is needed
	initStriker(striker, initialx, initialStrikerY ,strikerLength);
}

void initGame(struct TGame *game, int gameSize)
{
}

void updateGame(struct TGame *game)
{
}
