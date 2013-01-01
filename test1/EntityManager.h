#pragma once
#include "stdafx.h"

using namespace std;

class EntityManager {
public:
	enum EntityType {Planet};
	EntityManager();
	~EntityManager();

	unsigned int getNextId();


	void addPlanetEntity(sf::Vector2f position, sf::Vector2f delta, float mass, float radius);
	void removeEntity(unsigned id);
	
	int numEntities();

private:
	map<unsigned, EntityType> _entityMap;
	unsigned _nextId;
};