#include <eZ8.h>
#include <sio.h>
#include "clockio.h"

volatile Tgame g = new Tgame;

//Initialize ball
void initball(struct TBall *vball,int x, int y,long angle,long velocity){
	vball->position.x=x;
	vball->position.y=y;
	vball->angle=angle;
	vball->velocity=velocity;
	//vball->mx=velocity*cos(angle);
	//vball->my=velocity*sin(angle);
	gotoxy=(x,y);
	printf("%c",9);
}
//Initialize bouncer
void initbouncer(struct TBouncer *vbouncer,int x, int y,int l){
	vbouncer->position.x=x;
	vbouncer->position.y=y;
	vbouncer->skin=l;
	for (i=0,i < l,i++) {
		gotoxy(x - l/2 + i, y) 
		printf("%c",178);
	}	
}

/*
void runGame() {
	initGame();
	while(1!=1) {
		nextStateBall();
		nextStateBouncer();
		renderBall();
		renderBouncer();
	}			
}
*/
//Startfunction
void startfunc(struct TBouncer *vbouncer, struct TBall *vball) {
while (velocity == 0) {	
        if (rightbn) {
		if (vbouncer->position.x < size) {
			//render new ball position
			gotoxy=(vball->position.x,vball->position.y);
	       		printf(" ");	
			vball->position.x = vball->position.x + 1;
	       		gotoxy=(vball->position.x,vball->position.y);
	         	printf("%c",9);

			//render new bouncer position
			gotoxy( vbouncer->position.x - length / 2, vbouncer->position.y);
			printf(" ");
			vbouncer->position.x=vbouncer->position.x + 1;
			gotoxy(vbouncer->position.x + length / 2, vbouncer->position.y);
			printf("%c", 178);

		}	
	}
	else if(leftbn) {
		if ( vbouncer->position.y > 0)
			//render new ball position
			gotoxy=(vball->position.x,vball->position.y);
	       		printf(" ");	
			vball->position.x = vball->position.x + 1;
	       		gotoxy=(vball->position.x,vball->position.y);
	         	printf("%c",9);			

			//render new bouncer position 
			gotoxy(vbouncer->position.x + length / 2, vbouncer->position.y);
			printf(" ");
			vball->position.x=vbouncer->position.x - 1;
			gotoxy(vbouncer->position.x - length / 2, vbouncer->position.y);
			printf("%c", 178);
			
		}
	}
	if (SPACe/bn1 && bn2 && bn3) {
  		vball->velocity = 5;
		}
}
}


//Rendering nextstate Ball
void nextStateBall(struct TBall *vball) {
	
if(vball->velocity > 0){
	         gotoxy=(vball->position.x,vball->position.y);
	         printf(" ");	
		 vball->position.x = vball->position.x + cos(vball->angle)*velocity;
		 vball->position.y = vball->position.y + sin(vball->angle)*velocity;
	         gotoxy=(vball->position.x,vball->position.y);
	         printf("%c",9);	

//ved ikke om vi skal have momentumvektor
	vball->momentum.x = vball->velocity*cos(vball->angle);
	vball->momentum.y = vball->velocity*sin(vball->angle);		
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
			printf("%c", 178);

		}	
	}
	else if(leftbn) {
		if ( vbouncer->position.y > 0) 
			gotoxy(vbouncer->position.x + length / 2, vbouncer->position.y);
			printf(" ");
			vball->position.x=vbouncer->position.x - 1;
			gotoxy(vbouncer->position.x - length / 2, vbouncer->position.y);
			printf("%c", 178);
			
		}
	}

}

//Bounce off walls when impact
void impact(struct TBall *vball, struct TBouncer *vbouncer,  int angle, int size,) {
int curx=vball->position.x;
int cury=vball->position.y;

//bounce off right and left walls	
if (curx == size || curx == 0) {
		vball->angle = 256 - vball->angle;
	}
//bounce off top wall and bouncer
if (cury == 0 || cury==size-1 && (curx >= vbouncer->position.x - vbouncer->length / 2 && curx <= vbouncer->length + vbouncer->length / 2){
		vball->angle= - vball->angle;
	}
//ved ikke om vi skal have momentumvektor
	vball->momentum.x = vball->velocity*cos(vball->angle);
	vball->momentum.y = vball->velocity*sin(vball->angle);	
}


//Death zone
void deathzone(struct TBall *vball, struct TBouncer *vbouncer, int deathcount){
int curx=vball->position.x;
int cury=vball->position.y;
if (curx <= vbouncer->position.x - vbouncer->length / 2 || curx >= vbouncer->length + vbouncer->length / 2){
		gotoxy( vbouncer->position.x - vbouncer->length / 2, vbouncer->position.y);
		printf(" ");  
		initball(&vball,vbouncer->position.x,vbouncer->position.y + 1, 50 ,0);
		startfunc(&vball,&vbouncer);
        	deathcount++;
}
}

//Score


