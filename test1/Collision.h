#pragma once
#include "stdafx.h"
#include "GameObject.h"

class Collision {
public:
	static void detectCollisions(const std::vector<GameObject*>::iterator& begin, const std::vector<GameObject*>::iterator& end);
	static void resolveCollisions();
	static bool isCircleColliding(sf::Vector2f position1, float radius1, sf::Vector2f position2, float radius2);
private:
	static std::stack<std::pair<GameObject*, GameObject*>> collisions;
	static std::stack<SLOTMAP_ID> removeThese;
};