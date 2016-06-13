#ifndef _GAME_H_
#define _GAME_H_

#include "striker.h"
#include "ball.h"

struct TGame
{
	int gameSize;
	struct TBall balls[5];
	struct TStriker striker;
	int deathCount;
	int newBall;
};

void initGame(struct TGame *game, int gameSize);
void updateGame(struct TGame *game);

#endif