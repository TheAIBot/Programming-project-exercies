#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include <stdio.h>
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
#include "fixedmath.h"
#include "charset.h"


void initGame(struct TGame *game)
{
		//standard instanser
	game->strikerLength = STRIKER_LENGTH;
	game->gameSizeX = GAME_SIZE_X;
	game->gameSizeY = GAME_SIZE_Y;
	game->lives = DEFAULT_LIVES;
	game->level = 1;
	game->levelWon = 0;

	
	// start a clock with the chosen frequency which means the clock should tick every 1s / freq, 1s == 1000
	initTimer(&game->timer, 1000 / GAME_UPDATE_RATE);

	//initButtons();
	initJoystick();

	LEDinit(); 
	LEDsetString(GAME_NAME_LED);

	initSoundPin();
	initSoundClock();

	color(FCOLOR_WHITE, BCOLOR_BLACK);
	enablecursor('0');
}

void resetGame(struct TGame *game)
{
	game->level = 0;
	game->score = 0;
	game->strikerLength = STRIKER_LENGTH;
}

void getDifficulty(struct TGame *game)
{
	char i;
	game->difficulty = 1;
	// begin main loop, selecting difficulty level
	clrscr();
	fgcolor(FCOLOR_WHITE);
	window(0, 0, game->gameSizeX, game->gameSizeY, '0', GAME_NAME);
	gotoxy((game->gameSizeX >> 1) - 30, (game->gameSizeY >> 1));
	writeTitle(game->gameSizeX,5, "Welcome to", FCOLOR_WHITE);
	writeTitle(game->gameSizeX,5 + ROW_COUNT + 1, "Brick Breaker!", FCOLOR_WHITE);
    gotoxy((game->gameSizeX >> 1) - 30, (game->gameSizeY >> 1) + 2);
    printf("Select difficulty level by pressing up/down button (max. 5): %5d", game->difficulty);
    gotoxy((game->gameSizeX >> 1) - 30, (game->gameSizeY >> 1) + 3);
    printf("Press both buttons to start game.");
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
            printf("Select difficulty level by pressing up/down button (max. 5): %5d", game->difficulty);
		}
		if(isButton2Pressed() && game->difficulty > 1){
			(game->difficulty)--;
			gotoxy((game->gameSizeX >> 1) - 30, (game->gameSizeY >> 1) + 2);
        	printf("Select difficulty level by pressing up/down button (max. 5): %5d", game->difficulty);
		}
		if(isButton1Pressed() && isButton2Pressed() || game->difficulty >= 5){
			break;
		}
	}
	game->lives = DEFAULT_LIVES - (game->difficulty << 1);
	game->strikerLength -= 2 * game->difficulty;
}

int getAngle() {
	int angle = RANDOM(10,170);
	if (angle <= 100 && angle >= 80) {
		angle = RANDOM(10,84);
	}
	return angle;
}

void updateGameInfo(int gameSizeY, int lives, int score)
{
	gotoxy(0,gameSizeY);
	fgcolor(FCOLOR_LIGHT_GRAY);
	printf("Total score: %5d", score);
	gotoxy(0,gameSizeY + 1);
	printf("Lives: %5d", lives);
}

void startLevel(struct TGame *game)
{
	char i;
	game->newBall = 1;
	game->levelWon = 0;

	//draw window
	color(FCOLOR_WHITE, BCOLOR_BLACK);
	clrscr();
	window(0, 0, game->gameSizeX, game->gameSizeY, '0', GAME_NAME);


	//initialize game objects
	initBall(&game->balls[0],game->gameSizeX >> 1, game->gameSizeY - 2, FCOLOR_WHITE, getAngle(), 0, 1); // starting angle is random between 45 and 135 degrees
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
	fgcolor(FCOLOR_LIGHT_GRAY);
	printf("Difficulty: %5d\n", game->difficulty);
	updateGameInfo(game->gameSizeY + 2, game->lives, game->score);
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
		updateBoss(&game->boss, game->balls, &game->score, game->difficulty);
		if(handleBrickCollisions(game->bricks, game->balls, game->brickCount, &game->score) && isBossDead(&game->boss))
		{
			game->levelWon = 1;
		}
		else if(isBallDead(game->balls, game->gameSizeY))
		{
			if(IS_ALIVE(game->balls[0].data) == 0)
			{
				clearStriker(game->striker.position.x,game->striker.position.y, game->striker.length); 
				updateBallDrawnPosition(game->balls[0].position.x, game->balls[0].position.y, TO_FIX14(game->gameSizeX >> 1), TO_FIX14(game->gameSizeY - 2));
	
				initBall(&game->balls[0], game->gameSizeX >> 1, game->gameSizeY - 2, FCOLOR_WHITE, getAngle(), 0, 1); // starting angle is random between 45 and 135 degrees
				initStriker(&game->striker, game->gameSizeX >> 1, game->gameSizeY - 1 , game->strikerLength);
				game->newBall = 1;
			}
			game->lives--;
		}
		updateGameInfo(game->gameSizeY + 2, game->lives, game->score);
	}
}

void gameLost(struct TGame *game)
{
	char formattedString[13];
	clrscr();
	fgcolor(FCOLOR_WHITE);
	window(0, 0, game->gameSizeX, game->gameSizeY, '0', GAME_NAME);
    writeTitle(game->gameSizeX, (game->gameSizeY >> 1) - COLUMN_COUNT, "GAME OVER", FCOLOR_RED);
	sprintf(formattedString, "Score: %5d", game->score);
	writeTitle(game->gameSizeX, (game->gameSizeY >> 1) + 3, formattedString, FCOLOR_RED);
	gotoxy(0, game->gameSizeY + 1);
	printf("Score = points + lives * 500 * difficulty");
}

void gameWon(struct TGame *game)
{
	char formattedString[13];
	clrscr();
	fgcolor(FCOLOR_WHITE);
	window(0, 0, game->gameSizeX, game->gameSizeY, '0', GAME_NAME);
    writeTitle(game->gameSizeX, (game->gameSizeY >> 1) - 5, "YOU WIN!!!!", FCOLOR_GREEN);
	sprintf(formattedString, "Score: %5d", game->score + game->lives * 500 * game->difficulty);
	writeTitle(game->gameSizeX, (game->gameSizeY >> 1) + 3, formattedString, FCOLOR_GREEN);
	gotoxy(0, game->gameSizeY + 1);
	printf("Score = points + lives * 500 * difficulty");
}

void runGame(struct TGame *game)
{
	resetGame(game);
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
			break;
		}
	} while(game->level < LEVEL_COUNT);
	if(game->level == LEVEL_COUNT && game->lives > 0)
	{
		gameWon(game);
		playGameWinSound();
	}
	else {
		gameLost(game);
		playGameOverSound();
	}
	while(!isButton2Pressed()) {}
}
