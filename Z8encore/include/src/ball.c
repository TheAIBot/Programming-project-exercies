#include <eZ8.h>
#include <sio.h>
#include "ball.h"
#include "ansi.h"

void draw(int x, int y, char c)
{
	gotoxy(x, y);
	printf("%c", c); // (9)
}

void drawBall(int x, int y)
{
	const char ballChar = 9;
	draw(x, y, ballChar);
}

void clearBall(int x, int y)
{
	const char emptyChar = ' ';
	draw(x, y, emptyChar);
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
