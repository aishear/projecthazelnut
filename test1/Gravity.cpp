#pragma once
#include "stdafx.h"
#include "Gravity.h"

void Gravity::updateDeltas(std::vector<GameObject>& objects) {
	std::vector<GameObject>::iterator i;
	std::vector<GameObject>::iterator j;

	for(i = objects.begin(); i != objects.end(); ++i) {
		for(j = objects.begin(); j != objects.end(); ++j){
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

void Gravity::updatePositions(const std::vector<GameObject>::iterator& begin, const std::vector<GameObject>::iterator& end, float deltaTime) {
	std::for_each(begin, end, [&deltaTime](GameObject& i) {
		auto scaledDelta = i.getDelta() * deltaTime;
		i.setPosition(i.getPosition() + scaledDelta);
	});
}
