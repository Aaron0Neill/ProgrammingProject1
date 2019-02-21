//author: Aaron O Neill

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Globals.h"

#pragma once
class Asteroid
{
public:
	Asteroid();
	void setupSplash();
	void init();
	void move();
	void checkPosition();
	inline sf::Sprite getBody() { return asteroid; }
	inline sf::Vector2f getPosition() { return asteroid.getPosition(); }


private:

	sf::Texture asteroidTexture; //texture of the asteroid
	sf::Sprite asteroid; //sprite to display the texture
	sf::Vector2f velocity; //speed at which the asteroid moves
	float speed; //speed that the asteroid moves at
	float health; // health of the asteroid
	float rotation; //asteroid will rotate around the screen
	int spawnSide; //which side the asteroid will spawn at

};

