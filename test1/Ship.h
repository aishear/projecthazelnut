#pragma once
#include "stdafx.h"
#include "GravBody.h"
#include "IDrawable.h"
#include "GameObject.h"

class Ship : public GameObject {
public:
	Ship(sf::Vector2f position, sf::Vector2f initialDelta, float mass, sf::Sprite& sprite, float radius);
	virtual bool impactBy(float dameage, GameObject* other);
	virtual void increaseSize(GameObject* other);
	virtual float getRadius();
	virtual void draw(sf::RenderWindow& rw);
	virtual sf::Color getTrailColor();
private:
	float _radius;
	int _hull;
	int _shield;
};