//this file assuems to clock runs with 2000hz
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "timer.h"
#include "clockio.h"

#define ONE_SECOND 1000
#define ONE_MINUTE ONE_SECOND * 60
#define ONE_HOUR ONE_MINUTE * 60

unsigned long startMilisecond = 0;
unsigned long endMilisecond = 0;

void startTimer()
{
	startMilisecond = getMiliseconds();
	endMilisecond = 0;
	startClock();
}

void stopTimer()
{
	endMilisecond = getMiliseconds();
	stopClock();
}

void initTimer(struct TTimer *timer, long interval)
{
	timer->lastEvent = 0;
	timer->interval = interval;
}

void waitForEvent(struct TTimer *timer)
{
	while(timer->lastEvent + timer->interval > getMiliseconds()) {}
	timer->lastEvent = getMiliseconds();
}

struct TTime getStructuredTime()
{
	unsigned long milisecondsPassed = getElapsedMiliseconds();
	struct TTime timePassed;
	timePassed.hours       = (milisecondsPassed) / ONE_HOUR;
	timePassed.minutes     = (milisecondsPassed - timePassed.hours * ONE_HOUR) / ONE_MINUTE;
	timePassed.seconds     = (milisecondsPassed - timePassed.hours * ONE_HOUR - timePassed.minutes * ONE_MINUTE) / ONE_SECOND;
	timePassed.miliseconds = (milisecondsPassed - timePassed.hours * ONE_HOUR - timePassed.minutes * ONE_MINUTE - timePassed.seconds * ONE_SECOND);
	return timePassed;
}

unsigned long getElapsedMiliseconds()
{
	return endMilisecond - startMilisecond;
}




