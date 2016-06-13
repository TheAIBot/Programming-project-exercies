#ifndef _BALL_H_
#define _BALL_H_

#include "ansi.h"
#include "striker.h"

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
	struct TPosition momentum;
	char color;
};

void initBall(struct TBall *vBall,int x, int y, char color, int angle, long velocity);
void drawBall(long x, long y);
void clearBall(long x, long y);
char isBallDead(struct TBall *vball, int gameSize);
void impact(struct TBall *vball, struct TStriker *vStriker, int gameSizeX, int gameSizeY);
void updateBall(struct TBall *vball);

#endif