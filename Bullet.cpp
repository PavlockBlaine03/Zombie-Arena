#include "Bullet.h"

Bullet::Bullet()
{
	m_BulletShape.setSize(sf::Vector2f(2, 2));
}
void Bullet::shoot(float startX, float startY, float targetX, float targetY)
{
	m_InFlight = true;
	m_Position.x = startX;
	m_Position.y = startY;
	float gradient = (startX - targetX) / (startY - targetY);
	// Any gradient less than 1 needs to be negitive
	if (gradient < 0)
	{
		gradient *= -1;
	}
	float ratioXY = m_BulletSpeed / (1 + gradient);

	// set speed horizontally and vertically
	m_BulletDistanceY = ratioXY;
	m_BulletDistanceX = ratioXY * gradient;

	// Point bullet in right direction
	if (targetX < startX)
	{
		m_BulletDistanceX *= -1;
	}
	if (targetY < startY)
	{
		m_BulletDistanceY *= -1;
	}

	// Set max range of 1000 pixels
	float range = 1000;
	m_MinX = startX - range;
	m_MaxX = startX + range;
	m_MinY = startY - range;
	m_MaxY = startY + range;

	// position bullet ready to be drawn
	m_BulletShape.setPosition(m_Position);
}
void Bullet::stop()
{
	m_InFlight = false;
}
bool Bullet::isInFLight()
{
	return m_InFlight;
}
FloatRect Bullet::getPosition()
{
	return m_BulletShape.getGlobalBounds();
}
RectangleShape Bullet::getShape()
{
	return m_BulletShape;
}
void Bullet::update(float elapsedTime)
{
	// Update bullet position
	m_Position.x += m_BulletDistanceX * elapsedTime;
	m_Position.y += m_BulletDistanceY * elapsedTime;

	// move bullet
	m_BulletShape.setPosition(m_Position);

	// has bullet gone out of range
	if (m_Position.x < m_MinX || m_Position.x > m_MaxX || m_Position.y < m_MinY || m_Position.y > m_MaxY)
	{
		m_InFlight = false;
	}
}
