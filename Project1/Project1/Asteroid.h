//author: Aaron O Neill

#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once
class Asteroid
{
public:
	Asteroid();
	void setupSplash();
	void init();
	void move();
	inline sf::Sprite getBody() { return asteroid; }
	inline sf::Vector2f getPosition() { return asteroid.getPosition(); }


private:

	sf::Texture asteroidTexture; //texture of the asteroid
	sf::Sprite asteroid; //sprite to display the texture
	sf::Vector2f velocity; //speed at which the asteroid moves
	float speed; //speed that the asteroid moves at
	float health; // health of the asteroid

	bool alive{ true }; //bool to tell if the asteroid is alive or not
};

