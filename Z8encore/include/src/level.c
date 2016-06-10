#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "level.h"
#include "ansi.h"
#include "striker.h"
#include "ball.h"

void initLevel()
{

}

void updateLevel(struct TStriker *vStriker, 
				 struct TBall *vball,
				 struct TBrick bricks[],
				 struct TBoss *boss,
				 struct TPowerUp powerups[])
{
	
}

void moveStrikerPreShot(struct TStriker *vStriker, struct TBall *vball, char leftButtonPressed, char rightButtonPressed, char middleButtonPressed) {
    if (rightButtonPressed && vStriker->position.x < size) {
		//render new ball position
		clearBall(vball->position.x,vball->position.y);
		vball->position.x++;
		drawBall(vball->position.x,vball->position.y, vball->skin);

		//render new bouncer position
		clearStriker(vStriker->position.x, vStriker->position.y, vStriker->length);
		vStriker->position.x++;
		drawStriker(vStriker->position.x, vStriker->position.y, vStriker->length);	
	}
	else if(leftButtonPressed && vbouncer->position.x > 0) {
		//render new ball position
		clearBall(vball->position.x,vball->position.y);
		vball->position.x--;
		drawBall(vball->position.x,vball->position.y, vball->skin);

		//render new bouncer position
		clearStriker(vStriker->position.x, vStriker->position.y, vStriker->length);
		vStriker->position.x--;
		drawStriker(vStriker->position.x, vStriker->position.y, vStriker->length);
	}
	if (middleButtonPressed) {
		//need angle
  		vball->velocity = 5;
	}
}
