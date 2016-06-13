#include <eZ8.h>
#include <sio.h>
#include "color.h"
#include "striker.h"
#include "ansi.h"
#include "fixedmath.h"
#include "SineLUT.h"

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
void bounceStriker(struct TStriker *vStriker, struct TBall *vball, int gameSizeY){
	int ballx = FIX14_TO_INT(vball->position.x);//truncation
	int bally = FIX14_TO_INT(vball->position.y);//truncation
	int strx = vStriker->position.x;//truncation
	int stry = vStriker->position.y;//truncation
	int strhl = vStriker->length >> 1; //half length of striker
	
	if ((bally == gameSizeY - 1) && (ballx >= strx - strhl - 1 && ballx <= strx + strhl + 1)) {
		int ail = vball->angle - 270;  //incomming angle for ball incomming from left
 	    int air = 90 - vball->angle;  //incomming angle for ball incomming from right
		//When incomming from left
		if (FIX14_TO_INT(vball->momentum.x) > 0 && ballx - strx > 0){ //Right of striker
			if (ballx - strx <= strhl >> 1) { //Right medium
				vball->angle = 90 - (3*ail) >> 1;}
			else {   					   //Right end
			   vball->angle = 90 - 3*ail;}

		}
		if (FIX14_TO_INT(vball->momentum.x) > 0 && ballx - strx < 0){
			if (ballx - strx <= - strhl >> 1) { //Left medium
				vball->angle = 90 - (ail << 1 )/3;}
			else {   					   //Left end
			   vball->angle = 90 - ail/3;}
		} 
		//When incomming from right		
		if (FIX14_TO_INT(vball->momentum.x) < 0 && ballx - strx < 0){
			if (ballx - strx <= - strhl >> 1) { //Right medium
				vball->angle = 90 - (3*air) >> 1;}
			else {   					   //Right end
			   vball->angle = 90 - 3*air;}

		}
		if (FIX14_TO_INT(vball->momentum.x) > 0 && ballx - strx > 0){
			if (ballx - strx <= strhl >> 1) { //Left medium
				vball->angle = 90 - (air << 1 )/3;}
			else {   					   //Left end
			   vball->angle = 90 - air/3;}
		} 
	}
	vball->momentum.x = FIX14_MULT(vball->velocity, cos(vball->angle));
	vball->momentum.y = FIX14_MULT(vball->velocity, -sin(vball->angle));

}
