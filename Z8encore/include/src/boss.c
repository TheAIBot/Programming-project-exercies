#include <eZ8.h>
#include <sio.h>
#include "boss.h"
#include "random.h"
#include "ball.h"
#include "brick.h"
#include "color.h"
#include "fixedmath.h"

#define sX (60)
#define sY (20)
#define bS (0x26)
#define hn (1)
#define hI (hn | INDESTRUCTIBLE_BIT)
#define hIM (hI | MOVING_BIT)

#define brickHeight 2
#define brickWidth 6
#define bricksize 0x26



void initBoss(struct TBoss *boss)
{
    struct TBrick kkk[16] = 
	{
		//{(1) * 1, (1) * 15, 1, 3},

		{sX + 0, sY + 0, bS, hI},{sX + 2, sY + 0, bS, hI},{sX + 3, sY + 0, bS, hI},{sX + 5, sY + 0, bS, hI},
		{sX + 1, sY + 1, bS, hI},{sX + 2, sY + 1, bS, hI},{sX + 3, sY + 1, bS, hI}, {sX + 4, sY + 1, bS, hI},
		{sX + 0, sY + 2, bS, hI},{sX + 1, sY + 2, bS, hI},{sX + 2, sY + 2, bS, hn}, {sX + 3, sY + 2, bS, hn},{sX + 4, sY + 2, bS, hI},{sX + 5, sY + 2, bS, hI},
		{sX + 1, sY + 3, bS, hIM | DIRECTION_BIT},{sX + 4, sY + 3, bS, hIM},
	};
	int i;
	for(i = 0; i < 16; i++)
	{
		boss->bricks[i] = kkk[i];
	}
	boss->startShotX = sX + 2;
	boss->startShotY = sY + 3;
	boss->movement = (0xf0 << X_AXIS_MOVEMENT_BIT) | (bS & BRICK_WIDTH_BITS); // x axis 0000, x axis moves 0000
	boss->currentMovement = boss->movement;
}

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
				if(DIRECTION(brick->data))
				{
					brick->x++;
				}
				else
				{
					brick->x--;
				}
				updateBrickPosition(oldX, brick->y,  brick->x, brick->y, BRICK_HEIGHT(brick->size));
				if(invertDirection)
				{
					brick->data = brick->data ^ DIRECTION_BIT_SELECT; // inverts Direction with xor
				}
			}
		}
	}
	boss->currentMovement = (xMovement << X_AXIS_MOVEMENT_BIT) | xMoved;
}

void shoot(struct TBoss *boss, struct TBall shots[6])
{
	int i;
	for(i = 0; i < 6; i++)
	{
		if(ALIVE(shots[i].data) == 0)
		{
			//void initBall(struct TBall *vBall,int x, int y, char color, int angle, long velocity)
			initBall(&shots[i], boss->startShotX, boss->startShotY, FCOLOR_RED, RANDOM(225, 315), TO_FIX14(1) >> 2); 
		}
	}
}

char shouldShoot(struct TBall shots[6])
{
	if((RANDOM(0, 100) == 0))
	{
		int i;
		for(i = 0; i < 6; i++)
		{
			if(ALIVE(shots[i].data) == 0)
			{
				return 1;
			}
		}
	}
	return 0;
}

void updateBoss(struct TBoss *boss, struct TBall shots[6])
{
	handleBrickCollisions(boss->bricks, shots, 16);
	moveBricks(boss);
	if(shouldShoot(shots))
	{
		shoot(boss, shots);
	}
}
