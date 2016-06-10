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
	         gotoxy=(vball->position.x,vball->position.y);
	         printf(" ");	
		 vball->position.x = vball->position.x + cos(vball->angle)*velocity;
		 vball->position.y = vball->position.y + sin(vball->angle)*velocity;
	         gotoxy=(vball->position.x,vball->position.y);
	         printf("%c",vball->skin);  // (9)	

//ved ikke om vi skal have momentumvektor
	//vball->momentum.x = vball->velocity*cos(vball->angle);
	//vball->momentum.y = vball->velocity*sin(vball->angle);		
	}
}

//Rendering nextstate Bouncer
void nextStateBouncer(struct TBouncer *vbouncer) {
	if (rightbn) {
		if (vbouncer->position.x < size) {
			gotoxy( vbouncer->position.x - vbouncer->length / 2, vbouncer->position.y);
			printf(" ");
			vbouncer->position.x=vbouncer->position.x + 1;
			gotoxy(vbouncer->position.x + vbouncer->length / 2, vbouncer->position.y);
			printf("%c", vbouncer->skin); // (178)

		}	
	}
	else if(leftbn) {
		if ( vbouncer->position.x > 0) 
			gotoxy(vbouncer->position.x + length / 2, vbouncer->position.y);
			printf(" ");
			vball->position.x=vbouncer->position.x - 1;
			gotoxy(vbouncer->position.x - length / 2, vbouncer->position.y);
			printf("%c", vbouncer->skin); // (178)
			
		}
	}

}

//Bounce off walls when impact
void impact(struct TBall *vball, struct TBouncer *vbouncer,  int angle, int size,) {
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


