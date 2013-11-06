/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"
#include "PositionComponent.h"

using namespace std;

class PositionMap {
public:

	PositionMap();
	~PositionMap();

	PositionComponent* getPositionComponent(unsigned id);
	void addPositionComponent(unsigned id, sf::Vector2f position, sf::Vector2f delta, float mass);
	void removePositionComponent(unsigned id);

	void updateGravity();
	void updateComponents(float deltaTime);

private:

	map<unsigned, PositionComponent*> _positionMap;
};
