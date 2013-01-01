#pragma once
#include "stdafx.h"

using namespace std;

class EntityManager {
public:
	EntityManager();
	~EntityManager();

	unsigned int getNextId();


	void addPlanetEntity(sf::Vector2f position, sf::Vector2f delta, float mass, float radius);

private:
	set<unsigned> _usedIds;
	unsigned _nextId;
};