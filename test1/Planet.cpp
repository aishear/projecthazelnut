#pragma once
#include "stdafx.h"
#include "Planet.h"
#include "GravBody.h"
#include "Game.h"

Planet::Planet(sf::Vector2f position, sf::Vector2f initialDelta, float mass, sf::Sprite& sprite, float radius) 
	: GameObject(position, initialDelta, mass, sprite), _radius(radius)
{
	auto textureSize = _sprite.getTexture()->getSize();
	_sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
	auto size = (radius*2)/_sprite.getTexture()->getSize().x;
	_sprite.setScale(size, size);
}

bool Planet::impact(float damage, GameObject & other) {
	return false;
}

void Planet::changeSize(GameObject & other) {

}