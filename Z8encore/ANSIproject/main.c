#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include <string.h>
#include "ansi.h"
#include "SineLUT.h"
#include "SuperIO.h";
#include "charset.h"


volatile int hundredseconds = 0;
volatile int seconds = 0;
volatile int minutes = 0;
volatile int hours = 0;
volatile int runTimer = 1;
volatile char LEDupdateFlag = 0;
char videoBuffer[5][6];
char* wholeString;
int wholeStringIndex = 0;
int wholeStringLength = 0;


void printVector(struct TVector v)
{
	printf("\n");
	printFix(expand(v.x));
	printf("\n");
	printFix(expand(v.y));
	printf("\n");
}

char readkey()
{	char f7 = (~PFIN & 0x80) >> 7;
	char f6 = (~PFIN & 0x40) >> 5;
	char d3 = (~PDIN & 0x08) >> 1;
	return (f7 | f6 | d3);// & 0x07;

	/*
	char value=0;

	if((PFIN >> 7 & 1) == 0) value |= 1;
	if((PFIN >> 6 & 1) == 0) value |= 2;
	if((PDIN >> 3 & 1) == 0) value |= 4;

	return value;
	*/
}

void delay(int times)
{
	unsigned long delay = 0;
	int i;
	for(i = 0; i < times; i++)
	{
		delay += delay * delay;
	}
}

#pragma interrupt
void timer0int() {
	/*if (runTimer == 1)
	{
		hundredseconds++;
		if (hundredseconds == 100)
		{
		hundredseconds = 0;
			seconds++;
			if (seconds == 60)
			{
				seconds = 0;
				minutes++;
				if (minutes == 60)
				{
					minutes = 0;
					hours++;
				}
			}
		}
	}*/
	LEDupdateFlag = 1;

	//index++;
	//if (index > 4)
	//{
	//	index = 0;
	//}
}

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

void initTimer()
{
	//interupt vector
	SET_VECTOR(TIMER0, timer0int);

	//Timer
	DI();
	T0CTL = 0x39; //00111001b -> TEN = 1 TPOL = 0 PRES = 111 TMODE = 001.
	T0H = 0x00; //00000000; starting value
	T0L = 0x01; //00000001 - 0000000000000001
	T0RH = 0x00;
	T0RL = 0x48;

	//Set interrupt
	IRQ0ENH &= 0xDF; //enable Timer 0 interrupt, and set nominal priority
	IRQ0ENL |= 0x20; 

	//Enable timer
	T0CTL = 0xB9; //10111001
	EI();
}

void* LEDinit()
{
	PEDD = 0x00;
	PGDD = 0x00;

	initTimer();
}

char getCharColumnArray(char c, int index)
{
	return character_data[c - 32][index];
}

void LEDsetString(char string[], int length)
{
	int y = 0;
	for(wholeStringIndex = 0; wholeStringIndex < 5; wholeStringIndex++)
	{
		for(y = 0; y < 5; y++)
		{
			videoBuffer[wholeStringIndex][y] = getCharColumnArray(string[wholeStringIndex], y);
		}
	}
	wholeString = string;
	wholeStringLength = length;
}

void reloadChar()
{
	int y;
	for(y = 0; y < 5; y++)
	{
		videoBuffer[4][y] = getCharColumnArray(wholeString[wholeStringIndex], y);
	}
	//videoBuffer[4][5] = 0x00;
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


void writeLED(int column, int screen, char shape[6])
{		
		initScreen(screen);

		PEOUT &=  ~(1 << column);
		PGOUT |= shape[4 - column];
		
		// Clock D1
		clockScreen(screen);
}

void LEDupdate()
{
	int column = 0;
	int screen = 0;
	while (column < 20)
	{
		for(screen = 1; screen <= 4; screen++)
		{
			for(column = 0; column < 5; column++)
			{
				
				while(LEDupdateFlag == 0) {}
				writeLED(column % 21, screen, videoBuffer[screen - 1]);
				LEDupdateFlag = 0;
			}
		}
		if(LEDupdateFlag == 1){

			LEDupdateFlag = 0;	
			column++;
	 	}
	}
}

void main() {
	//standard instanser
	unsigned char index = 0;
	int times = 0;
	int i;
	int j;
	int k;
	int prevPressed = 0;
	int oldI;
	//char charA[] = {0x3F, 0x81, 0x81, 0x81, 0x3F};
	char charA[] = {0x2F, 0x49, 0x49, 0x49, 0x31};
	char title[11] = "Stop watch";
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);

	LEDsetString("ABRG  ", 6);

	

	initButtons();
	LEDinit();
	clrscr();

	while (1 == 1)
	{
		for(j = 0; j < 5; j++)
		{
			for(i = 0; i < 50;  i++)
			{
				LEDupdate();
			}
			for(i = 0; i < 6; i++)
			{
				for(k = 1; k < 6; k++)
				{
					videoBuffer[i][k - 1] = videoBuffer[i][k];
				}
				if(i < 5)
				{
					videoBuffer[i][4] = videoBuffer[i + 1][0];
				}
			}
		}
		reloadChar();
	}
	
	
	/*window(3,3,38,9, '0', title);
	gotoxy(5, 5);
	printf("Time since start:");
	gotoxy(5, 6);
	printf("Split time 1:");
	gotoxy(5, 7);
	printf("Split time 2:");
	oldI = -1;
	while (1 == 1)
	{
		char buttonpresses1 = readkey();
		char buttonpresses2;
		char buttonPress;
		delay(1000);
		buttonpresses2 = readkey();
		buttonPress = buttonpresses1 & buttonpresses2;
		if ((buttonPress & 0x06) == 0x06) // button f6 and d3 pressed
		{
			if (runTimer == 1)
			{
				runTimer = 0;
			}
			else
			{
				runTimer = 1;
			}
			hundredseconds = 0;
			seconds = 0;
			minutes = 0;
			hours = 0;
			gotoxy(25, 5);
			printf("%02d:%02d:%02d:%02d", hours, minutes, seconds, hundredseconds);
		}
		else if ((buttonPress & 0x01) == 0x01) // button f7 pressed
		{
			if (runTimer == 1)
			{
				runTimer = 0;
			}
			else
			{
				runTimer = 1;
			}
		}
		else if ((buttonPress & 0x02) == 0x02) // button f6 pressed
		{
			gotoxy(25, 6);
			printf("%02d:%02d:%02d:%02d", hours, minutes, seconds, hundredseconds);
		}
		else if ((buttonPress & 0x04) == 0x04) // button d3 pressed
		{
			gotoxy(25, 7);
			printf("%02d:%02d:%02d:%02d", hours, minutes, seconds, hundredseconds);
		}
		if (oldI != seconds){
			gotoxy(25, 5);
			printf("%02d:%02d:%02d:%02d", hours, minutes, seconds, hundredseconds);
			oldI = seconds;
		}
	}*/

	/*
	oldI = -1;
	while (1 == 1)
	{
		char buttonpresses1 = readkey();
		char buttonpresses2;
		char buttonPress;
		delay(3000);
		buttonpresses2 = readkey();
		buttonPress = buttonpresses1 | buttonpresses2;
		if (buttonPress > 0)
		{
		
		}
		if (oldI != seconds){
			printf("%dH %dm %ds %d hsm\n", hours, minutes, seconds, hundredseconds);
			oldI = seconds;
		}
	}
	*/


	/*char title[12] = "Hello world";
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	//title = ("Hello world");
  reverse('0');
	blink('0');
	underline('0');
	clrscr();
	gotoxy(1, 1);
	printf("hello world");
	window(3,3,50,10,'0',title);

	window(3,15,50,25,'1',title);*/
	//printf("%ld.", 720 % 360);
	/*printFix(expand(sin(0)));
	printFix(expand(sin(45)));
	printFix(expand(sin(-78)));
	printFix(expand(sin(649)));
	*/
	/*struct TVector vec;
	initVector(&vec, 1, 2);
	rotate(&vec, 180);
	printVector(vec);

	initVector(&vec, 6, 4);
	rotate(&vec, -10);
	printVector(vec);

	initVector(&vec, -4, -4);
	rotate(&vec, 900);
	printVector(vec);

	initVector(&vec, -4, 2);
	rotate(&vec, -35);
	printVector(vec);
	*/
	//printf("DD");

	/*while(1 == 1)
	{
		char updated = 0;
		char buttonpresses1 = readkey();
		
		char buttonpresses2;
		delay(3000);
		buttonpresses2 = readkey();
		if (buttonpresses1 | buttonpresses2 > 0 && prevPressed == 0)
		{
			updated  = 1;
			times++;	
			prevPressed = 1;
			//printf("dsasada");
		}
		else if (buttonpresses1 == 0)
		{
			prevPressed = 0;
		}
printf("%d\n", readkey());
		if (updated == 1)
		{
			printf("%d\n", times);
		}
	}
	*/
}
