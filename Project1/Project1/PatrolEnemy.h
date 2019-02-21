#pragma once
//Aaron O Neill
//basic enemy that patrols 

#include <iostream>
#include <SFML/Graphics.hpp>
#include "MyVector2.h"
#include "Globals.h"
#include <cstdlib>
#include <time.h>
#include <math.h>


class PatrolEnemy
{
public:
	PatrolEnemy();

	//all the set and get functions
	sf::Sprite getBody() { return m_body; }
	sf::Vector2f getVelocity() { return m_velocity; }
	void setVelocity(sf::Vector2f t_velocity);

	// main functions
	void loadSprite(); //function to load the sprite
	void init(); //function to initalise the player
	void move(); //function for the enemy to move
	void respawn(); //function for when the enemy is killed
	void checkPosition(); //function that checks to make sure the enemy doesnt go off the boundaries of the screen
	void changeDirection(); //function that changes the orientation of the enemy

private:
	sf::Texture m_bodyTexture; //body texture
	sf::Sprite m_body; //sprite that uses the texture
	sf::Vector2f m_velocity; //speed at which the sprite moves
	sf::Vector2f m_lookDirection;

	float health;
	float speed;
	float angle;

	bool m_alive{ true }; //used to detect if the player was killed or not


};

