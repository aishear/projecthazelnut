#include "stdafx.h"
#include "PositionComponent.h"
#include "PositionMap.h"

using namespace std;

PositionMap::PositionMap() {

}

PositionMap::~PositionMap() {

}

PositionComponent* PositionMap::getPositionComponent(unsigned id) {
	return _positionMap.find(id)->second;
}

void PositionMap::addPositionComponent(unsigned id, sf::Vector2f position, sf::Vector2f delta, float mass) {
	auto pc = new PositionComponent(id, position, delta, mass); 
	_positionMap.insert(pair<unsigned, PositionComponent*>(id, pc));
}

void PositionMap::updateGravity() {
	for_each(begin(_positionMap), end(_positionMap), [&](pair<unsigned, PositionComponent*> i){
		
		auto componentI = i.second;
		auto position1 = componentI->getPosition();

		for_each(begin(_positionMap), end(_positionMap), [&](pair<unsigned, PositionComponent*> j){
			//note this will simulate gravity when i and j are the same object

			auto componentJ = j.second;
			auto position2 = componentJ->getPosition();
			auto mass2 = componentJ->getMass();

			//update vectors for gravity
			sf::Vector2f difference = position1 - position2;
			if (difference.x != 0 && difference.y != 0){ //prevent division by zero
				float distance = sqrt(difference.x*difference.x + difference.y*difference.y);
				sf::Vector2f acceleration =  1.f * mass2 * (difference / (distance*distance*distance));
				componentI->setDelta(componentI->getDelta() - acceleration);
			}

		});
	});
}

void PositionMap::updateComponents(float deltaTime) {
	for_each(begin(_positionMap), end(_positionMap), [&](pair<unsigned, PositionComponent*> i){
		auto componentI = i.second;
		auto deltaPosition = componentI->getDelta() * deltaTime;
		componentI->setPosition(componentI->getPosition() + deltaPosition);
	});
}