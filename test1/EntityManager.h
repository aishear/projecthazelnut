/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"

using namespace std;

class EntityManager {
public:
	enum EntityType {Planet, Button};
	EntityManager();
	~EntityManager();

	unsigned int getNextId();


	void addPlanetEntity(sf::Vector2f position, sf::Vector2f delta, float mass, float radius);
	void addButton(sf::Rect<float> bound, std::function<void ()> action, sf::Sprite sprite);
	void removeEntity(unsigned id);
	
	int numEntities();

private:
	map<unsigned, EntityType> _entityMap;
	unsigned _nextId;
};
