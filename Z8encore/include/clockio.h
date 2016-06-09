#ifndef _CLOCKIO_H_
#define _CLOCKIO_H_

extern char LEDupdateFlag;

void delay(int times);
void waitOnce();
void initClock();
void startClock();
void stopClock();
unsigned long getMiliseconds();

#endif
