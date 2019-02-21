#include "PlayerSpaceShip.h"


//default constuctor
PlayerSpaceShip::PlayerSpaceShip()
{
	loadImage();
	init();
}


void PlayerSpaceShip::loadImage()
{
	if (!bodyTexture.loadFromFile("assets//textures//SpaceShip.png"))
	{
		std::cout << "error loading player space ship";
	}
	body.setTexture(bodyTexture); //setup the sprite
	body.setOrigin(body.getGlobalBounds().width / 2, body.getGlobalBounds().height / 2); //set the origin to the middle
	body.setPosition(SCREEN_WIDTH / 2.0, SCREEN_WIDTH / 2.0);
}

/// <summary>
/// function that moves the player
/// </summary>
void PlayerSpaceShip::move()
{
	velocity = sf::Vector2f(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		velocity.y = -speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		velocity.y = speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		velocity.x = speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		velocity.x = -speed;
	}
	if (vectorLength(velocity) != 0)
	{
		lookDirection = velocity;
	}
	body.move(velocity);
	changeDirection();
}

/// <summary>
/// function used to initialize the player space ship
/// </summary>
void PlayerSpaceShip::init()
{
	lives = 2; // gives the player two lives to start off
	health = 100; //the player starts with 100 health 
	speed = 3; //default speed of the player
}

/// <summary>
/// function that gets the player to respawn when killed
/// </summary>
void PlayerSpaceShip::respawn()
{
}

/// <summary>
/// function to check where the player is on the screen and respond accordingly
/// </summary>
void PlayerSpaceShip::checkPosition()
{
	if (getPosition().x < 0) //if the player goes to the left of the screen
	{
		body.setPosition(SCREEN_WIDTH, getPosition().y); //moves the player to the right of the screen
	}
	else if (getPosition().x > SCREEN_WIDTH) //if the player goes to the right of the screen
	{
		body.setPosition(0, getPosition().y); //sets the player to the left of the screen
	}
	if (getPosition().y < 0) //if the player hits the top of the screen
	{
		body.setPosition(getPosition().x, SCREEN_HEIGHT); //sets the player to the bottom of the screen
	}
	if (getPosition().y > SCREEN_HEIGHT) //if the player hits the bottom of the screen
	{
		body.setPosition(getPosition().x, 0); //sets the player to the top of the screen
	}
	//testing an idea
	/*if (getPosition().x < -600 || getPosition().x > 1400 || getPosition().y < -700 || getPosition().y > 1300)
	{
		body.setPosition(400, 300);
	}*/

}

/// <summary>
/// function to change the orientation of the ship depending on the way it is moving
/// </summary>
void PlayerSpaceShip::changeDirection()
{
	if (lookDirection.x == 0 && lookDirection.y < 0)
	{
		body.setRotation(0);
	}
	else if (lookDirection.x > 0 && lookDirection.y < 0 )
	{
		body.setRotation(45);
	}
	else if (lookDirection.x > 0 && lookDirection.y == 0)
	{
		body.setRotation(90);
	}
	else if (lookDirection.x > 0 && lookDirection.y > 0)
	{
		body.setRotation(135);
	}
	else if (lookDirection.x == 0 && lookDirection.y > 0)
	{
		body.setRotation(180);
	}
	else if (lookDirection.x < 0 && lookDirection.y > 0)
	{
		body.setRotation(225);
	}
	else if (lookDirection.x < 0 && lookDirection.y == 0)
	{
		body.setRotation(270);
	}
	else if (lookDirection.x < 0 && lookDirection.y < 0)
	{
		body.setRotation(315);
	}
}