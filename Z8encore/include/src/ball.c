#include <eZ8.h>
#include <sio.h>
#include "ball.h"
#include "ansi.h"
#include "SineLUT.h"
#include "fixedmath.h"
#include "clockio.h"

#define BALL_STYLE 254
#define EMPY_CHAR ' '

void updateBallDrawnPosition(long oldX, long oldY, long newX, long newY)
{
	int oX = ROUND_TO_INT(oldX);
	int oY = ROUND_TO_INT(oldY);
	int nX = ROUND_TO_INT(newX);
	int nY = ROUND_TO_INT(newY);

	//goto(oX,oY) write(EMPY_CHAR) goto(nX,nY) write(BALL_STYLE)
	printf("%c[%d;%dH%c%c[%d;%dH%c", ESC, oY, oX, EMPY_CHAR, ESC, nY, nX, BALL_STYLE);
}

void setBallColor(struct TBall *ball)
{
	fgcolor(ball->color);
}

//Initialize ball
void initBall(struct TBall *vBall,int x, int y, char color, int angle, long velocity){
	vBall->position.x = TO_FIX14(x);
	vBall->position.y = TO_FIX14(y);
	vBall->angle = angle;
	vBall->velocity = velocity;
	vBall->color = color;
	fgcolor(color);
	updateBallDrawnPosition(vBall->position.x, vBall->position.y, vBall->position.x, vBall->position.y);
}

void moveBall(struct TBall *vball)
{
	vball->position.x += FIX14_MULT(vball->velocity,cos(vball->angle));
	vball->position.y += FIX14_MULT(vball->velocity,-sin(vball->angle));
}

//Rendering nextstate Ball
void updateBall(struct TBall *vball) {
	if(vball->velocity > 0){
		long oldX = vball->position.x;
		long oldY = vball->position.y;
		moveBall(vball);
		if(FIX14_TO_INT(oldX) != vball->position.x ||
		   FIX14_TO_INT(oldY) != vball->position.y)
		{
			updateBallDrawnPosition(oldX, oldY, vball->position.x, vball->position.y);
		}
	}
	else 
	{
		vball->velocity = TO_FIX14(1) >> 1;
	}
}

char isBallDead(struct TBall *vball, int gameSizeY){
	int ballx = FIX14_TO_INT(vball->position.x);//truncation
	int bally = FIX14_TO_INT(vball->position.y);//truncation
	if (bally==gameSizeY-1){
		return 1;
	}
	return 0;
}

void impact(struct TBall *vball, struct TStriker *vStriker, int gameSizeX, int gameSizeY) {
	int ballx=FIX14_TO_INT(vball->position.x);//truncation
	int bally=FIX14_TO_INT(vball->position.y);//truncation
	int strx = vStriker->position.x;
	int stry = vStriker->position.y;
	int strhl = vStriker->length >> 1;//half length of striker

	//bounce off right and left walls	
	if (ballx >= gameSizeX - 1 && (vball->angle < 90 || vball->angle > 270) || 
			ballx <= 2             && vball->angle > 90 && vball->angle < 270) {
		vball->angle = 180 - vball->angle;
		if(vball->angle < 0)
		{
			vball->angle = vball->angle + 360;//find better solution
		}
	}
	//bounce off top wall and central striker
	if (bally <= 2){
		vball->angle= 360 - vball->angle;
	}
}

