#include <eZ8.h>
#include <sio.h>
#include "color.h"
#include "striker.h"
#include "ansi.h"
#include "fixedmath.h"
#include "SineLUT.h"

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

void updateStrikerDrawnPosition(int oldX, int oldY, int newX, int newY, int length)
{
	//goto(oX,oY) write(EMPY_CHAR) goto(nX,nY) write(BALL_STYLE)
	printf("%c[%d;%dH%c%c[%d;%dH%c", ESC, oldY, oldX, EMPTY_STYLE, ESC, newY, newX + length, STRIKER_STYLE);
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
	int oldY = vStriker->position.y;
	vStriker->position.x--;
	updateStrikerDrawnPosition(oldX, oldY, vStriker->position.x, vStriker->position.y, vStriker->length);
	//clearStrikerLeft(vStriker->position.x, vStriker->position.y, vStriker->length);
	//vStriker->position.x--;
	//drawStrikerLeft(vStriker->position.x, vStriker->position.y, vStriker->length);
}

void moveStrikerRight(struct TStriker *vStriker)
{
	int oldX = vStriker->position.x;
	int oldY = vStriker->position.y;
	vStriker->position.x++;
	updateStrikerDrawnPosition(oldX, oldY, vStriker->position.x, vStriker->position.y, vStriker->length);
	//clearStrikerRight(vStriker->position.x, vStriker->position.y, vStriker->length);
	//vStriker->position.x++;
	//drawStrikerRight(vStriker->position.x, vStriker->position.y, vStriker->length);
}

//Rendering nextstate Bouncer
void moveStriker(struct TStriker *vStriker, int gameSizeX, char rightButtonPressed, char leftButtonPressed) {
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
void bounceStriker(struct TStriker *vStriker, struct TBall *vball){
	int ballx = FIX14_TO_INT(vball->position.x);//truncation
	int bally = FIX14_TO_INT(vball->position.y);//truncation
	int strx = vStriker->position.x;//truncation
	int stry = vStriker->position.y;//truncation
	int strhl = vStriker->length >> 1; //half length of striker
	int ang = vball->angle;
	int ail = vball->angle - 270;  //incomming angle for ball incomming from left
  int air = 270 - vball->angle;  //incomming angle for ball incomming from right	

	if ((bally == stry - 1) && ballx >= strx - strhl - 1 && ballx <= strx + strhl + 1 && vball->angle >= 180) 
	{	
		int angle = vball->angle - 180;
		vball->angle = 180 - (angle);
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
				vball->angle += angle / 2;
			}
			else
			{
				vball->angle += angle / 3;
			}
		}
		else
		{
			if(ballx  - strx >  vStriker->length+1 >> 2)
			{
				vball->angle -= vball->angle / 2;
			}
			else
			{
				vball->angle -= vball->angle / 3;
			}
		}
		/*
	//When incomming from left
		if (0 <= ail && ail <= 90 && ballx - strx > 0){ //bouncing off right of striker 
			if (0 <= ail && ail <= 50 && ballx - strx <= vStriker->length+1 >> 2) { //right medium: within angle intervall ai=0-50 degrees
				vball->angle = 90 - ((3*ail) >> 1);}
 			else if (0 <= ail && ail <= 25 && ballx - strx > vStriker->length+1 >> 2){ //right end: within angel intervall ai=0-25 degrees
				vball->angle = 90 - 3*ail;}
			else {vball->angle = 0;} //for every other case set refracted angle to 20 degrees relative to the x-axis
		}
		if (0 <= ail && ail <= 90 && ballx - strx < 0){ //bouncing off left of striker 
			if (ballx - strx <= - vStriker->length+1 >> 2) { //Left medium: within angle intervall ai=0-90 degrees
				vball->angle = 90 - (ail << 1 )/3;}
			else { vball->angle = 90 - ail/3;} 			     //Left end: within angle intervall ai=0-90 degrees
		} 


		//When incomming from right	
		if (0 <= air && air <= 90 && ballx - strx < 0){ //bouncing off left of striker 
			if (0 <= ail && ail <= 50 && ballx - strx <= - vStriker->length+1 >> 2) {   //left medium: within angle intervall ai=0-50 degrees
				vball->angle = 90 + ((3*air) >> 1);}
			else if (0 <= ail && ail <= 25 && ballx - strx > - vStriker->length+1 >> 2) { //right end: within angel intervall ai=0-25 degrees
				vball->angle = 90 + 3*air;}
			else {vball->angle = 160;} //for every other case set refracted angle to 160 degrees relative to the x-axis

		}
		if (0 <= air && air <= 90 && ballx - strx > 0){//bouncing off right of striker 
			if (ballx - strx <= vStriker->length+1 >> 2) { //right medium:  within angle intervall ai=0-90 degrees
				vball->angle = 90 + (air << 1 )/3;}
			else {vball->angle = 90 + air/3;}   		   //right end: within angle intervall ai=0-90 degrees
		} 
	*/	
	}
}
