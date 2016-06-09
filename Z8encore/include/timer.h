#ifndef _TIMER_H_
#define _TIMER_H_

typedef struct
{
	int miliseconds;
	char seconds;
	char minutes;
	int hours;
} timer;

void startTimer();
void stopTimer();
struct Ttime getStructuredTime();
unsigned long getElapsedMiliseconds();

#endif