#include <eZ8.h>
#include <sio.h>
#include "color.h"
#include "striker.h"
#include "ansi.h"
#include "fixedmath.h"
#include "trigonometry.h"
#include "sound.h"
#include "game.h"

#define STRIKER_STYLE 178
#define EMPTY_STYLE ' '

void sdraw(int x, int y, int length, char c)
{
	int i;
	gotoxy(x - (length / 2), y); // go to left of bouncer
	for(i = 0; i < length; i++)
	{
		printf("%c", c);
	}
}

void updateStrikerDrawnPositionRight(int oldX, int Y, int newX, int length)
{
	int halfLength = length >> 1;
	//goto(oX,oY) write(EMPY_CHAR) goto(nX,nY) write(BALL_STYLE)
	printf("%c[%d;%dH%c%c[%d;%dH%c", ESC, Y, oldX - halfLength, EMPTY_STYLE, ESC, Y, newX + halfLength, STRIKER_STYLE);
}

void updateStrikerDrawnPositionLeft(int oldX, int Y, int newX, int length)
{
	int halfLength = length >> 1;
	//goto(oX,oY) write(EMPY_CHAR) goto(nX,nY) write(BALL_STYLE)
	printf("%c[%d;%dH%c%c[%d;%dH%c", ESC, Y, newX - halfLength, STRIKER_STYLE, ESC, Y, oldX + halfLength, EMPTY_STYLE);
}

void setStrikerColor()
{
	fgcolor(FCOLOR_BLUE);
}

void clearStriker(int x, int y, int length)
{
	sdraw(x, y, length, EMPTY_STYLE);
}

void clearStrikerLeft(int x, int y, int length)
{
	gotoxy(x + (length >> 1), y); // go to right of bouncer
	printf("%c", EMPTY_STYLE);
}

void clearStrikerRight(int x, int y, int length)
{
	gotoxy(x - (length >> 1), y); // go to left of bouncer
	printf("%c", EMPTY_STYLE);
}

void drawStriker(int x, int y, int length)
{
	setStrikerColor();
	sdraw(x, y, length, STRIKER_STYLE);
}

void drawStrikerLeft(int x, int y, int length)
{
	gotoxy(x - (length >> 1), y); // go to left of bouncer
	setStrikerColor();
	printf("%c", STRIKER_STYLE);
}

void drawStrikerRight(int x, int y, int length)
{
	gotoxy(x + (length >> 1), y); // go to right of bouncer
	setStrikerColor();
	printf("%c", STRIKER_STYLE);
}

void moveStrikerLeft(struct TStriker *vStriker)
{
	int oldX = vStriker->position.x;
	setStrikerColor();
	vStriker->position.x--;
	updateStrikerDrawnPositionLeft(oldX,  vStriker->position.y, vStriker->position.x, vStriker->length);
}

void moveStrikerRight(struct TStriker *vStriker)
{
	int oldX = vStriker->position.x;
	setStrikerColor();
	vStriker->position.x++;
	updateStrikerDrawnPositionRight(oldX, vStriker->position.y, vStriker->position.x, vStriker->length);
}

//Rendering nextstate Bouncer
void moveStriker(struct TStriker *vStriker, int gameSizeX, char rightButtonPressed, char leftButtonPressed) {
	setStrikerColor();
	if (rightButtonPressed && vStriker->position.x + (vStriker->length >> 1) + 1 < gameSizeX) {
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

//bounce off striker at different angles
void bounceStriker(struct TStriker *vStriker, struct TBall balls[MAX_BALL_COUNT]){
	int ballIndex;
	for(ballIndex = 0; ballIndex < MAX_BALL_COUNT; ballIndex++)
	{
		if(IS_ALIVE(balls[ballIndex].data))
		{
			struct TBall *ball = &balls[ballIndex];
			int ballx = FIX14_TO_INT(ball->position.x);//truncation
			int bally = FIX14_TO_INT(ball->position.y);//truncation
			int strx = vStriker->position.x;//truncation
			int stry = vStriker->position.y;//truncation
			int strhl = vStriker->length >> 1; //half length of striker
		
			if ((bally == stry - 1) && ballx >= strx - strhl - 1 && ballx <= strx + strhl + 1 && ball->angle >= 180) 
			{	
				int angle = ball->angle - 180;
				ball->angle = 180 - (angle);
				if(angle == 0)
				{
					angle = 20;
				}
				if(ballx - strx == 0)
				{
				}
				else if(ballx - strx < 0)
				{			
					if(ballx  - strx < - vStriker->length+1 >> 2)
					{
						ball->angle += angle / 2;
					}
					else
					{
						ball->angle += angle / 3;
					}
				}
				else
				{
					if(ballx  - strx >  vStriker->length+1 >> 2)
					{
						ball->angle -= ball->angle / 2;
					}
					else
					{
						ball->angle -= ball->angle / 3;
					}
				}
				playBounceSound();
			}
		}
	}
}

void moveStrikerPreShot(struct TBall *vball, struct TStriker *vStriker, int gameSizeX, char rightButtonPressed, char leftButtonPressed) {
    if (rightButtonPressed && vStriker->position.x + (vStriker->length >> 1) + 1 < gameSizeX) {
		//render new ball position
		long oldX = vball->position.x;
		long oldY = vball->position.y;
		vball->position.x += TO_FIX14(1);
		setBallColor(vball);
		updateBallDrawnPosition(oldX, oldY, vball->position.x, vball->position.y);

		//render new bouncer position
		moveStrikerRight(vStriker);	
	}
	else if(leftButtonPressed && vStriker->position.x - (vStriker->length >> 1) - 2 > 0) {
		//render new ball position
		long oldX = vball->position.x;
		long oldY = vball->position.y;
		vball->position.x -= TO_FIX14(1);
		setBallColor(vball);
		updateBallDrawnPosition(oldX, oldY, vball->position.x, vball->position.y);

		//render new bouncer position
		moveStrikerLeft(vStriker);
	}
}
