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

#define BALL_STYLE 254
#define EMPY_CHAR ' '

void updateBallDrawnPosition(long oldX, long oldY, long newX, long newY)
{
	int oX = FIX14_TO_INT(oldX);
	int oY = FIX14_TO_INT(oldY);
	int nX = FIX14_TO_INT(newX);
	int nY = FIX14_TO_INT(newY);

	//goto(oX,oY) write(EMPY_CHAR) goto(nX,nY) write(BALL_STYLE)
	printf("%c[%d;%dH%c%c[%d;%dH%c", ESC, oY, oX, EMPY_CHAR, ESC, nY, nX, BALL_STYLE);
}

void clearBall(long x, long y)
{
	gotoxy(FIX14_TO_INT(x), FIX14_TO_INT(y));
	printf("%c", EMPY_CHAR);
}

void setBallColor(struct TBall *ball)
{
	fgcolor(COLOR(ball->data));
}

//Initialize ball
void initBall(struct TBall *vBall,int x, int y, char color, int angle, long velocity, char alive){
	vBall->position.x = TO_FIX14(x);
	vBall->position.y = TO_FIX14(y);
	vBall->angle = angle;
	vBall->velocity = velocity;
	vBall->data = (color | (alive << ALIVE_BIT_SHIFT));
	setBallColor(vBall);
	if(alive)
	{
		updateBallDrawnPosition(vBall->position.x, vBall->position.y, vBall->position.x, vBall->position.y);
	}
}

void moveBall(struct TBall *vball)
{
	vball->position.x += FIX14_MULT(vball->velocity,cos(vball->angle));
	vball->position.y += FIX14_MULT(vball->velocity,-sin(vball->angle));
}

//Rendering nextstate Ball
void updateBalls(struct TBall balls[MAX_BALL_COUNT]) {
	int ballIndex;
	for(ballIndex = 0; ballIndex < MAX_BALL_COUNT; ballIndex++)
	{
		if(IS_ALIVE(balls[ballIndex].data))
		{
			struct TBall *ball = &balls[ballIndex];
			if(ball->velocity > 0){
				long oldX = ball->position.x;
				long oldY = ball->position.y;
				moveBall(ball);
				if(FIX14_TO_INT(oldX) != ball->position.x ||
				   FIX14_TO_INT(oldY) != ball->position.y)
				{
					setBallColor(ball);
					updateBallDrawnPosition(oldX, oldY, ball->position.x, ball->position.y);
				}
			}
			else 
			{
				ball->velocity = (TO_FIX14(1) + (TO_FIX14(1) >> 1)) >> 1;
			}
		}
	}
}

char isBallDead(struct TBall balls[MAX_BALL_COUNT], int gameSizeY){
	char isBallsDead = 0;
	int ballIndex;
	for(ballIndex = 0; ballIndex < MAX_BALL_COUNT; ballIndex++)
	{
		if(IS_ALIVE(balls[ballIndex].data))
		{
			struct TBall *ball = &balls[ballIndex];
			int ballx = FIX14_TO_INT(ball->position.x);
			int bally = FIX14_TO_INT(ball->position.y);

			if (bally >= gameSizeY - 1 && ball->angle > 180 && ball->angle < 360){
				ball->data &= ~(1 << ALIVE_BIT_SHIFT);//ball is dead, set alive bit to 0
				clearBall(ball->position.x, ball->position.y);
				isBallsDead = 1;
				playDeathBallSound();
			}
		}
	}
	return isBallsDead;
}

void impact(struct TBall balls[MAX_BALL_COUNT], struct TStriker *vStriker, int gameSizeX, int gameSizeY) {
	int ballIndex;
	for(ballIndex = 0; ballIndex < MAX_BALL_COUNT; ballIndex++)
	{
		if(IS_ALIVE(balls[ballIndex].data))
		{
			struct TBall *ball = &balls[ballIndex];
			int ballx = FIX14_TO_INT(ball->position.x);//truncation
			int bally = FIX14_TO_INT(ball->position.y);//truncation
			int strx  = vStriker->position.x;
			int stry  = vStriker->position.y;
			int strhl = vStriker->length >> 1;//half length of striker
		
			//bounce off right and left walls	
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

