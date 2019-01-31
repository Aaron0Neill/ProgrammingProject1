#include "Shield.h"



Shield::Shield()
{
	init();
}

void Shield::init()
{
	if (!shieldTexture.loadFromFile("assets//textures//shield.png"))
	{
		std::cout << "error loading shield png";
	}
	shield.setTexture(shieldTexture);
	shield.setOrigin(shield.getGlobalBounds().width / 2, shield.getGlobalBounds().height / 2);
//	shield.scale(0.7f, 0.7f);
}

void Shield::update(sf::Vector2f t_pos)
{
	if (health > 0)
	{
		if (angle <= 360)
		{
			xPos = t_pos.x + cos(angle);
			yPos = t_pos.y + 10 + sin(angle);
			angle++;
		}
		else
		{
			angle = 0;
		}
		shield.setPosition(xPos, yPos);
		
	}
}

void Shield::respawn()
{
	health = 100;
}

