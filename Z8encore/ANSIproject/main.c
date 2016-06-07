#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"
#include "SineLUT.h"
#include "SuperIO.h";


void printVector(struct TVector v)
{
	printf("\n");
	printFix(expand(v.x));
	printf("\n");
	printFix(expand(v.y));
	printf("\n");
}

char readkey()
{
	char f7 = 6 >> (PFIN & 0x40);
	char f6 = 5 >> (PFIN & 0x20);
	char d3 = PDIN & 0x04;
	return (f7 | f6 | d3);// & 0x07;
}

void main() {
	int times = 0;
PFADDR = 0x01;
PFCTL &= 0x60;	
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

	while(1 == 1)
	{
		char updated = 0;
		char buttonpresses1 = readkey();
		//int i;
		delay(50);
		/*for(i = 0; i < 10000; i++)
		{

		}*/
		char buttonpresses2 = readkey();
		if (buttonpresses1 > 0)
		{
			updated  = 1;
			times++;	
		}
		if (updated == 1)
		{
			printf("%d", times);
		}
	}

}
