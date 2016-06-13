#ifndef _STRIKER_H_
#define _STRIKER_H_

#include "ansi.h"
#include "ball.h"

struct TStriker
{
	struct TVector position;
	char length;
};

void initStriker(struct TStriker *vStriker,int x, int y,int l);
void clearStriker(int x, int y, int length);
void moveStrikerLeft(struct TStriker *vStriker);
void moveStrikerRight(struct TStriker *vStriker);
void moveStriker(struct TStriker *vStriker, int gameSize, char rightButtonPressed, char leftButtonPressed);
void bounceStriker(struct TStriker *vStriker, struct TBall *vball, int gameSize);
#endif