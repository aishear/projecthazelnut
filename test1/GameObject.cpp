#pragma once
#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(sf::Vector2f position, sf::Vector2f initialDelta, float mass, sf::Sprite& sprite) 
	: GravBody(position, initialDelta, mass), _sprite(sprite)
{

}


void GameObject::draw(sf::RenderWindow& rw) {
	rw.draw(_sprite);
}

void GameObject::updateSprite() {
	_sprite.setPosition(_position);
}