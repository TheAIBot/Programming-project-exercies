#ifndef _BALL_H_
#define _BALL_H_

#include "ansi.h"

struct TBall
{	
	struct TVector position;
	struct TVector momentum;
	long velocity;
	long angle;
	char color;
};

void initBall(struct TBall *vBall,int x, int y, char skin,long angle,long velocity);
void drawBall(int x, int y);
void clearBall(int x, int y);

#endif