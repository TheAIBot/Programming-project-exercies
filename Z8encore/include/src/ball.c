#include <eZ8.h>
#include <sio.h>
#include "ball.h"
#include "ansi.h"
#include "SineLUT.h"
#include "fixedmath.h"

#define BALL_STYLE 254
#define EMPY_CHAR ' '

void bdraw(long x, long y, char c)
{
	int ix = FIX14_TO_INT(x);
	int iy = FIX14_TO_INT(y);
	gotoxy(ix, iy);
	printf("%c", c); // (9)
}

void setBallColor(struct TBall *ball)
{
	fgcolor(ball->color);
}

void drawBall(long x, long y)
{
	bdraw(x, y, BALL_STYLE);
}

void clearBall(long x, long y)
{
	bdraw(x, y, EMPY_CHAR);
}

//Initialize ball
void initBall(struct TBall *vBall,int x, int y, char color, int angle, long velocity){
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
	vball->position.x += FIX14_MULT(vball->velocity,cos(vball->angle));
	vball->position.y += FIX14_MULT(vball->velocity,-sin(vball->angle));
}

//Rendering nextstate Ball
void updateBall(struct TBall *vball) {
	if(vball->velocity > 0){
		clearBall(vball->position.x,vball->position.y);	
		moveBall(vball);
		drawBall(vball->position.x,vball->position.y);
	}
	else 
	{
		vball->velocity = TO_FIX14(1) >> 1;
	}
}

char isBallDead(struct TBall *vball, int gameSizeY){
	int ballx = FIX14_TO_INT(vball->position.x);//truncation
	int bally = FIX14_TO_INT(vball->position.y);//truncation
	if (bally==gameSizeY-1){
		return 1;
	}
	return 0;
}

void impact(struct TBall *vball, struct TStriker *vStriker, int gameSizeX, int gameSizeY) {
	int ballx=FIX14_TO_INT(vball->position.x);//truncation
	int bally=FIX14_TO_INT(vball->position.y);//truncation
	int strx = vStriker->position.x;
	int stry = vStriker->position.y;
	int strhl = vStriker->length >> 1;//half length of striker

	//bounce off right and left walls	
	if (ballx == gameSizeX - 1 || ballx == 2) {
		vball->angle = 180 - vball->angle;
		if(vball->angle < 0)
		{
			vball->angle = vball->angle + 360;//find better solution
		}
	}
	//bounce off top wall and central striker
	if (bally == 2 ||(bally == stry - 1 && ballx == strx )){
		vball->angle= 360 - vball->angle;
	}
}

