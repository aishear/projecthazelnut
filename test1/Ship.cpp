#pragma once
#include "stdafx.h"
#include "Ship.h"
#include "GravBody.h"
#include "Game.h"

Ship::Ship(sf::Vector2f position, sf::Vector2f initialDelta, float mass, sf::Sprite& sprite, float radius) 
	: GameObject(position, initialDelta, mass, sprite), _radius(radius)
{
	auto textureSize = _sprite.getTexture()->getSize();
	_sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
	auto size = (radius*2)/_sprite.getTexture()->getSize().x;
	_sprite.setScale(size, size);

	_hull = 100;
	_shield = 100;
}

bool Ship::impactBy(float damage, GameObject* other) {
	return (_hull <= 0);
}

void Ship::increaseSize(GameObject* other) {

}