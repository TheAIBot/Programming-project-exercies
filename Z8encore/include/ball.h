#ifndef _BALL_H_
#define _BALL_H_

struct TBall
{	
	struct TVector position;
	struct TVector momentum;
	long velocity;
	long angle;
	char skin;
}

void initBall(struct TBall *vBall,int x, int y, char skin,long angle,long velocity);
void drawBall(char skin);

#endif