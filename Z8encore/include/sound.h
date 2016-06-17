#ifndef _SOUND_H_
#define _SOUND_H_

#include "ansi.h"

void timer1int();
void initSoundPin();
void initSoundClock();

void playBounceSound();
void playDeathBallSound();
void playDeathBrickSound();
void playStartGameSound();
void playGameOverSound();

#endif
