#ifndef _GAME_H_
#define _GAME_H_

#include "striker.h"
#include "ball.h"
#include "boss.h"
#include "timer.h"

#define GAME_NAME "Brick Breaker"
#define DEFAULT_LIVES 10
#define LEVEL_COUNT 3

struct TGame
{
	char gameSizeX;
	char gameSizeY;
	struct TBall balls[6];
	struct TBoss boss;
	struct TBrick bricks[40];
	struct TTimer timer;
	char brickCount;
	struct TStriker striker;
	char lives;
	char strikerLength;
	char newBall;
	char difficulty;
	int score;
	char level;
	char levelWon;
};

void initGame(struct TGame *game, int gameSizeX, int gameSizeY, int strikerSize, int updateFrequency);
void runGame(struct TGame *game);

#endif