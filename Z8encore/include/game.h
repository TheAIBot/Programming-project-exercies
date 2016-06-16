#ifndef _GAME_H_
#define _GAME_H_

#include "striker.h"
#include "ball.h"
#include "boss.h"
#include "timer.h"

#define GAME_NAME "Brick Breaker"

struct TGame
{
	int gameSizeX;
	int gameSizeY;
	struct TBall balls[6];
	struct TBoss boss;
	struct TBrick bricks[40];
	struct TTimer timer;
	char brickCount;
	struct TStriker striker;
	int lives;
	int strikerLength;
	int newBall;
	int difficulty;
	int score;
};

void initGame(struct TGame *game, int gameSizeX, int gameSizeY, int strikerSize, int updateFrequency);
void runGame(struct TGame *game);

#endif