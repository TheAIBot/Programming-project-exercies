#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "SineLUT.h"
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

#define brickHeight 2
#define brickWidth 6
#define bricksize 0x26

void initBallStriker(struct TBall *ball, struct TStriker *striker, int gameSize)
{
	int initialx = gameSize / 2;
	int initialStrikerY = gameSize - 1;
	int initialBallY = initialStrikerY - 1;
	int velocity = 0;
	int angle = 40;
	int strikerLength = 5;

	initBall(ball, initialx, initialBallY, FCOLOR_BLUE, angle, velocity, 1); // need to know why -3 and -2 is needed
	initStriker(striker, initialx, initialStrikerY ,strikerLength);
}

void initGame(struct TGame *game, int gameSizeX, int gameSizeY, int strikerLength, int updateFrequency)
{
	char i;
	struct TBrick bricks[1] = 
	{
		{(brickWidth + 1) * 1, (brickHeight + 1) * 15, bricksize, 3},
		/*{(brickWidth + 1) * 2, (brickHeight + 1) * 15, bricksize, 3},
		{(brickWidth + 1) * 3, (brickHeight + 1) * 15, bricksize, 3},
		{(brickWidth + 1) * 4, (brickHeight + 1) * 15, bricksize, 3},
		{(brickWidth + 1) * 5, (brickHeight + 1) * 15, bricksize, 3},
		{(brickWidth + 1) * 6, (brickHeight + 1) * 15, bricksize, 3},
		{(brickWidth + 1) * 7, (brickHeight + 1) * 15, bricksize, 3},
		{(brickWidth + 1) * 8, (brickHeight + 1) * 15, bricksize, 3},
		{(brickWidth + 1) * 9, (brickHeight + 1) * 15, bricksize, 3},
		{(brickWidth + 1) *10, (brickHeight + 1) * 15, bricksize, 3},
		{(brickWidth + 1) *11, (brickHeight + 1) * 15, bricksize, 3},
		{(brickWidth + 1) *12, (brickHeight + 1) * 15, bricksize, 3},
		{(brickWidth + 1) * 1, (brickHeight + 1) * 16, bricksize, 3},
		{(brickWidth + 1) * 2, (brickHeight + 1) * 16, bricksize, 3},
		{(brickWidth + 1) * 3, (brickHeight + 1) * 16, bricksize, 3},
		{(brickWidth + 1) * 4, (brickHeight + 1) * 16, bricksize, 3},
		{(brickWidth + 1) * 5, (brickHeight + 1) * 16, bricksize, 3},
		{(brickWidth + 1) * 6, (brickHeight + 1) * 16, bricksize, 3},
		{(brickWidth + 1) * 7, (brickHeight + 1) * 16, bricksize, 3},
		{(brickWidth + 1) * 8, (brickHeight + 1) * 16, bricksize, 3},
		{(brickWidth + 1) * 9, (brickHeight + 1) * 16, bricksize, 3},
		{(brickWidth + 1) *10, (brickHeight + 1) * 16, bricksize, 3},
		{(brickWidth + 1) *11, (brickHeight + 1) * 16, bricksize, 3},
		{(brickWidth + 1) *12, (brickHeight + 1) * 16, bricksize, 3},
		{(brickWidth + 1) * 1, (brickHeight + 1) * 17, bricksize, 3},
		{(brickWidth + 1) * 2, (brickHeight + 1) * 17, bricksize, 3},
		{(brickWidth + 1) * 3, (brickHeight + 1) * 17, bricksize, 3},
		{(brickWidth + 1) * 4, (brickHeight + 1) * 17, bricksize, 3},
		{(brickWidth + 1) * 5, (brickHeight + 1) * 17, bricksize, 3},
		{(brickWidth + 1) * 6, (brickHeight + 1) * 17, bricksize, 3},
		{(brickWidth + 1) * 7, (brickHeight + 1) * 17, bricksize, 3},
		{(brickWidth + 1) * 8, (brickHeight + 1) * 17, bricksize, 3},
		{(brickWidth + 1) * 9, (brickHeight + 1) * 17, bricksize, 3},
		{(brickWidth + 1) *10, (brickHeight + 1) * 17, bricksize, 3},
		{(brickWidth + 1) *11, (brickHeight + 1) * 17, bricksize, 3},
		{(brickWidth + 1) *12, (brickHeight + 1) * 17, bricksize, 3},*/
	};
	int brickCount = sizeof(bricks) / sizeof(bricks[0]);
	for(i = 0; i < brickCount; i++)
	{
		game->bricks[i] = bricks[i];
	}
	game->brickCount = brickCount;
	
		//standard instanser
	
	game->strikerLength = strikerLength;
	game->gameSizeX = gameSizeX;
	game->gameSizeY = gameSizeY;
	game->lives = 10;
	
	// start a clock with the chosen frequency which means the clock should tick every 1s / freq, 1s == 1000
	initTimer(&game->timer, 1000 / updateFrequency);

	//initButtons();
	initJoystick();

	LEDinit(); 
	LEDsetString(GAME_NAME);

	color(FCOLOR_WHITE, BCOLOR_BLACK);
	enablecursor('0');
}

void getDifficulty(struct TGame *game)
{
	while(1) {
		// begin main loop, selecting difficulty level
		clrscr();
		window(0, 0, game->gameSizeX, game->gameSizeY, '0', GAME_NAME);
		gotoxy((game->gameSizeX / 2) - 15, (game->gameSizeY / 2));
	    printf("Welcome to Brick Breaker!");
	    gotoxy((game->gameSizeX / 2) - 15, (game->gameSizeY / 2) - 2);
	    printf("Select difficulty level by pressing left/right button (max. 5): %5d", game->difficulty);
	    gotoxy((game->gameSizeX / 2) - 15, (game->gameSizeY / 2) - 3);
	    printf("Press center button to start game.");
		while(1){
			scrollText();//10ms
			scrollText();//10ms
			scrollText();//10ms
			scrollText();//10ms
			scrollText();//10ms
			scrollText();//10ms
			scrollText();//10ms
			scrollText();//10ms
			scrollText();//10ms
			scrollText();//10ms
			//1s / 100ms = 10hz update rate
			if(isd3Pressed()){
				game->difficulty++;
				gotoxy((game->gameSizeX / 2) - 15, (game->gameSizeY / 2) - 2);
	            printf("Select difficulty level by pressing left/right button: %5d", game->difficulty);
			}
			if( isf7Pressed() && game->difficulty > 1){
				game->difficulty--;
				gotoxy((game->gameSizeX / 2) - 15, (game->gameSizeY / 2) - 2);
	        	printf("Select difficulty level by pressing left/right button: %5d", game->difficulty);
			}
			if(isf6Pressed() || game->difficulty == 5){
				break;
			}
		}
	}
}

void startLevel(struct TGame *game)
{
	char i;
	game->newBall = 1;
	//initialize game objects
	initBall(&game->balls[0],game->gameSizeX >> 1, game->gameSizeY - 2, FCOLOR_WHITE, 45, 0, 1);
	for(i = 1; i <  6; i++)
	{
		initBall(&game->balls[i], 0, 0, FCOLOR_RED, 0, 0, 0);
	}
	initStriker(&game->striker, game->gameSizeX >> 1, game->gameSizeY - 1 ,game->strikerLength);
	initBricks(game->bricks, game->brickCount);
	initBoss(&game->boss);

	//draw window
	clrscr();
	fgcolor(FCOLOR_WHITE);
	window(0, 0, game->gameSizeX, game->gameSizeY, '0', GAME_NAME);
	fgcolor(FCOLOR_WHITE);
	//TIMER !!!!

	// initialize game data
	gotoxy(0,game->gameSizeY + 1);
	//TID??
	printf("Difficulty: %5d\n", game->difficulty);
	printf("Total score: %5d\n",game->score);
	printf("Lives: %5d",game->lives);
}

void updateGame(struct TGame *game)
{
	waitForEvent(&game->timer);
	if(game->newBall)
	{
		moveStrikerPreShot(&game->balls[0], &game->striker, game->gameSizeX, isd3Pressed(), isf7Pressed());
		if(!isf6Pressed())
		{
			game->newBall = 0;
		}
	}
	else
	{
		updateBalls(game->balls);
		moveStriker(&game->striker, game->gameSizeX, isf7Pressed(), isd3Pressed());
		impact(game->balls, &game->striker, game->gameSizeX, game->gameSizeY);
		bounceStriker(&game->striker, game->balls);
		handleBrickCollisions(game->bricks, game->balls, game->brickCount);
		updateBoss(&game->boss, game->balls);
		if(isBallDead(game->balls, game->gameSizeY))
		{
			clearStriker(game->striker.position.x,game->striker.position.y, game->striker.length); 
			updateBallDrawnPosition(game->balls[0].position.x, game->balls[0].position.y, game->gameSizeX >> 1, game->gameSizeY - 2);

			initBall(&game->balls[0], game->gameSizeX >> 1, game->gameSizeY - 2, FCOLOR_WHITE, 45, 0, 1);
			initStriker(&game->striker, game->gameSizeX >> 1, game->gameSizeY - 1 ,game->strikerLength);
			game->newBall = 1;
			game->lives--;
			
			gotoxy(0,game->gameSizeY + 3);
			printf("Lives: %5d", game->lives);
		}
	}
}

void runGame(struct TGame *game)
{
	getDifficulty(game);
	startLevel(game);
	while(game->lives > 0)
	{
		updateGame(game);
	}
}
