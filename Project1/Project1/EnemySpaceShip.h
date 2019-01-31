//Author: Aaron O Neill

#include <SFML/Graphics.hpp>

#pragma once
class EnemySpaceShip
{
public:
	EnemySpaceShip();
	EnemySpaceShip(sf::Vector2f t_position);
	//all the set and get functions
	sf::RectangleShape getBody() { return tempBody; }
	sf::Vector2f getVelocity() { return velocity; }
	void setVelocity(sf::Vector2f t_velocity);

	// main functions
	void init(); //function to initalise the player
	void move(); //function for the enemy to move
	void respawn(); //function for when the enemy is killed

private:
	sf::Texture bodyTexture; //body texture
	sf::Sprite body; //sprite that uses the texture
	sf::RectangleShape tempBody;
	sf::Vector2f velocity; //speed at which the sprite moves
	sf::Vector2f position; //position that the body is currently at
	bool alive{ true }; //used to detect if the player was killed or not


};

