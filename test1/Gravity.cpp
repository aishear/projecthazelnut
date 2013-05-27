#pragma once
#include "stdafx.h"
#include "Gravity.h"

void Gravity::updateDeltas(std::vector<GameObject>& planets) {
	std::vector<GameObject>::iterator i;
	std::vector<GameObject>::iterator j;

	for(i = planets.begin(); i != planets.end(); ++i) {
		for(j = planets.begin(); j != planets.end(); ++j){
			if (i == j) continue;
			
			sf::Vector2f position1 = i->getPosition();
			sf::Vector2f position2 = j->getPosition();

			//update vectors for gravity
			sf::Vector2f difference = position1 - position2;
			if (difference.x != 0 && difference.y != 0){ //prevent division by zero
				float distance = sqrt(difference.x*difference.x + difference.y*difference.y);
				sf::Vector2f acceleration =  1.f * j->getMass() * (difference / (distance*distance*distance));
				i->setDelta(i->getDelta() - acceleration);
			}
			
		}
	}
}