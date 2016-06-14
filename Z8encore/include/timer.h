#ifndef _TIMER_H_
#define _TIMER_H_

struct TTime
{
	int miliseconds;
	char seconds;
	char minutes;
	int hours;
};

struct TTimer
{
	long lastEvent;
	long interval;
};

void startTimer();
void stopTimer();
struct Ttime getStructuredTime();
unsigned long getElapsedMiliseconds();

void initTimer(struct TTimer *timer, long interval);
void waitForEvent(struct TTimer *timer);

#endif
