#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "brick.h"
#include "ansi.h"
#include "color.h"
#include "ball.h"

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

void handleBrickCollisions(struct TBrick bricks[], struct TBall *ball)
{
	int brickIndex;
	int brickLength = sizeof(bricks) / sizeof(bricks[0]);
	for(brickIndex = 0; brickIndex < brickLength; brickIndex++)
	{
		if(bricks[brickIndex].health > 0)
		{
			struct TBrick *brick = &bricks[brickIndex];
			//block of death
			if(((ball->position.x >= brick->position.x && 
			     ball->position.x <= brick->position.x) &&
				(ball->position.y == brick->position.y + 1 || 
				 ball->position.y == brick->position.y - 1) ||
			    (ball->position.y >= brick->position.y && 
			     ball->position.y <= brick->position.y) &&
				(ball->position.x == brick->position.x + 1 || 
				 ball->position.x == brick->position.x - 1)))
			{
				brick->health--;
				ball->angle = 360 - ball->angle;
				if(brick->health <= 0)
				{
					clearBrick(brick);
				}
			}
		}
	}
}

void initBricks(struct TBrick bricks[])
{
	int brickIndex;
	int brickLength = sizeof(bricks) / sizeof(bricks[0]);
	for(brickIndex = 0; brickIndex < brickLength; brickIndex++)
	{
		drawBrick(&bricks[brickIndex]);
	}
}
