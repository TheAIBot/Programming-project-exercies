#include <eZ8.h>
#include <sio.h>
#include "color.h"
#include "striker.h"
#include "ansi.h"
#include "fixedmath.h"
#include "trigonometry.h"
#include "sound.h"
#include "game.h"

//the character to draw the stiker with
#define STRIKER_STYLE 178 
#define EMPTY_STYLE ' '

//draw the stiker with a certain character
void sdraw(int x, int y, int length, char c)
{
	int i;
	//x, y is the middle of the striker so to draw the striker
	//the x,y position has to moved by half the length of the striker the the left
	gotoxy(x - (length >> 1), y);
	for(i = 0; i < length; i++)
	{
		printf("%c", c);
	}
}

//draw the striekr one position to the right
void updateStrikerDrawnPositionRight(int oldX, int Y, int newX, int length)
{
	int halfLength = length >> 1;
	//goto(oX,oY) write(EMPY_CHAR) goto(nX,nY) write(BALL_STYLE)
	printf("%c[%d;%dH%c%c[%d;%dH%c", ESC, Y, oldX - halfLength, EMPTY_STYLE, ESC, Y, newX + halfLength, STRIKER_STYLE);
}

//draw the striker one position to the left
void updateStrikerDrawnPositionLeft(int oldX, int Y, int newX, int length)
{
	int halfLength = length >> 1;
	//goto(oX,oY) write(EMPY_CHAR) goto(nX,nY) write(BALL_STYLE)
	printf("%c[%d;%dH%c%c[%d;%dH%c", ESC, Y, newX - halfLength, STRIKER_STYLE, ESC, Y, oldX + halfLength, EMPTY_STYLE);
}

//set the foreground color to thecolor of the striker
void setStrikerColor()
{
	fgcolor(FCOLOR_BLUE);
}

//remove the striker from the screen
void clearStriker(int x, int y, int length)
{
	sdraw(x, y, length, EMPTY_STYLE);
}

void drawStriker(int x, int y, int length)
{
	setStrikerColor();
	sdraw(x, y, length, STRIKER_STYLE);
}

//move and redraw the striker one position to the left
void moveStrikerLeft(struct TStriker *vStriker)
{
	int oldX = vStriker->position.x;
	setStrikerColor();
	vStriker->position.x--;
	updateStrikerDrawnPositionLeft(oldX,  vStriker->position.y, vStriker->position.x, vStriker->length);
}

//move and redraw the striker one position to the right
void moveStrikerRight(struct TStriker *vStriker)
{
	int oldX = vStriker->position.x;
	setStrikerColor();
	vStriker->position.x++;
	updateStrikerDrawnPositionRight(oldX, vStriker->position.y, vStriker->position.x, vStriker->length);
}

//move the striker left or right depending on the input
void moveStriker(struct TStriker *vStriker, int gameSizeX, char rightButtonPressed, char leftButtonPressed) {
	//if player want to move striker right and the striker isn't already as right as it can be
	if (rightButtonPressed && vStriker->position.x + (vStriker->length >> 1) + 1 < gameSizeX) {
		moveStrikerRight(vStriker);	
	}
	//if player want to move striker left and the striker isn't already as left as it can be
	else if(leftButtonPressed && vStriker->position.x - (vStriker->length >> 1) - 2 > 0) {
		moveStrikerLeft(vStriker);
	}
}

//initialize striker at a specific position with a specific length
void initStriker(struct TStriker *vStriker, int x, int y, int l){
	vStriker->position.x = x;
	vStriker->position.y = y;
	vStriker->length = l;
	drawStriker(x, y, l);	
}

//Bounce balls of the striker at an angle depending on where the balls hit the striker
//The striker is splitted up into 5 different zones where the balls angle are changed differently in all 5 zones
//The five zones are, from the right: right, middle right, middle, middle left and left zone
void bounceStriker(struct TStriker *vStriker, struct TBall balls[MAX_BALL_COUNT]){
	int ballIndex;
	for(ballIndex = 0; ballIndex < MAX_BALL_COUNT; ballIndex++)
	{
		//only update balls that are alive
		if(IS_ALIVE(balls[ballIndex].data))
		{
			struct TBall *ball = &balls[ballIndex];
			//the balls position is in fix14 format and the strikers position is in
			//fix0 format so to compare the two the balls position is converted to the fix0 format
			int ballx = FIX14_TO_INT(ball->position.x);
			int bally = FIX14_TO_INT(ball->position.y);
			int strx = vStriker->position.x;
			int stry = vStriker->position.y;
			int strhl = vStriker->length >> 1; //half length of striker
		
			//is the ball just above the striker and is the ball within the borders of the striker and is the balls
			//angle pointing down?
			if ((bally == stry - 1) && ballx >= strx - strhl - 1 && ballx <= strx + strhl + 1 && ball->angle >= 180) 
			{	
				//First the ball is bounces off the striker and then the balls angle is changed a bit depending on where
				//the ball hits the striker

				int angle = ball->angle - 180;
				//bounce the ball off the striker 
				ball->angle = 180 - (angle);

				//when the ball hits the middle of the striker
				//then no change to the balls angle should be made
				if(ballx - strx == 0)
				{
				}
				//if the ball is in the left or middle left zone
				else if(ballx - strx < 0)
				{			
					//is in the left zone
					if(ballx  - strx < - vStriker->length + 1 >> 2)
					{
						ball->angle += angle / 2;
					}
					//is in the middle left zone
					else
					{
						ball->angle += angle / 3;
					}
				}
				//is in the right or middle right zone
				else
				{
					//is in the right zone
					if(ballx  - strx >  vStriker->length + 1 >> 2)
					{
						ball->angle -= ball->angle / 2;
					}
					//is in the middle right zone
					else
					{
						ball->angle -= ball->angle / 3;
					}
				}
				playWallSound();
			}
		}
	}
}

//move the striker and the players main ball ath the same tim to the left or right
void moveStrikerPreShot(struct TBall *vball, struct TStriker *vStriker, int gameSizeX, char rightButtonPressed, char leftButtonPressed) {
	//move striker right and striker won't hit game wall to the right
    if (rightButtonPressed && vStriker->position.x + (vStriker->length >> 1) + 1 < gameSizeX) {
		//render new ball position
		long oldX = vball->position.x;
		long oldY = vball->position.y;
		//increment the balls x position to move it one to the right.
		//as the balls position is in fix14 format the 1 has to be changed to fix14 format aswell
		//increment it
		vball->position.x += TO_FIX14(1);
		setBallColor(vball);
		updateBallDrawnPosition(oldX, oldY, vball->position.x, vball->position.y);

		//redraw striker position
		moveStrikerRight(vStriker);	
	}
	//move striker left and striker won't hit game wall to the left
	else if(leftButtonPressed && vStriker->position.x - (vStriker->length >> 1) - 2 > 0) {
		//render new ball position
		long oldX = vball->position.x;
		long oldY = vball->position.y;
		//decrement the balls x position to move it one to the right.
		//as the balls position is in fix14 format the 1 has to be changed to fix14 format aswell
		//decrement it
		vball->position.x -= TO_FIX14(1);
		setBallColor(vball);
		updateBallDrawnPosition(oldX, oldY, vball->position.x, vball->position.y);

		//redraw striker position
		moveStrikerLeft(vStriker);
	}
}
