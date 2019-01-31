#include "PatrolEnemy.h"



PatrolEnemy::PatrolEnemy()
{
	init(); //initalizes the enemy
}

void PatrolEnemy::setVelocity(sf::Vector2f t_velocity)
{
	velocity = t_velocity; // allows manual changing of the velocity
}

void PatrolEnemy::init()
{
}

void PatrolEnemy::move()
{
}

void PatrolEnemy::respawn()
{
}

