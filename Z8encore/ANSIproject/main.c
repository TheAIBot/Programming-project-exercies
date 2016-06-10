#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "SineLUT.h"
#include "SuperIO.h"
#include "screenio.h"
#include "buttonio.h"
#include "timer.h"
#include "game.h"
#include "level.h"
#include "ball.h"
#include "striker.h"
#include "brick.h"
#include "boss.h"
#include "powerup.h"
#include "color.h"

/*
void printVector(struct TVector v)
{
	printf("\n");
	printFix(expand(v.x));
	printf("\n");
	printFix(expand(v.y));
	printf("\n");
}*/

void main() {
	//standard instanser
	struct TBall vball;
	struct TStriker vstriker;

	int velocity = 0;
	int angle = 40;
	int size = 150;
	int initialx = 75; 
	int initialy = size + 1;
	int initialstrikery = size;
	int initl = 5;
	unsigned char index = 0;
	int times = 0;
	int i;
	int j;
	int k;
	int prevPressed = 0;
	int oldI;
	char title[] = "Pong game\0";
	LEDsetString("Pong Game \0");

	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	
	initButtons();
	LEDinit();
	clrscr();
	
	
	initBall(&vball,initialx, initialy, FCOLOR_BLUE, angle, velocity);
	initStriker(&vstriker,initialx,initialstrikery ,initl);
	window(0, 0, size, size, '0', title);
	//initLevel
	moveStrikerPreShot(&vball, &vstriker, size, isd3Pressed(), isf7Pressed(), isf6Pressed());
/*
		while (1 == 1)
	{
		scrollText();
	}

	switch (op) {
    
	case 1:
	
	break;
	case 2:

	break;
	case 3:

	break;
	}
*/
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
