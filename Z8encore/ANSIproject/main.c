#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "ansi.h"




void main() {	
	char title[12] = "Hello world";
	init_uart(_UART0,_DEFFREQ,_DEFBAUD);
	//title = ("Hello world");
  reverse('0');
	blink('0');
	underline('0');
	clrscr();
	gotoxy(1, 1);
	printf("hello world");
	window(3,3,50,10,'0',title);

	window(3,15,50,25,'1',title);
}
