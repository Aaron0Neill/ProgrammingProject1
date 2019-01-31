//author: Aaron O Neill

#include <SFML/Graphics.hpp>
#include <iostream>

#pragma once
class Asteroid
{
public:
	Asteroid();
	void loadImage();
	void init();
	void move();
	inline sf::RectangleShape getBody() { return testBody; }


private:

	sf::Texture asteroidTexture;
	sf::Sprite asteroid;
	sf::RectangleShape testBody;
	sf::Vector2f velocity;
	sf::Vector2f position;

	bool alive{ true };
};

