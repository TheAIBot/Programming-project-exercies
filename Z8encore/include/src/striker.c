#include <eZ8.h>
#include <sio.h>
#include "color.h"
#include "striker.h"


//Initialize bouncer
void initStriker(struct TStriker *vStriker, int x, int y, int l){
	vStriker->position.x = x;
	vStriker->position.y = y;
	vStriker->length = l;
	drawStriker(x, y, l);	
}

void drawStriker(int x, int y, int length)
{
	const char strikerStyle = 178;
	draw(x, y, length, strikerStyle);
}

void clearStriker(int x, int y, int length)
{
	const char emptyChar = ' ';
	draw(x, y, length, emptyChar);
}

void draw(int x, int y, int length, char c)
{
	int i;
	gotoxy(x - (length / 2), y); // go to left of bouncer
	for(i = 0; i < length; i++)
	{
		printf("%c", bouncerStyle);
	}
}
