#include "PatrolEnemy.h"



PatrolEnemy::PatrolEnemy()
{
	srand(static_cast<unsigned int>(time(nullptr))); //sets the seed for random numbers
	loadSprite(); //calls the function to load the sprite
	init(); //initalizes the enemy
}

/// <summary>
/// function that allows you to manually set the velocity
/// </summary>
/// <param name="t_velocity"></param>
void PatrolEnemy::setVelocity(sf::Vector2f t_velocity)
{
	m_velocity = t_velocity; // allows manual changing of the velocity
}

/// <summary>
/// function used to load in the texture for the sprite and setup all the attributes for the sprite
/// </summary>
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

/// <summary>
/// initializes all the variables in the object
/// </summary>
void PatrolEnemy::init()
{
	health = 100;
	speed = 5;
	m_velocity.x = rand() % 11 - 5; //random number between -5-5
	m_velocity.y = rand() % 11 - 5;

}

/// <summary>
/// function that moves the spaceship
/// </summary>
void PatrolEnemy::move()
{
	m_body.move(m_velocity); //moves the body by the velocity
	if (vectorLength(m_velocity) != 0) //checks to make sure the player spaceship is moving
	{
//		m_lookDirection = m_velocity;
		changeDirection(); //changes the orientation of the ship when it is moving
	}
}

/// <summary>
/// function used for when the enemy dies
/// </summary>
void PatrolEnemy::respawn()
{
	init();
}

/// <summary>
/// function that checks to make sure the ship doesnt go off the boundaries of the screen
/// </summary>
void PatrolEnemy::checkPosition()
{
	if (m_body.getPosition().x < 50) //check to see if the body has hit the left hand side
	{
		m_velocity.x = rand() % 5 + 1; //move it right at a random speed
	}
	else if (m_body.getPosition().x > SCREEN_WIDTH - 50) //check if the body is gone off the right side
	{
		m_velocity.x = rand() % 5 - 5; //move it left at a random speed
	}
	if (m_body.getPosition().y < 50) //check to see if the ship hits the top of the screen
	{
		m_velocity.y = rand() % 5 + 1; //moves the ship down at a random speed
	}
	else if (m_body.getPosition().y > SCREEN_HEIGHT - 50) //checks to see if the body hits the bottom of the screen
	{
		m_velocity.y = rand() % 5 - 5; //moves the ship up at a random speed
	}
}

/// <summary>
/// function to change what direction the ship is facing
/// </summary>
void PatrolEnemy::changeDirection()
{
	angle = (atan2(m_velocity.y, m_velocity.x))* (180 / 3.1415926); //gets the angle of the velocity 
	angle += 90; //adds 90 to get the orientation correct for the ship
	m_body.setRotation(angle); //sets the rotation of the ship to be the direction of the ship
	
}

// up is -90
// down is 90
// right is 0
// left is 180

