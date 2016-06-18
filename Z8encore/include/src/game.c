#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "trigonometry.h"
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
#include "clockio.h"
#include "joystick.h"
#include "random.h"
#include "sound.h"


void initGame(struct TGame *game, int gameSizeX, int gameSizeY, int strikerLength, int updateFrequency)
{
	
		//standard instanser
	
	game->strikerLength = strikerLength;
	game->gameSizeX = gameSizeX;
	game->gameSizeY = gameSizeY;
	game->lives = DEFAULT_LIVES;
	game->level = 1;
	game->levelWon = 0;

	
	// start a clock with the chosen frequency which means the clock should tick every 1s / freq, 1s == 1000
	initTimer(&game->timer, 1000 / updateFrequency);

	//initButtons();
	initJoystick();

	LEDinit(); 
	LEDsetString(GAME_NAME);

	initSoundPin();
	initSoundClock();

	color(FCOLOR_WHITE, BCOLOR_BLACK);
	enablecursor('0');
}

void getDifficulty(struct TGame *game)
{
	char i;
	game->difficulty = 0;
	// begin main loop, selecting difficulty level
	clrscr();
	window(0, 0, game->gameSizeX, game->gameSizeY, '0', GAME_NAME);
	gotoxy((game->gameSizeX >> 1) - 30, (game->gameSizeY >> 1));
    printf("Welcome to Brick Breaker!");
    gotoxy((game->gameSizeX >> 1) - 30, (game->gameSizeY >> 1) + 2);
    printf("Select difficulty level by pressing left/right button (max. 5): %5d", game->difficulty);
    gotoxy((game->gameSizeX >> 1) - 30, (game->gameSizeY >> 1) + 3);
    printf("Press center button to start game.");
	while(1){
		//wait 100ms
		for(i = 0; i < 10; i++)
		{
			scrollText();//10ms
		}
		//1s / 100ms = 10hz update rate
		if(isButton1Pressed()){
			(game->difficulty)++;
			gotoxy((game->gameSizeX >> 1) - 30, (game->gameSizeY >> 1) + 2);
            printf("Select difficulty level by pressing left/right button (max. 5): %5d", game->difficulty);
		}
		if(isButton2Pressed() && game->difficulty > 1){
			(game->difficulty)--;
			gotoxy((game->gameSizeX >> 1) - 30, (game->gameSizeY >> 1) + 2);
        	printf("Select difficulty level by pressing left/right button (max. 5): %5d", game->difficulty);
		}
		if(isButton1Pressed() && isButton2Pressed() || game->difficulty >= 5){
			break;
		}
	}
}

void startLevel(struct TGame *game)
{
	char i;
	game->newBall = 1;
	game->levelWon = 0;

	//draw window
	clrscr();
	fgcolor(FCOLOR_WHITE);
	window(0, 0, game->gameSizeX, game->gameSizeY, '0', GAME_NAME);
	fgcolor(FCOLOR_WHITE);


	//initialize game objects
	initBall(&game->balls[0],game->gameSizeX >> 1, game->gameSizeY - 2, FCOLOR_WHITE, RANDOM(10, 170), 0, 1); // starting angle is random between 45 and 135 degrees
	for(i = 1; i <  MAX_BALL_COUNT; i++)
	{
		initBall(&game->balls[i], 0, 0, FCOLOR_RED, 0, 0, 0);
	}
	initStriker(&game->striker, game->gameSizeX >> 1, game->gameSizeY - 1 ,game->strikerLength);
	initBricks(game->bricks, game->brickCount);
	drawBoss(&game->boss);
	//TIMER !!!!

	// initialize game data
	gotoxy(0,game->gameSizeY + 1);
	//TID??
	printf("Difficulty: %5d\n", game->difficulty);
	printf("Total score: %5d\n",game->score);
	printf("Lives: %5d",game->lives);
}

void updateLives(int gameSizeY, int lives)
{
	gotoxy(0,gameSizeY + 3);
	fgcolor(FCOLOR_LIGHT_GRAY);
	printf("Lives: %5d", lives);
}

void updateGame(struct TGame *game)
{
	waitForEvent(&game->timer);
	if(isButton2Pressed())
	{
		game->levelWon = 1;
		return;
	}
	if(game->newBall)
	{
		moveStrikerPreShot(&game->balls[0], &game->striker, game->gameSizeX, isJoystickRight(),isJoystickLeft());
		moveStrikerPreShot(&game->balls[0], &game->striker, game->gameSizeX, isJoystickRight(),isJoystickLeft());
		if(isButton1Pressed())
		{
			game->newBall = 0;
		}
	}
	else
	{
		updateBalls(game->balls);
		moveStriker(&game->striker, game->gameSizeX, isJoystickRight(), isJoystickLeft());
		moveStriker(&game->striker, game->gameSizeX, isJoystickRight(), isJoystickLeft());
		impact(game->balls, &game->striker, game->gameSizeX, game->gameSizeY);
		bounceStriker(&game->striker, game->balls);
		updateBoss(&game->boss, game->balls);
		if(handleBrickCollisions(game->bricks, game->balls, game->brickCount))
		{
			game->levelWon = 1;
		}
		if(isBallDead(game->balls, game->gameSizeY))
		{
			if(IS_ALIVE(game->balls[0].data) == 0)
			{
				clearStriker(game->striker.position.x,game->striker.position.y, game->striker.length); 
				updateBallDrawnPosition(game->balls[0].position.x, game->balls[0].position.y, game->gameSizeX >> 1, game->gameSizeY - 2);
	
				initBall(&game->balls[0], game->gameSizeX >> 1, game->gameSizeY - 2, FCOLOR_WHITE, RANDOM(10, 170), 0, 1); // starting angle is random between 45 and 135 degrees
				initStriker(&game->striker, game->gameSizeX >> 1, game->gameSizeY - 1 ,game->strikerLength);
				game->newBall = 1;
			}
			game->lives--;
			
			updateLives(game->gameSizeY, game->lives);
		}
	}
}

void runGame(struct TGame *game)
{
	game->lives = DEFAULT_LIVES;
	game->level = 0;
	getDifficulty(game);
	playStartGameSound();
	do
	{
		game->level++;
		initLevel(game, game->level);
		startLevel(game);
		while(game->lives > 0 && game->levelWon == 0)
		{
			updateGame(game);
		}
		if(game->lives == 0)
		{
			playGameOverSound();
			break;
		}
	} while(game->level < LEVEL_COUNT);
	if(game->level == LEVEL_COUNT)
	{
		//game won
	}
}
