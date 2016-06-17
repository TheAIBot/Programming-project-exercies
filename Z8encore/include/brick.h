#ifndef _BRICK_H_
#define _BRICK_H_

#include "ansi.h"

#define HEALTH_MASK 0x0f
#define DROP_BIT_SHIFT 7
#define INDESTRUCTIBLE_BIT_SHIFT 6
#define INDESTRUCTIBLE_MASK 0x40
#define MOVING_BIT_SHIFT 5
#define MOVING_MASK 0x20
#define DIRECTION_BIT_SHIFT 4
#define DIRECTION_MASK 0x10
#define BRICK_WIDTH_MASK 0x0f
#define BRICK_HEIGHT_BIT_SHIFT 4

#define BRICK_WIDTH(size)        (size & BRICK_WIDTH_MASK)
#define BRICK_HEIGHT(size)       (size >> BRICK_HEIGHT_BIT_SHIFT)
#define HEALTH(data) 			 (data & HEALTH_MASK)
#define IS_INDESTRUCTIBLE(data) ((data & INDESTRUCTIBLE_MASK) >> INDESTRUCTIBLE_BIT_SHIFT) 
#define IS_MOVING(data)         ((data & MOVING_MASK) >> MOVING_BIT_SHIFT)
#define DIRECTION(data)         ((data & DIRECTION_MASK) >> DIRECTION_BIT_SHIFT)
#define MAKE_SIZE(height, width)((height << BRICK_HEIGHT_BIT_SHIFT) | width)

struct TBrick
{
	char x;
	char y;
	//can minimum be a 2x2 brick
	char size;//height 0000, width 0000
	char data; // drop 0, indestructible 0, is moving 0, direction 0, health 0000
};



char handleBrickCollisions(struct TBrick bricks[], struct TBall balls[6], int brickCount);
void initBricks(struct TBrick bricks[], int brickCount);
void setBrickColor(struct TBrick *brick);
void updateBrickPositionRight(int oldX, int oldY, int newX, int newY, char brickHeight, char brickWidth);
void updateBrickPositionLeft(int oldX, int oldY, int newX, int newY, char brickHeight, char brickWidth);
void drawBrick(struct TBrick *brick);
void clearBrick(struct TBrick *brick);

#endif