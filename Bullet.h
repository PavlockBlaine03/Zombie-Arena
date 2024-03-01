#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Bullet
{
private:
	// Where is the bullet
	Vector2f m_Position;
	
	// What each bullet looks like
	RectangleShape m_BulletShape;

	// Is bullet currently going through the air
	bool m_InFlight = false;

	// How fast does the bullet travel
	float m_BulletSpeed = 1000;

	// What fraction of 1 pixel does the bullet travel
	float m_BulletDistanceX;
	float m_BulletDistanceY;

	// Some boudaries so bullet does not fly forever
	float m_MaxX;
	float m_MinX;
	float m_MaxY;
	float m_MinY;
public:
	// The constructor
	Bullet();
	// Stop the bullet
	void stop();
	// returns value of m_InFlight
	bool isInFLight();
	// Launch new bullet
	void shoot(float startX, float startY, float xTarget, float yTarget);
	// Tell calling code where bullet is in world
	FloatRect getPosition();
	// return actual shape for drawing
	RectangleShape getShape();
	// update bullet each frame
	void update(float elapsedTime);
};