#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "brick.h"
#include "ansi.h"
#include "color.h"
#include "ball.h"
#include "fixedmath.h"

#define BRICK_STYLE 219
#define EMPTY_STYLE ' '

char getBrickColor(int health)
{
	if(health < 1)
	{
		return FCOLOR_GREEN;
	}
	else if(health < 2)
	{
		return FCOLOR_YELLOW;
	}
	else
	{
		return FCOLOR_RED;
	}
}

void brickdraw(struct TBrick *brick, char c)
{
	int x;
	int y;
	fgcolor(getBrickColor(brick->health));
	for(y = 0; y < brick->size.y; y++)
	{
		gotoxy(brick->position.x, brick->position.y + y);
		for(x = 0; x < brick->size.x; x++)
		{
			printf("%c", c);
		}
	}
}

void drawBrick(struct TBrick *brick)
{
	brickdraw(brick, BRICK_STYLE);
}

void clearBrick(struct TBrick *brick)
{
	brickdraw(brick, EMPTY_STYLE);
}

void handleBrickCollisions(struct TBrick bricks[], struct TBall *ball, int brickCount)
{
	int brickIndex;
	for(brickIndex = 0; brickIndex < brickCount; brickIndex++)
	{
		if(bricks[brickIndex].health > 0)
		{
			struct TBrick *brick = &bricks[brickIndex];
			int ballX = FIX14_TO_INT(ball->position.x);
			int ballY = FIX14_TO_INT(ball->position.y);
			int brickX = brick->position.x;
			int brickY = brick->position.y;
			int brickSizeX = brick->size.x;
			int brickSizeY = brick->size.y;
			if((ballX >= brickX && 
			    ballX <= brickX + brickSizeX) &&
				 (ballY == brickY + brickSizeY || 
				  ballY == brickY - 1))
			{
				brick->health--;
				ball->angle = 360 - ball->angle;
				if(brick->health <= 0)
				{
					clearBrick(brick);
				}
			}

			if((ballY >= brickY && 
			    ballY <= brickY + brickSizeY) &&
				 (ballX == brickX + brickSizeX || 
				  ballX == brickX - 1))
			{
				brick->health--;
				ball->angle = 180 - ball->angle;
				if(ball->angle < 0)
				{
					ball->angle = ball->angle + 360;//find better solution
				}
				if(brick->health <= 0)
				{
					clearBrick(brick);
				}
			}
		}
	}
}

void initBricks(struct TBrick bricks[], int brickCount)
{
	int brickIndex;
	for(brickIndex = 0; brickIndex < brickCount; brickIndex++)
	{
		drawBrick(&bricks[brickIndex]);
	}
}
