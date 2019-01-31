// author Aaron O Neill
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Asteroid.h"
#include "EnemySpaceShip.h"
#include "PlayerSpaceShip.h"
#include "Shield.h"
#include "MyVector2.h"

class Game
{
public:
	Game();
	~Game();
	/// main method for game
	void run();

private:

	enum gameState
	{
		splashScreen,
		inGame,
		endScreen
	};

	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();
	void setupSprite();

	gameState m_gameState;

	PlayerSpaceShip m_player; //main player object
	EnemySpaceShip m_enemy; //enemy follower
	Shield m_playerShield; //players shield

	sf::View m_playerView; //camera that follows the player
	sf::RenderWindow m_window; //main render window

	sf::Font m_mainFont; // font used by message
	sf::Font m_titleFont; // font used for the main title
	sf::Text m_title; //main title on the splashScreen

	bool m_exitGame; // control exiting game

};

#endif // !GAME

