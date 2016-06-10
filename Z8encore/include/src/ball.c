#include <eZ8.h>
#include <sio.h>
#include "ball.h"

//Initialize ball
void initBall(struct TBall *vBall,int x, int y, char color, long angle, long velocity){
	vBall->position.x = x;
	vBall->position.y = y;
	vBall->angle = angle;
	vBall->velocity = velocity;
	vBall->skin = skin;

	//vball->mx=velocity*cos(angle);
	//vball->my=velocity*sin(angle);
	drawBall(skin);
}

void drawBall(int x, int y, char skin)
{
	const char ballChar = 9;
	draw(x, y, ballChar);
}

void clearBall(int x, int y)
{
	const char emptyChar = ' ';
	draw(x, y, emptyChar);
}

void draw(int x, int y, char c)
{
	gotoxy(x, y);
	printf("%c", c); // (9)
}
