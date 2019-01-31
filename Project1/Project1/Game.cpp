// author Aaron O Neill

#include "Game.h"
#include <iostream>




Game::Game() :
	m_window{ sf::VideoMode{ 800, 600, 32 }, "SFML Game" },
	m_exitGame{ false }, //when true game will exit
	m_gameState{ splashScreen } //sets the game to default to the splash screen
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
		if (m_gameState == splashScreen)
		{
			if (sf::Event::KeyPressed == event.type)
			{
				m_gameState = inGame;
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
	m_playerShield.update(m_player.getPosition()); //calls the function to update the shield
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear();
	if (m_gameState == splashScreen)
	{
		m_window.draw(m_title);
	}
	m_window.setView(m_playerView);
	m_window.draw(m_player.getBody());
	m_window.draw(m_playerShield.getBody());
	m_window.draw(m_enemy.getBody());

	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_titleFont.loadFromFile("assets//fonts//Starjhol.ttf") && m_mainFont.loadFromFile("assets//fonts//Starjedi.ttf"))
	{
		std::cout << "font failure\n";
	}
	m_title.setFont(m_titleFont); //gives the title its font
	m_title.setCharacterSize(28); //sets the size of the text
	m_title.setString("\t\t  Space Survival\nPress any button to continue");
	m_title.setOrigin(m_title.getGlobalBounds().width / 2, m_title.getGlobalBounds().height / 2); //sets the origin of the text to the middle
	m_title.setPosition(400, 100); //sets the position to slightly above the middle of the screen

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	
}
