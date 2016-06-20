#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "brick.h"
#include "ansi.h"
#include "color.h"
#include "ball.h"
#include "fixedmath.h"
#include "bounce.h"
#include "sound.h"
#include "game.h"

#define BRICK_STYLE 219
#define EMPTY_STYLE ' '

char getBrickColor(char data)
{
  	char health = HEALTH(data);
	if(IS_INDESTRUCTIBLE(data))
	{
		return FCOLOR_LIGHT_GRAY;
	}
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

void updateBrickPositionLeft(int oldX, int oldY, int newX, int newY, char brickHeight, char brickWidth)
{
	char i;
	for(i = 0; i < brickHeight; i++)
	{
		//goto(oX,oY) write(EMPY_CHAR) goto(nX,nY) write(BALL_STYLE)
		printf("%c[%d;%dH%c%c[%d;%dH%c", ESC, oldY + i, oldX + brickWidth - 1, EMPTY_STYLE, ESC, newY + i, newX, BRICK_STYLE);
	}
}

void updateBrickPositionRight(int oldX, int oldY, int newX, int newY, char brickHeight, char brickWidth)
{
	char i;
	for(i = 0; i < brickHeight; i++)
	{
		//goto(oX,oY) write(EMPY_CHAR) goto(nX,nY) write(BALL_STYLE)
		printf("%c[%d;%dH%c%c[%d;%dH%c", ESC, oldY + i, oldX, EMPTY_STYLE, ESC, newY + i, newX + brickWidth - 1, BRICK_STYLE);
	}
}

void setBrickColor(struct TBrick *brick)
{
	fgcolor(getBrickColor(brick->data));
}

void brickdraw(struct TBrick *brick, char c)
{
	char brickSizeWidth = BRICK_WIDTH((brick->size));
	char brickSizeHeight = BRICK_HEIGHT((brick->size));
	char x;
	char y;
	setBrickColor(brick);
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

void handleBrickCornerCollision(struct TBall *ball, int minAngle, int maxAngle)
{
	if(ball->angle >= minAngle && ball->angle <= maxAngle)
	{
		ball->angle = bounceHorizontal(ball->angle);
	}
	else
	{
		ball->angle = bounceVertical(ball->angle);
	}
}

char handleBrickCollisions(struct TBrick bricks[], struct TBall balls[MAX_BALL_COUNT], int brickCount)
{
	int brickIndex;
	int ballIndex;
	int anyBricksAlive = 0;
	for(ballIndex = 0; ballIndex < MAX_BALL_COUNT; ballIndex++)
	{
		if(IS_ALIVE(balls[ballIndex].data))
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
					if(!IS_INDESTRUCTIBLE(brick->data))
					{
						anyBricksAlive = 1; // atleast one brick is alive
					}
					if(ballX >= brickX && 
					    ballX < brickX + brickSizeWidth)
					{
						if(ballY == brickY - 1 && ball->angle > 180 && ball->angle < 360)
						{
							hit = 1;
							ball->angle = bounceHorizontal(ball->angle);
						}
						else if(ballY == brickY + brickSizeHeight && ball->angle > 0 && ball->angle < 180)
						{
							hit = 1;
							ball->angle = bounceHorizontal(ball->angle);
						}
					}
					else if(ballY >= brickY && 
					        ballY < brickY + brickSizeHeight)
					{
						if(ballX == brickX - 1 && (ball->angle < 90 || ball->angle > 270))
						{
							hit = 1;
							ball->angle = bounceVertical(ball->angle);
						}
						else if(ballX == brickX + brickSizeWidth && ball->angle > 90 && ball->angle < 270)
						{
							hit = 1;
							ball->angle = bounceVertical(ball->angle);
						}
					}
					/*if((ballX >= brickX && 
					    ballX < brickX + brickSizeWidth ) &&
					   (ballY <= brickY + brickSizeHeight && 
						ballY >= brickY - 1))
					{
						hit = 1;
						ball->angle = bounceHorizontal(ball->angle);
					}
					else if((ballY >= brickY && 
					         ballY < brickY + brickSizeHeight) &&
						 	(ballX <= brickX + brickSizeWidth && 
						  	 ballX >= brickX - 1))
					{
						hit = 1;
						ball->angle = bounceVertical(ball->angle);
					}
					*/
					else if(ballX == brickX - 1 &&
					   		ballY == brickY - 1)
					{
						hit = 1;
						handleBrickCornerCollision(ball, 180, 270);
					}
					else if(ballX == brickX + brickSizeWidth &&
					   		ballY == brickY - 1)
					{
						hit = 1;
						handleBrickCornerCollision(ball, 270, 360);
					}
					else if(ballX == brickX - 1 &&
					   		ballY == brickY + brickSizeHeight)
					{
						hit = 1;
						handleBrickCornerCollision(ball, 90, 180);
					}
					else if(ballX == brickX + brickSizeWidth &&
					   		ballY == brickY + brickSizeHeight)
					{
						hit = 1;
						handleBrickCornerCollision(ball, 0, 90);
					}
					if(hit == 1)
					{
						if(!IS_INDESTRUCTIBLE(brick->data))
						{
							brick->data--;
							if(HEALTH(brick->data) <= 0)
							{
								clearBrick(brick);
								playDeathBrickSound();
							}
							else
							{
								drawBrick(brick);
								playBounceSound();
							}
						}
					}
				}
			}
		}
	}
	if(brickCount > 0 && anyBricksAlive == 0)
	{
		return 1;
	}
	return 0;
}

void initBricks(struct TBrick bricks[], int brickCount)
{
	int brickIndex;
	for(brickIndex = 0; brickIndex < brickCount; brickIndex++)
	{
		drawBrick(&bricks[brickIndex]);
	}
}
