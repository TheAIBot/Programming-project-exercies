#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "bounce.h"

//changes the angle on a horizontal plane
int bounceHorizontal(int angle)
{
	return 360 - angle;
}

//changes the angle on a vertical plane
int bounceVertical(int angle)
{
	angle = 180 - angle;
	//angle can't be less than 0 to make it positive
	if(angle < 0)
	{
		angle = angle + 360;
	}
	return angle;
}
