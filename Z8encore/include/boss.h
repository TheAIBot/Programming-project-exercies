#ifndef _BOSS_H_
#define _BOSS_H_

#define X_AXIS_MOVEMENT_BIT 4
#define X_AXIS_MOVEMENT(movement) ((movement >> X_AXIS_MOVEMENT_BIT) & 0x0f)
#define X_MOVED(movement) (movement & 0x0f)

#include "brick.h"

struct TBoss
{
	struct TBrick bricks[16];
	char movement; // x axis 0000, x axis moves 0000
	char currentMovement; // x axis 0000, x axis movement 0000 // alle brick der kan bevæge sig skal have den samme størrlse
	int startShotX;
	int startShotY;
};

void initBoss(struct TBoss *boss);
void updateBoss(struct TBoss *boss, struct TBall shots[6]);


#endif