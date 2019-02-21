#include "Bullet.h"



Bullet::Bullet()
{
	m_body.setFillColor(sf::Color::Yellow);
	m_body.setSize(sf::Vector2f{ 20,20 });
	m_body.setPosition(2000, 0);
}

/// <summary>
/// function to move the bullet when it is on the screen
/// </summary>
void Bullet::move()
{
	if (waitToFire > 0)
	{
		waitToFire--;
	}
	if(m_body.getPosition().x != 2000)
	{
//		m_bullet.move(m_velocity);
		m_body.move(m_velocity);
	}
}

/// <summary>
/// function to check if the bullet has gone off the screen
/// </summary>
void Bullet::checkPos()
{
	if (m_body.getPosition().x != 2000)
	{
		sf::Vector2f pos = m_body.getPosition();
		if (pos.x < -10 || pos.x > SCREEN_WIDTH + 10 || pos.y < -10 || pos.y > SCREEN_HEIGHT + 10)
		{
			m_body.setPosition(2000, 0);
			aliveBullets--;
		}
	}
}

/// <summary>
/// function used to initalize the bullets
/// </summary>
/// <param name="t_pos">position of the boject that fired it</param>
/// <param name="t_lookDirection"> direction said object is moving</param>
void Bullet::init(sf::Vector2f t_pos, sf::Vector2f t_lookDirection)
{
	if (aliveBullets <= TOTAL_BULLETS)
	{
		if (waitToFire <= 0)
		{
			if (m_body.getPosition().x == 2000)
			{
				m_body.setPosition(t_pos);
				m_velocity.x = t_lookDirection.x * 2;
				m_velocity.y = t_lookDirection.y * 2;
				aliveBullets++;
				waitToFire = 60;
			}
		}
	}
}

/// <summary>
/// function used to despawn the bullets after they collide with something
/// </summary>
void Bullet::despawn()
{
	m_velocity = sf::Vector2f{ 0,0 };
	m_body.setPosition(2000, 0);
	aliveBullets--;
}