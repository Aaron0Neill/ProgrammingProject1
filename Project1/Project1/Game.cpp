// author Aaron O Neill

#include "Game.h"
#include <iostream>




Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "SFML Game" },
	m_exitGame{ false }, //when true game will exit
	m_currentState{ Splash } //sets the game to default to the splash screen
{
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	m_playerView.setSize(sf::Vector2f{ 800,600 }); //sets the size of the camera
}


Game::~Game()
{
}


void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if ( sf::Event::Closed == event.type) // window message
		{
			m_window.close();
		}
		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code)
			{
				m_exitGame = true;
			}
		}
		if (m_currentState == Splash)
		{
			if (sf::Event::KeyPressed == event.type)
			{
				if (sf::Keyboard::Space == event.key.code)
				{
					m_currentState = GamePlay;
				}
			}
		}
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
	
	m_playerView.setCenter(m_player.getPosition()); //sets the center of the camer to the players position
	m_playerView.move(m_player.getVelocity()); //moves the window
	m_player.move(); //calls the function to move the player
	m_player.checkPosition(); //checks to make sure the player isnt gone too far
	m_playerShield.update(m_player.getPosition()); //calls the function to update the shield
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear();
	m_window.draw(m_background); //draws the background
	if (m_currentState == Splash) //checks what state the game is in
	{
		m_window.draw(m_title); //displays the title
		m_window.draw(m_asteroidText); //displays the informational text
		m_window.draw(m_continueText); //displays the text saying what button to push
	}
	m_window.setView(m_playerView); //sets the view to be the player
	m_window.draw(m_playerShield.getBody()); //draws the shield object
	m_window.draw(m_player.getBody()); //draws the player object
	m_window.draw(m_asteroid.getBody()); //draws the asteroid object

	m_window.display();
}



/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	//main title screen
	/**************************************************************************************************************************************/
	if (!m_titleFont.loadFromFile("assets//fonts//Starjhol.ttf")) //loads fonts
	{
		std::cout << "title font failure";
	}
	if (!m_mainFont.loadFromFile("assets//fonts//Starjedi.ttf"))
	{
		std::cout << "main font failure";
	}
	m_title.setFont(m_titleFont); //gives the title its font
	m_title.setCharacterSize(28); //sets the size of the text
	m_title.setString("Space Survival"); //sets the string for the splash screen
	m_title.setOrigin(m_title.getGlobalBounds().width / 2, m_title.getGlobalBounds().height / 2); //sets the origin of the text to the middle
	m_title.setPosition(400, 100); //sets the position to slightly above the middle of the screen
	m_title.setFillColor(sf::Color::Yellow);

	//continue text
	/**************************************************************************************************************************************/
	m_continueText.setFont(m_mainFont);
	m_continueText.setCharacterSize(20);
	m_continueText.setString("Press Space to continue");
	m_continueText.setOrigin(m_continueText.getGlobalBounds().width / 2, m_continueText.getGlobalBounds().height / 2);
	m_continueText.setPosition(400, 500);
	m_continueText.setFillColor(sf::Color::Yellow);

	//instructional asteroid text
	/**************************************************************************************************************************************/

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	//background
/*************************************************************************************************************************************/
	if (!m_backgroundTexture.loadFromFile("assets//textures//spacelarge.png")) //loads the background texture
	{
		std::cout << "error loading space backgroud";
	}
	m_background.setTexture(m_backgroundTexture); //gives the sprite the texture
	m_background.setOrigin(m_background.getGlobalBounds().width / 2 , m_background.getGlobalBounds().height / 2); //sets the origin to the middle of the sprite
	m_background.setPosition(m_player.getPosition()); //sets the middle of the background to the players position

}


