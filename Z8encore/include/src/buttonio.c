#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "buttonio.h"

void initButtons()
{
	//Initialize af knapper
	PFADDR = 0x01;
	PFCTL |= 0xC0;	
	PDADDR = 0x01;
	PDCTL |= 0x08;
	PEADDR = 0x00;
	PECTL |= 0x1f;
	PGADDR = 0x00;
	PDCTL |= 0xef;
}

char readkeys()
{	char f7 = (~PFIN & 0x80) >> 7;
	char f6 = (~PFIN & 0x40) >> 5;
	char d3 = (~PDIN & 0x08) >> 1;
	return (f7 | f6 | d3);// & 0x07;
}

char isf7Pressed()
{
	return ((~PFIN & 0x80) == 0x80)? 1 : 0;
}

char isf6Pressed()
{
	return ((~PFIN & 0x40) == 0x40)? 1 : 0;
}

char isd3Pressed()
{
	return ((~PDIN & 0x08) == 0x08)? 1 : 0;
}
