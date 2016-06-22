//this file assuems to clock runs with 2000hz
#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "timer.h"
#include "clockio.h"


//init the timer with a specific interval
void initTimer(struct TTimer *timer, long interval)
{
	timer->lastEvent = 0;
	timer->interval = interval;
}

//waits for interval in ms has passed since this method was last run
//This makes it possible to have code run with the same frequency even though
//the code takes a different amount of time to execute unless ofcource 
//the code takes more time to execute than the interval and if that's the case
//then this method will return immediatly
void waitForEvent(struct TTimer *timer)
{
	//wait for interval in ms to pass since this method was last run
	//by continiously polling the clock forthe amount of miliseconds since
	//the timer started
	while(timer->lastEvent + timer->interval > getMiliseconds()) {}
	//sets the current time to the time this method was last run
	timer->lastEvent = getMiliseconds();
}




