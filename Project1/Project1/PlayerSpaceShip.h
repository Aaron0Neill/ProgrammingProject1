/// @author: Aaron O Neill
/// 
/// space ship class

#include <SFML/Graphics.hpp>
#include "MyVector2.h"
#include <iostream>

#pragma once
class PlayerSpaceShip
{
public:
	//default constructor
	PlayerSpaceShip();
	//all the set and get functions
	sf::Sprite getBody() { return body; }
	sf::Vector2f getVelocity() { return velocity; }
	sf::Vector2f getPosition() { return body.getPosition(); }


	//all the movement functions
	void move();
	void changeDirection();
	void init();
	void respawn();

private:
	sf::Texture bodyTexture; //body texture
	sf::Sprite body; //sprite that uses the texture
	sf::Vector2f velocity; //speed at which the sprite moves
	sf::Vector2f lookDirection; //direction the spaceship is facing

	float direction;
	float lives;
	float speed;
	float health;
	float angle{ 0 };
	bool alive{ true }; //used to detect if the player was killed or not

};

