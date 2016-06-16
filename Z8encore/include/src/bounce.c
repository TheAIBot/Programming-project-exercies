#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "bounce.h"

int bounceHorizontal(int angle)
{
	return 360 - angle;
}

int bounceVertical(int angle)
{
	angle = 180 - angle;
	if(angle < 0)
	{
		angle = angle + 360;//find better solution
	}
	return angle;
}
