#ifndef _BALL_H_
#define _BALL_H_

#include "ansi.h"
#include "striker.h"

#define COLOR_BITS (0x7f)
#define COLOR(data) (data & COLOR_BITS)
#define ALIVE_BIT (7)
#define IS_ALIVE(data) (data >> ALIVE_BIT)

struct TPosition
{
	long x;
	long y;
};

struct TBall
{	
	struct TPosition position;
	int velocity;
	int angle;
	char data;//ALIVE 0, COLOR 0000000
};

void initBall(struct TBall *vBall,int x, int y, char color, int angle, long velocity, char alive);
void updateBallDrawnPosition(long oldX, long oldY, long newX, long newY);
char isBallDead(struct TBall balls[6], int gameSize);
void impact(struct TBall balls[6], struct TStriker *vStriker, int gameSizeX, int gameSizeY);
void updateBalls(struct TBall balls[6]);
void setBallColor(struct TBall *ball);

#endif