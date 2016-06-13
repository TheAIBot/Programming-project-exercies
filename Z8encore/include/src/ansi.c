#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines

#include <stdio.h>
#include "ansi.h"
#include "SineLUT.h"


#define ESC 0x1B

void fgcolor(int foreground) {
/*  Value      foreground     Value     foreground
    ------------------------------------------------
      0        Black            8       Dark Gray
      1        Red              9       Light Red
      2        Green           10       Light Green
      3        Brown           11       Yellow
      4        Blue            12       Light Blue
      5        Purple          13       Light Purple
      6        Cyan            14       Light Cyan
      7        Light Gray      15       White
*/
  int type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%dm", ESC, type, foreground+30);
}

void bgcolor(int background) {
/* IMPORTANT:   When you first use this function you cannot get back to true white background in HyperTerminal.
   Why is that? Because ANSI does not support true white background (ANSI white is gray to most human eyes).
                The designers of HyperTerminal, however, preferred black text on white background, which is why
                the colors are initially like that, but when the background color is first changed there is no
 	              way comming back.
   Hint:        Use resetbgcolor(); clrscr(); to force HyperTerminal into gray text on black background.

    Value      Color      
    ------------------
      0        Black
      1        Red
      2        Green
      3        Brown
      4        Blue
      5        Purple
      6        Cyan
      7        Gray
*/
  printf("%c[%dm", ESC, background+40);
}

void color(int foreground, int background) {
// combination of fgcolor() and bgcolor() - uses less bandwidth
  int type = 22;             // normal text
	if (foreground > 7) {
	  type = 1;                // bold text
		foreground -= 8;
	}
  printf("%c[%d;%d;%dm", ESC, type, foreground+30, background+40);
}

// enable/disable cursur
void enablecursor(char on){
    if (on == '1'){
	   printf("%c[?%dh", ESC, 25);
	} else {
	   printf("%c[?%dl", ESC, 25);
    }
}
void resetbgcolor() {
// gray on black text, no underline, no blink, no reverse
  printf("%c[m", ESC);  
}

void clrscr(){
	  printf("%c[2J", ESC);
}

void clreol(){
	printf("%c[K", ESC);
}

void gotoxy(int x, int y){
	printf("%c[%d;%dH", ESC, y, x);
}

void underline(char on){
    if (on == '1'){
	   printf("%c[%dm", ESC, 04);
	} else {
	   printf("%c[%dm", ESC, 24);
    }
}	


void blink(char on){
    if (on == '1'){
	   printf("%c[%dm", ESC, 05);
	} else {
	   printf("%c[%dm", ESC, 25);
    }
}

void reverse(char on){
    if (on == '1'){
	   printf("%c[%dm", ESC, 07);
	} else {
	   printf("%c[%dm", ESC, 27);
    }
}

void movecursor(int x,int y) {
if (x<0) printf("%c[%dD",ESC,(-1)*x);
else printf("%c[%dC",ESC,x);
if (y<0) printf("%c[%dB",ESC,(-1)*y);
else printf("%c[%dA",ESC,y);
}

void window(int x1, int y1, int x2, int y2, char style,char title[]){
   int i,j,l= 0;
   int windowWidth, titleStart, titleEnd;
   int index =0;

   int symbol_lefttopcorner;
   int symbol_righttopcorner;
   int symbol_leftbottomcorner;
   int symbol_rightbottomcorner;
   int symbol_sideline; 
   int symbol_bottomline;
   int symbol_leftturnstile;
   int symbol_rightturnstile;

   // SELECT STYLE
   if(style == '1'){
     symbol_lefttopcorner = 218;
	   symbol_leftturnstile = 180;
	   symbol_righttopcorner = 191;
	   symbol_rightturnstile = 195;

	   symbol_sideline = 179;
	   symbol_bottomline = 196;
       
	   symbol_leftbottomcorner = 192;
	   symbol_rightbottomcorner = 217;

   } else {
     symbol_lefttopcorner = 201;
	   symbol_leftturnstile = 185;
	   symbol_righttopcorner = 187;
	   symbol_rightturnstile = 204;

	   symbol_sideline = 186;
	   symbol_bottomline = 205;
       
	   symbol_leftbottomcorner = 200;
	   symbol_rightbottomcorner = 188;
      
   }
		for(i = x1; i<= x2; i++)
	 {
	 		gotoxy(i,y1);
			printf("%c", symbol_bottomline);
	 }

		for(i = x1; i<= x2; i++)
	 {
	 	 gotoxy(i,y2);
			printf("%c", symbol_bottomline);
	 }

		for(i = y1; i<= y2; i++)
	 {
	 	 gotoxy(x1,i);
			printf("%c", symbol_sideline);
	 }

		for(i = y1; i<= y2; i++)
	 {
	 	 gotoxy(x2,i);
			printf("%c", symbol_sideline);
	 }

	 gotoxy(x1,y1);
	printf("%c", symbol_lefttopcorner);

	gotoxy(x1,y2);
	printf("%c", symbol_leftbottomcorner);

	gotoxy(x2,y1);
	printf("%c", symbol_righttopcorner);

	gotoxy(x2,y2);
	printf("%c", symbol_rightbottomcorner);
	

  while ((title[l]) != '\0'){
		l++;
	}



	 windowWidth = x2 - x1;
	 titleStart = x1 + (windowWidth / 2) - (l / 2);
	 titleEnd = x1 + (windowWidth / 2) + (l / 2);
	 
	
	 gotoxy(titleStart,y1);
	 index = 0;
	 for(i = titleStart; i<= titleEnd; i++)
	 {
			printf("%c", title[index]);
			index++;
	 }
}

void initVector(struct TVector * v, long x, long y)
{
	v->x = x;
	v->y = y;
}

void rotate(struct TVector *v, int angle)
{
long nx=v->x;
long ny=v->y;	
v->x = nx * cos(angle) -ny * sin(angle);
	v->y = nx * sin(angle) + ny * cos(angle);
}
