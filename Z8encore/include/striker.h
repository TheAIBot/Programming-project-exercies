#ifndef _STRIKER_H_
#define _STRIKER_H_

#include "ansi.h"

struct TStriker
{
	struct TVector position;
	char length;
	char skin;
};

void initStriker(struct TStriker *vStriker,int x, int y,int l);
void moveStrikerLeft(struct TStriker *vStriker);
void moveStrikerRight(struct TStriker *vStriker);
void moveStriker(struct TStriker *vStriker, char rightButtonPressed, char leftButtonPressed);
#endif