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
	void loadImage();
	void move();
	void changeDirection();
	void init();
	void respawn();
	void checkPosition();

	sf::RectangleShape playerHitBox1; //used as a hit box for the player 
	sf::RectangleShape playerHitBox2; 

private:
	sf::Texture bodyTexture; //body texture
	sf::Sprite body; //sprite that uses the texture
	sf::Vector2f velocity; //speed at which the sprite moves
	sf::Vector2f lookDirection; //direction the spaceship is facing

	float lives; //number of lives that the player has
	float speed; //speed that the player can move at 
	float health; //health that the player has
	bool alive{ true }; //used to detect if the player was killed or not

};

