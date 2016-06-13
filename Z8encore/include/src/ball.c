#include <eZ8.h>
#include <sio.h>
#include "ball.h"
#include "ansi.h"
#include "SineLUT.h"
#include "fixedmath.h"

#define BALL_STYLE 9
#define EMPY_CHAR ' '

void bdraw(long x, long y, char c)
{
	int ix = FIX14_TO_INT(x);
	int iy = FIX14_TO_INT(y);
	gotoxy(ix, iy);
	printf("%c", c); // (9)
}

void drawBall(long x, long y)
{
	bdraw(x, y, 'o');
}

void clearBall(long x, long y)
{
	bdraw(x, y, EMPY_CHAR);
}

//Initialize ball
void initBall(struct TBall *vBall,int x, int y, char color, int angle, int velocity){
	vBall->position.x = TO_FIX14(x);
	vBall->position.y = TO_FIX14(y);
	vBall->angle = angle;
	vBall->velocity = velocity;
	vBall->color = color;

	fgcolor(color);
	drawBall(vBall->position.x, vBall->position.y);
}

void moveBall(struct TBall *vball)
{
	vball->position.x +=  FIX14_MULT(cos(vball->angle), vball->velocity);
	vball->position.y +=  FIX14_MULT(sin(vball->angle), vball->velocity);
}

//Rendering nextstate Ball
void updateBall(struct TBall *vball) {
	if(vball->velocity > 0){
		clearBall(vball->position.x,vball->position.y);	
		moveBall(vball);
		drawBall(vball->position.x,vball->position.y);
	}
}

char isBallDead(struct TBall *vball, struct TStriker *vStriker, int gameSize){
	int curx = vball->position.x;
	int cury = vball->position.y;
	if (cury==gameSize-1 && (curx <= vStriker->position.x - vStriker->length / 2 || curx >= vStriker->length + vStriker->length / 2)){
		return 1;
	}
	return 0;
}

void impact(struct TBall *vball, struct TStriker *vStriker, int gameSize,  int angle, int size) {
	int curx=vball->position.x;
	int cury=vball->position.y;
	
	//bounce off right and left walls	
	if (curx == gameSize || curx == 0) {
		vball->angle = 180 - vball->angle;
	}
	//bounce off top wall and bouncer
	if (cury == 0 || cury==gameSize-1 && (curx >= vStriker->position.x - vStriker->length / 2 && curx <= vStriker->length + vStriker->length / 2)){
		vball->angle= -vball->angle;
	}	
}


