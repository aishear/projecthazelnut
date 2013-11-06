/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */


#pragma once
#include "stdafx.h"
#include "Bullet.h"
#include "GameObject.h"

class GameObjectFactory {
public:
	static Bullet* createBullet(sf::Vector2f position, sf::Vector2f initialDelta, float mass, float radius);

};
