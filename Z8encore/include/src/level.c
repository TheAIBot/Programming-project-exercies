#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "level.h"
#include "ansi.h"
#include "striker.h"
#include "ball.h"

void initLevel(struct TStriker *vStriker, 
				 struct TBall *vball,
				 struct TBrick bricks[],
				 struct TBoss *boss,
				 struct TPowerUp powerups[])
{

}

void updateLevel(struct TStriker *vStriker, 
				 struct TBall *vball,
				 struct TBrick bricks[],
				 struct TBoss *boss,
				 struct TPowerUp powerups[])
{
	
}

void moveStrikerPreShot(struct TBall *vball, struct TStriker *vStriker, int gameSize, char leftButtonPressed, char rightButtonPressed, char middleButtonPressed) {
    if (rightButtonPressed && vStriker->position.x < gameSize) {
		//render new ball position
		clearBall(vball->position.x,vball->position.y);
		vball->position.x++;
		drawBall(vball->position.x, vball->position.y);

		//render new bouncer position
		moveStrikerRight(&vStriker);	
	}
	else if(leftButtonPressed && vStriker->position.x > 0) {
		//render new ball position
		clearBall(vball->position.x,vball->position.y);
		vball->position.x--;
		drawBall(vball->position.x,vball->position.y);

		//render new bouncer position
		moveStrikerLeft(&vStriker);
	}
	if (middleButtonPressed) {
		//need angle
  		vball->velocity = 5;
	}
}
