#ifndef _BOSS_H_
#define _BOSS_H_

#define BOSS_BRICK_COUNT 16
#define USE_BOSS_MASK 0x01
#define TICKS_UNTIL_MOVE_BIT_SHIFT 4
#define TICKS_UNTIL_MOVE_MASK 0xf0
#define X_MOVED_MASK 0x0f

//due to wierd stuff it sometimes happens that bit shifting to the right 
//adds 1's instead of 0's at the beginning.
//To circumvent this the result is & with the required bits(0x0f)
#define TICKS_UNTIL_MOVE(movement) ((movement >> TICKS_UNTIL_MOVE_BIT_SHIFT) & 0x0f)
#define X_MOVED(movement) (movement & X_MOVED_MASK)
#define USE_BOSS(data) (data & USE_BOSS_MASK)

#include "brick.h"

/*
TBoss:
A Boss is an entity which is supposed to be difficult to fight against.
It consists of bricks which are capable of moving.
The boss is defeated when all brick that aren't indestructible are dead.
The boss is also able to shoot and the boss contains a specific position that the shoots come from.
The bosses shots are not harmfull for the player but it's difficult to keep all the shots from dying as the 
player losses lifes for  each shot that dies.


bricks:
an array that contains all the bricks that the boss is made out off.


currentmovement:
All moving bricks are moved at once when a specified amount of ticks has passed by. 
The bricks are moved one position to the left or right depending on the bricks direction.
When the bricks have moved a certain amount of positions the bricks direction changes to the opposite way.
This way the moving bricks ocilates moving between two points on the screen.
The first four bits are used to store the number of ticks that are left until the bricks move again.
When the bricks move again this value of updated with the first four bits from movement.
The first four bits can be extracted with the macro TICKS_UNTIL_MOVE
The last four bits are used to store the amount of movements are left before the bricks direction has to change again.
When the last four bits reaches zero the value is updated from the last four bits from movement.
The last four bits can be extracted with the macro X_MOVED


movement:
stores the reset values for how many ticks have to happen before the bricks move and how many movements has to happen before the bricks
change direction.


startShotX, startShotY
Shot start position.


data:
This variable is currently only used to store wether the boss is used the the current level or not.
If the boss isn't used then it won't be drawn and updated in that level.
The bit can be extracted with the macro USE_BOSS.

*/

struct TBoss
{
	struct TBrick bricks[BOSS_BRICK_COUNT];
	char currentMovement; // x axis 0000, x axis movement 0000 // alle brick der kan bevæge sig skal have den samme størrlse
	char movement; // x axis 0000, x axis moves 0000
	int startShotX;
	int startShotY;
	char data;
};

void initBoss(struct TBoss *boss, struct TBrick bossBricks[BOSS_BRICK_COUNT], char startShitX, char startShotY, char movement, char useBoss);
void drawBoss(struct TBoss *boss);
void updateBoss(struct TBoss *boss, struct TBall shots[], unsigned int *score, char difficulty);
char isBossDead(struct TBoss *boss);


#endif