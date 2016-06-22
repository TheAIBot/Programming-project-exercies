#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines#include "screenio.h"
#include "display.h"
#include "clockio.h"
#include "charset.h"

#define DISPLAY_COUNT 4
#define DISPLAY_COLUMN_COUNT 5
//Ever display can at show one char at a time.
//To allow a a scrolling effect a char has to seem like it's
//being loaded in from the right.
//The scrolling effect is achieved by moving every column in the video buffer 
//one to the left so when the text is shown on the displays again
//then it will be shown as having moved one column to the left.
//When scrolling the next character has to gradually be shown on the last display
//when scrolling so it seems like it's scrolling in and to do that
//the video buffer loads in one additional character that at first won't be shown on the display but 
//when scrolling gradually will move sint o the last screem so it seems like it's scrolling in.
//That's why the video buffers length is one more than the amount of displays
#define VIDEO_BUFFER_LENGTH (DISPLAY_COUNT + 1)
//When scrolling it looks better if there is a columns space between each character
//So when loading the columns of a char into the video buffer the last column will be 0 which will turn off that column when shown.
#define VIDEO_BUFFER_COLUMNS (DISPLAY_COLUMN_COUNT + 1)
#define UPDATES_BEFORE_SCROLL 5

//The string there is shown in the displays is always the same
//and it's always set the the start of the problem
//so it doesn't really matter wether this is a global or
//inside of a struct in the game stuct because it's basically
//gives the same effect on the memory comsumption
//
char videoBuffer[VIDEO_BUFFER_LENGTH][VIDEO_BUFFER_COLUMNS];
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
	for(wholeStringIndex = 0; wholeStringIndex < DISPLAY_COLUMN_COUNT; wholeStringIndex++) // doesn't support strings that are smaller than 5 chars
	{
		for(y = 0; y < 6; y++) //maybe this hould be 5 instead of 6. look at loadCharIntoVideoBuffer which has correct code
		{
			videoBuffer[wholeStringIndex][y] = getCharColumnCharArray(string[wholeStringIndex], y);
		}
		//there is a space between each char which is a single turned off column of lights
		videoBuffer[wholeStringIndex][5] = 0x00;
	}
	//need to save the whole string so if there will be scrolled in the future
	//then the new chars can be taken from the whole string
	//the length of the string is saved here aswell as a performance
	//optimization and to reduce  duplication of code that finds the length
	//of the same string
	wholeString = string;
	wholeStringLength = length;
}

//loads a single char into the end of the video buffer
void loadCharIntoVideoBuffer()
{
	int y;
	//loads the next char columns into the end of the video buffer
	//which is determined by the number of displays
	for(y = 0; y < DISPLAY_COLUMN_COUNT; y++)
	{
		videoBuffer[DISPLAY_COUNT][y] = getCharColumnCharArray(wholeString[wholeStringIndex], y);
	}
	//the last column in every char is empty so there is a column of space
	//between each char when the chars are scrolling on the displays
	videoBuffer[DISPLAY_COUNT][DISPLAY_COLUMN_COUNT] = 0x00;
	//Move the character that will beloaded next and ifthe index is more than the length fo the string
	//then start with loading the first character again which is located at index 0
	wholeStringIndex++;
	if(wholeStringIndex >= wholeStringLength)
	{
		wholeStringIndex = 0;
	}
}

//prepares the selected display for drawing a column on it
void initDisplay(char display)
{
	switch(display)
	{
		case 1:
			PGOUT &= ~0x7f; //01111111
			PEOUT |= 0x1f | (1 << 7); //10011111
			break;
		case 2:
			PGOUT &= ~0x7f | (1 << 7);//11111111
			PEOUT |= 0x1f; //00011111
			break;
		case 3:
			PGOUT &= ~0x7f; //01111111
			PEOUT |= 0x1f | (1 << 5); //00111111
			break;
		case 4:
			PGOUT &= ~0x7f; //01111111
			PEOUT |= 0x1f | (1 << 6);//01011111
			break;
	}
}

//sends a clock signal the selected display so it shows the column
void clockDisplay(char display)
{
	switch(display)
	{
		case 1:
			PEOUT &= ~(1 << 7);
			PEOUT |= (1 << 7);
			PEOUT &= ~(1 << 7);
			break;
		case 2:
			PGOUT &= ~(1 << 7);
			PGOUT |= (1 << 7);
			PGOUT &= ~(1 << 7);
			break;
		case 3:
			PEOUT &= ~(1 << 5);
			PEOUT |= (1 << 5);
			PEOUT &= ~(1 << 5);
			break;
		case 4:
			PEOUT &= ~(1 << 6);
			PEOUT |= (1 << 6);
			PEOUT &= ~(1 << 6);
			break;
	}
}

//writes to a specific column to a specific display
void writeLED(int column, int display, char shape[])
{		
		//need to init the screen for writing
		initDisplay(display);

		//write what column to write to
		PEOUT &=  ~(1 << column);
		//write the column to the display
		PGOUT |= shape[DISPLAY_COUNT - column];
		
		// Clock the screen to display the column on it
		clockDisplay(display);
}

//writes a column to all displays
void LEDWriteCharColumnsToDisplay(int column, char toWrite[VIDEO_BUFFER_LENGTH][VIDEO_BUFFER_COLUMNS])
{
	int display;
	//display is index 1 based
	for(display = 1; display <= DISPLAY_COUNT; display++)
	{
		//wait for the clock to run and then update another display
		//which means the column of the display will be turned on for
		//~0.5ms
		waitOnce();
		//doesn't support strings that are smaller than the amount of displays
		//cound easily be sloved by using a MAX function to either get the length of the string or
		//the amount of displays but that's currently not needed
		writeLED(column, display, toWrite[display - 1]);
	}
}

//updates all columns of all displays
void LEDupdate()
{
	int column = 0;
	for(column = 0; column < DISPLAY_COLUMN_COUNT; column++)
	{
		LEDWriteCharColumnsToDisplay(column, videoBuffer);
	}
}

//handles scrolling of the text on the displays
//which doesn't nessesarily mean that the text will scroll
//when this method will be called as this method will only scroll the text when it
//has been called UPDATES_BEFORE_SCROLL times.
//This is to prevent the text from scrolling too fast when calling this method in a tight loop
void scrollText()
{
	int i;
	int j;
	int k;
	//either show the text on the displays or load in a new character
	if(columnScrollOffset < VIDEO_BUFFER_COLUMNS)
	{
		//only scrolls the text every UPDATES_BEFORE_SCROLL times this method is called
		//so when it isn't scrolling it's just showing the text on the displays
		if (LEDUpdateCount < UPDATES_BEFORE_SCROLL)
		{
			LEDupdate();
			LEDUpdateCount++;
		}
		else
		{
			//foreach column in each character move every column one to the left
			for(i = 0; i < VIDEO_BUFFER_LENGTH; i++)
			{
				//move ever column to the left except for the last one as that one has to come from the next characters first column
				for(k = 1; k < VIDEO_BUFFER_COLUMNS; k++)
				{
					videoBuffer[i][k - 1] = videoBuffer[i][k];
				}
				//only move a column from the next character to this character if we are not at the end of the videobuffer
				//as there is no next character when the end is reached
				if(i < VIDEO_BUFFER_LENGTH)
				{
					videoBuffer[i][VIDEO_BUFFER_LENGTH] = videoBuffer[i + 1][0];
				}
			}
			//the text scrolled so now wait for UPDATES_BEFORE_SCROLL to be reacked again
			//and increment columnScrollOffset which determines when to load in a nother character
			LEDUpdateCount = 0;
			columnScrollOffset++;
		}
	}
	//if the last character has been fully moved into the last display then load a new
	//character into the end of the videobuffer as there would otherwise be nothing to scroll
	if(columnScrollOffset == VIDEO_BUFFER_COLUMNS)
	{
		loadCharIntoVideoBuffer();
		columnScrollOffset = 0;
	}
}


