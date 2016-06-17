#ifndef _RANDOM_H_
#define _RANDOM_H_

#include "clockio.h"

#define RANDOM(min, max) ((getMiliseconds() % (max - min)) + min)

#endif