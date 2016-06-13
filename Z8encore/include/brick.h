#ifndef _BRICK_H_
#define _BRICK_H_

#include "ansi.h"

struct TBrick
{
	struct TVector position;
	struct TVector size;
	char health;
	struct TVector motion;
	char dropChance;
};


void handleBrickCollisions(struct TBrick bricks[], struct TBall *ball);
void initBricks(struct TBrick bricks[]);

#endif