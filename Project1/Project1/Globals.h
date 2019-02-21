#ifndef GLOBALS
#define GLOBALS

#include <SFML/Graphics.hpp>

enum class GameState
{
	splashScreen,
	gamePlay
};

static const int SCREEN_WIDTH{ 1000 };
static const int SCREEN_HEIGHT{ 800 };

static const int TOP{ 1 };
static const int BOTTOM{ 2 };
static const int LEFT{ 3 };
static const int RIGHT{ 4 };

static const int TOTAL_ASTEROIDS{ 4 };
static const int TOTAL_BULLETS{ 10 };

static int aliveBullets{ 0 }; //used to keep track of how many bullets are alive
static int waitToFire{ 0 }; //used to control how fast the bullets fire

//enum class GameState
//{
//	Splash,
//	GamePlay,
//	EndGame,
//};

#endif