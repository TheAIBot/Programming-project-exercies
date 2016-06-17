#ifndef _BOSS_H_
#define _BOSS_H_


#define USE_BOSS_MASK 0x01
#define X_AXIS_MOVEMENT_BIT_SHIFT 4
#define X_MOVED_MASK 0x0f

#define X_AXIS_MOVEMENT(movement) ((movement >> X_AXIS_MOVEMENT_BIT_SHIFT) & 0x0f)
#define X_MOVED(movement) (movement & X_MOVED_MASK)
#define USE_BOSS(data) (data & USE_BOSS_MASK)

#include "brick.h"

struct TBoss
{
	struct TBrick bricks[16];
	char movement; // x axis 0000, x axis moves 0000
	char currentMovement; // x axis 0000, x axis movement 0000 // alle brick der kan bevæge sig skal have den samme størrlse
	int startShotX;
	int startShotY;
	char data;
};

void initBoss(struct TBoss *boss, char useBoss);
void drawBoss(struct TBoss *boss);
void updateBoss(struct TBoss *boss, struct TBall shots[6]);


#endif