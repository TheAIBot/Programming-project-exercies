#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "brick.h"
#include "ansi.h"
#include "color.h"
#include "ball.h"
#include "fixedmath.h"

#define BRICK_STYLE 219
#define EMPTY_STYLE ' '

#define BRICK_WIDTH(size) (size & BRICK_WIDTH_BITS)
#define BRICK_HEIGHT(size) (size >> BRICK_HEIGHT_BITS)
#define HEALTH(health) (health & HEALTH_BITS)
#define INDESTRUCTIBLE(health) ((health & 0x40) >> INDESTRUCTIBLE_BIT) 

char getBrickColor(char health)
{
  health = HEALTH(health);
	if(health == 1)
	{
		return FCOLOR_GREEN;
	}
	else if(health == 2)
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
	char brickSizeWidth = BRICK_WIDTH((brick->size));
	char brickSizeHeight = BRICK_HEIGHT((brick->size));
	char x;
	char y;
	fgcolor(getBrickColor(brick->health));
	for(y = 0; y < brickSizeHeight; y++)
	{
		gotoxy(brick->x, brick->y + y);
		for(x = 0; x < brickSizeWidth; x++)
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
			char ballX = FIX14_TO_INT(ball->position.x);
			char ballY = FIX14_TO_INT(ball->position.y);
			char brickX = brick->x;
			char brickY = brick->y;
			char brickSizeWidth = BRICK_WIDTH((brick->size));
			char brickSizeHeight = BRICK_HEIGHT((brick->size));
			char hit = 0;
			if((ballX >= brickX && 
			    ballX < brickX + brickSizeWidth) &&
			   (ballY == brickY + brickSizeHeight || 
				ballY == brickY - 1))
			{
				hit = 1;
				ball->angle = 360 - ball->angle;
			}
			else if((ballY >= brickY && 
			         ballY < brickY + brickSizeHeight) &&
				 	(ballX == brickX + brickSizeWidth || 
				  	 ballX == brickX - 1))
			{
				hit = 1;
				ball->angle = 180 - ball->angle;
				if(ball->angle < 0)
				{
					ball->angle = ball->angle + 360;//find better solution
				}
			}
			else if(ballX == brickX - 1 &&
			   ballY == brickY - 1)
			{
				hit = 1;
				if(ball->angle >= 180 && ball->angle <= 270)
				{
					ball->angle = 360 - ball->angle;
				}
				else
				{
					ball->angle = 180 - ball->angle;
					if(ball->angle < 0)
					{
						ball->angle = ball->angle + 360;//find better solution
					}
				}
			}
			else if(ballX == brickX + brickSizeWidth &&
			   		ballY == brickY - 1)
			{
				hit = 1;
				if(ball->angle >= 270 && ball->angle <= 360)
				{
					ball->angle = 360 - ball->angle;
				}
				else
				{
					ball->angle = 180 - ball->angle;
					if(ball->angle < 0)
					{
						ball->angle = ball->angle + 360;//find better solution
					}
				}
			}
			else if(ballX == brickX &&
			   		ballY == brickY + brickSizeHeight)
			{
				hit = 1;
				if(ball->angle >= 90 && ball->angle <= 180)
				{
					ball->angle = 360 - ball->angle;
				}
				else
				{
					ball->angle = 180 - ball->angle;
					if(ball->angle < 0)
					{
						ball->angle = ball->angle + 360;//find better solution
					}
				}
			}
			else if(ballX == brickX + brickSizeWidth &&
			   		ballY == brickY + brickSizeHeight)
			{
				hit = 1;
				if(ball->angle >= 0 && ball->angle <= 90)
				{
					ball->angle = 360 - ball->angle;
				}
				else
				{
					ball->angle = 180 - ball->angle;
					if(ball->angle < 0)
					{
						ball->angle = ball->angle + 360;//find better solution
					}
				}
			}
			if(hit == 1)
			{
				if(!INDESTRUCTIBLE(brick->health))
				{
					brick->health--;
					if(brick->health <= 0)
					{
						clearBrick(brick);
					}
					else
					{
						drawBrick(brick);
					}
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
