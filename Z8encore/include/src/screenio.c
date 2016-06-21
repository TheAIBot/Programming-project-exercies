#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines#include "screenio.h"
#include "clockio.h"
#include "charset.h"

#define DISPLAY_COUNT 4
#define DISPLAY_COLUMN_COUNT 5

//The string there is shown in the displays is always the same
//and it's always set the the start of the problem
//so it doesn't really matter wether this is a global or
//inside of a struct in the game stuct because it's basically
//gives the same effect on the memory comsumption
//All the values are private
char videoBuffer[5][6];
char* wholeString;
int wholeStringIndex = 0;
int wholeStringLength = 0;
char LEDUpdateCount = 0;
char columnScrollOffset = 0;

//turn on the displays
void LEDinit()
{
	PEDD = 0x00;
	PGDD = 0x00;

	//to run the displays the clock is required to update the different columns
	//of the displays at a certains interval
	initClock();
}

//set the string the displays show
void LEDsetString(char string[])
{
	int length = 0;
	int y = 0;
	//get the length of the string to show in the displays
	while (string[++length] != '\0') { }
	//for the first 5 chars copy their columns over into the videoBuffer
	for(wholeStringIndex = 0; wholeStringIndex < 5; wholeStringIndex++) // doesn't support strings that are smaller than 5 chars
	{
		for(y = 0; y < 6; y++) //maybe this hould be 5 instead of 6. look at loadCharIntoVideoBuffer which has correct code
		{
			videoBuffer[wholeStringIndex][y] = getCharColumnCharArray(string[wholeStringIndex], y);
		}
		//there is a space between each char which is a single turned off column of lights
		videoBuffer[wholeStringIndex][5] = 0x00;
	}
	wholeString = string;
	wholeStringLength = length;
}


void loadCharIntoVideoBuffer()
{
	int y;
	for(y = 0; y < 5; y++)
	{
		videoBuffer[4][y] = getCharColumnCharArray(wholeString[wholeStringIndex], y);
	}
	videoBuffer[4][5] = 0x00;
	wholeStringIndex++;
	if(wholeStringIndex >= wholeStringLength)
	{
		wholeStringIndex = 0;
	}
}

void initScreen(char screen)
{
	if (screen == 1)
	{
		PGOUT &= ~0x7f; //01111111
		PEOUT |= 0x1f | (1 << 7); //10011111
	}
	else if(screen == 2)
	{
		PGOUT &= ~0x7f | (1 << 7);//11111111
		PEOUT |= 0x1f; //00011111
	}
	else if(screen == 3)
	{
		PGOUT &= ~0x7f; //01111111
		PEOUT |= 0x1f | (1 << 5); //00111111
	}
	else if(screen == 4)
	{
		PGOUT &= ~0x7f; //01111111
		PEOUT |= 0x1f | (1 << 6);//01011111
	}
}

void clockScreen(char screen)
{
	if (screen == 1)
	{
    //clock
		PEOUT &= ~(1 << 7);
		PEOUT |= (1 << 7);
		PEOUT &= ~(1 << 7);
	}
	else if(screen == 2)
	{
	  //clock
		PGOUT &= ~(1 << 7);
		PGOUT |= (1 << 7);
		PGOUT &= ~(1 << 7);
	}
	else if(screen == 3)
	{
	  //clock
		PEOUT &= ~(1 << 5);
		PEOUT |= (1 << 5);
		PEOUT &= ~(1 << 5);
	}
	else if(screen == 4)
	{
	  //clock
		PEOUT &= ~(1 << 6);
		PEOUT |= (1 << 6);
		PEOUT &= ~(1 << 6);
	}
}


void writeLED(int column, int screen, char shape[])
{		
		initScreen(screen);

		PEOUT &=  ~(1 << column);
		PGOUT |= shape[DISPLAY_COUNT - column];
		
		// Clock D1
		clockScreen(screen);
}

void LEDWriteCharColumnsToScreen(int column, char toWrite[5][6]) // need to make another method that load a char from the big char array and uses that so i don't have to supply the columns
{
	int screen = 0;
	for(screen = 1; screen <= DISPLAY_COUNT; screen++)
	{
		waitOnce();
		writeLED(column, screen, toWrite[screen - 1]);
	}
}

void LEDupdate()
{
	int column = 0;
	for(column = 0; column < DISPLAY_COLUMN_COUNT; column++) // doesn't support strings that are smaller than 4 chars
	{
		LEDWriteCharColumnsToScreen(column, videoBuffer);
	}
}

void scrollText()
{
	int i;
	int j;
	int k;
	if(columnScrollOffset < 6)
	{
		if (LEDUpdateCount < 5)
		{
			LEDupdate();
			LEDUpdateCount++;
		}
		if (LEDUpdateCount == 5)
		{
			for(i = 0; i < 5; i++)
			{
				for(k = 1; k < 6; k++)
				{
					videoBuffer[i][k - 1] = videoBuffer[i][k];
				}
				if(i < 5)
				{
					videoBuffer[i][5] = videoBuffer[i + 1][0];
				}
			}
			LEDUpdateCount = 0;
			columnScrollOffset++;
		}
	}
	if(columnScrollOffset == 6)
	{
		loadCharIntoVideoBuffer();
		columnScrollOffset = 0;
	}
}


