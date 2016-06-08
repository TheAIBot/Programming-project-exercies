#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines#include "screenio.h"
#include "timerio.h"
#include "charset.h"

char videoBuffer[5][6];
char* wholeString;
int wholeStringIndex = 0;
int wholeStringLength = 0;

void LEDinit()
{
	PEDD = 0x00;
	PGDD = 0x00;

	initTimer();
}

char getCharColumnArray(char c, int index)
{
	return character_data[c - 32][index];
}

void LEDsetString(char string[])
{
	int length = 0;
	int y = 0;
	while (string[++length] != '\0') { }
	for(wholeStringIndex = 0; wholeStringIndex < 5; wholeStringIndex++) // doesn't support strings that are smaller than 5 chars
	{
		for(y = 0; y < 6; y++)
		{
			videoBuffer[wholeStringIndex][y] = getCharColumnArray(string[wholeStringIndex], y);
		}
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
		videoBuffer[4][y] = getCharColumnArray(wholeString[wholeStringIndex], y);
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
		PGOUT |= shape[4 - column];
		
		// Clock D1
		clockScreen(screen);
}

void LEDWriteCharToScreen(int screen, char toWrite[]) // need to make another method that load a char from the big char array and uses that so i don't have to supply the columns
{
	int column = 0;
	for(column = 0; column < 5; column++)
	{
		while(LEDupdateFlag == 0) 
		{
		}
		writeLED(column, screen, toWrite);
		LEDupdateFlag = 0;
	}
}

void LEDupdate()
{
	int screen = 0;
	for(screen = 1; screen <= 4; screen++) // doesn't support strings that are smaller than 4 chars
	{
		LEDWriteCharToScreen(screen, videoBuffer[screen - 1]);
	}
}

void scrollText() // need to make this so it returns after running LEDupdate once, so it doesn't take that much time to run
{
	int i;
	int j;
	int k;
	for(j = 0; j < 5; j++)
	{
		for(i = 0; i < 5;  i++) // 5
		{
			LEDupdate();
		}
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
	}
	loadCharIntoVideoBuffer();
}


