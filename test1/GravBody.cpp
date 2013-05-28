#pragma once
#include "stdafx.h"
#include "GravBody.h"

GravBody::GravBody(sf::Vector2f position, sf::Vector2f initialDelta, float mass) 
	: _position(position), _delta(initialDelta), _mass(mass)
{

}

sf::Vector2f GravBody::getPosition() {
	return _position;
}

sf::Vector2f GravBody::getDelta() {
	return _delta;
}

float GravBody::getMass() {
	return _mass;
}

void GravBody::setDelta(sf::Vector2f & delta) {
	_delta = delta;
}

void GravBody::setPosition(sf::Vector2f & position) {
	_position = position;
}