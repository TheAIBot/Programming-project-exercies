#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "level.h"
#include "ansi.h"
#include "striker.h"
#include "ball.h"
#include "powerup.h"
#include "boss.h"
#include "brick.h"
#include "fixedmath.h"
#include "game.h"

#define BRICK_HEIGHT_1_ 2
#define BRICK_WIDTH_1_ 6
#define BRICK_SIZE_1_ 0x26

void level1(struct TGame *game)
{
	char i;
	struct TBrick bricks[39] = 
	{
		{(BRICK_WIDTH_1_ + 1) * 1, (BRICK_HEIGHT_1_ + 1) * 15, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 2, (BRICK_HEIGHT_1_ + 1) * 15, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 3, (BRICK_HEIGHT_1_ + 1) * 15, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 4, (BRICK_HEIGHT_1_ + 1) * 15, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 5, (BRICK_HEIGHT_1_ + 1) * 15, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 6, (BRICK_HEIGHT_1_ + 1) * 15, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 7, (BRICK_HEIGHT_1_ + 1) * 15, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 8, (BRICK_HEIGHT_1_ + 1) * 15, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 9, (BRICK_HEIGHT_1_ + 1) * 15, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) *10, (BRICK_HEIGHT_1_ + 1) * 15, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) *11, (BRICK_HEIGHT_1_ + 1) * 15, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) *12, (BRICK_HEIGHT_1_ + 1) * 15, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) *12, (BRICK_HEIGHT_1_ + 1) * 15, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 1, (BRICK_HEIGHT_1_ + 1) * 16, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 2, (BRICK_HEIGHT_1_ + 1) * 16, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 3, (BRICK_HEIGHT_1_ + 1) * 16, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 4, (BRICK_HEIGHT_1_ + 1) * 16, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 5, (BRICK_HEIGHT_1_ + 1) * 16, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 6, (BRICK_HEIGHT_1_ + 1) * 16, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 7, (BRICK_HEIGHT_1_ + 1) * 16, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 8, (BRICK_HEIGHT_1_ + 1) * 16, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 9, (BRICK_HEIGHT_1_ + 1) * 16, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) *10, (BRICK_HEIGHT_1_ + 1) * 16, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) *11, (BRICK_HEIGHT_1_ + 1) * 16, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) *12, (BRICK_HEIGHT_1_ + 1) * 16, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) *12, (BRICK_HEIGHT_1_ + 1) * 16, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 1, (BRICK_HEIGHT_1_ + 1) * 17, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 2, (BRICK_HEIGHT_1_ + 1) * 17, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 3, (BRICK_HEIGHT_1_ + 1) * 17, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 4, (BRICK_HEIGHT_1_ + 1) * 17, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 5, (BRICK_HEIGHT_1_ + 1) * 17, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 6, (BRICK_HEIGHT_1_ + 1) * 17, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 7, (BRICK_HEIGHT_1_ + 1) * 17, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 8, (BRICK_HEIGHT_1_ + 1) * 17, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 9, (BRICK_HEIGHT_1_ + 1) * 17, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) *10, (BRICK_HEIGHT_1_ + 1) * 17, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) *11, (BRICK_HEIGHT_1_ + 1) * 17, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) *12, (BRICK_HEIGHT_1_ + 1) * 17, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) *12, (BRICK_HEIGHT_1_ + 1) * 17, BRICK_SIZE_1_, 1},
	};
	int brickCount = sizeof(bricks) / sizeof(bricks[0]);
	for(i = 0; i < brickCount; i++)
	{
		game->bricks[i] = bricks[i];
	}
	game->brickCount = brickCount;
}

void level2(struct TGame *game)
{

}

void level3(struct TGame *game)
{

}


void initLevel(struct TGame *game, int level)
{
	switch(level)
	{
		case 1:
			break;
		default:
			break;
	}
}

void moveStrikerPreShot(struct TBall *vball, struct TStriker *vStriker, int gameSizeX, char rightButtonPressed, char leftButtonPressed) {
    if (rightButtonPressed && vStriker->position.x + (vStriker->length >> 1) + 1 < gameSizeX) {
		//render new ball position
		long oldX = vball->position.x;
		long oldY = vball->position.y;
		vball->position.x += TO_FIX14(1);
		setBallColor(vball);
		updateBallDrawnPosition(oldX, oldY, vball->position.x, vball->position.y);

		//render new bouncer position
		moveStrikerRight(vStriker);	
	}
	else if(leftButtonPressed && vStriker->position.x - (vStriker->length >> 1) - 2 > 0) {
		//render new ball position
		long oldX = vball->position.x;
		long oldY = vball->position.y;
		vball->position.x -= TO_FIX14(1);
		setBallColor(vball);
		updateBallDrawnPosition(oldX, oldY, vball->position.x, vball->position.y);

		//render new bouncer position
		moveStrikerLeft(vStriker);
	}
}
