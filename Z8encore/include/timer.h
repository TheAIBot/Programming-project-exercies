#ifndef _TIMER_H_
#define _TIMER_H_

struct TTime
{
	int miliseconds;
	char seconds;
	char minutes;
	int hours;
};

void startTimer();
void stopTimer();
struct Ttime getStructuredTime();
unsigned long getElapsedMiliseconds();

#endif
