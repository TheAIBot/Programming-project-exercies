#ifndef _SOUND_H_
#define _SOUND_H_

#include "ansi.h"

void initSoundPin();
void initSoundClock();

void playBounceSound(char h);
void playWallSound();
void playIndestructibleBrickSound();
void playDeathBallSound();
void playDeathBrickSound();
void playStartGameSound();
void playGameOverSound();
void playGameWinSound();
void playBossDeathSound();

#endif
