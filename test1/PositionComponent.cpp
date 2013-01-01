#include "stdafx.h"
#include "PositionComponent.h"

	PositionComponent::PositionComponent(unsigned id, sf::Vector2f position, sf::Vector2f delta, float mass) 
		: _id(id), _position(position), _delta(delta), _mass(mass)
	{

	}

	PositionComponent::~PositionComponent() {

	}

	sf::Vector2f PositionComponent::getPosition() {
		return _position;
	}

	sf::Vector2f PositionComponent::getDelta() {
		return _delta;
	}

	float PositionComponent::getMass() {
		return _mass;
	}

	unsigned PositionComponent::getId() {
		return _id;
	}

	void PositionComponent::setPosition(sf::Vector2f position) {
		_position = position;
	}

	void PositionComponent::setDelta(sf::Vector2f delta) {
		_delta = delta;
	}

	void PositionComponent::setMass(float mass) {
		_mass = mass;
	}