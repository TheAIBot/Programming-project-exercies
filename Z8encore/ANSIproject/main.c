#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "SineLUT.h"
#include "SuperIO.h";

volatile int index = 0;
volatile int hundredseconds = 0;
volatile int seconds = 0;
volatile int minutes = 0;
volatile int hours = 0;


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


/*index++;
	if (index > 5)
	{
		index = 0;
	}*/
}

void writeLED(int column, char shape[])
{
	PEOUT &=  ~(0x00 << column);
	PGOUT |= shape[column];
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
	T0CTL = 0x39; //00111001b -> TEN = 1 TPOL = 0 PRES = 011 TMODE = 001.
	T0H = 0x1; //0001; starting value
	T0L = 0x1; //0001; starting value
	T0RH = 0x00;

	T0RL = 0x90;

	//Set interrupt
	IRQ0ENH |= 0x20; //enable Timer 0 interrupt, and set nominal priority
	IRQ0ENL |= 0x20; 

	//Enable timer
	T0CTL = 0xc9; //10111001
	EI();
}

void initLED()
{
	PGOUT &= ~0x7f;
	PEOUT |= 0x1f;
}



void main() {
	//standard instanser
	int times = 0;
	int i;
	int prevPressed = 0;
	int oldI;
	char charA[] = {0x3F, 0x81, 0x81, 0x81, 0x3F};
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	

	initButtons();
	initTimer();
	initLED();

	oldI = -1;
	while (1 == 1)
	{
		if (oldI != seconds){
			printf("%dH %dm %ds %d hsm\n", hours, minutes, seconds, hundredseconds);
			oldI = seconds;
		}
	}

	oldI = -1;
	while (1 == 1)
	{
		if (oldI != index){
			PGOUT &= ~0x7f;
			PEOUT |= 0x1f;
			PEOUT &=  ~(0x01 << index);
			PGOUT |= charA[index];
			oldI = index;
		}
	}

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
