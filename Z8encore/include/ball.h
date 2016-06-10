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
	long velocity;
	long angle;
	char color;
};

void initBall(struct TBall *vBall,int x, int y, char color,long angle,long velocity);
void drawBall(int x, int y);
void clearBall(int x, int y);
char isBallDead(struct TBall *vball, struct TStriker *vStriker, int gameSize);
void impact(struct TBall *vball, struct TStriker *vStriker, int gameSize,  int angle, int size);
void updateBall(struct TBall *vball);

#endif