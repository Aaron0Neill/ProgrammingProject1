//Aaron O Neill 
//bullet class

#pragma once

#include <SFML/Graphics.hpp>
#include "Globals.h"
#include <iostream>

class Bullet
{
public:
	Bullet();

	void move(); //function to make the bullet move
	void checkPos(); //function to check the position of the bullet
	void init(sf::Vector2f t_pos, sf::Vector2f t_velocity); //function to initialize the body
	inline sf::RectangleShape getBody() { return m_body; }
	void despawn(); //function to kill a bullet

private:

	sf::RectangleShape m_body; //temp body
	sf::Texture m_bulletTexture; // texture of the bullet
	sf::Sprite m_bullet; //sprite for the bullet
	sf::Vector2f m_velocity; //speed at which the bullet moves
};

