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
void initBall(struct TBall *vBall,int x, int y, char color, int angle, long velocity){
	vBall->position.x = TO_FIX14(x);
	vBall->position.y = TO_FIX14(y);
	vBall->angle = angle;
	vBall->velocity = velocity;
	vBall->color = color;

	vBall->momentum.x = FIX14_MULT(velocity,cos(angle));
	vBall->momentum.y = FIX14_MULT(velocity,-sin(angle));

	fgcolor(color);
	drawBall(vBall->position.x, vBall->position.y);
}

void moveBall(struct TBall *vball)
{
	vball->position.x += vball->momentum.x;
	vball->position.y += vball->momentum.y;
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
		vball->velocity = TO_FIX14(1);
		vball->momentum.x = FIX14_MULT(vball->velocity,cos(vball->angle));
		vball->momentum.y = FIX14_MULT(vball->velocity,-sin(vball->angle));
	}
}

char isBallDead(struct TBall *vball, struct TStriker *vStriker, int gameSizeY){
	int ballx=FIX14_TO_INT(vball->position.x);//truncation
	int bally=FIX14_TO_INT(vball->position.y);//truncation
	int strx = vStriker->position.x;//truncation
	int strhl = vStriker->length >> 1;//half length of striker
	if (bally==gameSizeY-1 && (ballx <= strx - strhl - 1 || ballx >= strx + strhl + 1)){
		return 1;
	}
	return 0;
}

void impact(struct TBall *vball, struct TStriker *vStriker, int gameSizeX, int gameSizeY) {
	int ballx=FIX14_TO_INT(vball->position.x);//truncation
	int bally=FIX14_TO_INT(vball->position.y);//truncation
	int strx = vStriker->position.x;//truncation
	int strhl = vStriker->length >> 1;//half length of striker

	/*if(ballx <= 0 || ballx >= gameSizeX)
	{
		vball->momentum.x  = -vball->momentum.x;
	}

	if(bally <= 0 || bally >= gameSizeY)
	{
		vball->momentum.y  = -vball->momentum.y;
	}*/ 

	//bounce off right and left walls	
	if (ballx == gameSizeX || ballx == 0) {
		vball->angle = 180 - vball->angle;
	}
	//bounce off top wall and central striker
	if (bally == 0 ||(bally == gameSizeY - 1 && ballx >= strx - strhl - 1 && ballx <= strx + strhl + 1)){
		vball->angle= 360 - vball->angle;
	}
	//momentumvektor
	vball->momentum.x = FIX14_MULT(vball->velocity,cos(vball->angle));
	vball->momentum.y = FIX14_MULT(vball->velocity,-sin(vball->angle));	
}

