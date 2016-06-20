#ifndef _GAME_H_
#define _GAME_H_

#include "striker.h"
#include "ball.h"
#include "boss.h"
#include "timer.h"

#define GAME_NAME "Brick Breaker   "
#define DEFAULT_LIVES 12
#define LEVEL_COUNT 3
#define MAX_BRICK_COUNT 40
#define MAX_BALL_COUNT 6
#define STRIKER_LENGTH 21
#define GAME_SIZE_X 100
#define GAME_SIZE_Y 40
#define GAME_UPDATE_RATE 30

struct TGame
{
	int gameSizeX;
	int gameSizeY;
	struct TBall balls[MAX_BALL_COUNT];
	struct TBoss boss;
	struct TBrick bricks[MAX_BRICK_COUNT];
	struct TTimer timer;
	int brickCount;
	struct TStriker striker;
	int lives;
	int strikerLength;
	char newBall;
	char difficulty;
	unsigned int score;
	char level;
	char levelWon;
};

void initGame(struct TGame *game);
void runGame(struct TGame *game);

#endif