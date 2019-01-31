#include "PlayerSpaceShip.h"


//default constuctor
PlayerSpaceShip::PlayerSpaceShip()
{
	init();
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
		lookDirection = velocity;
	}
//	body.setRotation(angle);
	body.move(velocity);
	changeDirection();
	velocity = sf::Vector2f(0, 0);
}

/// <summary>
/// function used to initialize the player space ship
/// </summary>
void PlayerSpaceShip::init()
{
	if (!bodyTexture.loadFromFile("assets//textures//SpaceShip.png"))
	{
		std::cout << "error loading player space ship";
	}
	lives = 2; // gives the player two lives to start off
	health = 100; //the player starts with 100 health 
	speed = 3; //default speed of 3
	direction = 1; //sets the default direction to North
	body.setTexture(bodyTexture); //setup the sprite
	body.setOrigin(body.getGlobalBounds().width / 2, body.getGlobalBounds().height / 2); //set the origin to the middle
//	body.scale(0.5f, 0.5f);
	body.setPosition(400, 300);
}

/// <summary>
/// function that gets the player to respawn when killed
/// </summary>
void PlayerSpaceShip::respawn()
{
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