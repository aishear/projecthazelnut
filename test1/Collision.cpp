#pragma once
#include "stdafx.h"
#include "Collision.h"
#include "Game.h"

void Collision::detectCollisions(const std::vector<GameObject*>::iterator& begin, const std::vector<GameObject*>::iterator& end) {
	std::for_each(begin, end, [&](GameObject* i) {
		std::for_each(begin, end, [&i](GameObject* j) {
			if (i->getId() != j->getId()){
				if (i->getBound().intersects(j->getBound())) { //wide check
					//close check
					if (Collision::isCircleColliding(i->getPosition(), i->getRadius(), j->getPosition(), j->getRadius())) { //TODO make this work for every kind of shape
						Collision::collisions.push(std::pair<GameObject*, GameObject*>(i, j));
					}
				}
			}
		});
	});
}

void Collision::resolveCollisions() {
	while (!collisions.empty()) {
		GameObject* o1 = collisions.top().first;
		GameObject* o2 = collisions.top().second;

		bool remove = o1->impactBy(o2->getDamage(), o2);
		if (remove) {
			removeThese.push(o1->getId());
		}
		collisions.pop();
	}

	//remove deleted objects
	while (!removeThese.empty()) {
		Game::removeGBody(removeThese.top());
		removeThese.pop();
	}
}

bool Collision::isCircleColliding(sf::Vector2f position1, float radius1, sf::Vector2f position2, float radius2) {
	float dx = position2.x - position1.x;
	float dy = position2.y - position1.y;
	float radii = radius1 + radius2;
	
	//check for collisions
	return (( dx * dx )  + ( dy * dy ) < radii * radii);  //both sides have been squared
}

std::stack<std::pair<GameObject*, GameObject*>> Collision::collisions;
std::stack<SLOTMAP_ID> Collision::removeThese;