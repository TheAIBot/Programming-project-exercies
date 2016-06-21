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

//Represents a ball on the screen that can hit bricks and will bounce of the games edges
//and the striker
//to make it possible for a ball to move at an angle the ball needs to store its position as a decimal number.
//
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
void impact(struct TBall balls[6], struct TStriker *vStriker, int gameSizeX, int gameSizeY);
void updateBalls(struct TBall balls[6]);
void setBallColor(struct TBall *ball);

#endif