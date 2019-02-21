// author Aaron O Neill

#include "Game.h"
#include <iostream>




Game::Game() :
	m_window{ sf::VideoMode{ 1000, 800, 32 }, "SFML Game" },
	m_exitGame{ false }, //when true game will exit
	m_currentState{ GameState::splashScreen } //sets the game to default to the splash screen
{
	setupFontAndText(); // load font 
	setupSprite(); // load texture
	m_playerView.setSize(sf::Vector2f{ 1000,800 }); //sets the size of the camera
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
			render(); // as many as possible
		}
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
		if (m_currentState == GameState::splashScreen)
		{
			if (sf::Event::KeyPressed == event.type)
			{
				if (sf::Keyboard::Space == event.key.code)
				{
					m_currentState = GameState::gamePlay;
					for (int i = 0; i < TOTAL_ASTEROIDS; i++)
					{
						m_asteroids[i].init();
					}
					m_patrolEnemy.init();
				}
			}
		}
		else
		{
			if (sf::Event::KeyPressed == event.type)
			{
				if (sf::Keyboard::Space == event.key.code)
				{
					for (int i = 0; i < TOTAL_BULLETS; i++)
					{
 						m_playerBullets[i].init(m_player.getPosition(), m_player.getDirection());
 					}
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
	if (m_currentState == GameState::gamePlay)
	{
		m_playerView.setCenter(m_player.getPosition()); //sets the center of the camer to the players position
		m_playerView.move(m_player.getVelocity()); //moves the window
		m_player.move(); //calls the function to move the playera
		m_player.checkPosition(); //checks to make sure the player isnt gone too far
		m_patrolEnemy.move(); //moves the enemy object
		m_patrolEnemy.checkPosition(); //makes sure the enemy doesnt move off the screen
		for (int i = 0; i < TOTAL_ASTEROIDS; i++)
		{
			m_asteroids[i].move(); //move the asteroid
			m_asteroids[i].checkPosition(); //reset the asteroid if it leaves the screen
		}
		for (int i = 0; i < TOTAL_BULLETS; i++)
		{
			m_playerBullets[i].move(); //moves the bullets 
			m_playerBullets[i].checkPos(); //checks if the bullets leave the screen
		}
		collisionDetection(); //checks if any objects collide
	}
	m_playerShield.update(m_player.getPosition()); //calls the function to update the shield
}

/// <summary>
/// draw the frame and then switch bufers
/// </summary>
void Game::render()
{
	m_window.clear();
	m_window.draw(m_background); //draws the background
	if (m_currentState == GameState::splashScreen) //checks what state the game is in
	{
		m_window.draw(m_title); //displays the title
		m_window.draw(m_asteroidText); //displays the informational text
		m_window.draw(m_continueText); //displays the text saying what button to push
		m_window.draw(m_controls); //displays the keys used to move
		m_window.draw(m_controlsText); //displays the text to explain the controls
		m_window.draw(m_enemyText); //displays the information on the enemy
	}
//	m_window.setView(m_playerView); //sets the view to be the player
	for (int i = 0; i < TOTAL_ASTEROIDS; i++)
	{
		m_window.draw(m_asteroids[i].getBody()); //draws the asteroid object
	}
	for (int i = 0; i < TOTAL_BULLETS; i++)
	{
		m_window.draw(m_playerBullets[i].getBody());
	}
	m_window.draw(m_patrolEnemy.getBody()); //draws the enemy object
	m_window.draw(m_playerShield.getBody()); //draws the shield object
	m_window.draw(m_player.getBody()); //draws the player object

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
	m_title.setCharacterSize(32); //sets the size of the text
	m_title.setString("Space Survival"); //sets the string for the splash screen
	m_title.setOrigin(m_title.getGlobalBounds().width / 2, m_title.getGlobalBounds().height / 2); //sets the origin of the text to the middle
	m_title.setPosition(SCREEN_WIDTH / 2.0, 100); //sets the position to slightly above the middle of the screen
	m_title.setFillColor(m_textColour);

	//continue text
	/**************************************************************************************************************************************/
	m_continueText.setFont(m_mainFont);
	m_continueText.setCharacterSize(24);
	m_continueText.setString("Press Space to continue");
	m_continueText.setOrigin(m_continueText.getGlobalBounds().width / 2, m_continueText.getGlobalBounds().height / 2);
	m_continueText.setPosition(SCREEN_WIDTH /2.0, SCREEN_HEIGHT -200);
	m_continueText.setFillColor(m_textColour);

	//instructional asteroid text
	/**************************************************************************************************************************************/
	m_asteroidText.setFont(m_mainFont);
	m_asteroidText.setCharacterSize(14);
	m_asteroidText.setString("These are asteroids \nthat float through space \nThey will cause damage \nif you collide with them");
	m_asteroidText.setOrigin(m_asteroidText.getGlobalBounds().width / 2.0, m_asteroidText.getGlobalBounds().height / 2.0);
	m_asteroidText.setPosition(SCREEN_WIDTH - 125,250);
	m_asteroidText.setFillColor(m_textColour);

	//controls text
	/**************************************************************************************************************************************/
	m_controlsText.setFont(m_mainFont);
	m_controlsText.setCharacterSize(14);
	m_controlsText.setString("These are the keys\nyou use to move\nup, down, left and right\nuse the spacebar to fire");
	m_controlsText.setOrigin(m_controlsText.getGlobalBounds().width / 2.0, m_controlsText.getGlobalBounds().height / 2.0);
	m_controlsText.setPosition(SCREEN_WIDTH - 125,SCREEN_HEIGHT / 2.0 + 50);
	m_controlsText.setFillColor(m_textColour);

	//enemy text
	m_enemyText.setFont(m_mainFont);
	m_enemyText.setCharacterSize(14);
	m_enemyText.setString("These are enemies\nthat randomly move\naround the screen and will\nshoot at you if you get\ntoo close");
	m_enemyText.setOrigin(m_enemyText.getGlobalBounds().width / 2.0, m_enemyText.getGlobalBounds().height / 2.0);
	m_enemyText.setPosition((m_enemyText.getGlobalBounds().width / 2.0) + 50, 350);
	m_enemyText.setFillColor(m_textColour);


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

	if (!m_controlsTexture.loadFromFile("assets//textures//WASDKeys.png"))
	{
		std::cout << "Error loading controls";
	}
	m_controls.setTexture(m_controlsTexture);
	m_controls.setOrigin(m_controls.getGlobalBounds().width / 2.0, m_controls.getGlobalBounds().height / 2.0);
	m_controls.setPosition(SCREEN_WIDTH - 150, 350);
	
	onScreenArea.setSize(sf::Vector2f{ m_window.getSize() });

}

void Game::collisionDetection()
{
	for (int i = 0; i < TOTAL_ASTEROIDS; i++)
	{
		for (int j = 0; j < TOTAL_BULLETS; j++)
		{
			if (m_playerBullets[j].getBody().getGlobalBounds().intersects(m_asteroids[i].getBody().getGlobalBounds()))
			{
				m_asteroids[i].init();
				m_playerBullets[j].despawn();
			}
		}
	}
}


