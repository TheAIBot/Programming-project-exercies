#include <eZ8.h>
#include <sio.h>
#include "color.h"
#include "striker.h"
#include "ansi.h"

#define STRIKER_STYLE 178
#define EMPTY_CHAR ' '

void sdraw(int x, int y, int length, char c)
{
	int i;
	gotoxy(x - (length / 2), y); // go to left of bouncer
	for(i = 0; i < length; i++)
	{
		printf("%c", c);
	}
}

void clearStriker(int x, int y, int length)
{
	sdraw(x, y, length, EMPTY_CHAR);
}

void clearStrikerLeft(int x, int y, int length)
{
	gotoxy(x + (length >> 1), y); // go to right of bouncer
	printf("%c", EMPTY_CHAR);
}

void clearStrikerRight(int x, int y, int length)
{
	gotoxy(x - (length >> 1), y); // go to left of bouncer
	printf("%c", EMPTY_CHAR);
}

void drawStriker(int x, int y, int length)
{
	fgcolor(FCOLOR_GREEN);
	sdraw(x, y, length, STRIKER_STYLE);
}

void drawStrikerLeft(int x, int y, int length)
{
	gotoxy(x - (length >> 1), y); // go to left of bouncer
	fgcolor(FCOLOR_GREEN);
	printf("%c", STRIKER_STYLE);
}

void drawStrikerRight(int x, int y, int length)
{
	gotoxy(x + (length >> 1), y); // go to right of bouncer
	fgcolor(FCOLOR_GREEN);
	printf("%c", STRIKER_STYLE);
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
