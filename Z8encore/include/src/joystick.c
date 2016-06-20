#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "joystick.h"
#include "clockio.h"

#define BUTTON_1_BIT 0x80
#define BUTTON_2_BIT 0x20
#define IS_BUTTON_1_PRESSED (((~PFIN & BUTTON_1_BIT) == BUTTON_1_BIT))
#define IS_BUTTON_2_PRESSED (((~PFIN & BUTTON_2_BIT) == BUTTON_2_BIT))

void initJoystick()
{
	PFADDR = 0x01;
	PFCTL |= 0x50;

	PHADDR = 0x02;
	ADCCTL |= 0x98;
}

int joystickXAxis()
{
	return (((int)ADCD_H << 2) | ((ADCD_L & 0xc0)) >> 6);
} 

char isJoystickRight()
{
	return joystickXAxis() == JOYSTICK_RIGHT;
}

char isJoystickLeft()
{
	return joystickXAxis() == JOYSTICK_LEFT;
}

char isButton1Pressed()
{
	if(IS_BUTTON_1_PRESSED)
	{
		delay(10);
		return IS_BUTTON_1_PRESSED;
	}
	return 0;
}
char isButton2Pressed()
{
	if(IS_BUTTON_2_PRESSED)
	{
		delay(10);
		return IS_BUTTON_2_PRESSED;
	}
	return 0;
}
