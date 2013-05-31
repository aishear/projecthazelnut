#pragma once
#include "stdafx.h"
#include "Bullet.h"
#include "GravBody.h"
#include "Game.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f initialDelta, float mass, sf::Sprite& sprite, float radius) 
	: GameObject(position, initialDelta, mass, sprite), _radius(radius)
{
	auto textureSize = _sprite.getTexture()->getSize();
	_sprite.setOrigin(textureSize.x / 2, textureSize.y / 2);
	auto size = (radius*2)/_sprite.getTexture()->getSize().x;
	_sprite.setScale(size, size);

}

bool Bullet::impactBy(float damage, GameObject* other) {
	return true;
}

void Bullet::increaseSize(GameObject* other) {

}