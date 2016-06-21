#include <eZ8.h>             // special encore constants, macros and flash routines
#include <sio.h>             // special encore serial i/o routines
#include "level.h"
#include "ansi.h"
#include "striker.h"
#include "ball.h"
#include "powerup.h"
#include "boss.h"
#include "brick.h"
#include "fixedmath.h"
#include "game.h"

#define BRICK_HEIGHT_1_ 2
#define BRICK_WIDTH_1_ 6
#define BRICK_SIZE_1_ MAKE_SIZE(BRICK_HEIGHT_1_, BRICK_WIDTH_1_)

#define BRICK_HEIGHT_2_ 2
#define BRICK_WIDTH_2_ 8
#define BRICK_SIZE_2_ MAKE_SIZE(BRICK_HEIGHT_2_, BRICK_WIDTH_2_)

#define BOSS_START_X_3_ 33
#define BOSS_START_Y_3_ 13
#define BOSS_BRICK_DEFAULT_3_ 1
#define BOSS_BRICK_INVULNERABLE_3_ (BOSS_BRICK_DEFAULT_3_ | (1 << INDESTRUCTIBLE_BIT_SHIFT))
#define BOSS_BRICK_MOVING_INVULNERABLE_3_ (BOSS_BRICK_INVULNERABLE_3_ | (1 << MOVING_BIT_SHIFT))

void level1(struct TGame *game)
{
	char i;
	struct TBrick bricks[39] = 
	{
		{(BRICK_WIDTH_1_ + 1) * 1, (BRICK_HEIGHT_1_ + 1) * 5, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 2, (BRICK_HEIGHT_1_ + 1) * 5, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 3, (BRICK_HEIGHT_1_ + 1) * 5, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 4, (BRICK_HEIGHT_1_ + 1) * 5, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 5, (BRICK_HEIGHT_1_ + 1) * 5, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 6, (BRICK_HEIGHT_1_ + 1) * 5, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 7, (BRICK_HEIGHT_1_ + 1) * 5, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 8, (BRICK_HEIGHT_1_ + 1) * 5, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 9, (BRICK_HEIGHT_1_ + 1) * 5, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) *10, (BRICK_HEIGHT_1_ + 1) * 5, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) *11, (BRICK_HEIGHT_1_ + 1) * 5, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) *12, (BRICK_HEIGHT_1_ + 1) * 5, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) *12, (BRICK_HEIGHT_1_ + 1) * 5, BRICK_SIZE_1_, 3},
		{(BRICK_WIDTH_1_ + 1) * 1, (BRICK_HEIGHT_1_ + 1) * 6, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 2, (BRICK_HEIGHT_1_ + 1) * 6, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 3, (BRICK_HEIGHT_1_ + 1) * 6, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 4, (BRICK_HEIGHT_1_ + 1) * 6, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 5, (BRICK_HEIGHT_1_ + 1) * 6, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 6, (BRICK_HEIGHT_1_ + 1) * 6, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 7, (BRICK_HEIGHT_1_ + 1) * 6, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 8, (BRICK_HEIGHT_1_ + 1) * 6, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 9, (BRICK_HEIGHT_1_ + 1) * 6, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) *10, (BRICK_HEIGHT_1_ + 1) * 6, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) *11, (BRICK_HEIGHT_1_ + 1) * 6, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) *12, (BRICK_HEIGHT_1_ + 1) * 6, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) *12, (BRICK_HEIGHT_1_ + 1) * 6, BRICK_SIZE_1_, 2},
		{(BRICK_WIDTH_1_ + 1) * 1, (BRICK_HEIGHT_1_ + 1) * 7, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 2, (BRICK_HEIGHT_1_ + 1) * 7, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 3, (BRICK_HEIGHT_1_ + 1) * 7, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 4, (BRICK_HEIGHT_1_ + 1) * 7, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 5, (BRICK_HEIGHT_1_ + 1) * 7, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 6, (BRICK_HEIGHT_1_ + 1) * 7, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 7, (BRICK_HEIGHT_1_ + 1) * 7, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 8, (BRICK_HEIGHT_1_ + 1) * 7, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) * 9, (BRICK_HEIGHT_1_ + 1) * 7, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) *10, (BRICK_HEIGHT_1_ + 1) * 7, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) *11, (BRICK_HEIGHT_1_ + 1) * 7, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) *12, (BRICK_HEIGHT_1_ + 1) * 7, BRICK_SIZE_1_, 1},
		{(BRICK_WIDTH_1_ + 1) *12, (BRICK_HEIGHT_1_ + 1) * 7, BRICK_SIZE_1_, 1},
	};
	struct TBrick bossBricks[0];
	int brickCount = sizeof(bricks) / sizeof(bricks[0]);
	for(i = 0; i < brickCount; i++)
	{
		game->bricks[i] = bricks[i];
	}
	initBoss(&game->boss, bossBricks, 0, 0, 0, 0);

	game->brickCount = brickCount;
}

void level2(struct TGame *game)
{
	char i;
	struct TBrick bricks[39] = 
	{
		{(BRICK_WIDTH_2_) * 1, (BRICK_HEIGHT_2_ + 1) * 3, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 3, (BRICK_HEIGHT_2_ + 1) * 3, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 5, (BRICK_HEIGHT_2_ + 1) * 3, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 7, (BRICK_HEIGHT_2_ + 1) * 3, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 9, (BRICK_HEIGHT_2_ + 1) * 3, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 11, (BRICK_HEIGHT_2_ + 1) * 3, BRICK_SIZE_2_, 3},

		{(BRICK_WIDTH_2_) * 2 , (BRICK_HEIGHT_2_ + 1) * 4, BRICK_SIZE_2_, 2},
		{(BRICK_WIDTH_2_) * 4 , (BRICK_HEIGHT_2_ + 1) * 4, BRICK_SIZE_2_, 2},
		{(BRICK_WIDTH_2_) * 6 , (BRICK_HEIGHT_2_ + 1) * 4, BRICK_SIZE_2_, 1},
		{(BRICK_WIDTH_2_) * 8 , (BRICK_HEIGHT_2_ + 1) * 4, BRICK_SIZE_2_, 2},
		{(BRICK_WIDTH_2_) * 10 , (BRICK_HEIGHT_2_ + 1) * 4, BRICK_SIZE_2_, 2},

		{(BRICK_WIDTH_2_) * 1, (BRICK_HEIGHT_2_ + 1) * 5, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 3, (BRICK_HEIGHT_2_ + 1) * 5, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 5, (BRICK_HEIGHT_2_ + 1) * 5, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 7, (BRICK_HEIGHT_2_ + 1) * 5, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 9, (BRICK_HEIGHT_2_ + 1) * 5, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) *11, (BRICK_HEIGHT_2_ + 1) * 5, BRICK_SIZE_2_, 3},

		{(BRICK_WIDTH_2_) * 2 , (BRICK_HEIGHT_2_ + 1) * 6, BRICK_SIZE_2_, 2},
		{(BRICK_WIDTH_2_) * 4 , (BRICK_HEIGHT_2_ + 1) * 6, BRICK_SIZE_2_, 2},
		{(BRICK_WIDTH_2_) * 6 , (BRICK_HEIGHT_2_ + 1) * 6, BRICK_SIZE_2_, 1},
		{(BRICK_WIDTH_2_) * 8 , (BRICK_HEIGHT_2_ + 1) * 6, BRICK_SIZE_2_, 2},
		{(BRICK_WIDTH_2_) *10 , (BRICK_HEIGHT_2_ + 1) * 6, BRICK_SIZE_2_, 2},

		{(BRICK_WIDTH_2_) * 1, (BRICK_HEIGHT_2_ + 1) * 7, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 3, (BRICK_HEIGHT_2_ + 1) * 7, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 5, (BRICK_HEIGHT_2_ + 1) * 7, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 7, (BRICK_HEIGHT_2_ + 1) * 7, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 9, (BRICK_HEIGHT_2_ + 1) * 7, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) *11, (BRICK_HEIGHT_2_ + 1) * 7, BRICK_SIZE_2_, 3},

		{(BRICK_WIDTH_2_) * 2 , (BRICK_HEIGHT_2_ + 1) * 8, BRICK_SIZE_2_, 2},
		{(BRICK_WIDTH_2_) * 4 , (BRICK_HEIGHT_2_ + 1) * 8, BRICK_SIZE_2_, 2},
		{(BRICK_WIDTH_2_) * 6 , (BRICK_HEIGHT_2_ + 1) * 8, BRICK_SIZE_2_, 1},
		{(BRICK_WIDTH_2_) * 8 , (BRICK_HEIGHT_2_ + 1) * 8, BRICK_SIZE_2_, 2},
		{(BRICK_WIDTH_2_) *10 , (BRICK_HEIGHT_2_ + 1) * 8, BRICK_SIZE_2_, 2},

		{(BRICK_WIDTH_2_) * 1, (BRICK_HEIGHT_2_ + 1) * 9, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 3, (BRICK_HEIGHT_2_ + 1) * 9, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 5, (BRICK_HEIGHT_2_ + 1) * 9, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 7, (BRICK_HEIGHT_2_ + 1) * 9, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) * 9, (BRICK_HEIGHT_2_ + 1) * 9, BRICK_SIZE_2_, 3},
		{(BRICK_WIDTH_2_) *11, (BRICK_HEIGHT_2_ + 1) * 9, BRICK_SIZE_2_, 3},

	};
	struct TBrick bossBricks[0];
	int brickCount = sizeof(bricks) / sizeof(bricks[0]);
	for(i = 0; i < brickCount; i++)
	{
		game->bricks[i] = bricks[i];
	}
	initBoss(&game->boss, bossBricks, 0, 0, 0, 0);

	game->brickCount = brickCount;
}

void level3(struct TGame *game)
{
	char i;
	struct TBrick bricks[32] = 
	{
		{BOSS_START_X_3_ + 2 - 5 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 5 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 2},
		{BOSS_START_X_3_ + 2 - 3 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 5 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 2},
		{BOSS_START_X_3_ + 2 - 1 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 5 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 2},
		{BOSS_START_X_3_ + 2 + 1 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 5 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 2},
		{BOSS_START_X_3_ + 2 + 3 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 5 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 2},
		{BOSS_START_X_3_ + 2 + 5 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 5 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 2},
		{BOSS_START_X_3_ + 2 + 7 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 5 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 2},
		{BOSS_START_X_3_ + 2 + 9 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 5 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 2},

		{BOSS_START_X_3_ + 2 - 4 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 3 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 3},
		{BOSS_START_X_3_ + 2 - 2 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 3 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 3},
		{BOSS_START_X_3_ + 2 - 0 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 3 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 3},
		{BOSS_START_X_3_ + 2 + 2 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 3 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 3},
		{BOSS_START_X_3_ + 2 + 4 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 3 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 3},
		{BOSS_START_X_3_ + 2 + 6 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 3 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 3},
		{BOSS_START_X_3_ + 2 + 8 * BRICK_WIDTH_1_, BOSS_START_Y_3_ - 3 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 3},

		{BOSS_START_X_3_ + 2 - 5 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 9 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 2},
		{BOSS_START_X_3_ + 2 - 3 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 9 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 2},
		{BOSS_START_X_3_ + 2 - 1 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 9 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 2},
		{BOSS_START_X_3_ + 2 + 5 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 9 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 2},
		{BOSS_START_X_3_ + 2 + 7 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 9 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 2},
		{BOSS_START_X_3_ + 2 + 9 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 9 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 2},

		{BOSS_START_X_3_ + 2 - 4 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 7 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 3},
		{BOSS_START_X_3_ + 2 - 2 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 7 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 3},
		{BOSS_START_X_3_ + 2 - 0 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 7 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 3},
		{BOSS_START_X_3_ + 2 + 4 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 7 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 3},
		{BOSS_START_X_3_ + 2 + 6 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 7 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 3},
		{BOSS_START_X_3_ + 2 + 8 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 7 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, 3},


	};
	struct TBrick bossBricks[BOSS_BRICK_COUNT] = 
	{
		{BOSS_START_X_3_ + 0 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 0 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_INVULNERABLE_3_},
		{BOSS_START_X_3_ + 2 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 0 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_INVULNERABLE_3_},
		{BOSS_START_X_3_ + 3 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 0 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_INVULNERABLE_3_},
		{BOSS_START_X_3_ + 5 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 0 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_INVULNERABLE_3_},
		{BOSS_START_X_3_ + 1 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 1 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_INVULNERABLE_3_},
		{BOSS_START_X_3_ + 2 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 1 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_INVULNERABLE_3_},
		{BOSS_START_X_3_ + 3 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 1 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_INVULNERABLE_3_}, 
		{BOSS_START_X_3_ + 4 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 1 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_INVULNERABLE_3_},
		{BOSS_START_X_3_ + 0 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 2 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_INVULNERABLE_3_},
		{BOSS_START_X_3_ + 1 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 2 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_INVULNERABLE_3_},
		{BOSS_START_X_3_ + 2 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 2 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_DEFAULT_3_}, 
		{BOSS_START_X_3_ + 3 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 2 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_DEFAULT_3_},
		{BOSS_START_X_3_ + 4 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 2 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_INVULNERABLE_3_},
		{BOSS_START_X_3_ + 5 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 2 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_INVULNERABLE_3_},
		{BOSS_START_X_3_ + 1 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 3 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_MOVING_INVULNERABLE_3_ | DIRECTION_MASK},
		{BOSS_START_X_3_ + 4 * BRICK_WIDTH_1_, BOSS_START_Y_3_ + 3 * BRICK_HEIGHT_1_, BRICK_SIZE_1_, BOSS_BRICK_MOVING_INVULNERABLE_3_},
	};
	char startX = BOSS_START_X_3_ + 3 * BRICK_WIDTH_1_ + 1;
	char startY = BOSS_START_Y_3_ + 5 * BRICK_HEIGHT_1_ + 1;
	char movement = X_AXIS_MOVEMENT_MASK | (BRICK_SIZE_1_ & BRICK_WIDTH_MASK);
	int brickCount = sizeof(bricks) / sizeof(bricks[0]);
	for(i = 0; i < brickCount; i++)
	{
		game->bricks[i] = bricks[i];
	}

	initBoss(&game->boss, bossBricks, startX, startY, movement, 1);

	game->brickCount = brickCount;
}


void initLevel(struct TGame *game, int level)
{
	switch(level)
	{
		case 1:
			level1(game);
			break;
		case 2:
			level2(game);
			break;
		case 3:
			level3(game);
			break;
		default:
			break;
	}
}


