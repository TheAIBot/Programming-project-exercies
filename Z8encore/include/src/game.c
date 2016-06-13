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

	initBall(ball, initialx, initialBallY, FCOLOR_BLUE, angle, velocity); // need to know why -3 and -2 is needed
	initStriker(striker, initialx, initialStrikerY ,strikerLength);
}

void initGame(struct TGame *game, int gameSize)
{
	game->gameSize = gameSize;
	game->newBall = 1;
	game->deathCount = 0;

	color(FCOLOR_BLACK, BCOLOR_GRAY);
	clrscr();
	window(0, 0, gameSize, gameSize, '0', "Pong Game\0");

	initBallStriker(&(game->balls[0]), &(game->striker), gameSize);
}

void updateGame(struct TGame *game)
{
	if(game->newBall)
	{
		while(!isf6Pressed())
		{
			moveStrikerPreShot(&(game->balls[0]), &(game->striker), game->gameSize, isd3Pressed(), isf7Pressed());
			//delay(100);
		}
		game->newBall = 0;
		game->balls[0].velocity = 1;
	}
	else
	{
		updateBall(&(game->balls[0]));
		delay(100);
		if(isBallDead(&(game->balls[0]), game->gameSize))
		{
			clearStriker(game->striker.position.x,game->striker.position.y, game->striker.length); 
			clearBall(game->balls[0].position.x, game->balls[0].position.y);
			initBallStriker(&(game->balls[0]), &(game->striker), game->gameSize);
			game->deathCount++;
			game->newBall = 1;
		}
		//bla bla bla code
	}
}
