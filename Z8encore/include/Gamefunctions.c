#include <eZ8.h>
#include <sio.h>
#include "clockio.h"
#include "color.h"
#include "game.h"
#include "level.h"
#include "ball.h"
#include "striker.h"
#include "brick.h"
#include "boss.h"
#include "powerup.h"
#include "SineLUT.h"
#include "buttonio.h"

//volatile Tgame g = new Tgame;


//Rendering nextstate Ball
void nextStateBall(struct TBall *vball) {
	
	if(vball->velocity > 0){
		clearBall(vball->position.x,vball->position.y);	
		 vball->position.x = vball->position.x + cos(vball->angle) * vball->velocity;
		 vball->position.y = vball->position.y + sin(vball->angle) * vball->velocity;
		 drawBall(vball->position.x,vball->position.y);	

//ved ikke om vi skal have momentumvektor
	//vball->momentum.x = vball->velocity*cos(vball->angle);
	//vball->momentum.y = vball->velocity*sin(vball->angle);		
	}
}

//Bounce off walls when impact
void impact(struct TBall *vball, struct TStriker *vStriker, int gameSize,  int angle, int size) {
int curx=vball->position.x;
int cury=vball->position.y;

//bounce off right and left walls	
if (curx == gameSize || curx == 0) {
		vball->angle = 180 - vball->angle;
	}
//bounce off top wall and bouncer
if (cury == 0 || cury==gameSize-1 && (curx >= vStriker->position.x - vStriker->length / 2 && curx <= vStriker->length + vStriker->length / 2)){
		vball->angle= - vball->angle;
	}
//ved ikke om vi skal have momentumvektor
	//vball->momentum.x = vball->velocity*cos(vball->angle);
	//vball->momentum.y = vball->velocity*sin(vball->angle);	
}


//Death zone
char isBallDead(struct TBall *vball, struct TStriker *vStriker, int gameSize){
	int curx=vball->position.x;
	int cury=vball->position.y;
	if (cury==gameSize-1 &&(curx <= vStriker->position.x - vStriker->length / 2 || curx >= vStriker->length + vStriker->length / 2)){
		return 1;
	}
	return 0;
}

//Score


