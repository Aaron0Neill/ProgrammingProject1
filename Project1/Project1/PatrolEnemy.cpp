#include "PatrolEnemy.h"



PatrolEnemy::PatrolEnemy()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	loadSprite();
	init(); //initalizes the enemy
}

void PatrolEnemy::setVelocity(sf::Vector2f t_velocity)
{
	m_velocity = t_velocity; // allows manual changing of the velocity
}

void PatrolEnemy::loadSprite()
{
	if (!m_bodyTexture.loadFromFile("assets//textures//patrolenemy.png"))
	{
		std::cout << "error loading patrol enemy";
	}
	m_body.setTexture(m_bodyTexture);
	m_body.setOrigin(m_body.getGlobalBounds().width / 2.0, m_body.getGlobalBounds().height / 2.0);
	m_body.setPosition(175, 250);
}

void PatrolEnemy::init()
{
	health = 100;
	speed = 5;
	m_velocity.x = rand() % 11 - 5;
	m_velocity.y = rand() % 11 - 5;
}

void PatrolEnemy::move()
{
	m_body.move(m_velocity);
	if (vectorLength(m_velocity) != 0)
	{
		m_lookDirection = m_velocity;
		changeDirection();
	}
}

void PatrolEnemy::respawn()
{
	init();
}

void PatrolEnemy::changeDirection()
{
	angle = (atan2(m_velocity.y, m_velocity.x))* (180 / 3.1415926);
	std::cout << angle;
}

