#ifndef _ANSI_H_
#define _ANSI_H_

struct TVector
{
	int x;
	int y;
};

void fgcolor(int);
void bgcolor(int);
void color();
void resetbgcolor();
void clrscr();
void clreol();
void gotoxy(int, int);
void underline(char);
void blink(char);
void reverse(char);
void movecursor(int, int);
void window(int, int, int, int ,char, char[]);
void initVector(struct TVector * v, long, long);
void rotate(struct TVector *v, int angle);

#endif
