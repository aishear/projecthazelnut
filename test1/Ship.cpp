/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"
#include "Ship.h"
#include "GravBody.h"
#include "Game.h"
#include "GameObjectFactory.h"

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

void Ship::updatePosition(float deltaTime) {

	auto scaledDelta = (_delta + _thrustDelta) * deltaTime;
	_position += scaledDelta;
}

bool Ship::impactBy(float damage, GameObject* other) {
	//bounce off and damage ship
	if (_mass < other->getMass()) {

	} else if (_mass > other->getMass()) {
		float massRatio = other->getMass() / this->getMass(); // smaller / larger
		this->setDelta(this->getDelta() * massRatio); //slow down depending on how large the other object is
	} else {
		this->setDelta(this->getDelta() * 0.5f);
	}

	if (_shield > 0) {
		_shield -= damage;
		if (_shield < 0)
			_shield = 0;
	} else {
		_hull -= damage;
		if (_hull < 0)
			_hull = 0;
	}

	if (_hull <= 0) {
		Game::removeShip(_id);
		return true;
	} else {
		return false;
	}
}

void Ship::increaseSize(GameObject* other) {

}

float Ship::getRadius() {
	return _radius;
}

void Ship::draw(sf::RenderWindow& rw) {
	rw.draw(_sprite);

	sf::RectangleShape hull(sf::Vector2f(_radius * (_hull / 100.0f), 3));
	hull.setPosition(_position.x - _radius, _position.y - _radius - 30);
	hull.setFillColor(sf::Color::Red);
	rw.draw(hull);

	sf::RectangleShape shield(sf::Vector2f(_radius * (_shield / 100.0f), 3));
	shield.setPosition(_position.x - _radius, _position.y - _radius - 20);
	shield.setFillColor(sf::Color::Blue);
	rw.draw(shield);
}

sf::Color Ship::getTrailColor() {
	return sf::Color::Red;
}

void Ship::setThrust(float angleRadians, float power) {
	_thrustDelta.x = power * cos(angleRadians);
	_thrustDelta.y = power * -sin(angleRadians);
}
	
void Ship::fire(float angleRadians, float power) {
	sf::Vector2f offset((_radius + 12) * cos(angleRadians), (_radius + 12) * -sin(angleRadians));
	sf::Vector2f bulletPosition(_position + offset);
	sf::Vector2f bulletDelta(power * cos(angleRadians), power * sin(angleRadians)); 
	Game::addBullet(GameObjectFactory::createBullet(bulletPosition, bulletDelta + _delta, 10, 2));
}
