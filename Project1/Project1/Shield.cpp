#include "Shield.h"



Shield::Shield()
{
	init();
}

void Shield::init()
{
	if (!shieldTexture.loadFromFile("assets//textures//shield.png")) //loads the shield sprite 
	{
		std::cout << "error loading shield png"; //displays error message if the texture wasnt loaded
	}
	shield.setTexture(shieldTexture); //assigns the texture
	shield.setOrigin(shield.getGlobalBounds().width / 2, shield.getGlobalBounds().height / 2); //sets the origin to the middle of the shield
	shield.setColor(sf::Color(255, 255, 255, health)); //gives it a colour with a variable for the oppacity
}

void Shield::update(sf::Vector2f t_pos)
{
	if (health > 0) //checks to make sure the shield still has health
	{
		shield.setColor(sf::Color(255, 255, 255, health)); //changes how clear the players shield is 
		if (angle <= 360) // checks to see if the angle is above 360, used to make sure the angle does go over the limit
		{
			//used to shake the the ship
			xPos = t_pos.x + cos(angle);
			yPos = t_pos.y + 10 + sin(angle);
			angle++;
		}
		else //reset the angle if it goes full circle
		{
			angle = 0;
		}
		shield.setPosition(xPos, yPos); //updates the shield position
	}
}

void Shield::respawn()
{
}

