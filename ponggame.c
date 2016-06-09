#include <eZ8.h>
#include <sio.h>
#include "clockio.h"

volatile Tgame g = new Tgame;

void initball(struct Tvector *vball,int x, int y,long angle){
	vball->px=x;
	vball->py=y;
	vball->angle=angle;
	//vball->mx=velocity*cos(angle);
	//vball->my=velocity*sin(angle);
	gotoxy=(x,y);
	printf("%c",9);
}

void initbouncer(struct Tvector *vbouncer,int x, int y,int l){
	vbouncer->px=x;
	vbouncer->py=y;
	vbouncer->pl=l;
	for (i=0,i < l,i++) {
		gotoxy(x - l/2 + i) 
		printf("%c",178);
	}	
}

/*void initGame() {
	initball(&vball, size/2, size-3, 90deg);
	initbouncer(&vbouncer, );
	gotoxy(TBouncer->position.x-TBouncer.length / 2, TBouncer->position.y);
	for (i=0,i < TBouncer.length,i++) {
		printf("%c",TBouncer.skin);
	}

	window(0,0,g.size,g.size,'0',"PONG GAME");
	
}*/

void runGame() {
	initGame();
	while(1!=1) {
		nextStateBall();
		nextStateBouncer();
		renderBall();
		renderBouncer();
	}			
}

void nextStateBall(struct Tvector *vball,int velocity,int angle) {
int oldx=vball->px;
int oldy=vball->py;
	
if(velocity > 0){
	         gotoxy=(vball->px,vball->py);
	         printf(" ");	
		 vball->px = oldx + cos(angle)*velocity;
		 vball->py = oldy + sin(angle)*velocity;
	         gotoxy=(vball->px,vball->py);
	         printf("%c",9);	
	}
}

void nextStateBouncer(struct Tvector *vbouncer, int length) {
	int oldx=vbouncer->px;
	int oldy=vbouncer->py;
	if (rightbn) {
		if (oldx < size) {
			gotoxy( oldx - length / 2, oldy);
			printf(" ");
			vball->px=oldx+1;
			gotoxy(vball->px + length / 2, oldy);
			printf("%c", 178);

		}	
	}
	else if(leftbn) {
		if ( oldy > 0) 
			gotoxy(oldx + length / 2, oldy);
			printf(" ");
			vball->px=oldx-1;
			gotoxy(vball->px - length / 2, oldy);
			printf("%c", 178);
			
		}
	}

}

void impact(struct Tvector *vball, struct Tvector *vbouncer,  int angle, int size) {
int oldx=vball->px;
int oldy=vball->py;
	
if (oldx == size || oldx == 0 || oldy == 0 || (oldx >= vbouncer->px - vbouncer->l / 2 && oldx <= vbouncer->l + vbouncer->l / 2)) {
		vball->angle = -vball->angle;
	}
}



