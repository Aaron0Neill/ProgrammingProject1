#include "Bullet.h"



Bullet::Bullet()
{
	for (int i = 0; i < TOTAL_BULLETS; i++)
	{
		m_body[i].setFillColor(sf::Color::Yellow);
		m_body[i].setSize(sf::Vector2f{ 20,20 });
		m_body[i].setPosition(2000, 0);
		m_alive[i] = false;
		m_velocity[i].x = 0;
		m_velocity[i].y = 0;
	}
}

void Bullet::move()
{
	if (waitToFire > 0)
	{
		waitToFire--;
	}
	for (int i = 0; i < TOTAL_BULLETS; i++)
	{
		if(m_body[i].getPosition().x != 2000)
		{
// 			m_bullet.move(m_velocity);
			m_body[i].move(m_velocity[i]);
		}
	}
}

void Bullet::checkPos()
{
	for (int i = 0; i < TOTAL_BULLETS; i++)
	{
		if (m_body[i].getPosition().x != 2000)
		{
			sf::Vector2f pos = m_body[i].getPosition();
			if (pos.x < -10 || pos.x > SCREEN_WIDTH + 10 || pos.y < -10 || pos.y > SCREEN_HEIGHT + 10)
			{
				m_body[i].setPosition(2000, 0);
				aliveBullets--;
			}
		}	
	}
}

void Bullet::init(sf::Vector2f t_pos, sf::Vector2f t_lookDirection)
{
	if (waitToFire <= 0 && aliveBullets <= TOTAL_BULLETS)
	{
		for (int i = 0; i < TOTAL_BULLETS; i++)
		{
			if (m_body[i].getPosition().x == 2000)
			{
				m_alive[i] = true;
				m_body[i].setPosition(t_pos);
				m_velocity[i].x = t_lookDirection.x * 2;
				m_velocity[i].y = t_lookDirection.y * 2;
				aliveBullets++;
				waitToFire = 10;
				std::cout << aliveBullets << std::endl;
				break;
			}
		}
	}
}

void Bullet::draw(sf::RenderWindow &m_window)
{
	if (aliveBullets <= TOTAL_BULLETS)
	{
		for (int i = 0; i < TOTAL_BULLETS; i++)
		{
			m_window.draw(m_body[i]);
		}
	}
}

sf::RectangleShape Bullet::getBody()
{
	for (int i = 0; i < TOTAL_BULLETS; i++)
	{
		return m_body[i];
	}
}
