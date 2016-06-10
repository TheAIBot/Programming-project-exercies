#ifndef _STRIKER_H_
#define _STRIKER_H_


struct TStriker
{
	struct TVector position;
	char length;
	char skin;
}

void initBouncer(struct TBouncer *vbouncer,int x, int y,int l);
void drawBouncer(int x, int y, int length);
void clearBouncer(int x, int y, int length);

#endif