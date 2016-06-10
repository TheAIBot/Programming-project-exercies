#include <eZ8.h>
#include <sio.h>
#include "color.h"
#include "striker.h"
#include "ansi.h"

void sdraw(int x, int y, int length, char c)
{
	int i;
	gotoxy(x - (length / 2), y); // go to left of bouncer
	for(i = 0; i < length; i++)
	{
		printf("%c", c);
	}
}

void drawStriker(int x, int y, int length)
{
	const char strikerStyle = 178;
	sdraw(x, y, length, strikerStyle);
}

void clearStriker(int x, int y, int length)
{
	const char emptyChar = ' ';
	sdraw(x, y, length, emptyChar);
}

void clearStrikerLeft(int x, int y, int length)
{
	const char emptyChar = ' ';
	gotoxy(x + (length >> 1), y); // go to right of bouncer
	printf("%c", emptyChar);
}

void clearStrikerRight(int x, int y, int length)
{
	const char emptyChar = ' ';
	gotoxy(x - (length >> 1), y); // go to left of bouncer
	printf("%c", emptyChar);
}

void drawStrikerLeft(int x, int y, int length)
{
	const char strikerStyle = 178;
	gotoxy(x - (length >> 1), y); // go to left of bouncer
	printf("%c", strikerStyle);
}

void drawStrikerRight(int x, int y, int length)
{
	const char strikerStyle = 178;
	gotoxy(x + (length >> 1), y); // go to right of bouncer
	printf("%c", strikerStyle);
}

void moveStrikerLeft(struct TStriker *vStriker)
{
	clearStrikerLeft(vStriker->position.x, vStriker->position.y, vStriker->length);
	vStriker->position.x--;
	drawStrikerLeft(vStriker->position.x, vStriker->position.y, vStriker->length);
}

void moveStrikerRight(struct TStriker *vStriker)
{
	clearStrikerRight(vStriker->position.x, vStriker->position.y, vStriker->length);
	vStriker->position.x++;
	drawStrikerRight(vStriker->position.x, vStriker->position.y, vStriker->length);
}

//Rendering nextstate Bouncer
void moveStriker(struct TStriker *vStriker, int gameSize, char rightButtonPressed, char leftButtonPressed) {
	if (rightButtonPressed && vStriker->position.x + (vStriker->length >> 1) + 1 < gameSize) {
		moveStrikerRight(vStriker);	
	}
	else if(leftButtonPressed && vStriker->position.x - (vStriker->length >> 1) - 2 > 0) {
		moveStrikerLeft(vStriker);
	}
}

//Initialize bouncer
void initStriker(struct TStriker *vStriker, int x, int y, int l){
	vStriker->position.x = x;
	vStriker->position.y = y;
	vStriker->length = l;
	drawStriker(x, y, l);	
}
