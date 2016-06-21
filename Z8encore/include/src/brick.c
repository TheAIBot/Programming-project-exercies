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

//the character the brick is drawn with
#define BRICK_STYLE 219
#define EMPTY_STYLE ' '
//score given to the player when a brick is killed
#define SCORE_KILL_BRICK 50


//get the color of the brick
//returns the color of the brick which depends of the health of the brick and wether it's indestructible or not
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

//redraws the brick one position to the left
void updateBrickPositionLeft(int oldX, int oldY, int newX, int newY, char brickHeight, char brickWidth)
{
	char i;
	for(i = 0; i < brickHeight; i++)
	{
		//goto(oX,oY) write(EMPY_CHAR) goto(nX,nY) write(BALL_STYLE)
		printf("%c[%d;%dH%c%c[%d;%dH%c", ESC, oldY + i, oldX + brickWidth - 1, EMPTY_STYLE, ESC, newY + i, newX, BRICK_STYLE);
	}
}

//redraws the brick one position to the right
void updateBrickPositionRight(int oldX, int oldY, int newX, int newY, char brickHeight, char brickWidth)
{
	char i;
	for(i = 0; i < brickHeight; i++)
	{
		//goto(oX,oY) write(EMPY_CHAR) goto(nX,nY) write(BALL_STYLE)
		printf("%c[%d;%dH%c%c[%d;%dH%c", ESC, oldY + i, oldX, EMPTY_STYLE, ESC, newY + i, newX + brickWidth - 1, BRICK_STYLE);
	}
}

//sets the foreground color to the bricks color
void setBrickColor(struct TBrick *brick)
{
	fgcolor(getBrickColor(brick->data));
}

//draw a brick at its position which a specific chararcter
void brickdraw(struct TBrick *brick, char c)
{
	char brickSizeWidth = BRICK_WIDTH((brick->size));
	char brickSizeHeight = BRICK_HEIGHT((brick->size));
	char x;
	char y;
	setBrickColor(brick);
	//draw every row of the brick
	for(y = 0; y < brickSizeHeight; y++)
	{
		//goto row
		gotoxy(brick->x, brick->y + y);
		//draw every column
		for(x = 0; x < brickSizeWidth; x++)
		{
			printf("%c", c);
		}
	}
}

//draw the brick with the brick style
void drawBrick(struct TBrick *brick)
{
	brickdraw(brick, BRICK_STYLE);
}

//remove the brick from the screen by drawing over it with spaces
void clearBrick(struct TBrick *brick)
{
	brickdraw(brick, EMPTY_STYLE);
}

//handles ball collision with a bricks corner
void handleBrickCornerCollision(struct TBall *ball, int minAngleHorizontal, int maxAngleHorizontal, int illigalMinAngleVeritcal, int illigalMaxAngleVeritcal)
{
	if(ball->angle >= minAngleHorizontal && ball->angle <= maxAngleHorizontal)
	{
		ball->angle = bounceHorizontal(ball->angle);
	}
	else if(!(ball->angle >= illigalMinAngleVeritcal && ball->angle <= illigalMaxAngleVeritcal))
	{
		ball->angle = bounceVertical(ball->angle);
	}
}

//handles all collisions between balls and bricks and changes the life of bricks and the angle of balls when they hit
//returns 1 if atleast one brick has health and isn't indestructible otherwise returns 0
char handleBrickCollisions(struct TBrick bricks[], struct TBall balls[MAX_BALL_COUNT], int brickCount, unsigned int *score)
{
	int brickIndex;
	int ballIndex;
	int anyBricksAlive = 0;
	for(ballIndex = 0; ballIndex < MAX_BALL_COUNT; ballIndex++)
	{
		if(IS_ALIVE(balls[ballIndex].data))
		{
			//for all balls that are alive
			struct TBall *ball = &balls[ballIndex];
			for(brickIndex = 0; brickIndex < brickCount; brickIndex++)
			{
				if(HEALTH(bricks[brickIndex].data) > 0)
				{
					//for all bricks that are alive
					struct TBrick *brick = &bricks[brickIndex];
					char ballX = FIX14_TO_INT(ball->position.x);
					char ballY = FIX14_TO_INT(ball->position.y);
					char brickX = brick->x;
					char brickY = brick->y;
					char brickSizeWidth = BRICK_WIDTH((brick->size));
					char brickSizeHeight = BRICK_HEIGHT((brick->size));
					//this value determines wether the brick was hit by the ball or not
					char hit = 0;
					if(!IS_INDESTRUCTIBLE(brick->data))
					{
						anyBricksAlive = 1; // atleast one brick is alive
					}
					//maybe hit brick either on the top or bottom
					if(ballX >= brickX && 
					    ballX < brickX + brickSizeWidth)
					{
						//hit brick on top
						if(ballY == brickY - 1 && ball->angle > 180 && ball->angle < 360)
						{
							hit = 1;
							ball->angle = bounceHorizontal(ball->angle);
						}
						//hit brick on bottom
						else if(ballY == brickY + brickSizeHeight && ball->angle > 0 && ball->angle < 180)
						{
							hit = 1;
							ball->angle = bounceHorizontal(ball->angle);
						}
					}
					//maybe hit brick either on the left or right
					else if(ballY >= brickY && 
					        ballY < brickY + brickSizeHeight)
					{
						//hit brick on the left
						if(ballX == brickX - 1 && (ball->angle < 90 || ball->angle > 270))
						{
							hit = 1;
							ball->angle = bounceVertical(ball->angle);
						}
						//hit brick on the right
						else if(ballX == brickX + brickSizeWidth && ball->angle > 90 && ball->angle < 270)
						{
							hit = 1;
							ball->angle = bounceVertical(ball->angle);
						}
					}
					//hit top left corner
					else if(ballX == brickX - 1 &&
					   		ballY == brickY - 1)
					{
						hit = 1;
						handleBrickCornerCollision(ball, 180, 270, 90, 180);
					}
					//hit top right corner
					else if(ballX == brickX + brickSizeWidth &&
					   		ballY == brickY - 1)
					{
						hit = 1;
						handleBrickCornerCollision(ball, 270, 360, 0, 90);
					}
					//hit bottom left corner
					else if(ballX == brickX - 1 &&
					   		ballY == brickY + brickSizeHeight)
					{
						hit = 1;
						handleBrickCornerCollision(ball, 90, 180, 180, 270);
					}
					//hit bottom right corner
					else if(ballX == brickX + brickSizeWidth &&
					   		ballY == brickY + brickSizeHeight)
					{
						hit = 1;
						handleBrickCornerCollision(ball, 0, 90, 270, 360);
					}
					//if the brick was hit
					if(hit == 1)
					{
						if(!IS_INDESTRUCTIBLE(brick->data))
						{
							//take one life
							//only bricks with life can reach this line so a overflow can't happen by subtracting
							//which could otherwise corrupt the other bits in data
							brick->data--;
							//if the brick is dead
							if(HEALTH(brick->data) == 0)
							{
								//give score to the player
								*score += SCORE_KILL_BRICK;
								clearBrick(brick);
								playDeathBrickSound();
							}
							//else redraw the brick with the bricks new color
							else
							{
								drawBrick(brick);
								playBounceSound(HEALTH(brick->data));
							}
						}
						else
						{
							playIndestructibleBrickSound();
						}
					}
				}
			}
		}
	}
	/*
	if(brickCount > 0 && anyBricksAlive == 0)
	{
		return 1;
	}
	return 0;
	*/
	return anyBricksAlive;
}

//init all bricks by drawing them all on the screen
void drawBricks(struct TBrick bricks[], int brickCount)
{
	int brickIndex;
	for(brickIndex = 0; brickIndex < brickCount; brickIndex++)
	{
		drawBrick(&bricks[brickIndex]);
	}
}
