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


bool GameObject::impactBy(float damage, GameObject* other) {
	return false;
}

void GameObject::increaseSize(GameObject* other) {
	//do nothing by default
}

float GameObject::getDamage() {
	return _delta.x + _delta.y;
}

void GameObject::setId(SLOTMAP_ID id) {
	_id = id;
}

SLOTMAP_ID GameObject::getId() {
	return _id;
}

sf::FloatRect GameObject::getBound() {
	return _sprite.getGlobalBounds();
}