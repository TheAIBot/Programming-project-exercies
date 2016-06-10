#ifndef _POWERUP_H_
#define _POWERUP_H_

#include "ansi.h"

struct TPowerUp
{
	char powerupType;
	struct TVector position;
	struct TVector motion;
}

#endif