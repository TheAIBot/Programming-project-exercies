#ifndef _SCREENIO_H_
#define _SCREENIO_H_

void LEDinit();
void LEDsetString(char string[]);
void LEDupdate();
void LEDWriteCharToDisplay(int display, char toWrite[]);
void scrollText();

#endif
