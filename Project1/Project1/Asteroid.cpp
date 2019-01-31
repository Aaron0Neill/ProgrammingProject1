#include "Asteroid.h"



Asteroid::Asteroid()
{
	loadImage();
	init();
}

void Asteroid::init()
{
	health = 100; //sets the health of the asteroid
	speed = 3; //set the speed of the asteroid
}

void Asteroid::move()
{
}

void Asteroid::loadImage()
{
	if (!asteroidTexture.loadFromFile("assets//textures//asteroid.png")) //load the texuture
	{
		std::cout << "error with asteroid texture";
	}
	asteroid.setTexture(asteroidTexture); //sets the texture of the asteroid
	asteroid.setOrigin(asteroid.getGlobalBounds().width / 2, asteroid.getGlobalBounds().height / 2); //sets the origin to the middle of the sprite
	asteroid.setPosition(650, 300); //sets the asteroids position
}
