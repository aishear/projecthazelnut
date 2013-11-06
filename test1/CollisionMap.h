/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

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
	void addCollisionComponent(unsigned id, CollisionComponent::ShapeType shape, float width, float height);
	void removeCollisionComponent(unsigned id);

	void resolveCollisions();
	static bool isCircleColliding(sf::Vector2f position1, float radius1, sf::Vector2f position2, float radius2);
	static void resolveCollision(PositionComponent* large, PositionComponent* small, CollisionComponent* largeCollision, CollisionComponent* smallCollision);

private:

	map<unsigned, CollisionComponent*> _collisionMap;
};
