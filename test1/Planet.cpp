/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

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

bool Planet::impactBy(float damage, GameObject* other) {
	bool destroyMe = false;
	if (_mass < other->getMass()) {
		destroyMe = true;
		other->increaseSize(this);
	} else if (_mass > other->getMass()) {
		float massRatio = other->getMass() / this->getMass(); // smaller / larger
		this->setDelta(this->getDelta() + (massRatio * other->getDelta()));
	} else {
		destroyMe = true;
	}
	return destroyMe;
}

void Planet::increaseSize(GameObject* other) {
	_radius = sqrt(pow(_radius, 2) + pow(other->getRadius(), 2));
	auto size = (_radius*2)/_sprite.getTexture()->getSize().x;
	_sprite.setScale(size, size);

	_mass += other->getMass();
}

float Planet::getRadius() {
	return _radius;
}

void Planet::draw(sf::RenderWindow & rw) {
	rw.draw(_sprite);

	//debug circle drawing
	/*
	sf::CircleShape s(_radius);	
	s.setOrigin(_radius, _radius);
	s.setPosition(_position);
	rw.draw(s);
	*/
}
