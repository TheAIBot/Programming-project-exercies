#include <eZ8.h>
#include <sio.h>
#include "ball.h"
#include "ansi.h"
#include "SineLUT.h"

#define FIX14_SHIFT 14
#define FIX14_MULT(a, b) ( (a)*(b) >> FIX14_SHIFT )
#define FIX14_DIV(a, b) ( ((a) << FIX14_SHIFT) / (b) )
#define FIX14_TOINT(a) (a >> FIX14_SHIFT)

void bdraw(int x, int y, char c)
{
	gotoxy(x, y);
	printf("%c", c); // (9)
}

void drawBall(long x, long y)
{
	const char ballChar = 9;
	bdraw(FIX14_TOINT(x), FIX14_TOINT(y), 'O');
}

void clearBall(long x, long y)
{
	const char emptyChar = ' ';
	bdraw(FIX14_TOINT(x), FIX14_TOINT(y), emptyChar);
}

//Initialize ball
void initBall(struct TBall *vBall,int x, int y, char color, long angle, long velocity){
	vBall->position.x = x;
	vBall->position.y = y;
	vBall->angle = angle;
	vBall->velocity = velocity;
	vBall->color = color;

	//vball->mx=velocity*cos(angle);
	//vball->my=velocity*sin(angle);
	fgcolor(color);
	drawBall(x, y);
}

void moveBall(struct TBall *vball)
{
	vball->position.x = vball->position.x + FIX14_MULT(cos(vball->angle),vball->velocity);
	vball->position.y = vball->position.y + FIX14_MULT(sin(vball->angle),vball->velocity);
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
	int curx=vball->position.x;
	int cury=vball->position.y;
	if (cury==gameSize-1 &&(curx <= vStriker->position.x - vStriker->length / 2 || curx >= vStriker->length + vStriker->length / 2)){
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
	//ved ikke om vi skal have momentumvektor
		//vball->momentum.x = vball->velocity*cos(vball->angle);
		//vball->momentum.y = vball->velocity*sin(vball->angle);	
}


