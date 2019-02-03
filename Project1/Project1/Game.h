// author Aaron O Neill
#ifndef GAME
#define GAME

#include <SFML/Graphics.hpp>
#include "Asteroid.h"
#include "PatrolEnemy.h"
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
	//enum for what state the game is in
	enum GameState
	{
		Splash,
		GamePlay,
		End
	};

	//main update loop
	void processEvents();
	void update(sf::Time t_deltaTime);
	void render();
	
	//seperate functions
	void setupFontAndText();
	void setupSprite();

	//game states and objects
	GameState m_currentState;

	PlayerSpaceShip m_player; //main player object
	Shield m_playerShield; //players shield
	Asteroid m_asteroid;

	sf::View m_playerView; //camera that follows the player
	sf::RenderWindow m_window; //main render window

	//shapes

	//texture and sprites
	sf::Texture m_backgroundTexture; //texture for the background image
	sf::Sprite m_background; 

	sf::Texture m_controlsTexture; //texture to show player what the controls are
	sf::Sprite m_controls;

	//font and text
	sf::Font m_mainFont; // font used by message
	sf::Font m_titleFont; // font used for the main title
	sf::Text m_title; //main title on the splashScreen
	sf::Text m_asteroidText; //text that displays what the asteroid is
	sf::Text m_enemyText; //text that dispalys to explain the enemy
	sf::Text m_continueText; //tells the player what button to push to continue
	sf::Text m_controlsText; //text that informs the player of what the controls are

	//colour of the text
	sf::Color m_textColour = sf::Color::Yellow; //used to control the colour of all text objects

	bool m_exitGame; // control exiting game

};

#endif // !GAME

