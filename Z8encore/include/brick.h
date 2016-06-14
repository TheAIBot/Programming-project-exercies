#ifndef _BRICK_H_
#define _BRICK_H_

#include "ansi.h"

#define HEALTH_BITS 0x3f
#define DROP_BIT = 7
#define INDESTRUCTIBLE_BIT 6
#define BRICK_WIDTH_BITS 0x0f
#define BRICK_HEIGHT_BITS 4

struct TBrick
{
	char x;
	char y;
	char size;//height 0000, width 0000
	char health; // drop 0, indestructible 0, health 000000
	//struct TVector motion;
};



void handleBrickCollisions(struct TBrick bricks[], struct TBall *ball, int brickCount);
void initBricks(struct TBrick bricks[], int brickCount);

#endif