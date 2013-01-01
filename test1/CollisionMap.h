#pragma once
#include "stdafx.h"
#include "CollisionComponent.h"

using namespace std;

class CollisionMap {
public:

	CollisionMap();
	~CollisionMap();

	CollisionComponent* getCollisionComponent(unsigned id);
	void addCollisionComponent(unsigned id, CollisionComponent::shapeType shape);



private:

	map<unsigned, CollisionComponent*> _collisionMap;
};