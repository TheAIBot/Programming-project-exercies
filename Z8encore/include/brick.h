#ifndef _BRICK_H_
#define _BRICK_H_

struct TBrick
{
	struct TVector position;
	struct TVector size;
	char health;
	struct TVector motion;
	char dropChance;
};

#endif