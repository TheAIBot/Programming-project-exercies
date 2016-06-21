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

/*
TBrick:
This struct defines the parameters for a rectangle on the screen which the ball cal bounce on and potentially damage.

x, y:
The top left position of the brick


size:
Contains the width and height of the brick. Height and width is both 4 bits which means
that the max value for the height and width is 15. Due to the way brick collisions with balls
The height of the brick is the last four bits and can be extracted with the macro BRICK_HEIGHT
The width of the brick is the first four bits and can be extracted with the macro BRICK_HEIGHT
A size can be made by a width and height by using the macro MAKE_SIZE.


data:
Contains wether the brick is indestructible, moving, its direction and its health. The last
bit is not used for anything.

indestructible:
Is the seventh bit. if this bit is set to 1 then the brick is indestructible which means it can't be killed.
Even if a brick is indestructible is still needs health or else collision checks with balls won't be done.
The bit can be extracted with the macro IS_INDESTRUCTIBLE.

is moving:
Is the sixth bit and determines if this brick is able to move. Set to 1 if the brick cshould be able to move.
This bit can be extracted with the macro IS_MOVING.

direction:
Only usefull if the is moving bit is set as the direction of the movement otherwise is useless.
Direction is the fifth bit.
If the bit is set to 1 then the brick should move right and otherwise move left.
This bit can be extracted with the macro DIRECTION.

health:
The first four bits are reserved for the bricks health which can max be 15.
The health can be extracted with the macro HEALTH.

*/

struct TBrick
{
	char x;
	char y;
	//can minimum be a 2x2 brick
	char size;//height 0000, width 0000
	char data; // 0 indestructible 0, is moving 0, direction 0, health 0000
};



char handleBrickCollisions(struct TBrick bricks[], struct TBall balls[], int brickCount, unsigned int *score);
void drawBricks(struct TBrick bricks[], int brickCount);
void setBrickColor(struct TBrick *brick);
void updateBrickPositionRight(int oldX, int oldY, int newX, int newY, char brickHeight, char brickWidth);
void updateBrickPositionLeft(int oldX, int oldY, int newX, int newY, char brickHeight, char brickWidth);
void drawBrick(struct TBrick *brick);
void clearBrick(struct TBrick *brick);

#endif