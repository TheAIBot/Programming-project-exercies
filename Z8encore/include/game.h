#ifndef _GAME_H_
#define _GAME_H_

#include "striker.h"
#include "ball.h"
#include "boss.h"
#include "timer.h"

#define GAME_NAME "Brick Breaker"
#define GAME_NAME_LED "Brick Breaker    "
#define DEFAULT_LIVES 12
#define LEVEL_COUNT 3
#define MAX_BRICK_COUNT 80
#define MAX_BALL_COUNT 6
#define STRIKER_LENGTH 21
#define GAME_SIZE_X 100
#define GAME_SIZE_Y 40
#define GAME_UPDATE_RATE 30
#define MAX_DIFFICULTY 5
#define MIN_DIFFICULTY 1

/*
TGame:
This struct contains all the informationthat is required to run the game.


gameSizeX, gameSizeY:
Contains the width and height of the game.
The width and height are currently specified by GAME_SIZE_X and GAME_SIZE_Y.


balls:
Contains all the balls the game will use.
The size of the array is equal to the max amount of balls that can be seen
in the game simultaniously.
The first ball is reserved as the ball the player starts out with.

boss:
Contains the boss. Not all levels are required to have a boss.


bricks:
Contains all the bricks that the game will use.
The size of the array is equal to the amount of bricks that a level will start out with.
When all bricks are dead and a possible boss is dead then the level has been won.


timer:
This timer makes sure that the game updates with the specified frequence which is
specified by GAME_UPDATE_RATE.


brickCount:
Equal to the size of the bricks array.


striker:
This is the striker that the player controls.


lives:
The amount of lives the player has left.
The default amount of lifes is specified by DEFAULT_LIVES.


strikerLength:
Holds the strikers length.


newBall:
This variable is 1 if balls[0] is dead which means that the game should give the player a new ball


difficulty:
Contains the difficulty of the current game.


level:
Determines what level the player is playing.
There is currently 3 levels.


levelWon:
Determines wether the player has won the level or not.

*/

struct TGame
{
	int gameSizeX;
	int gameSizeY;
	struct TBall balls[MAX_BALL_COUNT];
	struct TBoss boss;
	struct TBrick bricks[MAX_BRICK_COUNT];
	struct TTimer timer;
	int brickCount;
	struct TStriker striker;
	int lives;
	int strikerLength;
	char newBall;
	char difficulty;
	unsigned int score;
	char level;
	char levelWon;
};

void initGame(struct TGame *game);
void runGame(struct TGame *game);

#endif