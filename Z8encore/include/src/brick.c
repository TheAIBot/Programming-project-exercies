#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "brick.h"
#include "ansi.h"
#include "color.h"
#include "ball.h"
#include "fixedmath.h"

#define BRICK_STYLE 219
#define EMPTY_STYLE ' '

char getBrickColor(char data)
{
  	char health = HEALTH(data);
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

void updateBrickPosition(int oldX, int oldY, int newX, int newY, char brickHeight)
{
	char i;
	for(i = 0; i < brickHeight; i++)
	{
		//goto(oX,oY) write(EMPY_CHAR) goto(nX,nY) write(BALL_STYLE)
		printf("%c[%d;%dH%c%c[%d;%dH%c", ESC, oldY + i, oldX, EMPTY_STYLE, ESC, newY + i, newX, BRICK_STYLE);
	}
}

void brickdraw(struct TBrick *brick, char c)
{
	char brickSizeWidth = BRICK_WIDTH((brick->size));
	char brickSizeHeight = BRICK_HEIGHT((brick->size));
	char x;
	char y;
	fgcolor(getBrickColor(brick->data));
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

void handleBrickCollisions(struct TBrick bricks[], struct TBall balls[6], int brickCount)
{
	int brickIndex;
	int ballIndex;
	for(ballIndex = 0; ballIndex < 6; ballIndex++)
	{
		if(ALIVE(balls[ballIndex].data))
		{
			struct TBall *ball = &balls[ballIndex];
			for(brickIndex = 0; brickIndex < brickCount; brickIndex++)
			{
				if(HEALTH(bricks[brickIndex].data) > 0)
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
						if(!INDESTRUCTIBLE(brick->data))
						{
							brick->data--;
							if(HEALTH(brick->data) <= 0)
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
