#include <eZ8.h>
#include <sio.h>
#include "ball.h"
#include "ansi.h"
#include "trigonometry.h"
#include "fixedmath.h"
#include "clockio.h"
#include "bounce.h"
#include "sound.h"
#include "game.h"

//char a ball is drawn on the screen with
#define BALL_STYLE 254
#define EMPY_CHAR ' '

//Clears the ball at its previous position and draws it at its new position
void updateBallDrawnPosition(long oldX, long oldY, long newX, long newY)
{
	int oX = FIX14_TO_INT(oldX);
	int oY = FIX14_TO_INT(oldY);
	int nX = FIX14_TO_INT(newX);
	int nY = FIX14_TO_INT(newY);

	//goto(oX,oY) write(EMPY_CHAR) goto(nX,nY) write(BALL_STYLE)
	printf("%c[%d;%dH%c%c[%d;%dH%c", ESC, oY, oX, EMPY_CHAR, ESC, nY, nX, BALL_STYLE);
}

//removes a ball from the screen at the specified ball position
void clearBall(long x, long y)
{
	gotoxy(FIX14_TO_INT(x), FIX14_TO_INT(y));
	printf("%c", EMPY_CHAR);
}

//sets the foreground color the the balls color
void setBallColor(struct TBall *ball)
{
	fgcolor(COLOR(ball->data));
}

//Initialize ball
void initBall(struct TBall *vBall,int x, int y, char color, int angle, long velocity, char alive){
	// need to convert x, y to the Fix14 format as that's what the ball uses to specify its position
	vBall->position.x = TO_FIX14(x);
	vBall->position.y = TO_FIX14(y);

	vBall->angle = angle;
	vBall->velocity = velocity;
	//set the color and wether the ball is alive at once in the same char
	vBall->data = (color | (alive << ALIVE_BIT_SHIFT));
	//Need to draw the ball if it's a live to begin with
	if(alive)
	{
		setBallColor(vBall);
		updateBallDrawnPosition(vBall->position.x, vBall->position.y, vBall->position.x, vBall->position.y);
	}
}

//moves the ball
void moveBall(struct TBall *vball)
{
	vball->position.x += FIX14_MULT(vball->velocity,cos(vball->angle));
	vball->position.y += FIX14_MULT(vball->velocity,-sin(vball->angle));
}

//Update an array of balls
void updateBalls(struct TBall balls[MAX_BALL_COUNT]) {
	int ballIndex;
	for(ballIndex = 0; ballIndex < MAX_BALL_COUNT; ballIndex++)
	{
		//only update balls that are alive
		if(IS_ALIVE(balls[ballIndex].data))
		{
			struct TBall *ball = &balls[ballIndex];
			//if a ball doesn't have a speed then set one or move and redraw the ball
			if(ball->velocity > 0){
				long oldX = ball->position.x;
				long oldY = ball->position.y;
				moveBall(ball);
				//only redraw the ball if the balls new position differes from its old position
				if(FIX14_TO_INT(oldX) != ball->position.x ||
				   FIX14_TO_INT(oldY) != ball->position.y)
				{
					setBallColor(ball);
					updateBallDrawnPosition(oldX, oldY, ball->position.x, ball->position.y);
				}
			}
			else 
			{
				//set the balls speed to (1 + (1 / 2)) / 2 = 0.75
				ball->velocity = (TO_FIX14(1) + (TO_FIX14(1) >> 1)) >> 1;
			}
		}
	}
}

//Checks wether a ball is supposed to be dead and kills it if it's supposed to be dead
//returns 1 if any ball died or 0 if no ball died
char isBallDead(struct TBall balls[MAX_BALL_COUNT], int gameSizeY){
	char isBallsDead = 0;
	int ballIndex;
	for(ballIndex = 0; ballIndex < MAX_BALL_COUNT; ballIndex++)
	{
		//only check alive balls
		if(IS_ALIVE(balls[ballIndex].data))
		{
			struct TBall *ball = &balls[ballIndex];
			int ballx = FIX14_TO_INT(ball->position.x);
			int bally = FIX14_TO_INT(ball->position.y);

			//is the ball at the bottom of the level and is the balls angle pointing down?
			if (bally >= gameSizeY - 1 && ball->angle > 180 && ball->angle < 360){
				//ball is dead, only set alive bit to 0
				ball->data &= ~(1 << ALIVE_BIT_SHIFT);
				clearBall(ball->position.x, ball->position.y);
				isBallsDead = 1;
				playDeathBallSound();
			}
		}
	}
	return isBallsDead;
}

//bounce balls of the games walls
void impact(struct TBall balls[MAX_BALL_COUNT], int gameSizeX, int gameSizeY) {
	int ballIndex;
	for(ballIndex = 0; ballIndex < MAX_BALL_COUNT; ballIndex++)
	{
		//only bounce balls that are alive
		if(IS_ALIVE(balls[ballIndex].data))
		{
			struct TBall *ball = &balls[ballIndex];
			int ballx = FIX14_TO_INT(ball->position.x);
			int bally = FIX14_TO_INT(ball->position.y);
		
			//bounce off right and left wall	
			if (ballx >= gameSizeX - 1 && (ball->angle < 90 || ball->angle > 270) || 
				ballx <= 2 && ball->angle > 90 && ball->angle < 270) {
				ball->angle = bounceVertical(ball->angle);
				playWallSound();
			}
			//bounce off top wall
			if (bally <= 2 && ball->angle > 0 && ball->angle < 180){
				ball->angle = bounceHorizontal(ball->angle);
				playWallSound();
			}
		}
	}
}

