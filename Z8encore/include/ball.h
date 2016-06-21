#ifndef _BALL_H_
#define _BALL_H_

#include "ansi.h"
#include "striker.h" 

#define COLOR_MASK 0x7f
#define ALIVE_BIT_SHIFT 7

#define COLOR(data) (data & COLOR_MASK)
#define IS_ALIVE(data) ((data >> ALIVE_BIT_SHIFT) & 0x01)

struct TPosition
{
	long x;
	long y;
};
/*
TBall:
Represents a ball on the screen that can hit bricks and will bounce of the games edges
and the striker.


Position:
To make it possible for a ball to move at an angle the ball needs to store its position as a decimal number
and to do that longs are used for the x and y value where the last 14 bits of the long is reserved for decimals.
The above struct TPosition only purpose is to contain the position of a ball.


Velocity and angle:
For every tick the game runs the ball has to amove a certain length in the x and y axis which is defined 
by the velocity, which determines how fast the ball is moving, and the angle which determines where the ball is moving

Velocity:
The game itself isn't able to detect if a ball moves more than one position in the x and y axis at a time.
To prevent that from happening the velocity can't be more than 1

Angle:
Is a number between 0 and 360. 


Data:
This char contains different settings specific to this ball that doesn't require a char for its self.

Color:
The last 7 bits are reserved to specify the color of the ball although only 15 colors exist.
The color can be extracted from the char with the macro COLOR.

Alive:
When the game is initiated it initiates an array with the max amount of balls the game can run at a time
but not all balls are supposed to be shown and updated which is what this first bit of data is for. 
When a ball is alive the bit is 1 and when it's dead it's 0.
The Alive status can be extracted with the macro IS_ALIVE.
*/

struct TBall
{	
	struct TPosition position;
	int velocity;
	int angle;
	char data;//ALIVE 0, COLOR 0000000
};

void initBall(struct TBall *vBall,int x, int y, char color, int angle, long velocity, char alive);
void updateBallDrawnPosition(long oldX, long oldY, long newX, long newY);
char isBallDead(struct TBall balls[6], int gameSize);
void impact(struct TBall balls[6], int gameSizeX, int gameSizeY);
void updateBalls(struct TBall balls[6]);
void setBallColor(struct TBall *ball);

#endif