#include <eZ8.h>
#include <sio.h>
#include "boss.h"
#include "random.h"
#include "ball.h"
#include "brick.h"
#include "color.h"
#include "fixedmath.h"
#include "game.h"
#include "sound.h"

//score given to the player when the boss dies
#define SCORE_KILL_BOSS 2000

//draw all the bricks the boss is made out off
void drawBoss(struct TBoss *boss)
{
	if(USE_BOSS(boss->data))
	{
		char i;
		for(i = 0; i < BOSS_BRICK_COUNT; i++)
		{
			drawBrick(&boss->bricks[i]);
		}
	}
}

//clear all the bricks the boss is made out off
void clearBoss(struct TBoss *boss)
{
	char i;
	for(i = 0; i < BOSS_BRICK_COUNT; i++)
	{
		clearBrick(&boss->bricks[i]);
	}
}

void initBoss(struct TBoss *boss, struct TBrick bossBricks[BOSS_BRICK_COUNT], char startShotX, char startShotY, char movement, char useBoss)
{
	//only init boss if it's being used
	if(useBoss)
	{
		int i;
		//put all the bricks into the brick array inside the boss
		for(i = 0; i < BOSS_BRICK_COUNT; i++)
		{
			boss->bricks[i] = bossBricks[i];
		}
		boss->startShotX = startShotX;
		boss->startShotY = startShotY;
		boss->movement = movement;
		boss->currentMovement = boss->movement;
		//set the USE_BOSS bit to 1
		boss->data |= USE_BOSS_MASK;
	}
	else
	{
		//The boss isn't being used then set the USE_BOSS bit to 0
		boss->data &= ~USE_BOSS_MASK; // set USE_BOSS bit to 0
	}
}

//Moves boss bricks acording to the bosses movement specifications
void moveBricks(struct TBoss *boss)
{
	int i;
	char ticksUntilMove = TICKS_UNTIL_MOVE(boss->currentMovement);
	char xMoved = X_MOVED(boss->currentMovement);
	
	ticksUntilMove--;
	//if it's time to move
	if(ticksUntilMove == 0)
	{
		char invertDirection = 0;
		xMoved--;
		//if it's time to change direction
		if(xMoved == 0)
		{
			invertDirection = 1;
			//reset value
			xMoved = X_MOVED(boss->movement);
		}
		//reset value
		ticksUntilMove = TICKS_UNTIL_MOVE(boss->movement);

		for(i = 0; i < BOSS_BRICK_COUNT; i++)
		{
			struct TBrick *brick  = &boss->bricks[i];
			//only move bricks that has health and are moving
			if(HEALTH(brick->data) > 0 &&
			   IS_MOVING(brick->data))
			{
				int oldX = brick->x;
				setBrickColor(brick);
				//either move the brick left or right depending on the direction of the brick
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
					//invert the bricks direction
					brick->data = brick->data ^ DIRECTION_MASK;
				}
			}
		}
	}
	//put updated values back into currentMovement
	boss->currentMovement = (ticksUntilMove << TICKS_UNTIL_MOVE_BIT_SHIFT) | xMoved;
}

//fires a ball from the boss
void shoot(struct TBoss *boss, struct TBall shots[MAX_BALL_COUNT])
{
	int i;
	//find a ball that is dead
	for(i = 0; i < MAX_BALL_COUNT; i++)
	{
		if(IS_ALIVE(shots[i].data) == 0)
		{
			//shoot the ball from the boss and then leave the method as only one shot should be fired
			initBall(&shots[i], boss->startShotX, boss->startShotY, FCOLOR_RED, RANDOM(190, 350), TO_FIX14(1) >> 2, 1); 
			break;
		}
	}
}

//Determines wether the boss should shoot
//returns 1 if it's randomly determined that it should shoot and there is a ball dead, otherwise it returns false
char shouldShoot(struct TBall shots[MAX_BALL_COUNT], char difficulty)
{
	//depending on the difficulty the chance of a shot should change
	if((RANDOM(0, 200 - 20 * (int)difficulty) == 0))
	{
		int i;
		//return 1 if there is a dead ball
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

//returns 1 if the boss is dead and 0 if it's not
char isBossDead(struct TBoss *boss)
{
	//the boss is dead if it's not used
	if(USE_BOSS(boss->data))
	{
		int i;
		//the boss is dead if all its bricks that aren't indestructible are dead
		for(i = 0; i < BOSS_BRICK_COUNT; i++)
		{
			if(IS_ALIVE(boss->bricks[i].data) && 
			   IS_INDESTRUCTIBLE(boss->bricks[i].data) == 0)
			{
				return 0;
			}
		}
	}
	return 1;
}

//updates the boss bricks and has a chance of shooting
void updateBoss(struct TBoss *boss, struct TBall shots[MAX_BALL_COUNT], unsigned int *score, char difficulty)
{
	if(USE_BOSS(boss->data))
	{
		moveBricks(boss);
		if(shouldShoot(shots, difficulty))
		{
			shoot(boss, shots);
		}
		//if none of the bricks with health that aren't indestructible are alive then the boss is dead
		if(handleBrickCollisions(boss->bricks, shots, BOSS_BRICK_COUNT, score) == 1)
		{
			//the boss is dead so award the player with some points
			*score += SCORE_KILL_BOSS;
			clearBoss(boss);
			//set the bit USE_BOSS to 0 as the boss isn't needed anymore
			boss->data = boss->data ^ USE_BOSS_MASK;
			playBossDeathSound();
		}
	}
}
