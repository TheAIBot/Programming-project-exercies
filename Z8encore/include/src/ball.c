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

	vball->momentum.x=FIX14_MULT(velocity*cos(angle));
	vball->momentum.y=FIX14_MULT(velocity*sin(angle));
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
	int ballx=FIX14_TOINT(vball->position.x);//truncation
	int bally=FIX14_TOINT(vball->position.y);//truncation
	int strx = FIX14_TOINT(vStriker->position.x);//truncation
	int strhl = vStriker->length >> 1;//half length of striker
	if (bally==gameSize-1 && (ballx <= strx - strhl - 1 || ballx >= strx + strhl + 1)){
		return 1;
	}
	return 0;
}

void impact(struct TBall *vball, struct TStriker *vStriker, int gameSize,  int angle, int size) {
	int ballx=FIX14_TOINT(vball->position.x);//truncation
	int bally=FIX14_TOINT(vball->position.y);//truncation
	int strx = FIX14_TOINT(vStriker->position.x);//truncation
	int strhl = vStriker->length >> 1;//half length of striker

	//bounce off right and left walls	
	if (ballx == gameSize || ballx == 0) {
		vball->angle = 360 - vball->angle;
	}
	//bounce off top wall and central striker
	if (bally == 0 ||(bally == gameSize - 1 && ballx >= strx - strhl - 1 && ballx <= strx + strhl + 1)){
		vball->angle= 180 - vball->angle;
	}
	//ved ikke om vi skal have momentumvektor
		vball->momentum.x = FIX14_MULT(vball->velocity,cos(vball->angle));
		vball->momentum.y = FIX14_MULT(vball->velocity,sin(vball->angle));	
}

//bounce off striker at different angles
void bounceStriker(struct TStriker *vStriker, struct TBall *vball, int gameSize){
	int ballx = FIX14_TOINT(vball->position.x);//truncation
	int bally = FIX14_TOINT(vball->position.y);//truncation
	int strx = FIX14_TOINT(vStriker->position.x);//truncation
	int stry = FIX14_TOINT(vStriker->position.y);//truncation
	int strhl = vStriker->length >> 1; //half length of striker
	
	if ((bally == gameSize - 1) && (ballx >= strx - strhl - 1 && ballx <= strx + strhl + 1)) {
		air = vball->angle - 90;  //incomming angle for ball incomming from left
 	    ail = 90 - vball->angle;  //incomming angle for ball incomming from left
		//When incomming from left
		if (FIX14_TOINT(vball->momentum.x) > 0 && ballx - strx > 0){
			if (ballx - strx =< strx >> 1) { //Right medium
				vball->angle = 90 - 1.5*air;}
			else {   					   //Right end
			   vball->angle = 90 - 3*air;}

		} else 
		if (FIX14_TOINT(vball->momentum.x) > 0 && ballx - strx < 0){
			if (ballx - strx =< - strx >> 1) { //Left medium
				vball->angle = 90 - air/1.5;}
			else {   					   //Left end
			   vball->angle = 90 - air/3;}
		} else
		//When incomming from right		
		if (FIX14_TOINT(vball->momentum.x) < 0 && ballx - strx < 0){
			if (ballx - strx =< - strx >> 1) { //Right medium
				vball->angle = 90 - 1.5*air;}
			else {   					   //Right end
			   vball->angle = 90 - 3*air;}

		} else 
		if (FIX14_TOINT(vball->momentum.x) > 0 && ballx - strx > 0){
			if (ballx - strx =< strx >> 1) { //Left medium
				vball->angle = 90 - air/1.5;}
			else {   					   //Left end
			   vball->angle = 90 - air/3;}
		} else
	}
	vball->momentum.x=FIX14_MULT(velocity*cos(vball->angle));
	vball->momentum.y=FIX14_MULT(velocity*sin(vball->angle));

}
