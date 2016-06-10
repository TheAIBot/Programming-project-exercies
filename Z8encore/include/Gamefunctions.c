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

//volatile Tgame g = new Tgame;


//Rendering nextstate Ball
void nextStateBall(struct TBall *vball) {
	
	if(vball->velocity > 0){
		clearBall(vball->position.x,vball->position.y);	
		 vball->position.x = vball->position.x + cos(vball->angle) * velocity;
		 vball->position.y = vball->position.y + sin(vball->angle) * velocity;
		 drawBall(vball->position.x,vball->position.y);	

//ved ikke om vi skal have momentumvektor
	//vball->momentum.x = vball->velocity*cos(vball->angle);
	//vball->momentum.y = vball->velocity*sin(vball->angle);		
	}
}

//Bounce off walls when impact
void impact(struct TBall *vball, struct TBouncer *vbouncer,  int angle, int size) {
int curx=vball->position.x;
int cury=vball->position.y;

//bounce off right and left walls	
if (curx == size || curx == 0) {
		vball->angle = 180 - vball->angle;
	}
//bounce off top wall and bouncer
if (cury == 0 || cury==size-1 && (curx >= vbouncer->position.x - vbouncer->length / 2 && curx <= vbouncer->length + vbouncer->length / 2)){
		vball->angle= - vball->angle;
	}
//ved ikke om vi skal have momentumvektor
	//vball->momentum.x = vball->velocity*cos(vball->angle);
	//vball->momentum.y = vball->velocity*sin(vball->angle);	
}


//Death zone
void deathzone(struct TBall *vball, struct TBouncer *vbouncer, int deathcount){
int curx=vball->position.x;
int cury=vball->position.y;
if (cury==size-1 &&(curx <= vbouncer->position.x - vbouncer->length / 2 || curx >= vbouncer->length + vbouncer->length / 2)){
		gotoxy( vbouncer->position.x - vbouncer->length / 2, vbouncer->position.y);
		printf(" ");  
		initball(&vball,vbouncer->position.x,vbouncer->position.y + 1, 40 ,0);
		startfunc(&vball,&vbouncer);
        	deathcount++;
}
}

//Score


