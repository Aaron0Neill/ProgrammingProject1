#include "EnemySpaceShip.h"



EnemySpaceShip::EnemySpaceShip()
{
	init();
}

EnemySpaceShip::EnemySpaceShip(sf::Vector2f t_position)
{
	position = t_position;
}

void EnemySpaceShip::setVelocity(sf::Vector2f t_velocity)
{
	velocity = t_velocity;
}

void EnemySpaceShip::init()
{
	//temp variables
	tempBody.setSize(sf::Vector2f{ 30,30 });
	tempBody.setPosition(100, 20);
	tempBody.setFillColor(sf::Color::Red);
}

void EnemySpaceShip::move()
{
}

void EnemySpaceShip::respawn()
{
}


