#ifndef _RANDOM_H_
#define _RANDOM_H_

#include "timer.h"

#define RANDOM(min, max) ((getElapsedMiliseconds() % (max - min)) + min)

#endif