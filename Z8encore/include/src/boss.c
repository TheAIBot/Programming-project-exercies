#include <eZ8.h>
#include <sio.h>
#include "boss.h"
#include "random.h"
#include "ball.h"
#include "brick.h"
#include "color.h"
#include "fixedmath.h"
#include "game.h"

void drawBoss(struct TBoss *boss)
{
	if(USE_BOSS(boss->data))
	{
		char brickCount = sizeof(boss->bricks) / sizeof(boss->bricks[0]);
		char i;
		for(i = 0; i < brickCount; i++)
		{
			drawBrick(&boss->bricks[i]);
		}
	}
}


void clearBoss(struct TBoss *boss)
{
	char brickCount = sizeof(boss->bricks) / sizeof(boss->bricks[0]);
	char i;
	for(i = 0; i < brickCount; i++)
	{
		clearBrick(&boss->bricks[i]);
	}
}

void initBoss(struct TBoss *boss, struct TBrick bossBricks[BOSS_BRICK_COUNT], char startShotX, char startShotY, char movement, char useBoss)
{
	if(useBoss)
	{
		int i;
		for(i = 0; i < BOSS_BRICK_COUNT; i++)
		{
			boss->bricks[i] = bossBricks[i];
		}
		boss->startShotX = startShotX;
		boss->startShotY = startShotY;
		boss->movement = movement;
		boss->currentMovement = boss->movement;
		boss->data |= USE_BOSS_MASK;
	}
	else
	{
		boss->data &= ~USE_BOSS_MASK; // set USE_BOSS bit to 0
	}
}

//Moves boss bricks acording to the bosses movement specifications
void moveBricks(struct TBoss *boss)
{
	int i;
	char xMovement = X_AXIS_MOVEMENT(boss->currentMovement);
	char xMoved = X_MOVED(boss->currentMovement);

	xMovement--;
	if(xMovement == 0)
	{
		char invertDirection = 0;
		xMoved--;
		if(xMoved == 0)
		{
			invertDirection = 1;
			xMoved = X_MOVED(boss->movement);
		}
		xMovement = X_AXIS_MOVEMENT(boss->movement);

		for(i = 0; i < 16; i++)
		{
			struct TBrick *brick  = &(boss->bricks[i]);
			if(HEALTH(brick->data) > 0 &&
			   IS_MOVING(brick->data))
			{
				int oldX = brick->x;
				setBrickColor(brick);
				if(DIRECTION(brick->data))
				{
					brick->x++;
					updateBrickPositionRight(oldX, brick->y,  brick->x, brick->y, BRICK_HEIGHT(brick->size), BRICK_WIDTH(brick->size));
				}
				else
				{
					brick->x--;
					updateBrickPositionLeft(oldX, brick->y,  brick->x, brick->y, BRICK_HEIGHT(brick->size), BRICK_WIDTH(brick->size));
				}
				if(invertDirection)
				{
					brick->data = brick->data ^ DIRECTION_MASK; // inverts Direction with xor
				}
			}
		}
	}
	boss->currentMovement = (xMovement << X_AXIS_MOVEMENT_BIT_SHIFT) | xMoved;
}

void shoot(struct TBoss *boss, struct TBall shots[MAX_BALL_COUNT])
{
	int i;
	for(i = 0; i < MAX_BALL_COUNT; i++)
	{
		if(IS_ALIVE(shots[i].data) == 0)
		{
			//void initBall(struct TBall *vBall,int x, int y, char color, int angle, long velocity)
			initBall(&shots[i], boss->startShotX, boss->startShotY, FCOLOR_RED, RANDOM(190, 350), TO_FIX14(1) >> 2, 1); 
			break;
		}
	}
}

char shouldShoot(struct TBall shots[MAX_BALL_COUNT])
{
	if((RANDOM(0, 200) == 0))
	{
		int i;
		for(i = 0; i < MAX_BALL_COUNT; i++)
		{
			if(IS_ALIVE(shots[i].data) == 0)
			{
				return 1;
			}
		}
	}
	return 0;
}

void updateBoss(struct TBoss *boss, struct TBall shots[MAX_BALL_COUNT])
{
	if(USE_BOSS(boss->data))
	{
		if(handleBrickCollisions(boss->bricks, shots, BOSS_BRICK_COUNT) == 1)
		{
			clearBoss(boss);
			boss->data = boss->data ^ USE_BOSS_MASK;
		}
		moveBricks(boss);
		if(shouldShoot(shots))
		{
			shoot(boss, shots);
		}
	}
}
