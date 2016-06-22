#ifndef _SCREENIO_H_
#define _SCREENIO_H_

void LEDinit(void);
void LEDsetString(char string[]);
void LEDupdate(void);
void LEDWriteCharToScreen(int screen, char toWrite[]);
void scrollText(void);

#endif
