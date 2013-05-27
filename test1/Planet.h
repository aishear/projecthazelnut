#pragma once
#include "stdafx.h"
#include "GravBody.h"
#include "IDrawable.h"
#include "GameObject.h"

class Planet : public GameObject {
public:
	Planet(sf::Vector2f position, sf::Vector2f initialDelta, float mass, sf::Sprite& sprite, float radius);
private:
	float _radius;
};