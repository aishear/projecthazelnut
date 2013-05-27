#pragma once
#include "stdafx.h"
#include "Planet.h"
#include "GravBody.h"

Planet::Planet(sf::Vector2f position, sf::Vector2f initialDelta, float mass, sf::Sprite& sprite, float radius) 
	: GameObject(position, initialDelta, mass, sprite), _radius(radius)
{

}
