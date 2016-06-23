#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include <stdio.h>
#include "trigonometry.h"
#include "display.h"
#include "buttonio.h"
#include "timer.h"
#include "game.h"
#include "level.h"
#include "ball.h"
#include "striker.h"
#include "brick.h"
#include "boss.h"
#include "color.h"
#include "clockio.h"
#include "joystick.h"
#include "random.h"
#include "sound.h"
#include "fixedmath.h"
#include "charset.h"

//makes a game
void initGame(struct TGame *game)
{
	//standard instanser
	game->strikerLength = STRIKER_LENGTH;
	game->gameSizeX = GAME_SIZE_X;
	game->gameSizeY = GAME_SIZE_Y;
	game->lives = DEFAULT_LIVES;
	game->level = 0;
	game->score = 0;

	
	// start a clock with the chosen frequency which means the clock should tick every 1s / freq, 1s == 1000
	initTimer(&game->timer, 1000 / GAME_UPDATE_RATE);

	//init the method used to ontrol the game
	initJoystick();

	//init the led screens to show thegames name
	LEDinit(); 
	LEDsetString(GAME_NAME_LED);

	//init the sound
	initSoundPin();
	initSoundClock();
	
	//set foreground and background color
	color(FCOLOR_LIGHT_CYAN, BCOLOR_BLACK);
	//disable the cursor
	enablecursor('0');
}

//reset the variables that can change between games
void resetGame(struct TGame *game)
{
	game->level = 0;
	game->score = 0;
	game->strikerLength = STRIKER_LENGTH;
	game->lives = DEFAULT_LIVES;
}

//get difficulty from player input
void getDifficulty(struct TGame *game)
{
	char i;
	//default starting difficulty is 1
	game->difficulty = MIN_DIFFICULTY;

	//draw instruction for the player on screen to chose difficulty
	clrscr();
	fgcolor(FCOLOR_LIGHT_CYAN);
	window(0, 0, game->gameSizeX, game->gameSizeY, '0', GAME_NAME);
	gotoxy((game->gameSizeX >> 1) - 30, (game->gameSizeY >> 1));
	writeTitle(game->gameSizeX,5, "Welcome to", FCOLOR_LIGHT_CYAN);
	writeTitle(game->gameSizeX,5 + ROW_COUNT + 1, "Brick Breaker!", FCOLOR_LIGHT_CYAN);
    gotoxy((game->gameSizeX >> 1) - 30, (game->gameSizeY >> 1) + 2);
    printf("Select difficulty level by pressing A/B button (max. 5): %5d", game->difficulty);
    gotoxy((game->gameSizeX >> 1) - 30, (game->gameSizeY >> 1) + 3);
    printf("Press both buttons to start game.");
	while(1){
		//wait 100ms
		//1s / 100ms = 10hz update rate
		//update the displays
		for(i = 0; i < 10; i++)
		{
			//10ms
			//it takes 10ms to update all the displays
			scrollText();
		}
		//if button 1 and 2 is pressed or ifthe difficulty is 5 then the difficulty has been chosen 
		if(isButton1Pressed() && isButton2Pressed() || game->difficulty >= MAX_DIFFICULTY){
			break;
		}
		if(isButton1Pressed() && game->difficulty < MAX_DIFFICULTY){
			//increment difficulty and redraw the difficulty on the screen
			game->difficulty++;
			gotoxy((game->gameSizeX >> 1) - 30, (game->gameSizeY >> 1) + 2);
            printf("Select difficulty level by pressing A/B button (max. 5): %5d", game->difficulty);
		}
		if(isButton2Pressed() && game->difficulty > MIN_DIFFICULTY){
			//decrement difficulty and redraw the difficulty on the screen
			game->difficulty--;
			gotoxy((game->gameSizeX >> 1) - 30, (game->gameSizeY >> 1) + 2);
        	printf("Select difficulty level by pressing A/B button (max. 5): %5d", game->difficulty);
		}
	}
	//the amount of lives and the strikers length depends on the difficulty
	//so they are set now
	game->lives = DEFAULT_LIVES - (game->difficulty << 1);
	game->strikerLength -= 2 * game->difficulty;
}

//returns an angle that isn't straight up
int getAngle() {
	//get an angle that's pointing up
	int angle = RANDOM(10,170);
	//if the angle is too straight up then find a new angle
	if (angle <= 100 && angle >= 80) {
		angle = RANDOM(10,79);
	}
	return angle;
}

//write information to screen about the players lives and score
void updateGameInfo(int gameSizeY, int lives, int score)
{
	gotoxy(0, gameSizeY);
	fgcolor(FCOLOR_LIGHT_GRAY);
	printf("Total score: %5d", score);
	gotoxy(0,gameSizeY + 1);
	printf("Lives: %5d", lives);
}

//make the game ready for a level
void startLevel(struct TGame *game)
{
	char i;
	//the start of a game should always begin with the striker
	//having a ball which is why newBall is set to 1
	game->newBall = 1;
	//The level hasn't been won yet
	game->levelWon = 0;

	//draw game window
	color(FCOLOR_LIGHT_CYAN, BCOLOR_BLACK);
	clrscr();
	window(0, 0, game->gameSizeX, game->gameSizeY, '0', GAME_NAME);


	//init the players main ball at the center of the bottom line of the game with no speed and which is alive
	initBall(&game->balls[0],game->gameSizeX >> 1, game->gameSizeY - 2, FCOLOR_LIGHT_CYAN, getAngle(), 0, 1);
	//init the rest of the balls as red dead balls
	for(i = 1; i <  MAX_BALL_COUNT; i++)
	{
		initBall(&game->balls[i], 0, 0, FCOLOR_RED, 0, 0, 0);
	}
	//start the striker in the middle at the bottom of the game
	initStriker(&game->striker, game->gameSizeX >> 1, game->gameSizeY - 1 ,game->strikerLength);
	//draw the bricks 
	drawBricks(game->bricks, game->brickCount);
	drawBoss(&game->boss);

	fgcolor(FCOLOR_LIGHT_GRAY);
	gotoxy(0,game->gameSizeY + 1);
	printf("Difficulty: %d\n", game->difficulty);
	updateGameInfo(game->gameSizeY + 2, game->lives, game->score);
}

//updates everything in the game
void updateGame(struct TGame *game)
{
	//the game updates with a specific frequency
	//and this method will only return when its' time to update the game again
	waitForEvent(&game->timer);
	//this is a cheat to skip levels
	if(isButton2Pressed())
	{
		game->levelWon = 1;
		return;
	}
	//if the players main ball is dead
	if(game->newBall)
	{
		//move the stiker with the ball on top twice in one game update as the striker is otherwise too slow
		moveStrikerPreShot(&game->balls[0], &game->striker, game->gameSizeX, isJoystickRight(),isJoystickLeft());
		moveStrikerPreShot(&game->balls[0], &game->striker, game->gameSizeX, isJoystickRight(),isJoystickLeft());
		//when the player is satisfied with the strikers position the run the other code which starts the ball
		if(isButton1Pressed())
		{
			game->newBall = 0;
		}
	}
	else
	{
		//move all alive balls
		updateBalls(game->balls);
		//move striker twice so it doesn't feel slow
		moveStriker(&game->striker, game->gameSizeX, isJoystickRight(), isJoystickLeft());
		moveStriker(&game->striker, game->gameSizeX, isJoystickRight(), isJoystickLeft());
		//handle balls impacting the games walls
		impact(game->balls, game->gameSizeX, game->gameSizeY);
		//bounce balls off the striker
		bounceStriker(&game->striker, game->balls);
		//update the boss and all its bricks
		updateBoss(&game->boss, game->balls, &game->score, game->difficulty);
		//if all brick that had health and wasn't indestructible are dead and the boss is dead then win the level
		if(handleBrickCollisions(game->bricks, game->balls, game->brickCount, &game->score) && isBossDead(&game->boss))
		{
			game->levelWon = 1;
		}
		//handle any balls dying and if any balls are dead
		else if(isBallDead(game->balls, game->gameSizeY))
		{
			//if the ball that is dead the the players main ball then set the striker to start the ball again
			if(IS_ALIVE(game->balls[0].data) == 0)
			{
				clearStriker(game->striker.position.x,game->striker.position.y, game->striker.length); 
				updateBallDrawnPosition(game->balls[0].position.x, game->balls[0].position.y, TO_FIX14(game->gameSizeX >> 1), TO_FIX14(game->gameSizeY - 2));
	
				initBall(&game->balls[0], game->gameSizeX >> 1, game->gameSizeY - 2, FCOLOR_LIGHT_CYAN, getAngle(), 0, 1); 
				initStriker(&game->striker, game->gameSizeX >> 1, game->gameSizeY - 1 , game->strikerLength);
				game->newBall = 1;
			}
			game->lives--;
		}
		updateGameInfo(game->gameSizeY + 2, game->lives, game->score);
	}
}

//writes the end screen which is mostly the same wether the player won or lost 
//except for the message in the middle of the screen and the color of the text
void endScreen(struct TGame *game, char message[], char color)
{
	char formattedString[13];
	clrscr();
	fgcolor(FCOLOR_LIGHT_CYAN);
	window(0, 0, game->gameSizeX, game->gameSizeY, '0', GAME_NAME);
    writeTitle(game->gameSizeX, (game->gameSizeY >> 1) - 5, message, color);
	//format the score string and write it as a title
	sprintf(formattedString, "Score: %5d", game->score + game->lives * 500 * game->difficulty);
	writeTitle(game->gameSizeX, (game->gameSizeY >> 1) + 3, formattedString, color);

	gotoxy((game->gameSizeX >> 1) - 10, (game->gameSizeY >> 1) + 3 + ROW_COUNT + 2);
	printf("Press button B to restart");
	gotoxy(0, game->gameSizeY + 1);
	printf("Score = points + lives * 500 * difficulty");
}

//writes to the screen that the player lost
void gameLost(struct TGame *game)
{
	endScreen(game, "GAME OVER", FCOLOR_RED);
}

//writes to the screen that the player won
void gameWon(struct TGame *game)
{
	endScreen(game, "YOU WIN!!!!", FCOLOR_GREEN);
}

//starts or restarts the game
void runGame(struct TGame *game)
{
	//if it restarts the game then the game has to be reset
	resetGame(game);
	//get the difficulty of the game from the player
	getDifficulty(game);
	playStartGameSound();
	do
	{
		game->level++;
		//load the level int game
		initLevel(game, game->level);
		startLevel(game);
		//run the level until the player is either dead or won the level
		while(game->lives > 0 && game->levelWon == 0)
		{
			updateGame(game);
		}
		//if the player is dead
		if(game->lives == 0)
		{
			break;
		}
		//run until there is no more levels
	} while(game->level < LEVEL_COUNT);
	//if the player won the game
	if(game->level == LEVEL_COUNT && game->lives > 0)
	{
		gameWon(game);
		playGameWinSound();
	}
	else {
		gameLost(game);
		playGameOverSound();
	}
	//wait for the player to press button 2 to exit the gameover or game won screen
	while(!isButton2Pressed()) {}
}
