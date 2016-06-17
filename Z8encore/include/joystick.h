#ifndef _JOYSTICK_H_
#define _JOYSTICK_H_

#define JOYSTICK_RIGHT 1023
#define JOYSTICK_LEFT 0

void initJoystick();
int joystickXAxis();
char isJoystickLeft();
char isJoystickRight();
char isButton1Pressed();

#endif