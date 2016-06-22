#ifndef _STRIKER_H_
#define _STRIKER_H_

#include "ansi.h"
#include "ball.h"

/*
TStriker:
This is the entity that the player controls in the game.
It's able to bounce balls off it at an angle depending on where the ball its the striker.


position:
The x, y position of the middle of the striker.


length:
The length of the striker:

*/

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
void bounceStriker(struct TStriker *vStriker, struct TBall balls[]);
void moveStrikerPreShot(struct TBall *vball, struct TStriker *vStriker, int gameSizeX, char rightButtonPressed, char leftButtonPressed);
#endif