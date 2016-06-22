#ifndef _RANDOM_H_
#define _RANDOM_H_

#include "clockio.h"

//uses the amount of milixeconds since the game started to return a random number
//between min and excluding max
#define RANDOM(min, max) ((getMiliseconds() % (max - min)) + min)

#endif