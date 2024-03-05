#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Pickup
{
private:
	// Start value for health pickups
	const int HEALTH_START_VALUE = 50;
	const int AMMO_START_VALUE = 12;
	const int START_WAIT_TIME = 10;
	const int START_SECONDS_TO_LIVE = 5;

	// THe sprite that represents this pickup
	Sprite m_Sprite;

	// THe arena that it exists in 
	IntRect m_Arena;

	// How much is this pickup worth
	int m_Value;

	// WHat type of pickup 1 = health 2 = ammo
	int m_Type;

	// handle spawning and disappearing
	bool m_Spawned;
	float m_SecondsSinceSpawn;
	float m_SecondsSinceDeSpawn;
	float m_SecondsToLive;
	float m_SecondsToWait;

public:
	Pickup(int type);
	void setArena(IntRect arena);
	void spawn();
	FloatRect getPosition();
	Sprite getSprite();
	void update(float elapsedTime);
	bool isSpawned();
	int gotIt();
	void upgrade();
};