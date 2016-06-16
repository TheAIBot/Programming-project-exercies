#ifndef _BRICK_H_
#define _BRICK_H_

#include "ansi.h"

#define HEALTH_BITS 0x0f
#define DROP_BIT 7
#define INDESTRUCTIBLE_BIT 6
#define MOVING_BIT 5
#define DIRECTION_BIT 4
#define DIRECTION_BIT_SELECT 0x10
#define BRICK_WIDTH_BITS 0x0f
#define BRICK_HEIGHT_BITS 4

#define BRICK_WIDTH(size) (size & BRICK_WIDTH_BITS)
#define BRICK_HEIGHT(size) (size >> BRICK_HEIGHT_BITS)
#define HEALTH(data) (data & HEALTH_BITS)
#define IS_INDESTRUCTIBLE(data) ((data & 0x40) >> INDESTRUCTIBLE_BIT) 
#define IS_MOVING(data) ((data & 0x20) >> MOVING_BIT)
#define DIRECTION(data) ((data & DIRECTION_BIT_SELECT) >> DIRECTION_BIT)

struct TBrick
{
	char x;
	char y;
	char size;//height 0000, width 0000
	char data; // drop 0, indestructible 0, is moving 0, direction 0, health 0000
	//struct TVector motion;
};



void handleBrickCollisions(struct TBrick bricks[], struct TBall balls[6], int brickCount);
void initBricks(struct TBrick bricks[], int brickCount);
void setBrickColor(struct TBrick *brick);
void updateBrickPositionRight(int oldX, int oldY, int newX, int newY, char brickHeight, char brickWidth);
void updateBrickPositionLeft(int oldX, int oldY, int newX, int newY, char brickHeight, char brickWidth);
void drawBrick(struct TBrick *brick);

#endif