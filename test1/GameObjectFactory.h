
#pragma once
#include "stdafx.h"
#include "Bullet.h"
#include "GameObject.h"

class GameObjectFactory {
public:
	static Bullet* createBullet(sf::Vector2f position, sf::Vector2f initialDelta, float mass, float radius);

};