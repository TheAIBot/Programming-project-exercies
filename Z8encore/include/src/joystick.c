#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "joystick.h"
#include "clockio.h"

#define BUTTON_1_BIT 0x80
#define IS_BUTTON_1_PRESSED (((~PFIN & BUTTON_1_BIT) == BUTTON_1_BIT))
#define BUTTON_2_BIT 0x20
#define IS_BUTTON_2_PRESSED (((~PFIN & BUTTON_2_BIT) == BUTTON_2_BIT))

//sets the pins the joystick uses
void initJoystick()
{
	PFADDR = 0x01;  //00000001 Setting F-register to Data Direction
	PFCTL |= 0x50;  //01010000 Initializing PF7 and PF5 as inputs

	PHADDR = 0x02;  //00000010 Setting Analog H-register to Alternate Function
	ADCCTL |= 0x98; //10011000 CEN=1, CONT=1, ANAIN=1000 
}

//returns the value that joystick returns that specifies the x axis
int joystickXAxis()
{
	return (((int)ADCD_H << 2) | ((ADCD_L & 0xc0)) >> 6); //Shifting the 10 analog-input bits
} 

//returns wether the joystick is pointing right
char isJoystickRight()
{
	return joystickXAxis() == JOYSTICK_RIGHT; //JOYSTICK_RIGHT = 1023
}

//returns wether the joystick is pointing left
char isJoystickLeft()
{
	return joystickXAxis() == JOYSTICK_LEFT; //JOYSTICK_LEFT = 0
}

//returns wether button 1 is pressed
char isButton1Pressed()
<<<<<<< HEAD
{   //Implementing a debounce function to read if button is pressed
=======
{
	//it's checked twice if the button is pressed with a delay inbetween
	//because if the button was just stopped being pressed then the button 
	//can oscillate between pressed and not pressed for a short while
>>>>>>> refs/remotes/origin/andreas
	if(IS_BUTTON_1_PRESSED)
	{
		delay(10);
		return IS_BUTTON_1_PRESSED;
	}
	return 0;
}

//returns wether button 2 is pressed
char isButton2Pressed()
<<<<<<< HEAD
{	//Implementing a debounce function to read if button is pressed
=======
{
	//it's checked twice if the button is pressed with a delay inbetween
	//because if the button was just stopped being pressed then the button 
	//can oscillate between pressed and not pressed for a short while
>>>>>>> refs/remotes/origin/andreas
	if(IS_BUTTON_2_PRESSED)
	{
		delay(10);
		return IS_BUTTON_2_PRESSED;
	}
	return 0;
}
