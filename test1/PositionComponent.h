#pragma once
#include "stdafx.h"

using namespace std;

class PositionComponent {
public:
	PositionComponent(unsigned id, sf::Vector2f position, sf::Vector2f delta, float mass);
	~PositionComponent();

	sf::Vector2f getPosition();
	sf::Vector2f getDelta();
	float getMass();

	void setPosition(sf::Vector2f position);
	void setDelta(sf::Vector2f delta);
	void setMass(float mass);

private:
	unsigned _id;
	sf::Vector2f _position;
	sf::Vector2f _delta;
	float _mass;
};