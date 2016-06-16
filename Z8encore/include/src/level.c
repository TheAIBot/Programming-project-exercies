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


void initLevel(struct TStriker *vStriker, struct TBall *vball, struct TBrick bricks[], struct TBoss *boss, struct TPowerUp powerups[])
{

}

void moveStrikerPreShot(struct TBall *vball, struct TStriker *vStriker, int gameSizeX, char leftButtonPressed, char rightButtonPressed) {
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
