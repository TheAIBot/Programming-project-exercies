#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "buttonio.h"
#include "clockio.h"

#define F7_BIT 0x80
#define F6_BIT 0x40
#define D3_BIT 0x08
#define IS_F7_PRESSED (((~PFIN & F7_BIT) == F7_BIT))
#define IS_F6_PRESSED (((~PFIN & F6_BIT) == F6_BIT))
#define IS_D3_PRESSED (((~PDIN & D3_BIT) == D3_BIT))

void initButtons()
{
	//Initialize af knapper

	//what button is this?
	PFADDR = 0x01;
	PFCTL |= 0xC0;

	//what button is this?
	PDADDR = 0x01;
	PDCTL |= 0x08;

	//what button is this?
	PEADDR = 0x00;
	PECTL |= 0x1f;

	//what button is this?
	PGADDR = 0x00;
	PDCTL |= 0xef;
}

char readkeys()
{
	char f7 = (~PFIN & F7_BIT) >> 7;
	char f6 = (~PFIN & F6_BIT) >> 5;
	char d3 = (~PDIN & D3_BIT) >> 1;
	return (f7 | f6 | d3);
}

char isf7Pressed()
{
	if(IS_F7_PRESSED)
	{
		delay(10);
		return IS_F7_PRESSED;
	}
	return 0;
}

char isf6Pressed()
{
	if(IS_F6_PRESSED)
	{
		delay(10);
		return IS_F6_PRESSED;
	}
	return 0;
}

char isd3Pressed()
{
	if(IS_D3_PRESSED)
	{
		delay(10);
		return IS_D3_PRESSED;
	}
	return 0;
}
