/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"
#include "GravBody.h"
#include "IDrawable.h"
#include "GameObject.h"

class Ship : public GameObject {
public:
	Ship(sf::Vector2f position, sf::Vector2f initialDelta, float mass, sf::Sprite& sprite, float radius);
	virtual void updatePosition(float deltaTime);
	virtual bool impactBy(float dameage, GameObject* other);
	virtual void increaseSize(GameObject* other);
	virtual float getRadius();
	virtual void draw(sf::RenderWindow& rw);
	virtual sf::Color getTrailColor();
	void setThrust(float angleRadians, float power);
	void fire(float angleRadians, float power);
private:
	float _radius;
	int _hull;
	int _shield;

	sf::Vector2f _thrustDelta;

};
