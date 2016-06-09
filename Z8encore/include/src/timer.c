//this file assuems to clock runs with 2000hz
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "timer.h"
#include "clockio.h"

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
	startClock();
}

struct Ttime getStructuredTime()
{
	const unsigned long ONE_SECOND = 1000;
	const unsigned long ONE_MINUTE = oneSecond * 60;
	const unsigned long ONE_HOUR = oneMinute * 60;

	unsigned long milisecondsPassed = getElapsedMiliseconds();
	time timePassed;
	timePassed.hours       = (milisecondsPassed) / ONE_HOUR;
	timePassed.minutes     = (milisecondsPassed - timePassed.hours * ONE_HOUR) / ONE_MINUTE;
	timePassed.seconds     = (milisecondsPassed - timePassed.hours * ONE_HOUR - timePassed.minutes * ONE_MINUTE) / ONE_SECOND;
	timePassed.miliseconds = (milisecondsPassed - timePassed.hours * ONE_HOUR - timePassed.minutes * ONE_MINUTE - timePassed.seconds * ONE_SECOND);
	return &time;
}

unsigned long getElapsedMiliseconds()
{
	return endMilisecond - startMilisecond;
}




