/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"
#include "GravBody.h"
#include "IDrawable.h"
#include "SlotMap.h"
#include "ISlotItem.h"

class GameObject : public GravBody, public virtual IDrawable, public virtual ISlotItem {
public:

	GameObject(sf::Vector2f position, sf::Vector2f initialDelta, float mass, sf::Sprite& sprite);
	virtual void draw(sf::RenderWindow& rw);
	virtual void updateSprite();
	virtual void updatePosition(float deltaTime);
	virtual bool impactBy(float damage, GameObject* other);
	virtual void increaseSize(GameObject* other);
	virtual float getDamage();
	void setId(SLOTMAP_ID id);
	void setMass(float mass);
	SLOTMAP_ID getId();
	float getMass();
	virtual float getRadius();
	sf::FloatRect getBound();
	void addTrailPoint();
	std::list<sf::Vector2f> * getTrail();
	virtual sf::Color getTrailColor();

	static const unsigned TRAIL_LENGTH = 40; //must be even since there are 2 verties in a line

protected:
	sf::Sprite _sprite;
	SLOTMAP_ID _id;
	std::list<sf::Vector2f> _trail;

private:
	sf::Vector2f _lastTrailPoint;
	bool _addTrailLine;
};
