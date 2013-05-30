#pragma once
#include "stdafx.h"
#include "GravBody.h"
#include "IDrawable.h"
#include "GameObject.h"

class Ship : public GameObject {
public:
	Ship(sf::Vector2f position, sf::Vector2f initialDelta, float mass, sf::Sprite& sprite, float radius);
	virtual bool impact(float dameage, GameObject & other);
	virtual void increaseSize(GameObject & other);
private:
	float _radius;
	int _hull;
	int _shield;
};