/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"

class GravBody {
public:
	sf::Vector2f getPosition();
	sf::Vector2f getDelta();
	float getMass();

	void setDelta(sf::Vector2f & delta);
	void setPosition(sf::Vector2f & position);
protected:
	GravBody(sf::Vector2f position, sf::Vector2f initialDelta, float mass);

	sf::Vector2f _position;
	sf::Vector2f _delta;
	float _mass;
};
