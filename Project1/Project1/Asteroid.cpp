#include "Asteroid.h"



Asteroid::Asteroid()
{
	loadImage();
}

void Asteroid::init()
{
}

void Asteroid::move()
{
}

void Asteroid::loadImage()
{
	if (!asteroidTexture.loadFromFile(""))
	{
		std::cout << "Error loading file";
	}
}
