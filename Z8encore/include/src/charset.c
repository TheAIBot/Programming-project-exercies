#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"

#define COLUMN_COUNT 5
#define ROW_COUNT 7
#define TITLE_CHAR '#'

char getCharColumnCharArray(char c, int index)
{
	return character_data[c - 32][index];
}

void writeTitle(int startX, int startY, char title[])
{
	char titleLength = 0;
	char column = 0;
	char x;
	char row;


	while ((title[titleLength]) != '\0'){
		titleLength++;
	}

	for(x = startX; x < titleLength; x++)
	{
		for(column = 0; column < COLUMN_COUNT; column++)
		{
			char columnBits = getCharColumnCharArray(title[x - startX], column);
			for(row = 0, row < ROW_COUNT; row++)
			{
				if(columnBits & (1 << row) == 1)
				{
					gotoxy(x + column, startY + y - (2 * row));
					printf("%c", TITLE_CHAR);
					gotoxy(x + column, startY + y - (2 * row) + 1);
					printf("%c", TITLE_CHAR);
				}
				
			}
		}
	}
}
