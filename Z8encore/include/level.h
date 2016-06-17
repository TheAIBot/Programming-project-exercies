#ifndef _LEVEL_H_
#define _LEVEL_H_

void moveStrikerPreShot(struct TBall *vball, struct TStriker *vStriker, int gameSize, char leftButtonPressed, char rightButtonPressed);
void initLevel(struct TGame *game, int level);

#endif
