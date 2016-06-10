#ifndef _BOSS_H_
#define _BOSS_H_

struct TBoss
{
	struct TVector position;
	struct TVector size;
	struct TBall *shots;
	char health;
	char color;
	char points;
}


#endif