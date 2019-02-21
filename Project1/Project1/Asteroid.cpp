#include "Asteroid.h"



Asteroid::Asteroid()
{
	setupSplash();
}

void Asteroid::init()
{
	health = 100; //sets the health of the asteroid
	speed = 3; //set the speed of the asteroid
	spawnSide = rand() % 4 + 1;
	if (spawnSide == TOP)
	{
		asteroid.setPosition(rand() % SCREEN_WIDTH + 1, -asteroid.getGlobalBounds().height / 2.0); //sets it above the screen
	}
	else if (spawnSide == BOTTOM)
	{
		asteroid.setPosition(rand() % SCREEN_WIDTH + 1, SCREEN_HEIGHT + asteroid.getGlobalBounds().height / 2.0); //bottom of the screen
	}
	else if (spawnSide == LEFT)
	{
		asteroid.setPosition(-asteroid.getGlobalBounds().width / 2.0, rand() % SCREEN_HEIGHT + 1); //left side of the screen
	}
	else if (spawnSide == RIGHT)
	{
		asteroid.setPosition(SCREEN_WIDTH + asteroid.getGlobalBounds().width / 2.0, rand() % SCREEN_HEIGHT + 1); //right side of the screen
	}
}

void Asteroid::move()
{
	if (spawnSide == TOP)
	{//make the asteroid move down faster than anything
		velocity.x = rand() % 3 + 1;
		velocity.y = rand() % 3 + 3;
	}
	else if (spawnSide == BOTTOM)
	{//make the asteroid move up
		velocity.x = rand() % 3 + 1;
		velocity.y = rand() % 3 - 4;
	}
	else if (spawnSide == RIGHT)
	{//make the asteroid move left
		velocity.x = rand() % 3 - 4;
		velocity.y = rand() % 3 + 1;
	}
	else if (spawnSide == LEFT)
	{//make the asteroid move right
		velocity.x = rand() % 3 + 3;
		velocity.y = rand() % 3 + 1;
	}
	asteroid.move(velocity);
}

void Asteroid::checkPosition()
{
	if (asteroid.getPosition().x < -asteroid.getGlobalBounds().width  || asteroid.getPosition().x > SCREEN_WIDTH + asteroid.getGlobalBounds().width )
	{
		init();
	}
	if (asteroid.getPosition().y < -asteroid.getGlobalBounds().height || asteroid.getPosition().y > SCREEN_HEIGHT + asteroid.getGlobalBounds().height)
	{
		init();
	}
}

void Asteroid::setupSplash()
{
	if (!asteroidTexture.loadFromFile("assets//textures//asteroid.png")) //load the texuture
	{
		std::cout << "error with asteroid texture";
	}
	asteroid.setTexture(asteroidTexture); //sets the texture of the asteroid
	asteroid.setOrigin(asteroid.getGlobalBounds().width / 2, asteroid.getGlobalBounds().height / 2); //sets the origin to the middle of the sprite
	asteroid.setPosition(SCREEN_WIDTH - 125, 125); //sets the asteroids position
}
