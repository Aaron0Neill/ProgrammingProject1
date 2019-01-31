//Aaron O Neill
#pragma once

//spaceship shield class
#include <SFML/Graphics.hpp>
#include <iostream>

class Shield
{
public:
	Shield();

	void init();
	void update(sf::Vector2f t_pos);
	void respawn();
	inline sf::Sprite getBody() { return shield; }
	inline float getHealth() { return health; }


private:
	sf::Texture shieldTexture;
	sf::Sprite shield;
	float xPos; //x position of the shield
	float yPos; //y position of the shield
	float angle{ 0 };
	float health{ 255 };
};

