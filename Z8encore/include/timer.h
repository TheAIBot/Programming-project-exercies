#ifndef _TIMER_H_
#define _TIMER_H_

/*
TTimer:
This struct allows the code only run at a specific interval
by waiting a certain amount of time before the timers waitForEvent
will return and allow other code to run

lastEvent:
Holds the amount of miliseconds that had run when the timer last
time allowed to run


interval:
The amount of miliseconds between each event. If only 20ms has passed
and interval is set to 30 then waitForEvent will wait for 10ms

*/

struct TTimer
{
	long lastEvent;
	long interval;
};

void initTimer(struct TTimer *timer, long interval);
void waitForEvent(struct TTimer *timer);

#endif
