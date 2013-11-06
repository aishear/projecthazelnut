/*
 * Copyright 2013 Andrew Shearer <kb3luf@verizon.net>
 * MIT LICENCE - see MIT-LICENCE.txt
 * This file is part of projectHazelnut, a n-body simulation and game.
 */

#pragma once
#include "stdafx.h"
#include "Gravity.h"

void Gravity::updateDeltas(std::vector<GameObject*>& objects, float deltaTime) {
	std::vector<GameObject*>::iterator i;
	std::vector<GameObject*>::iterator j;

	for(i = objects.begin(); i != objects.end(); ++i) {
		for(j = objects.begin(); j != objects.end(); ++j){
			if (i == j) continue;
			
			sf::Vector2f position1 = (*i)->getPosition();
			sf::Vector2f position2 = (*j)->getPosition();

			//update vectors for gravity
			sf::Vector2f difference = position1 - position2;
			if (difference.x != 0 && difference.y != 0){ //prevent division by zero
				float distance = sqrt(difference.x*difference.x + difference.y*difference.y);
				sf::Vector2f acceleration =  1.f * (*j)->getMass() * (difference / (distance*distance*distance));
				acceleration *= deltaTime;
				(*i)->setDelta((*i)->getDelta() - acceleration);
			}
			
		}
	}
}

void Gravity::updatePositions(const std::vector<GameObject*>::iterator& begin, const std::vector<GameObject*>::iterator& end, float deltaTime) {
	std::for_each(begin, end, [&deltaTime](GameObject* i) {
		i->updatePosition(deltaTime);
	});
}
