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
	body.setPosition(400, 300);
}

/// <summary>
/// function that moves the player
/// </summary>
void PlayerSpaceShip::move()
{
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
		std::cout << getPosition().x << " , " << getPosition().y << std::endl;
		lookDirection = velocity;
	}
	body.move(velocity);
	changeDirection();
	velocity = sf::Vector2f(0, 0);
}

/// <summary>
/// function used to initialize the player space ship
/// </summary>
void PlayerSpaceShip::init()
{
	lives = 2; // gives the player two lives to start off
	health = 100; //the player starts with 100 health 
	speed = 5; //default speed of the player
}

/// <summary>
/// function that gets the player to respawn when killed
/// </summary>
void PlayerSpaceShip::respawn()
{
}

void PlayerSpaceShip::checkPosition()
{
	if (getPosition().x < -600 || getPosition().x > 1400 || getPosition().y < -700 || getPosition().y > 1300)
	{
		body.setPosition(400, 300);
	}
}

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