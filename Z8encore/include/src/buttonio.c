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
/*
	//what button is this?
	PFADDR = 0x01;
	PFCTL |= 0xC0;

	//what button is this?
	PDADDR = 0x01;
	PDCTL |= 0x08;
*/

	PFADDR = 0x01;
	PFCTL |= 0x50;

	PHADDR = 0x02;
	ADCCTL |= 0x88;

	//what button is this?
	PEADDR = 0x00;
	PECTL |= 0x1f;

	//what button is this?
	PGADDR = 0x00;
	PDCTL |= 0xef;
}

char readkeys()
{	
	int aX = (int) ((ADCD_H << 2) | ((ADCD_L & 11000000)) >> 6); //
	char f7 = (~PFIN & F7_BIT) >> 7;
	char f6 = (~PFIN & F6_BIT) >> 5;
	char d3 = (~PDIN & D3_BIT) >> 1;
	return (f7 | f6 | d3);
}

char isf7Pressed()
{
	char b1 = IS_F7_PRESSED;
	if(b1 == 1)
	{
		delay(10);
		return b1 & IS_F7_PRESSED;
	}
	return 0;
}

char isf6Pressed()
{
	char b1 = IS_F6_PRESSED;
	if(b1 == 1)
	{
		delay(10);
		return b1 & IS_F6_PRESSED;
	}
	return 0;
}

char isd3Pressed()
{
	char b1 = IS_D3_PRESSED;
	if(b1 == 1)
	{
		delay(10);
		return b1 & IS_D3_PRESSED;
	}
	return 0;
}
