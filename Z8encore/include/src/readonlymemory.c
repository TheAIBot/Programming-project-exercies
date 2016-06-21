#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines

void ROMtoRAM(char *dest, char rom *src)
{
	while(*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
}
