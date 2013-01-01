#pragma once
#include "stdafx.h"
#include "CollisionComponent.h"
#include "PositionComponent.h"

using namespace std;

class CollisionMap {
public:

	CollisionMap();
	~CollisionMap();

	CollisionComponent* getCollisionComponent(unsigned id);
	void addCollisionComponent(unsigned id, CollisionComponent::ShapeType shape);
	void removeCollisionComponent(unsigned id);

	void resolveCollisions();
	static bool isCircleColliding(sf::Vector2f position1, float radius1, sf::Vector2f position2, float radius2);
	static void resolveCollision(PositionComponent* large, PositionComponent* small);

private:

	map<unsigned, CollisionComponent*> _collisionMap;
};