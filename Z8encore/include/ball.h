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
	char color;
};

void initBall(struct TBall *vBall,int x, int y, char color, int angle, int velocity);
void drawBall(long x, long y);
void clearBall(long x, long y);
char isBallDead(struct TBall *vball, struct TStriker *vStriker, int gameSize);
void impact(struct TBall *vball, struct TStriker *vStriker, int gameSize,  int angle, int size);
void updateBall(struct TBall *vball);

#endif